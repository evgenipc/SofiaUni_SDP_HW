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
#include "Operator.h"

using namespace std;

Operator::Operator(char symbol, char operatorSymbol, int asociativ)
{
	this->symbol = symbol;
	this->operatorSymbol = operatorSymbol;
	this->asociativ = asociativ;
}

Operator& Operator::operator=(const Operator& other)
{
	if (this != &other) {
		symbol = other.symbol;
		operatorSymbol = other.operatorSymbol;
		asociativ = other.asociativ;
	}
	return *this;
}