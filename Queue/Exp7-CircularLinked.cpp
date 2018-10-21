#include<iostream>
using namespace std;
struct node{
	int data;
	struct node *next;
};
struct node *ptr,*front,*rear;
void insert(int n)
{
	struct node *f;
	int i=0;
	while(i<n)
	{
		if(front==NULL)
		{
			f=new node;
			cin>>f->data;
			f->next=NULL;
			front=f;
			rear=front;
		}
		else
		{
			f=new node;
			cin>>f->data;
			rear->next=f;
			f->next=front;
			rear=rear->next;
		}
		i++;
	}
	
}
void deletee()
{
	if(front==NULL)
		cout<<"underflow"<<endl;
	else
	{
		ptr=front;
		front=front->next;
		rear->next=front;
		delete ptr;
	}
}
void display()
{
	ptr=front;
	do{
		cout<<ptr->data<<" ";
		ptr=ptr->next;
	}while(ptr!=front);
}
int main()
{
	int choice,n;
	cout<<"enter 1 to insert, 2 to delete, 3 to display and 4 to stop"<<endl;
	cin>>choice;
	front=NULL;
	while(choice!=4)
	{
		switch(choice)
		{
			case 1: cout<<"enter the no of elements"<<endl;
					cin>>n;
					insert(n);
					break;
			case 2: deletee();
					break;
			case 3: display();
		}
		cout<<"enter again"<<endl;
		cin>>choice;
	}
	return 0;
}
