#ifndef CUSTOMCONTAINER1_HPP
#define CUSTOMCONTAINER1_HPP


#include <gui_generated/containers/CustomContainer1Base.hpp>
#include <BitmapDatabase.hpp>
#include <math.h>

class CustomContainer1 : public CustomContainer1Base
{
public:
    CustomContainer1();
    virtual ~CustomContainer1() {}

    virtual void initialize();

    void updateImage(Bitmap image);
    void updateShape();
    void cleanShape();

protected:
};

#endif // CUSTOMCONTAINER1_HPP
