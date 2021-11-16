#ifndef ADD_H
#define ADD_H
#include <iostream>
struct list { int node; struct list* next; };
class ListOfNum
{
public:
    list* head = NULL;
    list* CurrentItem;
    list* LastItem;
    list* helping = head;
    ListOfNum(int StartNum)
    {
        int Value = 1;
        if (head == NULL)
        {
            head = new list;
            head->node = Value++;
            head->next = NULL;
            LastItem = head;
        }
        for (int i = 1; i < StartNum; ++i)
        {
            CurrentItem = new list;
            CurrentItem->node = Value++;
            LastItem->next = CurrentItem;
            CurrentItem->next = NULL;
            LastItem = CurrentItem;
        }
    }
    void push_back(int EndNum);
    void push_front(int StartNum);
    void pop_back();
    void pop_front();
    void remove(int n);
    void at(int id);
    int get_size();
    void clear();
    void set(int pos, int pop);
    bool isEmpty();
    void insert(int pop, int pos);
    void insertList(ListOfNum& list_2, int pos);
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