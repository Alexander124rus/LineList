
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
using namespace std;

struct ListNode
{
	int data;
	struct ListNode* next;
};
typedef ListNode List;

List* head = NULL;


//Добавление элемента в список
void MakeList(int DataValue)
{
	List* listNode = (List*)malloc(sizeof(List));
	listNode->data = DataValue;
	listNode->next = NULL;

	if (head == NULL) {
		head = listNode;
	}
	else {
		List* current = head;
		while (current->next != NULL)
			current = current->next;
		
		current->next = listNode;
	}
}

//Печать списка
void PrintList()
{
	List* current = head;

	while (current != NULL)
	{
		cout << current->data << endl;
		current = current->next;
	}
}


void FindList(List* Head)
{
	List* ptr;
	List* current = Head;
	while (current != NULL) {
		
		if (current->data % 3 == 0) {
			
			if (current == Head)
			{
				ptr = Head;
				Head = Head->next;
				free(ptr);
				current = Head;
				
			}
			else {
				ptr = Head;

				while (ptr->next != current) {
					ptr = ptr->next;
				}
				ptr->next = current->next;
				free(current);
				current = ptr;
			}
		}
		else {
			current = current->next;
		}
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");



	MakeList(4);
	MakeList(3);
	MakeList(6);
	MakeList(10);

	cout << "Первый список\n";
	PrintList();
	FindList(head);

	cout << "Изминённый список\n";
	PrintList();
}
