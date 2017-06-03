
#include <EEPROM.h>
int buttonPin = 2;

int val ;
int val2 ;
unsigned long previousMillis = 0;
long interval_1 = 1000;
long interval_2 = 5000;
int btnpress =0 ;
int timer_1 = 0;
String read = "";
void setup()
{
	Serial.begin(9600);
	pinMode(buttonPin, INPUT);
	
	pinMode(13, OUTPUT);
	pinMode(12, OUTPUT);
	btnpress = EEPROM.read(0);
}

void loop()
{
	unsigned long currentMillis = millis();
	if (currentMillis - previousMillis >= interval_1) {
		previousMillis = currentMillis;
		timer_1++;
	}
	while (Serial.available() > 0) {
		read = Serial.readString();
		
		if (read == "1")
		{
			btnpress = 1;
			Serial.println("program 1");
			EEPROM.write(0, 1);
		}
		if (read == "2")
		{
			btnpress = 2;
			Serial.println("program 2");
			EEPROM.write(0, 2);
			
		}
		if (read == "3")
		{
			btnpress = 3;
			Serial.println("program 3");
			EEPROM.write(0, 3);
		}
		if (read == "4")
		{
			btnpress = 4;
			Serial.println("program 4");
			EEPROM.write(0, 4);
		}
		if (read == "5")
		{
			btnpress = 5;
			Serial.println("program 5");
			EEPROM.write(0, 5);
		}
		if (read == "info")
		{
			Serial.println("1 - 1 min off / 1 min on");
			Serial.println("2 - 10 min off / 5 min on");
			Serial.println("3 - 20 min off / 10 min on");
			Serial.println("4 - 15 min off / 15 min on");
			Serial.println("5 - 10 min off / 20 min on");
			Serial.print("current EEPROM program ");
			Serial.println(EEPROM.read(0));
			Serial.print("current progam ");
			Serial.println(btnpress);
		}
	}

	switch (btnpress)
	{
	case 1:
		if (timer_1 == 60) {
			digitalWrite(13, HIGH);
			digitalWrite(12, HIGH);
			
		}
		else if (timer_1 >= 60*2)
		{
			timer_1 = 0;
			digitalWrite(13, LOW);
			digitalWrite(12, LOW);
		}
		
		break;
	case 2:
		if (timer_1 == 60*10) {
			digitalWrite(13, HIGH);
			digitalWrite(12, HIGH);

		}
		else if (timer_1 >= 60*15)
		{
			timer_1 = 0;
			digitalWrite(13, LOW);
			digitalWrite(12, LOW);
		}

		break;
	case 3:
		if (timer_1 == 60*20) {
			digitalWrite(13, HIGH);
			digitalWrite(12, HIGH);

		}
		else if (timer_1 >= 60*30)
		{
			timer_1 = 0;
			digitalWrite(13, LOW);
			digitalWrite(12, LOW);
		}

		break;
	case 4:
		if (timer_1 == 60*15) {
			digitalWrite(13, HIGH);
			digitalWrite(12, HIGH);

		}
		else if (timer_1 >= 60*30)
		{
			timer_1 = 0;
			digitalWrite(13, LOW);
			digitalWrite(12, LOW);
		}

		break;
	case 5:
		if (timer_1 == 60*10) {
			digitalWrite(13, HIGH);
			digitalWrite(12, HIGH);

		}
		else if (timer_1 >= 60*30)
		{
			timer_1 = 0;
			digitalWrite(13, LOW);
			digitalWrite(12, LOW);
		}

		break;
	default:
		digitalWrite(13, LOW);
		digitalWrite(12, LOW);
		break;
	}
			
	}

  /* add main program code here */


