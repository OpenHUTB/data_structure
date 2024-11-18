/*
输入：
1，2，3
输出：
2
输入：
1，2，3，4
输出：
2
*/
#include <queue>
#include <iostream>
using namespace std;


priority_queue<int, vector<int>, greater<int>> A; //小根堆
priority_queue<int> B;                            //大根堆
void Insert(int x)                                //插入整数x
{
    if (A.size() == 0) // A为空，直接插入x
    {
        A.push(x);
    }
    else if (x > A.top()) // x大于A堆顶元素,插入到A中
    {
        A.push(x);
        if (A.size() > B.size()) //若A中元素多于B，将堆顶元素移动到B中
        {
            int e = A.top();
            A.pop();
            B.push(e);
        }
    } else // x不大于A堆顶元素,插入到B中
    {
        B.push(x);
        if (B.size() > A.size()) //若B中元素多于A，将堆顶元素移动到A中
        {
            int e = B.top();
            B.pop();
            A.push(e);
        }
    }
}

void main() 
{
    int a[3] = {1, 2, 3};
    for (int i = 0; i < 3; i++) {
        Insert(a[i]);
    }
    cout << A.top() << endl;
    cout << B.top() << endl;
    printf("\n");
}
