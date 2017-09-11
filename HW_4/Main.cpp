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
#include"BinarySearchTree.h"
#include"ReadFromFile.h"
#include"CommandsHandle.h"


int main(int argc, char *argv[])
{

	ReadFromFile(argv[1]);

	CheckCommand();

	system("pause");
	return 0;
}