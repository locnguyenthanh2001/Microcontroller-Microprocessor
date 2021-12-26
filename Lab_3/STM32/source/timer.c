#include "main.h"
#include "timer.h"
#include "input_reading.h"


int timer0_counter = 0;
int timer0_flag = 0;

int timer1_counter = 0;
int timer1_flag = 0;

int timer_led_matrix_flag = 0;
int timer_led_matrix_counter = 0;

int TIMER_CYCLE = 10;

void setTimer0(int duration) {
	timer0_counter = duration / TIMER_CYCLE;
	timer0_flag = 0;
}

void setTimer1(int duration){
	timer1_counter = duration / TIMER_CYCLE;
	timer1_flag = 0;
}

void setTimerLedMatrix(int duration){
	timer_led_matrix_flag = 0;
	timer_led_matrix_counter = duration / TIMER_CYCLE;
}

void timer_run(){
	if(timer0_counter > 0) {
		timer0_counter--;
		if(timer0_counter == 0) timer0_flag = 1;
	}
	if(timer1_counter > 0) {
		timer1_counter--;
		if(timer1_counter == 0) timer1_flag = 1;
	}
	if(timer_led_matrix_counter > 0) {
		timer_led_matrix_counter--;
			if(timer_led_matrix_counter == 0) timer_led_matrix_flag = 1;
		}

}

void HAL_TIM_PeriodElapsedCallback( TIM_HandleTypeDef * htim )
{
	if(htim->Instance == TIM2){
		timer_run();
		button_reading();
	}
}
