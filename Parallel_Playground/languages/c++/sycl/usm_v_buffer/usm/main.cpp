#include <iostream>

#include "GSimulation.hpp"

int main(int argc, char** argv) 
{
  int N;			//number of particles
  int nstep; 		//number ot integration steps
  
  printf("nbody simulation OpenCL version.\n \
      ./nbody.x <num_particles> <num_steps> <cpu-to-gpu ratio> <cpu-wgsize> <gpu-wgsize>\n \
      <cpu-to-gpu-ratio> is optional and will default to 0 which will start a parameter sweep from 0 to 100 percent. \n \
      <cpu-wgsize> is optional and will default to 0 which will allow the runtime to select work group size.\n \
      <gpu-wgsize> is optional and will default to 0 which will allow the runtime to select work group size.\n \
      to test for correctness: ./nbody.x 2000 500 <cpu/gpu/cpu+gpu> \n \
      last reported energy  level should be: \n \
      ");
  GSimulation sim;
   std::string a ;
  if(argc>1)
  {
    N=atoi(argv[1]);
    sim.set_number_of_particles(N);  
    if(argc>2) 
    {
      nstep=atoi(argv[2]);
      sim.set_number_of_steps(nstep);  
    }
    if(argc > 3) 
      a = argv[3];
      std::cout << a << std::endl;
      if (!a.compare("cpu")) sim.set_devices(1);
      if (!a.compare(std::string("gpu"))) sim.set_devices(2);
      if (!a.compare(std::string("cpu+gpu"))) sim.set_devices(3);

    if(argc > 4) 
      sim.set_cpu_ratio(atof(argv[4]));

    if(argc > 5) {
      sim.set_cpu_wgsize(atoi(argv[5]));
      sim.set_gpu_wgsize(atoi(argv[6]));
    }
  }
  
  sim.start();

  return 0;
}
