/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/screen1_screen/Screen1ViewBase.hpp>
#include "BitmapDatabase.hpp"
#include <texts/TextKeysAndLanguages.hpp>
#include <touchgfx/Color.hpp>

Screen1ViewBase::Screen1ViewBase() :
    buttonCallback(this, &Screen1ViewBase::buttonCallbackHandler)
{

    tiledImage1.setBitmap(touchgfx::Bitmap(BITMAP_OA_ID));
    tiledImage1.setPosition(0, 0, 480, 272);
    tiledImage1.setOffset(0, 0);

    textArea1_1.setXY(170, 12);
    textArea1_1.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 0, 0));
    textArea1_1.setLinespacing(0);
    textArea1_1.setTypedText(touchgfx::TypedText(T_SINGLEUSEID4));

    tiledImage2.setBitmap(touchgfx::Bitmap(BITMAP_BACKGROUND_ID));
    tiledImage2.setPosition(29, 55, 432, 205);
    tiledImage2.setOffset(0, 0);

    textArea2.setPosition(36, 59, 418, 195);
    textArea2.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    textArea2.setLinespacing(0);
    Unicode::snprintf(textArea2Buffer, TEXTAREA2_SIZE, "%s", touchgfx::TypedText(T_SINGLEUSEID6).getText());
    textArea2.setWildcard(textArea2Buffer);
    textArea2.setTypedText(touchgfx::TypedText(T_SINGLEUSEID5));

    buttonWithLabel1.setXY(401, 193);
    buttonWithLabel1.setBitmaps(touchgfx::Bitmap(BITMAP_BLUE_BUTTONS_ROUND_ICON_BUTTON_ID), touchgfx::Bitmap(BITMAP_BLUE_BUTTONS_ROUND_ICON_BUTTON_PRESSED_ID));
    buttonWithLabel1.setLabelText(touchgfx::TypedText(T_SINGLEUSEID19));
    buttonWithLabel1.setLabelColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    buttonWithLabel1.setLabelColorPressed(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    buttonWithLabel1.setAction(buttonCallback);

    add(tiledImage1);
    add(textArea1_1);
    add(tiledImage2);
    add(textArea2);
    add(buttonWithLabel1);
}

void Screen1ViewBase::setupScreen()
{

}

void Screen1ViewBase::buttonCallbackHandler(const touchgfx::AbstractButton& src)
{
    if (&src == &buttonWithLabel1)
    {
        //Interaction1
        //When buttonWithLabel1 clicked change screen to Screen3
        //Go to Screen3 with no screen transition
        application().gotoScreen3ScreenNoTransition();
    }
}
