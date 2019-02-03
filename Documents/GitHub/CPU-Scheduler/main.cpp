//Michelle Simoni and Fisher Harris
//main.cpp
//date: 01/31/2019

#include "scheduleSim.h"
#include "fcfs.h"
#include "srtf.h"
#include "rr.h"
#include <fstream>
#include <iostream>

const string RR_TYPE = "RR";
const string SRTF_TYPE = "SRTF";
const string FCFS_TYPE = "FCFS";

using namespace std;

main()
{
  //Greet user
  cout << "---CPSC3500 Project 2 by Fisher H and Michelle S---" << endl;
  
  //Get filename
  string file = "input1.txt";
  
  //Get a quantum value
  int num = 1;

  
  Srtf S1(file);
  S1.run();


  
  cout<<endl<<"finished"<<endl;
}
