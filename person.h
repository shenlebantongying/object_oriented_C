/* Date: 2021-01-27
 */

#ifndef _PERSON_H_
#define _PERSON_H_

typedef struct person{ // tag name
	int id;
	char *name;
} Person;

typedef Person *PersonPtr; // A ptr to Person struct.

PersonPtr Person__create(int id, char *name);
void Person__destroy(PersonPtr p);

char * Person__setName(PersonPtr p, char *name);
int Person__setID(PersonPtr p, int id);

void Person__toString(PersonPtr p);

#endif //_PERSON_H_
