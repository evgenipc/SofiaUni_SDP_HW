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


#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include<iostream>
#include"Object.h"
template <typename KeyType,typename DataType>

class BinarySearchTree {
private:
	struct Node {
		KeyType key;
		DataType data;
		Node* left;
		Node* right;
		Node() :left(nullptr), right(nullptr) {}
	};
	Node* root;
	int size;

public:
	BinarySearchTree() { root = nullptr; }
	void build(Object arr[], int arrSize)
	{
		buildSelfbalanced(arr,0, arrSize-1);
	}
	~BinarySearchTree() { del(root); }
	void insert(const KeyType key, const DataType data)
	{	
		insertPrivate(key, data, root);
	}
	void remove(const KeyType key,const DataType data)
	{
		removePrivate(key,data, root);
	}
	void removeAll(const KeyType key)
	{
		removeAllPrivate(key, root);
	}
	bool search(const KeyType key, const DataType data)
	{
		return searchPrivate(key, data, root);
	}
	int getSize() { return size; }
	void print()
	{
		printPrivate(root,1);
	}

private:

	void buildSelfbalanced(Object arr[], int start,int end)
	{
		if (start > end)
			return;
		int mid = (start + end) / 2;

		insert(arr[mid].getKey(), arr[mid].getData());

			buildSelfbalanced(arr, start,mid-1);
			buildSelfbalanced(arr,mid+1,end);
	}

	void insertPrivate(const KeyType key, const DataType data, Node*& tree)
	{
		if (!tree)
		{
			tree = new Node;
			tree->key = key;
			tree->data = new char[strlen(data) + 1];
			strcpy(tree->data,(char*)data);
			tree->data[strlen(data)] = '\0';
			++size;
		}
		else if (key < tree->key || (key==tree->key && strcmp(data,tree->data)<0))
			insertPrivate(key, data, tree->left);
		else if (key > tree->key || (key==tree->key && strcmp(data, tree->data)>0))
			insertPrivate(key, data, tree->right);
	}

	void removePrivate(const KeyType key,const DataType data, Node*& tree)
	{
		if (!tree)
			std::cout << "Not found to delete!" << std::endl;
		else if (key == tree->key && strcmp(data,tree->data)==0)
		{
			Node* delLeaf = tree;
			if (!tree->left)
				tree = tree->right;
			else if (!tree->right)
				tree = tree->left;
			else
			{
				Node* maxLeft = getMax(tree->left);
				maxLeft->left = tree->left;
				maxLeft->right = tree->right;
				tree = maxLeft;
			}
			--size;
				delete delLeaf;
			std::cout << "Removed!" << std::endl;
		}
		else if (key < tree->key ||
				(key == tree->key && strcmp(data, tree->data) < 0))
			removePrivate(key,data, tree->left);
		else if (key > tree->key || 
				(key == tree->key && strcmp(data, tree->data) > 0))
			removePrivate(key,data, tree->right);
	}

	void removeAllPrivate(const KeyType key, Node*& tree) 
	{
		if (!tree)
			return;
		else if (key == tree->key)
		{
			Node* delLeaf = tree;
			if (!tree->left)
				tree = tree->right;
			else if (!tree->right)
				tree = tree->left;
			else
			{
				Node* maxLeft = getMax(tree->left);
				maxLeft->left = tree->left;
				maxLeft->right = tree->right;
				tree = maxLeft;
			}
			--size;
				delete delLeaf;
			removeAllPrivate(key, tree);
		}
		else if (key < tree->key)
			removeAllPrivate(key, tree->left);
		else if (key > tree->key)
			removeAllPrivate(key, tree->right);
	}

	bool searchPrivate(const KeyType key, const DataType data, Node*& tree)
	{
		if (!tree)
			return false;
		else if (key == tree->key && strcmp(data, tree->data) == 0)
			return true;
		else if (key < tree->key || (key == tree->key && strcmp(data, tree->data) < 0))
			return searchPrivate(key, data, tree->left);
		else if (key > tree->key || (key == tree->key && strcmp(data, tree->data) > 0))
			return searchPrivate(key, data, tree->right);
	}

	void printPrivate(Node* tree,int depth)
	{
		if (!tree)
			return;
		printf("%*d \n", depth, tree->key);
			printPrivate(tree->left,++depth);

			printPrivate(tree->right,depth);
	}

	Node* getMin(Node*& tree)
	{
		if (tree->left)
			getMin(tree->left);
		
		Node* answer = tree;
		tree = tree->right;
		return answer;
	}

	Node* getMax(Node*& tree)
	{
		if (tree->right)
			getMax(tree->right);

		Node* answer = tree;
		tree = tree->left;
		return answer;
	}

	void del(Node*& root)
	{
		if (root) {
			del(root->left);
			del(root->right);
			delete root;
		}
	}

};
 

#endif // !BINARYTREE_H
