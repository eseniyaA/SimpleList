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
	void operator+=(int d)
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
	/*void printList()
	{
		Node* current = head;
		while (current != NULL)
		{
			cout << current->data << endl;
			current = current->next;
		}
	}*/

	std::ostream& operator<<(std::ostream& out)
	{
		Node* current = head;
		while (current != nullptr)
		{
			out << current->data << endl;
			current = current->next;
		}
		return out;
	}
};
int main()
{
	List myList;
	myList.operator+=(5);
	myList += 11;
	myList += 27;
	myList += 35;
	myList += 50;
	std:cout << myList;
	return 0;
}