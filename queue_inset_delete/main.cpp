#include<iostream>
using namespace std;
#define MAX_ELE 100

class queue
{
	int rear = -1, front = -1;
	int queue_array[MAX_ELE];
public:
//	int rear = -1, front = -1;
//	int queue_array[MAX_ELE];
	void insert_queue(int element);
	void delete_queue();
	void display_queue();
};

void queue::insert_queue(int element)
{
	if (rear == MAX_ELE - 1)
	{
		cout << "queue is full" << endl;
	}
	else
	{
		if (front == -1)
			front = 0;
		rear++;
		queue_array[rear] = element;
	}
}

void queue::delete_queue()
{
	if ((front == -1) || (front > rear))
	{
		cout << "queue is empty" << endl;
	}
	else
	{
		cout << "deleted item is:"<<queue_array[front] << endl;
		front++;
	}
}

void queue::display_queue()
{
	if ((front == -1) || (front > rear))
	{
		cout << "queue is empty" << endl;
	}
	else
	{
		int fro = front;
		for (int i = front;i<=rear; i++)
		{
			cout << "items in queue are:"<<queue_array[fro] << endl;
			fro++;
		}
	}
}
int main()
{
	queue q1;
	int n;
	int element;
	while (1)
	{
		cout << "enter 1:insert 2:delete 3:display 4:exit" << endl;
		cin >> n;
		switch (n)
		{
		   case 1:
			   cout << "enter the element to insert" << endl;
			   cin >> element;
			   q1.insert_queue(element);
			   break;
		   case 2:
			   q1.delete_queue();
			   break;
		   case 3:
			   q1.display_queue();
			   break;
		   case 4:
			   exit(0);
			   break;
		   case 5:
			   cout << "enter valid option" << endl;
			   break;
		}
	}
	cin.get();
}