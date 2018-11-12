#include<iostream>
using namespace std;
int top=-1,stack[50];
void push(int x)
{
	++top;
	stack[top]=x;
}
int pop()
{
	int temp;
	temp=stack[top];
	top--;
	return temp;
}
int main()
{
	int n,m,i,j,k,v;
	int g[50][50],visit[50]={0},visited[50]={0};
	cout<<"enter vertices "<<endl;
	cin>>n;
	cout<<"enter edges"<<endl;
	cin>>m;
	for(k=1;k<=m;k++)
	{
		cin>>i>>j;
		g[i][j]=1;	
	}
	cout<<"enter initial vertex"<<endl;	
	cin>>v;
	cout<<"Final vertices"<<endl;
	cout<<v<<" ";
	visited[v]=1;
	k=1;
	while(k<n)
	{
		for(j=n;j>=1;j--)
		{
			if(g[v][j]!=0 && visited[j]!=1 && visit[j]!=1)
			{
				visit[j]=1;
				push(j);
			}
		}
		if(top==-1)
		{
			return 0;
		}
		v=pop();
		k++;
		cout<<v<<" ";
		visit[v]=0;
		visited[v]=1;
	}
	
}
