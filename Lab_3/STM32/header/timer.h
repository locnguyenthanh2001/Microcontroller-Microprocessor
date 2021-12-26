/*
 * timer.h
 *
 *  Created on: Oct 8, 2021
 *      Author: ADMIN
 */

#ifndef INC_TIMER_H_
#define INC_TIMER_H_

extern int timer0_flag;
extern int timer0_counter;

extern int timer1_flag;
extern int timer1_counter;

extern int timer_led_matrix_flag;



void setTimer1(int duration);
void setTimer0 (int duration);
void setTimerLedMatrix(int duration);
void timer_run();
void HAL_TIM_PeriodElapsedCallback (TIM_HandleTypeDef * htim);



#endif /* INC_TIMER_H_ */
