#include<iostream>
using namespace std;
class sort{
	int arr[50];
	public:
		void insert(int n);
		void mergesort(int l,int r);
		void merge(int l,int m,int r);
		void display(int n);
};
void sort::insert(int n)
{
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
}
void sort::mergesort(int l,int r)
{
	int total,mid;
	if(l<r)
	{
		total=l+(r-1);
		mid=total/2;
		mergesort(l,mid);
		mergesort(mid+1,r);
		merge(l,mid,r);
	}
}
void sort::merge(int l,int mid,int r)
{
	int n1,n2,i,j,k;
	n1=mid-l+1;
	n2=r-mid;
	int L[n1],R[n2];
	for(i=0;i<n1;i++)
	{
		L[i]=arr[i-l];
	}
	for(i=0;i<n2;i++)
	{
		R[i]=arr[i+mid+1];
	}
	i=0;
	j=0;
	k=1;
	while(i<n1 && j<n2)
	{
		if(L[i]<=R[j])
		{
			arr[k]=L[i];
			i++;
		}
		else
		{
			arr[k]=R[j];
			j++;
		}
		k++;
	}
	while(i<n1)
	{
		arr[k]=L[i];
		i++;
		k++;
	}
	while(j<n2)
	{
		arr[k]=R[j];
		k++;
		j++;
	}
}
void sort::display(int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}
int main()
{
	int n;
	sort s;
	cout<<"enter no of elememts"<<endl;
	cin>>n;
	cout<<"enter elements"<<endl;
	s.insert(n);
	s.mergesort(0,n-1);
	cout<<"merge sort"<<endl;
	s.display(n);
}
