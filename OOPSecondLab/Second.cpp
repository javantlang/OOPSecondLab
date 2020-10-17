#include <iostream>

using namespace std;

class PointSecond {
protected:
    int x;
public:
    int y;
    PointSecond() {
        cout << "PointSecond()\n";
        x = 0;
        y = 0;
    }
    PointSecond(int x, int y) {
        printf("PointSecond3D(int %d, int %d)\n", x, y);
        this->x = x;
        this->y = y;
    }
    PointSecond(PointSecond& p) {
        cout << "PointSecond(PointSecond& p)\n";
        x = p.x;
        y = p.y;
    }
    virtual ~PointSecond() {
        printf("~PointSecond(%d, %d)\n", x, y);
    }

    virtual void Secondincrease() {
        ++x;
        ++y;
    }
protected:
    int getX(PointSecond& p) {
        return this->x;
    }
private:
    int getY() {
        return this->y;
    }
};

class PointSecond3D : public PointSecond {
private:
    int z;
public:
    PointSecond3D() {
        cout << "PointSecond3D()\n";
        z = 0;
    }
    PointSecond3D(int x, int y, int z) : PointSecond(x, y) {
        printf("PointSecond3D(int %d, int %d, int %d)\n", x, y, z);
        this->z = z;
    }
    PointSecond3D(PointSecond3D& p) {
        cout << "PointSecond3D(PointSecond3D& p)\n";
        x = p.x;
        y = p.y;
        z = p.z;
    }
    ~PointSecond3D() {
        printf("~PointSecond3D(%d, %d, %d)\n", x, y, z);
    }

    void Secondincrease() {
        ++x;
        ++y;
        ++z;
    }
    void setfromPointSecond(PointSecond& p) {
        this->x = getX(p);

        /*Так как в отличии от getX getY имеет модификатор private,
        а не protected, вызвать его внутри класса потомка мы не можем 
        this->y = getY(p);*/
    }
};

int Secondmain()
{
	setlocale(0, "");
	cout << "\nSecond.cpp\n";

    {
        PointSecond3D point(1, 2, 3);
        /*Так как int x имеет модификатор доступа protected
        он доступен только внутри данного класса и классов-потомков
        Аналогично с методом getX
        point.x = 0;
        point.getX();*/

        point.y = 0;

        /*Так как int z имеет модификатор доступа privat
        у нас не получится его вызвать
        Аналогично с getY
        point.z = 0;
        point.getY();*/
    }

    PointSecond* multiPoint = new PointSecond3D(7, 7, 7);
    multiPoint->Secondincrease();

    delete multiPoint;
    return 0;
}