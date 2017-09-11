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
class BinarySearchTree {
private:
	struct Node {
		__int64 key;
		Node* left;
		Node* right;
		Node() :left(nullptr), right(nullptr) {}
	};
	Node* root;
	int size;

public:
	BinarySearchTree() { root = nullptr; }
	~BinarySearchTree() { del(root); }
	void insert(const __int64 key)
	{
		insertPrivate(key, root);
	}
	void remove(const __int64 key)
	{
		removePrivate(key, root);
	}
	bool search(const __int64 key)
	{
		return searchPrivate(key, root);
	}
	int getSize() { return size; }
	void print()
	{
		printPrivate(root, 1);
	}

private:


	void insertPrivate(const __int64 key, Node*& tree)
	{
		if (!tree)
		{
			tree = new Node;
			tree->key = key;
			++size;
		}
		else if (key < tree->key)
			insertPrivate(key, tree->left);
		else if (key > tree->key)
			insertPrivate(key, tree->right);
	}

	void removePrivate(const __int64 key, Node*& tree)
	{
		if (!tree)
			std::cout << "Not found to delete!" << std::endl;
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
			std::cout << "Removed!" << std::endl;
		}
		else if (key < tree->key)
			removePrivate(key, tree->left);
		else if (key > tree->key)
			removePrivate(key, tree->right);
	}


	bool searchPrivate(const __int64 key, Node*& tree)
	{
		if (!tree)
			return false;
		else if (key == tree->key)
			return true;
		else if (key < tree->key)
			return searchPrivate(key,tree->left);
		else if (key > tree->key)
			return searchPrivate(key, tree->right);
	}

	void printPrivate(Node* tree, int depth)
	{
		if (!tree)
			return;
		printf("%*d \n", depth, tree->key);
		printPrivate(tree->left, ++depth);

		printPrivate(tree->right, depth);
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
