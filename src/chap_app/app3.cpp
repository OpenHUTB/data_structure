#include <stdio.h>
#include<string.h>
#define N 8
int grid[N][N];	
int dx[8]={-2,-1,1,2,2,1,-1,-2};			//x方向的偏移量 
int dy[8]={1,2,2,1,-1,-2,-2,-1};			//y方向的偏移量
bool DFS(int i,int j,int step)			//从(i,j)格子开始游历 
{
	if(step>=N*N) return true;
	int exists[8]={0};						//记录每个方位出口的出路数
	int nexti[8]={0};						//记录每个方位出口的格子 
	int nextj[8]={0};
	int ni,nj;
	int count, mindi;
	for(int di=0;di<8;di++)					//初始化每个方位出口的出路数为0 
		exists[di]=0;
	int total=0;							//(i,j)格子的出口数为total，初始为0 
	for(int di=0;di<8;di++)					//试探(i,j)格子的8个方位
	{
		ni=i+dx[di];						//di方位的相邻格子是(ni,nj) 
		nj=j+dy[di];
		if(ni<0 || nj<0 || ni>=N || nj>=N) 
			continue;						//如果是边界则不可走
		if(grid[ni][nj]==0)					//如果这个方位可走，记录下来
		{	nexti[total]=ni;				//(ni,nj)是(i,j)的第total个相邻可走格子
			nextj[total]=nj;
			total++;						//(i,j)格子的出口数增1
		}
	}
	if(total==0)							//如果出口数为0则返回
		return false;
	else if(total==1)						//如果只有一个出口，mindi表示该出口
		mindi=0;
	else
	{	
		for(int c=0;c<total;c++)			//求每个出口的出口数
			for(int di=0;di<8;di++)			//试探每个方位的相邻格子 
			{
				ni=nexti[c]+dx[di];
				nj=nextj[c]+dy[di];
				if(ni<0 || nj<0 || ni>=N || nj>=N)
					continue;
				if(grid[ni][nj]==0)			//(ni,nj)格子是可走的 
					exists[c]++;
			}
		int tmp=exists[0];
		mindi=0;
		for(int c=1;c<total;c++)		//在多个出口中找最小出口数的出口mindi
			if(exists[c]<tmp)
			{
				tmp=exists[c];
				mindi=c;
			}
	}
	grid[nexti[mindi]][nextj[mindi]]=step+1;
	if (DFS(nexti[mindi],nextj[mindi],step+1))
		return true;
	else
		return false;
}
int main(void)
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
	grid[sx][sy]=1;							//(sx,sy)格子是第1步 
	if(DFS(sx, sy,1))
	{
		printf("从(%d,%d)出发的游历完成，游历如下:\n",sx,sy);
		for(int i=0;i<N;i++)
		{ 
			for(int j=0;j<N;j++)
				printf("  %2d", grid[i][j]);
			printf("\n");
		}
	}
	else
		printf("游历失败！\n");
	return 1;
}

