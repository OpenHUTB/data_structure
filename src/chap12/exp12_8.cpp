// 使用STL算法sort()实现整型数组a的递增排序
#include <algorithm>
#include <vector>

using namespace std;

void main() {
    vector<int> myv;
    myv.push_back(1);
    myv.push_back(2);
    myv.push_back(3);
    vector<int>::iterator it;                     //定义正向迭代器it
    for (it = myv.begin(); it != myv.end(); ++it) //从头到尾遍历所有元素
        printf("%d ", *it);                       //输出：1 2 3
    printf("\n");
    vector<int>::reverse_iterator rit;
    //定义反向迭代器rit
    for (rit = myv.rbegin(); rit != myv.rend(); ++rit) //从尾到头遍历所有元素
        printf("%d ", *rit);                           //输出：3 2 1
    printf("\n");
}
