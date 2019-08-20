#include<iostream>
#include<queue>
using namespace std;

void display_queue(queue <int>q1)
{
	queue <int>q2 = q1;
    while(!q2.empty())
	{
			cout << "items in queue are:" << q2.front() << endl;
			q2.pop();
	}
}

int main()
{
	queue <int>q1;
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
			q1.push(element);
			break;
		case 2:
			q1.pop();
			break;
		case 3:
			display_queue(q1);
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