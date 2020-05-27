#ifndef SCREEN3VIEW_HPP
#define SCREEN3VIEW_HPP

#include <gui_generated/screen3_screen/Screen3ViewBase.hpp>
#include <gui/screen3_screen/Screen3Presenter.hpp>

class Screen3View : public Screen3ViewBase
{
public:
    Screen3View();
    virtual ~Screen3View() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    virtual void scrollList1UpdateItem(CustomContainer1& item, int16_t itemIndex);

protected:

    // Callback which is executed when a item in the scroll list is selected.
    // The parameter itemSelected is the selected item.
    Callback<Screen3View, int16_t> scrollList1ItemSelectedCallback;
    void scrollList1ItemSelectedHandler(int16_t itemSelected);

};

#endif // SCREEN3VIEW_HPP
