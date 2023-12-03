#pragma once

class CLParcours2D : public CLParcours {
public:
    CLParcours2D(int capacite);
    virtual double calculDistance() const override;
    virtual void message() const override;
};
