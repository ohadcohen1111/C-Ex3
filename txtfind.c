#include <stdio.h>
#include "txtfind.h"

int Getline(char s[])
{
char c;
int i = 0;
while(scanf("%c",&c) == 1)
{
    if(i == LINE)
    {
        break;
    }
    s[i] = c;
    if(c == '\n')
    {
        break;
    }
    i++;
}
return i;
}


int Getword(char w[])
    {
char c;
int i = 0;
while(scanf("%c",&c) >= 1)
{
    if(i == WORD)
    {
        break;
    }
    w[i] = c;
    if((c == ' ') || (c == 0) || (c == '\n'))
    {
        break;
    }
    i++;
}
return i;
}


int stringLength(char * str2)
{
    int length = 0;
    for(; (*str2 != '\0') && (*str2 != ' ') && (*str2 != '\n'); str2++)
    {
        length++;
    }
    return length;
}


int substring(char * str1, char * str2)
{
    int counter = 0;
    char * str1Pointer = str1;
    char * str2Pointer = str2;
   
    for(; (*str1Pointer != '\0'); str1Pointer++)
    {
        if(*str1Pointer == *str2Pointer)
        {
            counter++;
            str2Pointer++;

        } else {
            counter = 0;
            str2Pointer = str2;
        }
        if(counter == stringLength(str2))
        {
            return 1;
        }
    }
    return 0;
}


int similar(char * s, char * t, int n)
{
char * sPointer = s;
char * tPointer = t;
int stop = 0;
int counter = 0;

for(; (*sPointer != '\0') && (*sPointer != ' ') && (*tPointer != '\0') && (*tPointer != ' '); sPointer++)
{
    if(*sPointer == *tPointer)
    {
        counter++;
        tPointer++;
    } else {
        stop++;
    }
    if(stop > n)
    {
        return 0;
    }
}
    if((stop <= n) && (counter == stringLength(t)) && (stringLength(t) + 1) >= stringLength(s))
    {
        return 1;
    }
    return 0;
}


void print_lines(char*str)
{
char s[LINE];
int length;
for(;(length = Getline(s))  > 0;)
{
    if(substring(s, str))
        {
        for(int i = 0; i < length; i++)
        {
            printf("%c",s[i]);
        }
        printf("\n");
        }
    }
}

void print_similar_words(char * str)
{
    char w[WORD];
    int length;
    for(;(length = Getword(w)) > 0;)
    {
        if(similar(w,str,1))
        {
        for(int i = 0; i < length; i++)
        {
            printf("%c",w[i]);
        }
        printf("\n");
        }
    }
}
