#include <stdlib.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "phonebook_opt2.h"

entry *findName(char lastname[], entry *pHead[])
{
    unsigned long i;
    i = djb2_hash((unsigned char *)lastname)%SIZE_OF_TABLE;
    entry *e = pHead[i];

    while (e != NULL) {
        if (strcasecmp(lastname, e->lastName) == 0)
            return e;
        e = e->pNext;
    }
    return NULL;
}

void append(entry *pHead[],char lastName[])
{
    entry *e;
    unsigned long i;
    i = djb2_hash((unsigned char *)lastName)%SIZE_OF_TABLE;

    if(pHead[i]==NULL) {
        pHead[i] = (entry *) malloc(sizeof(entry));
        pHead[i]->pNext = NULL;
        strcpy(pHead[i]->lastName,lastName);
        pHead[i]->pDetail = NULL;
    } else {
        for(e=pHead[i]; e->pNext!=NULL; e=e->pNext);
        e->pNext = (entry *) malloc(sizeof(entry));
        e = e->pNext;
        strcpy(e->lastName, lastName);
        e->pNext = NULL;
        e->pDetail = NULL;

    }
}

unsigned long djb2_hash(unsigned char *str)
{
    unsigned long hash = 5381;
    int c;

    while((c = *str++)) {
        hash = ((hash<<5)+hash)+c;   //hash*33+c
    }

    return hash;
}
