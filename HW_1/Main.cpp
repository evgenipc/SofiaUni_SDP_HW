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


#include <iostream>
#include "Operator.h"




void ReadFromFile1(char*);
void ReadFromFile2(char*);

int main(int argc, char** argv)
{

	//ReadFromFile1(argv[2]);
	//ReadFromFile2(argv[1]);

	ReadFromFile1("text.txt");
	ReadFromFile2("text2.txt");
	system("PAUSE");
	return 0;
}