#include <iostream>
using namespace std;
struct Node
{
	int data;
	Node* next;
};
class List
{
private:
	Node* head;
public:
	List()
	{
		head = NULL;
	}
	void addNode(int d)
	{
		Node* nd = new Node();
		nd->data = d;
		nd->next = head;
		head = nd;
	}
	void printList()
	{
		Node* current = head;
		while (current)
		{
			cout << current->data << endl;
			current = current->next;
		}
	}
};
int main()
{
	List ls;
	ls.addNode(134);
	ls.addNode(2387);
	ls.addNode(5);
	ls.addNode(74);
	ls.addNode(0);
	ls.printList();
	return 0;
}