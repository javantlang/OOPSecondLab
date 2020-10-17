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
        printf("Point3D(int %d, int %d)\n", x, y);
        this->x = x;
        this->y = y;
    }
    Point(Point& p) {
        cout << "Point(Point& p)\n";
        x = p.x;
        y = p.y;
    }
    virtual ~Point() {
        printf("~Point(%d, %d)\n", x, y);
    }

    virtual void increase() {
        ++x;
        ++y;
    }
};

class Point3D : public Point {
private:
    int z;
public:
    Point3D() {
        cout << "Point3D()\n";
        z = 0;
    }
    Point3D(int x, int y, int z) : Point(x, y) {
        printf("Point3D(int %d, int %d, int %d)\n", x, y, z);
        this->z = z;
    }
    Point3D(Point3D& p) {
        cout << "Point3D(Point3D& p)\n";
        x = p.x;
        y = p.y;
        z = p.z;
    }
    ~Point3D() {
        printf("~Point3D(%d, %d, %d)\n", x, y, z);
    }

    void increase() {
        ++x;
        ++y;
        ++z;
    }
};

int main()
{
	setlocale(0, "");
	cout << "Second.cpp\n";
}