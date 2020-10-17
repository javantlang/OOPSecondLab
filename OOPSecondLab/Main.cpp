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
        x = p.x;
        y = p.y;
    }
    ~Point() {
        cout << "~Point()\n";
    }
};

int main()
{
    cout << "Работа началась\n";
}

