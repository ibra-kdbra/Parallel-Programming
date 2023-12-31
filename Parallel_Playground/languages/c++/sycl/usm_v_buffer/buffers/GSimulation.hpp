#define ALIGNMENT 64
#ifndef _GSIMULATION_HPP
#define _GSIMULATION_HPP


#include "Particle.hpp"
#include "Constants.hpp"
class GSimulation 
{
public:
  GSimulation();
  ~GSimulation();
  
  void init();
  void set_number_of_particles(int N);
  void set_number_of_steps(int N);
  void start();
  void update(real_type dt);

  inline void set_cpu_ratio(const float &cpu_ratio){ _cpu_ratio = cpu_ratio; }
  inline void set_cpu_wgsize(const int &cpu_wgsize){ _cpu_wgsize = cpu_wgsize; }
  inline void set_gpu_wgsize(const int &gpu_wgsize){ _gpu_wgsize = gpu_wgsize; }
  inline int get_cpu_ratio() const {return _cpu_ratio; }
  inline void set_devices(int N) { _devices = N;};
  inline int get_devices() { return _devices;};
  
private:
  ParticleSoA *particles;
  
  int       _npart;		//number of particles
  int	    _nsteps;		//number of integration steps
  real_type _tstep;		//time step of the simulation

  int	    _sfreq;		//sample frequency
  
  real_type _kenergy;		//kinetic energy
  
  double _totTime;		//total time of the simulation
  double _totFlops;		//total number of flops 

  float _cpu_ratio = -1.0f;
  int _cpu_wgsize = 0;
  int _gpu_wgsize = 0;
  int _devices = 0;
   
  void init_pos();	
  void init_vel();
  void init_acc();
  void init_mass();

    
  inline void set_npart(const int &N){ _npart = N; }
  inline int get_npart() const {return _npart; }
  
  inline void set_tstep(const real_type &dt){ _tstep = dt; }
  inline real_type get_tstep() const {return _tstep; }
  
  inline void set_nsteps(const int &n){ _nsteps = n; }
  inline int get_nsteps() const {return _nsteps; }
  
  inline void set_sfreq(const int &sf){ _sfreq = sf; }
  inline int get_sfreq() const {return _sfreq; }
  
  void print_header();
  
};

#endif
