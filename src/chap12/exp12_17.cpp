#include <queue>
using namespace std;
void main() {
    queue<int> qu;
    qu.push(1);
    qu.push(2);
    qu.push(3);
    printf("队头元素: %d\n", qu.front());
    printf("队尾元素: %d\n", qu.back());
    printf("出队顺序: ");
    while (!qu.empty()) //出队所有元素
    {
        printf("%d ", qu.front());
        qu.pop();
    }
    printf("\n");
}
