#pragma once

class CLPoint3D : public CLPoint2D {
protected:
    double z;

public:
    CLPoint3D(double x, double y, double z);
    virtual void afficherCoordo() const override;
    double getZ() const { return z; }
};