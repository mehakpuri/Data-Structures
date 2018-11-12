#include<iostream>
using namespace std;
struct node{
	int data;
	struct node *left,*right;
};
node *root;
void insert(node *root1,node *temp)
{
	if(root1==NULL)
	{
		root=temp;
		return;
	}
	if(root1->data>temp->data)
	{
		if(root1->left==NULL)
		{
			root1->left=temp;
		}
		else
		{
			insert(root1->left,temp);
		}
	}
	else
	{
		if(root1->right==NULL)
		{
			root1->right=temp;
		}
		else
		{
			insert(root1->right,temp);
		}
	}
}
void inorder(node *root1)
{
	if(root1==NULL)
	{
		cout<<"tree is empty"<<endl;
	}
	if(root1->left!=NULL)
	{
		inorder(root1->left);
	}
	cout<<root1->data<<" ";
	if(root1->right!=NULL)
	{
		inorder(root1->right);
	}
}
void preorder(node *root1)
{
	if(root1==NULL)
	{
		cout<<"tree is empty"<<endl;
	}
	cout<<root1->data<<" ";
	if(root1->left!=NULL)
	{
		preorder(root1->left);
	}
	if(root1->right!=NULL)
	{
		preorder(root1->right);
	}
}
void postorder(node *root1)
{
	if(root1==NULL)
	{
		cout<<"tree is empty"<<endl;
	}
	if(root1->left!=NULL)
	{
		postorder(root1->left);
	}
	if(root1->right!=NULL)
	{
		postorder(root1->right);
	}
	cout<<root1->data<<" ";
}
node* minvalnode(node* node1)
{
    node* current=node1;
    while(current->left!=NULL)
    {
        current=current->left;
    }
    return current;
}
node* deletenode(node* root1,int key)
{
    if(root1==NULL)
    {
        return NULL;
    }
    if(key<root1->data)
    {
        root1->left=deletenode(root1->left,key);

    }
    else if(key>root1->data)
    {
        root1->right=deletenode(root1->right,key);
    }
    else
    {
        if(root1->right==NULL && root1->left==NULL)
        {
            delete root1;
            root1=NULL;
        }
        else if(root1->right==NULL)
        {
            node* temp=root1;
            root1=root1->left;
            delete temp;
        }
        else if(root1->left==NULL)
        {
            node* temp=root1;
            root1=root1->right;
            delete temp;
        }
        else
        {
            node* temp=minvalnode(root1->right);
            root1->data=temp->data;
            root1->right=deletenode(root1->right,temp->data);

        }
    }
    return root1;
}
int main()
{
	struct node *temp;
	int n,d,choice;
	root=NULL;
	cout<<"enter 1 to insert,2 for inorder, 3 for preorder, 4 for postorder, 5 to delete and 6 too stop"<<endl;
	cin>>choice;
	while(choice!=6)
	{
		switch(choice)
		{
			case 1: cout<<"enter no of elements"<<endl;
					cin>>n;
					cout<<"enter elements"<<endl;
					for(int i=0;i<n;i++)
					{
						cin>>d;
						temp=new node;
						temp->data=d;
						temp->left=NULL;
						temp->right=NULL;
						insert(root,temp);
					}
					break;
			case 2: cout<<"inorder using recusrion"<<endl;
					inorder(root);
					break;
			case 3: cout<<"preorder using recursion"<<endl;
					preorder(root);
					break;
			case 4:	cout<<"postorder using recursion"<<endl;
					postorder(root);
					break;
			case 5: cout<<"enter the no to delete"<<endl;
					cin>>d;
					deletenode(root,d);
		}
		cout<<endl;
		cout<<"enter again"<<endl;
		cin>>choice;
	}
}
