#include <gui/screen2_screen/Screen2View.hpp>
#include <BitmapDatabase.hpp>

//extern UART_HandleTypeDef huart1;

Screen2View::Screen2View()
{

}

void Screen2View::setupScreen()
{

	Indx_Item = int(presenter -> Get_Item());
	Unicode::itoa(Indx_Item,textArea2Buffer, TEXTAREA2_SIZE, 10);  // change the numbber of the scrollwheel WildCard
	//HAL_UART_Transmit(&huart1, (uint8_t *)textArea2Buffer, 2, HAL_MAX_DELAY);

	  switch (Indx_Item) {
	        case 0 :
	          CHECK1.setBitmap(Bitmap(BITMAP_DOWN_ID));
	          CHECK1.setVisible( true ) ;
	          CHECK1.invalidate();
	        break;

	        case 1 :
	          CHECK1.setBitmap(Bitmap(BITMAP_UP_ID));
	          CHECK1.setVisible( true ) ;
	          CHECK1.invalidate();
	        break;

	        case 2 :
	          CHECK1.setBitmap(Bitmap(BITMAP_CAMPAGNECUIVRE_ID));
	          CHECK1.setVisible( true );
	          CHECK1.invalidate();
	        break;

	        case 3 :
	          CHECK1.setBitmap(Bitmap(BITMAP_CAMPAGNEALU_ID));
	          CHECK1.setVisible( true ) ;
	          CHECK1.invalidate();
	        break;
	        case 4 :
	          CHECK1.setBitmap(Bitmap(BITMAP_LOWCOP_ID));
	          CHECK1.setVisible( true ) ;
	          CHECK1.invalidate();
	        break;
	        case 5 :
	          CHECK1.setBitmap(Bitmap(BITMAP_LOGISTIQUE_ID));
	          CHECK1.setVisible( true ) ;
	          CHECK1.invalidate();
	        break;
	        case 6 :
	          CHECK1.setBitmap(Bitmap(BITMAP_BREAK_ID));
	          CHECK1.setVisible( true ) ;
	          CHECK1.invalidate();
	        break;
	        case 7 :
	          CHECK1.setBitmap(Bitmap(BITMAP_NEPASRECHARGER_ID));
	          CHECK1.setVisible( true ) ;
	          CHECK1.invalidate();
	        break;
	        case 8 :
	          CHECK1.setBitmap(Bitmap(BITMAP_MCMTQ_ID));
	          CHECK1.setVisible( true ) ;
	          CHECK1.invalidate();
	        break;
	        case 9 :
	          CHECK1.setBitmap(Bitmap(BITMAP_TQ_ID));
	          CHECK1.setVisible( true ) ;
	          CHECK1.invalidate();
	        break;

	        default:
	        break ;
	  }

    Screen2ViewBase::setupScreen();
}

void Screen2View::tearDownScreen()
{
    Screen2ViewBase::tearDownScreen();
}

