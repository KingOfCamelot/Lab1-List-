#include <iostream>
#include "MethodDeclaration.h"
using namespace std;
void ListOfNum::push_back(int EndNum)
{
    node* elem = new node;
    elem->info = EndNum;
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
    node* elem = new node;
    elem->info = StartNum;
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
    if (head == nullptr) throw invalid_argument("List empty");
    node* temp = head;
    node* prev = NULL;
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
    if (head == nullptr) throw invalid_argument("List empty");
    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        LastItem = nullptr;
    }
    else 
    {
        node* first = head->next;
        delete head;
        head = first;
    }
}
void ListOfNum::remove(int index)
{
    if (index > get_size()) throw invalid_argument("Your index > size of list");
    if (index <= 0) throw invalid_argument("Your index <= 0");
    CurrentItem = head;
    node* previositem = 0;
    for (int i = 0; i < index; ++i)
    {
        previositem = CurrentItem;
        CurrentItem = CurrentItem->next;
    }
    previositem->next = CurrentItem->next;
    delete CurrentItem;
}
int ListOfNum::at(int index)
{
    if (index > get_size()) throw invalid_argument("Your index > size of list");
    if (index <= 0) throw invalid_argument("Your index <= 0");
    int i = 0;
    node* tmp_ptr = head;
    while (i < index)
    {
        tmp_ptr = tmp_ptr->next;
        i++;
    }
    CurrentItem->info = tmp_ptr->info;
    return tmp_ptr->info;
}
int ListOfNum::get_size()
{
    if (isEmpty())
    {
        CurrentItem->info = 0;
        return 0;
    }
    int size = 1;
    node* tmp_ptr = head;
    while (tmp_ptr->next != nullptr) 
    {
        tmp_ptr = tmp_ptr->next;
        size++;
    }
    CurrentItem->info = size;
    return size;
}
void ListOfNum::set(int index, int value)
{
    if (index > get_size()) throw invalid_argument("Your index > size of list");
    if (index <= 0) throw invalid_argument("Your index <= 0");
    CurrentItem = head;
    for (int i = 1; i <= index; ++i)
    {
        if (i == index) CurrentItem->info = value;
        CurrentItem = CurrentItem->next;
    }
}
bool ListOfNum::isEmpty()
{
    return head == nullptr;
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
void ListOfNum::insert(int value,int index)
{
    if (index > get_size()) throw invalid_argument("Your index > size of list");
    if (index <= 0) throw invalid_argument("Your index <= 0");
    node* newel = new node;
    newel->info = value;
    if (index == 1)
    {
        newel->next = head;
        head = newel;
    }
    else
    {
        node* before = head;
        for (int i = 0; i < index - 1; i++)
            before = before->next;

        newel->next = before->next;
        before->next = newel;
    }
}
void ListOfNum::insertList(ListOfNum& list_2, int index)
{
    if (index > get_size()) throw invalid_argument("Your index > size of list");
    if (index <= 0) throw invalid_argument("Your index <= 0");
    int pos2 = index;
    CurrentItem = head;
    list_2.CurrentItem = list_2.head;
    for (int i = 1; i <= 14; ++i)
    {
        if (i == index)
        {
            for (int j = 1; j <= 4; ++j)
            {
                insert(list_2.CurrentItem->info, pos2);
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
    list_2.CurrentItem = list_2.head;
    cout << "List #1: ";
    for (int i = 1; i <= 10; ++i)
    {
        cout << list_1.CurrentItem->info << " | ";
        list_1.CurrentItem = list_1.CurrentItem->next;
    }
    cout << "List #2: ";
    for (int i = 1; i <= 4; ++i)
    {
        cout << list_2.CurrentItem->info << " | ";
        list_2.CurrentItem = list_2.CurrentItem->next;
    }
    cout << endl;
    list_1.pop_back();
    list_1.push_back(23);
    list_1.push_front(56);
    list_1.pop_front();
    list_1.remove(5);
    list_1.insert(45, 1);
    list_1.at(3);
    list_1.clear();
    list_1.get_size();
    list_1.get_size();
    list_1.set(5, 23);
    list_1.insertList(list_2, 3);
    list_1.isEmpty();
    cout << endl << "List #1 after Insert List: ";
    list_1.CurrentItem = list_1.head;
    for (int i = 1; i <= 14; ++i)
    {
        cout << list_1.CurrentItem->info << " | ";
        list_1.CurrentItem = list_1.CurrentItem->next;
    }
    return 0;
}