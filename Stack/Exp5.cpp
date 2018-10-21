#include<iostream>
using namespace std;
class stack{
	int a[50],top;
	public:
		stack()
		{
			top=-1;
		}
		void push(int value);
		void pop();
		void display();
};
void stack::push(int value)
{
	if(top==49)  //size-1
	{
		cout<<"overflow"<<endl;
	}
	else
	{
		top++;
		a[top]=value;
	}
}
void stack::pop()
{
	if(top==-1)
	{
		cout<<"underflow"<<endl;
	}
	else
	{
		top--;
	}
}
void stack::display()
{
	cout<<"displaying from top to bottom "<<endl;
	for(int i=top;i>=0;i--)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
}
int main()
{
	int n,value,choice;
	stack s;
	cout<<"enter 1 to push, 2 to pop, 3 to display, 4 to stop"<<endl;
	cin>>choice;
	while(choice!=4)
	{
		switch(choice)
		{
			case 1: cout<<"enter no of elements "<<endl;
					cin>>n;
					for(int i=0;i<n;i++)
					{
						cin>>value;
						s.push(value);
					}
					break;
			case 2: s.pop();
					break;
			case 3: s.display();
		}
		cout<<"enter again "<<endl;
		cin>>choice;
	}
	return 0;
}
