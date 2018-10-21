#include<iostream>
using namespace std;
int search(int arr[],int n,int elem)
{
	for(int i=0;i<n;i++)
	{
		if(elem==arr[i])
			return i;
	}
	return -1;
}
int main()
{
	int arr[50],n,elem,index;
	cout<<"enter no of elements to insert"<<endl;
	cin>>n;
	cout<<"enter elements"<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	cout<<"enter the element to search"<<endl;
	cin>>elem;
	index = search(arr,n,elem);
	if(index==-1)
		cout<<"element is not present in the array "<<endl;
	else
		cout<<"element is present at index "<<index<<" in the array "<<endl;
	return 0;
}
