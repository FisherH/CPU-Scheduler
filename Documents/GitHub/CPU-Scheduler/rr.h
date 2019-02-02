//Michelle Simoni and Fisher Harris
//rr.h
//01/31/2019

#include "scheduleSim.h"
#ifndef RR_H
#define RR_H

class RR : public SchedSim
{
 public:
 RR(string inFile, int timeQuantum);
  ~RR(void){};

  void run();

 protected:

  
 private:
  int timeQ;

 
  double aveWait();

  double aveRosponse();

  double cpuUsage();

  double aveTurnAround();
};
#endif
