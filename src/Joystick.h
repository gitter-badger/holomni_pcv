
#ifndef _Joystick_h_
#define _Joystick_h_

#include "Traj3.h"
#include "Motion.h"
#include "Command.h"
#include "PCV_State.h"

class Joystick
{
 public:
  Joystick():cxd(3)
    {
      ax_ = 0.50; // linear acceleration max
      aw_ = 0.30 * REV2RAD; // angular acc max
      vx_ = 0.70; // linear vel max
      vw_ = 0.15 * REV2RAD; // ang vel max
    }
    void Init();
    void Step(Pcv_Command cmd);
  private:
     Float   ax_,aw_,vx_,vw_;     // Traj3    
    PrVector cxd;
};

#endif