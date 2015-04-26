
#include <AccelStepper.h>
#include "SpinningFlameThing.h"

AccelStepper stepper(AccelStepper::DRIVER,53,52); // Defaults to AccelStepper::FULL4WIRE (4 pins) on 2, 3, 4, 5
SpinningFlameThing flame(&stepper, -85, 250, 200*8, A1, A2);
void setup()
{  
	Serial.begin(115200);
	stepper.setAcceleration(6000);
	flame.scan(0, 90, 700);
}

long last;

void loop(){
	flame.run();

	if (flame.isDone()){
		int high;
		int low;
		int r;
		int theta;
		flame.getFlamePosition(&high, &low, &r, &theta);
		Serial.println(r);
		Serial.println(theta);
		Serial.println("");
		flame.scan(0, 90, 700);
	}

	if (millis() - last > 5000){
		//flame.scan()
		last = millis();
	}


}