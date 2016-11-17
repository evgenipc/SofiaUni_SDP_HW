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


#ifndef STACK_H
#define STACK_H

template <typename T>
class Stack 
{
private:
	struct Node 
	{
		T m_data;
		Node* m_next;
	};
	Node* last;
public:
	Stack() : last(nullptr) {};
	bool isEmpty();
	void push(const T&);
	void pop();
	T& top();
	~Stack();

};


 template<typename T>
inline bool Stack<T>::isEmpty() {
	if (last == nullptr)
		return true;
	else
		return false;
}

template<typename T>
inline void Stack<T>::push(const T& data)
{
	Node* tmp = new Node;
	tmp->m_data = data;
	tmp->m_next = last;
	last = tmp;
}

template<typename T>
inline void Stack<T>::pop()
{
	if (!isEmpty())
	{
		Node* tmp = last;
		last = last->m_next;  
		delete tmp;
	}
	else throw 420;
}

template<typename T>
inline T & Stack<T>::top()
{
	if (!isEmpty())
	{
		return last->m_data;
	}
	else throw 420;
}

template<typename T>
inline Stack<T>::~Stack()
{
	while (!isEmpty())
	{
		pop();

	}
	delete last;
}

#endif
