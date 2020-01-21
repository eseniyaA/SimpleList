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
	Node* head; //"������" ���������� ������
public:
	List() //����������� ������ ��� ����������
	{
		head = NULL; //������� �������� ���� ���
	}
	//�����, ����������� ����� ���� � ������
	void addNode(int d)
	{
		Node* nd = new Node; //����������� ������� ����� ����
		nd->data = d;        //������ ���� ������
		nd->next = NULL;     //����� ���� � �����, ������� NULL
		if (head == NULL)     //���� ������� ������ ����
			head = nd;
		else                 //���� ���� ��� �� ������
		{
			Node* current = head;
			//���� � ����� �������������� ���������� ����
			while (current->next != NULL)
				current = current->next;
			//�������������� ��������� �� ���������
			current->next = nd;
		}
	}
	//�����, ��������� ��������� ������ �� �����
	void printList()
	{
		Node* current = head;
		while (current != NULL)
		{
			cout << current->data << endl;
			current = current->next;
		}
	}
};
int main()
{
	List myList;
	myList.addNode(5);
	myList.addNode(11);
	myList.addNode(27);
	myList.addNode(35);
	myList.addNode(50);
	myList.printList();
	return 0;
}