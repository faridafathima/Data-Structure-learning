#include<iostream>
#include<stack>
using namespace std;

void display(stack<int> s)
{
   if (s.empty())
   {
	   cout << "no items in the list" << endl;
   }
   else
   {
	   while(!(s.empty()))
	   {
		  // cout << "number of elements in the stack" << s.size() << endl;
		   //cout << "deleted element from stack"<< s.top() << endl;
		   cout << s.top() << endl;
		   s.pop();
	   }
   }
}

int main()
{
	int n;
	int element;
	stack<int> s;
	while (1)
	{
		cout << "enter the stack operations:" << endl;
		cin >> n;
		switch (n)
		{
		    case 1:
				cout << "enter the element to push" << endl;
				cin >> element;
				s.push(element);
				break;
			case 2:
				s.pop();
				break;
			case 3:
				display(s);
				break;
			case 4:exit(0);
				break;
			default: cout << "enter a valid option" << endl;
				break;
		}
	}
}