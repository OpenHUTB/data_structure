#include<iostream>

using namespace std;

class Sample  				//声明类Sample
{
private:
    int x,y; 				//数据成员
public:
    void setvalue(int x1,int y1); 	//成员函数
    void display();
};
void Sample::setvalue(int x1,int y1) { x=x1;y=y1; }
void Sample::display()
{
    cout << "x=" << x << ",y=" << y << endl;
}

void main()
{   Sample a;
    a.display();
    a.setvalue(1, 2);
    a.display();
}

