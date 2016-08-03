//524 - Prime Ring Problem
#include<iostream>
using namespace std;
#define max 18
int num;
bool vis[max];
int circle[max];
bool prime[]={0,1,1,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,1};

void reset()
{
	for(int i=0;i<max;i++)
	{
		vis[i]=0;
		circle[i]=0;
	}
}

bool isprime(int number)
{
	return prime[number];
}
void recursion(int level,int previousIndex)
{
	if(level==num)
	{
		if(isprime(circle[0]+previousIndex))
		{
			bool firsttime=true;
			for(int i=0;i<num;i++)
			{
				if(firsttime)
					firsttime=false;
				else
					printf(" ");
				printf("%d",circle[i]);
			}
			printf("\n");
		}
	}

	if(level>0)
	{
		for(int i=1;i<=num;i++)
		{
			if(!vis[i])
			{
					if(isprime(previousIndex+i))
					{
						vis[i]=true;
						circle[level]=i;
						recursion(level+1,i);
						vis[i]=false;
						circle[level]=0;
					}	
			}
		}
	}else
	{
		vis[1]=true;
		circle[level]=1;
		recursion(level+1,1);
	}
}

int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	bool fistime=true;
	int tc=1;
	while(scanf("%d",&num)!=EOF)
	{
		if(fistime)
			fistime=false;
		else
			printf("\n");
			
		printf("Case %d:\n",tc++);
		recursion(0,0);
		reset();
	}
	return 0;
}
