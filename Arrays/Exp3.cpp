#include<iostream>
using namespace std;
int main()
{
	int arr[20],n,i,j,temp,elem,last,first,middle;
	cout<<"enter the size of the array "<<endl;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	cout<<"unsorted array "<<endl;
	for(i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(arr[j]>arr[j+1])
			{
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
	cout<<"sorted array "<<endl;
	for(i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl<<"enter the element to find "<<endl;
	cin>>elem;
	first=0;
	last=n-1;
	middle=(first+last)/2;
	while(first<=last)
	{
		if(arr[middle]<elem)
			first=middle+1;
		else if(arr[middle]==elem)
		{
			cout<<"found at location "<<middle+1<<endl;
			break;
		}
		else
			last=middle-1;
		middle = (first+last)/2;
	}
	if(first>last)
	{
		cout<<"element not found in the array"<<endl;
	}
	return 0;
}
