/*
 * SCH.h
 *
 *  Created on: Nov 16, 2021
 *      Author: ADMIN
 */

#ifndef INC_SCH_H_
#define INC_SCH_H_
#include "main.h"
#include "TaskStructure.h"
#include "timer.h"

// MUST BE ADJUSTED FOR EACH NEW PROJECT
#define SCH_MAX_TASKS 40
#define NO_TASK_ID 0
sTask SCH_tasks_G[SCH_MAX_TASKS] ;
static int size = 0;

void SCH_Init(void);
int SCH_Add_Task( void (* pFunction)() , unsigned int DELAY, unsigned int PERIOD);
void SCH_Dispatch_Tasks(void);
void SCH_Delete_Task(const uint32_t TASK_INDEX);
void SCH_Update( void );





#endif /* INC_SCH_H_ */
