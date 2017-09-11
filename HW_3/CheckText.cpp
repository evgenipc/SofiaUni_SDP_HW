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
#include"CheckText.h"
#include"Trie.h"


void readText(char* dir) {

	char wordBuff[256];
	Node* current = nullptr;
	int currentPoints=0;

	int numberOfWords = 0;
	int points = 0;

	std::ifstream textFile(dir);
	if (textFile.is_open())
	{
		while (!textFile.eof())
		{

			textFile >> wordBuff;
			numberOfWords++;
			current = dictionery.findPhrase(wordBuff, current);


			if (current != nullptr)
			{
				currentPoints = current->points;
			}
			else
			{
				points += currentPoints;
				currentPoints = 0;
				current = dictionery.findPhrase(wordBuff, nullptr);
				if (current != nullptr)
				{
					currentPoints = current->points;
				}
			}
		



		}
		points += currentPoints;
	}

	std::cout << points/numberOfWords << std::endl;

}