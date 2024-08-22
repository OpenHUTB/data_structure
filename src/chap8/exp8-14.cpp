#include <iostream>
#include <cstring>
#include<vector>
#include<algorithm>
using namespace std;
#define INF 0x3f3f3f3f
#define MAXV 105 
int mat[MAXV][MAXV];
int U[MAXV];
int lowcost[MAXV];
int n;

int Prim()									//解法1：Prim算法求顶点1出发的最小生成树的权值和
{	memset(U,0,sizeof(U));
	memset(lowcost,0x3f,sizeof(lowcost));
	int ans=0;								//存放结果
	lowcost[1]=0;
	for(int i=1;i<=n;i++)
	{	int minc=INF,k=0;
		for(int j=1;j<=n;j++)					//在(V-U)中找出离U最近的顶点k
			if(!U[j] && lowcost[j]<minc)
			{	minc=lowcost[j];
				k=j;
			}
		ans+=minc;							//累计最小生成树的边权
		U[k]=1;								//标记k已经加入U
		for(int i=1;i<=n;i++)					//调整
			if(U[i]==0 && lowcost[i]>mat[k][i])
				lowcost[i]=mat[k][i];
	}
	return ans;
}
//----并查集基本运算算法 
int parent[MAXV];							//并查集存储结构
int rnk[MAXV];								//存储结点的秩
void Init(int n)								//并查集初始化
{	for (int i=1;i<=n;i++)						//顶点编号1到n 
	{	parent[i]=i;
		rnk[i]=0;
	}
}
int Find(int x)								//并查集中查找x结点的根结点
{	if (x!=parent[x])
		parent[x]=Find(parent[x]);			//路径压缩
	return parent[x];
}
void Union(int x,int y)						//并查集中x和y的两个集合的合并
{	int rx=Find(x);
	int ry=Find(y);
	if (rx==ry)								//x和y属于同一棵树的情况
		return;
	if (rnk[rx]<rnk[ry])
		parent[rx]=ry;						//rx结点作为ry的孩子 
	else
	{	if (rnk[rx]==rnk[ry])					//秩相同，合并后rx的秩增1
			rnk[rx]++;
		parent[ry]=rx;						//ry结点作为rx的孩子
	}
}
struct Edge								//边向量元素类型
{	int u;									//边的起始顶点
	int v;									//边的终止顶点
	int w;									//边的权值
	Edge(int u,int v,int w)					//构造函数
	{	this->u=u;
		this->v=v;
		this->w=w;
	}
	bool operator<(const Edge &s) const		//重载<运算符
	{
		return w<s.w;						//用于按w递增排序
	}
};
int Kruskal()								//解法2：改进的Kruskal算法求最小生成树的权值和
{	int ans=0;
	vector<Edge> E;							//建立存放所有边的向量E
	for (int i=1;i<=n;i++)						//由图的邻接矩阵g产生边向量E
		for (int j=1;j<=n;j++)
			if (i<j)
				E.push_back(Edge(i,j,mat[i][j]));
	sort(E.begin(),E.end());					//对E按权值递增排序
	Init(n);									//并查集初始化
	int k=1;									//k表示当前构造生成树的第几条边,初值为1
	int j=0;									//E中边的下标,初值为0
	while (k<n)								//生成的边数小于n时循环
	{	int u1=E[j].u;
		int v1=E[j].v;						//取一条边的起始和终止顶点
		int sn1=Find(u1);
		int sn2=Find(v1);					//分别得到两个顶点所属的集合编号
		if (sn1!=sn2)							//两顶点属于不同的集合,该边是最小生成树的一条边
		{	ans+=E[j].w;					//累计最小生成树的边权
			k++;							//生成边数增1
			Union(sn1,sn2);					//合并
		}
		j++;									//扫描下一条边
	}
	return ans;
}
int main()
{
	freopen("data14.txt","r",stdin);	//输入重定向 
	scanf("%d",&n);
	printf("村庄n=%d\n",n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			scanf("%d",&mat[i][j]);
	printf("邻接矩阵\n"); 
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			printf("%4d ",mat[i][j]);
		printf("\n");
	}
	int k;
	scanf("%d",&k);
	printf("已经建好如下%d条道路\n",k);
	for(int i=0;i<k;i++)
	{	int a,b;
		scanf("%d%d",&a,&b);
		printf("  (%d,%d)\n",a,b);
		mat[a][b]=mat[b][a]=0;
	}
	printf("求解结果\n"); 
	printf("  解法1: %d\n",Prim());
	printf("  解法2: %d\n",Kruskal());
	return 0;
}

