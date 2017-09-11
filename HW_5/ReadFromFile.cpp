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
#include<fstream>


BinarySearchTree* ReadFromFile(char* directory, BinarySearchTree*& first)
{
	__int64 key = 0;
	char* buff;

	std::ifstream file(directory, std::ios::in | std::ios::binary);
	if (file.is_open())
	{
		BinarySearchTree* result = new BinarySearchTree;
		while (true)
		{

			file.read((char*)&key, sizeof(__int64));
			if (file.eof())
				break;
			
			if (!first ||first->search(key))
			{
				if(key>0)
				result->insert(key);
			}
		}
		delete first;
		file.close();
		return result;

	}
	else
	{
		std::cout << "Unable to open file" << std::endl;
		return nullptr;
	}
}