#pragma once

#include <memory>

class LinkedList {
private:
	size_t size_;
	struct node {
		int value;
		std::shared_ptr<struct node> next;
	};
	std::shared_ptr<node> head_;

	std::shared_ptr<node> createNode(int value) const
	{
		std::shared_ptr<node> newNode = std::make_shared<node>();
		newNode->value = value;
		newNode->next = nullptr;
		return std::move(newNode);
	}

	std::shared_ptr<node> reachLastNode() const {
		std::shared_ptr<node> tmp = head_;
		while (tmp->next != nullptr)
			tmp = tmp->next;
		return tmp;
	}

public:
	LinkedList(): size_(0), head_(nullptr) {}

	size_t size() const { return size_; }

	void insert(int value) {
		if (head_ == nullptr) {
			head_ = createNode(value);
		} else {
			std::shared_ptr<node> tmp = reachLastNode();
			tmp->next = createNode(value);
		}

		++size_;
	}
	
	void remove(int value) {
		if (head_ != nullptr) {
			std::shared_ptr<node> toDelete = head_, previous;
			while (toDelete != nullptr && toDelete->value != value) {
				previous = toDelete;
				toDelete = toDelete->next;
			}
			if (toDelete != nullptr && toDelete->value == value) {
				previous->next = toDelete->next;
				toDelete = nullptr;
				--size_;
			}
		}
	}

	size_t find(int value) const {		
		size_t pos = -1, index = 0;
		if (head_ != nullptr) {
			std::shared_ptr<node> tmp = head_;
			while (tmp != nullptr && tmp->value != value) {
				tmp = tmp->next;
				index++;
			}
			if (tmp != nullptr && tmp->value == value)
				pos = index;
		}
		return pos;
	}
};