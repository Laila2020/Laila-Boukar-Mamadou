//Laila Boukar Mamadou

// Helper functions for music

#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#include "helpers.h"

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    int numerator=atoi(&fraction[0]);
    int denominator=atoi(&fraction[3]);
    if(numerator>0&&denominator>0&&(denominator%2==0))
    {
        return (float) (numerator/denominator);
    }
    else
    {
        return 1;
    }
}
// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    int sounds;
    char TILES=note[0];
    int OCTAVE=note[strlen(note)- 1]- 48;
    if(TILES=='C')
    {
        sounds=1;
    }
    if(TILES=='D')
    {
        sounds=3;
    }
    if(TILES=='E')
    {
        sounds=5;
    }
    if(TILES=='F')
    {
        sounds=7;
    }
    if(TILES=='G')
    {
        sounds=9;
    }
    if(TILES=='A')
    {
        sounds=11;
    }
    if(TILES=='B')
    {
        sounds=13;
    }
    if(note[1]=='#')
    {
        sounds++;
    }
    if(note[1]=='b')
    {
        sounds--;
    }

//calcul frequency
/*
440*(2^(n/12))
*/
    float freq= 440 * (powf(2,(sounds- 10/ (float) 12)));
    return round (freq * (powf(2, OCTAVE- 4)));
}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    if(strcmp(s,"\0")==0)
    {return true;}
    else
    {return false;}
}

