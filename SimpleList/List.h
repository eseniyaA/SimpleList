#pragma once
#include<iostream>

class List
{
private:
	class Node
	{
	private:
		int* item;
		Node* next;
	public:
		Node()
		{
			item = nullptr;
			next = nullptr;
		}
		Node(const int& item)
		{
			this->item = new int(item);
			next = nullptr;
		}
		~Node()
		{
			delete item;
		}
		void setItem(int *item)
		{
			this->item = item;
		}
		void setNext(Node* next)
		{
			this->next = next;
		}
		Node* getNext()
		{
			return next;
		}
		int getItem()
		{
			return *item;
		}
		bool operator==(const Node& right) const
		{
			return this->item == right.item;
		}
		bool operator<(const Node& right) const
		{
			return this->item < right.item;
		}
	};
	Node *head;
	Node *tail;
public:
	List()
	{
		tail = nullptr;
	}
	~List()
	{
		Node* current = head;
		while (head != tail)
		{
			current = current->getNext();
			delete head;
			head = current;
		}
		delete current;
	}
	List& operator+(int *item)
	{
		Node* current;
		tail->setNext(current);
		tail->setItem(item);
		if (tail->getNext == nullptr)
			tail->setNext = new List();
		tail = tail->getNext;
	}

	List& removeMinimal()
	{
		int min = INT_MAX;
		Node* current = head;
		while (current->getNext() != nullptr)
		{
			if (min < current->getItem())
				min = current->getItem();
			current = current->getNext();
		}

		while (current->getNext() != nullptr)
		{
			if (min < current->getItem())
			{
				current->setItem(nullptr);
				current = current->getNext();
			}
			current = current->getNext();
		}
	}
	
	friend std::ostream& operator<<(std::ostream& out, const List& list)
	{
		Node* current;
		while (current->getItem != nullptr)
		{
			out << current->getItem;
		}
		return out;
	}

	
	
};