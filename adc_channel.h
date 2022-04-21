
#ifndef ADC_DRIVER_ADC_CHANNEL_H_
#define ADC_DRIVER_ADC_CHANNEL_H_

#include "adc_params.h"


class CADC_Channel
{
private:
	class CADC_SW_SequencerStep
	{
	private:
		enum state_t : uint8_t
		{
			unallocated,
			allocated,
			e_enabled,
			e_disabled
		};
		uint8_t _stepId;
		uint8_t _state;

	public:
		bool inline isAllocated()
		{
			return (_state != unallocated);
		}

		inline void setStepIdx(uint8_t idx)
		{
			_stepId = idx;
		}

		void enable();
		void program(CADC_ChannelConfig& param);
		void disable();
	};


	CADC_ChannelConfig _params;
	CADC_SW_SequencerStep _sequencerStep;
	uint8_t _channelId;
	uint8_t _ADCInstance;
	uint8_t _chIdx;



public:
	CADC_Channel();

	void allocate(uint8_t idx);

	void initialize(CADC_ChannelConfig& params);

	void startConversion();

	void stopConversion();

	void free();

};



#endif /* ADC_DRIVER_ADC_CHANNEL_H_ */
