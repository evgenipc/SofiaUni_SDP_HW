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

int charToIndex(const char chr)
{
	if (chr >= 65 && chr <= 90)
		return chr + 32 - 'a';
	else if (chr == ' ' || chr == 9 || chr == 10)
		return CHARS_SIZE-1;
	else
		return chr - 'a';
}

void Trie::addPhrase(const char* str,const int newPoints)
{
	Node* loc = root;
	int len = strlen(str);
	
	for (int i = 0; i < len; i++) {
		int idx = charToIndex(str[i]);

		if (loc->children[idx] == nullptr) {
			loc->children[idx] = new Node();
			loc->children[idx]->chr = str[i];
		}
		loc = loc->children[idx];
	}
	loc->points = newPoints;
}

Node* Trie::findPhrase(const char* str,Node* newRoot)
{
	Node* loc;
	if (newRoot == nullptr)
		loc = root;
	else
		//skip the space if it's not the first checked word

		if (newRoot->children[26])
			loc = newRoot->children[26]; //one space ahead
		else
			return nullptr;

	int len = strlen(str);
	//if the last char of the string is one of there skip it

	if (str[len-1] == '.' || str[len-1] == '!' || str[len-1] == ',' || str[len-1] == '?')
		len--;

	for (int i = 0; i < len; i++) {
		int idx = charToIndex(str[i]);

		if (!loc->children[idx]) {
			return nullptr;
		}
		loc = loc->children[idx];
	}
	return loc;
	
}


Trie::~Trie()
{
	delete root;
}
