//Michelle Simoni and Fisher Harris
//srtf.cpp
//date: 01/31/2019

#include "scheduleSim.h"
#include "srtf.h"
#include <vector>
#include <iostream>
#include <string>

using namespace std;

void Srtf:: run()
{
  vector<int> rt; // Remaining time

  for (int i = 0; i < pCount; i++) 
  {
    rt.push_back(priorityQ[i].burstTime);
    waitVec.push_back(-1);
  }

  int complete = 0, min = MAX;
  int shortest = 0, finishTime;
  bool check = false;

  // Process until all processes gets completed
  while (complete != pCount) {
    for (int j = 0; j < pCount; j++) {
      if ((priorityQ[j].arrivalTime <= clockT) &&
          (rt[j] < min) && rt[j] > 0) {
        min = rt[j];
        shortest = j;
        check = true;
      }
    }

    printProcess(priorityQ[shortest +1].pid, clockT);

    if (check == false) 
      clockT++;
   

    rt[shortest]--;
    min = rt[shortest];

    if (min == 0)
      min = MAX;

    if (rt[shortest] == 0) {
      complete++;
      finishTime = clockT + 1;
      printFinish(shortest+1, clockT);
      waitVec[shortest] = finishTime - priorityQ[shortest].burstTime -
        priorityQ[shortest].arrivalTime;
      if(waitVec[shortest] < 0)
        waitVec[shortest] = 0;
    }
    clockT++;
  }
}
int Srtf :: shortestIndex()
{
  int smallI=0,index=0;
  for(int i=0;i<pCount;i++)
  {
    if(smallI<priorityQ[i].burstTime && priorityQ[i].notProcessed)
    {
      smallI=priorityQ[i].burstTime;
      index=i;
    }
  }
  
  return index;
}

double Srtf :: aveResponse()
{
  double sum = 0;
  
  for (int i = 0; i < pCount; i++) 
    sum += priorityQ[i].responseTime;
    
  return sum / pCount;
}

double Srtf::aveWait()
{
  return 0;
}

double Srtf::aveTurnAround()
{
  return 0;
}

double Srtf::cpuUsage()
{
  return 0;
}
