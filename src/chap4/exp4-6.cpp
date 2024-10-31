//文件名:exp4-6.cpp

#include<stdio.h>
#include<string.h>
#define max 100
static int count = 0; //这里我设置静态变量 看看递归可以调用几次 也就是字符串可以匹配几次 
void getnext(char *t,char next[])
{
	int k=-1,j=0,l=strlen(t);
	next[0]=-1;
	while(j<l-1)
	{
		if(k==-1||t[j]==t[k])
		{
			k++;j++;
			next[j]=k;
		}
		else k=next[k];
	}
}
void KMP(char *s,char *t)
{
	
	char next[max];
	int i=0,j=0;
	getnext(t,next);
	while(i<strlen(s)&&j<strlen(t))
	{
		if(j==-1||s[i]==t[j])
		{
			i++;j++;
		}
		else j=next[j];
	}
	if(j==strlen(t)) 
		{
		j=0;
		count++; 
		KMP(s+i,t);
		
		}
	else
		return; 
}
int main()
{
	char *s="aaabbdaabbde";
	char *t="aabbd";
	KMP(s,t);
	printf("模式串在主串中不重复出现次数为%d",count);
	return 0;
	
}

