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

		while (head != tail && head->getItem() == min)
		{
			Node* oldHead = head;
			head = head->getNext();
			delete oldHead;
		}

		Node* prev = head;
		current = head->getNext();
		if (head = tail)
			return;
		while (current != tail)
		{
			if (min == current->getItem())
			{
				Node* oldCurrent = current;
				current = current->getNext();
				delete oldCurrent;
				prev->setNext(current);
			}
			else
			{
				prev = current;
				current = current->getNext();
			}
		}
		
	}
	
	friend std::ostream& operator<<(std::ostream& out, List& list);

	
	
};

std::ostream& operator<<(std::ostream& out, List& list)
{
	List::Node* current = list.head;
	while (current != list.tail)
	{
		out << current->getItem() << ' ';
		current = current->getNext();
	}
	return out;
}