#pragma once
using namespace std;
struct node
{
    int data;
    node* next;
};

void insert_at_beginning(int x, node** pointerToHead);
void insert_at_end(int x, node** pointerToHead);
void insert_at_nth_position(int x, int n, node** pointerToHead);
void delete_at_nth_position(int n, node** pointerToHead);
void reverse_iteration(node** pointerToHead);
void print_by_iteration(node** pointerToHead);
void print_forward_by_recursion(node* head);
void print_reverse_by_recursion(node* head);
node* reverse_recursion(node* p);
