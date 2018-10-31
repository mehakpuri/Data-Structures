#include<iostream>
using namespace std;
class insertion
{
	int arr[50],key,i,j;
	public:
		void insert(int n);
		void sort(int n);
		void insertagain(int value,int n);
		void display(int n);
};
void insertion::insert(int n)
{
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
}
void insertion::sort(int n)
{
	for(j=1;j<n;j++)
	{

		key=arr[j];
		i=j-1;
		while(i>=0 && arr[i]>key)
		{
			arr[i+1]=arr[i];
			i=i-1;
		}
		arr[i+1]=key;
	}
}
void insertion::insertagain(int value,int n)
{
	int index,l;
	for(int k=0;k<n;k++)
	{
		if(arr[k]>value)
		{
			index=k;
			break;			
		}

	}
	cout<<"indeex"<<index<<endl;
	for(l=n;l>=index;l--)
	{
		arr[l+1]=arr[l];
	}
	arr[l+1]=value;
}
void insertion::display(int n)
{
	for(int k=0;k<n;k++)
	{
		cout<<arr[k]<<" ";
	}
	cout<<endl;
}
int main()
{
	int n,value;
	insertion obj;
	cout<<"enter the no of elements "<<endl;
	cin>>n;
	obj.insert(n);
	obj.sort(n);
	cout<<"insertion sort "<<endl;
	obj.display(n);
	cout<<"enter another element to insert"<<endl;
	cin>>value;
	obj.insertagain(value,n);
	cout<<"insertion sort "<<endl;
	obj.display(n+1);
}
