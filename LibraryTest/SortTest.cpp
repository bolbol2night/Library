#include "stdafx.h"
#include "CppUnitTest.h"
#include "Utils.hpp"
#include <array>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace LibraryTest
{
	TEST_CLASS(SortTest)
	{
	private:
		std::array<int, 10> container_;

		TEST_METHOD_INITIALIZE(setup) { }

		TEST_METHOD(sorting_empty_array_doesnt_update_the_array)
		{
			std::array<int, 0> empty;
			InsertionSort(empty.begin(), empty.end());
			//QuickSort(empty.begin(), empty.end());
			Assert::IsTrue(empty.size() == 0);
		}

		TEST_METHOD(sorting_array_with_single_element_doesnt_update_the_array)
		{
			std::array<int, 1> single;
			single[0] = 10;
			InsertionSort(single.begin(), single.end());
			//QuickSort(single.begin(), single.end());
			Assert::IsTrue(single.at(0) == 10);
		}

		TEST_METHOD(sorting_array_with_random_element_reorder_the_array)
		{
			std::array<int, 10> expected;
			for (size_t i = 0; i < 10; ++i) {
				container_[i] = 9 - i;
				expected[i] = i;
			}
			InsertionSort(container_.begin(), container_.end());
			//QuickSort(container_.begin(), container_.end());
			Assert::IsTrue(container_[0] == expected[0] && container_[1] == expected[1] && container_[2] == expected[2]
				&& container_[3] == expected[3] && container_[4] == expected[4]	&& container_[5] == expected[5]
				&& container_[6] == expected[6]	&& container_[7] == expected[7] && container_[8] == expected[8]
				&& container_[9] == expected[9]);
		}

		TEST_METHOD_CLEANUP(tearDown) { }
	};
}