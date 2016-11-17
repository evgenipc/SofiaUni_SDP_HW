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
#include"OperatorArray.h"
#include<fstream>
using namespace std;

OperatorArray operatorsArray;

void ParseLine(char buff[6]);

void ReadFromFile1(char* directory) {
	if (directory != nullptr)
	{
		ifstream myFile;
		myFile.open(directory);
		char buff[6];

		if (myFile.is_open()) {
			while (!myFile.eof()) {

				myFile.getline(buff, 6);
				ParseLine(buff);

			}
		}
		myFile.close();
	}
}
void ParseLine(char buff[6]) {
	Operator* tmp = new Operator(buff[0], buff[2], buff[4] - '0');

	operatorsArray.Add(*tmp);

}