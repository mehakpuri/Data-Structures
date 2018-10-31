#include<iostream>
using namespace std;
class radix{
	int a[50],n;
	public:
		void insert();
		void radixsort();
		int getmax();
		void countsort(int exp);
		void display();
};
void radix::insert()
{
	cout<<"enter no of elements"<<endl;
	cin>>n;
	cout<<"enter elements "<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
}
void radix::radixsort()
{
	int maxdata,exp;
	maxdata=getmax();
	for(exp=1;(maxdata/exp)>0;exp=exp*10)
	{
		countsort(exp);
	}
}
int radix::getmax()
{
	int max;
	max=a[0];
	for(int i=0;i<n;i++)
	{
		if(a[i]>max)
			max=a[i];
	}
	return max;
}
void radix::countsort(int exp)
{
	int count[10]={0};
	int output[50];
	for(int i=0;i<n;i++)
	{
		count[a[i]/exp%10]++;
	}
	for(int i=0;i<10;i++)
	{
		count[i]=count[i]+count[i-1];
	}
	for(int i=n-1;i>=0;i--)
	{
		output[count[(a[i]/exp)%10]-1]=a[i];
		count[(a[i]/exp)%10]--;
	}
	for(int i=0;i<n;i++)
	{
		a[i]=output[i];	
	}
}
void radix::display()
{
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
}
int main()
{
	radix r;
	r.insert();
	r.radixsort();
	r.display();
}
