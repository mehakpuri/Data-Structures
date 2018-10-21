#include<iostream>
using namespace std;
struct node{
	int data;
	struct node *prev;
	struct node *next;
};
int main()
{
	struct node *f1,*head,*tail,*ptr,*ptrn;
	int i=0,n,choice,number;
	cout<<"enter the no of elements"<<endl;
	cin>>n;
	head=NULL;
	tail=NULL;
	while(i<n)
	{
		if(head==NULL && tail==NULL)
		{
			f1=new node;
			cin>>f1->data;
			f1->prev=NULL;
			f1->next=NULL;
			head=f1;
			tail=f1;
		}
		else
		{
			f1=new node;
			cin>>f1->data;
			tail->next=f1;
			f1->prev=tail;
			f1->next=NULL;
			tail=f1;
		}
		i++;
	}
	cout<<"Linked list before deletion"<<endl;
	ptr=head;
	while(ptr!=NULL)
	{
		cout<<ptr->data<<" ";
		ptr=ptr->next;
	}
	cout<<endl;
	cout<<"enter 1 for deletion at beginning, 2 for deletion at end, 3 for deletion in between"<<endl;
	cin>>choice;
	switch(choice)
	{
		case(1): ptr=head;
				ptr->next->prev=NULL;
				head=ptr->next;
				ptr->next=NULL;
				delete ptr;
				break;
		case 2: ptr=head;
				while(ptr->next->next!=NULL)
				{
					ptr=ptr->next;
				}
				ptrn=ptr->next;
				ptr->next=NULL;
				ptrn->prev=NULL;
				delete ptrn;
				tail=ptr;
				break;
		case 3: cout<<"enter the no to delete"<<endl;
				cin>>number;
				ptr=head;
				while(ptr->data!=number)
				{
					ptr=ptr->next;
				}
				ptr->prev->next=ptr->next;
				ptr->next->prev=ptr->prev;
				ptr->next=NULL;
				ptr->prev=NULL;
				delete ptr;
				break;
	}
	cout<<"Linked list after deletion"<<endl;
	ptr=head;
	while(ptr!=NULL)
	{
		cout<<ptr->data<<" "<<endl;
		ptr=ptr->next;
	}
	return 0;
}
