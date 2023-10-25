//global variables
const int stringArrayLength = 12;
char* string_frets[stringArrayLength];
int solenoid_pins[stringArrayLength];
char active_note = '!';

void setup()
{
    //red green blue yellow
    int button[4] = {21, 23, 25, 27};
    setupStringArrays();

    pinMode(button[0], INPUT_PULLUP);
    pinMode(button[1], INPUT_PULLUP);
    pinMode(button[2], INPUT_PULLUP);
    pinMode(button[3], INPUT_PULLUP);

    for(int i = 0; i < sizeof(solenoid_pins); i++)
    {
        pinmode(solenoid_pins[i], OUTPUT);
    }
}

void loop()
{
    int pressed_button = buttonCheck();
    if(pressed_button < 4)
    {
        clearActiveNote();
        switch(pressed_button)
        {
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
                playF();
                break;
            //g
            case 3:
                playG();
                break;
        }
        delay(15000);
        clearActiveNote();
    }
}

//check on if any buttons are being pressed
int buttonCheck() 
{
    //red - c
    if (digitalRead(button[0]) == LOW) 
    {
        return 0;
    } 

    //green - a
    else if (digitalRead(button[1]) == LOW) 
    {
        return 1;
    } 

    //blue - f
    else if (digitalRead(button[2]) == LOW) 
    {
        return 2;
    } 

    //yellow - g
    else if (digitalRead(button[3]) == LOW) 
    {
        return 3;
    } 

    //none
    else 
    {
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
//solenoid indicies size, for loop following, that calls to find each string and activated respective solenoids
void playNote(int solenoid_indicies[], int solenoid_indicies_size)
{

}

//option 2
//ex function yet to be implemented

//c a f g

void playC()
{
    char string_fret[2] = {'A', 3};
    int solendoid_index = findSolenoidIndex(string_fret);
    if (solendoid_index == -1) {}//error
    digitalWrite(solenoid_pins[solendoid_index], HIGH);

    active_note = 'C';
}
void releaseC()
{
    char string_fret[2] = {'A', 3};
    int solendoid_index = findSolenoidIndex(string_fret);
    if (solendoid_index == -1) {}//error
    digitalWrite(solenoid_pins[solendoid_index], LOW);

    active_note = '!';
}

//a minor
void playA()
{
    char string_fret[2] = {'G', 2};
    int solendoid_index = findSolenoidIndex(string_fret);
    if (solendoid_index == -1) {}//error
    digitalWrite(solenoid_pins[solendoid_index], HIGH);

    // char string_fret[2] = {'C', 1};
    // int solendoid_index = findSolenoidIndex(string_fret);
    // if (solendoid_index == -1) {}//error
    // digitalWrite(solenoid_pins[solendoid_index], HIGH);

    active_note = 'A';
}
void releaseA()
{
    char string_fret[2] = {'G', 2};
    int solendoid_index = findSolenoidIndex(string_fret);
    if (solendoid_index == -1) {}//error
    digitalWrite(solenoid_pins[solendoid_index], LOW);

    // char string_fret[2] = {'C', 1};
    // int solendoid_index = findSolenoidIndex(string_fret);
    // if (solendoid_index == -1) {}//error
    // digitalWrite(solenoid_pins[solendoid_index], LOW);

    active_note = '!';
}

void playF()
{
    char string_fret[2] = {'E', 1};
    int solendoid_index = findSolenoidIndex(string_fret);
    if (solendoid_index == -1) {}//error
    digitalWrite(solenoid_pins[solendoid_index], HIGH);

    char string_fret[2] = {'G', 2};
    int solendoid_index = findSolenoidIndex(string_fret);
    if (solendoid_index == -1) {}//error
    digitalWrite(solenoid_pins[solendoid_index], HIGH);

    active_note = 'F';
}
void releaseF()
{
    char string_fret[2] = {'E', 1};
    int solendoid_index = findSolenoidIndex(string_fret);
    if (solendoid_index == -1) {}//error
    digitalWrite(solenoid_pins[solendoid_index], LOW);

    char string_fret[2] = {'G', 2};
    int solendoid_index = findSolenoidIndex(string_fret);
    if (solendoid_index == -1) {}//error
    digitalWrite(solenoid_pins[solendoid_index], LOW);

    active_note = '!';
}

void playG()
{
    char string_fret[2] = {'C', 2};
    int solendoid_index = findSolenoidIndex(string_fret);
    if (solendoid_index == -1) {}//error
    digitalWrite(solenoid_pins[solendoid_index], HIGH);

    char string_fret[2] = {'E', 3};
    int solendoid_index = findSolenoidIndex(string_fret);
    if (solendoid_index == -1) {}//error
    digitalWrite(solenoid_pins[solendoid_index], HIGH);

    char string_fret[2] = {'A', 2};
    int solendoid_index = findSolenoidIndex(string_fret);
    if (solendoid_index == -1) {}//error
    digitalWrite(solenoid_pins[solendoid_index], HIGH);

    active_note = 'G';
}
void releaseG()
{
    char string_fret[2] = {'C', 2};
    int solendoid_index = findSolenoidIndex(string_fret);
    if (solendoid_index == -1) {}//error
    digitalWrite(solenoid_pins[solendoid_index], LOW);

    char string_fret[2] = {'E', 3};
    int solendoid_index = findSolenoidIndex(string_fret);
    if (solendoid_index == -1) {}//error
    digitalWrite(solenoid_pins[solendoid_index], LOW);

    char string_fret[2] = {'A', 2};
    int solendoid_index = findSolenoidIndex(string_fret);
    if (solendoid_index == -1) {}//error
    digitalWrite(solenoid_pins[solendoid_index], LOW);

    active_note = '!';
}

void playE()
{
    char string_fret[2] = {'C', 4};
    int solendoid_index = findSolenoidIndex(string_fret);
    if (solendoid_index == -1) {}//error
    digitalWrite(solenoid_pins[solendoid_index], HIGH);

    char string_fret[2] = {'E', 3};
    int solendoid_index = findSolenoidIndex(string_fret);
    if (solendoid_index == -1) {}//error
    digitalWrite(solenoid_pins[solendoid_index], HIGH);

    char string_fret[2] = {'A', 2};
    int solendoid_index = findSolenoidIndex(string_fret);
    if (solendoid_index == -1) {}//error
    digitalWrite(solenoid_pins[solendoid_index], HIGH);

    active_note = 'G';
}
void releaseE()
{
    char string_fret[2] = {'C', 4};
    int solendoid_index = findSolenoidIndex(string_fret);
    if (solendoid_index == -1) {}//error
    digitalWrite(solenoid_pins[solendoid_index], LOW);

    char string_fret[2] = {'E', 3};
    int solendoid_index = findSolenoidIndex(string_fret);
    if (solendoid_index == -1) {}//error
    digitalWrite(solenoid_pins[solendoid_index], LOW);

    char string_fret[2] = {'A', 2};
    int solendoid_index = findSolenoidIndex(string_fret);
    if (solendoid_index == -1) {}//error
    digitalWrite(solenoid_pins[solendoid_index], LOW);

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
            char string_fret[2] = {string, j + 1};
            string_frets[i * j] = string_fret;
        }
    }
}