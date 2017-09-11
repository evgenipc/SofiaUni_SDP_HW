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
#include"CommandsHandle.h"
#include"ReadFromFile.h"
using std::cin;
using std::cout;

char buff[2048];

void CheckCommand() {

	int i = 0;
	cin.get(buff[0]);
	while (buff[i] != ' ')
	{
		++i;
		cin.get(buff[i]);

	}
	buff[i + 1] = '\0';


	if (strncmp(buff,"add",3) == 0)
	{
		i = 0;
		int key = 0;
		do
		{
			cin.get(buff[i]);
			++i;
		} while (buff[i - 1] != ' ');
		buff[i - 1] = '\0';
		key = atoi(buff);
		
		cin.getline(buff, 2048);
		bst.insert(key, buff);
		bst.print();

		CheckCommand();
	}
	else if (strncmp(buff, "removeall",9) == 0)
	{
		i = 0;
		int key = 0;
		do
		{
			cin.get(buff[i]);
			++i;
		} while (buff[i - 1] != '\n');
		buff[i - 1] = '\0';

		key = atoi(buff);
		int size = bst.getSize();
		bst.removeAll(key);
		cout << size - bst.getSize() << std::endl;
		cout<<std::endl;
		bst.print();
		CheckCommand();
	}
	else if (strncmp(buff, "search",6) == 0)
	{
		i = 0;
		int key = 0;
		do
		{
			cin.get(buff[i]);
			++i;
		} while (buff[i - 1] != ' ');
		buff[i - 1] = '\0';

		key = atoi(buff);
		cin.getline(buff, 2048);

		

		bool answer= bst.search(key, buff);
		if (answer == true)
			cout << "true" << std::endl;
		else
			cout << "false" << std::endl;
		bst.print();
		CheckCommand();
	}
	else if (strncmp(buff, "remove", 6) == 0)
	{
		i = 0;
		int key = 0;
		do
		{
			cin.get(buff[i]);
			++i;
		} while (buff[i - 1] != ' ');
		buff[i - 1] = '\0';
		key = atoi(buff);
		cin.getline(buff, 2048);
		bst.remove(key, buff);
		bst.print();
		CheckCommand();
	}
	else
	{
		cout << "Wrong command!Try again!" << std::endl;
		cin.getline(buff,2048);
		CheckCommand();
	}

}

bool cmpnPrefix(const char* lhs, const char* rhs)
{
	int lhsLen = strlen(lhs);
	int rhsLen = strlen(rhs);
	int n = 0;
	if (lhsLen > rhsLen)
		n = rhsLen;
	else n = lhsLen;
	for (int i = 0; i < n; ++i)
	{
		if (lhs[i] != rhs[i])
			return false;
	}
	return true;
}