
#ifndef ADC_DRIVER_ADC_DRIVER_H_
#define ADC_DRIVER_ADC_DRIVER_H_

#include "adc_registers.h"
#include "adc_params.h"

class CADC_Driver
{
private:
	const ADCConfigRegistersList_t* ADC_CONFIG_REGISTERS;
	int32_t enableAdc();
	int32_t disable();

public:
	CADC_Driver(uint32_t baseAddress) :
		ADC_CONFIG_REGISTERS(baseAddress)
	{

	}


	int32_t initialize(const uint32_t chNum, const CADC_ChannelConfig& params);

	int32_t startAcq(const uint32_t chNum);

	int32_t stopAcq(const uint32_t chNum);
};




extern CADC_Driver ADC0_Driver(MCU_ADC0_BASE_ADDRESS);
extern CADC_Driver ADC1_Driver(MCU_ADC1_BASE_ADDRESS);

extern CADC_Driver& ADCDriver[2];

#endif /* ADC_DRIVER_ADC_DRIVER_H_ */
