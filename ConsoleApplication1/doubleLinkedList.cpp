#include "doubleLinkedList.h"
#include<iostream>
using namespace std;

Node* doubleLinkedList::getNewNode(int x)
{
	Node* newNode = new Node();
	newNode->data = x;
	newNode->next = nullptr;
	newNode->prev = nullptr;
	return newNode;
}

void doubleLinkedList::insertAtBeginning(int x)
{
	Node* newNode = getNewNode(x);
	if (head == nullptr)
		head = newNode;
	else
	{
		newNode->next = head;
		head->prev = newNode;
		head = newNode;
	}
}

void doubleLinkedList::insertAtEnd(int x)
{
	Node* newNode = getNewNode(x);
	if (head == nullptr)
		head = newNode;
	else
	{
		Node* temp1 = head;
		while (temp1->next != nullptr)
			temp1 = temp1->next;
		newNode->prev = temp1;
		temp1->next = newNode;
	}
}

void doubleLinkedList::insertAtNthNode(int x, int n)
{
	Node* newNode = getNewNode(x);
	if (n == 1)
	{
		newNode->next = head;
		head->prev = newNode;
		head = newNode;
	}
	else
	{
		Node* temp1 = head;
		for (int i = 0; i < n - 1; i++)
			temp1 = temp1->next;
		newNode->next = temp1;
		newNode->prev = temp1->prev;
		(temp1->prev)->next = newNode;
		temp1->prev = newNode;
	}
}

void doubleLinkedList::deleteNthNode(int n)
{
	Node* temp1 = head;
	if (n == 1)
	{
		head = temp1->next;
		(temp1->next)->prev = nullptr;
		delete temp1;
	}
	else
	{
		for (int i = 0; i < n - 1; i++)
			temp1 = temp1->next;
		(temp1->prev)->next = temp1->next;
		(temp1->next)->prev = temp1->prev;
		delete temp1;

	}
}

void doubleLinkedList::printForawrdByIteration()
{
	Node* temp1 = head;
	while (temp1 != nullptr)
	{
		cout << temp1->data << " ";
		temp1 = temp1->next;
	}
	cout << endl;
}

void doubleLinkedList::printReverseByIteration()
{
	Node* temp1 = head;
	while (temp1->next != nullptr)
		temp1 = temp1->next;
	while (temp1 != nullptr)
	{
		cout << temp1->data << " ";
		temp1 = temp1->prev;
	}
	cout << endl;
}

void doubleLinkedList::printForwardByRecursion(Node* head)
{
	if (head == nullptr)
	{
		cout << endl;
		return;
	}
	else
	{
		cout << head->data << " ";
		printForwardByRecursion(head->next);
	}
}

void doubleLinkedList::printReverseByRecursion(Node* head)
{
	if (head == nullptr)
		return;
	else
	{
		printReverseByRecursion(head->next);
		cout << head->data << " ";
	}
}

Node* doubleLinkedList::getHead()
{
	return head;
}

doubleLinkedList::doubleLinkedList():head(nullptr)
{
}