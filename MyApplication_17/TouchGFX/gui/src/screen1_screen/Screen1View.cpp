#include <gui/screen1_screen/Screen1View.hpp>


Screen1View::Screen1View()
{

}

void Screen1View::setupScreen()
{
    Screen1ViewBase::setupScreen();
}

void Screen1View::tearDownScreen()
{
    Screen1ViewBase::tearDownScreen();
}

void Screen1View::setLog(T_MEAS currentData)
{
	touchgfx::Unicode::UnicodeChar tmp[150];
	Unicode::strncpy(tmp, (const char*)currentData.data, 150);
	Unicode::snprintf(textArea2Buffer,150, tmp);
	textArea2.invalidate();

}

