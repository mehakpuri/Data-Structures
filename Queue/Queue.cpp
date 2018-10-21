#include<iostream>
#define size 20
using namespace std;
int q[20],front=-1,rear=-1;
void insert(int value)
{
	if(rear==size-1)
	{
		cout<<"overflow"<<endl;
	}
	else if(front==-1)
	{
		front=0;
		rear=0;
		q[rear]=value;
	}
	else
	{
		rear++;
		q[rear]=value;
	}

}
void display()
{
	for(int i=front;i<=rear;i++)
	{
		cout<<q[i]<<" ";
	}
	cout<<endl;
}
void deletee()
{
	if(front==-1)
		cout<<"underflow"<<endl;
	else if(front==rear)
	{
		front=-1;
		rear=-1;
	}
	else
		front++;
}
int main()
{
	int n,value,choice;
	cout<<"enter 1 to insert, 2 to delete, 3 to display and 4 to stop"<<endl;
	cin>>choice;
	while(choice!=4)
	{
		switch(choice)
		{
		case 1: cout<<"enter no of elements "<<endl;
				cin>>n;
				cout<<"enter elements "<<endl;
				for(int i=0;i<n;i++)
				{
					cin>>value;
					insert(value);
				}
				break;
		case 2: deletee();
				break;	
		case 3: display();
				break;
		}
		cout<<"enter choice"<<endl;
		cin>>choice;
	}
	return 0;
}
