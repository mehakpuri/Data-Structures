#include<iostream>
using namespace std;
struct node{
	int data;
	struct node *next;
};
int main()
{
	struct node *ptr,*f,*head,*temp;
	head=NULL;
	int i=0,n,pos;
	cout<<"enter no of elemsnts ";
	cin>>n;
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
			f=new node;
			cin>>f->data;
			f->next=head;
			ptr->next=f;
			ptr=ptr->next;
		}
		i++;
	}
	ptr=head;
	do
	{
		cout<<ptr->data<<" ";
		ptr=ptr->next;
	}while(ptr!=head);
	
	//deletion at beg
	
	temp=head;
	ptr=head;
	do
	{
		ptr=ptr->next;
	}while(ptr->next!=head);
	
	head=head->next;
	temp->next=NULL;
	delete temp;
	ptr->next=head;
	
	ptr=head;
	cout<<endl;
	do
	{
		cout<<ptr->data<<" ";
		ptr=ptr->next;
	}while(ptr!=head);
	
	//deletion at end
	
	ptr=head;
	do
	{
		ptr=ptr->next;
	}while(ptr->next->next!=head);
	
	temp=ptr->next;
	ptr->next=head;
	temp->next=NULL;
	delete temp;
	
	ptr=head;
	cout<<endl;
	do
	{
		cout<<ptr->data<<" ";
		ptr=ptr->next;
	}while(ptr!=head);
	
	//deletion in between
	
	cout<<endl<<"enter position to delete ";
	cin>>pos;
	
	ptr=head;
	i=1;
	while(i<pos-1)
	{
		ptr=ptr->next;
		i++;
		
	}
	temp=ptr->next;
	ptr->next=ptr->next->next;
	temp->next=NULL;
	delete temp;
	
	ptr=head;
	do
	{
		cout<<ptr->data<<" ";
		ptr=ptr->next;
	}while(ptr!=head);
	
	return 0;
	
}
