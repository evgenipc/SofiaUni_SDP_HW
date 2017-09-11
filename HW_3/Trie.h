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

#ifndef TRIE_H
#define TRIE_H

const int CHARS_SIZE = 27; //26 is the alphabet + space/tab/new line

struct Node
{
	int points;
	char chr;
	Node* children[CHARS_SIZE];

	Node() {
		points = 0;
		for (int i = 0; i<CHARS_SIZE; i++) {
			children[i] = nullptr;
		}

	}
	~Node() {
		for (int i = 0; i < CHARS_SIZE; i++)
		{
			delete children[i];
		}
	}
};


class Trie
{
private:
	
	Node* root;

public:
	Trie() {
		root = new Node;
		
	};
	void addPhrase(const char*,const int); 
	Node* findPhrase(const char*,Node*);

	~Trie();
};


extern Trie dictionery;

#endif // !TRIE_H
