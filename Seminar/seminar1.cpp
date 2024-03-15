#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<assert.h>
//for is_alpha()
using namespace std;

void lettersVowels(char name[], int &nLetters, int &nVowels)
{
    nLetters = 0;
    nVowels = 0;
    char vowels[] = {'a', 'e', 'i', 'o', 'u'};
    int nLetters = 0, nVowels = 0;
    for(int i=0;name[i]!='\0';i++)
    {
        if(isalpha(name[i]))
        {
            nLetters += 1;
            if(strchr(vowels,name[i]) != NULL)
            {
                nVowels += 1;
            }
        }
    }
}

int main()
{
    char name[50], vowels[] = {'a', 'e', 'i', 'o', 'u'};
    int nLetters = 0, nVowels = 0;

    cout<<"What is your name? ";cin>>name;

    int length = strlen(name);
    for(int i=0;name[i]!='\0';i++)
    {
        if(isalpha(name[i]))
        {
            nLetters += 1;
            if(strchr(vowels,tolower(name[i])) != NULL)
            {
                nVowels += 1;
            }
        }
    }

    lettersVowels(name, nLetters, nVowels)

    cout<<name<<endl;
    cout<<nVowels<<endl;
    cout<<nLetters;

    //First test: empty string
    strcpy(name,"ghj");
    lettersVowels(name, nLetters, nVowels);
    assert(nLetters == 3 && nVowels == 0);

    //Second test: any letters or vowels
    strcpy(name,"123512861");
    lettersVowels(name, nLetters, nVowels);
    assert(nLetters == 0 && nVowels == 0);

    //Fourth test: one or more vowels
    strcpy(name,"Barba Antonia");
    lettersVowels(name, nLetters, nVowels);
    assert(nLetters == 12 && nVowels == 6);

    return 0;
}
