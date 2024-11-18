// 链栈类 模板
#include<iostream>

using namespace std;

template <typename T>
struct NodeType //单链表结点的类型
{
    T data;         //数据域
    NodeType* next; //指针域
};
template <typename T>
class LiStack //链栈类模板
{
    NodeType<T>* lhead; //单链表的头结点指针
  public:
    LiStack() //构造函数,初始化栈
    {
        lhead = new NodeType<T>();
        lhead->next = NULL;
    }


       ~LiStack() //析构函数,销毁栈
    {
        NodeType<T>* p = lhead->next;
        while (p != NULL) {
            delete lhead;
            lhead = p;
            p = p->next;
        }
        delete lhead; //释放头结点空间
    }

    int StackEmpty() //判断栈是否为空
    {
        return (lhead->next == NULL);
    }

     void Push(T e) //进栈
    {
        NodeType<T>* p;
        p = new NodeType<T>();
        p->data = e;
        p->next = lhead->next; //插入p结点作为第一个数据结点
        lhead->next = p;
    }
    bool Pop(T& e) //出栈
    {
        NodeType<T>* p;
        if (lhead->next == NULL) //栈空的情况
            return false;
        p = lhead->next; // p指向第一个数据结点
        e = p->data;
        lhead->next = p->next;
        delete p;
        return true;
    }

     bool GetTop(T& e) //取栈顶元素
    {
        if (lhead->next == NULL) //栈空的情况
            return false;
        e = lhead->next->data;
        return true;
    }
};


int main() {
    LiStack<int> st1;    //整数链栈
    st1.Push(1);
    st1.Push(2);
    int i = 0;
    st1.GetTop(i);
    cout << i << endl;

    LiStack<char> st2;   //字符链栈
    LiStack<double> st3; //实数链栈

    return 1;
}
