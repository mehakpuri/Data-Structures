#include<iostream>
using namespace std;
int q[50],front=-1,rear=-1;
void insert(int value)
{
	if(front==-1)
	{
		front=rear=0;
		q[front]=value;
	}
	else
	{
		rear++;
		q[rear]=value;
	}
}
int deletion()
{
	int temp;
	temp=q[front];
	if(front==rear)
	{
		front=rear=-1;
	}
	else
	{
		front++;
	}
	return temp;
}
int main()
{
	int n,m,i,j,k,v;
	int g[50][50],visit[50]={0},visited[50]={0};
	cout<<"enter no of vertices"<<endl;
	cin>>n;
	cout<<"enter no of edges"<<endl;
	cin>>m;
	cout<<"edges"<<endl;
	for(k=1;k<=m;k++)
	{
		cin>>i>>j;
		g[i][j]=1;
	}
	cout<<"enter initial vertex"<<endl;
	cin>>v;
	cout<<"final vertices"<<endl;
	cout<<v<<" ";
	visited[v]=1;
	k=1;
	while(k<n)
	{
		for(j=1;j<=n;j++)
		{
			if(g[v][j]!=0 &&visited[j]!=1 && visit[j]!=1)
			{
				visit[j]=1;
				insert(j);
			}
		}
		v=deletion();
		cout<<v<<" ";
		k++;
		visit[v]=0;
		visited[v]=1;
	}
	
}
