#include <stdio.h>
class Sample2 {
    int value;

  public:
    Sample2() { value = 0; }      //构造函数
    Sample2(int v) { value = v; } //重载构造函数
    int getvalue() { return value; }
    void setvalue(int v) { value = v; }
};


void main() {
    // 构造时赋初值。默认为0进行构造。
    Sample2 a[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}, b[10];
    printf("输出a:\n  ");
    for (int i = 0; i < 10; i++) {
        printf("a[%d]=%d ", i, a[i].getvalue());
        if ((i + 1) % 5 == 0)
            printf("\n  ");
    }
    printf("\n输出b:\n  ");
    for (int i = 0; i < 10; i++) {
        printf("b[%d]=%d ", i, b[i].getvalue());
        if ((i + 1) % 5 == 0)
            printf("\n  ");
    }
    printf("\n");
}
