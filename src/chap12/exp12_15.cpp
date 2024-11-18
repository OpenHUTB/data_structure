#include <stack>
using namespace std;
void main() {
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    printf("栈顶元素: %d\n", st.top());
    printf("出栈顺序: ");
    while (!st.empty()) //栈不空时出栈所有元素
    {
        printf("%d ", st.top());
        st.pop();
    }
    printf("\n");
}
