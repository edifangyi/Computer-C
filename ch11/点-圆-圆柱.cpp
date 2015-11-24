#include "iostream"
using namespace std;


/*******************************点类*******************************/
class Point //点类
{
private:
    int x, y;   //点的x和y坐标，私有成员
public:
    Point(int = 0, int = 0);    //构造函数
    void SetPoint( int ,int );  //设置坐标
    int GetX() { return x; }    //取x坐标  外界想取得点的坐标需要接口函数Getx
    int GetY() { return y; }    //取y坐标
    void Print();               //输出点的坐标
};
Point::Point(int a, int b) 
{ 
    SetPoint(a, b); 
}
void Point::SetPoint(int a, int b)
{
    x = a;
    y = b;
}
void Point::Print()
{
    cout << '[' << x << "," << y << ']';
}


/*******************************派生圆类****************************/
class Circle :public Point  //派生圆类
{
    double radius;  //私有成员  
public:
    Circle(int x = 0, int y = 0, double r = 0.0);
    void SetRadius(double);     //设置半径
    double GetRadius();         //取半径
    double Area();              //计算面积
    void Print();               //输出圆心坐标和半径
};

Circle::Circle(int a, int b, double r) :Point(a, b) { SetRadius(r); }
void Circle::SetRadius(double r) { radius = (r >= 0 ? r : 0); }
double Circle::GetRadius() { return radius; }
double Circle::Area() { return 3.1415926*radius*radius; }
void Circle::Print()
{
    cout << "Center =";
    Point::Print();
    cout << "; Radius =" << radius << endl;
}

/************************派生圆柱体类*******************************/
class Cylinder :public Circle   
{
    double high;
public:
    Cylinder(int x, int y, double r, double h);
    void Set_data(int x, int y, double r, double h);    //修改数据
    double Area();      //计算表面积
    double Volume();    //计算体积
    void Print();       //输出圆心坐标和半径
};
Cylinder::Cylinder(int x, int y, double r, double h) :Circle(x, y, r)
{
    high = h;
}
void Cylinder::Set_data(int x, int y, double r, double h)
{
    SetPoint(x, y);
    SetRadius(r);
    high = h;
}
double Cylinder::Volume()
{
    return Circle::Area()*high;
}
double Cylinder::Area()
{
    double r = GetRadius();
    return 2 * 3.1415926*r*r + 2 * 3.1415926*r*high;
}

int main()
{
    cout << "测试点类" << endl;
    Point p(30, 50);
    p.Print();
    cout << endl;
    system("pause");

    cout << "测试圆类" << endl;
    Circle c(120, 80, 10.0);
    cout << "圆心： ";
    c.Point::Print();
    cout << "\n圆面积: " << c.Area() << endl;
    system("pause");

    cout << endl << "测试圆柱体类" << endl;
    Cylinder cy(240, 160, 10.0, 10.0);
    cout << "圆柱体中心点： ";
    cy.Point::Print();
    cout << "\n圆柱体圆面积： " << cy.Circle::Area() << endl;
    cout << "圆柱体表面积: " << cy.Area() << endl;
    cout << "圆柱体体积: " << cy.Volume() << endl;

    system("pause");
    return 0;
}