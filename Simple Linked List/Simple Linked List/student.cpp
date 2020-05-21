#include <iostream>
#include <string>
using namespace std;
struct NODE
{
	string name;
	int ID;
	NODE* next;
};
NODE *insertNODE(NODE *head)
{
	NODE *cur, *tmp;
	tmp = new NODE;
	tmp->next = NULL;
	if (head->next == NULL)
	{
		cout << "Insert ID for student.";
		cin >> head->ID;
		cout << "Insert name for student.";
		cin >> head->name;
		head->next = tmp;
		return head;
	}
	cur = head->next;
	cout << "Insert ID for student.";
	cin >> tmp->ID;
	cout << "Insert name for student.";
	cin >> tmp->name;
	while (cur->next != NULL)
	{
		if (tmp->ID <= cur->next->ID)
		{
			tmp->next = cur->next;
			cur->next = tmp;
			return head;
		}
		cur = cur->next;
	}
	cur->next = tmp;
	return head;
}
void searchList(NODE* head, int searchID)
{
	while (head->ID != searchID && head != NULL)
		searchList(head->next, searchID);
	if (head->ID == searchID)
		cout << "ID=" << searchID << " Student name= " << head->name << endl;
	else
		cout << "Error! No student with ID= " << searchID << " exist..";
}
NODE* deleteID(NODE *head, int searchID)
{
	NODE *cur = head, *tmp;
	if (head->ID == searchID)
	{
		cout << "Found ID=" << searchID << " of Student name=" << cur->name << "\nDeleting...";
		tmp = head;
		head = head->next;
		delete tmp;
		cout << "ID removed successfully!";
		return head;
	}
	cur = head->next;
	tmp = head;
	while (cur != NULL)
	{
		if (cur->ID == searchID)
		{
			cout << "Found ID=" << searchID << " of Student name=" << cur->name << "\nDeleting...";
			cur = cur->next;
			delete tmp->next;
			tmp->next = cur;
			delete tmp;
			cout << "ID removed successfully!";
			return head;
		}
		tmp = cur;
		cur = cur->next;
	}
	cout << "Error! Did not find the following ID=" << searchID;
	return head;
}
int numberOfStudents(NODE* head)
{
	if (head->next == NULL)
		return 1;
	else
		return 1 + numberOfStudents(head->next);
}
void displayList(NODE* head)
{
	if (head == NULL)
		cout << "End of list";
	while (head != NULL)
	{
		cout << "ID= " << head->ID << "\tName= " << head->name << endl;
		displayList(head->next);
	}
}
NODE *deleteList(NODE* head)
{
	if (head->next == NULL)
	{
		delete head;
		return NULL;
	}
	NODE *cur, *tmp;
	cur = head->next;
	tmp = head;
	while (cur != NULL)
	{
		delete tmp;
		tmp = cur;
		cur = cur->next;
	}
	delete tmp;
	return NULL;
}
int main()
{
	NODE* head;
	int choice, searchID;
	head = new NODE;
	head->next = NULL;
	head->ID = 0;
	do
	{
		cout << "Choose your destiny...\n";
		cout << "1- Insert new Student\n";
		cout << "2- Search student by id\n";
		cout << "3- Remove student by id\n";
		cout << "4- Return number of students\n";
		cout << "5- Display the list\n";
		cout << "6- Delete the list\n";
		cout << "0- Exit!\nEnter choice, 0 to exit:\t";
		cin >> choice;
		switch (choice)
		{
		case 1:
			head = insertNODE(head);
			break;
		case 2:
			cout << "Enter the following ID to search name in list: ";
			cin >> searchID;
			searchList(head, searchID);
			break;
		case 3:
			cout << "Enter the following ID to remove from list: ";
			cin >> searchID;
			head = deleteID(head, searchID);
			break;
		case 4:
			cout << "There are " << numberOfStudents(head) << "students in the list.";
			break;
		case 5:
			displayList(head);
			break;
		case 6:
			"Deleting list...";
			head = deleteList(head);
			cout << "The list has been successfully removed!";
			break;
		default:
			break;
		};
	}
	while (choice != 0);
	return 0;
}