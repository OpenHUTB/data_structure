#include <stdio.h>
#include<string.h>
#define N 8
int grid[N][N];	
int dx[]={-2,-1,1,2,2,1,-1,-2};			//x方向的偏移量 
int dy[]={1,2,2,1,-1,-2,-2,-1};			//y方向的偏移量
bool DFS(int i,int j,int x,int y,int step)	//搜索(i,j)->(x,y)的路径 
{
	int ni,nj;
	if(i==x && j==y)						//找到一条路径 
		return true;
	for(int di=0;di<8;di++)
	{
		ni=i+dx[di];						//di方位的相邻格子是(ni,nj) 
		nj=j+dy[di];
		if(ni<0 || nj<0 || ni>=N || nj>=N) 
			continue;						//如果是边界则不可走
		if(grid[ni][nj]==0)					//如果这个方位可走
		{
			grid[ni][nj]=step+1;			//从(i,j)走到(ni,nj) 
			if (DFS(ni,nj,x,y,step+1))			//递归调用
				return true; 
			grid[ni][nj]=0;					//从(ni,nj)回退 
		}
	}
	return false;
}
int main()
{
	int sx,sy,tx,ty;
	memset(grid,0,sizeof(grid));			//初始时grid所有元素为0 
	printf("输入起始点：");
	scanf("%d %d", &sx, &sy);
	if(sx<0 || sx>=N || sy<0 || sy>=N)
	{
		printf("  起始位置错误!\n");
		return 0;
	}
	printf("输入终止点：");
	scanf("%d %d", &tx, &ty);
	if(tx<0 || tx>=N || ty<0 || ty>=N)
	{
		printf("  终止位置错误!\n");
		return 0;
	}
	printf("\n求(%d,%d)->(%d,%d)的路径\n",sx,sy,tx,ty);
	grid[sx][sy]=1;							//(sx,sy)格子是第1步 
	if (DFS(sx,sy,tx,ty,1))
	{	printf("找到一条路径如下\n"); 
		for(int i=0;i<N;i++)
		{ 
			for(int j=0;j<N;j++)
				printf("  %2d", grid[i][j]);
			printf("\n");
		}
	}
	else
		printf("没有找到这样的路径\n");
	return 1;
}

