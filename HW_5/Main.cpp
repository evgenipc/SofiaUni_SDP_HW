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
#include"ReadFromFile.h"
#include"BinarySearchTree.h"


int main()
{
	int n = 0;
	std::cin >> n;
	std::cin.ignore();
	char** directories = new char*[n];
	BinarySearchTree* current = nullptr;

	for (int i = 0; i < n; ++i)
	{
		directories[i] = new char[1024];
		std::cin.getline(directories[i], 1024);
		current = ReadFromFile(directories[i], current);
	}
	current->print();
	return 0;
}