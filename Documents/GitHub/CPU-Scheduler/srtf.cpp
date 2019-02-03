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
  vector <int> rTime;
  int process=0;
  waitVec.push_back(clockT);

  while(!isFinished())
  {
    //Select the shortest process
    process=shortestIndex();
    
    //if this is the first response, record response time
    if(priorityQ[process].responseTime == -1)
      priorityQ[process].responseTime = clockT;
    
    //give the selected process the correct number of cycles
    for(int i = 0; i < priorityQ[process].burstTime; i++)
    {
      printProcess(priorityQ[process].pid,clockT);
      clockT++;
    }

    printFinish(priorityQ[process].pid,clockT);
    priorityQ[process].notProcessed=false;
    
  }
  printClosing(clockT);
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

bool Srtf :: isFinished()
{
  for(int i=0;i<pCount;i++)
    if(priorityQ[i].notProcessed)
      return false;

  return true;
}

double Srtf :: aveResponse()
{
  double sum = 0;
  
  for (int i = 0; i < pCount; i++) 
    sum += priorityQ[i].responseTime;
    
  return sum / pCount;
}


