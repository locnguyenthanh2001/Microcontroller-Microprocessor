#include "main.h"
#include "led_display.h"


int led_buffer[MAX_LED] = { 0, 0, 0, 0};

void updateClockBuffer(int first_road, int second_road){
	led_buffer[0] = first_road / 10;
	led_buffer[1] = first_road % 10;
	led_buffer[2] = second_road /10;
	led_buffer[3] = second_road % 10;
}

void display7SEG(int num){
	char led7seg[10] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};
	for (int i = 0; i < 7; i++){
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0 << i, (led7seg[num] >> i) & 1);
	}
}

void update7SEG ( int index ) {
	switch ( index ) {
	case 1:
		// Display the first 7 SEG with led_buffer [0]
		HAL_GPIO_WritePin(GPIOA, EN0_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOA, EN1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOA, EN2_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOA, EN3_Pin, GPIO_PIN_SET);
		display7SEG(led_buffer[0]);
		break ;
	case 2:
		// Display the third 7 SEG with led_buffer [2]
		HAL_GPIO_WritePin(GPIOA, EN0_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOA, EN1_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOA, EN2_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOA, EN3_Pin, GPIO_PIN_SET);
		display7SEG(led_buffer[1]);
		break ;
	case 3:
		// Display the forth 7 SEG with led_buffer [3]
		HAL_GPIO_WritePin(GPIOA, EN0_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOA, EN1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOA, EN2_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOA, EN3_Pin, GPIO_PIN_SET);
		display7SEG(led_buffer[2]);
		break ;
	case 4:
		HAL_GPIO_WritePin(GPIOA, EN0_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOA, EN1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOA, EN2_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOA, EN3_Pin, GPIO_PIN_RESET);
		display7SEG(led_buffer[3]);
		break ;
	default:
		break;
	}
}




void display_LED_TRAFFIC_FIRST_ROAD(int LED_NO){
	switch(LED_NO){
	case 1:
		HAL_GPIO_WritePin(GPIOA, LED_RED_1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOA, LED_AMBER_1_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOA, LED_GREEN_1_Pin, GPIO_PIN_RESET);
		break;
	case 2:
		HAL_GPIO_WritePin(GPIOA, LED_RED_1_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOA, LED_AMBER_1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOA, LED_GREEN_1_Pin, GPIO_PIN_RESET);
		break;
	case 3:
		HAL_GPIO_WritePin(GPIOA, LED_RED_1_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOA, LED_AMBER_1_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOA, LED_GREEN_1_Pin, GPIO_PIN_SET);
		break;
	}
}

void display_LED_TRAFFIC_SECOND_ROAD(int LED_NO){
	switch(LED_NO){
	case 1:
		HAL_GPIO_WritePin(GPIOA, LED_RED_2_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOB, LED_AMBER_2_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, LED_GREEN_2_Pin, GPIO_PIN_RESET);
		break;
	case 2:
		HAL_GPIO_WritePin(GPIOA, LED_RED_2_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, LED_AMBER_2_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOB, LED_GREEN_2_Pin, GPIO_PIN_RESET);
		break;
	case 3:
		HAL_GPIO_WritePin(GPIOA, LED_RED_2_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, LED_AMBER_2_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, LED_GREEN_2_Pin, GPIO_PIN_SET);
		break;
	}
}
