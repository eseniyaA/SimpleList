#pragma once

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

		}
		~Node()
		{
			delete item;
		}
		void setItem(int *item)
		{
			this->item = item;
		}
		int getItem()
		{
			return *item;
		}
		bool operator==(const Node& node) const
		{
			return this->item == node.getItem;
		}
	};
	Node *head;
	Node *tail;
	int size;
public:
	List()
	{
		head = nullptr;
		tail = nullptr;
		size = 0;
	}
	List(const Node& newNode)
	{
		head;
		*tail = Node(newNode.getItem);
		size++;
	}
};