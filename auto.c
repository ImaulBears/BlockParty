#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTServo,  none)
#pragma config(Motor,  mtr_S1_C1_1,     motorAlpha,    tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C1_2,     motorBeta,     tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     motorGamma,    tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     motorDelta,    tmotorTetrix, openLoop, encoder)
#pragma config(Servo,  srvo_S1_C3_1,    servoAlpha,           tServoContinuousRotation)
#pragma config(Servo,  srvo_S1_C3_2,    servoBeta,            tServoStandard)
#pragma config(Servo,  srvo_S1_C3_3,    servoGamma,           tServoStandard)
#pragma config(Servo,  srvo_S1_C3_4,    servoDelta,           tServoStandard)
#pragma config(Servo,  srvo_S1_C3_5,    servoEpsilon,         tServoStandard)
#pragma config(Servo,  srvo_S1_C3_6,    servoZeta,            tServoStandard)

//Copyright 2014 FTC Team 7553 - Thavma
//Original pile of crap by Richard. Totally rewritten by Alex.
//GPL or something, I guess. Tell us if you use it. Don't make money with it. Copy it, share the source.
//That's the general gist of the GPL

#include "JoystickDriver.c"  //Include file to "handle" the Bluetooth messages.

void initializeRobot()
{
	return;
}

void reencode(char *motorName)
{
	char newName[32] = "";

	strcat(newName, "motor");
	strcat(newName, motorName);
	nMotorEncoder[newName] = 0;
}

task main()
{
	string Alpha = "Alpha";
	string Delta = "Delta";

	initializeRobot();

	wait1Msec(1);
	reencode(Delta);

 	while(nMotorEncoder[motorDelta] < 3571) {
 		motor[motorAlpha] = 100;
 		motor[motorDelta] = 100;
 	}


 	wait1Msec(500);
	reencode(Delta);

	while(nMotorEncoder[motorDelta] < 285) {
		motor[motorAlpha] = -50;
		motor[motorDelta] = -50;
	}

	wait1Msec(1);
	reencode(Alpha);

	while(nMotorEncoder[motorAlpha] < 1851) {
		motor[motorAlpha] = 75;
		motor[motorDelta] = -75;
	}

	wait1Msec(1);
	reencode(Alpha);

	while(nMotorEncoder[motorAlpha] < 4142) {
		motor[motorAlpha] = 50;
		motor[motorDelta] = 50;
	}

	wait1Msec(1);
	reencode(Delta);

	while(nMotorEncoder[motorDelta] < 1234) {
		motor[motorAlpha] = -50;
		motor[motorDelta] = 50;
	}

	wait1Msec(1);
	reencode(Delta);

	while(nMotorEncoder[motorDelta] < 3285) {
		motor[motorAlpha] = 50;
		motor[motorDelta] = 50;
	}

	wait1Msec(1);
	reencode(Delta);

	while(nMotorEncoder[motorDelta] < 1851) {
		motor[motorAlpha] = -100;
		motor[motorDelta] = 100;
	}

	wait1Msec(1);
	reencode(Delta);

	while(nMotorEncoder[motorDelta] < 5142) {
		motor[motorAlpha] = 100;
		motor[motorDelta] = 100;
	}
}
