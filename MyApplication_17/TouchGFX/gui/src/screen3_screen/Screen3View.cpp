#include <gui/screen3_screen/Screen3View.hpp>
#include "BitmapDatabase.hpp"
#include "texts/TextKeysAndLanguages.hpp"
#include <gui_generated/containers/CustomContainer1Base.hpp>

extern UART_HandleTypeDef huart1;

Screen3View::Screen3View() :
	scrollList1ItemSelectedCallback(this, &Screen3View::scrollList1ItemSelectedHandler)
{

}

void Screen3View::setupScreen()
{
	// The item selected callbacks are registerd with scroll wheel and list
	scrollList1.setItemSelectedCallback(scrollList1ItemSelectedCallback);

	// The scroll wheel and list is updated to show the selected icons and numbers.
	for (int i = 0; i < scrollList1ListItems.getNumberOfDrawables(); i++)
	{
		scrollList1.itemChanged(i);
	}
	Screen3ViewBase::setupScreen();
}

void Screen3View::tearDownScreen()
{
    Screen3ViewBase::tearDownScreen();
}

void Screen3View::scrollList1UpdateItem(CustomContainer1& item, int16_t itemIndex)
{
    switch (itemIndex)
    {
    case 0:
    	item.updateImage(Bitmap(BITMAP_MINIDOWN_ID));
        break;
    case 1:
    	item.updateImage(Bitmap(BITMAP_MINIUP_ID));
        break;
    case 2:
    	item.updateImage(Bitmap(BITMAP_MINICAMPAGNECUIVRE_ID));
        break;
    case 3:
    	item.updateImage(Bitmap(BITMAP_MINICAMPAGNEALU_ID));
        break;
    case 4:
    	item.updateImage(Bitmap(BITMAP_MINILOWCOP_ID));
        break;
    case 5:
    	item.updateImage(Bitmap(BITMAP_MINILOGISTIQUE_ID));
        break;
    case 6:
    	item.updateImage(Bitmap(BITMAP_MINIBREAK_ID));
        break;
    case 7:
    	item.updateImage(Bitmap(BITMAP_MININEPASRECHARGER_ID));
        break;
    case 8:
    	item.updateImage(Bitmap(BITMAP_MINIMCMTQ_ID));
        break;
    case 9:
    	item.updateImage(Bitmap(BITMAP_MINITQ_ID));
        break;
      default:
    break ;
    }
}

void Screen3View::scrollList1ItemSelectedHandler(int16_t itemSelected)
{

//	touchgfx::Unicode::UnicodeChar myBuffer[10];
//	Unicode::itoa(itemSelected,myBuffer, 10, 10);
//	HAL_UART_Transmit(&huart1, (uint8_t *)myBuffer, 2, HAL_MAX_DELAY);
	presenter -> save_Item(itemSelected);

	for (int i = 0; i < 9; i++)
	{
		touchgfx::Drawable* e = scrollList1ListItems.getDrawable(i);
		CustomContainer1* dd = (CustomContainer1*)e;
		dd->cleanShape();
	}

	touchgfx::Drawable* d = scrollList1ListItems.getDrawable(itemSelected);
	CustomContainer1* cc = (CustomContainer1*)d;
	cc->updateShape();
}

