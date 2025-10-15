/*
    This file is part of the ChipWhisperer Example Targets
    Copyright (C) 2012-2017 NewAE Technology Inc.

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "hal.h"
#include "stm32f0xx_hal_gpio.h"
#include <stdint.h>
#include <stdlib.h>

/*
 * This code configures all GPIOs of the embedded target
 * as output and open drain, so that they behave as high
 * impedance.
 * Then when send it into an empty infinite loop.
 * Documentation: https://chipwhisperer.readthedocs.io/en/latest/Capture/ChipWhisperer-Nano.html#connecting-to-external-targets
 */
int main(void)
{
    platform_init();

    GPIO_InitTypeDef GpioInit;
	GpioInit.Pin       = GPIO_PIN_All;
	GpioInit.Mode      = GPIO_MODE_OUTPUT_OD;
	GpioInit.Pull      = GPIO_NOPULL;
	HAL_GPIO_Init(GPIOA, &GpioInit);


	while(1);
}
