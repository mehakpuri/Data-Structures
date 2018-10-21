#include<iostream>
#include<string.h>
#define size 100
using namespace std;
class stack
{
	char st[size],output[size];
	int top;
	public:
		stack()
		{
			top=-1;
		}
		void push(char sym);
		int pop();
		int prec(char sym);
		void infixtopostfix(char infix[]);
};
void stack::push(char sym)
{
	if(top==size-1)
	{
		cout<<"overflow"<<endl;
	}
	else
	{
		top++;
		st[top]=sym;
	}
}
int stack::pop()
{
	char temp;
	if(top==-1)
	{
		cout<<"underflow"<<endl;
	}
	else
	{
		temp=st[top];
		top--;
		return temp;	
	}
	
}
int stack::prec(char sym)
{
	if(sym=='(' || sym==')')
		return 0;
	else if(sym=='+' || sym=='-')
		return 1;
	else if(sym=='*' || sym=='/')
		return 2;
	else if(sym=='^')
		return 3;	
}
void stack::infixtopostfix(char infix[])
{
	int length,j=0;
	length=strlen(infix);
	for(int i=0;i<length;i++)
	{
		if(infix[i]!='+' && infix[i]!='-' && infix[i]!='*' && infix[i]!='/' && infix[i]!='^' && infix[i]!='(' && infix[i]!=')')
		{
			output[j++]=infix[i];
		}
		else
		{
			if(infix[i]!='(' && infix[i]!=')')
			{
				if(top==-1)
				{
					push(infix[i]);	
				}
				else
				{
					if(prec(infix[i])<=prec(st[top]))
					{
						while(prec(infix[i])<=prec(st[top]))
						{
							output[j++]=pop();
						}
					}
					push(infix[i]);
				}
			}
			else
			{
				if(infix[i]=='(')
					push(infix[i]);
				else if(infix[i]==')')
				{
					char temp;
					temp=pop();
					while(temp!='(')
					{
						output[j++]=temp;
						temp=pop();
					}
				}
			}
		}
	}
	while(top!=-1)
	{
		output[j++]=pop();
	}
	cout<<output<<endl;
}
int main()
{
	char infix[size];
	cin>>infix;
	stack s;
	s.infixtopostfix(infix);
	return 0;
}
