#include<iostream>
using namespace std;
struct node{
	int data;
	struct node *next;
};
int main()
{
	struct node *f,*head,*ptr,*ptrn;
	int i=0,n,pos;
	cout<<"enter no of elemments ";
	cin>>n;
	head=NULL;
	while(i<n)
	{
		if(head==NULL)
		{
			f=new node;
			cin>>f->data;
			f->next=NULL;
			head=f;
			ptr=head;
		}
		else
		{
			f= new node;
			cin>>f->data;
			f->next=NULL;
			ptr->next=f;
			ptr=ptr->next;
		}
		i++;
	}
	ptr->next=head;
	ptr=head;
	do
	{
		cout<<ptr->data<<" ";
		ptr=ptr->next;
	}while(ptr!=head);
	
	//insertion at beg
	
	cout<<endl<<"enter a value for insertion at beg "<<endl;
	f=new node;
	cin>>f->data;
	
	ptr=head;
	do
	{
		ptr=ptr->next;
	}while(ptr->next!=head);
	
	f->next=head;
	ptr->next=f;
	head=f;
	
	ptr=head;
	do
	{
		cout<<ptr->data<<" ";
		ptr=ptr->next;
	}while(ptr!=head);
	
	//insertion in middle
	
	cout<<endl<<"enter the position to insert "<<endl;
	cin>>pos;
	cout<<"enter the value"<<endl;
	f=new node;
	cin>>f->data;
	i=1;
	ptr=head;
	while(i<pos-1)
	{
		ptr=ptr->next;
		i++;
	}
	
	ptrn=ptr->next;
	
	ptr->next=f;
	f->next=ptrn;
	
	ptr=head;
	do
	{
		cout<<ptr->data<<" ";
		ptr=ptr->next;
	}while(ptr!=head);
	
	//insertion at end
	
	cout<<endl<<"enter the value to insert at end "<<endl;
	f=new node;
	cin>>f->data;
	ptr=head;
	do
	{
		ptr=ptr->next;
	}while(ptr->next!=head);
	
	ptr->next=f;
	f->next=head;
	
	ptr=head;
	do
	{
		cout<<ptr->data<<" ";
		ptr=ptr->next;
	}while(ptr!=head);
	

	return 0;
}
