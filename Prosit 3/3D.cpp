#include "pch.h"
using namespace std;

CLPoint3D::CLPoint3D(double x, double y, double z) : CLPoint2D(x, y), z(z) {}

void CLPoint3D::afficherCoordo() const {
    cout << "Voici les coordonnees en 3D : (" << x << ", " << y << ", " << z << ")" << endl;
}
