#pragma once
using namespace std;
struct Node
{
	int data;
	Node* next;
	Node* prev;
};

class doubleLinkedList
{
private:
	Node* head;
public:
	Node* getNewNode(int x);
	void insertAtBeginning(int x);
	void insertAtEnd(int x);
	void insertAtNthNode(int x, int n);
	void deleteNthNode(int n);
	void printForawrdByIteration();
	void printReverseByIteration();
	void printForwardByRecursion(Node* head);
	void printReverseByRecursion(Node* head);
	Node* getHead();
	doubleLinkedList();
};

