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


#ifndef OPERATOR_H
#define OPERATOR_H

class Operator {
private:
	char symbol;
	char operatorSymbol;
	int asociativ;


public:
	Operator() {};
	Operator(char, char, int);
	~Operator() {};
	char getSymbol() { return symbol; };
	char getOperatorSymbol() { return operatorSymbol; };
	int getAsociativ() {return asociativ;};
	Operator& operator=(const Operator&);

};






#endif