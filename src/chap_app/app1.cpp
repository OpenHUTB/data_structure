#include <stdio.h>
#include<string.h>
#define N 5
int grid[N][N];	
int dx[]={-2,-1,1,2,2,1,-1,-2};			//x方向的偏移量 
int dy[]={1,2,2,1,-1,-2,-2,-1};			//y方向的偏移量
int cnt=0;
void DFS(int i,int j,int step)			//从(i,j)格子开始游历 
{
	int ni,nj;
	if(step>=N*N)						//找到一条路径 
	{	cnt++;
		if(cnt<=3)
		{	printf("第%d个解\n",cnt); 
			for(int i=0;i<N;i++)
			{ 
				for(int j=0;j<N;j++)
					printf("  %2d", grid[i][j]);
				printf("\n");
			}
		}
		return;
	}
	for(int di=0;di<8;di++)
	{
		ni=i+dx[di];						//di方位的相邻格子是(ni,nj) 
		nj=j+dy[di];
		if(ni<0 || nj<0 || ni>=N || nj>=N) 
			continue;						//如果是边界则不可走
		if(grid[ni][nj]==0)					//如果这个方位可走
		{
			grid[ni][nj]=step+1;			//从(i,j)走到(ni,nj) 
			DFS(ni,nj,step+1);				//递归调用，继续走下去 
			grid[ni][nj]=0;					//从(ni,nj)回退 
		}
	}
}
int main()
{
	int sx, sy;
	memset(grid,0,sizeof(grid));			//初始时grid所有元素为0 
	printf("输入起始点：");
	scanf("%d %d", &sx, &sy);
	if(sx<0 || sx>=N || sy<0 || sy>=N)
	{
		printf("  起始位置错误!\n");
		return 0;
	}
	printf("\n从(%d,%d)出发的游历\n",sx,sy);
	grid[sx][sy]=1;							//(sx,sy)格子是第1步 
	DFS(sx, sy,1);
	printf(".\n\.\n");
	printf("共%d个解\n",cnt); 
	return 1;
}

