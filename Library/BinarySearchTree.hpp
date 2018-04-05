#pragma once

#include <memory>

class BinarySearchTree {
private:
	struct node {
		int value;
		std::shared_ptr<node> left;
		std::shared_ptr<node> right;
	};

	std::shared_ptr<node> createNode(int value)
	{
		std::shared_ptr<node> newNode = std::make_shared<node>();
		newNode->value = value;
		newNode->left = nullptr;
		newNode->right = nullptr;
		return std::move(newNode);
	}

	std::shared_ptr<node> insertNode(std::shared_ptr<node> root, int value) {
		std::shared_ptr<node> tmp;
		if (root == nullptr)
			return createNode(value);
		else 
		{
			tmp = root;
			if (root->value <= value)
				root->right = insertNode(root->right, value);
			else
				root->left = insertNode(root->left, value);
			return tmp;
		}
	}

	std::string inOrder(std::shared_ptr<node> node) const
	{
		if (node == nullptr)
			return "";
		else {
			std::ostringstream oss;
			if (node->left != nullptr)
				oss << inOrder(node->left) << " ";
			oss << node->value;
			if (node->right != nullptr)
				oss << " " << inOrder(node->right);
			//oss << inOrder(node->left) << " " << node->value << " " << inOrder(node->right);
			return oss.str();
		}
	}

	std::shared_ptr<node> root_;

public:
	BinarySearchTree(): root_(nullptr) {}

	void insert(int value)
	{
		root_ = insertNode(root_, value);
	}

	std::string inOrderTraversal() const {
		std::ostringstream content;
		content << inOrder(root_);
		return content.str();
	}
	std::shared_ptr<node> getRoot() { return root_; }
};