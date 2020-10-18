#include <iostream>

using namespace std;

class Centre {
public:
    int x, y;

    Centre() {
        cout << "Centre()\n";
        x = 0;
        y = 0;
    }
    Centre(int x, int y) {
        printf("Centre(%d, %d)\n", x, y);
        this->x = x;
        this->y = y;
    }
    Centre(Centre& p) {
        cout << "Centre(Centre& p)\n";
        x = p.x;
        y = p.y;
    }
    virtual ~Centre() {
        printf("~Centre(%d, %d)\n", x, y);
    }
};

class Centre3D : public Centre {
public:
    int z;

    Centre3D() {
        cout << "Centre3D()\n";
        z = 0;
    }
    Centre3D(int x, int y, int z) : Centre(x, y) {
        printf("Centre3D(%d, %d, %d)\n", x, y, z);
        this->z = z;
    }
    Centre3D(Centre3D& p) {
        cout << "Centre3D(Centre3D& p)\n";
        x = p.x;
        y = p.y;
        z = p.z;
    }
    ~Centre3D() {
        printf("~Centre3D(%d, %d, %d)\n", x, y, z);
    }
};

class Sphere {
protected:
    int r;
    Centre3D* centre;
public:
    Sphere() {
        cout << "Sphere()\n";
        centre = new Centre3D;
        r = 0;
    }
    Sphere(int x, int y, int z, int r) {
        printf("Sphere(%d, %d, %d, %d)\n", x, y, z, r);
        centre = new Centre3D(x, y, z);
        this->r = r;
    }
    Sphere(Sphere& sph) {
        cout << "Sphere(Sphere& sph)\n";
        centre = new Centre3D(*sph.centre);
        r = sph.r;
    }
    ~Sphere() {
        printf("~Sphere3D(%d, %d, %d, %d)\n", centre->x, centre->y, centre->z, r);
        delete centre;
    }
};

int compositionmain()
{
    cout << "\nComposition.cpp\n";
    {
        cout << "\nСоздание объектов Sphere в стеке:\n";
        Sphere staticS1;
        Sphere staticS2(7, 7, 7, 7);
        Sphere staticS3(staticS2);

        cout << "\nУдаление объектов Sphere в стеке:\n";
    }

    cout << "\nСоздание объектов Sphere в куче:\n";
    Sphere* dynamicS1 = new Sphere();
    Sphere* dynamicS2 = new Sphere(9, 9, 9, 9);
    Sphere* dynamicS3 = new Sphere(*dynamicS2);

    cout << "\nУдаление объектов Sphere в куче:\n";
    delete dynamicS1;
    delete dynamicS2;
    delete dynamicS3;

    return 0;
}