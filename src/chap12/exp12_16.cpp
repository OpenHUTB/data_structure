#include <iostream>
#include <stack> //包含stack<T>栈容器
using namespace std;
#define MAX_SIZE 8
int H[4] = {0, 1, 0, - 1}; //水平偏移量,下标对应方位号0～3
int V[4] = {-1, 0, 1, 0};  //垂直偏移量
char Maze[MAX_SIZE][MAX_SIZE] = {
    {'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X'} ,
    { 'O', 'O', 'O', 'O', 'O', 'X', 'X', 'X'} ,{
        'X', 'O', 'X', 'X', 'O', 'O', 'O', 'X'} ,{
        'X', 'O', 'X', 'X', 'O', 'X', 'X', 'O'} ,{
        'X', 'O', 'X', 'X', 'X', 'X', 'X', 'X'} ,{
        'X', 'O', 'X', 'X', 'O', 'O', 'O', 'X'} ,{
        'X', 'O', 'O', 'O', 'O', 'X', 'O', 'O'} ,{
        'X', 'X', 'X', 'X', 'X', 'X', 'X', 'O'}};
typedef struct {
    int i;  //当前方块的行号
    int j;  //当前方块的列号
    int di; // di是下一相邻可走方位的方位号
} Box;      //方块类型


bool FindPath(int X,int Y) //查找从(X,Y)出发的一条迷宫路径
{
    Box e;
    int i,j,i1,j1,k,di;
    bool find;
    stack<Box> st;
    e.i = X;
    e.j = Y;
    e.di = -1;
    st.push(e); //入口方块进栈
    Maze[X][Y] = ' ';
    while (!st.empty()) //栈不空循环
    {
        e = st.top(); //取栈顶方块e
        i = e.i;
        j = e.j;
        di = e.di;
        if (i == MAX_SIZE - 1 && j == MAX_SIZE - 1) //找到一条路径,输出
        {
            for (int r = 0; r < MAX_SIZE; r++) {
                printf("  ");
                for (int c = 0; c < MAX_SIZE; c++)
                    printf("%c", Maze[r][c]);
                printf("\n");
            }
            return true;
        } else //还没有找到出口的情况
        {
            find = false;
            for (k = di + 1; k < 4; k++) //试探(i,j)的di后面的方位
            {
                i1 = i + V[k];
                j1 = j + H[k];
                if (i1 >= 0 && i1 < MAX_SIZE && j1 >= 0 && j1 < MAX_SIZE &&
                    Maze[i1][j1] == 'O') {
                    find = true; //找到(i,j)的一个可走相邻方块(i1,j1)
                    break;
                }
            }
            if (find) //找到一个可走相邻方块(i1,j1)
            {
                st.top().di = k; //修改原栈顶元素的di值为k
                e.i = i1;
                e.j = j1;
                e.di = -1;
                st.push(e); //相邻可走方块e进栈
                Maze[i1][j1] = ' ';
            } else {
                st.pop();         //将栈顶方块退栈
                Maze[i][j] = 'O'; //恢复退栈方块的迷宫值
            }
        }
    }
    return false;
}

void main() 
{ 
    FindPath(0, 0);
    printf("\n");
}
