#ifndef _PARTICLE_HPP
#define _PARTICLE_HPP
#include <cmath>
#include "types.hpp"

struct Particle
{
  public:
    Particle() { init();}
    void init() 
    {
      pos[0] = 0.; pos[1] = 0.; pos[2] = 0.;
      vel[0] = 0.; vel[1] = 0.; vel[2] = 0.;
      acc[0] = 0.; acc[1] = 0.; acc[2] = 0.;
      mass   = 0.;
    }
    real_type pos[3];
    real_type vel[3];
    real_type acc[3];  
    real_type mass;
};

struct ParticleSoA
{
  public:
    ParticleSoA() { init();}
    void init() 
    {
      pos_x = NULL; pos_y = NULL; pos_z = NULL;
      vel_x = NULL; vel_y = NULL; vel_z = NULL;
      acc_x = NULL; acc_y = NULL; acc_z = NULL;
      mass  = NULL;
    }
    real_type *pos_x, *pos_y, *pos_z;
    real_type *vel_x, *vel_y, *vel_z;
    real_type *acc_x, *acc_y, *acc_z;  
    real_type *mass;
};

#endif
