//global variables
const int stringArrayLength = 16; 
const char* string_frets[stringArrayLength];
const char* solenoid_pins[stringArrayLength];

void setup()
{
    setupStringArrays();
}

void loop()
{

}

//option 1
//ex function yet to be implemented
void playNote(int solenoid_indicies[])
{

}

//option 2
//ex function yet to be implemented
void playSpecificNote()
{

}

//using loops to write to our arrays instead of manually typing them out
//should fill solenoid pins with even digital pins from 20-52 (16 pins)
//should fill string_combinations with all string fret combinations for the first 4 frets (16 string fret combinations)
//arrays will have corresponding indexes
//string_fret format is letter, number
//solenoid format is letter, number, number
void setupStringArrays()
{
    for(int i = 20, int j = 0; i < 52; i += 2, j++)
    {
        char solenoid_pin[3] = {'D', (i / 10), (i % 10)};
        solenoid_pins[j] = solenoid_pin;
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

        for(int j = 1; j < 5; j++)
        {
            char string_fret[2] = {string, i};
            string_frets[i * j] = string_fret;
        }
    }
}