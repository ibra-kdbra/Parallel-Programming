/* Utility functions for heat equation solver
 *   NOTE: This file does not need to be edited! */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <mpi.h>

#include "heat.h"

/* Utility routine for allocating a two dimensional array */
double **malloc_2d(int nx, int ny)
{
    double **array;
    int i;

    array = (double **) malloc(nx * sizeof(double *));
    array[0] = (double *) malloc(nx * ny * sizeof(double));

    for (i = 1; i < nx; i++) {
        array[i] = array[0] + i * ny;
    }

    return array;
}

/* Utility routine for deallocating a two dimensional array */
void free_2d(double **array)
{
    free(array[0]);
    free(array);
}


/* Copy data on temperature1 into temperature2 */
void copy_field(field *temperature1, field *temperature2)
{
    assert(temperature1->nx == temperature2->nx);
    assert(temperature1->ny == temperature2->ny);
    memcpy(temperature2->data[0], temperature1->data[0],
           (temperature1->nx + 2) * (temperature1->ny + 2) * sizeof(double));
}

/* Swap the data of fields temperature1 and temperature2 */
void swap_fields(field *temperature1, field *temperature2)
{
    double **tmp;
    MPI_Win tmp_win;
    tmp = temperature1->data;
    temperature1->data = temperature2->data;
    temperature2->data = tmp;
    /* Swap the RMA windows */
    tmp_win = temperature1->rma_window;
    temperature1->rma_window = temperature2->rma_window;
    temperature2->rma_window = tmp_win;

}

/* Allocate memory for a temperature field and initialise it to zero */
void allocate_field(field *temperature)
{
    // Allocate also ghost layers
    temperature->data =
        malloc_2d(temperature->nx + 2, temperature->ny + 2);

    // Create RMA window. In principle, only borders would be needed
    // but it is simpler to expose the whole array
    MPI_Win_create(&temperature->data[0][0],
                   (temperature->nx + 2) * (temperature->ny + 2) * sizeof(double), 
                   sizeof(double), MPI_INFO_NULL, MPI_COMM_WORLD,
                   &temperature->rma_window);

    // Initialize to zero
    memset(temperature->data[0], 0.0,
           (temperature->nx + 2) * (temperature->ny + 2) * sizeof(double));
}
