#ifndef CUSTOMCONTAINER2_HPP
#define CUSTOMCONTAINER2_HPP


#include <gui_generated/containers/CustomContainer2Base.hpp>
#include <BitmapDatabase.hpp>
#include <math.h>

extern UART_HandleTypeDef huart1;

class CustomContainer2 : public CustomContainer2Base
{
public:
    CustomContainer2();
    virtual ~CustomContainer2() {}

    virtual void initialize();

    int setNumber2 (int no)
        {
          Unicode::itoa(no,textArea1Buffer, TEXTAREA1_SIZE, 10);  // change the numbber of the scrollwheel WildCard
          switch (no % 10)
          {
              case 0:
                  icon.setBitmap(Bitmap(BITMAP_MINIDOWN_ID));     // change the image of the scrollwheel icon
                  HAL_UART_Transmit(&huart1, (uint8_t *)textArea1Buffer, 2, HAL_MAX_DELAY);
                  break;
              case 1:
                  icon.setBitmap(Bitmap(BITMAP_MINIUP_ID));
                  HAL_UART_Transmit(&huart1, (uint8_t *)textArea1Buffer, 2, HAL_MAX_DELAY);
                  break;
              case 2:
                  icon.setBitmap(Bitmap(BITMAP_MINICAMPAGNECUIVRE_ID));
                  HAL_UART_Transmit(&huart1, (uint8_t *)textArea1Buffer, 2, HAL_MAX_DELAY);
                  break;
              case 3:
                  icon.setBitmap(Bitmap(BITMAP_MINICAMPAGNEALU_ID));
                  HAL_UART_Transmit(&huart1, (uint8_t *)textArea1Buffer, 2, HAL_MAX_DELAY);
                  break;
              case 4:
                  icon.setBitmap(Bitmap(BITMAP_MINILOWCOP_ID));
                  HAL_UART_Transmit(&huart1, (uint8_t *)textArea1Buffer, 2, HAL_MAX_DELAY);
                  break;
              case 5:
                  icon.setBitmap(Bitmap(BITMAP_MINILOGISTIQUE_ID));
                  HAL_UART_Transmit(&huart1, (uint8_t *)textArea1Buffer, 2, HAL_MAX_DELAY);
                  break;
              case 6:
                  icon.setBitmap(Bitmap(BITMAP_MINIBREAK_ID));
                  HAL_UART_Transmit(&huart1, (uint8_t *)textArea1Buffer, 2, HAL_MAX_DELAY);
                  break;
              case 7:
                  icon.setBitmap(Bitmap(BITMAP_MININEPASRECHARGER_ID));
                  HAL_UART_Transmit(&huart1, (uint8_t *)textArea1Buffer, 2, HAL_MAX_DELAY);
                  break;
              case 8:
                  icon.setBitmap(Bitmap(BITMAP_MINIMCMTQ_ID));
                  HAL_UART_Transmit(&huart1, (uint8_t *)textArea1Buffer, 2, HAL_MAX_DELAY);
                  break;
              case 9:
                  icon.setBitmap(Bitmap(BITMAP_MINITQ_ID));
                  HAL_UART_Transmit(&huart1, (uint8_t *)textArea1Buffer, 2, HAL_MAX_DELAY);
                  break;
               default:
            break ;
          }
          return no;
        }

protected:
};

#endif // CUSTOMCONTAINER2_HPP
