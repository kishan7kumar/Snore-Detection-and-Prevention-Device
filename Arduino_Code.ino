//********************PROGRAM FOR ANTI-SNORING ELECTRONIC DEVICE (ASED)****************************\\


// defining Sound sensor
int micpin = A0; // arduino analog pin A0 connected to sound sensor A0 pin
int m1 = 0;
int m2 = 0;
int m3 = 0;
// defining L293D motor driver pins
const int in3 = 2;
const int in4 = 3;
// defining buzzer
const int buzzer = 4;
// defining leds
int greenled = 5; //for showing air filling
int blueled = 6;  // for showing snoring detetection
int redled = 7;	  // for showing power on or off

void setup()
{
	pinMode(micpin, INPUT);	 // gives input signals to the arduino board micvalue1 and micvalaue2
							 // Serial.begin(9600);        // for displaying into serial monitor
	pinMode(buzzer, OUTPUT); // for buzzer
	pinMode(in3, OUTPUT);	 // for L293D motor driver which is connected to Air Pump
	pinMode(in4, OUTPUT);	 // for L293D motor driver which is connected to Air Pump
	pinMode(greenled, OUTPUT);
	pinMode(blueled, OUTPUT);
	pinMode(redled, OUTPUT);

	// all system check
	digitalWrite(redled, HIGH);
	digitalWrite(blueled, HIGH);
	digitalWrite(greenled, HIGH);
	tone(buzzer, 1000);
	delay(100);
	noTone(buzzer);
	delay(1000);
	digitalWrite(blueled, LOW);
	digitalWrite(greenled, LOW);
	digitalWrite(redled, LOW);
	delay(1000);
}

void loop()

{
	digitalWrite(redled, HIGH);
	Listen();										  // microphone starts to liten to snoring
	if (m1 < 400 && m2 < 400 && m3 != m1 && m3 != m2) // when snoring starts then get inside loop
	{												  //Serial.println("snoring starts------- filling air into pillow ");
		FillAir();									  // air starts to fill inside air bag of pillow
		delay(40000);								  // fill air for 35 seconds
		StopAir();
		delay(2000);

		for (int i = 1; i < 100; i++)
		{
			Listen();
			if (m1 < 300 && m2 < 300)
			{ //Serial.println("snoring too loud !!!!!!!!!! raising alarm ");
				Alarmseq();
				delay(2000);
				break;
			}
		}
	}
} //loop function closed

// all functions defined here

void Listen()
{
	digitalWrite(blueled, HIGH);
	m1 = analogRead(micpin);
	delay(90);
	m2 = analogRead(micpin);
}
void PlayAlarm()
{
	digitalWrite(blueled, HIGH);
	digitalWrite(greenled, HIGH);
	tone(buzzer, 1000);
	delay(500); // ...for 1 sec
}

void StopAlarm()
{
	digitalWrite(blueled, LOW);
	digitalWrite(greenled, LOW);
	noTone(buzzer);
	delay(500);
}

void FillAir()
{
	digitalWrite(blueled, LOW);
	digitalWrite(greenled, HIGH);
	digitalWrite(in3, HIGH);
	digitalWrite(in4, LOW);
}

void StopAir()
{
	digitalWrite(greenled, LOW);
	digitalWrite(in3, LOW);
	digitalWrite(in4, LOW);
}

void Alarmseq()
{
	PlayAlarm();
	StopAlarm();
	PlayAlarm();
	StopAlarm();
	PlayAlarm();
	StopAlarm();
	PlayAlarm();
	StopAlarm();
	PlayAlarm();
	StopAlarm();
	PlayAlarm();
	StopAlarm();
	PlayAlarm();
	StopAlarm();
	PlayAlarm();
	StopAlarm();
	PlayAlarm();
	StopAlarm();
}
