#ifndef _Home_h_
#define _Home_h_

#include <stdio.h>
#include <math.h>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "Params.h"

#define MSG  printf

using namespace std;

/*
Use: Main control loop calls Step at step_freq rate while GetCalibrated() returns false for any of the motors. 
Step takes in encoder ticks, the index state (0/1)
Step returns desired torques to go to the motor and the computed encoder offsets.
Once each channel is calibrated it is assumed that the main control loop adjusts encoder ticks by the computed offset.
*/
class Home
{
 public:
  Home(int step_freq, Pcv_Params params_in, vector<int> calibrated_in);
  void Step(vector<long> enc_ticks,vector<int> index_pulse);
  vector<double> GetTq(){return des_tq;} //Desired current
  vector<long> GetOffset(){return e_offset;} //Computed offsets
  vector<int> GetCalibrated(){return calibrated;}//Calibration complete
 private:    
    Float hw_period, hw_freq; 
    Home_Params  params;
    vector<double>     des_tq;
    vector<int>     calibrated;
    vector<int>		first_step;
    vector<int>		state;
    vector<long> e_des,e_old,e,e1,e_offset;
};

#endif // _Home_h_