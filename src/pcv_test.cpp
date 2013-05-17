// gcc -g -Wall -lholomni_pcv -I./pr/include -I./ -ansi -pedantic pcv_test.cpp -o pcv_test

// gcc -g -Wall -lyaml-cpp -I./pr/include -I./ -ansi -pedantic pcv_test.cpp Pcv.cpp Filter.cpp Vehicle.cpp Caster.cpp Ctrl.cpp Traj3.cpp pr/src/matrix/PrMatrix.cpp pr/src/matrix/PrVector.cpp  -o pcv_test

#include "Pcv.h"
#include <mcheck.h> /* Header file to include mtrace related functions */
#include <stdlib.h>

int main()
{
  //mtrace(); /* This starts memory tracing. */
  printf("Starting PCV Test..\n");
  
  PCV * pcv = new PCV("/home/meka/mekabot/m3qa/robot_config/mb1/pcv_meka_b1r1.yml", 1000);
  
  delete pcv;
  
  pcv = NULL;
  
  pcv = new PCV("/home/meka/mekabot/m3qa/robot_config/mb1/pcv_meka_b1r1.yml", 1000);
  
  delete pcv;
    
  
  printf("Exiting PCV Test..\n");
  
 return EXIT_SUCCESS;
}