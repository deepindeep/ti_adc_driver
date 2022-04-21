#ifndef ADC_DRIVER_ADC_PARAMS_H_
#define ADC_DRIVER_ADC_PARAMS_H_

#include "inttypes.h"
#define INVALID_PIN (-1)

enum inputType_t : uint8_t
{
	e_inputType_single,
	e_inputType_differential,
	e_inputType_invalid
};

enum conversionMode_t : uint8_t
{
	e_conversionMode_single,
	e_conversionMode_Continous,
	e_conversionMode_invalid
};

enum sampleAverageNum_t : uint8_t
{
	e_sampleAvg_noAvg,
	e_sampleAvg_2,
	e_sampleAvg_4,
	e_sampleAvg_8,
	e_sampleAvg_16,
};




class CADC_ChannelConfig
{
public:
	uint32_t 	_inputPosPin;
	uint32_t 	_inputNegPin;
	inputType_t _inputType;
	sampleAverageNum_t 	_sampleAvgNum;
	uint32_t   _samplingRateInTicks;

};

#endif /* ADC_DRIVER_ADC_PARAMS_H_ */
