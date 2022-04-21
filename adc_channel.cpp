
#include "adc_channel.h"
#include "adc_driver.h"

CADC_Channel::CADC_Channel()
{

}


void CADC_Channel::allocate(uint8_t idx)
{
	_channelId = idx;
	_chIdx		 = (idx & 0x0F);
	_ADCInstance = (idx >> 8) & 0xFF;
}

void CADC_Channel::free()
{
	stopConversion();
	_channelId = 0xFF;
}

void CADC_Channel::initialize(CADC_ChannelConfig& params)
{
	_params = params;

	ADCDriver[_ADCInstance].initialize(_chIdx, params);
}


void CADC_Channel::startConversion()
{
	ADCDriver[_ADCInstance].startAcq(_chIdx);
	// enable
}

void CADC_Channel::stopConversion()
{
	ADCDriver[_ADCInstance].stop(_chIdx);
}
