#include "B4RDefines.h"
namespace B4R {
	void B4RAdafruitMotorShield::Initialize(Byte Address, UInt Frequency) {
		motorShield = new (beAdafruit_MotorShield) Adafruit_MotorShield(Address);
		motorShield->begin(Frequency);
	}
	void B4RAdafruitMotorShield::SetPWM (Byte Pin, UInt Value) {
		motorShield->setPWM(Pin, Value);
	}
	void B4RAdafruitMotorShield::SetPin (Byte Pin, bool Value) {
		motorShield->setPin(Pin, Value);
	}
	void B4RAdafruitDCMotor::Initialize(B4RAdafruitMotorShield* MotorShield, Byte PortNumber) {
		motor = MotorShield->motorShield->getMotor(PortNumber);
	}
	void B4RAdafruitDCMotor::Run(Byte Command) {
		motor->run(Command);
	}
	void B4RAdafruitDCMotor::setSpeed(Byte s) {
		motor->setSpeed(s);
	}
	void B4RAdafruitStepperMotor::Initialize(B4RAdafruitMotorShield* MotorShield, UInt Steps, Byte PortNumber) {
		motor = MotorShield->motorShield->getStepper(Steps, PortNumber);
	}
	void B4RAdafruitStepperMotor::setSpeed(UInt rpm) {
		motor->setSpeed(rpm);
	}
	void B4RAdafruitStepperMotor::Release() {
		motor->release();
	}
	void B4RAdafruitStepperMotor::Step (UInt Steps, Byte Dir, Byte Style) {
		motor->step(Steps, Dir, Style);
	}
	void B4RAdafruitStepperMotor::OneStep (Byte Dir, Byte Style) {
		motor->onestep(Dir, Style);
	}
}