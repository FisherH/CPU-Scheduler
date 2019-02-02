//Michelle Simoni and Fisher Harris
//scheduling.cpp
//date: 01/29/2019

#include "scheduleSim.h"
#include <iostream>
#include <fstream>
#include <queue>

const string LINE="==========================================";
const string SYSTEM_TIME="<system time ";
const string CLOSE_BRACKET="> ";
const string PROCESS="process ";
const string RUNNING=" is running";
const string FINISHED=" is finished....";
const string IDLE="idle";
const string COMPLETED=" all processes are finished.............";
const string CPU="CPU usage :";
const string AVE_WAIT="Average waiting time :";
const string AVE_RESPONSE="Average responseTime :";
const string AVE_TURN="Average turnaround time :";
const string PERCENT="%";



SchedSim:: SchedSim( string input)
{
  inFile=input;
  clockT=0;
  pCount=0;
  burst=0;
  arival=0;
  idNum=0;
  inputFile();
}


void SchedSim:: printStats()
{
  cout<<LINE<<endl;
  cout<<CPU<<cpuUsage()<<PERCENT<<endl;
  cout<<AVE_WAIT<<aveWait()<<endl;
  cout<<AVE_RESPONSE<<aveRosponse()<<endl;
  cout<<AVE_TURN<<aveTurnAround()<<endl;
  cout<<LINE<<endl;
}


////////////////protected//////////////////
void SchedSim:: printProcess(int pid, int clockTime)
{
    cout<< SYSTEM_TIME<<clockTime<<CLOSE_BRACKET<<PROCESS<<pid<<RUNNING<<endl;
}

void SchedSim:: printFinish(int pid, int clockTime)
{
    cout<<SYSTEM_TIME<<clockTime<<CLOSE_BRACKET<<PROCESS<<pid<<FINISHED<<endl;
}

void SchedSim:: printClosing(int clockTime)
{
    cout<<SYSTEM_TIME<<clockTime<<CLOSE_BRACKET<<COMPLETED<<endl;
}

///////////////functions just ment for children////////

double SchedSim:: aveWait()
{
  return 0.00;
}

double SchedSim:: aveRosponse()
{
  return 0.00;
}

double SchedSim:: aveTurnAround()
{
  return 0.00;
}


double SchedSim :: cpuUsage()
{
  return 0.00;
}
///////////////////private//////////////////
void SchedSim:: inputFile()
{
  ifstream file(inFile.c_str());
  
  if(file.is_open())
    {
      while(file>>idNum>>arival>>burst)
        {
          process tempNode={
            idNum,
            arival,
            burst,
            burst,
            true
          };
          priorityQ.push_back(tempNode);
          pCount++;
        }
    }
  file.close();
}


