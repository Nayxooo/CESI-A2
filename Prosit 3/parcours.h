#pragma once

class CLParcours {
protected:
    std::vector <CLPoint*> points;

public:
    CLParcours() {}
    virtual void ajouterPoint(CLPoint* point);
    virtual double calculDistance() const = 0;
    virtual void message() const = 0;
    virtual ~CLParcours();
};
