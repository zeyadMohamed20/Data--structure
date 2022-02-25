#include "singleLinkedList.h"
#include<iostream>
using namespace std;


void singleLinkedList::insert_at_beginning(int x)
{
    node* temp = new node();
    temp->data = x;
    temp->next = head;
    head = temp;
}

void singleLinkedList::insert_at_end(int x)
{
    node* temp = new node();
    temp->data = x;
    temp->next = nullptr;
    if (head == nullptr)
        head = temp;
    else
    {
        node* temp1 = head;
        while (temp1->next != nullptr)
            temp1 = temp1->next;
        temp1->next = temp;
    }
}

void singleLinkedList::insert_at_nth_position(int x, int n)
{
    node* temp = new node();
    temp->data = x;
    node* temp1 = head;
    if (n == 1)
    {
        temp->next = head;
        head = temp;
    }
    else
    {
        for (int i = 0; i < n - 2; i++)
            temp1 = temp1->next;
        temp->next = temp1->next;
        temp1->next = temp;
    }
}

void singleLinkedList::delete_at_nth_position(int n)
{
    node* temp1 = head;
    if (n == 1)
    {
        head = temp1->next;
        delete temp1;
    }
    else
    {
        for (int i = 0; i < n - 2; i++)
            temp1 = temp1->next;
        node* temp2 = temp1->next;
        temp1->next = temp2->next;
        delete temp2;
    }
}

void singleLinkedList::reverse_iteration()
{
    node* current = head;
    node* prev = nullptr;
    node* next;
    while (current != nullptr)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

void singleLinkedList::reverse_recursion(node* p)
{
    p = head;
    if (p->next == nullptr)
    {
        head = p;
    }
    else
    {
        reverse_recursion(p->next);
        node* q = p->next;
        q->next = p;
        p->next = nullptr;
    }
}

void singleLinkedList::print_by_iteration()
{
    node* temp = head;
    cout << "List is: ";
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void singleLinkedList::print_forward_by_recursion(node* head)
{
    if (head == nullptr)
    {
        cout << endl;
        return;
    }
    else
    {
        cout << head->data << " ";
        print_forward_by_recursion(head->next);
    }
}

void singleLinkedList::print_reverse_by_recursion(node* head)
{
    if (head == nullptr)
        return;
    else
    {
        print_reverse_by_recursion(head->next);
        cout << head->data << " ";
    }
}

node* singleLinkedList::get_head()
{
    return head;
}

singleLinkedList::singleLinkedList() : head(nullptr)
{
}
