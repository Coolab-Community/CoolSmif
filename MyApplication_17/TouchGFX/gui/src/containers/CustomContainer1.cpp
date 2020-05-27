#include <gui/containers/CustomContainer1.hpp>
#include <touchgfx\Bitmap.hpp>

CustomContainer1::CustomContainer1()
{

}

void CustomContainer1::initialize()
{
    CustomContainer1Base::initialize();
}

void CustomContainer1::updateImage(Bitmap image)
{
    icon.setBitmap(image);
    icon.invalidate();
}

void CustomContainer1::updateShape()
{
    shape1.setVisible(true);
    shape1.invalidate();
}

void CustomContainer1::cleanShape()
{
    shape1.setVisible(false);
    shape1.invalidate();
}
