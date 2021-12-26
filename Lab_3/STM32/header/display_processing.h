/*
 * display_processing.h
 *
 *  Created on: Oct 9, 2021
 *      Author: ADMIN
 */

#ifndef INC_DISPLAY_PROCESSING_H_
#define INC_DISPLAY_PROCESSING_H_

void set_up_display(void);

void fsm_for_traffic_display_processing(void);
void fsm_for_led_seg_display_processing(int state);
void fsm_for_traffic_setting_processing(int state);

void set_red_cycle(int value);
void set_amber_cycle(int value);
void set_green_cycle(int value);


#endif /* INC_DISPLAY_PROCESSING_H_ */
