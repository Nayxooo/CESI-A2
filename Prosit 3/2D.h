#pragma once

class CLPoint2D : public CLPoint {
public:
    CLPoint2D(double x, double y);
    virtual void afficherCoordo() const;
    double getX() const { return x; }
    double getY() const { return y; }

protected:
    double x, y;
};