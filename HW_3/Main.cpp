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
#include"Trie.h"
#include"LoadDictionery.h"
#include"CheckText.h"

using std::cout;

int main(int argc,char** argv) {
	
	loadDictionery(argv[1]);
	readText(argv[2]);
	int i=2;
	
	for(int i=2;i<argc;++i)
	{
		readText(argv[i]);
	}
}