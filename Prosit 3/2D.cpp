#include "pch.h"
using namespace std;

CLPoint2D::CLPoint2D(double x, double y) : x(x), y(y) {}

void CLPoint2D::afficherCoordo() const {
    cout << "Voici les coordonnees en 2D : (" << x << ", " << y << ")" << endl;
}
