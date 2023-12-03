#include "pch.h"
using namespace std;

CLParcours2D::CLParcours2D(int capacite) : CLParcours() {
    points.reserve(capacite);
}

double CLParcours2D::calculDistance() const {
    double distance = 0.0;
    for (size_t i = 0; i < points.size() - 1; ++i) {
        double dx = dynamic_cast<CLPoint2D*>(points[i + 1])->getX() - dynamic_cast<CLPoint2D*>(points[i])->getX();
        double dy = dynamic_cast<CLPoint2D*>(points[i + 1])->getY() - dynamic_cast<CLPoint2D*>(points[i])->getY();
        distance += sqrt(dx * dx + dy * dy);
    }
    return distance;
}

void CLParcours2D::message() const {
    cout << "Parcours 2D : " << calculDistance() << " units" << endl;
}