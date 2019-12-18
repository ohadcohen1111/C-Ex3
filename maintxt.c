#include <stdio.h>
#include "txtfind.h"

int main()
{
    char word[WORD];
    Getword(word);
    char aORb[WORD];
    Getword(aORb);
    if(aORb[0] == 'a')
    {
        Getword(aORb);
         print_lines(word);
    }
    else if(aORb[0] == 'b')
    {
         Getword(aORb);
         print_similar_words(word);
    }
    return 0;
}
