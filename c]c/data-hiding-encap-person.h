#ifndef __PERSON__H__
#define __PERSON__H_

struct Person;
typedef struct Person *pPerson;

pPerson AddName(char *firstname, char *lastname, int age);
void PrintName(pPerson);

#endif


