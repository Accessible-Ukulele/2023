//global variables
const int stringArrayLength = 12;
char* string_frets[stringArrayLength];
int solenoid_pins[stringArrayLength];
int button[4] = {29, 23, 25, 27};
char string_fret[2] = {'z', 'z'};
char active_note = '!';
int solenoid_index;
int button_hold_start;
int time_button_held;
int pressed_button = 4;

void setup()
{
    //setup serial console
    Serial.begin(9600);

    //red green blue yellow
    setupStringArrays();

    pinMode(button[0], INPUT_PULLUP);
    pinMode(button[1], INPUT_PULLUP);
    pinMode(button[2], INPUT_PULLUP);
    pinMode(button[3], INPUT_PULLUP);

    for(int i = 0; i < sizeof(solenoid_pins); i++)
    {
        pinMode(solenoid_pins[i], OUTPUT);
    }
}

void loop()
{
    switch(pressed_button)
    {
        //held for too long
        case -1:
            clearActiveNote();
            analogWrite(36, 0);
            delay(1000);
        //c
        case 0:
            playC();
            break;
        //a
        case 1:
            playA();
            break;
        //f
        case 2:
            playF()
            analogWrite(36, 255);
            break;
        //g
        case 3:
            playG();
            break;
        case 4:
            analogWrite(36, 0);
            break;

    }
    pressed_button = buttonCheck();

    if(time_button_held >= 1500)
    {
        pressed_button = -1; 
        loop();
    }
}

//check on if any buttons are being pressed
int buttonCheck() 
{
    //red - c
    if (digitalRead(button[0]) == HIGH) 
    {
        time_button_held = millis() - button_hold_start;
        Serial.println("Hello, red");
        return 0;
    } 

    //green - a
    else if (digitalRead(button[1]) == HIGH) 
    {
        time_button_held = millis() - button_hold_start;
        Serial.println("Hello, green");
        return 1;
    } 

    //blue - f
    else if (digitalRead(button[2]) == HIGH) 
    {
        time_button_held = millis() - button_hold_start;
        Serial.println("Hello, blue");
        return 2;
    } 

    //yellow - g
    else if (digitalRead(button[3]) == HIGH) 
    {
        time_button_held = millis() - button_hold_start;
        Serial.println("Hello, yellow");
        return 3;
    } 

    //none
    else 
    {
        Serial.println("Hello, none");
        button_hold_start = millis();
        return 4;
    }
}

//track down which index is attached to the solenoid that we want
//returns an index when given a string_fret combination to find
//returns index or returns -1 on fail
int findSolenoidIndex(char string_fret[2])
{
    //if we use char* we will have to manually write .find
    for(int i = 0; i < sizeof(string_frets); i++)
    {
        if(string_frets[i][0] == string_fret[0] && string_frets[i][1] == string_fret[1])
        {
            return i;
        }
    }
    return -1;
}

//option 1
//ex function yet to be implemented
//solenoid indicies size, for loop fol0ing, that calls to find each string and activated respective solenoids
void playNote(int solenoid_indicies[], int solenoid_indicies_size)
{

}

//option 2
//ex function yet to be implemented

//c a f g

void playC()
{
    string_fret[0] = 'A';
    string_fret[1] = 3;
    solenoid_index = findSolenoidIndex(string_fret);
    if (solenoid_index == -1) {}//error
    analogWrite(solenoid_pins[solenoid_index], 255);

    active_note = 'C';
}
void releaseC()
{
    string_fret[0] = 'A';
    string_fret[1] = 3;
    solenoid_index = findSolenoidIndex(string_fret);
    if (solenoid_index == -1) {}//error
    analogWrite(solenoid_pins[solenoid_index], 0);

    active_note = '!';
}

//a minor
void playA()
{
    string_fret[0] = 'G';
    string_fret[1] = 2;
    solenoid_index = findSolenoidIndex(string_fret);
    if (solenoid_index == -1) {}//error
    analogWrite(solenoid_pins[solenoid_index], 255);

    // string_fret = {'C', 1};
    // solenoid_index = findSolenoidIndex(string_fret);
    // if (solenoid_index == -1) {}//error
    // analogWrite(solenoid_pins[solenoid_index], 255);

    active_note = 'A';
}
void releaseA()
{
    string_fret[0] = 'G';
    string_fret[1] = 2;
    solenoid_index = findSolenoidIndex(string_fret);
    if (solenoid_index == -1) {}//error
    analogWrite(solenoid_pins[solenoid_index], 0);

    // string_fret = {'C', 1};
    // solenoid_index = findSolenoidIndex(string_fret);
    // if (solenoid_index == -1) {}//error
    // analogWrite(solenoid_pins[solenoid_index], 0);

    active_note = '!';
}

void playF()
{
    string_fret[0] = 'E';
    string_fret[1] = 1;
    solenoid_index = findSolenoidIndex(string_fret);
    if (solenoid_index == -1) {}//error
    analogWrite(solenoid_pins[solenoid_index], 255);

    string_fret[0] = 'G';
    string_fret[1] = 2;
    solenoid_index = findSolenoidIndex(string_fret);
    if (solenoid_index == -1) {}//error
    analogWrite(solenoid_pins[solenoid_index], 255);

    active_note = 'F';
}
void releaseF()
{
    string_fret[0] = 'E';
    string_fret[1] = 1;
    solenoid_index = findSolenoidIndex(string_fret);
    if (solenoid_index == -1) {}//error
    analogWrite(solenoid_pins[solenoid_index], 0);

    string_fret[0] = 'G';
    string_fret[1] = 2;
    solenoid_index = findSolenoidIndex(string_fret);
    if (solenoid_index == -1) {}//error
    analogWrite(solenoid_pins[solenoid_index], 0);

    active_note = '!';
}

void playG()
{
    string_fret[0] = 'C';
    string_fret[1] = 2;
    solenoid_index = findSolenoidIndex(string_fret);
    if (solenoid_index == -1) {}//error
    analogWrite(solenoid_pins[solenoid_index], 255);

    string_fret[0] = 'E';
    string_fret[1] = 3;
    solenoid_index = findSolenoidIndex(string_fret);
    if (solenoid_index == -1) {}//error
    analogWrite(solenoid_pins[solenoid_index], 255);

    string_fret[0] = 'A';
    string_fret[1] = 2;
    solenoid_index = findSolenoidIndex(string_fret);
    if (solenoid_index == -1) {}//error
    analogWrite(solenoid_pins[solenoid_index], 255);

    active_note = 'G';
}
void releaseG()
{
    string_fret[0] = 'C';
    string_fret[1] = 2;
    solenoid_index = findSolenoidIndex(string_fret);
    if (solenoid_index == -1) {}//error
    analogWrite(solenoid_pins[solenoid_index], 0);

    string_fret[0] = 'E';
    string_fret[1] = 3;
    solenoid_index = findSolenoidIndex(string_fret);
    if (solenoid_index == -1) {}//error
    analogWrite(solenoid_pins[solenoid_index], 0);

    string_fret[0] = 'A';
    string_fret[1] = 2;
    solenoid_index = findSolenoidIndex(string_fret);
    if (solenoid_index == -1) {}//error
    analogWrite(solenoid_pins[solenoid_index], 0);

    active_note = '!';
}

void playE()
{
    string_fret[0] = 'C';
    string_fret[1] = 2;
    solenoid_index = findSolenoidIndex(string_fret);
    if (solenoid_index == -1) {}//error
    analogWrite(solenoid_pins[solenoid_index], 255);

    string_fret[0] = 'E';
    string_fret[1] = 3;
    solenoid_index = findSolenoidIndex(string_fret);
    if (solenoid_index == -1) {}//error
    analogWrite(solenoid_pins[solenoid_index], 255);

    string_fret[0] = 'A';
    string_fret[1] = 2;
    solenoid_index = findSolenoidIndex(string_fret);
    if (solenoid_index == -1) {}//error
    analogWrite(solenoid_pins[solenoid_index], 255);

    active_note = 'G';
}
void releaseE()
{
    string_fret[0] = 'C';
    string_fret[1] = 2;
    solenoid_index = findSolenoidIndex(string_fret);
    if (solenoid_index == -1) {}//error
    analogWrite(solenoid_pins[solenoid_index], 0);

    string_fret[0] = 'E';
    string_fret[1] = 3;
    solenoid_index = findSolenoidIndex(string_fret);
    if (solenoid_index == -1) {}//error
    analogWrite(solenoid_pins[solenoid_index], 0);

    string_fret[0] = 'A';
    string_fret[1] = 2;
    solenoid_index = findSolenoidIndex(string_fret);
    if (solenoid_index == -1) {}//error
    analogWrite(solenoid_pins[solenoid_index], 0);

    active_note = '!';
}

void clearActiveNote()
{
    switch(active_note)
    {
        case '!':
            return;
        case 'A':
            releaseA();
            return;
        case 'C':
            releaseC();
            return;
        case 'F':
            releaseF();
            return;
        case 'G':
            releaseG();
            return;
    }
}


//using loops to write to our arrays instead of manually typing them out
//should fill solenoid pins with even digital pins from 20-52 (16 pins)
//should fill string_combinations with all string fret combinations for the first 4 frets (16 string fret combinations)
//arrays will have corresponding indexes
//string_fret format is letter, number
//solenoid format is letter, number, number
void setupStringArrays()
{
    for(int i = 20, j = 0; i <= 42; i += 2, j++)
    {
        solenoid_pins[j] = i;
    }

    for(int i = 1; i < 5; i++)
    {
        char string;
        switch(i)
        {
            case 1:
                string = 'G';
            case 2:
                string = 'C';
            case 3:
                string = 'E';
            case 4:
                string = 'A';
        }

        for(int j = 0; j < 3; j++)
        {
            string_fret[0] = string, 
            string_fret[1] = j + 1;
            string_frets[i * j] = string_fret;
        }
    }
}