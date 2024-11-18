#include <map>
using namespace std;
void main() {
    map<char, int> mymap; //定义map容器mymap
    mymap.insert(pair<char, int>('a', 1));
    //插入方式1
    mymap.insert(map<char, int>::value_type('b', 2));
    //插入方式2
    mymap['c'] = 3; //插入方式3
    map<char, int>::iterator it;
    for (it = mymap.begin(); it != mymap.end(); it++)
        printf("[%c,%d] ", it->first, it->second);
    printf("\n");
}