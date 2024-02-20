const int trigPin = 9;
const int echoPin = 10;
const int LEDPin = 3;

const float speedOfSound = 0.034282; // Speed of sound in cm/micro second

// Returns in centimetres
long getUltrasoundDistance(int trigPin, int echoPin)
{
  long duration;

  do
  {
    digitalWrite(trigPin, LOW);
    delayMicroseconds(5);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(15);
    digitalWrite(trigPin, LOW);
  
    duration = pulseIn(echoPin, HIGH);
  }
  while (duration == 0);

  long cm = duration / 2 * speedOfSound;
  
  return cm;
}

void setup()
{
  Serial.begin(9600);
  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
 
  pinMode(LEDPin, OUTPUT);
}

void loop()
{
  auto distance = getUltrasoundDistance(trigPin, echoPin);
  
  Serial.println(distance);
  
  // if (distance <= 20) {
  //   digitalWrite(LEDPin, HIGH);
  // }
  // else {
  //   digitalWrite(LEDPin, LOW);
  // }
}