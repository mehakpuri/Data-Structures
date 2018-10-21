#include<iostream>
using namespace std;
int main()
{
	int arr[50],n,ch,elem,pos,index;
	cout<<"enter no of elements to insert"<<endl;
	cin>>n;
	cout<<"enter elements"<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	cout<<"enter 1 to insert new element, 2 to delete, 3 to find location, 4 to display and 5 to stop"<<endl;
	cin>>ch;
	while(ch!=5)
	{
		switch(ch)
		{
			case 1: cout<<"enter the element to insert ";
					cin>>elem;
					cout<<"enter the position ";
					cin>>pos;
					for(int j=n-1;j>=pos-1;j--)
					{
						arr[j+1]=arr[j];
					}
					arr[pos-1]=elem;
					n=n+1;
					for(int i=0;i<n;i++)
					{
						cout<<arr[i]<<" ";
					}
					cout<<endl;
					break;
			case 2: cout<<"enter the position of element to delete ";
					cin>>pos;
					for(int j=pos-1;j<n;j++)
					{
						arr[j]=arr[j+1];
					}
					n=n-1;
					for(int i=0;i<n;i++)
					{
						cout<<arr[i]<<" ";
					}
					cout<<endl;
					break;
			case 3: cout<<"enter the element to find its location ";
					cin>>elem;
					for(int i=0;i<n;i++)
					{
						if(arr[i]==elem)
						{
							index=i;
							break;
						}
					}
					cout<<"element "<<elem<<" is at index "<<index<<endl;
					break;
			case 4: cout<<"array elements are "<<endl;
					for(int i=0;i<n;i++)
					{
						cout<<arr[i]<<" ";
					}
					cout<<endl;
					
		}
		cout<<"enter choice again "<<endl;
		cin>>ch;
	}
	
}
