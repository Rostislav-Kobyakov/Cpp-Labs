#include <iostream>
#include <cstdlib>
using namespace std;
struct Node
{
	char data;
	Node* next;
};
struct List
{
	Node* head;

	List()
	{
		head = NULL;
	}

		void addNode(char value)
		{
			Node* newNode = new Node;
			newNode->data = value;
			newNode->next = NULL;
			if (head == NULL)
			{
				head = newNode;
				return;
			}
			Node* current = head;
			while (current->next != NULL)
			{
				current = current->next;
			}
			current->next = newNode;
		}
		void deleteNode(char value) // удаление по значению
		{
			if (head == NULL)
			{
				return;
			}
			Node* prev = NULL;
			Node* current = this->head;

			while (current != NULL)
			{
				if (current->data == value)
				{
					if (prev == NULL)
					{
						this->head = current->next;
					}
					else
					{
						prev->next = current->next;
					}
					delete current;
					return;
				}
				prev = current;
				current = current->next;
			}
		}
		void deleteAllNode(char value, bool& flag)
		{
			if (head == NULL)
				{
					return;
				}
			Node* prev = NULL;
			Node* current = head;
			while (current != NULL)
			{
				if (current->data == value)
				{
					if (prev == NULL)
					{
						head = current->next;
					}
					else
					{
						prev->next = current->next;
					}
					Node* temp = current;
					current = current->next;
					delete temp;
					flag = true;
				}
				else
				{
					prev = current;
					current = current->next;
				}
			}
		}
		void printList() {
			Node* current = head;
			while (current != NULL) 
			{
				cout << current->data << " ";
				current = current->next;
			}
			cout << endl;
		}
		void insertionSort()
		{
			if (head == NULL || head->next == NULL) {
				return;
			}
			Node* sorted = NULL, * current = head;
			while (current != NULL) {
				Node* nextNode = current->next;
				if (sorted == NULL || sorted->data > current->data) {
					current->next = sorted;
					sorted = current;
				}
				else {
					Node* temp = sorted;
					while (temp->next != NULL && temp->next->data < current->data) {
						temp = temp->next;
					}
					current->next = temp->next;
					temp->next = current;
				}
				current = nextNode;
			}
			head = sorted;
		}
		void ListFilling(int& size) // заполнение списка
		{
			char k;
			for (int i = 0; i < size; i++)
			{
				cout << "Enter " << i + 1 << " node: " << endl;
				cin >> k;
				addNode(k);
			}
		}

};

void Solution1(List &L, List &L1, List &L2) // говно, переделывай
{
	Node* current1 = L1.head;
	Node* prev1 = NULL;
	while (current1 != NULL || prev1 != NULL) // удаляем все схожие элементы(в том числе дубли) в L2 и L1
	{
		bool flag = false;
		if (prev1 != NULL)
		{
			L2.deleteAllNode(prev1->data, flag);

			if (flag && current1 != NULL)
				L1.deleteAllNode(prev1->data, flag);
			else
				if (current1 != NULL && prev1->data == current1->data)
					L1.deleteNode(current1->data);
		}
		if (current1 == NULL)
			break;
		prev1 = current1;
		current1 = current1->next;
	}
	current1 = L1.head;
	while (current1 != NULL) // заполняем оставшимися из L2
	{
		L.addNode(current1->data);
		current1 = current1->next;
	}
	Node* current2 = L2.head;
	while (current2 != NULL) // заполняем оставшимися из L1
	{
		L.addNode(current2->data);
		current2 = current2->next;
	}

}

void Solution(List& L, List& L1, List& L2)
{
	Node* current1 = L1.head;
	Node* current2 = L2.head;
	Node* next1 = current1->next;
	Node* next2 = current2->next;
	while (current1->next != NULL && current2->next != NULL) // основное заполнение
	{
		while (next1->data == current1->data) // скип дублей
		{
			current1 = current1->next;
			if (current1->next == NULL)
				break;
			next1 = current1->next;
		}
		while (next2->data == current2->data) //скип дублей
		{
			current2 = current2->next;
			if (current2->next == NULL)
				break;
			next2 = current2->next;
		}
		if (current1->data != current2->data)
		{
			if (current1->data < current2->data)
			{
				L.addNode(current1->data);
				if (current1->next == NULL)
					break;
				current1 = current1->next;
				next1 = current1->next;
			}
			else
			{
				L.addNode(current2->data);
				if (current2->next == NULL)
					break;
				current2 = current2->next;
				next2 = current2->next;
			}

		}
		else
		{
			do // скип дублей
			{
				current1 = current1->next;
				if (current1->next == NULL)
					break;
				next1 = current1->next;
			} while (next1->data == current1->data);
			do //скип дублей
			{
				current2 = current2->next;
				if (current2->next == NULL)
					break;
				next2 = current2->next;
			} while (next2->data == current2->data);
		}
	}
	bool flag = 0;
	if (current1->next == NULL && current2->next != NULL) // заполнение если первый умер
	{
		while (current2->next != NULL)
		{
			if (current2->data != current1->data)
			{
				if(current2->data != next2->data)
				L.addNode(current2->data);
			} 
			else 
				flag = 1;
			current2 = current2->next;
			if(current2->next != NULL)
			next2 = current2->next;
		}
		if (current2->data != current1->data && !flag)
		{
			L.addNode(current2->data);
			L.addNode(current1->data);
		}
		else if(current2->data != current1->data)
			L.addNode(current2->data);
		flag = 1;
	}
	if (current2->next == NULL && current1->next != NULL && !flag) // заполнение если второй умер
	{
		while (current1->next != NULL)
		{
			if (current2->data != current1->data)
			{
				if (current1->data != next1->data)
					L.addNode(current1->data);
			}
			else
				flag = 1;
			current1 = current1->next;
			if(current1->next != NULL)
			next1 = current1->next;
		}
		if (current2->data != current1->data && !flag)
		{
			L.addNode(current2->data);
			L.addNode(current1->data);
		} else if (current2->data != current1->data)
			L.addNode(current1->data);
	}
}

int main()
	{
	List L, L1, L2;
	int size1, size2;
	cout << "Enter number of nodes for L1" << endl;
	cin >> size1;
	L1.ListFilling(size1);
	cout << "L1: " << endl;
	L1.printList();
	L1.insertionSort();
	cout << "Sorted L1: " << endl;
	L1.printList();
	cout << "Enter number of nodes for L2" << endl;
	cin >> size2;
	L2.ListFilling(size2);
	cout << "L2: " << endl;
	L2.insertionSort();
	cout << "Sorted L2: " << endl;
	L2.printList();
	Solution(L,L1,L2);
	cout << "L: " << endl;
	L.printList();
} // победная строчка🥳🥳🥳
