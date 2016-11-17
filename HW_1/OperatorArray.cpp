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
#include"OperatorArray.h"

void OperatorArray::Add(const Operator& obj)
{
	Operator* tmp= new Operator[size + 1];
	for (int i = 0; i < size; ++i)
	{
		tmp[i] = operators[i];
	}
	tmp[size] = obj;
	delete[] operators;
	operators = tmp;
	tmp = nullptr;
	size += 1;
}

Operator& OperatorArray::operator[](const int index) {
	if (index >= 0 && index < size) {
		return operators[index];
	}
	else throw 420;
}

void OperatorArray::Destroy()
{
	delete[] operators;
	size = 0;
}
OperatorArray::~OperatorArray() {
	Destroy();
}

