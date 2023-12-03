#pragma once

class CLParcours3D : public CLParcours2D {
public:
    CLParcours3D(int capacite);
    virtual double calculDistance() const override;
    virtual void message() const override;
};
