/*
 * adc_registers.h
 *
 *  Created on: 21-Apr-2022
 *      Author: benaka
 */

#ifndef ADC_DRIVER_ADC_REGISTERS_H_
#define ADC_DRIVER_ADC_REGISTERS_H_

#include <inttypes.h>

const uint32_t MCU_ADC0_BASE_ADDRESS = 0x40200000;
const uint32_t MCU_ADC1_BASE_ADDRESS = 0x40210000;

struct ADCConfigRegistersList_t
{
	uint32_t ADC_REVISION[4];

	uint32_t ADC_EOI;
	uint32_t ADC_STATUS_RAW;
	uint32_t ADC_STATUS;

	uint32_t ADC_ENABLE_CLR[2];
	uint32_t ADC_DMAENABLE_SET;
	uint32_t ADC_DMAENABLE_CLR;
	uint32_t ADC_CONTROL;

	uint32_t ADC_SEQUENCER_STAT;
	uint32_t ADC_RANGE[4];
	uint32_t ADC_MISC;
	uint32_t ADC_STEPENABLE;
	uint32_t reserved[3];

	struct
	{
		uint32_t A;
		uint32_t B;
	} ADC_STEPCONFIG[16];

	struct
	{
		uint32_t A;
		uint32_t B;
	} ADC_STEPDELAY[16];


	uint32_t ADC_FIFO0WC;
	uint32_t ADC_FIFO0THRESHOLD;
	uint32_t ADC_FIFO0DMAREQ;

	uint32_t ADC_FIFO1WC;
	uint32_t ADC_FIFO1THRESHOLD;
	uint32_t ADC_FIFO1DMAREQ;

	uint32_t ADC_FIFO0DATA[64];
	uint32_t ADC_FIFO1DATA[64];
};

#define DIFF_CNTRL_BIT (25)
#define SEL_INP_SWC    (22)
#define SEL_INM_SWM    (18)
#define AVERAGING      (4)
#define MODE		   (1)


extern ADCConfigRegistersList_t* ADC0_CONFIG_REGISTERS;
extern ADCConfigRegistersList_t* ADC1_CONFIG_REGISTERS;

#endif /* ADC_DRIVER_ADC_REGISTERS_H_ */
