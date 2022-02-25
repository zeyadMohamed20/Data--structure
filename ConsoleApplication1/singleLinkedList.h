#pragma once
using namespace std;

struct node
{
    int data;
    node* next;
};

class singleLinkedList
{
private:
    node* head;
public:
    void insert_at_beginning(int x);
    void insert_at_end(int x);
    void insert_at_nth_position(int x, int n);
    void delete_at_nth_position(int n);
    void reverse_iteration();
    void reverse_recursion(node* p);
    void print_by_iteration();
    void print_forward_by_recursion(node* head);
    void print_reverse_by_recursion(node* head);
    node* get_head();
    singleLinkedList();
};