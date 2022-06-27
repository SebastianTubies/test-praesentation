#ifndef CLION_KEYVALUE_H
#define CLION_KEYVALUE_H

#define MAXCHAR 32
#define MAXSUBS 40


typedef struct KeyValueStore
{
    char key[MAXCHAR];
    char value[MAXCHAR];
    char pid[MAXCHAR];
} kvs;

kvs subs[MAXSUBS];



int put(char* key, char *value, kvs *speicher);
char* get(char* key, kvs *speicher);
int del(char* key, kvs *speicher);
char* sub(char* key, kvs *speicher);




#endif //CLION_KEYVALUE_H



