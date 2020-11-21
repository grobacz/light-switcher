#define output_pin 6
#define input_pin 7
#define alert_diode 8

int distance;
long impulseLength = 1000;
int lowDistanceCounter = 0;
int sum;

void setup() {
  Serial.begin(9600);
  pinMode(output_pin, OUTPUT);
  pinMode(input_pin, INPUT);
  pinMode(alert_diode, OUTPUT);
  digitalWrite(output_pin, LOW);
}

void loop() {  
  impulseLength = pulseIn(input_pin, HIGH);
  distance = impulseLength / 60;
  digitalWrite(output_pin, HIGH);
  digitalWrite(output_pin, LOW);
  delayMicroseconds(10);

  if (lowDistanceCounter < 1 && distance <= 5.0) {
    lowDistanceCounter++;
  } else if (distance <= 5.0) {
    digitalWrite(alert_diode, HIGH);
    Serial.println("light switch");
    //delay(100);
  } else {
    digitalWrite(alert_diode, LOW);
    lowDistanceCounter = 0;
  }
}
