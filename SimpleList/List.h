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
		Node(Node const&) = delete;
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
		if (head == nullptr || tail == nullptr)
			return;
		Node* current = head;
		while (head != tail)
		{
			current = current->getNext();
			delete head;
			head = current;
		}
		delete current;
	}
	List(List const&) = delete;
	List& operator=(List const&) = delete;

	List(List&& list) noexcept
	{
		this->head = list.head;
		this->tail = list.tail;
		list.head = nullptr;
		list.tail = nullptr;

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

		if (head = tail)
			return;
		Node* prev = head;
		current = head->getNext();
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

	class Iterator
	{
	private:
		Node* current;
	public:
		Iterator(Node* current)
		{
			this->current = current;
		}
		Iterator(const Iterator& itr)
		{
			current = itr.current;
		}
		Iterator operator++(int)
		{
			Iterator tmp = Iterator(*this);
			if (current->getNext() != nullptr)
				current = current->getNext();
			return tmp;
		}
		Iterator& operator++()
		{
			if (current->getNext() != nullptr)
				current = current->getNext();
			return *this;
		}
		void setItem(const int& item)
		{
			current->setItem(item);
		}
		int getItem() const
		{
			return current->getItem();
		}
		bool operator==(const Iterator& itr)
		{
			return current == itr.current;
		}
		bool operator!=(const Iterator& itr)
		{
			return current != itr.current;
		}
	};

	void reduce()
	{
		Node* current = head;
		
		while (current != tail && current->getNext() != tail)
		{
			if (current->getNext() == tail)
				return;
			Node* next = current->getNext();
			current->setItem(current->getItem() + next->getItem());
			current->setNext(next->getNext());
			current = current->getNext();
			delete next;
		}	
	}
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