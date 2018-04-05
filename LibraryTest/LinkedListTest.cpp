#include "stdafx.h"
#include "CppUnitTest.h"
#include "LinkedList.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace LibraryTest
{		
	TEST_CLASS(LinkedListTest)
	{
	private:
		LinkedList list;

		void dummyInsert() {
			for (size_t i = 0; i < 10; ++i)
				list.insert(10 * i + 1);
		}

	public:
		TEST_METHOD_INITIALIZE(setup) { }

		TEST_METHOD(empty_linked_list_size_is_null)
		{
			Assert::IsTrue(list.size() == 0);
		}

		TEST_METHOD(inserting_element_into_linked_list_increments_its_size)
		{
			list.insert(10);
			Assert::IsTrue(list.size() == 1);

			list.insert(20);
			Assert::IsTrue(list.size() == 2);
		}

		TEST_METHOD(inserted_element_is_added_to_the_bottom_of_the_list)
		{
			list.insert(10);
			Assert::IsTrue(list.find(10) == list.size() - 1);

			list.insert(20);
			Assert::IsTrue(list.find(20) == list.size() - 1);
		}

		TEST_METHOD(deleting_element_present_in_a_linked_list_decrements_its_size)
		{
			dummyInsert();
			size_t previousSize = list.size();
			list.remove(31);
			Assert::IsTrue(list.size() == previousSize - 1);
		}

		TEST_METHOD(deleting_element_missing_in_a_linked_list_doesnt_change_the_list)
		{
			dummyInsert();
			size_t previousSize = list.size();
			list.remove(30);
			Assert::IsTrue(list.size() == previousSize);
		}

		TEST_METHOD_CLEANUP(tearDown) { }
	};
}