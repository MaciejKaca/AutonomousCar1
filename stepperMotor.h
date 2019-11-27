#pragma once

#include <Arduino.h>
#include <AccelStepper.h>
#include <stepperInterface.h>

const byte DIRECTION_PIN = 7;
const byte STEPPER_PIN = 8;
const byte MOTOR_INTERFACE_TYPE = 1;
const byte STEPPER_DRIVER_POWER = 2;

const int MAX_MOTOR_SPEED = 1000;
const int INITIAL_SPEED = 0;

bool isMessagePresent();

void handleMessage(StepperMotorMsg message, AccelStepper &stepperMotor);

void receiveMessage(StepperMotorMsg &message);