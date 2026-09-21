const int pingPin = 7;
const int echoPin = 6;
const int in1 = 13;
const int in2 = 12;
const int en = 9;
void setup()
{

Serial.begin(9600);

}

void loop()
{
long duration, inches, cm;
pinMode(in1, OUTPUT);
pinMode(in2, OUTPUT);
pinMode(en, OUTPUT);
digitalWrite(in1, HIGH);
digitalWrite(in2, LOW);
digitalWrite(en, HIGH);
pinMode(pingPin, OUTPUT);
digitalWrite(pingPin, LOW);
delayMicroseconds(2);
digitalWrite(pingPin, HIGH);
delayMicroseconds(10);
digitalWrite(pingPin, LOW);
pinMode(echoPin, INPUT);
duration = pulseIn(echoPin, HIGH);
inches = microsecondsToInches(duration);
cm = microsecondsToCentimeters(duration);

if(cm<50)
digitalWrite(in1, LOW);
digitalWrite(in2, LOW);


delay(100);
}

long microsecondsToInches(long microseconds)
{
return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds)
{
return microseconds / 29 / 2;
}
