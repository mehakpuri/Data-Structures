#include<iostream>
using namespace std;
struct node{
	int data;
	struct node *next;
};
struct node *ptr,*head,*front;
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
			ptr=front;
		}
		else
		{
			f=new node;
			cin>>f->data;
			f->next=NULL;
			ptr->next=f;
			ptr=ptr->next;
		}
		i++;
	}
}
void deletee()
{
	ptr=front;
	front=front->next;
	ptr->next=NULL;
	delete ptr;
}
void display()
{
	ptr=front;
	while(ptr!=NULL)
	{
		cout<<ptr->data<<" ";
		ptr=ptr->next;
	}
	cout<<endl;
}
int main()
{
	int choice,n;
	cout<<"enter choice, 1 to insert, 2 to delete, 3 to display and 4 to stop"<<endl;
	cin>>choice;
	front=NULL;
	while(choice!=4)
	{
		switch(choice)
		{
			case 1: cout<<"enter no of elements "<<endl;
			cin>>n;
			insert(n);
			break;
			case 2: deletee();
			break;
			case 3: display();
		}
		cout<<"enter again "<<endl;
		cin>>choice;
	}
	return 0;
}
