#include<iostream>
using namespace std;
class quick
{
	int arr[50];
	public:
		void insert(int n);
		void quicksort(int low,int high);
		int partition(int low,int high);
		void display(int n);
};
void quick::insert(int n)
{
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
}
void quick::quicksort(int low,int high)
{
	int pi;
	if(low<high)
	{

		pi = partition(low,high);
		quicksort(low,pi-1);
		quicksort(pi+1,high);
	}
}
int quick::partition(int low,int high)
{
	int pivot,i,j,temp,temp1;
	pivot=arr[low];
	i=high+1;
	for(j=high;j>=low+1;j--)
	{
		if(arr[j]>=pivot)
		{
			i--;
			temp=arr[i];
			arr[i]=arr[j];
			arr[j]=temp;
		}
	}
	temp1=arr[i-1];
	arr[i-1]=arr[low];
	arr[low]=temp1;
	return(i-1);
}
void quick::display(int n)
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
	quick q;
	cout<<"enter no of elements"<<endl;
	cin>>n;
	cout<<"enter elements "<<endl;
	q.insert(n);
	cout<<"unsorted elements"<<endl;
	q.display(n);
	q.quicksort(0,n-1);
	cout<<"quick sort "<<endl;
	q.display(n);
}
