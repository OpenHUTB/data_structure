#include <list>
using namespace std;
void disp(list<int>& lst) //输出lst的所有元素
{
    list<int>::iterator it;
    for (it = lst.begin(); it != lst.end(); it++)
        printf("%d ", *it);
    printf("\n");
}
void main() {
    list<int> lst; //定义list容器lst
    list<int>::iterator it, start, end;
    lst.push_back(5); //添加5个整数5,2,4,1,3
    lst.push_back(2);
    lst.push_back(4);
    lst.push_back(1);
    lst.push_back(3);
    printf("初始lst: ");
    disp(lst);
    it = lst.begin();      // it指向首元素5
    start = ++lst.begin(); // start指向第2个元素2
    end = --lst.end();     // end指向尾元素3
    lst.insert(it, start, end);
    printf("执行lst.insert(it,start,end)\n");
    printf("插入后lst: ");
    disp(lst);
}
