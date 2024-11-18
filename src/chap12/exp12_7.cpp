// 使用STL算法sort()实现整型数组a的递增排序
#include <algorithm>

using namespace std;


void main() {
    int a[] = {2, 5, 4, 1, 3};
    sort(a, a + 5);
    for (int i = 0; i < 5; i++)
        printf("%d ", a[i]); //输出: 1 2 3 4 5
    printf("\n");

}
