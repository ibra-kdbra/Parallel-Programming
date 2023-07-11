# Tasks on Parallel Programming in C++
## OMP

1.Write a program where each thread prints its identifier, the total number of threads, and the string "HelloWorld". Run the program with 8 threads. Is the output always identical? Why?

2.Write a program that defines two parallel regions whose execution depends on the conditional operator #pragma omp parallel if(...). If the specified number of threads is greater than 1, the parallel region is executed; otherwise, it is not executed. Set the number of threads to 3 for the first region and 1 for the second region. Inside the parallel regions, determine the number of threads and the thread number, and output the result to the screen. Verify the correctness of the program.

3.Write a program that declares and assigns initial values to integer variables a and b. Define two parallel regions, the first with 2 threads and the second with 4 threads. For the first region, declare the variables a and b as protected, with private and firstprivate access modes, respectively. Inside the region, determine the thread number and increase the values of the variables by this amount. Output the values of the variables to the screen before entering the parallel region, inside the parallel region, and after exiting the parallel region. For the second region, declare variable a as shared, variable b as protected with private access mode, determine the thread number, and decrease the values of the variables by this amount. Output the values of the variables to the screen before entering the parallel region, inside the parallel region, and after exiting the parallel region.

4.Write a program that declares and assigns initial values to integer arrays a[10] and b[10]. Define a parallel region with a number of threads set to 2, and allocate code for the main thread (number 0) and the thread with number 1. The main thread should find the minimum value of the elements of array a, and the thread with number 1 should find the maximum value of the elements of array b. Output the result to the screen.

5.Write a program that declares and assigns initial values to the elements of a two-dimensional array d[6][8]. Use a random number generator to initialize the values. Using the sections...section directive construct, define three sections to perform the following operations:
	The first section calculates the arithmetic mean of the elements in the two-dimensional array.
	The second section calculates the minimum and maximum values of the elements in the two-dimensional array.
	The third section calculates the number of array elements whose numeric values are multiples of 3.
	In each section, determine and output to the screen the thread number and the result of the calculations. Use iteration-type work-sharing constructs.

6.Write a program that declares and assigns initial values to integer arrays a[10] and b[10]. Using the parallel for construct and reduction, calculate the arithmetic means of the elements of arrays a and b, compare the results, and output the result to the screen.

7.Write a program that defines two parallel regions, each containing a for loop initializing the elements of one-dimensional integer arrays a[12], b[12], and c[12]. Set the number of threads to 3 for the first region and 4 for the second region. The first parallel region initializes the elements of arrays a and b using static iteration distribution, and the second parallel region initializes the elements of array c according to the rule c[i] = a[i] + b[i] using dynamic iteration distribution. Determine and output the number of threads, thread number, and loop execution result for each region. Verify the correctness of the program.

8.Using the features of OpenMP, write a program that multiplies a matrix by a vector. Compare the execution time of the sequential and parallel programs.

9.Write a program that declares and assigns initial values to the elements of a two-dimensional array d[6][8]. Use a random number generator to initialize the values. Using the omp parallel for and omp critical directives, determine the minimum and maximum values of the elements of the two-dimensional array. Set the number of threads independently. Output the result to the screen.

10.Write a program that declares and assigns initial values to an array of integer numbers a[30]. Use a random number generator to initialize the values. Using the omp parallel for and omp atomic constructs, calculate the number of array elements whose numeric values are multiples of 9. Set the number of threads independently. Output the result to the screen.

11.Write a program that declares and initializes an array of random integer values. Using OpenMP, find the maximum numerical value of the array elements that are multiples of 7. Determine the length of the array and the number of threads independently. Output the result to the screen. Use critical sections to synchronize the numerical maximum values.

12.Modify task 1 so that threads print their identifiers in reverse order. There are at least 5 ways to solve this problem. Try to find as many as possible.

13.Given an array of integers representing a decimal number in binary form, write a parallel program to compute the decimal value. int a[30] = {1, 0, 1, 1, 0, 1, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 1, 1, 0, 0, 0, 1, 0, 1}; The number x can be represented in a base p system as x = an * pn + an-1 * pn-1 + a1 * p1 + a0 * p0, where an ... a0 are the digits in the representation of the given number.

14.Write a parallel program to compute the square of the number 2^10 without using multiplication. Explanation: The square of a natural number N is equal to the sum of the first N odd numbers. For example, 32 = 9 is 1+3+5=9; 52 = 25 is 1+3+5+7+9=25;

15.Write a program that uses the features of OpenMP to find all prime numbers in a range specified from the keyboard. Determine the number of threads independently. Output the result to the screen.


__________________________________________________________

### MPI

1.1. Write an MPI program that prints "Hello, World!" and run the program on 4 processes.

1.2. Write a program that prints the process rank and the total number of processes in the MPI_COMM_WORLD communicator.

1.3. Write a program and run it on 2 processes. On process 0, create an array "a" of 10 elements and generate random values for them. Send this array in its entirety to process 1 using the MPI_Send function. Print the received array on process 1.

1.4. Use blocking message passing operations (MPI_Send and MPI_Recv) to send a one-dimensional array from process 1 to the other processes in the group. Before calling the receive function (MPI_Recv) on the receiving processes, determine the amount of data to be received (MPI_Probe). Allocate memory for the receive buffer size, and then call the MPI_Recv function. Print the received message on screen.

1.5. Write a program that calculates vector elements according to the formula. The vectors are created on process 0 and are sent to the other processes in equal blocks using MPI_Send. All processes calculate their own array elements based on the formula. Each process sends the calculated elements to process 0.

2.1. Write a program that calculates vector elements according to the formula. The vectors are created on process 0 and are sent to the other processes in equal blocks using MPI_Send. All processes calculate their own array elements based on the formula. Each process sends the calculated elements to process 0.

2.2. Write a program that swaps vector elements. The vectors are created on process 0 and are sent to the other processes in equal blocks using MPI_Send. Each process sends the calculated elements to process 0.

2.3. Implement element-wise matrix multiplication in the program (1 point).

2.4. Implement matrix multiplication in the program (1 point).

2.5. Implement matrix transposition in the program (1 point).

3.1. Write a program to calculate the norm of a vector. Use the MPI_Scatter function to distribute the elements of the vector 'x' among all processes. Use the MPI_Reduce function with the MPI_Sum operation to obtain the final sum on process 0.

3.2. Write a program to calculate the dot product of two vectors. Use the MPI_Scatter function to distribute the elements of vector 'x' among all processes. Use the MPI_Reduce function with the MPI_Sum operation to obtain the final sum on process 0.

3.3. Write a program to multiply a matrix by a vector. Distribute the matrix evenly along rows, and send the vector to all processes. After performing the multiplication operation on each process, gather the resulting local parts of the resulting vector to one process (with rank 0). Use the MPI_Bcast function to broadcast the vector, the MPI_Scatter function to distribute the elements of the matrix, and the MPI_Gather function to gather the local parts of the resulting vector into a global vector.

3.4. Write a program to calculate the norm of a matrix using the formula where A is the matrix. Use the MPI_Scatter function to distribute the elements of the matrix A among all processes. Use the MPI_Reduce function with the MPI_MAX operation to obtain the final value.

3.5. Write a program to calculate the element-wise multiplication of two matrices (). Use the MPI_Scatter function to distribute the elements of matrices A and B, and use the MPI_Gather function to gather the computed data into matrix C.

4.1. Let A and B be two matrices of real numbers defined on process 0. Write a program in which the matrices are sent in equal chunks from process 0 to the other processes using the MPI_Send function. All processes compute their elements of the resulting matrix using a given formula. Each process sends its computed elements to process 0. Implement the Gaussian elimination method to transform the matrix into a lower triangular form (1 point).

4.2. Write a program and run it on p (= 2, 3, 4, 6, 8) processes. Declare and initialize an array of 12 elements on process 0. Use the MPI_Send function to distribute blocks of the array to other processes. The size of each block is (12/p)+1. As a result, process 0 should have elements of the array from 0 to 12/p, process 1 should have elements from 12/p+1 to 2×(12/p), process 3 should have elements from 2×(12/p)+1 to 3×(12/p), and so on. Print the array elements on each process. Note that not all processes will have enough elements. (1 point)

4.3. Develop a program in which two processes repeatedly exchange messages with a length of n bytes. Conduct experiments and evaluate the dependence of the execution time on the message length. Consider two message exchange scenarios: PingPong - bidirectional transmission: Data is transmitted from one process to another with subsequent return of the transmitted data to the source process. The execution time is measured after receiving the return response on the source process. PingPing - unidirectional transmission: Two processes simultaneously transmit data to each other. The execution time is measured after each process receives the message. (1 point)

5.1. Declare and fill an 8x8 matrix 'a' with values on process 0. Create a new data type to scatter odd rows of matrix 'a' into matrix 'b' (4x8), and even rows into matrix 'c' (4x8), using the MPI_Type_vector function.

5.2. Create a data type using the MPI_Type_create_struct function and scatter rows of matrix 'a' (8x8) to a 2x8 matrix 'd' on 4 processes according to the following scheme: rows 0 and 4 to process 0, rows 1 and 5 to process 1, rows 2 and 6 to process 2, and rows 3 and 7 to process 3.

5.3. Create a new group consisting of processes with ranks 8, 3, 9, 1, and 6. Using the MPI_Comm_create(...) constructor, create a communicator for the group. Declare and fill a one-dimensional array of real numbers on process 0 of the created group and print it to the screen. Use the MPI_Bcast function to broadcast the array to all processes in the created group. Print the received arrays to the screen. Send the received array from the last process of the new group to process 0 of the original group. Run the program on 10 processes.


__________________________________________________________

### Merge Sort sequential implementation, OMP (using sections), and MPI

![1](Merge%20Sort/MPI%20graphs/1.png)

![2](Merge%20Sort/MPI%20graphs/2.png)

![3](Merge%20Sort/MPI%20graphs/3.png)

![4](Merge%20Sort/MPI%20graphs/4.png)
