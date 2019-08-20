#include<iostream>
using namespace std;

struct node
{
   int data;
   struct node* link;
};

typedef struct node NODE;

class linked_list
{
	NODE* head;
public:
	linked_list()
	{
		head = NULL;
	}
	void insert_front(int element);
	void delete_rear();
	void display();
	void delete_middle_ele();
	void finding_loop();
};

void linked_list::finding_loop()
{

}
void linked_list::delete_middle_ele()
{
	NODE *slow,*fast,*prev;
	slow = head;
	fast = head;
	prev = head;
	int flag = 0;
	if (head != NULL)
	{
		while ((fast != NULL) && (fast->link != NULL))
		{
			fast = fast->link->link;
			if (head == slow)
			{
				prev = slow;
			}
			else
			{
				prev = prev->link;
			}
			slow = slow->link;

			//to detect loop
			if (slow == fast)
			{
				flag = 1;
			}
		}
		cout << "middle element is" << slow->data << endl;
		if (fast->link == NULL)
		{
			cout << "middle element is deleted" << slow->data << endl;
			head = NULL;
			fast = NULL;
			slow = NULL;
		}
		else if (fast != NULL && fast->link != NULL)
		{
			prev->link = fast;
			cout << "middle element is deleted" << slow->data << endl;
		}
		else
		{
			prev->link = NULL;
			cout << "middle element is deleted" << slow->data << endl;
		}
	}
	else
	{
		cout << "no elements to delete" << endl;
	}
	if (flag == 1)
	{
		cout << "loop is detected" << endl;
	}
	else
	{
		cout << "loop is not detected" << endl;
	}
}

void linked_list::insert_front(int element)
{
	NODE* first = new NODE;
	first->data = element;
	NODE* tmp = NULL;
	tmp = head;
	if (tmp == NULL)
	{
		first->link = NULL;
		head = first;
	}
	else
	{
		first->link = tmp;
		head = first;
	}
}

void linked_list::delete_rear()
{
	NODE* tmp;
	NODE* next;
	tmp = head;
	next = tmp->link;
	if (tmp->link == NULL)
	{
		delete(tmp);
		head = NULL;
	}
	else
	{
		while (next->link != NULL)
		{
			tmp = tmp->link;
			next = next->link;
		}
		delete(next);
		tmp->link = NULL;
	}
}

void linked_list::display()
{
	NODE* tmp;
	tmp = head;
	if (head == NULL)
	{
		cout << "all elements are deleted" << endl;
	}
	else
	{
		while (tmp != NULL)
		{
			cout << tmp->data << endl;
			tmp = tmp->link;
		}
	}
}

int main()
{
	linked_list l1;
	int op;
	int element;
	while (1)
	{
		cout << "enter the operation to be performed on the list"<< endl;
		cin >> op;
		switch (op)
		{
		case 1:
			cout << "enter the element to be inserted" << endl;
			cin >> element;
			l1.insert_front(element);
			break;
		case 2:
			l1.delete_rear();
			break;
		case 3:
			cout << "displaying the elements" << endl;
			l1.display();
			break;

		case 4:
			cout << "delete the middle element" << endl;
			l1.delete_middle_ele();
			break;

		case 5:
			cout << "finding loop:" << endl;
			l1.finding_loop();
			break;
		case 6:
			exit(0);
			break;
		}
	}
	cin.get();
}