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
#include"Object.h"
#include <fstream>
using namespace std;

BinarySearchTree<int, char*> bst;

Object* arr = nullptr;
int arrSize = 0;

void sort(Object arr[], int);
void ReadFromFile(char* directory) 
{
	__int32 key = 0;
	__int32 size = 0;
	char* buff;

	ifstream file(directory, ios::in | ios::binary);
	if (file.is_open())
	{
		while (true)
		{

			file.read((char*)&key, sizeof(__int32));
			file.read((char*)&size, sizeof(__int32));
			buff = new char[size + 1];
			file.read(buff, size);

			if (file.eof())
				break;

			buff[size] = '\0';

			// if(time): Make array resize not shit

			Object* arrTemp = new Object[arrSize + 1];
			for (int i = 0; i < arrSize; ++i)
			{
				arrTemp[i] = arr[i];
			}
			delete[] arr;
			arr = arrTemp;
			arrTemp = nullptr;

			arr[arrSize] = Object(key, buff);
			++arrSize;
			delete[] buff;
			buff = nullptr;
			size = 0;
		}

		file.close();
		sort(arr, arrSize);
		bst.build(arr, arrSize);
		bst.print();

	}
	else cout << "Unable to open file";
}
 // if(time): change bubble to faster sort algorithm
void sort(Object arr[], int size) {
	bool swap= true;
	Object tmp;
	while (swap== true) {
		swap = false;
		for (int i = 0; i < size - 1; ++i)
			if (arr[i + 1] < arr[i]) {
				tmp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = tmp;
				swap = true;
			}
	}
}



//ADD SORT ARRAY