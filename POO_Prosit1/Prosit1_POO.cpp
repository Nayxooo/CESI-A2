#include <iostream>
#include <cmath>

// namespace évite la formulation "std::cout" ou encore "std::endl"
using namespace std;

// Création de notre classe
class Coordonnees {
private:
    double x;
    double y;

public:
    // Constructeur
    Coordonnees(double xCoord, double yCoord) : x(xCoord), y(yCoord) {}

    // Méthode pour calculer la distance entre les 2 points
    double distance(Coordonnees* Point) { 
        double X = Point->x;
        double Y = Point->y;
        return sqrt(X*X + Y*Y);
    }
};

int main(){
    Coordonnees* point1 = new Coordonnees(0, 0); // "new" équivalent de malloc en C
    Coordonnees* point2 = new Coordonnees(1, 1);

    double distancePoint = point1->distance(point2);

    cout << "La distance entre les points est : " << distancePoint << endl;

    delete point1; // "delete" équivalent de free en C
    delete point2;

    return 0;
}