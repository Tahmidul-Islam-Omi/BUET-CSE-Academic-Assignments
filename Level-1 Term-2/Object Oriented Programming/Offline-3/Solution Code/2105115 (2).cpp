#include<iostream>
// your code
using namespace std;

class Point2D
{
    double x,y;
public:
    Point2D()
    {
        x = 0;
        y = 0;
    }
    Point2D(double x, double y);
    void setX(double x);
    void setY(double y);
    double getX();
    double getY();
    void print();
    ~Point2D();

    Point2D operator+( Point2D &t);
    Point2D operator*( double n);
    bool operator==( Point2D &t);
    bool operator!=( Point2D &t);



    // your code
};

Point2D::Point2D(double argx,double argy)
{
    x = argx;
    y = argy;
}

void Point2D::setX(double argx)
{
    x=argx;
}

void Point2D::setY(double argy)
{
    y = argy;
}

double Point2D::getX()
{
    return x;
}

double Point2D::getY()
{
    return y;
}

void Point2D::print()
{
    cout << "(" << x << "," << y << ")";
}

Point2D::~Point2D()
{
    x = 0;
    y = 0;
}

Point2D Point2D::operator+( Point2D &t) {
        Point2D ans;
        ans.x = this->x + t.getX();
        ans.y = this->y + t.getY();

        return ans;
}

Point2D Point2D:: operator*( double n) {
        Point2D ans;
        ans.x = this->x * n;
        ans.y = this->y * n;
        return ans;
}

bool Point2D :: operator==( Point2D &t) {
    if(this->x == t.getX() && this->y == t.getY()) {
        return true;
    }
    else {
        return false;
    }
}

bool Point2D :: operator!=( Point2D &t) {
    if(this->x != t.getX() || this->y == t.getY()) {
        return true;
    }
    else {
        return false;
    }
}


// your code

class Circle
{
    Point2D center;
    double radius;
public:
    Circle();
    Circle(Point2D c, double r);
    void setCenter(Point2D c);
    void setRadius(double r);
    Point2D getCenter();
    double getRadius();
    void print();
    ~Circle();

    Circle operator+( Point2D &t);
    Circle operator*( double n);
    Circle operator+(Circle &t);
    Circle operator-(Circle &t);
    bool operator==(Circle &t);
    bool operator<(Circle &t);
    bool operator>(Circle &t);
    bool operator<=(Circle &t);
    bool operator>=(Circle &t);
    void operator++();
    Circle operator++(int);

    // your code
};


Circle:: Circle()
{
    center.setX(0);
    center.setY(0);
    radius=0;
}

Circle::Circle(Point2D c, double r)
{
    center.setX(c.getX());
    center.setY(c.getY());
    radius=r;
}

void Circle::setCenter(Point2D c)
{
    center.setX(c.getX());
    center.setY(c.getY());
}

void Circle::setRadius(double r)
{
    radius=r;
}
Point2D Circle::getCenter()
{
    return center;
}
double Circle::getRadius()
{
    return radius;
}

void Circle::print()
{
    cout << "[Center: ";
    center.print();
    cout << " Radius: " << radius;
    cout<<"]";
}

Circle::~Circle()
{
    center.setX(0);
    center.setY(0);
    radius=0;
}

Circle Circle :: operator+( Point2D &t) {
    Circle ans;
    ans.center = this->center + t;
    ans.radius = this->radius;
    return ans;
}

Circle Circle::operator*( double n) {
    Circle ans;
    ans.center = this->center * n;
    ans.radius = this->radius * n;
    return ans;
}

Circle Circle::operator+(Circle &t) {
    Circle ans;
    ans.radius = this->radius + t.radius;
    double alpha = this->radius / (this->radius + t.radius);
    ans.center.setX( this->center.getX()*alpha + t.center.getX()*(1- alpha) );
    ans.center.setY( this->center.getY()*alpha + t.center.getY() * (1-alpha) );
    return ans;

}

Circle Circle::operator-(Circle &t) {
    Circle ans;
    ans.radius = this->radius - t.radius;
    double alpha = this->radius / (this->radius + t.radius);
    ans.center.setX( this->center.getX()*alpha + t.center.getX()*(1- alpha) );
    ans.center.setY(this->center.getY()*alpha + t.center.getY() * (1-alpha) );
    return ans;

}

bool Circle::operator==(Circle &t) {
    if(this->radius == t.radius) {
        return true;
    }

    else {
        return false;
    }
}

bool Circle::operator>(Circle &t) {
    if(this->radius > t.radius) {
        return true;
    }

    else {
        return false;
    }
}

bool Circle::operator<(Circle &t) {
    if(this->radius < t.radius) {
        return true;
    }

    else {
        return false;
    }
}

bool Circle::operator>=(Circle &t) {
    if(this->radius >= t.radius) {
        return true;
    }

    else {
        return false;
    }
}

bool Circle::operator<=(Circle &t) {
    if(this->radius <= t.radius) {
        return true;
    }
    else {
        return false;
    }
}

void Circle::operator++() {
    this->radius = this->radius + 1;
}

Circle Circle::operator++(int) {
    Circle temp;
    temp.radius = this->radius;
    this->radius = this->radius + 1;
    temp.center = this->center;
    return temp;
}



// your code

class Rectangle
{
    Point2D topRightPoint,bottomLeftPoint;
public:
    Rectangle();
    Rectangle(Point2D oneCorner,Point2D anotherCorner);
    void setTopRightPoint(Point2D oneCorner);
    void setbottomLeftPoint(Point2D anotherCorner);
    Point2D getTopRightPoint();
    Point2D getBottomLeftPoint();
    void print();
    ~Rectangle();
    Rectangle operator+( Point2D &t) {
        Rectangle ans;
        ans.topRightPoint = this->topRightPoint + t;
        ans.bottomLeftPoint = this->bottomLeftPoint + t;
        return ans;
    }
    Rectangle operator*( double n) {
        Rectangle ans;
        ans.topRightPoint = this->topRightPoint * n;
        ans.bottomLeftPoint = this->bottomLeftPoint * n;
        return ans;
    }
    // your code
};

Rectangle::Rectangle()
{
    topRightPoint.setX(0);
    topRightPoint.setY(0);
    bottomLeftPoint.setX(0);
    bottomLeftPoint.setY(0);
}
Rectangle::Rectangle(Point2D oneCorner,Point2D anotherCorner)
{
    topRightPoint=oneCorner;
    bottomLeftPoint=anotherCorner;
}

void Rectangle::setTopRightPoint(Point2D oneCorner)
{
    topRightPoint=oneCorner;
}
void Rectangle::setbottomLeftPoint(Point2D anotherCorner)
{
    bottomLeftPoint=anotherCorner;
}
Point2D Rectangle::getTopRightPoint()
{
    return topRightPoint;
}
Point2D Rectangle::getBottomLeftPoint()
{
    return bottomLeftPoint;
}

void Rectangle::print()
{
    cout<<"[Top Right Point: ";
    topRightPoint.print();
    cout<<"  Bottom left Point: ";
    bottomLeftPoint.print();
    cout<<"]";
}
Rectangle::~Rectangle()
{
    topRightPoint.setX(0);
    topRightPoint.setY(0);
    bottomLeftPoint.setX(0);
    bottomLeftPoint.setY(0);
}


int main()
{
    // Declaration
    Point2D p1(5, 10);
    Point2D p2(15, 10);
    Point2D p3;


    Circle c1(p1, 10);
    Circle c2;
    Circle c3;

    Rectangle r1(p2 , p1);
    Rectangle r2;

    // Point2D operation
    p3 = p1 + p2;
    cout << "p1 + p2: ";
    p3.print();
    cout << endl;

    p3 = p1 * 2.5;
    cout << "p1 * 2.5: ";
    p3.print();
    cout << endl;

    cout << "p1 == p2: " << (p1 == p2) << endl;
    cout << "p1 != p2: " << (p1 != p2) << endl;

    // Circle Operation

    c2 = c1 + p2;
    cout << "c1 + p2: ";
    c2.print();
    cout << endl;

    c3 = c1 * 1.5;
    cout << "c1 * 1.5: ";
    c3.print();
    cout << endl;

    c3 = c1 + c2;
    cout << "c1 + c2: ";
    c3.print();
    cout << endl;

    c3 = c1 - c2;
    cout << "c1 - c2: ";
    c3.print();
    cout << endl;

    c1.print();
    cout << endl;
    c2.print();
    cout << endl;

    cout << "c1 == c2: " << (c1 == c2) << endl;
    cout << "c1 > c2: " << (c1 > c2) << endl;
    cout << "c1 >= c2: " << (c1 >= c2) << endl;
    cout << "c1 < c2: " << (c1 < c2) << endl;
    cout << "c1 <= c2: " << (c1 <= c2) << endl;

    ++c1;
    cout << "++c1: ";
    c1.print();
    cout << endl;

    c2 = c1++;
    cout << "c2 = c1++: ";
    c2.print();
    cout << endl;

    // Rectangle Operation


    r2 = r1 + p2;
    cout << "r1 + p2: ";
    r2.print();
    cout << endl;

    r2 = r1 * 1.5;
    cout << "r1 * 1.5: ";
    r2.print();
    cout << endl;

    return 0;
}
