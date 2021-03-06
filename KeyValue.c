#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include "KeyValue.h"

/* put KEY VALUE
 * get KEY
 * del KEY
 */

int c=0;
int s=0;

int put(char* key, char *value, kvs *speicher)
{

    for(int i = 0; i < MAXCHAR; i++)
    {
        if(strcmp(speicher[i].key, key) == 0)   //suche nach vorhandenen Key
        {
            strcpy(speicher[i].value,value);

            return 1;
        }
    }
    strcpy(speicher[c].key,key);    //neuer Key & Value
    strcpy(speicher[c].value,value);
    c++;

    return 0;
}


char* get( char* key, kvs *speicher)
{

    for(int i=0; i < MAXCHAR; i++)
    {
        if (strcmp(speicher[i].key, key) == 0) // Suche nach dem Key
        {
            return speicher[i].value;
        }
    }

    return "Key_nicht_im_Store";
}

char* sub(char* key, kvs *speicher){


    strcpy(subs[s].key, key);
    strcpy(subs[s].value, get(key, speicher));
    sprintf(subs[s].pid, "%d", getpid());
    s++;

    return 0;
}

int del( char* key, kvs *speicher)
{
    int i;
    for(i = 0; i < MAXCHAR; i++)
    {
        if(strcmp(speicher[i].key,key) == 0) //Suche nach dem Key
        {
            break;
        }
    }
    while(i < MAXCHAR ) {
        strcpy(speicher[i].key,speicher[i+1].key); // Das Füllen der Lücken im Array
        strcpy(speicher[i].value,speicher[i+1].key);
        i++;
    }
    c--;

    return 0;
}
