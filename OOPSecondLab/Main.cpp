#include <iostream>

using namespace std;

class Point {
public:
    int x, y;
    Point() {
        cout << "Point()\n";
        x = 0;
        y = 0;
    }
    Point(int x, int y) {
        cout << "Point(int x, int y)\n";
        this->x = x;
        this->y = y;
    }
    Point(Point& p) {
        cout << "Point(Point& p)\n";
        x = p.x;
        y = p.y;
    }
    ~Point() {
        printf("~Point(%d, %d)\n", x, y);
    }

    void increase() {
        ++x;
        ++y;
    }
    void decrease();
};

void Point::decrease() {
    --x;
    --y;
}

int main()
{
    cout << "Word start\n";
    {
        Point staticP1;
        Point staticP2(7, 7);
        Point staticP3(staticP2);

        staticP1.increase();
        staticP3.decrease();
    }

    Point* dynamicP1 = new Point();
    Point* dynamicP2 = new Point(9, 9);
    Point* dynamicP3 = new Point(*dynamicP2);

    delete dynamicP1;
    delete dynamicP2;
    delete dynamicP3;
}

