#include "config.h"
#include "adc.h"
#include "adc-target.h"
//#include "powermgmt.h"

const unsigned short battery_level_dangerous[BATTERY_TYPES_COUNT] =
{
    3540
};

const unsigned short battery_level_shutoff[BATTERY_TYPES_COUNT] =
{
    3500
};

/* voltages (millivolt) of 0%, 10%, ... 100% when charging disabled */
const unsigned short percent_to_volt_discharge[BATTERY_TYPES_COUNT][11] =
{
    /* average measured values from X5 and M5L */
    { 3500, 3650, 3720, 3740, 3760, 3790, 3840, 3900, 3950, 4040, 4120 }
};

/* voltages (millivolt) of 0%, 10%, ... 100% when charging enabled */
const unsigned short percent_to_volt_charge[11] =
{
    /* TODO: This is identical to the discharge curve.
     * Calibrate charging curve using a battery_bench log. */
    3500, 3650, 3720, 3740, 3760, 3790, 3840, 3900, 3950, 4040, 4120
};

#define BATTERY_SCALE_FACTOR  6000
/* full-scale ADC readout (2^10) in millivolt */

/* Returns battery voltage from ADC [millivolts] */
int _battery_voltage(void)
{
    return (adc_read(ADC_BATTERY) * BATTERY_SCALE_FACTOR) >> 10;
}
