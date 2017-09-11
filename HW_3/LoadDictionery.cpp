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
#include<fstream>
#include<cstring>
#include"LoadDictionery.h"
#include"Trie.h"

using std::cout;

const int EXPRESION_BUFFER_SIZE = 1024;
Trie dictionery = Trie();

void loadDictionery(char* dir)
{

	char buff[EXPRESION_BUFFER_SIZE];

	std::ifstream dictioneryFile(dir);
	if (dictioneryFile.is_open())
	{
		while (!dictioneryFile.eof())
		{
			dictioneryFile.getline(buff,EXPRESION_BUFFER_SIZE);

			int numIdx = (int)(strrchr(buff,' ')-buff+1);

			char* str = new char[numIdx];
			strncpy(str, buff, numIdx -1);
			str[numIdx -1] = '\0';

			dictionery.addPhrase(str, atoi(strrchr(buff, ' ') + 1));

			delete[] str;
		}
		dictioneryFile.close();
	}

	else cout << "Cant open file";

}













