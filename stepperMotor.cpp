#include "stepperMotor.h"

bool isMessagePresent()
{
    if(Serial.available() )
    {
        return true;
    }
    return false;
}

void handleMessage(StepperMotorMsg message, AccelStepper &stepperMotor)
{
    switch (message.command)
    {
    case RUN:
        if(message.direction == BACKWARD)
        {
            stepperMotor.setSpeed(message.speed * -1);
        }
        else
        {
            stepperMotor.setSpeed(message.speed);
        }
            
        digitalWrite(STEPPER_DRIVER_POWER, HIGH);
        break;
        
    case BRAKE:
        stepperMotor.setSpeed(0);
        break;

    case SWICTH_OFF:
        digitalWrite(STEPPER_DRIVER_POWER, LOW);
        stepperMotor.setSpeed(0);
        break;

    case MOVE_DISTANCE:
        //TODO
        break;
        
    }
}

void receiveMessage(StepperMotorMsg &message)
{
     Serial.readBytes((char*)&message, sizeof(StepperMotorMsg));
}
