#include "adc_driver.h"

CADC_Driver ADC0_Driver(MCU_ADC0_BASE_ADDRESS);
CADC_Driver ADC1_Driver(MCU_ADC1_BASE_ADDRESS);


CADC_Driver ADCDriver[2] = {ADC0_Driver, ADC1_Driver};


int32_t CADC_Driver::initialize(const uint32_t chNum, const CADC_ChannelConfig& params)
{
	stopAcq(chNum);
	if (params._inputType == e_conversionMode_Continous)
	{
		ADC_CONFIG_REGISTERS->ADC_STEPCONFIG[chNum] |= (1 << MODE);
	}

	ADC_CONFIG_REGISTERS->ADC_STEPCONFIG[chNum] |= ((params._sampleAvgNum) << AVERAGING);
	ADC_CONFIG_REGISTERS->ADC_STEPCONFIG[chNum] |= ((chNum & 0xF) << SEL_INP_SWC);

	if (params._inputNegPin == INVALID_PIN)
	{
		ADC_CONFIG_REGISTERS->ADC_STEPCONFIG[chNum] &= ~(1 << DIFF_CNTRL_BIT);
	}
	else
	{
		ADC_CONFIG_REGISTERS->ADC_STEPCONFIG[chNum] |= ((chNum & 0xF) << SEL_INM_SWM);
	}

}

int32_t CADC_Driver::startAcq(const uint32_t chNum)
{
	ADC_CONFIG_REGISTERS->ADC_STEPENABLE |= (1 << chNum);
	enableADC();
	return 0;
}

int32_t CADC_Driver::enableAdc()
{
	ADC_CONFIG_REGISTERS->ADC_ENABLE_CLR |= (0x01);
	return 0;
}

int32_t CADC_Driver::disable()
{
	ADC_CONFIG_REGISTERS->ADC_ENABLE_CLR &= ~(0x01);
	return 0;
}
int32_t CADC_Driver::stopAcq(const uint32_t chNum)
{
	ADC_CONFIG_REGISTERS->ADC_STEPENABLE &= ~(1 << chNum); // disable it for now

	return 0;
}
