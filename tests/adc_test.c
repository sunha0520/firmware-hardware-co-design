#include "adc.h"
#include "pcf50606.h"

// stub
int pcf50606_read(int any_addr)
{
   return 42;
}

// stub
int pcf50606_write(int any_addr, unsigned char any_value)
{
   return 12;
}

int main(void)
{
   int ok;
   ok = test_adc_read();
   if(!ok)
      return 1;

   return 0;
}

int test_adc_read(void)
{
   unsigned short data = adc_read(ADC_BATTERY);
   return data == 42;
}
