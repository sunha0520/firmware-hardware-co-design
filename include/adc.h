#ifndef _ADC_H_
#define _ADC_H_

#include "adc-target.h"

/* Functions that have INIT_ATTR attached are NOT guaranteed to survive after
 * root_menu() has been called. Their code may be overwritten by other data or
 * code in order to save RAM, and references to them might point into
 * zombie area.
 *
 * It is critical that you make sure these functions are only called before
 * the final call to root_menu() (see apps/main.c) is called (i.e. basically
 * only while main() runs), otherwise things may go wild,
 * from crashes to freezes to exploding daps.
 */
#define INIT_ATTR

/* channels are declared in adc-target.h */
unsigned short adc_read(int channel);
void adc_init(void) INIT_ATTR;

#endif /* _ADC_H_ */
