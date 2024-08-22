//文件名:exp2-6.cpp
#include "linklist.cpp"				//包含单链表的基本运算算法
#include<string.h>
void Split1(LinkNode *&L)			//解法1：将L中所有结点按首结点值进行划分
{
	LinkNode *pre,*p,*q;
	if(L->next==NULL || L->next->next==NULL)
		return;						//单链表L为空或者只有一个结点时返回 
	int x=L->next->data;			//取首结点值x 
	pre=L->next;					//pre指向首结点
	p=pre->next;					//p指向pre结点的后继结点 
	while(p!=NULL) 
	{
		if(p->data<x)				//结点p的值小于x时 
		{ 
			pre->next=p->next;		//删除结点p
			p->next=L->next;		//将结点p插入到表头
			L->next=p;
			p=pre->next;			//继续遍历 
		}
		else						//结点p的值大于等于x时 
		{
			pre=p;					//pre,p同步后移 
			p=pre->next;
		}
	}
}
void Split2(LinkNode *&L)			//解法2：将L中所有结点按首结点值进行划分
{
	LinkNode *p=L->next,*r,*L1,*r1;
	if(L->next==NULL || L->next->next==NULL)
		return;						//单链表L为空或者只有一个结点时返回 
	int x=L->next->data;			//取首结点值x 
	r=L;
	L1=(LinkNode*)malloc(sizeof(LinkNode));	//建立大于等于x的单链表L1
	r1=L1; 
	while (p!=NULL)
	{
		if (p->data<x)			//若p结点值小于x
		{
			r->next=p; r=p;
			p=p->next;
		}
		else
		{
			r1->next=p; r1=p;
			p=p->next;
		}
	}
	r1->next=NULL;
	r->next=L1->next;			//L和L1连接 
	free(L1);
}

int main()
{
	LinkNode *L;
	ElemType a[]="daxgdchaeb";
	int n=strlen(a);
	printf("解法1\n"); 
	CreateListR(L,a,n);
	printf("  L: "); DispList(L);
	printf("  以首结点值进行划分\n");
	Split1(L);
	printf("  L: "); DispList(L);
	DestroyList(L);
	printf("解法2\n"); 
	CreateListR(L,a,n);
	printf("  L: "); DispList(L);
	printf("  以首结点值进行划分\n");
	Split2(L);
	printf("  L: "); DispList(L);
	DestroyList(L);
	return 1;
}
