/**
*
* Solution to homework task
* Data Structures Course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2016/2017
*
* @author Evgeni Dimov
* @idnumber 45137
* @task 1
* @compiler VC
*
*/
#include<iostream>
#include"Object.h"


Object& Object::operator=(const Object& other)
{
	if (this != &other)
	{

		this->key = other.key;
		this->str = new char[strlen(other.str) + 1];
		strcpy(this->str, other.str);
	}
	return *this;
}

bool Object::operator==(const Object& other) {
	if (key == other.key && strcmp(str, other.str) == 0)
		return true;
	else
		return false;
}

bool Object::operator!=(const Object & other) {
	if (key == other.key && strcmp(str, other.str) == 0)
		return false;
	else
		return true;
}

bool Object::operator<(const Object& o2) const
{
	if (key < o2.getKey())
		return true;
	else if (key == o2.getKey())
		if (strcmp(str, o2.getData()) < 0)
			return true;
		else
			return false;
	else
		return false;
}