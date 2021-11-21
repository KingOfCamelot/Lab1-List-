#ifndef ADD_H
#define ADD_H
#include <iostream>
struct node { int info; struct node* next; };
class ListOfNum
{
public:
    node* CurrentItem;
    node* head = NULL;
    node* LastItem;
    ListOfNum(int StartNum)
    {
        int Value = 1;
        if (head == NULL)
        {
            head = new node;
            head->info = Value++;
            head->next = NULL;
            LastItem = head;
        }
        for (int i = 1; i < StartNum; ++i)
        {
            CurrentItem = new node;
            CurrentItem->info = Value++;
            LastItem->next = CurrentItem;
            CurrentItem->next = NULL;
            LastItem = CurrentItem;
        }
    }
    void push_back(int EndNum);
    void push_front(int StartNum);
    void pop_back();
    void pop_front();
    void remove(int index);
    int at(int index);
    int get_size();
    void clear();
    void set(int index, int value);
    bool isEmpty();
    void insert(int value,int index);
    void insertList(ListOfNum& list_2,int index);
    ~ListOfNum()
    {
        if (head != nullptr)
        {
            while (head != nullptr)
            {
                pop_back();
            }
        }
    }
};
#endif