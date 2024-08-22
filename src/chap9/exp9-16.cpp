//文件名:exp9-16.cpp
#include<stdio.h>
#define MaxSize 1005
int ht[MaxSize];				//哈希表
int a[MaxSize]; 
int n;
//-----哈希表操作算法开始-------
void insertht(int x,int no)		//将<x,no>插入到哈希表ht中 
{
	ht[x]=no;
}
void deleteht(int x)			//从哈希表ht中删除<x,*> 
{
	ht[x]=-1;
}
//-----哈希表操作算法结束-------
void dispa()					//输出序列 
{
	printf("a: ");
	for(int i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");
}
void inserta(int x)				//插入x 
{
	a[n]=x;						//在a的末尾添加x 
	insertht(x,n); 				//将<x,n>插入到哈希表ht中 
	n++;	
}
void deletea(int x)				//删除x
{
	int no=ht[x];				//求整数x的序号no 
	deleteht(x);				//从哈希表ht中删除x
	a[no]=a[n-1];				//将z中末尾元素移到no位置
	deleteht(a[n-1]); 			//从哈希表ht中删除a[n-1]
	insertht(a[n-1],no); 		//将<a[n-1],no>重新插入到哈希表ht中 
	n--;
}
int search(int no)				//返回序号为no的整数
{
	return a[no-1];
}
int main()
{
	int op[]={1,5,1,4,1,3,2,4,1,7,1,6,3,2,2,5,3,1,3,2};
	int m=sizeof(op)/sizeof(op[0]);		//操作次数为m/2 
	for(int i=0;i<MaxSize;i++)		//初始化哈希表ht 
		ht[i]=-1;
	n=0;
	for(int i=0;i<m;i+=2)
	{
		switch(op[i])
		{
			case 1:					//插入操作 
				printf("插入%d\t\t",op[i+1]); 
				inserta(op[i+1]);
				dispa();
				break;
			case 2:					//删除操作	
				printf("删除%d\t\t",op[i+1]); 
				deletea(op[i+1]);
				dispa();
				break;
			case 3:					//按当前序号查找 
				printf("序号%d的整数: %d\n",op[i+1],search(op[i+1])); 
				break;
		}
	}		
	return 1;
}
