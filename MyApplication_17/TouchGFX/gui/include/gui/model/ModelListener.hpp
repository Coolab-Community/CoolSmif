#ifndef MODELLISTENER_HPP
#define MODELLISTENER_HPP

#include <gui/model/Model.hpp>

class ModelListener
{
public:
    ModelListener() : model(0) {}
    
    virtual ~ModelListener() {}

    void bind(Model* m)
    {
        model = m;
    }

    /* Call this function to notify that log has changed.
    ** override this function.*/
    virtual void notifyLogChanged() {}

protected:
    Model* model;
};

#endif // MODELLISTENER_HPP
