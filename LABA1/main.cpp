#include <iostream>
#include "FunctionHeaders.h"
using namespace std;
void ListOfNum::push_back(int EndNum)
{
    list* elem = new list;
    elem->node = EndNum;
    if (head == nullptr)
    {
        head = elem;
        LastItem = elem;
        elem->next = nullptr;
    }
    else
    {
        LastItem->next = elem;
        LastItem = elem;
    }
}
void ListOfNum::push_front(int StartNum)
{
    list* elem = new list;
    elem->node = StartNum;
    if (head == nullptr)
    {
        head = elem;
        LastItem = elem;
        elem->next = nullptr;
    }
    else
    {
        elem->next = head;
        head = elem;
    }
}
void ListOfNum::pop_back()
{
    list* temp = head;
    list* prev = NULL;
    while (temp->next)
    {
        prev = temp;
        temp = temp->next;
    }
    if (prev) prev->next = NULL;
    else head = NULL;
    if (temp) delete temp;
}
void ListOfNum::pop_front()
{
    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        LastItem = nullptr;
    }
    else 
    {
        list* first = head->next;
        delete head;
        head = first;
    }
}
void ListOfNum::remove(int n)
{
    CurrentItem = head;
    list* previositem = 0;
    for (int i = 0; i < n; ++i)
    {
        previositem = CurrentItem;
        CurrentItem = CurrentItem->next;
    }
    previositem->next = CurrentItem->next;
    delete CurrentItem;
}
void ListOfNum::at(int id) 
{
    int i = 0;
    list* tmp_ptr = head;
    while (i < id) 
    {
        tmp_ptr = tmp_ptr->next;
        i++;
    }
    CurrentItem->node = tmp_ptr->node;
    cout << endl << "Element to index " << id << ": " << tmp_ptr->node << endl;
}
int ListOfNum::get_size()
{
    if (isEmpty()) return 0;
    int size = 1;
    list* tmp_ptr = head;
    while (tmp_ptr->next != nullptr) 
    {
        tmp_ptr = tmp_ptr->next;
        size++;
    }
    CurrentItem->node = size;
    return size;
}
void ListOfNum::set(int pos, int pop)
{
    CurrentItem = head;
    for (int i = 1; i <= pos; ++i)
    {
        if (i == pos) CurrentItem->node = pop;
        CurrentItem = CurrentItem->next;
    }
}
bool ListOfNum::isEmpty()
{
    CurrentItem = head;
    return CurrentItem == nullptr;
}
void ListOfNum::clear()
{
    if (head != nullptr) 
    {
        while (head != nullptr) 
        {
            pop_back();
        }
    }
}
void ListOfNum::insert(int pop, int pos)
{
    list* newel = new list;
    newel->node = pop;
    if (pos == 1)
    {
        newel->next = head;
        head = newel;
    }
    else
    {
        list* before = head;
        for (int i = 0; i < pos - 1; i++)
            before = before->next;

        newel->next = before->next;
        before->next = newel;
    }
}
void ListOfNum::insertList(ListOfNum& list_2, int pos)
{
    int pos2 = pos;
    CurrentItem = head;
    list_2.CurrentItem = list_2.head;
    for (int i = 1; i <= 14; ++i)
    {
        if (i == pos)
        {
            for (int j = 1; j <= 4; ++j)
            {
                insert(list_2.CurrentItem->node, pos2);
                pos2++;
                list_2.CurrentItem = list_2.CurrentItem->next;
            }
        }
    }
}
int main()
{
    ListOfNum list_1 = ListOfNum(10);
    ListOfNum list_2 = ListOfNum(4);
    list_1.CurrentItem = list_1.head;
    cout << "List #1: ";
    for (int i = 1; i <= 10; ++i)
    {
        cout << list_1.CurrentItem->node << " | ";
        list_1.CurrentItem = list_1.CurrentItem->next;
    }
    list_2.CurrentItem = list_2.head;
    cout << endl << "List #2: ";
    for (int i = 1; i <= 4; ++i)
    {
        cout << list_2.CurrentItem->node << " | ";
        list_2.CurrentItem = list_2.CurrentItem->next;
    }
    list_1.push_back(23);
    list_1.push_front(56);
    list_1.pop_back();
    list_1.pop_front();
    list_1.remove(3);
    list_1.insert(45, 4);
    list_1.at(3);
    list_1.clear();
    list_1.get_size();
    list_1.get_size();
    list_1.set(5, 23);
    list_1.insertList(list_2, 3);
    cout << endl << "List #1 after Insert List: ";
    list_1.CurrentItem = list_1.head;
    for (int i = 1; i <= 14; ++i)
    {
        cout << list_1.CurrentItem->node << " | ";
        list_1.CurrentItem = list_1.CurrentItem->next;
    }
    return 0;
}