//Michelle Simoni and Fisher haris
//01/29/2019
//fcfs.cpp


#include "fcfs.h"
#include <queue>
#include <list>
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>


FcFs :: FcFs(string inFile, int timeQuantum): SchedSim(inFile)
{

}


void FcFs :: run()
{
  int tempWait=0;
  waitVec.push_back(tempWait);
  for(int i=0;i<pCount;i++)
    {
      for(int k=0;k<priorityQ[i].burstTime;k++)
        {
          burstVec.push_back(priorityQ[i].burstTime);
            if(k<priorityQ[i].burstTime)
              {
                printProcess(priorityQ[i].pid,tempWait);
              }
          tempWait++;
        }
      printFinish(priorityQ[i].pid,tempWait);
      waitVec.push_back(tempWait);
    }
  printClosing(tempWait);
  clockT=tempWait;
}


double FcFs :: aveWait()
{
  double totalWait=0;
  for(int i=0;i<pCount;i++)
    {
      totalWait+=waitVec[i]- priorityQ[i].arrivalTime;
    }
  return roundf((totalWait/pCount)*100)/100;
}

double FcFs ::aveTurnAround()
{
  int totalBurst = 0,aveTurn=0;
  for (int i = 0; i < pCount; i++) {
    totalBurst += priorityQ[i].burstTime;
    aveTurn +=( totalBurst - priorityQ[i].arrivalTime);
    
  }
  return roundf((aveTurn/pCount)*100)/100;
}

double FcFs :: aveRosponse()
{
  return aveWait();
}

double FcFs :: cpuUsage()
{
  int totalBurst=0;
  for(int i=0;i<pCount;i++)
    {
      totalBurst+= priorityQ[i].burstTime;
    }
  return round((totalBurst/clockT)*100);
}
