
#define enA 9
#define in1 6
#define in2 7


void setup() {
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  Serial.begin(9600);
  // Set initial rotation direction
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
}
void loop() {
  int potValue = analogRead(A0); // Read potentiometer value
  int pwmOutput = map(potValue, 0, 1023, 0 , 255); // Map the potentiometer value from 0 to 255
  analogWrite(enA, pwmOutput); // Send PWM signal to L298N Enable pin


  

  if(potValue > 0) {
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    
    delay(20);
  }
 Serial.println(potValue);

}
