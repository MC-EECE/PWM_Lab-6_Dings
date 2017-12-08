/*************************************************************************
 * Copyright (c) 2009 Altera Corporation, San Jose, California, USA.      *
 * All rights reserved. All use of this software and documentation is     *
 * subject to the License Agreement located at the end of this file below.*
 *************************************************************************/

#include "my_awesome_pwm.h"
#include "system.h"

 int main(void)
 {
    alt_u32 period, pulse_width;
    alt_u8 enable = 0;
    IOWR(PWM_0_BASE, PWM_ENABLE, enable);
    IOWR(PWM_1_BASE, PWM_ENABLE, enable);
    IOWR(PWM_2_BASE, PWM_ENABLE, enable);
    while(1)
    {
    	// read from switches to determine pulse width
    	enable = (IORD(SLIDER_SWITCHES_BASE, 0)&0x20000)?1:0;
    	pulse_width = IORD(SLIDER_SWITCHES_BASE,0)&0xFF;

    	// set the pwm period
    	period = (IORD(SLIDER_SWITCHES_BASE,0)&0xFF00) >> 8;

    	// output the period to the pwm
    	// output the pulse width value to the pwm
    	alt_u32 test_period = IORD(PWM_0_BASE, PWM_PERIOD);
 
    	IOWR(PWM_0_BASE, PWM_PERIOD, period);
    	IOWR(PWM_0_BASE, PWM_PULSE_WIDTH, pulse_width);

    	alt_u32 test_pw = IORD(PWM_0_BASE, PWM_PULSE_WIDTH);
    	if ((test_pw == pulse_width) && (test_period == period))
    	{
    	  IOWR(PWM_0_BASE, PWM_ENABLE, enable);
    	}
    }
    	  while(1) {
    	       	// read from switches to determine pulse width
    	       	enable = (IORD(SLIDER_SWITCHES_BASE, 0)&0x20000)?1:0;
    	       	pulse_width = IORD(SLIDER_SWITCHES_BASE,0)&0xFF;
    	       	// set the pwm period
    	       	period = (IORD(SLIDER_SWITCHES_BASE,0)&0xFF00) >> 8;

    	       	// output the period to the pwm
    	       	// output the pulse width value to the pwm
    	       	 alt_u32 test_period = IORD(PWM_1_BASE, PWM_PERIOD);

    	           IOWR(PWM_1_BASE, PWM_PERIOD, period);
    	           IOWR(PWM_1_BASE, PWM_PULSE_WIDTH, pulse_width);

    	          alt_u32 test_pw = IORD(PWM_1_BASE, PWM_PULSE_WIDTH);
    	            if ((test_pw == pulse_width) && (test_period == period))
    	            {
    	            IOWR(PWM_1_BASE, PWM_ENABLE, enable);
    	          }
    	      }

    	      while(1) {
    	         // read from switches to determine pulse width
    	         enable = (IORD(SLIDER_SWITCHES_BASE, 0)&0x20000)?1:0;
    	         pulse_width = IORD(SLIDER_SWITCHES_BASE,0)&0xFF;
    	         // set the pwm period
    	         period = (IORD(SLIDER_SWITCHES_BASE,0)&0xFF00) >> 8;

    	         // output the period to the pwm
    	         // output the pulse width value to the pwm
    	         alt_u32 test_period = IORD(PWM_2_BASE, PWM_PERIOD);

    	         IOWR(PWM_2_BASE, PWM_PERIOD, period);
    	         IOWR(PWM_2_BASE, PWM_PULSE_WIDTH, pulse_width);

    	         alt_u32 test_pw = IORD(PWM_2_BASE, PWM_PULSE_WIDTH);
    	         if ((test_pw == pulse_width) && (test_period == period))
    	         {
    	           IOWR(PWM_2_BASE, PWM_ENABLE, enable);
    	         }
}
return 0;
}


/******************************************************************************
 *                                                                             *
 * License Agreement                                                           *
 *                                                                             *
 * Copyright (c) 2006 Altera Corporation,Bronx, NY, USA.           			   *
 * All rights reserved.                                                        *
 *                                                                             *
 * Permission is hereby granted, free of charge, to any person obtaining a     *
 * copy of this software and associated documentation files (the "Software"),  *
 * to deal in the Software without restriction, including without limitation   *
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,    *
 * and/or sell copies of the Software, and to permit persons to whom the       *
 * Software is furnished to do so, subject to the following conditions:        *
 *                                                                             *
 * The above copyright notice and this permission notice shall be included in  *
 * all copies or substantial portions of the Software.                         *
 *                                                                             *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  *
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,    *
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE *
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER      *
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING     *
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER         *
 * DEALINGS IN THE SOFTWARE.                                                   *
 *                                                                             *
 * This agreement shall be governed in all respects by the laws of the State   *
 * of California and by the laws of the United States of America.              *
 * Altera does not recommend, suggest or require that this reference design    *
 * file be used in conjunction or combination with any other product.          *
 ******************************************************************************/
