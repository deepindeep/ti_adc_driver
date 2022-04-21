#include "adc_manager.h"
#include "adc_channel.h"

CADC_Channel* CADC_Manager::getAdcChannel()
{
	for (int32_t i = 0; i < MAX_NUM_ADC_CHANNELS; i++)
	{
		if (!_adcChannel[i].isAllocated())
		{
			_adcChannel.allocate(i);
			return &_adcChannel[i];
		}
	}
	return NULL;
}


int32_t CADC_Manager::releaseAdcChannel(CADC_Channel* ch)
{
	ch->free();
	return 0;
}


