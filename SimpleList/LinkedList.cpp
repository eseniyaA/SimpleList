//#include <iostream>
//using namespace std;
//class Node        //���� ����, �������������� � ���� ���������
//{
//	friend class List;//��������� ����� ������ �������������, ����� �� ���� ������ � �������� �����
//private:
//	int key;       //����� ���� � ������
//	int data;      //������, ������������ � ����
//	Node* next;    //��������� �� ��������� ���������
//	Node* last;    //��������� �� ���������� ���������
//public:
//	Node(int data, Node* next, Node* last)
//	{
//		this->data = data;
//		this->next = next;
//		this->last = last;
//	}
//	Node(int data)
//	{
//		this->data = data;
//	}
//};
//class List        //�����, ����������� ������ "������"
//{
//private:
//	Node* head;   //������ ������ (��������� �� ������ ���� � ������)
//	Node* temp;   //��������� �� ��������� ���� � ������
//public:
//	List() : head(NULL), temp(NULL) //� ������ ��������� ������� ��������� ����� ����, �.�. ���������� ������� ��� ��� � ��������� �� �� ���
//	{
//	}
//	void addNodeEnd(int data)     //�����, ����������� ���� � ����� ������
//	{
//		Node* nd = new Node(data, NULL, temp); //������� ����� ����, ��������� � ���� ������ � ������ ��� ���������, ���������� NULL
//		temp = nd;
//		if (head)
//		{
//			Node* current = head;  //��������� �� ������ ������, �� ������ ����; � ������������ � ����� ��� ���������� ����������� ����
//			while (current->next)   //������������ � ����� ��� ������, ���� �� ������ �� ���������� ����, ������������� �� ����������
//				current = current->next; //��������� �� ��������� ����
//			current->next = nd;    //���������� ��������� �� ��������� ����
//		}
//		else                       //���� ������ ��� ���� � ��������� ������ ����, �� ������ ��������� �� ����
//			head = nd;             //� ������ ������ ��� ���������: ��� ���� NULL, ���� ��������� �� ������ ���� � ������
//		numNode(); //�������� ���� ������
//	}
//	void addNodeBeginning(int data)   //�����, ����������� ���� � ������ ������
//	{
//		Node* nd = new Node(data);
//		if (head) //���� ��� ���� ���� � ������
//		{
//			Node* tmp = head;
//			head = nd;
//			nd->next = tmp;
//		}
//		else    //���� ������ ����
//		{
//			head = nd;
//			nd->next = NULL;
//		}
//		numNode();
//	}
//	void deleteNodeEnd() //�������� ���� � ����� ������
//	{
//		if (temp)
//		{
//			Node* current = temp;
//			current = current->last;
//			delete current->next;
//			current->next = NULL;
//		}
//		else
//			cout << "The list is empty!" << endl;
//	}
//	void deleteNodeBeginning() //�������� ���� � ������ ������
//	{
//		if (head)
//		{
//			Node* tmp = head;
//			tmp = tmp->next;
//			delete head;     //����������� ������ �� ����� ������
//			head = tmp;      //� ������ ����� ��������
//		}
//		else
//			cout << "The list is empty!" << endl;
//		numNode();
//	}
//	int find(int k) //����� �� ����� � ������
//	{
//		Node* counter = head;
//		while (counter)
//		{
//			if (counter->key == k)
//				return counter->data;
//			counter = counter->next;
//		}
//	}
//	void printListForward() const //������� �� ������ ��� ������ � ������ �������
//	{
//		Node* current = head;
//		while (current)             //���� �� ������ �� ���������� ����
//		{
//			cout << current->key << " - " << current->data << endl;   //������� ������ �� �����
//			current = current->next;         //��������� � ���������� ����
//		}
//	}
//	void printListBack() const     //������� �� ������ ��� ������ � �������� �������
//	{
//		Node* current = temp;
//		while (current)
//		{
//			cout << current->key << " - " << current->data << endl;
//			current = current->last;
//		}
//	}
//	void numNode() //���������� �������-�������, �������� ���� ������
//	{
//		Node* counter = head;
//		int i = 0;
//		while (counter)
//		{
//			counter->key = ++i;
//			counter = counter->next;
//		}
//	}
//};
//int main()
//{
//	List n; //������� ��������� ������ List
//	int key;
//	n.addNodeEnd(21);  //�������� ����� addNode ������ List (���������� ����)
//	n.addNodeEnd(32);
//	n.addNodeEnd(47);
//	n.addNodeEnd(63);
//	n.addNodeEnd(78);
//	n.addNodeEnd(83);
//	n.addNodeEnd(97);
//	n.addNodeEnd(98);
//	n.printListForward();
//	cout << endl;
//	n.printListBack();
//	n.addNodeBeginning(17);
//	n.addNodeBeginning(15);
//	n.addNodeBeginning(10);
//	n.addNodeBeginning(3);
//	cout << endl;
//	n.printListForward();
//	n.deleteNodeEnd();
//	cout << endl;
//	n.printListForward();
//	n.deleteNodeBeginning();
//	cout << endl;
//	n.printListForward();
//	cout << "Enter a number of node: ";
//	cin >> key;
//	cout << "Data node " << key << " = " << n.find(key) << endl;
//}