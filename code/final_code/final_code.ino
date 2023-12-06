void setup() 
{
    //pin declarations
    const int GREEN = 23;
    const int RED = 25;
    const int YELLOW = 27;
    const int BLUE = 29;
    const int FAN = 7;

    //RED button
    pinMode(RED, INPUT_PULLUP);
    //BLUE button
    pinMode(GREEN, INPUT_PULLUP);
    //YELLOW button
    pinMode(YELLOW, INPUT_PULLUP);
    //BLUE button
    pinMode(BLUE, INPUT_PULLUP);

    //FAN pin
    pinMode(FAN, OUTPUT);

    //solenoid pins
    pinMode(22, OUTPUT);
    pinMode(28, OUTPUT);
    pinMode(32, OUTPUT);
    pinMode(36, OUTPUT);
    pinMode(40, OUTPUT);
    pinMode(42, OUTPUT);
}

void loop() 
{
    //c chord
    if (digitalRead(GREEN) == HIGH)
    {
        digitalWrite(42, HIGH);
        digitalWrite(40, LOW);
        digitalWrite(36, LOW);
        digitalWrite(32, LOW);
        digitalWrite(28, LOW);
        digitalWrite(22, LOW);

        digitalWrite(FAN, HIGH);

    }
    //g chord
    else if (digitalRead(RED) == HIGH)
    {
        digitalWrite(42, LOW);
        digitalWrite(40, HIGH);
        digitalWrite(36, HIGH);
        digitalWrite(32, LOW);
        digitalWrite(28, HIGH);
        digitalWrite(22, LOW);

        digitalWrite(FAN, HIGH);
    }
    //a chord
    else if (digitalRead(YELLOW) == HIGH)
    {
        digitalWrite(42, LOW);
        digitalWrite(40, LOW);
        digitalWrite(36, LOW);
        digitalWrite(32, LOW);
        digitalWrite(28, LOW);
        digitalWrite(22, HIGH);

        digitalWrite(FAN, HIGH);
    }
    //f chord
    else if (digitalRead(BLUE) == HIGH)
    {
        digitalWrite(42, LOW);
        digitalWrite(40, LOW);
        digitalWrite(36, LOW);
        digitalWrite(32, HIGH);
        digitalWrite(28, LOW);
        digitalWrite(22, HIGH);

        digitalWrite(FAN, HIGH);
    }


    else
    {
        digitalWrite(42, LOW);
        digitalWrite(40, LOW);
        digitalWrite(36, LOW);
        digitalWrite(32, LOW);
        digitalWrite(28, LOW);
        digitalWrite(22, LOW);

        digitalWrite(FAN, LOW);
    }
}
