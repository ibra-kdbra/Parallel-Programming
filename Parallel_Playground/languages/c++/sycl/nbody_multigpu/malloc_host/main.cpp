#include <iostream>

#include "GSimulation.hpp"

int main(int argc, char** argv) 
{
  int N;			//number of particles
  int nstep; 		//number ot integration steps
  int num_gpus;
  
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
      num_gpus =atoi(argv[3]);
      sim.set_number_of_gpus(num_gpus);
  }
  
  sim.start();

  return 0;
}
