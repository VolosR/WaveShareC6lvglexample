
#include "Display_ST7789.h"
#include "LVGL_Driver.h"
#include "ui.h"

unsigned long time1=0;
unsigned long time2=0;
int period1=600;
int period2=400;

void setup()
{       

  LCD_Init();
  Lvgl_Init();
  ui_init();
  Set_Backlight(12);
}

int progress=0;
void loop()
{
  if(millis()>time1+period1)
    {
    period1=random(300,1200);
    time1=millis();
     _ui_label_set_property(ui_Label3, _UI_LABEL_PROPERTY_TEXT,String(random(100,255)).c_str());
    }

    
  if(millis()>time2+period2)
    {
    period2=random(300,1200);
    time2=millis();
     _ui_label_set_property(ui_Label5, _UI_LABEL_PROPERTY_TEXT,String(random(10,99)).c_str());
    }
    progress=progress+random(1,2);
    if(progress>=100)
    progress=random(0,20);
     lv_bar_set_value(ui_Bar1, progress, LV_ANIM_OFF);
  Timer_Loop();
  delay(5);
}
