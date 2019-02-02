//rr.cpp
//Michelle Simoni,Fisher Harris
//date: 01/31/2019

#include "rr.h"
#include<iostream>
#include <queue>
#include <math.h>

RR:: RR(string inFile, int timeQuantum): SchedSim(inFile)
{
  timeQ=timeQuantum;
}

void RR:: run()
{
  burst=0;
  bool isFinish = false;

  while (!isFinish) {
    for (int  i = 0; i < pCount; i++) {
      if (priorityQ[i].arrivalTime <= clockT && priorityQ[i].notProcessed) {

        for (int j = 0; j < timeQ; j++) {
          printProcess(priorityQ[i].pid,clockT);
          clockT++;
          burst++;
          priorityQ[i].timeRemain--;
          
          
          if (priorityQ[i].timeRemain<= 0) {
            printFinish(priorityQ[i].pid,clockT);
            waitVec.push_back(clockT);
            priorityQ[i].notProcessed = false;
            break;
          }
        }
      }
    }
    
    bool completed = true;
    
    for (int  g = 0; g < pCount; g++)
      if (priorityQ[g].notProcessed)
        completed = false;
      
    if(completed)
      isFinish=true;
  }
  printClosing(clockT);  
}

double RR:: aveWait()
{
  double totalWait=0;
  for(int i=0;i<pCount;i++)
    totalWait+=(waitVec[i]-priorityQ[i].arrivalTime-priorityQ[i].burstTime);
    
  return totalWait/(double)pCount;
}

double RR:: aveRosponse()
{
  double aveRosponse=0;
  for(int i=0;i<pCount;i++)
    aveRosponse+= (double)i*(double)timeQ;

  return aveRosponse/(double)pCount;
}

double RR:: aveTurnAround()
{
  double aveTurn=0.00;
  for(int i=0;i<pCount;i++)
    aveTurn += waitVec[i]- priorityQ[i].arrivalTime;

  return roundf((aveTurn/ pCount)*100)/100;
}

double RR:: cpuUsage()
{
  return ((double)burst/(double)clockT)*100;
}
