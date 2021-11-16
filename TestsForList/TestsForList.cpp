#include "pch.h"
#include "CppUnitTest.h"
#include "../LABA1/FunctionHeaders.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

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
				if (i == 11) Assert::AreEqual(23, list_1.CurrentItem->node);
				list_1.CurrentItem = list_1.CurrentItem->next;
			}
		}
		TEST_METHOD(Push_front)
		{
			ListOfNum list_1 = ListOfNum(10);
			list_1.push_front(40);
			list_1.CurrentItem = list_1.head;
			Assert::AreEqual(40, list_1.CurrentItem->node);
		}
		TEST_METHOD(Pop_back)
		{
			ListOfNum list_1 = ListOfNum(10);
			list_1.pop_back();
			list_1.CurrentItem = list_1.head;
			for (int i = 1; i <= 9; ++i)
			{
				if (i == 9) Assert::AreEqual(9, list_1.CurrentItem->node);
				list_1.CurrentItem = list_1.CurrentItem->next;
			}
		}
		TEST_METHOD(Pop_front)
		{
			ListOfNum list_1 = ListOfNum(10);
			list_1.pop_front();
			list_1.CurrentItem = list_1.head;
			Assert::AreEqual(2, list_1.CurrentItem->node);
		}
		TEST_METHOD(remove)
		{
			ListOfNum list_1 = ListOfNum(10);
			list_1.remove(3);
			list_1.CurrentItem = list_1.head;
			for (int i = 0; i < 9; ++i)
			{
				if (i == 3)  Assert::AreEqual(5, list_1.CurrentItem->node);
				list_1.CurrentItem = list_1.CurrentItem->next;
			}
		}
		TEST_METHOD(at)
		{
			ListOfNum list_1 = ListOfNum(10);
			list_1.at(3);
			Assert::AreEqual(4, list_1.CurrentItem->node);
		}
		TEST_METHOD(get_size)
		{
			ListOfNum list_1 = ListOfNum(10);
			list_1.CurrentItem = list_1.head;
			list_1.get_size();
			Assert::AreEqual(10, list_1.CurrentItem->node);
		}
		TEST_METHOD(set)
		{
			ListOfNum list_1 = ListOfNum(10);
			list_1.set(5, 23);
			list_1.CurrentItem = list_1.head;
			for (int i = 1; i <= 10; ++i)
			{
				if (i == 5) Assert::AreEqual(23, list_1.CurrentItem->node);
				list_1.CurrentItem = list_1.CurrentItem->next;
			}
		}
		TEST_METHOD(isEmpty)
		{
			ListOfNum list_1 = ListOfNum(0);
			list_1.isEmpty();
			bool EmptyList = list_1.CurrentItem;
			Assert::AreEqual(true, EmptyList);
		}
		TEST_METHOD(insert)
		{
			ListOfNum list_1 = ListOfNum(10);
			list_1.insert(25, 4);
			list_1.CurrentItem = list_1.head;
			for (int i = 1; i <= 11; ++i)
			{
				if (i == 5) Assert::AreEqual(25, list_1.CurrentItem->node);
				list_1.CurrentItem = list_1.CurrentItem->next;
			}
		}
		TEST_METHOD(insertlist)
		{
			ListOfNum list_1 = ListOfNum(10);
			ListOfNum list_2 = ListOfNum(4);
			list_1.insertList(list_2, 3);
			list_1.get_size();
			Assert::AreEqual(14, list_1.CurrentItem->node);
		}
		TEST_METHOD(clear)
		{
			ListOfNum list_1 = ListOfNum(10);
			list_1.clear();
			list_1.isEmpty();
			bool EmptyList = list_1.CurrentItem;
			Assert::AreEqual(false, EmptyList);
		}
	};
}