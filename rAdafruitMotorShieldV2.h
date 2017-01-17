#pragma once
#include "B4RDefines.h"
#include "Adafruit_MotorShield.h"
//~version: 1.00
namespace B4R {
	//~shortname: AdafruitMotorShield
	class B4RAdafruitMotorShield {
		private:
			uint8_t beAdafruit_MotorShield[sizeof(Adafruit_MotorShield)];
		public:
			//~hide
			Adafruit_MotorShield* motorShield;
			//Initializes the object.
			//Address - I2C address. Default value is 0x60.
			//Frequency - Frequency in hz. Default value is 1600.
			void Initialize(Byte Address, UInt Frequency);
			void SetPWM (Byte Pin, UInt Value);
			void SetPin (Byte Pin, bool Value);
	};
	//~shortname: AdafruitDCMotor
	class B4RAdafruitDCMotor {
		private:
			Adafruit_DCMotor* motor;
		public:
			//Initializes the object.
			//MotorShield - An initialized MotorShield object.
			//PortNumber - Motor port number.
			void Initialize(B4RAdafruitMotorShield* MotorShield, Byte PortNumber);
			//Command - One of the COMMAND constants.
			void Run(Byte Command);
			//Sets the speed (0 - 255).
			void setSpeed(Byte s);
			#define /*Byte COMMAND_FORWARD;*/ B4RAdafruitDCMotor_COMMAND_FORWARD FORWARD
			#define /*Byte COMMAND_BACKWARD;*/ B4RAdafruitDCMotor_COMMAND_BACKWARD BACKWARD
			#define /*Byte COMMAND_RELEASE;*/ B4RAdafruitDCMotor_COMMAND_RELEASE RELEASE
	};
	//~shortname: AdafruitStepperMotor
	class B4RAdafruitStepperMotor {
		private:
			Adafruit_StepperMotor* motor;
		public:
			//Initializes the object.
			//MotorShield - An initialized MotorShield object.
			//Steps - Number of steps per revolution.
			//PortNumber - Stepper port number.
			void Initialize(B4RAdafruitMotorShield* MotorShield, UInt Steps, Byte PortNumber);
			//Sets the speed (RPM)/
			void setSpeed(UInt rpm);
			void Release();
			//Steps - Number of steps.
			//Dir - One of the DIR constants.
			//Style - One of the STYLE constants.
			void Step (UInt Steps, Byte Dir, Byte Style);
			//Dir - One of the DIR constants.
			//Style - One of the STYLE constants.
			void OneStep (Byte Dir, Byte Style);
			#define /*Byte STYLE_SINGLE;*/ B4RAdafruitStepperMotor_STYLE_SINGLE SINGLE
			#define /*Byte STYLE_DOUBLE;*/ B4RAdafruitStepperMotor_STYLE_DOUBLE DOUBLE
			#define /*Byte STYLE_INTERLEAVE;*/ B4RAdafruitStepperMotor_STYLE_INTERLEAVE INTERLEAVE
			#define /*Byte STYLE_MICROSTEP;*/ B4RAdafruitStepperMotor_STYLE_MICROSTEP MICROSTEP
			#define /*Byte DIR_FORWARD;*/ B4RAdafruitStepperMotor_DIR_FORWARD FORWARD
			#define /*Byte DIR_BACKWARD;*/ B4RAdafruitStepperMotor_DIR_BACKWARD BACKWARD
			#define /*Byte DIR_RELEASE;*/ B4RAdafruitStepperMotor_DIR_RELEASE RELEASE
	};
}