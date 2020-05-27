#include <gui/screen1_screen/Screen1View.hpp>
#include <gui/screen1_screen/Screen1Presenter.hpp>

Screen1Presenter::Screen1Presenter(Screen1View& v)
    : view(v)
{

}

void Screen1Presenter::activate()
{
	 view.setLog(model->getCurrentLog());
}

void Screen1Presenter::deactivate()
{

}

void Screen1Presenter::notifyLogChanged()
{
    view.setLog(model->getCurrentLog());
}
