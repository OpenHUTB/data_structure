/* 输入：
12
5 2 3 3 1 3 4 2 5 2 3 5
输出：
3 4 
2 3 
5 3 
1 1 
4 1
*/
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
struct Elem {
    int d;   //整数
    int num; //出现次数
    bool operator<(const Elem& s) {
        bool result;
        if (s.num == num) //次数相同，d越小越排列在前面
            result = s.d > d;
        else //次数不同，num越大越排列在前面
            result = s.num < num;
        return result;
    }
};

int main() {
    int n;
    cin >> n;
    map<int, int> mymap;
    map<int, int>::iterator it;
    for (int i = 0; i < n; i++) //累计x的次数
    {
        int x;
        cin >> x;
        ++mymap[x];
    }
    vector<Elem> myv;
    for (it = mymap.begin(); it != mymap.end(); ++it) {
        Elem e; //由mymap产生myv
        e.d = it->first;
        e.num = it->second;
        myv.push_back(e);
    }
    sort(myv.begin(), myv.end());        // myv元素排序
    for (int j = 0; j < myv.size(); j++) //输出myv
        cout << myv[j].d << " " << myv[j].num << endl;
    return 0;
}
