#include "pch.h"
#include <iostream>
#include "CppUnitTest.h"
#include "../LABA1/MethodDeclaration.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace TestsForList
{
	TEST_CLASS(TestsForList)
	{
	public:
		TEST_METHOD(Push_back)
		{
			ListOfNum list_1 = ListOfNum(10);
			list_1.push_back(23);
			list_1.CurrentItem = list_1.head;
			for (int i = 1; i <= 11; ++i)
			{
				if (i == 11) Assert::AreEqual(23, list_1.CurrentItem->info);
				list_1.CurrentItem = list_1.CurrentItem->next;
			}
		}
		TEST_METHOD(Push_back_2)// if list is empty
		{
			ListOfNum list_1 = ListOfNum(0);
			list_1.pop_back();
			list_1.push_back(23);
			list_1.CurrentItem = list_1.head;
			for (int i = 1; i <= 1; ++i)
			{
				if (i == 1) Assert::AreEqual(23, list_1.CurrentItem->info);
				list_1.CurrentItem = list_1.CurrentItem->next;
			}
		}
		TEST_METHOD(Push_front)
		{
			ListOfNum list_1 = ListOfNum(10);
			list_1.push_front(40);
			list_1.CurrentItem = list_1.head;
			Assert::AreEqual(40, list_1.CurrentItem->info);
		}
		TEST_METHOD(Push_front_2)// if list is empty
		{
			ListOfNum list_1 = ListOfNum(0);
			list_1.pop_back();
			list_1.push_front(40);
			list_1.CurrentItem = list_1.head;
			Assert::AreEqual(40, list_1.CurrentItem->info);
		}
		TEST_METHOD(Pop_back)
		{
			ListOfNum list_1 = ListOfNum(10);
			list_1.pop_back();
			list_1.CurrentItem = list_1.head;
			for (int i = 1; i <= 9; ++i)
			{
				if (i == 9) Assert::AreEqual(9, list_1.CurrentItem->info);
				list_1.CurrentItem = list_1.CurrentItem->next;
			}
		}
		TEST_METHOD(Pop_back_2)// for one element
		{
			ListOfNum list_1 = ListOfNum(1);
			list_1.CurrentItem = list_1.head;
			list_1.pop_back();
			Assert::AreEqual(true, list_1.isEmpty());
		}
		TEST_METHOD(Pop_back_3)// if list epmty
		{
			ListOfNum list_1 = ListOfNum(0);
			list_1.pop_back();
			try
			{
				list_1.pop_back();
			}
			catch(invalid_argument& e)
			{
				cerr << e.what() << endl;
				cout << "List empty";
			}
		}			
		TEST_METHOD(Pop_front)
		{
			ListOfNum list_1 = ListOfNum(10);
			list_1.pop_front();
			list_1.CurrentItem = list_1.head;
			Assert::AreEqual(2, list_1.CurrentItem->info);
		}
		TEST_METHOD(Pop_front_2)// for one element
		{
			ListOfNum list_1 = ListOfNum(1);
			list_1.pop_back();
			Assert::AreEqual(true, list_1.isEmpty());
		}
		TEST_METHOD(Pop_front_3)// if list epmty
		{
			ListOfNum list_1 = ListOfNum(0);
			list_1.pop_back();
			try
			{
				list_1.pop_front();
			}
			catch (invalid_argument& e)
			{
				cerr << e.what() << endl;
				cout << "List empty";
			}
		}
		TEST_METHOD(remove)
		{
			ListOfNum list_1 = ListOfNum(10);
			list_1.remove(3);
			list_1.CurrentItem = list_1.head;
			for (int i = 0; i < 9; ++i)
			{
				if (i == 3)  Assert::AreEqual(5, list_1.CurrentItem->info);
				list_1.CurrentItem = list_1.CurrentItem->next;
			}
		}
		TEST_METHOD(remove_2)//index > size list
		{
			ListOfNum list_1 = ListOfNum(10);
			list_1.CurrentItem = list_1.head;
			try
			{
				list_1.remove(14);
			}
			catch (invalid_argument& e)
			{
				cerr << e.what() << endl;
				cout << "Index > size of list";
			}
		}
		TEST_METHOD(remove_3) //index = 0
		{
			ListOfNum list_1 = ListOfNum(10);
			list_1.CurrentItem = list_1.head;
			try
			{
				list_1.remove(0);
			}
			catch (invalid_argument& e)
			{
				cerr << e.what() << endl;
				cout << "Index = 0, start index of list is 1";
			}
		}
		TEST_METHOD(at)
		{
			ListOfNum list_1 = ListOfNum(10);
			list_1.at(3);
			Assert::AreEqual(4, list_1.CurrentItem->info);
		}
		TEST_METHOD(at_2) //index = 0
		{
			ListOfNum list_1 = ListOfNum(10);
			list_1.CurrentItem = list_1.head;
			try
			{
				list_1.at(0);
			}
			catch (invalid_argument& e)
			{
				cerr << e.what() << endl;
				cout << "Index = 0, start index of list is 1";
			}
		}
		TEST_METHOD(at_3)//index > size list
		{
			ListOfNum list_1 = ListOfNum(10);
			list_1.CurrentItem = list_1.head;
			try
			{
				list_1.at(14);
			}
			catch (invalid_argument& e)
			{
				cerr << e.what() << endl;
				cout << "Index > size of list";
			}
		}
		TEST_METHOD(get_size)
		{
			ListOfNum list_1 = ListOfNum(10);
			list_1.CurrentItem = list_1.head;
			list_1.get_size();
			Assert::AreEqual(10, list_1.CurrentItem->info);
		}
		TEST_METHOD(get_size_2) //empty list
		{
			ListOfNum list_1 = ListOfNum(0);
			list_1.CurrentItem = list_1.head;
			list_1.pop_back();
			list_1.get_size();
			Assert::AreEqual(0, list_1.CurrentItem->info);
		}
		TEST_METHOD(set)
		{
			ListOfNum list_1 = ListOfNum(10);
			list_1.set(5, 23);
			list_1.CurrentItem = list_1.head;
			for (int i = 1; i <= 10; ++i)
			{
				if (i == 5) Assert::AreEqual(23, list_1.CurrentItem->info);
				list_1.CurrentItem = list_1.CurrentItem->next;
			}
		}
		TEST_METHOD(set_2) //index = 0
		{
			ListOfNum list_1 = ListOfNum(10);
			list_1.CurrentItem = list_1.head;
			try
			{
				list_1.set(0, 12);
			}
			catch (invalid_argument& e)
			{
				cerr << e.what() << endl;
				cout << "Index = 0, start index of list is 1";
			}
		}
		TEST_METHOD(set_3)//index > size list
		{
			ListOfNum list_1 = ListOfNum(10);
			list_1.CurrentItem = list_1.head;
			try
			{
				list_1.set(14, 34);
			}
			catch (invalid_argument& e)
			{
				cerr << e.what() << endl;
				cout << "Index > size of list";
			}
		}
		TEST_METHOD(isEmpty)
		{
			ListOfNum list_1 = ListOfNum(0);
			list_1.pop_back();
			Assert::AreEqual(true, list_1.isEmpty());
		}
		TEST_METHOD(isEmpty_2)// if list not empty
		{
			ListOfNum list_1 = ListOfNum(2);
			Assert::AreEqual(false, list_1.isEmpty());
		}
		TEST_METHOD(insert)
		{
			ListOfNum list_1 = ListOfNum(10);
			list_1.insert(25, 4);
			list_1.CurrentItem = list_1.head;
			for (int i = 1; i <= 11; ++i)
			{
				if (i == 5) Assert::AreEqual(25, list_1.CurrentItem->info);
				list_1.CurrentItem = list_1.CurrentItem->next;
			}
		}
		TEST_METHOD(insert_2) //index = 0
		{
			ListOfNum list_1 = ListOfNum(10);
			list_1.CurrentItem = list_1.head;
			try
			{
				list_1.insert(0, 26);
			}
			catch (invalid_argument& e)
			{
				cerr << e.what() << endl;
				cout << "Index = 0, start index of list is 1";
			}
		}
		TEST_METHOD(insert_3)//index > size list
		{
			ListOfNum list_1 = ListOfNum(10);
			list_1.CurrentItem = list_1.head;
			try
			{
				list_1.insert(23, 56);
			}
			catch (invalid_argument& e)
			{
				cerr << e.what() << endl;
				cout << "Index > size of list";
			}
		}
		TEST_METHOD(insert_4)// insert in beginning of the list
		{
			ListOfNum list_1 = ListOfNum(10);
			list_1.insert(25, 1);
			list_1.CurrentItem = list_1.head;
			for (int i = 1; i <= 11; ++i)
			{
				if (i == 1) Assert::AreEqual(25, list_1.CurrentItem->info);
				list_1.CurrentItem = list_1.CurrentItem->next;
			}
		}
		TEST_METHOD(insertlist)
		{
			ListOfNum list_1 = ListOfNum(10);
			ListOfNum list_2 = ListOfNum(4);
			list_1.insertList(list_2, 3);
			list_1.get_size();
			Assert::AreEqual(14, list_1.CurrentItem->info);
		}
		TEST_METHOD(insertList_2) //index = 0
		{
			ListOfNum list_1 = ListOfNum(10);
			ListOfNum list_2 = ListOfNum(4);
			list_1.CurrentItem = list_1.head;
			try
			{
				list_1.insertList(list_2, 0);
			}
			catch (invalid_argument& e)
			{
				cerr << e.what() << endl;
				cout << "Index = 0, start index of list is 1";
			}
		}
		TEST_METHOD(insertList_3)//index > size list
		{
			ListOfNum list_1 = ListOfNum(10);
			ListOfNum list_2 = ListOfNum(4);
			list_1.CurrentItem = list_1.head;
			try
			{
				list_1.insertList(list_2, 34);
			}
			catch (invalid_argument& e)
			{
				cerr << e.what() << endl;
				cout << "Index > size of list";
			}
		}
		TEST_METHOD(clear)
		{
			ListOfNum list_1 = ListOfNum(10);
			list_1.clear();
			Assert::AreEqual(true, list_1.isEmpty());
		}
		TEST_METHOD(clear_2) // list with 1 element
		{
			ListOfNum list_1 = ListOfNum(1);
			list_1.clear();
			Assert::AreEqual(true, list_1.isEmpty());
		}
	};
}