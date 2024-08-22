//实验题15
//文件:exp8-15.cpp 
#include <stdio.h>
#define MAXV 105
#define INF 0x3f3f3f3f
int N,M;
void Dijkstra(int g[MAXV][MAXV],int v,int dist[MAXV])	//Dijkstra算法
{
	int S[MAXV];					//S[i]=1表示顶点i在S中, S[i]=0表示顶点i在U中
	int mindist,i,j,u;
	for (i=1;i<=N;i++)
	{	dist[i]=g[v][i];			//距离初始化
		S[i]=0;						//S[]置空
	}
	S[v]=1;							//源点编号v放入S中
	for (i=1;i<N;i++)				//循环直到所有顶点的最短路径都求出
	{	mindist=INF;				//mindist置最大长度初值
		for (j=1;j<=N;j++)			//选取不在S中（即U中）的最小距离的顶点u
			if (S[j]==0 && dist[j]<mindist) 
			{	u=j;
				mindist=dist[j];
			}
		S[u]=1;						//顶点u加入S中
		for (j=1;j<=N;j++)			//修改不在S中（即U中）的顶点的最短路径
		{
			if (S[j]==0)
				if (g[u][j]<INF && dist[u]+g[u][j]<dist[j])
					dist[j]=dist[u]+g[u][j];
		}
	}
}
int solve()								//求解算法 
{
	freopen("data15.txt","r",stdin);	//输入重定向 
	int A[MAXV][MAXV];					//正向邻接矩阵
	int B[MAXV][MAXV];					//反向邻接矩阵
	int dist1[MAXV],dist2[MAXV];
	int a,b,c;
	scanf("%d%d",&N,&M);
	printf("N=%d,M=%d\n",N,M);
	for (int i=1;i<=N;i++)				//初始化邻接矩阵 
		for(int j=1;j<=N;j++)
		{
			if(i==j)
				A[i][j]=A[i][j]=0;
			else
				A[i][j]=B[i][j]=INF;
		}
	for(int i=0;i<M;i++)
	{	scanf("%d%d%d",&a,&b,&c);		//读入一条边<a,b>:c 
		printf("<%d,%d>:%d\n",a,b,c);
		A[a][b]=B[b][a]=c;
	}
	Dijkstra(A,1,dist1);
	printf("求出dist1:  [");
	for(int i=2;i<=N;i++)
		printf("%4d",dist1[i]);
	printf("]\n");
	Dijkstra(B,1,dist2);
	printf("求出dist2:  [");
	for(int i=2;i<=N;i++)
		printf("%4d",dist2[i]);
	printf("]\n");
	int ans=0;
	for(int i=1;i<=N;i++)
		ans+=(dist1[i]+dist2[i]);
	return ans;
}

int main()
{
	printf("ans=%d\n",solve());
	return 0;
}

