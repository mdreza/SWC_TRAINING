///*
// Vector data structure for Graph

//#include<cstdio>
#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<queue>
#define MAX 201
using namespace std;



int Node,Edge;
bool bfs(vector <int> graph[],int source);

int main()
{
	
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	
	while (scanf("%d",&Node))
	{
		if(Node==0)
			break;

		scanf("%d",&Edge);
		vector < int > nodes[MAX];
		int source,dest;	
		//printf("%d %d\n",Node,Edge);
		for(int i=1;i<=Edge;i++)
		{		
			scanf("%d%d",&source,&dest);
			nodes[source].push_back(dest);
			nodes[dest].push_back(source);
		
		}
		bool bicorable=bfs(nodes,dest);
		if(bicorable)
			printf("BICOLORABLE.\n");
		else
			printf("NOT BICOLORABLE.\n");
		source=0;
		dest=0;
	}
	
	
	return 0;
}

bool bfs(vector <int> graph[],int source)
{
	bool visitArray[MAX]={false};
	int colorArray[MAX]={0};
	queue<int> q;
	q.push(source);
	visitArray[source]=true;
	while(!q.empty())
	{
		int currentNode=q.front();
		q.pop();
		for(int i=0;i<graph[currentNode].size();i++)
		{
			if(!visitArray[graph[currentNode][i]])
			{
				visitArray[graph[currentNode][i]]=true;

				if(colorArray[currentNode]==1)
					colorArray[graph[currentNode][i]]=2;
				else
					colorArray[graph[currentNode][i]]=1;

				q.push(graph[currentNode][i]);
			}
			else
			{
				if(colorArray[graph[currentNode][i]]==colorArray[currentNode]==1)
				{
					
					return false;
				}
			}

		}
		
	}
	 return true;
}

/*
// Vector data structure for Graph

#include<cstdio>
#include<vector>
#include<queue>
#define MAX 1000
using namespace std;


vector <int> edge[MAX];
vector <int> cost[MAX];
int indeg[MAX],outdeg[MAX];
int Node,Edge;

void bfs(vector <int> graph[],int source);

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	
	scanf("%d%d",&Node,&Edge);
	for(int i=1;i<=Edge;i++)
	{
		int source,dest,weight;
		scanf("%d%d%d",&source,&dest,&weight);
		edge[source].push_back(dest);
		cost[source].push_back(weight);
		outdeg[source]++;
		indeg[dest]++;
	}

	/*

	for(int i=1;i<=Edge;i++) 
	{
		printf("%d --in:%d-out:%d->",i,indeg[i],outdeg[i]);
		int count=0;
		for(int j=0;j<edge[i].size();j++)
		{
			printf("%d(%d)",edge[i][j],cost[i][j]);
			count++;
			if(count<edge[i].size())
				printf(", ");
		}
		printf("\n");
	}

	

	 bfs(edge,1);

	return 0;
}

void bfs(vector <int> graph[],int source)
{
	int distance[MAX];
	memset(distance,-1,sizeof(distance));
	queue<int> q;
	q.push(source);
	distance[source]=0;
	while(!q.empty())
	{
		int currentNode=q.front();
		q.pop();
		for(int i=0;i<graph[currentNode].size();i++)
		{
			if(distance[graph[currentNode][i]]<0)
			{
				distance[graph[currentNode][i]]=distance[currentNode]+1;
				q.push(graph[currentNode][i]);
			}

		}
		
	}

	for(int i=1;i<=Node;i++)
	{
		printf("\n %d",distance[i]);
	}
	 
}
//*/

/* //727 - Equation

#include<iostream>
using namespace std;

int operatorPrecedence(char op)
{
	switch(op)
	{
	case '+':
		return 0;
	case '-':
		return 0;
	case '*':
		return 1;
	case '/':
		return 1;
	case '(':
		return 2;
	case ')':
		return 2;
	default:
		cout<<"no valid operator\n";
	}
}

bool isalphabet(char op)
{
	if(op>=48 && op<=57)
		return false;
	else
		return true;
}

bool isdigit(char op)
{
	if(op>=48 && op<=57)
		return true;
	else 
		return false;
}


int main()
{
	return 0;
}


*/
/*
//488 - Triangle Wave
#include<iostream>
#include<cstdio>
int main()
{
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	int T,A,F;
	scanf("%d",&T);
	while(T--)
	{
		scanf("\n%d%d",&A,&F);
		while(F--)
		{
			for(int i=1;i<=A;i++)
			{
				
				for(int j=1;j<=i;j++)
					printf("%d",i);
				printf("\n");
			}
			for(int i=A-1;i>0;i--)
			{
				
				for(int j=i;j>0;j--)
					printf("%d",i);
				printf("\n");
			}
			if(F>0)
				printf("\n");
		}
		if(T>0)
			printf("\n");
	}
	return 0;
}
*/
/*
//10226 hardwood species
#include<iostream>
#include<iomanip>
#include<cstdio>
#include<string>
#include<map>
#include<vector>
#include<algorithm>

using namespace std;
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	
	int N;
	string s="";
	cin>>N;
	getline(cin,s);
	getline(cin,s);
	while(N--)
	{
		map <string,int> treeMap;
		int total=0;
		while(getline(cin,s))
		{
			if(s.empty())
				break;
			if(treeMap.find(s)!=treeMap.end())
			{
				treeMap[s]=treeMap[s]+1;
			}
			else
			{
				treeMap[s]=1;
			}

		}
	
		for(map <string,int>::iterator it=treeMap.begin();it != treeMap.end();it++)
		{
			total+=it->second;
		}
		for(map <string,int>::iterator it=treeMap.begin();it != treeMap.end();it++)
		{
			float result=(it->second*100)/(total*1.0);
			cout<<fixed;
			cout<<setprecision(4);
			cout<<it->first<<" "<<result<<"\n";
		}
		if(N>0)
		cout<<"\n";
	}
	return 0;
}
*/
/*
//10954 - Add All
#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	
	int sum;
	int cost;
	int N;
	int data;
	while(scanf("%d",&N))
	{
		priority_queue< int, vector <int>,greater <int> > mypQueue;
		if(N==0)
			break;
		while(N--)
		{
			scanf("%d",&data);
			mypQueue.push(data);
		}		
		//mypQueue.pop();
		cost=0;
		while(mypQueue.size()>1)
		{
			sum=mypQueue.top();
			mypQueue.pop();
			sum=sum+mypQueue.top();
			mypQueue.pop();
			cost=cost+sum;
			mypQueue.push(sum);
			
		}
		printf("%d\n",cost);
		
		
	}
	return 0;
}
*/

/*
//855 - Lunch in Grid City
#include<cstdio>
#include<algorithm>
#define people 50005
int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	int numberoftestcase,numberoffriend,numberofstreer,numberofavenue,street[people],avenue[people];
	scanf("%d",&numberoftestcase);
	while(numberoftestcase--)
	{
		scanf("%d%d%d",&numberofstreer,&numberofavenue,&numberoffriend);
		for(int i=0;i<numberoffriend;i++)
		{
			scanf("%d%d",&street[i],&avenue[i]);
		}
		std::sort(street,street+numberoffriend);
		std::sort(avenue,avenue+numberoffriend);
		if(numberoffriend==1)
			printf("(Street: %d, Avenue: %d)\n",street[0],avenue[0]);
		else
		{
			if(numberoffriend%2==0)
				printf("(Street: %d, Avenue: %d)\n",street[(numberoffriend/2)-1],avenue[(numberoffriend/2)-1]);
			else
				printf("(Street: %d, Avenue: %d)\n",street[numberoffriend/2],avenue[numberoffriend/2]);
		}
		
	}
	return 0;
}
*/
/*
//11462 - Age Sort
#include<cstdio>
#define AGE 102
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int N,n,count[AGE];
	while(scanf("%d",&N))
	{
		int c=0;
		if(N==0)
			break;

		for(int i=0;i<AGE;i++)
				count[i]=0;
		while(N--)
		{
		
			scanf("%d",&n);
			count[n]++;
		}
		for(int i=0;i<AGE;i++)
		{
			if(count[i]>0)
			{
				if(c>0)
				printf(" ");
				c++;
				for(int j=0;j<count[i];j++)
				{
					if(j>0)
					printf(" ");
					printf("%d",i);
				}
				
			}
		}
		printf("\n");
		}
	
	return 0;
}
*/

/*
//11340	Newspaper
#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);

    int Testcase,rate;
	int numberOfchar,numberofLine;
	int charpricelist[257];
	unsigned long long dollar=0; // dolar must be big enough
	unsigned char c; // without unsigned wrong answer
	cin>>Testcase;
	while(Testcase--)
	{
		for(int i=0;i<257;i++)
			charpricelist[i]=0;
		dollar=0;
		cin>>numberOfchar;
		for(int i=0;i<numberOfchar;i++)
		{
			cin>>c>>rate;
			cin.ignore();
			charpricelist[(int)c]=rate;
		}
		cin>>numberofLine;
		cin.ignore();
		for(int i=0;i<numberofLine;i++)
		{
			while(c=cin.get())
			{
				if( c=='\n')
					break;
				dollar=dollar+charpricelist[(int) c];
			}
			
		}
		
		printf("%.2lf$\n",dollar/100.0);
	}
	 return 0;
}

*/
/*
int f91(int N)
{
	printf("Input N=%d \n",N);

	if(N<=100)
	{
		int i= f91(f91(N+11));
		printf("Return N=%d \n",i);
		return i;
	}
	if(N>=101)
	{
		int j=N-10;
		printf("Return Base N=%d \n",j);
		return j;
	}
}
int main()
{
	int N;
	while(scanf("%d",&N)==1 && N!=0)
	{
		printf("f91(%d) = %d\n",N,f91(N));
	}

	return 0;
}
*/



/*
int main()
{
	int NumTestCase;
	int r,c;
	while(scanf("%d",&NumTestCase)!=EOF)
	{
		for(int i=0;i<NumTestCase;i++)
		{
			scanf("%d%d",&r,&c);
			printf("%d\n",(r/3)*(c/3));
			
		}
	}
return 0;
}
*/

/*#include<iostream> // 573 the snail
#include<cstdio>

int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	int H, U, D,F;
	while(scanf("%d%d%d%d",&H, &U, &D, &F) && H>0)
	{
		double initialHeight=0;
		double distancedClimbed=U;
		double heightAfterClimbing=0;
		double heightAfterSliding=0;
		int day=0;
		while(1)
		{
			day++;
			heightAfterClimbing=initialHeight+distancedClimbed;
			if(heightAfterClimbing>H)
			{
				printf("success on day %d\n",day);
				break;
			}
			heightAfterSliding=heightAfterClimbing-D;
			if(heightAfterSliding<0)
			{
				printf("failure on day %d\n",day);
				break;
			}

			initialHeight=heightAfterSliding;
			
			if (distancedClimbed>0)
				distancedClimbed=distancedClimbed-((U*F)/100.0);
			else
				distancedClimbed=0;
		}

	}

return 0;
}

*/

/*
//10114 - Loansome Car Buyer
#include<cstdio>

int main()
{
	
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	float depArray[101];
	int numberOfmonth,numberOfdepriciation;
	float downPayment, carPrice;
	while(scanf("%d %f %f %d",&numberOfmonth,&downPayment,&carPrice,&numberOfdepriciation) && numberOfmonth>0)
	{
		
		int month;float rate;
		
		for(int i=0;i<100;i++)
		{
			depArray[i]=0;
		}
		for(int i=0;i<numberOfdepriciation;i++)
		{
			scanf("%d %f",&month,&rate);
			depArray[month]=rate;
		}
		int count=0;
		double paymentleft=carPrice,worthleft=(carPrice+downPayment)*(1-depArray[0]),permonthPayment=carPrice/numberOfmonth;
		
		double lastdepRate=depArray[0];
		while(1)
		{
			//printf("%d---%d\n",numberOfmonth,count);
			if (worthleft>paymentleft)
			{
				printf("%d month",count);
				if(count !=1)
					printf("s\n");
				else
					printf("\n");
				break;
			}
			count++;
			if(count>numberOfmonth)
				break;
			paymentleft=paymentleft-permonthPayment;

			if(depArray[count]>0)
			{
				lastdepRate=depArray[count];
				worthleft=worthleft*(1-lastdepRate);
			}
			else
			{
				worthleft=worthleft*(1-lastdepRate);
			}
			
		}
	}
	return 0;
}

*/
/*

#include<cstdio>

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int h,m;
	double hourangle,minangle,anglediff;
	while(scanf("%d:%d",&h,&m)!=EOF)
	{
		if(h==0 && m==0)
			break;
		//printf("%d--%d\n",h,m);
		hourangle=(h + m/60.0)*30.0;
		minangle=m*6.0;
		anglediff=hourangle-minangle;
		if(anglediff<0)
			anglediff*=-1;
		if(anglediff >180)
			anglediff=360-anglediff;
		printf("%.3f\n",anglediff);
	}
	return 0;
}

*/

/* MineSweeper
#include<cstdio>


int row,coloum;
int mineField[101][101];
int dr[8]={-1,+1,0,0,-1,+1,+1,-1};
int dc[8]={0,0,-1,+1,+1,+1,-1,-1};
//char mineField[101][101];
int valid(int nr,int nc,int row ,int coloum);

void fieldupdate(int r,int c,int row,int coloum)
{
	int nr,nc;
	for(int k=0;k<8;k++)
	{
		nr=r+dr[k];
		nc=c+dc[k];
		//printf("inside nr=%d nc=%d\n",nr,nc);
		if(valid(nr,nc,row,coloum))
		{
		//	printf("inside nr=%d nc=%d\n",nr,nc);
			if(mineField[nr][nc]!=-1)
			{
				mineField[nr][nc]=mineField[nr][nc]+1;
			}
		}
		
	}
}
void clearfield()
{
	for(int i=0;i<101;i++)
			for(int j=0;j<101;j++)
				mineField[i][j]=0;
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int row,coloum;
	int count=0;
	while(scanf("%d%d",&row,&coloum)!=EOF)
	{ char temp;
		if(row==0 && coloum==0)
			break;
		clearfield();


		for(int i=0;i<row;i++)
			for(int j=0;j<coloum;j++)
			{
				scanf(" %c",&temp);
				if(temp =='*')
				{
					mineField[i][j]=-1;
					fieldupdate(i,j,row,coloum);
				}
			}
			count++;
			if(count>1)
					printf("\n");
			printf("Field #%d:\n",count);
			for(int i=0;i<row;i++)
			{
				for(int j=0;j<coloum;j++)
				{
					if(mineField[i][j]==-1)
					printf("*");
					else
						printf("%d",mineField[i][j]);
				}
				printf("\n");
			}
	}

	return 0;
}

 int valid(int nr,int nc,int row ,int coloum)
 {
	if(nr>=0 && nr<row && nc>=0 && nc<coloum)
		return 1;
	else 
		return 0;
 }

 */

/*
//Beat the spread
#include<cstdio>

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n;
	long long int a,b;
	long long int x,y;
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=0;i<n;i++)
		{
			scanf("%lld %lld",&a,&b);
			if(b>a)
				printf("impossible\n");
			else
			{
			x=(a+b)/2; 
			y=(a-b)/2;
			if((x+y)==a)
				printf("%lld %lld\n",x,y);
			else
				printf("impossible\n");
			}

		}
	}

	return 0;
}

*/

/*

//Jolly Jumper

#include<cstdio>
#include<math.h>
#include<cstring>

int values[3002];
bool valuecheker[3002];
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int number;
	float diffcurr=0;
	while(scanf("%d",&number)!=EOF)
	{
		//if(number<1)
			//continue;
		//for(int k=0;k<302;k++)
			//valuecheker[k]=0;
		memset(values,0,sizeof(values));
		memset(valuecheker,0,sizeof(valuecheker));
		if(number==1)
		{
			scanf("%d",&values[0]);
			printf("Jolly\n");
			continue;
		}
		for(int j=0;j<number;j++)
		{
			scanf("%d",&values[j]);
		}

		for(int i=0;i<number-1;i++)
		{
			diffcurr=values[i]-values[i+1];
			diffcurr=fabs(diffcurr);

			valuecheker[(int)diffcurr]=1;
		}
		for(int i=1;i<number;i++)
		{
			if(valuecheker[i]!=1)
			{	
					printf("Not jolly\n");
					break;
			}
			else if(i==(number-1))
				printf("Jolly\n");
		}

	}

return 0;
}


*/
/*

//ID Codes

#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	char codes[71];
	while(true)
	{
		scanf("%s",&codes);
		if(strcmp(codes,"#")==0)
			break;
		if(std::next_permutation(codes,codes+strlen(codes)))
			printf("%s\n",codes);
		else
			printf("No Successor\n");

	}

	return 0;
}
*/
/*
#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	long long int number[10002];
	long long int a;
	int index=1,i;
	int mid,amid;
	long long int average;
	while(scanf("%lld",&a)!=EOF)
	{
		
		number[index]=a;
		std::sort(number+1,number+index+1);
		mid=index/2+1;
		amid=index/2;
		average=(number[mid]+number[amid])/2;
		if((index%2)!=0)
			printf("%lld\n",number[mid]);
		else
			printf("%lld\n",average);
		index++;	
	}
	return 0;
}

*/
//----------------------------------------------------------------------------

/*
//352 - The Seasonal War
#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
#define MAX 25
#define valid(nx,ny) nx>=0 && nx<MAX && ny>=0 && ny<MAX

int fx[]={-1,+1,+0,+0,-1,-1,+1,+1};
int fy[]={+0,+0,-1,+1,-1,+1,-1,+1};

int mat[MAX][MAX];
int vis[MAX][MAX];


void fill(int x,int y);
void reset();
int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("project.c","w",stdout);
	int D;
	int T=0;
	while(cin>>D)
	{
		T++;
		string digit="",temp;
		int count=0;
		int index=0;
		for(int i=0;i<D;i++)
		{
			cin>>temp;
			digit+=temp;
		}

		for(int i=0;i<D;i++)
		{
			for(int j=0;j<D;j++,index++)
			{
				mat[i][j]=digit[index]-'0';
				
			}
		}

		for(int i=0;i<D;i++)
		{
			for(int j=0;j<D;j++)
			{
				if((mat[i][j]==1) && (!vis[i][j]))
				{
					fill(i,j);
					count++;
				}
				
			}
		}

		cout<<"Image number "<<T<<" contains "<<count<<" war eagles.\n";
		reset();
	}

}

void fill(int x,int y)
{
	vis[x][y]=1;
	
	for(int k=0;k<8;k++)
	{
		int nx=x+fx[k];
		int ny=y+fy[k];

		if(valid(nx,ny)&&(!vis[nx][ny])&&(mat[nx][ny]==1))
		{
			fill(nx,ny);
		}
	}	
	
}

void reset()
{
	for(int i=0;i<MAX;i++)
	{
		for(int j=0;j<MAX;j++)
		{
			mat[i][j]=0;
			vis[i][j]=0;
		}
	}
}

//572 - Oil Deposits

#include<iostream>
//#include<cstdio>

using namespace std;
#define MAX 101
int row=0,col=0;
char mat[MAX][MAX];
bool vis [MAX][MAX];
int fx[]={-1,+1,+0,+0,-1,-1,+1,+1};
int fy[]={+0,+0,-1,+1,-1,+1,-1,+1};
#define valid(nx,ny) nx >= 0 && nx <row && ny >= 0 && ny<col
void fill(int x,int y);
void reset();
int main()
{
//	freopen("input.txt","r",stdin);
//	freopen("project.c","w",stdout);

	while(cin >> row >> col)
	{
		if(row==0)
			return 0;
		int count=0;
		for(int i=0;i<row;i++)
		for(int j=0;j<col;j++)
			{
				cin>>mat[i][j];
			}

		
		for(int i=0;i<row;i++)
		for(int j=0;j<col;j++)
			{
				if((!vis[i][j])&&(mat[i][j]=='@'))
				{
					fill(i,j);
					count++;
				}
			}

		cout<<count<<"\n";
		reset();
	}
	return 0;
}

void fill(int x,int y)
{
	vis[x][y]=true;
	for(int k=0;k<8;k++)
	{
		int nx=x+fx[k];
		int ny=y+fy[k];
		if(valid(nx,ny)&&(!vis[nx][ny])&&(mat[nx][ny]=='@'))
			fill(nx,ny);

	}


}
void reset()
{
	for(int i=0;i<MAX;i++)
		for(int j=0;j<MAX;j++)
		{
			mat[i][j]='\0';
			vis[i][j]=false;
		}
}


#include<iostream>

int main()
{
	int mat[1000];
	for(int i=1;i<=1000;i++)
		mat[i]=i;
	char char_a='a';
	int int_a=char_a-'\0';
	printf("char_a:%d\n",char_a);
	printf("char_a:%c\n",char_a);
	printf("int_a:%d\n",int_a);
	printf("mat_a:%d\n",mat[char_a]);
	scanf("%c",&char_a);
	return 0;
}


//10336 - Rank the Languages
#include<iostream>
using namespace std;
#define MAX 1000
int fx[]={-1,+1,+0,+0},
	fy[]={+0,+0,-1,+1};
char mat[MAX][MAX];
bool vis[MAX][MAX];
int row=0,col=0;
int T=0;
//int freeq[123]={0};
struct Letters
{
	char c;
	int f;
}freeq[123];

#define valid(nx,ny) nx>=0 && nx<row && ny>=0 && ny<col
void reset();
void fill(int x,int y,char c);
int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("project.c","w",stdout);

	cin>>T;
	for(int t=0;t<T;t++)
	{
		cin>>row>>col;

		for(int j=0;j<123;j++)
		{
			freeq[j].f=0;
			freeq[j].c=j;
		}

		for(int i=0;i<row;i++)
		{
			for(int j=0;j<col;j++)
			{
				cin>>mat[i][j];
			}

		}


		for(int i=0;i<row;i++)
			for(int j=0;j<col;j++)
			{
				if((!vis[i][j]))
				{
					freeq[mat[i][j]].f +=1;
					fill(i,j,mat[i][j]);
				}
			}
		// cofigure structure with charecter value (sorted by charecter)

		for(int i=0;i<123;i++)
			{
				for(int j=0;j<(123-1);j++)
				{
					if(freeq[j].f<freeq[j+1].f)
					{
					Letters temp;
					temp=freeq[j];
					freeq[j]=freeq[j+1];
					freeq[j+1]=temp;
					}
				}
			}
		cout<<"World #"<<t+1<<"\n";
		for(int j=0;j<123;j++)
			{
				if(freeq[j].f>0)
					cout<<freeq[j].c<<": "<<freeq[j].f<<"\n";
			}

		reset();
	}

}

void fill(int x,int y,char c)
{
	vis[x][y]=true;
	for(int i=0;i<4;i++)
	{
		int nx=x+fx[i];
		int ny=y+fy[i];
		if((valid(nx,ny))&&(!vis[nx][ny])&&(mat[nx][ny]==c))
		{
			fill(nx,ny,c);
		}
	}
}

void reset()
{
		for(int i=0;i<MAX;i++)
		{
			for(int j=0;j<MAX;j++)
				{
					vis[i][j]=false;
					mat[i][j]=0;
				}
		}
}


//784 - Maze Exploration
#include<iostream>
#include<cstdio>
//#include<_dbdao.h>
using namespace std;
int row=0,col=0;
#define valid(nx,ny) nx>0 && nx<row && ny>0 && ny<col
#define MAX_ROW 31
#define MAX_COL 81
int fx[]={-1,+1,+0,+0,-1,-1,+1,+1},
	fy[]={+0,+0,-1,+1,-1,+1,-1,+1};
char mat[MAX_ROW][MAX_COL];
void fill(int x,int y);
void reset();
int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("project.c","w",stdout);
	int T;
	scanf("%d\n",&T);
	for(int t=0;t<T;t++)
	{
		row=0,col=MAX_COL;
		while(gets(mat[row]))
		{
			if(mat[row][0]=='_')
				break;
			row++;
		}

		for(int i=0;i<=row;i++)
		{
			for(int j=0;j<MAX_COL;j++)
			{
				if((mat[i][j]=='*'))
					fill(i,j);
			}
		}

		for(int i=0;i<=row;i++)
			{
				puts(mat[i]);
			}
		reset();
	}
	return 0;
}

void fill(int x,int y)
{
	mat[x][y]='#';
	for(int i=0;i<8;i++)
	{
		int nx=x+fx[i];
		int ny=y+fy[i];

		if((valid(nx,ny))&&(mat[nx][ny]==' ') )
		{
			fill(nx,ny);
		}
	}

}

void reset()
{
	for(int i=0;i<MAX_ROW;i++)
		{
			for(int j=0;j<MAX_COL;j++)
			{
				mat[i][j]='\0';
			}
		}
}

*/
/*

cant do this
#include<iostream>
bool isThere(int num,int x,int y);
bool check(int start,int end,int x,int y);
int w,h;
#define valid(nx,ny) nx>=0 && nx<h && ny>=0 && ny<w
int mat[100][100];
int fx[]={-1,+1,+0,+0,-1,-1,+1,+1};
int fy[]={+0,+0,-1,+1,-1,+1,-1,+1};
int main()
{
	int T;
	int result=0;

	scanf("%d",&T);
	for(int t=0;t<T;t++)
	{
		scanf("%d %d",&h,&w);
		for(int i=0;i<h;i++)
		{
			for(int j=0;j<w;j++)
			{
				scanf("%d",&mat[i][j]);
			}
		}

	for(int k=1;k<6;k++)
	{
		bool found=false;
		for(int i=0;i<h && !found;i++)
		{
			for(int j=0;j<w && !found;j++)
			{
				if(mat[i][j]==1)
				{				
						if(isThere(k,i,j))
						{
							result++;
							found=true;
							break;
						}
					
				}
			}
		}
	}
		printf("%d: \n",result);
	}
	return 0;
}

bool isThere(int num,int x,int y)
{
	switch(num)
	{
		case 1:
			{
				if(check(0,1,x,y)||check(2,3,x,y))
					return true;
				break;
			}
			
		case 2:
			{
				if(check(0,3,x,y))
					return true;
				break;
			}

		default:
			//printf("Default");
			break;
	}
	return false;
}

 bool check(int start,int end,int x,int y)
 {
	 int k=0;
	 for(int i=start;i<=end;i++)
	 {
		if( valid(x+fx[i],y+fy[i]))
			k++;
	 }
	 if(k==(end-start+1))
		 return true;
	 else
		 return false;
 }




//299 - Train Swapping
#include<iostream>
int mat[52];

int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("project.c","w",stdout);
	int T,N;
	int temp=0;
	
	scanf("%d",&T);
	for(int t=0;t<T;t++)
	{
		int swap=0;
		scanf("%d",&N);
		for(int n=0;n<N;n++)
		{
			scanf("%d",&mat[n]);
		}

		for(int i=0;i<N;i++)
			for(int j=0;j<N-1;j++)
			{
				if(mat[j]>mat[j+1])
				{
					//swap
					 temp=mat[j];
					 mat[j]=mat[j+1];
					 mat[j+1]=temp;
					 swap++;
				}

			}

			printf("Optimal train swapping takes %d swaps.\n",swap);
	}
}
 */
 
 //8 queen simulation
/*
#include<iostream>
using namespace std;

int queenMap[8][8]={0};
int total=0;
int num=0;
bool clearToPlace(int x,int y)
{
	// go up-dpwm
	for(int i=0;i<8;i++)
	{
		if((queenMap[i][y]==1))
			return false;
	}
	//go left right
	for(int i=0;i<8;i++)
	{
		if((queenMap[x][i]==1))
			return false;
	}
	// go down-right diagonal

	for(int i=x,j=y;i<8 && j<8;i++,j++)
	{
		if((queenMap[i][j]==1))
			return false;
	}
	
	//go up left
	for(int i=x,j=y;i>=0 && j>=0;i--,j--)
	{
		if((queenMap[i][j]==1))
			return false;
	}
	//up right
	for(int i=x,j=y;i>=0 && j<8;i--,j++)
	{
	if((queenMap[i][j]==1))
			return false;
	}
	//down left
	for(int i=x,j=y;i<8 && j>=0;i++,j--)
	{
	if((queenMap[i][j]==1))
			return false;
	}
	// no case matched then return true
	return true;
}
void printdata()
{
	for(int i=0;i<8;i++)
	{
		printf("\n");
		for(int j=0;j<8;j++)
		{
			printf("%d ",queenMap[i][j]);
		}

	}
	printf("\n");
}

void recur(int row,int totalQueenPlaced)
{
	num++;
	int i=row;
	if(totalQueenPlaced==8)
	{
		printdata();
		printf("totalQueenPlaced: %d",totalQueenPlaced);
		printf("\n--------------------------");
		total++;
		return;
	}
	for(int colom=0;colom<8;colom++)
	{
		if(clearToPlace(row,colom))
		{
			queenMap[row][colom]=1;
			recur(row+1,totalQueenPlaced+1);
			queenMap[row][colom]=0;
		}
	}
}

int main()
{
	freopen("output.txt","w",stdout);
	recur(0,0);
	printf("\n--- Total :%d ----",total);
	return 0;	                                                                                                                                                                                                                                                                                                                                                                                                  return 0;
}

*/

//11085 	Back to the 8-Queens
#include<iostream>
#include<cstdio>
using namespace std;
int board[8][8];
int data[8];
int finalMove=1000;

void reset()
{
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<8;j++)
		{
			board[i][j]=0;
		}
		data[i]=0;
	}
	finalMove=1000;
}
void printBoard()
{
     for(int i=0;i<8;i++)
     {
          printf("\n");
         for(int j=0;j<8;j++)
            printf("%d ",board[i][j]);
     }
}

bool isSafeToPlace(int row,int colom)
{
    for(int j=colom;j>=0;j--)
        if(board[row][j]==1)
            return false;

    for(int i=row,j=colom;(i<8 && j>=0);i++,j--)
        if(board[i][j]==1)
            return false;

    for(int i=row,j=colom;(i>=0 && j>=0);i--,j--)
        if(board[i][j]==1)
            return false;

    return true;
}


void recur(int colom,int move)
{
    //printf("recursion called \n");
	
    if(colom>7)
    {
		//printf("\n----------Move :%d-----------\n",move);
		if(move<finalMove)
			finalMove=move;
		//printBoard();
        return;
    }


    for(int row=0;row<8;row++)
    {
        
            if(board[row][colom]==1)
            {
				board[row][colom]=0;
				if(isSafeToPlace(row,colom))
				{
					board[row][colom]=1;
					recur(colom+1,move);
				}else
				{
					board[row][colom]=1;
					//continue;
				}
               
            }
            else
            {
				if(isSafeToPlace(row,colom))
				{
					board[row][colom]=1;
					board[data[colom]-1][colom]=0;
					recur(colom+1,move+1);
				    board[row][colom]=0;
				    board[data[colom]-1][colom]=1;
				}

            }
    }


}
int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	int T=0;
	bool loop=true;
	while(loop)
	{
		T++;
		for(int i=0;i<8;i++)
		{
			if(scanf("%d",&data[i])==EOF)
			{
				loop=false;
				break;
			}
		}
		if(!loop)
			continue;

		for(int i=0;i<8;i++)
		{
			board[data[i]-1][i]=1;
		}
		//printBoard();
		recur(0,0);
		printf("Case %d: %d\n",T,finalMove);
		reset();
	}
    return 0;
}

//167 - The Sultan's Successors
#include<iostream>
#include<cstdio>
#define MAX 8
unsigned int realboard[MAX][MAX];
bool queenBoard[MAX][MAX]={false};
int max=0;
int temp=0;

void resetdata()
{
	temp=0;
	max=0;
	for(int i=0;i<MAX;i++)
			for(int j=0;j<MAX;j++)
			{
				realboard[i][j]=0;
				queenBoard[i][j]=false;
			}
}
bool clearToplace(int row,int colom)
{
	for(int i=0;i<MAX;i++)
		if(queenBoard[i][colom]==1)
			return false;
	for(int j=0;j<MAX;j++)
		if(queenBoard[row][j]==1)
			return false;
	for(int i=row,j=colom;(i>=0 && j>=0);i--,j--)
		if(queenBoard[i][j]==1)
			return false;
	for(int i=row,j=colom;(i<MAX && j<MAX);i++,j++)
		if(queenBoard[i][j]==1)
			return false;
	for(int i=row,j=colom;(i>=0 && j<MAX);i--,j++)
		if(queenBoard[i][j]==1)
			return false;
	for(int i=row,j=colom;(i<MAX && j>=0);i++,j--)
		if(queenBoard[i][j]==1)
			return false;
	return true;
}

int findvalue()
{
	int value=0;
	for(int i=0;i<MAX;i++)
			for(int j=0;j<MAX;j++)
			{
				if(queenBoard[i][j]==1)
				{
					value+=realboard[i][j];
				}
			}
	return value;
}

void recursion(int row,int numberofplacedQueen)
{
	if(numberofplacedQueen==8)
	{
		temp=findvalue();
		if(temp>max)
			max=temp;
		return;
	}

	for(int colom=0;colom<MAX;colom++)
	{
		if(clearToplace(row,colom))
		{
			queenBoard[row][colom]=1;
			recursion(row+1,numberofplacedQueen+1);
			queenBoard[row][colom]=0;

		}
	}
}

int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	int T=0;
	scanf("%d",&T);
	for(int t=1;t<=T;t++)
	{
		for(int i=0;i<MAX;i++)
			for(int j=0;j<MAX;j++)
				scanf("%d",&realboard[i][j]);

		recursion(0,0);
		printf("%5d\n",max);
		resetdata();
	}
	return 0;
}

//336 - A Node Too Far

 
