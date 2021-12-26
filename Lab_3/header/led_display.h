/*
 * led_display.h
 *
 *  Created on: Oct 5, 2021
 *      Author: ADMIN
 */

#ifndef INC_LED_DISPLAY_H_
#define INC_LED_DISPLAY_H_

#define MAX_LED 4

int led_buffer[MAX_LED];

void updateClockBuffer(int first_road, int second_road);
void display7SEG(int num);
void update7SEG(int index);


void display_LED_TRAFFIC_SECOND_ROAD(int LED_NO);
void display_LED_TRAFFIC_FIRST_ROAD(int LED_NO);



#endif /* INC_LED_DISPLAY_H_ */
