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

#ifndef OBJECT_H
#define OBJECT_H
#include<iostream>


class Object {
private:

	__int32 key;
	char* str;

public:
	Object() { key = 0; str = nullptr; };
	Object(__int32 key, char* str2)
	{
		str = new char[strlen(str2) + 1];
	strcpy(str, str2);
		this->key = key;
	}
	~Object() { delete str; }

	Object& operator=(const Object&);
	bool operator==(const Object&);
	bool operator!=(const Object&);

	bool operator<(const Object&) const;
	
	__int32 getKey() const { return key; }
	char* getData() const { return str; }

	void print() { std::cout << "-> key:" << key << " str:" << str << std::endl; }

};


#endif // !OBJECT_H
