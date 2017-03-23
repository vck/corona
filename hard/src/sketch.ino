int LED1=13;
int LED2=12;
String recvd = "";


void setup()
{

	Serial.begin(9600);
	pinMode(LED1, OUTPUT);
	pinMode(LED2, OUTPUT);
}

void loop()
{
	while(Serial.available() > 0){
		int read = Serial.read();
		recvd += (char)read;

		Serial.println(recvd);

    blink(recvd.toInt());
    blink1(recvd.toInt());

		recvd = "";
	}

}


void blink(int times){
  for(int i=0; i < times; i++){
    digitalWrite(LED1, HIGH);
    delay(500);
    digitalWrite(LED1, LOW);
    delay(500);
  }
}


void blink1(int times){
  for(int i=0; i < times; i++){
    digitalWrite(LED2, HIGH);
    delay(500);
    digitalWrite(LED2, LOW);
    delay(500);
  }
}
