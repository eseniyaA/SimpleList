#pragma once
#include<iostream>

class List
{
private:
	class Node
	{
	private:
		int item;
		Node* next;
	public:
		Node()
		{
			item = 0;
			next = nullptr;
		}
		Node(const int& item)
		{
			this->item = item;
			next = nullptr;
		}
		void setItem(const int& item)
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
		int getItem() const
		{
			return item;
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
		tail = new Node;
		head = tail;
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
	List& operator+=(const int& item)
	{
		tail->setItem(item);
		Node* newTail = new Node();
		tail->setNext(newTail);
		tail = newTail;
		return *this;
	}

	void removeMinimal()
	{
		int min = INT_MAX;
		Node* current = head;
		while (current != tail)
		{
			if (min > current->getItem())
				min = current->getItem();
			current = current->getNext();
		}

		Node* prev = current;
		while (head != tail && head->getItem == min)
		{
			Node* oldHead = head;
			head = head->getNext();
			while (current != tail)
			{
				if (head->getItem == min)
				{
					head = current;
					delete head;
				}
				if (min == current->getItem())
				{

				}
				current = current->getNext();
			}
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