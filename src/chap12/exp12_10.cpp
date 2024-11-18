#include <deque>
using namespace std;

void disp(deque<int>& dq) //输出dq的所有元素
{
    deque<int>::iterator iter; //定义迭代器iter
    for (iter = dq.begin(); iter != dq.end(); iter++)
        printf("%d ", *iter);
    printf("\n");
}

void main() {
    deque<int> dq;    //建立一个双端队列dq
    dq.push_front(1); //队头插入1
    dq.push_back(2);  //队尾插入2
    dq.push_front(3); //队头插入3
    dq.push_back(4);  //队尾插入4
    printf("dq: ");
    disp(dq);
    dq.pop_front(); //删除队头元素
    dq.pop_back();  //删除队尾元素
    printf("dq: ");
    disp(dq);
}
