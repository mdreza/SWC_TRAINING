#include<iostream>
using namespace std;
#define max 12
char data[max];
char result[max];
int NumberofChar;

void removeCharat(int possition)
{
	for(int i=possition;i<NumberofChar;i++)
	{
		result[i]=result[i+1];
	}
}

void inserCharat(int possition,char ch)
{
	for(int i=NumberofChar;i>possition;i--)
	{
		result[i]=result[i-1];
	}
	result[possition]=ch;
}

void reset()
{
	for(int i=0;i<max;i++)
	{
		data[i]='\0';
		result[i]='\0';
	}
}
int findlength(char arr[max])
{
	int ln=0;
	for(int i=0;arr[i];i++)
		ln++;
	return ln;
}

void printdata()
{
	puts(result);
}
void recursion(int level)
{
	if(level==NumberofChar)
	{
		printdata();
		return;
	}
	for(int i=0;i<=findlength(result);i++)
	{
		inserCharat(i,data[level]);
		recursion(level+1);
		removeCharat(i);

	}

}
int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	bool firstime=true;
	while(gets(data))
	{
		if(firstime)
			firstime=false;
		else
			printf("\n");
		NumberofChar=findlength(data);
		recursion(0);
		reset();
		
	}	
	return 0;
}
