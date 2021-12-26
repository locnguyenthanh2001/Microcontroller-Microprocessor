#include "main.h"
#include "display_processing.h"
#include "led_display.h"
#include "timer.h"

int RED_CYCLE = 5000;
int GREEN_CYCLE = 3000;
int AMBER_CYCLE = 2000;

int TIME_RATIO = 1000;
int TIME_CYCLE = 100;
int LED_CYCLE = 150;

enum TrafficState { RED_LED, AMBER_LED , GREEN_LED} ;
enum TrafficState firstTraffic = RED_LED ;
enum TrafficState secondTraffic = GREEN_LED;

enum LedMatrix { LED_1, LED_2, LED_3, LED_4};
enum LedMatrix LED_NO = LED_1;

void set_red_cycle(int value){
	RED_CYCLE = value * TIME_RATIO;
}
void set_amber_cycle(int value){
	AMBER_CYCLE = value * TIME_RATIO;
}
void set_green_cycle(int value){
	GREEN_CYCLE = value * TIME_RATIO;
}

void set_up_display(void){
	setTimer0(RED_CYCLE);
	setTimer1(GREEN_CYCLE);
	setTimerLedMatrix(LED_CYCLE);
	LED_NO = LED_1;
	firstTraffic = RED_LED ;
	secondTraffic = GREEN_LED;
}


void fsm_for_traffic_display_processing(void){
	switch (firstTraffic){
	case RED_LED:
		display_LED_TRAFFIC_FIRST_ROAD(1);
		if(timer0_flag == 1){
			firstTraffic = GREEN_LED;
			setTimer0(GREEN_CYCLE);
		}
		break ;
	case AMBER_LED:
		display_LED_TRAFFIC_FIRST_ROAD(2);
		if(timer0_flag == 1){
			firstTraffic = RED_LED;
			setTimer0(RED_CYCLE);
		}
		break ;
	case GREEN_LED:
		display_LED_TRAFFIC_FIRST_ROAD(3);
		if(timer0_flag == 1){
			firstTraffic = AMBER_LED;
			setTimer0(AMBER_CYCLE);
		}
		break ;
	}
	switch (secondTraffic){
	case RED_LED:
		display_LED_TRAFFIC_SECOND_ROAD(1);
		if(timer1_flag == 1){
			secondTraffic = GREEN_LED;
			setTimer1(GREEN_CYCLE);
		}
		break ;
	case AMBER_LED:
		display_LED_TRAFFIC_SECOND_ROAD(2);
		if(timer1_flag == 1){
			secondTraffic = RED_LED;
			setTimer1(RED_CYCLE);
		}
		break ;
	case GREEN_LED:
		display_LED_TRAFFIC_SECOND_ROAD(3);
		if(timer1_flag == 1){
			secondTraffic = AMBER_LED;
			setTimer1(AMBER_CYCLE);
		}
		break ;
	}
}
void fsm_for_led_seg_display_processing(int state){
	switch(LED_NO){
	case LED_1:
		update7SEG(1);
		if(timer_led_matrix_flag == 1){
			if(state == 0)updateClockBuffer(timer0_counter / TIME_CYCLE, timer1_counter / TIME_CYCLE);
			setTimerLedMatrix(LED_CYCLE);
			LED_NO = LED_2;
		}
		break;
	case LED_2:
		update7SEG(2);
		if(timer_led_matrix_flag == 1){
			if(state == 0)updateClockBuffer(timer0_counter / TIME_CYCLE, timer1_counter / TIME_CYCLE);
			setTimerLedMatrix(LED_CYCLE);
			LED_NO = LED_3;
		}
		break;
	case LED_3:
		update7SEG(3);
		if(timer_led_matrix_flag == 1){
			if(state == 0)updateClockBuffer(timer0_counter / TIME_CYCLE, timer1_counter / TIME_CYCLE);
			setTimerLedMatrix(LED_CYCLE);
			LED_NO = LED_4;
		}
		break;
	case LED_4:
		update7SEG(4);
		if(timer_led_matrix_flag == 1){
			if(state == 0)updateClockBuffer(timer0_counter / TIME_CYCLE, timer1_counter / TIME_CYCLE);
			setTimerLedMatrix(LED_CYCLE);
			LED_NO = LED_1;
		}
		break;
	}
}

void fsm_for_traffic_setting_processing(int state){
	switch(state){
	case 1:
		HAL_GPIO_TogglePin(GPIOA, LED_RED_1_Pin);
		HAL_GPIO_TogglePin(GPIOA, LED_RED_2_Pin);
		HAL_GPIO_WritePin(GPIOA, LED_AMBER_1_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOA, LED_GREEN_1_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, LED_AMBER_2_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, LED_GREEN_2_Pin, GPIO_PIN_RESET);
		break;
	case 2:
		HAL_GPIO_TogglePin(GPIOA, LED_GREEN_1_Pin);
		HAL_GPIO_TogglePin(GPIOB, LED_GREEN_2_Pin);
		HAL_GPIO_WritePin(GPIOA, LED_RED_1_Pin , GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOA, LED_AMBER_1_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOA, LED_RED_2_Pin , GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, LED_AMBER_2_Pin, GPIO_PIN_RESET);
		break;
	case 3:
		HAL_GPIO_TogglePin(GPIOA, LED_AMBER_1_Pin);
		HAL_GPIO_TogglePin(GPIOB, LED_AMBER_2_Pin);
		HAL_GPIO_WritePin(GPIOA, LED_RED_1_Pin , GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOA, LED_GREEN_1_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOA, LED_RED_2_Pin , GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, LED_GREEN_2_Pin, GPIO_PIN_RESET);
		break;
	}
}

