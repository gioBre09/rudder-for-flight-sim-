#include <Joystick.h>

//Joystick Setup
Joystick_ Joystick(JOYSTICK_DEFAULT_REPORT_ID,JOYSTICK_TYPE_JOYSTICK,
  0, 0,                  // Button Count, Hat Switch Count
  true, true, true,     // X, Y, & Z Axis
  false, false, false,     // Rx, Ry, or No Rz
  false, false,          // Rudder but no throttle
  false, false, false);  // No accelerator, brake, or steering;
int leftPedal = 0;
int rightPedal = 0;
int rudderAxis_ = 0;                 

void setup(){
  Serial.begin(9600); //Start serial monitoring
  Joystick.begin(); //Starts joystick
}
  
void loop(){
  
  leftPedal = analogRead(A3);
  leftPedal = map(leftPedal,0,1023,0,4999);
  Joystick.setXAxis(leftPedal);
  
  rightPedal = analogRead(A2);
  rightPedal = map(rightPedal,0,1023,0,4999);
  Joystick.setYAxis(rightPedal);

  rudderAxis_ = analogRead(A1);
  rudderAxis_ = map(rudderAxis_,-30,1023,0,2500);
  Joystick.setZAxis(rudderAxis_);

  delay(5);
}
