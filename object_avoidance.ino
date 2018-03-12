#include <Zumo32U4.h>

Zumo32U4LCD lcd;
Zumo32U4ProximitySensors proxSensors;

Zumo32U4Motors motors;
// --- Setup function
void setup() {
  // Get the proximity sensors initialized
  proxSensors.initThreeSensors();
}

// --- Main program loop
void loop() {

  // --- Read the sensors
  proxSensors.read();    
  int left_sensor = proxSensors.countsLeftWithLeftLeds();
  int center_left_sensor = proxSensors.countsFrontWithLeftLeds();
  int center_right_sensor = proxSensors.countsFrontWithRightLeds();
  int right_sensor = proxSensors.countsRightWithRightLeds();

  // Update the display
  lcd.gotoXY(0, 1);
  lcd.print(left_sensor);
  lcd.print(" ");
  lcd.print(center_left_sensor);
  lcd.print(" ");
  lcd.print(center_right_sensor);
  lcd.print(" ");
  lcd.print(right_sensor);

  if(center_left_sensor > 5 || right_sensor >5)
  {
 motors.setLeftSpeed(-400);
 motors.setRightSpeed(400);
 delay(180);
  motors.setLeftSpeed(400);
 motors.setRightSpeed(400);
  }
  
  if(center_left_sensor < 5 || right_sensor <5)
  {

  motors.setLeftSpeed(400);
 motors.setRightSpeed(400);
  }
  
}
