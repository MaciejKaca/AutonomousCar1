#include <stepperInterface.h>
#include "stepperMotor.h"

AccelStepper stepperMotor = AccelStepper(MOTOR_INTERFACE_TYPE, STEPPER_PIN, DIRECTION_PIN);
StepperMotorMsg message;

void setup()
{
   pinMode(STEPPER_DRIVER_POWER, OUTPUT);

   digitalWrite(STEPPER_DRIVER_POWER, LOW);

   stepperMotor.setMaxSpeed(MAX_MOTOR_SPEED);
   stepperMotor.setSpeed(INITIAL_SPEED);}

void loop()
{
   if(isMessagePresent())
   {
      receiveMessage(message);
   }

   handleMessage(message, stepperMotor);
}
