/* TODO: error handling
 * TODO: Polymorphic
 * TODO: print the name of struct via some macros
 * Date: 2021-01-27
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "person.h"

#define OBJECT_INVALID 1

// Constructor (With out mem allocation)
void Person__init(PersonPtr self, int id, char *name)
{
	self->id = id;
	self->name = name;
}

// Real Initializer (A wrapper of Constructor with Allocation)
PersonPtr Person__create(int id, char *name)
{
	PersonPtr result = (PersonPtr)malloc(sizeof(Person));
	Person__init(result, id, name);
	return result;
}

// set-methods
char *Person__setName(PersonPtr p, char *name)
{
	size_t size = strlen(name);
	char *temp = (char *)malloc(sizeof(char) * size + 1);
	strcpy(temp, name);
	p->name = temp;

	return p->name;
}

//Destructor
void Person__destroy(PersonPtr p)
{
	if (p) {
		free(p);
	}
}

// set-method
int Person__setID(PersonPtr p, int id)
{
	p->id = id;
	return p->id;
}

// .toString()
void Person__toString(PersonPtr p)
{
	printf("{id:%i,name:\"%s\"}\n", p->id, p->name);
}

int main()
{
	PersonPtr slbtty = Person__create(1, "default");

	Person__setName(slbtty, "slbtty");
	Person__toString(slbtty);

	Person__setName(slbtty, "slb Prime");
	Person__setID(slbtty, 2);
	Person__toString(slbtty);

	// =>
	// {id:1,name:"slbtty"}
	// {id:2,name:"slb Prime"}

	Person__destroy(slbtty);

	return 0;
}
