#ifndef HPUH_H
#define HPUH_H

#include "Arduino.h"

/* HPUH-can library 

MIT license
written by Davide Tarantino
*/

#define SPI_CS_PIN 10
#define INTERR_ID 0 //pin 2

class HPUH {
 private:
  unsigned char buf[64];
  unsigned int combineBytes(unsigned char low, unsigned char high);
  
  unsigned int rpm;
  float tps;
  unsigned char th2o;
  unsigned char tair;
  unsigned char toil;
  float vbb1;
  float vbb2;
  float vbb3;
  float lambda1;
  float lambda2;
  float speed1;
  float speed2;
 
 public:
  boolean init(void);
  void getData(void);

  inline unsigned int getRpm() { return rpm; }
  inline float getTps() { return tps; }
  inline unsigned char getTh2o() { return th2o; }
  inline unsigned char getTair() { return tair; }
  inline unsigned char getToil() { return toil; }
  inline float getVbb1() { return vbb1; }
  inline float getVbb2() { return vbb2; }
  inline float getVbb3() { return vbb3; }
  inline float getLambda1() { return lambda1; }
  inline float getLambda2() { return lambda2; }
  inline float getSpeed1() { return speed1; }
  inline float getSpeed2() { return speed2; }

};
#endif
