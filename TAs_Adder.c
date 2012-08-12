/* 
 * Header
 *
 */

#include <stdio.h>
#define LENGTH 200

void PrintNumber(int TheNumber[]);
void GetNumber(char* Input, int Number[]);
void AddNumber(int FirstNumber[], int SecondNumber[], int Answer[]);

int main(int argc, char**argv)
{
    int FirstNumber[LENGTH];
    int SecondNumber[LENGTH];
    int Answer[LENGTH];
    if(argc == 3)
    {
        GetNumber(argv[1], FirstNumber);
        GetNumber(argv[2], SecondNumber);
        AddNumber(FirstNumber, SecondNumber,Answer);
        PrintNumber(Answer);
    }
    return 0;
}
void PrintNumber(int TheNumber[])
{
    int i = LENGTH-1;
    int LeadingZero = 1;
    for(i; i >= 0; i--)
    {
        if(TheNumber[i] != 0)
        {
            LeadingZero = 0;
        }
        if(!LeadingZero)
        {
            printf("%d", TheNumber[i]);
        }
    }
}

void GetNumber(char* Input, int Number[])
{
    int i = 0;
    int Temp;
    for(i; i < LENGTH; i++)
    {
        Number[i] = 0;
    }
    i=0;
    while(Input[i] != '\0')
    {
        Number[i] = (int)Input[i]-48;
        i++;
    }
    int j = 0;
    i--;
    while(i > j)
    {
        Temp = Number[i];
        Number[i] = Number[j];
        Number[j] = Temp;
        j++;
        i--;
    }
}

void AddNumber(int FirstNumber[], int SecondNumber[], int Answer[])
{
    int i = 0;
    int Digit;
    for(i; i < LENGTH; i++)
    {
        Answer[i] = 0;
    }
    i = 0;
    for(i; i < LENGTH; i++)
    {
        Digit = (FirstNumber[i] + SecondNumber[i]);
        if(Digit < 10)
        {
            Answer[i] = Answer[i] + Digit;
        }
        else
        {
            if(i < LENGTH-1)
            {
                Answer[i+1] = 1;
            }
            Answer[i] = Answer[i] + (Digit%10);
        }
    }
}

// newline \n

