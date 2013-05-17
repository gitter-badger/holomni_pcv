
#include "Joystick.h"
#include "Home.h"

void Joystick::Init()
{
    x.zero();  // ZERO THE LOCAL COORDS
    traj->curPos( x  );
    traj->curVel( xd );
    traj->accel(  ax_, aw_ );
    traj->maxVel( vx_, vw_ );     
}

void Joystick::Step(Pcv_Command cmd)
{
  double jx = cmd.joystick_x;
  double jy = cmd.joystick_y;
  double jyaw = cmd.joystick_yaw;
  int jb = cmd.joystick_button;
  //static float jx=0,jy=0;
    //static int jb=0,jb_old=-1;
    static int jb_old=-1;
    static Float funOff = 0;
    static Float funX = 0;
        
    
    if( jb != jb_old )
      switch( jb )
      { case 0:
	case 1:		  
	  cmd.ctrlFrame_ = CTRL_F_LOCAL;
	  traj->curPos( x  );
	  traj->curVel( xd );
	  break;
	case 2:
	  cmd.ctrlFrame_ = CTRL_F_GLOBAL;
	  traj->curPos( gx  );
	  traj->curVel( gxd );
	  funX = gx[2] + funOff;
	  break;
      }
    switch(jb)
    { case 0:
	cxd[0] =  jx;
	cxd[1] =  jy;
	cxd[2] =  jyaw;
	traj->get_uV( cxd, dx, dxd, dxdd );
	//MSG("%f, %f, %f, %f, %f, %f\n",jx,jy,jyaw,dx[0],dxd[0],dxdd[0]);
	break;
    case 1:
      cxd[0] = jx*cos(funOff);
      cxd[1] = -jx*sin(funOff);
      cxd[2] = jyaw;
      traj->get_uV( cxd, dx, dxd, dxdd );
      break;
    case 2:
      funOff -= rxd[2]/hw_freq;
      cxd[0] = jx*cos(funX);
      cxd[1] =  -jx*sin(funX);
      cxd[2] = jyaw;
  //                 cxd[0] = -jy*sin(funOff) + 0.5*jy*rxd[2]*cos(funOff);
  //                 cxd[1] =  jy*cos(funOff) + 0.5*jy*rxd[2]*sin(funOff);
      traj->get_uV( cxd, dx, dxd, dxdd );
      break;
    default:
      cxd.zero();
      traj->get_uV( cxd, dx, dxd, dxdd );
      break;
    }
    jb_old = jb; // AGE BUTTON VALUE
}
