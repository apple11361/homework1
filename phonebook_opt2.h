#ifndef _PHONEBOOK2_H
#define _PHONEBOOK2_H

#define SIZE_OF_TABLE 10000
#define MAX_LAST_NAME_SIZE 16
#define OPT2 1

typedef struct __PHONE_BOOK_ENTRY_DETAIL {
    char firstName[16];
    char email[16];
    char phone[10];
    char cell[10];
    char addr1[16];
    char addr2[16];
    char city[16];
    char state[2];
    char zip[5];
} detail;

typedef struct __PHONE_BOOK_ENTRY {
    char lastName[MAX_LAST_NAME_SIZE];
    detail *pDetail;
    struct __PHONE_BOOK_ENTRY *pNext;
} entry;

unsigned long djb2_hash(unsigned char *str);
entry *findName(char lastname[], entry *pHead[]);
void append(entry *pHead[],char lastName[]);


#endif
