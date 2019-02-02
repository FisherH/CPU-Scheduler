//Michelle Simoni and Fisher Harris
//srtf.h
//date: 01/29/31

#include "scheduleSim.h"

#ifndef SRTF_H
#define SRTF_H

using namespace std;

class Srtf : public SchedSim{
 public:
 Srtf(string inFile, int timeQuantum);
 ~Srtf(void){};

  void run();

 protected:
  
  //descriptoin: this function is to find the average waiting time for all
  //processes
  //  double aveWait();
  //description: this function is to find the response time for all
  //processes
  double aveResponse();

  //description: this function is to find the turn around time for all
  //processes
  //  double aveTurnAround();

  //description: this function will find the cpu Usage for the scheduler
  // double cpuUsage();

  //description: is a function within this class to find the shortest process
  //once it finds the shortest process it will output the index of where that short
  //process is in the vector
  int shortestIndex();

  //description: is a function within this class that will look at the vector and
  //return true if everything is processed or false otherwise
  bool isFinished();

};
#endif
