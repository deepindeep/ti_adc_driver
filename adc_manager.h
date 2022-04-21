#ifndef ADC_DRIVER_ADC_MANAGER_H_
#define ADC_DRIVER_ADC_MANAGER_H_

#include "adc_channel.h"

class CADC_Manager
{
private:
#define MAX_NUM_ADC_CHANNELS (16)

	CADC_Channel _adcChannel[MAX_NUM_ADC_CHANNELS];

public:
	void CADC_Manager()
	{

	}

	CADC_Channel* getAdcChannel();

	int32_t releaseAdcChannel(CADC_Channel* ch);

};


#endif /* ADC_DRIVER_ADC_MANAGER_H_ */
