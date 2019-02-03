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
  string file;
  cout<<"What file do you want to read from?";
  cout<<endl;
  cin>>file;
  
  //Get schedule type
  string type;
  cout << "What schedule type would you like to use? (SRTF/RR/FCFS)" << endl;
  cout<<endl;
  cin >> type;
  
  //Get a quantum value
  int num;
  cout<<"What would you like to use as your quantum number?";
  cout<<endl;
  cin>>num;
  cout<<endl;

  
  RR S1(file,num);
  S1.run();


  
  cout<<endl<<"finished"<<endl;
}
