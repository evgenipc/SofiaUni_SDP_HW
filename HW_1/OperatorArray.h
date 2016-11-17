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
#include"Operator.h"
using namespace std;


class OperatorArray {
private:
	Operator* operators;
	int size;
public:
	OperatorArray() { operators = nullptr; size = 0; };
	Operator& operator[](const int);
	void Add(const Operator&);
	void Destroy();
	int getSize() { return size; };
	~OperatorArray();


};


extern OperatorArray operatorsArray;