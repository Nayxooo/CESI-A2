#include "pch.h"
using namespace std;

CLParcours3D::CLParcours3D(int capacite) : CLParcours2D(capacite) {
}

double CLParcours3D::calculDistance() const {
    double distance = 0.0;
    for (size_t i = 0; i < points.size() - 1; ++i) {
        double dx = dynamic_cast<CLPoint3D*>(points[i + 1])->getX() - dynamic_cast<CLPoint3D*>(points[i])->getX();
        double dy = dynamic_cast<CLPoint3D*>(points[i + 1])->getY() - dynamic_cast<CLPoint3D*>(points[i])->getY();
        double dz = dynamic_cast<CLPoint3D*>(points[i + 1])->getZ() - dynamic_cast<CLPoint3D*>(points[i])->getZ();
        distance += sqrt(dx * dx + dy * dy + dz * dz);
    }
    return distance;
}

void CLParcours3D::message() const {
    cout << "Parcours 3D : " << calculDistance() << " units" << endl;
}

CLParcours::~CLParcours() {
    for (CLPoint* point : points) {
        delete point;
    }
    points.clear();
}

void CLParcours::ajouterPoint(CLPoint* point) {
    points.push_back(point);
}