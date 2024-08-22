#include<stdio.h>
using namespace std;
#define MAXV 1010
#define INF 0x3f3f3f3f							//定义∞
int n,m;
int D[MAXV][MAXV],C[MAXV][MAXV];
int s,t;
void Dijkstra()								//狄克斯特拉算法
{	int dist[MAXV];
	int cost[MAXV];
	int S[MAXV];
	int mindist,u;
	for(int i=1;i<=n;i++)							//dist、cost、S初始化
	{	dist[i]=D[s][i];
		cost[i]=C[s][i];
		S[i]=0;
	}
	dist[s]=cost[s]=0;
	S[s]=1;
	for(int i=0;i<n-1;i++)
	{	mindist=INF;
		u=s;
		for(int j=1;j<=n;j++)						//求尚未考虑的、距离最小的顶点u
		{	if (S[j]==0 && mindist>dist[j])
			{	mindist=dist[j];
				u=j;
			}
		}
		if (mindist==INF) break;					//找不到连通的顶点
		S[u]=1;									//将顶点u加入S集合
		for (int j=1;j<=n;j++)						//考虑顶点u,求s到每个顶点j的最短路径长度和花费
		{	int d=mindist+D[u][j];				//d记录经过顶点u的路径长度
			int c=cost[u]+C[u][j];					//c记录经过顶点u的花费
			if(S[j]==0 && d<dist[j])
			{	dist[j]=d;
				cost[j]=c;
			}
			else if(S[j]==0 && d==dist[j] && c<cost[j])
				cost[j]=c;						//有多条长度相同的最短路径时求最小花费
		}
		if(S[t]==1)								//已经求出s到t的最短路径
		{	printf("  最短距离为%d，花费为%d\n",dist[t],cost[t]);
			return;
		}
	}
}
int main()
{
	freopen("data16.txt","r",stdin);	//输入重定向 
	int a,b,d,p;
	printf("输入数据\n"); 
	scanf("%d%d",&n,&m); 
	printf("  n=%d,m=%d\n",n,m);
	for(int i=1;i<=n;i++)
	{	for(int j=1;j<=n;j++)
		{	D[i][j]=INF;
			C[i][j]=INF;
		}
	}
	int cnt=0;
	for(int i=0;i<m;i++)
	{	scanf("%d%d%d%d\n",&a,&b,&d,&p);
		printf("  第%d条边: (%d,%d),长度:%d,花费%d\n",++cnt,a,b,d,p); 
		if(D[a][b]>d)
		{	D[a][b]=D[b][a]=d;				//无向图的边是对称的
			C[a][b]=C[b][a]=p;
		}
	}
	scanf("%d%d",&s,&t);
	printf("  起点:%d  终点:%d\n",s,t); 
	printf("求解结果\n"); 
	Dijkstra();
	return 0;
}

