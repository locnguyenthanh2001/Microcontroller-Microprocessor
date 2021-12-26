#include "main.h"
#include "input_processing.h"
#include "display_processing.h"
#include "input_reading.h"
#include "led_display.h"
#include "timer.h"


int RED_DEFAULT = 5;
int GREEN_DEFAULT = 3;
int AMBER_DEFAULT = 2;

enum States {Initial, RED_STATE, GREEN_STATE, AMBER_STATE};
enum States state = Initial;
int check_btn_1 = 0;
int check_btn_2 = 0;
int check_btn_3 = 0;
int value = 1;
int counter = 0;

void fsm_for_input_processing ( void )
{
	switch(state)
	{
	case Initial:
		fsm_for_traffic_display_processing();
		fsm_for_led_seg_display_processing(state);
		if(is_button_pressed(0) && check_btn_1 == 0)
		{
			check_btn_1++;
		}
		else if(is_button_pressed_1s(0) && check_btn_1 == 1){
			check_btn_1++;
		}
		else if((!is_button_pressed(0) && check_btn_1 == 1)||(!is_button_pressed(0) && check_btn_1 == 2))
		{
			state++;
			setTimer0(500);
			HAL_GPIO_TogglePin(GPIOA, LED_RED_1_Pin);
			HAL_GPIO_TogglePin(GPIOA, LED_RED_2_Pin);
			HAL_GPIO_WritePin(GPIOA, LED_AMBER_1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, LED_GREEN_1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, LED_AMBER_2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, LED_GREEN_2_Pin, GPIO_PIN_RESET);
			setTimer1(1000);
			check_btn_1 = 0;
		}
		break;
	case RED_STATE:
		if(counter == 10) {
			state = Initial;
			set_red_cycle(RED_DEFAULT);
			set_green_cycle(GREEN_DEFAULT);
			set_amber_cycle(AMBER_DEFAULT);
			set_up_display();
			value = 1;
			check_btn_1 = 0;
			check_btn_2 = 0;
			check_btn_3 = 0;
			counter = 0;
		}
		if(timer1_flag == 1){
			counter++;
			setTimer1(1000);
		}
		if(timer0_flag == 1){
			fsm_for_traffic_setting_processing(RED_STATE);
			setTimer0(500);
		}
		if(is_button_pressed(1) && check_btn_2 == 0)
		{
			check_btn_2++;
		}else if(is_button_pressed_1s(1) && check_btn_2 == 1){
			check_btn_2++;
		}else if((!is_button_pressed(1) && check_btn_2 == 1)||(!is_button_pressed(1) && check_btn_2 == 2)){
			value++;
			check_btn_2 = 0;
		}
		if(is_button_pressed(2) && check_btn_3 == 0)
		{
			check_btn_3++;
		}else if(is_button_pressed_1s(2) && check_btn_3 == 1){
			check_btn_2++;
		}else if((!is_button_pressed(2) && check_btn_3 == 1)||(!is_button_pressed(2) && check_btn_3 == 2)){
			set_red_cycle(value);
			value = 1;
			check_btn_3 = 0;
		}
		if(is_button_pressed(0) && check_btn_1 == 0){
			check_btn_1++;
		}else if(is_button_pressed_1s(0) && check_btn_1 == 1){
			check_btn_1++;
		}else if((!is_button_pressed(0) && check_btn_1 == 1)||(!is_button_pressed(0) && check_btn_1 == 2)){
			state++;
			counter = 0;
			setTimer1(1000);
			value = 1;
			check_btn_1 = 0;
		}
		updateClockBuffer(value, state+1);
		fsm_for_led_seg_display_processing(state);
		break;
	case GREEN_STATE:
		if(counter == 10) {
			state = Initial;
			set_red_cycle(RED_DEFAULT);
			set_green_cycle(GREEN_DEFAULT);
			set_amber_cycle(AMBER_DEFAULT);
			set_up_display();
			value = 1;
			check_btn_1 = 0;
			check_btn_2 = 0;
			check_btn_3 = 0;
			counter = 0;
		}
		if(timer1_flag == 1){
			counter++;
			setTimer1(1000);
		}
		if(timer0_flag == 1){
			fsm_for_traffic_setting_processing(GREEN_STATE);
			setTimer0(500);
		}
		if(is_button_pressed(1) && check_btn_2 == 0)
		{
			check_btn_2++;
		}else if(is_button_pressed_1s(1) && check_btn_2 == 1){
			check_btn_2++;
		}else if((!is_button_pressed(1) && check_btn_2 == 1)||(!is_button_pressed(1) && check_btn_2 == 2)){
			value++;
			check_btn_2 = 0;
		}
		if(is_button_pressed(2) && check_btn_3 == 0)
		{
			check_btn_3++;
		}else if(is_button_pressed_1s(2) && check_btn_3 == 1){
			check_btn_2++;
		}else if((!is_button_pressed(2) && check_btn_3 == 1)||(!is_button_pressed(2) && check_btn_3 == 2)){
			set_green_cycle(value);
			value = 1;
			check_btn_3 = 0;
		}
		if(is_button_pressed(0) && check_btn_1 == 0){
			check_btn_1++;
		}else if(is_button_pressed_1s(0) && check_btn_1 == 1){
			check_btn_1++;
		}else if((!is_button_pressed(0) && check_btn_1 == 1)||(!is_button_pressed(0) && check_btn_1 == 2)){
			state++;
			counter = 0;
			setTimer1(1000);
			value = 1;
			check_btn_1 = 0;
		}
		updateClockBuffer(value, state+1);
		fsm_for_led_seg_display_processing(state);
		break;
	case AMBER_STATE:
		if(counter == 10) {
			state = Initial;
			set_red_cycle(RED_DEFAULT);
			set_green_cycle(GREEN_DEFAULT);
			set_amber_cycle(AMBER_DEFAULT);
			set_up_display();
			value = 1;
			check_btn_1 = 0;
			check_btn_2 = 0;
			check_btn_3 = 0;
			counter = 0;
		}
		if(timer1_flag == 1){
			counter++;
			setTimer1(1000);
		}
		if(timer0_flag == 1){
			fsm_for_traffic_setting_processing(AMBER_STATE);
			setTimer0(500);
		}
		if(is_button_pressed(1) && check_btn_2 == 0)
		{
			check_btn_2++;
		}else if(is_button_pressed_1s(1) && check_btn_2 == 1){
			check_btn_2++;
		}else if((!is_button_pressed(1) && check_btn_2 == 1)||(!is_button_pressed(1) && check_btn_2 == 2)){
			value++;
			check_btn_2 = 0;
		}
		if(is_button_pressed(2) && check_btn_3 == 0)
		{
			check_btn_3++;
		}else if(is_button_pressed_1s(2) && check_btn_3 == 1){
			check_btn_2++;
		}else if((!is_button_pressed(2) && check_btn_3 == 1)||(!is_button_pressed(2) && check_btn_3 == 2)){
			set_amber_cycle(value);
			value = 1;
			check_btn_3 = 0;
		}
		if(is_button_pressed(0) && check_btn_1 == 0){
			check_btn_1++;
		}else if(is_button_pressed_1s(0) && check_btn_1 == 1){
			check_btn_1++;
		}else if((!is_button_pressed(0) && check_btn_1 == 1)||(!is_button_pressed(0) && check_btn_1 == 2)){
			state = Initial;
			check_btn_1 = 0;
			value = 1;
			set_up_display();
		}
		updateClockBuffer(value, state+1);
		fsm_for_led_seg_display_processing(state);
		break;
	}
}

