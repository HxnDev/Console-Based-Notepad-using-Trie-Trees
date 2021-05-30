#pragma once
#include<iostream>
#include <string>
#include <cstring>
#include <fstream>
using namespace std;


template <typename T>
struct node 
{
	node<T>* next;
	T data;
};

template <class T>

class List
{
private:
	node<T>* head;
	node<T>* tail;
	node<T>* current;
	int size;
public:
	List()	//Constructor
	{
		head = NULL;
		tail = NULL;
		current = NULL;
		size = 0;
	}


	void InsertFirst(T dataItem)	//Inserts at the start of the list
	{
		node<T>* newnode = new  node<T>;
		newnode->data = dataItem;
		newnode->next = head;
		head = newnode;
		size++;
	}


	void InsertLast(T dataItem)	//Inserts at the end of the list
	{
		node<T>* newnode = new node<T>;

		newnode->data = dataItem;
		newnode->next = NULL;
		if (head == NULL)
		{
			head = newnode;
			tail = newnode;
			newnode = NULL;
		}
		else
		{
			tail->next = newnode;
			tail = newnode;
		}

		size++;
	}


	int returnIndex(const T& DataItem)	//Returns index(position) of the node
	{
		node<T>* current = head;
		int index = 1;

		while (current && current->data != DataItem) 
		{
			current = current->next;
			index++;
		}

		if (current)
			return index - 1;
		return 0;
	}


	void removeFirst()	//Removes at the start of the list
	{
		node<T>* temp = new node<T>;
		temp = head;
		head = head->next;
		delete temp;
	}


	void removeLast()	//Removes the element from the end of the list
	{
		node<T>* current = new node<T>;
		node<T>* previous = new node<T>;
		current = head;
		while (current->next != NULL)
		{
			previous = current;
			current = current->next;
		}
		tail = previous;
		previous->next = NULL;
		delete current;
	}


	void remove(T DT) {		//removes a data item
		if (head->data == DT) 
		{
			removeFirst();
			return;
		}

		if (tail->data == DT) 
		{
			removeLast();
			return;
		}

		node<T>* current2 = head;
		node<T>* temp = current2;

		while (current2 != NULL) 
		{
			if (current2->data == DT) 
			{
				temp->next = current2->next;
				delete current2;
				return;
			}

			else 
			{
				temp = current2;
				current2 = current2->next;
			}
		}

		cout << "Item not found in list" << endl;
	}
	

	void Display()	//Displays the list
	{
		node<T>* newnode = new node<T>;
		newnode = head;
		while (newnode != NULL)
		{
			cout << newnode->data;
			newnode = newnode->next;
			cout << "\n";

		}
	}




	bool isEmpty() {		//Checks if the list is empty
		if (!size)
			return true;

		return false;
	}


	int getSize() {		//total size of list
		return size;
	}


	void clear() {		//clears memory used by list
		node<T>* current2 = head;
		node<T>* temp = current2;

		while (current2 != NULL) 
		{
			current2 = current2->next;
			delete temp;
			temp = current2;
		}

		size = 0;
	}


	T findVal(int index) {		//Returns value at a given index

		node<T>* current = head;
		int count = 0;

		while (current && count < index) {
			current = current->next;
			count++;
		}

		if (current == NULL) {
			cout << "\nIndex is out of range.\n";
		}
		else
			return current->data;
	}


	T operator [](int index) {	//Overloads '[]' operator
		return findVal(index);
	}


	~List()	//Destructor
	{
		node<T>* current2 = head;
		node<T>* temp = current2;

		while (current2 != NULL)
		{
			current2 = current2->next;
			delete temp;
			temp = current2;
		}
	}


};
