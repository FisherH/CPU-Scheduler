//Michelle Simoni and Fisher Harris
//scheduleSim.h
//date: 01/30/2019

#include <vector>
#include <fstream>

#ifndef SCHEDSIM_H
#define SCHEDSIM_H

using namespace std;

struct process {
  int pid;
  int arrivalTime;
  int burstTime;
  int timeRemain;
  int responseTime;
  bool notProcessed;
}; 

class SchedSim{

public:

  //pre: assuming that the user inputs a string to a file
  //post: will upload file to the scheduling sims memory
  SchedSim(string input);

  //deconstructor
  ~SchedSim(void){};

  //description: run is a function that would run the select schedule based of
  //the child class
  void run();
  //description: will print out the cpu usage, average waiting time, average
  //response time, lastly average turnaround time
  void printStats();

  int processCount();
  
protected:
    //description: a function to call to print out what it would say if
    // the process was running
    void printProcess(int pid, int clockTime);
    //description: a function to call if one process finished
    void printFinish(int pid, int clockTime);
    //description: a function to call to print all closing functions
    void printClosing(int clockTime);
    
    //description: not ment to be coded in this class simply a
    //function used in the children
    virtual double aveWait();
    //description: not ment to be coded in this class simply
    //a function used in the children
    virtual double aveRosponse();
    //description: not ment to be coded in this class simply
    //a function used in the children
    virtual double aveTurnAround();
    //description: not ment to be coded in this class simply
    //a function used in the children
    virtual double cpuUsage();

    //////////////////variables/////////////////
    //input file
    string inFile;

    //clock timer
    int clockT;
    //process count
    int pCount;
    //variable to take in burst time
    int burst;
    //variable to take in arrivalTime
    int arival;
    //variable to take in the pid
    int idNum;

    //using vector to hold priority Q as it is easier to use
    vector<process> priorityQ;
    //two int vectors will help in calculating the wait time
    vector<int> waitVec;
    vector<int> burstVec;
    
private:

    //pre: assuming the user input is a file
    //post: will open file and parse into a process node and insert in
    //our vector
    void inputFile();
};
#endif
