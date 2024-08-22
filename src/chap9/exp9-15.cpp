//文件名:exp9-15.cpp
//AVL算法
#include <stdio.h>
#include <malloc.h>
#define max(x,y) ((x)>(y)?(x):(y))
typedef struct node 
{	
	int key;                  		//关键字项
	int ht;                       		//当前结点的子树高度
    struct node *lchild,*rchild;		//左右孩子指针
} AVLNode;								//AVL树结点类型
void DestroyAVL(AVLNode* r)				//释放所有的结点空间
{
	if (r!=NULL)
	{
		DestroyAVL(r->lchild);			//递归释放左子树
		DestroyAVL(r->rchild);			//递归释放右子树
		delete r;						//释放根结点
	}
}
int getht(AVLNode* p)                 	//返回结点p的子树高度
{	if (p==NULL)
		return 0;
    return p->ht;
 }
AVLNode* right_rotate(AVLNode* A) 			//以结点A为根做右旋转
{	AVLNode* B=A->lchild;
	A->lchild=B->rchild;
	B->rchild=A;
	A->ht=max(getht(A->rchild),getht(A->lchild))+1;
	B->ht=max(getht(B->rchild),getht(B->lchild))+1;
	return B;
}
AVLNode* left_rotate(AVLNode* A)            //以结点A为根做左旋转
{	AVLNode* B=A->rchild;
	A->rchild=B->lchild;
	B->lchild=A;
	A->ht=max(getht(A->rchild),getht(A->lchild))+1;
	B->ht=max(getht(B->rchild),getht(B->lchild))+1;
	return B;
}
AVLNode* LL(AVLNode* A)                    	//LL型调整
{
	return right_rotate(A);
}
AVLNode* RR(AVLNode* A)                     //RR型调整
{
	return left_rotate(A);
}
AVLNode* LR(AVLNode* A)                     //LR型调整
{	AVLNode* B=A->lchild;
	A->lchild=left_rotate(B);    			//结点b左旋
	return right_rotate(A);     			//结点a右旋
}
AVLNode* RL(AVLNode* A)                     //RL型调整
{	AVLNode* B=A->rchild;
	A->rchild=right_rotate(B);   			//结点b右旋
	return left_rotate(A);     				 //结点a左旋
}
AVLNode* InsertAVL(AVLNode* r,int k)			//在AVL树r中插入关键字k 
{	if (r==NULL)                             		//空树时创建根结点
	{   AVLNode* p=(AVLNode*)malloc(sizeof(AVLNode));
		p->key=k; p->ht=1;
		p->lchild=p->rchild=NULL;
        return p;
    }
	else if (k==r->key)								//找到重复关键字时返回			
         return r;
	else if (k<r->key)                           	//k<r->key的情况
	{	r->lchild=InsertAVL(r->lchild,k);		 	//将k插入到r的左子树中
        if (getht(r->lchild)-getht(r->rchild)>=2)	//找到失衡结点r
        {	if (k<r->lchild->key)             		//k插入在r的左孩子的左子树中
                r=LL(r);               				//采用LL型调整
            else                           			//k插入在r的左孩子的右子树中
                r=LR(r);                			//采用LR型调整
        }
	}
	else                                   			//k>r->key的情况
	{	r->rchild=InsertAVL(r->rchild,k);		 	//将k插入到r的右子树中
        if (getht(r->rchild)-getht(r->lchild)>=2)   //找到失衡结点r
        {	if (k>r->rchild->key)              		//k插入在r的右孩子的右子树中
                r=RR(r);                			//采用RR型调整
            else                           			//k插入在r的右孩子的左子树中
                r=RL(r);                			//采用RL型调整
        }
    }
    r->ht=max(getht(r->lchild),getht(r->rchild))+1;   //更新结点r的高度
	return r;
}
AVLNode* Deletemin(AVLNode* r,int &mine)		//删除AVL树r中的最小结点 
{
	AVLNode *f=NULL,*p=r;
	while(p->lchild!=NULL)						//找根结点r的最左下结点p
	{
		f=p;
		p=p->lchild;
	}
	if(f==NULL)									//结点p是根结点
		r=r->rchild;
	else										//结点p不是根结点
		f->lchild=p->rchild;
	mine=p->key;
	free(p);
	return r;
}
AVLNode* Deletemax(AVLNode* r,int &maxe)			//删除AVL树r中的最大结点 
{
	AVLNode *f=NULL,*p=r;
	while(p->rchild!=NULL)						//找根结点r的最右下结点p
	{
		f=p;
		p=p->rchild;
	}
	if(f==NULL)									//结点p是根结点
		r=r->lchild;
	else										//结点p不是根结点
		f->rchild=p->lchild;
	maxe=p->key;
	free(p);
	return r;
}
void inorder(AVLNode* r)                    //中序遍历所有结点值 
{
    if (r!=NULL)
    {	inorder(r->lchild);
        printf("%d ",r->key);
        inorder(r->rchild);
    }
}
void solve(int a[],int n)
{
	AVLNode *b=NULL;
	int mine,maxe;
	for(int i=0;i<n;i++)
	{
		if(a[i]==-1)						//删除最小整数
		{
			b=Deletemin(b,mine);
			printf("删除最小元素%2d  ",mine);
			printf("序列: "); inorder(b); printf("\n");
		}			 
		else if (a[i]==-2)					//删除最大整数
		{
			b=Deletemax(b,maxe); 
			printf("删除最大元素%2d  ",maxe);
			printf("序列: "); inorder(b); printf("\n");
		}
		else								//插入一个整数 
		{
			b=InsertAVL(b,a[i]);
			printf("插入%d\t\t",a[i]);
			printf("序列: "); inorder(b); printf("\n");
		}
	} 
	DestroyAVL(b);
}
int main()
{
	int a[]={3,5,-1,6,1,2,8,-2,-2,4};
	int n=sizeof(a)/sizeof(a[0]);
	solve(a,n);
	return 1;
}
