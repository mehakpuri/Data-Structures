#include<iostream>
#define size 5
using namespace std;
class queue{
	int q[size],front,rear;
	public:
		queue()
		{
			front=-1;
			rear=-1;
		}
		void insert(int);
		int deletee();
		void display();
};
void queue::insert(int value)
{
	if((front==0 && rear==size-1)||(rear==front-1))
		cout<<"overflow"<<endl;
	else if(front==-1)
	{
		front=rear=0;
		q[rear]=value;
	}
	else if(rear==size-1)
	{
		rear=0;
		q[rear]=value;
	}
	else
	{

		rear=rear+1;
		q[rear]=value;
	}
}
int queue::deletee()
{
	int temp=q[front];
	if(front==-1)
		cout<<"underflow"<<endl;
	else if(front==rear)
		front=rear=-1;
	else if(front==size-1)
		front=0;
	else
		front++;
	
	return temp;
}
void queue::display()
{
	if(rear>=front)
	{
		for(int i=front;i<=rear;i++)
			cout<<q[i]<<" "; 
	}
	else
	{
		for(int i=front;i<=size-1;i++)
			cout<<q[i]<<" ";
		for(int i=0;i<=rear;i++)
			cout<<q[i]<<" ";
	}
	cout<<endl;
}
int main()
{
	int choice,n,value;
	queue q;
	cout<<"enter 1 to insert, 2 to delete and 3 to display and 4 to stop"<<endl;
	cin>>choice;
	while(choice!=4)
	{
		switch(choice)
		{	
			case 1: cout<<"enter the no of elements to insert"<<endl;
					cin>>n;
					for(int i=0;i<n;i++)
					{
						cin>>value;
						q.insert(value);
					}
					break;
			case 2: value = q.deletee();
					cout<<"deleted value is "<<value<<endl;
					break;
			case 3: q.display();
		
		}
		cout<<"enter choice"<<endl;
		cin>>choice;
	}
	return 0;
}
