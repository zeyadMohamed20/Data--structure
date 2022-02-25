#include<iostream>
using namespace std;

struct node
{
    int data;
    node* next;
};

void insert_at_beginning(int x, node** pointerToHead)
{
    node* temp = new node();
    temp->data = x;
    temp->next = *pointerToHead;
    *pointerToHead = temp;
}

void insert_at_end(int x, node** pointerToHead)
{
    node* temp = new node();
    temp->data = x;
    temp->next = nullptr;
    if (*pointerToHead == nullptr)
        *pointerToHead = temp;
    else
    {
        node* temp1 = *pointerToHead;
        while (temp1->next != nullptr)
            temp1 = temp1->next;
        temp1->next = temp;
    }
}

void insert_at_nth_position(int x, int n, node** pointerToHead)
{
    node* temp = new node();
    temp->data = x;
    node* temp1 = *pointerToHead;
    if (n == 1)
    {
        temp->next = *pointerToHead;
        *pointerToHead = temp;
    }
    else
    {
        for (int i = 0; i < n - 2; i++)
            temp1 = temp1->next;
        temp->next = temp1->next;
        temp1->next = temp;
    }
}

void delete_at_nth_position(int n, node** pointerToHead)
{
    node* temp1 = *pointerToHead;
    if (n == 1)
    {
        *pointerToHead = temp1->next;
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

void reverse_iteration(node* *pointerToHead)
{
    node* current = *pointerToHead;
    node* prev = nullptr;
    node* next;
    while (current != nullptr)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *pointerToHead = prev;
}

void print_by_iteration(node** pointerToHead)
{
    node* temp = *pointerToHead;
    cout << "List is: ";
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void print_forward_by_recursion(node* head)
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

void print_reverse_by_recursion(node* head)
{
    if (head == nullptr)
    {
        return;
    }
    else
    {
        print_reverse_by_recursion(head->next);
        cout << head->data << " ";
    }
}

node* reverse_recursion(node* p)
{
    node* head;
    if (p->next == nullptr)
    {
        head = p;
        return head;
    }
    else
    {
        head = reverse_recursion(p->next);
        node* q = p->next;
        q->next = p;
        p->next = nullptr;
        return head;
    }
}