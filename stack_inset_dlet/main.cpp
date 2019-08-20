#include<iostream>
using namespace std;

#define MAXELEMENTS 20

class stack
{
public:
	int top = -1;
	int stack_array[MAXELEMENTS];
	void push(int element);
	void pop(int tops);
	void show_stack();
};

void stack::push(int element)
{
	if (top >= MAXELEMENTS)
	{
		cout << "stack is full" << endl;
	}
	else
	{
		top++;
		stack_array[top] = element;
		cout << "element inserted is:" << stack_array[top] << "top is" << top << endl;
	}
}

void stack::pop(int tops)
{
	if (top == -1)
	{
		cout << "stack is empty" << endl;
	}
	else
	{
		cout << "element deleted is:"<< stack_array[top] << endl;
		stack_array[top--];
	}
}

void stack::show_stack()
{
	if (top == -1)
	{
		cout << "stack is empty, no elements to display" << endl;
	}
	else
	{
		cout << "elements in stack are" << endl;
		for (int i = 0; i <= top; i++)
		{
			cout << stack_array[i] << endl;
		}
	}
}
int main()
{
	int n;
	int element;
	stack s1;
	while(1)
	{
	    cout << "enter stack operations" <<endl;
	    cin >> n;
		switch (n)
		{
		case 1:
			cout << "enter the element to push in stack" << endl;
			cin >> element;
			s1.push(element);
			break;
		case 3:
			cout << "to display the elements in stack" << endl;
			s1.show_stack();
			break;
		case 4:
			exit(0);
		case 2:
			s1.pop(s1.top);
			break;
		default:
			cout << "enter the valid operation" << endl;
			break;
		}
	}
	cin.get();
}