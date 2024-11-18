#include <vector>
using namespace std;
void main() {
    vector<int> myv;          //定义vector容器myv
    vector<int>::iterator it; //定义myv的正向迭代器it
    myv.push_back(1);         //在myv末尾添加元素1
    it = myv.begin();         // it迭代器指向开头元素1
    myv.insert(it, 2);        //在it指向的元素之前插入元素2
    myv.push_back(3);         //在myv末尾添加元素3
    myv.push_back(4);         //在myv末尾添加元素4
    it = myv.end();           // it迭代器指向尾元素4的后面
    it--;                     // it迭代器指向尾元素4
    myv.erase(it);            //删除元素4
    for (it = myv.begin(); it != myv.end(); ++it)
        printf("%d ", *it);
    printf("\n");
}
