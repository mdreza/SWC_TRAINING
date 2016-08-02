// repetative element handle is the challenge
#include<iostream>
using namespace std;
#define max 13
int vis[max];
int frequency[max];
int dataset[max];
int numberofdata,targetsum,numberofactualdata=0;
bool anserfound=false;
void reset()
{
	anserfound=false;
	numberofdata=targetsum=numberofactualdata=0;
	for(int i=0;i<max;i++)                
	{
		vis[i]=dataset[i]=frequency[i]=0;
	}
}
void printvis()
{
	anserfound=true;
	bool firsttime=true;
	for(int i=0;i<max;i++)
	{
		if(vis[i])
		{
			
			for(int j=0;j<vis[i];j++)
			{
				if(firsttime)
					firsttime=false;
				else
					printf("+");

				printf("%d",dataset[i]);
			}
			
		}
	}
	printf("\n");
}
void recursion(int level,int sum)
{
	if(level==numberofactualdata)
	{
		if(sum==targetsum)
		{
			printvis();
		}
		return;
	}

	for(int i=frequency[level];i>=0;i--)// 0 element--- 1 element --- n element (recursive tree)
	{
	vis[level]=i;
	recursion(level+1,sum +(i*dataset[level]));
	vis[level]=0;
	}
}

int main()
{
	//freopen("input.txt","r",stdin);
	while(1)
	{
		
		scanf("%d %d",&targetsum,&numberofdata);
		if(targetsum==0 && numberofdata==0)
			break;
		for(int i=0;i<numberofdata;i++)
		{
			int tmp;
			scanf("%d",&tmp);
			if(i==0) // preparing frequency map from data element
			{
				dataset[numberofactualdata]=tmp;
				frequency[numberofactualdata]+=1;
				numberofactualdata++;
			}
			else
			{
				if(tmp==dataset[numberofactualdata-1])
				{
					frequency[numberofactualdata-1]+=1;
				}
				else
				{
					dataset[numberofactualdata]=tmp;
					frequency[numberofactualdata]+=1;
					numberofactualdata++;
				}
			}
			
		}
		printf("Sums of %d:\n",targetsum);
		recursion(0,0);
		if(!anserfound)
			printf("NONE\n");
		reset();
	}
	return 0;
}
