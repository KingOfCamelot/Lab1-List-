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
	};
}