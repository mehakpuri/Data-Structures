#include<iostream>
using namespace std;
struct node{
	int data;
	struct node *prev;
	struct node *next;
};
class doubly{
	struct node *head,*tail;
	public:
		doubly()
		{
			head=NULL;
			tail=NULL;
		}
		void insert(int value);
		void insertbeg(int value);
		void insertend(int value);
		void insertbet(int value,int elem);
		void deletee(int value);
		void search(int value);
		void display();
};
void doubly::insert(int value)
{
	struct node *f;
	f=new node;
	f->data=value;
	if(head==NULL && tail==NULL)
	{
		f->next=NULL;
		f->prev=NULL;
		head=f;
		tail=f;
	}
	else
	{
		f->next=NULL;
		f->prev=tail;
		tail->next=f;
		tail=tail->next;
	}
}
void doubly::insertbeg(int value)
{
	struct node *f;
	f=new node;
	f->data=value;
	f->next=head;
	f->prev=NULL;
	head->prev=f;
	head=f;
}
void doubly::insertend(int value)
{
	struct node *f;
	f=new node;
	f->data=value;
	f->next=NULL;
	f->prev=tail;
	tail->next=f;
	tail=f;
}
void doubly::insertbet(int value,int elem)
{
	struct node *ptr,*f;
	f=new node;
	f->data=value;
	ptr=head;
	while(ptr->data!=elem)
	{
		ptr=ptr->next;
	}
	f->next=ptr->next;
	ptr->next->prev=f;
	f->prev=ptr;
	ptr->next=f;
}
void doubly::deletee(int value)
{
	struct node *temp,*ptr;
	ptr=head;
	while(ptr->data!=value)
	{
		ptr=ptr->next;
	}
	temp=ptr->next;
	ptr->prev->next=temp;
	temp->prev=ptr->prev;
	ptr->next=NULL;
	ptr->prev=NULL;
	delete ptr;
}
void doubly::search(int value)
{
	struct node *ptr;
	int count=1;
	ptr=head;
	while(ptr->data!=value && ptr!=NULL)
	{
		ptr=ptr->next;
		count++;
	}
	if(ptr!=NULL)
	cout<<"element is at "<<count<<" position"<<endl;	
	else
	cout<<"no element found in the linked list "<<endl;
}
void doubly::display()
{
	struct node *ptr;
	ptr=head;
	while(ptr!=NULL)
	{
		cout<<ptr->data<<" ";
		ptr=ptr->next;
	}
	cout<<endl;
}

int main()
{
	int n,ch,value,ch2,elem;
	doubly d;
	cout<<"enter no of elements "<<endl;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>value;
		d.insert(value);
	}
	cout<<"enter 1 to insert new element, 2 to delete, 3 to search, 4 to display and 5 to stop "<<endl;
	cin>>ch;
	while(ch!=5)
	{
		switch(ch)
		{
			case 1: cout<<"enter 1 to insert at beginning, 2 to insert at end and 3 for in between"<<endl;
					cin>>ch2;
					cout<<"enter value ";
					cin>>value;
					if(ch2==1)
					{
						d.insertbeg(value);
					}
					else if(ch2==2)
					{
						d.insertend(value);
					}
					else
					{
						cout<<"enter the element after which you want to insert "<<endl;
						cin>>elem;
						d.insertbet(value,elem);
					}
					break;
			case 2: cout<<"enter the element to delete"<<endl;
					cin>>value;
					d.deletee(value);
					break;
			case 3: cout<<"enter the element to search"<<endl;
					cin>>value;
					d.search(value);
					break;
			case 4: d.display();
		}
		cout<<"enter again "<<endl;
		cin>>ch;
	}
}
