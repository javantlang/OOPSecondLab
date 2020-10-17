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

class Point3D : public Point {
private:
    int z;
public:
    Point3D() {
        cout << "Point3D()\n";
        z = 0;
    }
    Point3D(int x, int y, int z) {
        printf("Point3D(int %d, int %d, int %d)\n", x, y, z);
        this->x = x;
        this->y = y;
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
};

int main()
{
    setlocale(0, "");
    cout << "Word start\n";
    {
        cout << "Создание объектов Point в стеке:\n";
        Point staticP1;
        Point staticP2(7, 7);
        Point staticP3(staticP2);

        staticP1.increase();
        staticP3.decrease();
        cout << "Удаление объектов Point в стеке:\n";
    }

    cout << "Создание объектов Point в куче:\n";
    Point* dynamicP1 = new Point();
    Point* dynamicP2 = new Point(9, 9);
    Point* dynamicP3 = new Point(*dynamicP2);

    dynamicP2->decrease();
    cout << "Удаление объектов Point в куче:\n";
    delete dynamicP1;
    delete dynamicP2;
    delete dynamicP3;

    {
        cout << "Создание объектов Point3D в стеке:\n";
        Point3D staticP3D1;
        Point3D staticP3D2(7, 7, 7);
        Point3D staticP3D3(staticP3D2);
        cout << "Удаление объектов Point3D в стеке:\n";
    }
}

