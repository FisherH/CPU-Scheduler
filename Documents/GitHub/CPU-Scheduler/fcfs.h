//Michelle Simoni and Fisher harris
// 01/29/2018
//first come first serve class
#include"scheduleSim.h"
#include <queue>
#include <list>
#ifndef FCFS_H
#define FCFS_H
using namespace std;

class FcFs : public SchedSim{
  
 public:
 FcFs(string inFile, int timeQuantum);
  ~FcFs(void){};
  
  void run();
  
 protected:
  
  //descriptoin: this function is to find the average waiting time for all
  //processes
  double aveWait();
  //description: this function is to find the response time for all
  //processes
  double aveRosponse();
  
  //description: this function is to find the turn around time for all
  //processes
  double aveTurnAround(); 
  
  //description: this function will find the cpu Usage for the scheduler
  double cpuUsage();
    
    
     
    
};

#endif
