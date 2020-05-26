#include "stdafx.h"
#include <iostream>
#include <Windows.h>
using namespace std;

class Stac {
private:
	class Node {//��������� ����� ������� ������������ ��� ��������� �����
	public:
		string date;
		Node* Next;
		Node (string a = NULL, Node *b = nullptr) {//����������� ������ node
			this->date = a;
			this->Next = b;
		}
	};
	Node *Head;
	int size;
public:
	Stac() {//����������� ������ stac
		Head = nullptr;
		size = 0;
	}

	Stac(const Stac &a) {//����������� �����������
		Head = NULL;
		Node* cur = a.Head;
		int b = a.size;
		while (b != 0) {
			for (int i = 1; i < b; i++) {
				cur = cur->Next;
			}
			push(cur->date);
			b--;
			cur = a.Head;
		}
	}

	~Stac() {//���������� ������ stac
		Node* tmp;
		while (!emp()) {
			tmp = Head;
			Head = Head->Next;
			delete(tmp);
			size--;
		}
	}
	bool emp() {//�������� �� �������
		return Head == nullptr;
	}
	void push(string a) {//���������� ���������� � ����
		if (emp()) {
			Head = new Node(a);
			size++;
		}
		else {
			Node *current = Head;
			Head = new Node(a);
			Head->Next = current;
			size++;
		}
	}
	void print() {//����� ����������� ����� � �������
		if (!emp()) {
			Node* current = Head;
			while (!emp()) {
				cout << Head->date << " ";
				Head = Head->Next;
			}
			Head = current;
			cout << endl << size << endl;
		}
		else { cout << "����� �����" << endl; }
	}
	void pop() {//�������� ������� ���������� ����� 
		Node *current = Head;
		Head = Head->Next;
		delete current;
		size--;
	}
	void hideval(string val) {//����� ���������� �� ��������
		Node* cur = Head;
		for (int i = 1; i <= size; i++) {
			if (Head->date == val) {
				cout << i << ":" << Head->date << endl;
				Head = Head->Next;
			}
			else {
				Head = Head->Next;
			}
		}
		Head = cur;
	}
	void hiadnum(int num) {//����� ���������� �� ������� � �����
		int a = 1;
		if (int i = num - 1 < size) {
			Node* cur = Head;
			while (a < num) {
				Head = Head->Next;
				a++;
			}
			cout << num << ":" << Head->date << endl;
			Head = cur;
		}
		else {
			cout << "����� ���" <<endl;
		}
	}
};

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Stac Bib;
	string name;
	int n = 1;
	while (n != 0) {
		cout << "�������� ��������:" << endl
			<< "0 - �����" << endl
			<< "1 - �������� ����� �� �����" << endl
			<< "2 - ����� ������ ����� � �����" << endl
			<< "3 - ����� ������������ �����" << endl
			<< "4 - ����� ����� �� ������" << endl
			<< "5 - ����������� ��� ����� �� �����" << endl
			<< "6 - ������ ��� ����� � �����" << endl
			<< "7 - ���� ������������ �����������" << endl;
		cin >> n;
		int a;
		switch (n)
		{
		case (1):
			cout << "�������� �����:";
			cin >> name;
			Bib.push(name);
			break;
		case (2):
			Bib.pop();
			cout << "����� ������" << endl;
			break;
		case(3):
			cout << "�������� �����:";
			cin >> name;
			Bib.hideval(name);
			break;
		case(4):
			cout << "�����:";
			cin >> a;
			Bib.hiadnum(a);
			break;
		case(5):
			Bib.print();
			break;
		case(6):
			Bib.~Stac();
			cout << "����� �������" << endl;
			break;
		case(7): {
			Stac a(Bib);
			cout << "�������� ����:" << endl;
			Bib.print();
			cout << "����� ����:" << endl;
			a.print(); }
			break;
		default:
			cout << "������� �� ����������" << endl;
			break;
		}
	}
	system("pause");
    return 0;
}

