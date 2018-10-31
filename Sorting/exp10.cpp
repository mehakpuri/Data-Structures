#include<iostream>
using namespace std;
class sort{
	int arr1[50],arr2[50],final[50];
	public:
		void insert(int n,int a[]);
		void selection(int n,int a[]);
		void merge(int l,int m,int r,int a1[],int a2[]);
		void display(int n);
};
void sort::insert(int n,int a[])
{
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
}
void sort::selection(int n,int a[])
{
	int temp;
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(a[i]>a[j])
			{
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
}
void sort::merge(int l,int mid,int r,int a1[],int a2[])
{
	int n1,n2,i,j,k;
	n1=mid-l+1;
	n2=r-mid;
	cout<<n1<<n2<<endl;
	for(i=0;i<n1;i++)
	{
		arr1[i]=a1[i];
	}
	for(i=0;i<n2;i++)
	{
		arr2[i]=a2[i];
	}
	i=0;
	j=0;
	k=1;
	while(i<n1 && j<n2)
	{
		if(arr1[i]<=arr2[j])
		{
			final[k]=arr1[i];
			i++;
		}
		else
		{
			final[k]=arr2[j];
			j++;
		}
		k++;
	}
	while(i<n1)
	{
		final[k]=arr1[i];
		i++;
		k++;
	}
	while(j<n2)
	{
		final[k]=arr2[j];
		k++;
		j++;
	}
}
void sort::display(int n)
{
	for(int i=1;i<=n;i++)
	{
		cout<<final[i]<<" ";
	}
	cout<<endl;
}
int main()
{
	int n1,n2,a1[50],a2[50];
	sort s;
	cout<<"enter no of elements in array 1 "<<endl;
	cin>>n1;
	cout<<"enter elements"<<endl;
	s.insert(n1,a1);
	cout<<"enter no of elements in array 2 "<<endl;
	cin>>n2;
	cout<<"enter elements"<<endl;
	s.insert(n2,a2);
	s.selection(n1,a1);
	s.selection(n2,a2);
	s.merge(0,n1-1,n1+n2-1,a1,a2);
	s.display(n1+n2);
}
