#include "stdafx.h"
#include "CppUnitTest.h"
#include "BinarySearchTree.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace LibraryTest
{
	TEST_CLASS(BinarySearchTreeTest)
	{
	private:
		BinarySearchTree bst;

		TEST_METHOD_INITIALIZE(setup)
		{
			for (int i = 0; i < 10; ++i)
				bst.insert(i);
		}

		TEST_METHOD(empty_bst_has_a_null_root_node)
		{
			BinarySearchTree empty;
			Assert::IsTrue(empty.getRoot() == nullptr);
		}

		TEST_METHOD(adding_an_element_to_bst_updates_only_the_root_node)
		{
			BinarySearchTree single;
			single.insert(1);
			Assert::IsTrue(single.getRoot()->value == 1);
			Assert::IsTrue(single.getRoot()->left == nullptr);
			Assert::IsTrue(single.getRoot()->right == nullptr);
		}

		TEST_METHOD(adding_two_elements_to_bst_adds_the_minimum_value_to_the_left_node_and_the_other_element_to_the_root_node)
		{
			BinarySearchTree twin;
			twin.insert(10);
			twin.insert(15);
			Assert::IsTrue(twin.getRoot()->value == 10
				&& twin.getRoot()->right->value == 15 && twin.getRoot()->right->left == nullptr && twin.getRoot()->right->right == nullptr
				&& twin.getRoot()->left == nullptr);
		}

		TEST_METHOD(adding_three_elements_to_bst_adds_the_minimum_value_on_the_left_node_the_maximum_element_on_the_right_node_and_the_last_element_at_the_root_node)
		{
			BinarySearchTree three;
			three.insert(10);
			three.insert(15);
			three.insert(5);
			Assert::IsTrue(three.getRoot()->value == 10
				&& three.getRoot()->left->value == 5 && three.getRoot()->left->left == nullptr && three.getRoot()->left->right == nullptr
				&& three.getRoot()->right->value == 15 && three.getRoot()->right->left == nullptr && three.getRoot()->right->right == nullptr);
		}

		TEST_METHOD(in_order_traversal_of_a_bst_returns_sorted_array_of_elements)
		{
			std::ostringstream actual, expected;
			for (int i = 0; i < 10; ++i) {
				expected << i;
				if (i < 9)
					expected << " ";
			}

			actual << bst.inOrderTraversal();
			Assert::AreEqual(expected.str(), actual.str());
		}

		TEST_METHOD_CLEANUP(tearDown) {}
	};
}