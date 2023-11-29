
int button[4] = {29, 23, 25, 27};
void setup() {


    pinMode(button[0], INPUT_PULLUP);
    pinMode(button[1], INPUT_PULLUP);
    pinMode(button[2], INPUT_PULLUP);
    pinMode(button[3], INPUT_PULLUP);

    pinMode(36, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  // if(digitalRead(button[0]) == LOW)
  // {
  //   digitalWrite(36, HIGH);
  // }
  // else if(digitalRead(button[1]) == HIGH)
  // {
  //   digitalWrite(36, LOW);
  // }

  analogWrite(36, 255);

  delay(800);

  analogWrite(36, 0);
  delay(800);
  

}
