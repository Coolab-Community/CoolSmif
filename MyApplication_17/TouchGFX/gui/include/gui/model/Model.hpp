#ifndef MODEL_HPP
#define MODEL_HPP

extern "C"
{
#include "MyTask.h"
}

class ModelListener;

class Model
{
public:
    Model();

    void bind(ModelListener* listener)
    {
        modelListener = listener;
    }

    void tick();

    // Function that allow your presenters to read current log.
    T_MEAS getCurrentLog() const { return currentLog; }

    void save_Item(int16_t Item)
       {
           Indx_Item = Item;
       }

    int16_t Get_Item()
       {
           return Indx_Item;
       }

protected:
    ModelListener* modelListener;

    // Variable storing last received log;
    T_MEAS currentLog= {0} ; // Struct defined in "MyTask.h"

    int16_t Indx_Item = 0 ;

};

#endif // MODEL_HPP
