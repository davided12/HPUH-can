#include <HPUH-can.h>

HPUH hpuh;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println(hpuh.init());
}

void loop() {
  // put your main code here, to run repeatedly:
  hpuh.getData();
  Serial.println(hpuh.getRpm()); 
  Serial.println(hpuh.getTps()); 
  Serial.println(hpuh.getVbb1());
  Serial.println(hpuh.getSpeed1());
  Serial.println(hpuh.getLambda1());
}
