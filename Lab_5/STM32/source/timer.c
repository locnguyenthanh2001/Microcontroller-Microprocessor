#include"timer.h"

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
	SCH_Update();
}

