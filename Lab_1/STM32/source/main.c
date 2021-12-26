/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
/////////////////////////////////////////////////////////////
//                 This is answer for question 10          //
/////////////////////////////////////////////////////////////
/*void clearAllClock(){
	HAL_GPIO_WritePin(GPIOA, LED1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA, LED2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA, LED3_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA, LED4_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA, LED5_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA, LED6_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA, LED7_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA, LED8_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA, LED9_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA, LED10_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA, LED11_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA, LED12_Pin, GPIO_PIN_SET);
}

void setNumberOnClock(int num){
	if(num == 1)HAL_GPIO_WritePin(GPIOA, LED1_Pin, GPIO_PIN_RESET);
	if(num == 2)HAL_GPIO_WritePin(GPIOA, LED2_Pin, GPIO_PIN_RESET);
	if(num == 3)HAL_GPIO_WritePin(GPIOA, LED3_Pin, GPIO_PIN_RESET);
	if(num == 4)HAL_GPIO_WritePin(GPIOA, LED4_Pin, GPIO_PIN_RESET);
	if(num == 5)HAL_GPIO_WritePin(GPIOA, LED5_Pin, GPIO_PIN_RESET);
	if(num == 6)HAL_GPIO_WritePin(GPIOA, LED6_Pin, GPIO_PIN_RESET);
	if(num == 7)HAL_GPIO_WritePin(GPIOA, LED7_Pin, GPIO_PIN_RESET);
	if(num == 8)HAL_GPIO_WritePin(GPIOA, LED8_Pin, GPIO_PIN_RESET);
	if(num == 9)HAL_GPIO_WritePin(GPIOA, LED9_Pin, GPIO_PIN_RESET);
	if(num == 10)HAL_GPIO_WritePin(GPIOA, LED10_Pin, GPIO_PIN_RESET);
	if(num == 11)HAL_GPIO_WritePin(GPIOA, LED11_Pin, GPIO_PIN_RESET);
	if(num == 0)HAL_GPIO_WritePin(GPIOA, LED12_Pin, GPIO_PIN_RESET);
}

void clearNumberOnClock(int num){
	if(num == 1)HAL_GPIO_WritePin(GPIOA, LED1_Pin, GPIO_PIN_SET);
	if(num == 2)HAL_GPIO_WritePin(GPIOA, LED2_Pin, GPIO_PIN_SET);
	if(num == 3)HAL_GPIO_WritePin(GPIOA, LED3_Pin, GPIO_PIN_SET);
	if(num == 4)HAL_GPIO_WritePin(GPIOA, LED4_Pin, GPIO_PIN_SET);
	if(num == 5)HAL_GPIO_WritePin(GPIOA, LED5_Pin, GPIO_PIN_SET);
	if(num == 6)HAL_GPIO_WritePin(GPIOA, LED6_Pin, GPIO_PIN_SET);
	if(num == 7)HAL_GPIO_WritePin(GPIOA, LED7_Pin, GPIO_PIN_SET);
	if(num == 8)HAL_GPIO_WritePin(GPIOA, LED8_Pin, GPIO_PIN_SET);
	if(num == 9)HAL_GPIO_WritePin(GPIOA, LED9_Pin, GPIO_PIN_SET);
	if(num == 10)HAL_GPIO_WritePin(GPIOA, LED10_Pin, GPIO_PIN_SET);
	if(num == 11)HAL_GPIO_WritePin(GPIOA, LED11_Pin, GPIO_PIN_SET);
	if(num == 0)HAL_GPIO_WritePin(GPIOA, LED12_Pin, GPIO_PIN_SET);
}


int main(void)
{
  HAL_Init();
  SystemClock_Config();
  MX_GPIO_Init();
  int hour = 0;
  int minute = 0;
  int second = 0;
  while (1)
  {
	  if(second < 600)second++;
	  if(second == 600){
		  minute++;
		  second = 0;
	  }
	  if(minute == 60){
		  hour++;
		  if(hour == 12) hour = 0;
	  }
	  if(minute == 60)minute = 0;
	  clearAllClock();
	  setNumberOnClock(hour);
	  setNumberOnClock(minute / 5);
	  setNumberOnClock(second / 50);
	  HAL_Delay(10);
  }
}*/


/////////////////////////////////////////////////////////////////////////
//        This is answer for question 9 and previous questions         //
/////////////////////////////////////////////////////////////////////////



void display7SEG_A(int num){
	if(num == 0){
		HAL_GPIO_WritePin(GPIOB, a_Pin|b_Pin|c_Pin|f_Pin|e_Pin|d_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, g_Pin, GPIO_PIN_SET);
	}else if(num == 1){
		HAL_GPIO_WritePin(GPIOB, b_Pin|c_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, a_Pin|g_Pin|f_Pin|e_Pin|d_Pin, GPIO_PIN_SET);
	}else if(num == 2){
		HAL_GPIO_WritePin(GPIOB, a_Pin|b_Pin|g_Pin|e_Pin|d_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, c_Pin|f_Pin, GPIO_PIN_SET);
	}else if(num == 3){
		HAL_GPIO_WritePin(GPIOB, a_Pin|b_Pin|c_Pin|g_Pin|d_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, f_Pin|e_Pin, GPIO_PIN_SET);
	}else if(num == 4){
		HAL_GPIO_WritePin(GPIOB, b_Pin|c_Pin|g_Pin|f_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, a_Pin|e_Pin|d_Pin, GPIO_PIN_SET);
	}else if(num == 5){
		HAL_GPIO_WritePin(GPIOB, a_Pin|c_Pin|g_Pin|f_Pin|d_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, b_Pin|e_Pin, GPIO_PIN_SET);
	}else if(num == 6){
		HAL_GPIO_WritePin(GPIOB, a_Pin|c_Pin|g_Pin|f_Pin|e_Pin|d_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, b_Pin, GPIO_PIN_SET);
	}else if(num == 7){
		HAL_GPIO_WritePin(GPIOB, a_Pin|b_Pin|c_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, g_Pin|f_Pin|e_Pin|d_Pin, GPIO_PIN_SET);
	}else if(num == 8){
		HAL_GPIO_WritePin(GPIOB, a_Pin|b_Pin|c_Pin|g_Pin|f_Pin|e_Pin|d_Pin, GPIO_PIN_RESET);

	}else if(num == 9){
		HAL_GPIO_WritePin(GPIOB, a_Pin|b_Pin|c_Pin|g_Pin|f_Pin|d_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, e_Pin, GPIO_PIN_SET);
	}
}
void display7SEG_B(int num){
	if(num == 0){
		HAL_GPIO_WritePin(GPIOB, A_Pin|B_Pin|C_Pin|F_Pin|E_Pin|D_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, G_Pin, GPIO_PIN_SET);
	}else if(num == 1){
		HAL_GPIO_WritePin(GPIOB, B_Pin|C_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, A_Pin|G_Pin|F_Pin|E_Pin|D_Pin, GPIO_PIN_SET);
	}else if(num == 2){
		HAL_GPIO_WritePin(GPIOB, A_Pin|B_Pin|G_Pin|E_Pin|D_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, C_Pin|F_Pin, GPIO_PIN_SET);
	}else if(num == 3){
		HAL_GPIO_WritePin(GPIOB, A_Pin|B_Pin|C_Pin|G_Pin|D_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, F_Pin|E_Pin, GPIO_PIN_SET);
	}else if(num == 4){
		HAL_GPIO_WritePin(GPIOB, B_Pin|C_Pin|G_Pin|F_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, A_Pin|E_Pin|D_Pin, GPIO_PIN_SET);
	}else if(num == 5){
		HAL_GPIO_WritePin(GPIOB, A_Pin|C_Pin|G_Pin|F_Pin|D_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, B_Pin|E_Pin, GPIO_PIN_SET);
	}else if(num == 6){
		HAL_GPIO_WritePin(GPIOB, A_Pin|C_Pin|G_Pin|F_Pin|E_Pin|D_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, B_Pin, GPIO_PIN_SET);
	}else if(num == 7){
		HAL_GPIO_WritePin(GPIOB, A_Pin|B_Pin|C_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, G_Pin|F_Pin|E_Pin|D_Pin, GPIO_PIN_SET);
	}else if(num == 8){
		HAL_GPIO_WritePin(GPIOB, A_Pin|B_Pin|C_Pin|G_Pin|F_Pin|E_Pin|D_Pin, GPIO_PIN_RESET);

	}else if(num == 9){
		HAL_GPIO_WritePin(GPIOB, A_Pin|B_Pin|C_Pin|G_Pin|F_Pin|D_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, E_Pin, GPIO_PIN_SET);
	}
}
#define RED 0
#define GREEN 1
#define YELLOW 2

int main(void)
{
  HAL_Init();
  SystemClock_Config();
  MX_GPIO_Init();
  int count_1 = 500;
  int count_2 = 300;
  int light_1 = RED;
  int light_2 = GREEN;
  while (1)
     {
   	  if(light_1 == RED){
   		 HAL_GPIO_WritePin(GPIOA, LED_RED_Pin, GPIO_PIN_RESET);
   		 HAL_GPIO_WritePin(GPIOA, LED_YELLOW_Pin, GPIO_PIN_SET);
   		 HAL_GPIO_WritePin(GPIOA, LED_GREEN_Pin, GPIO_PIN_SET);
   		 if(count_1 > 0) count_1--;
   		 else{
   			count_1 = 300;
   			light_1 = GREEN;
   		 }
   	  }else if(light_1 == YELLOW){
   		 HAL_GPIO_WritePin(GPIOA, LED_RED_Pin, GPIO_PIN_SET);
   		 HAL_GPIO_WritePin(GPIOA, LED_YELLOW_Pin, GPIO_PIN_RESET);
   		 HAL_GPIO_WritePin(GPIOA, LED_GREEN_Pin, GPIO_PIN_SET);
   		 if(count_1 > 0) count_1--;
   		  else{
   			  count_1 = 500;
   			  light_1 = RED;
   		  }
   	  }else if(light_1 == GREEN){
   		 HAL_GPIO_WritePin(GPIOA, LED_RED_Pin, GPIO_PIN_SET);
   		 HAL_GPIO_WritePin(GPIOA, LED_YELLOW_Pin, GPIO_PIN_SET);
   		 HAL_GPIO_WritePin(GPIOA, LED_GREEN_Pin, GPIO_PIN_RESET);
   		 if(count_1 > 0) count_1--;
   		 else{
   			 count_1 = 200;
   			 light_1 = YELLOW;
   		 }
   	  }
   	  if(light_2 == RED){
   	  		 HAL_GPIO_WritePin(GPIOA, RED_Pin, GPIO_PIN_RESET);
   	  		 HAL_GPIO_WritePin(GPIOA, YELLOW_Pin, GPIO_PIN_SET);
   	  		 HAL_GPIO_WritePin(GPIOA, GREEN_Pin, GPIO_PIN_SET);
   	  		 if(count_2 > 0) count_2--;
   	  		 else{
   	  			 count_2 = 300;
   	  			 light_2 = GREEN;
   	  		 }
   	  	  }else if(light_2 == YELLOW){
   	  		 HAL_GPIO_WritePin(GPIOA, RED_Pin, GPIO_PIN_SET);
   	  		 HAL_GPIO_WritePin(GPIOA, YELLOW_Pin, GPIO_PIN_RESET);
   	  		 HAL_GPIO_WritePin(GPIOA, GREEN_Pin, GPIO_PIN_SET);
   	  		 if(count_2 > 0) count_2--;
   	  		  else{
   	  			  count_2 = 500;
   	  			  light_2 = RED;
   	  		  }
   	  	  }else if(light_2 == GREEN){
   	  		 HAL_GPIO_WritePin(GPIOA, RED_Pin, GPIO_PIN_SET);
   	  		 HAL_GPIO_WritePin(GPIOA, YELLOW_Pin, GPIO_PIN_SET);
   	  		 HAL_GPIO_WritePin(GPIOA, GREEN_Pin, GPIO_PIN_RESET);
   	  		 if(count_2 > 0) count_2--;
   	  		 else{
   	  			 count_2 = 200;
   	  			 light_2 = YELLOW;
   	  		 }
   	  	  }
   	display7SEG_A((int)(count_1 / 100));
   	display7SEG_B((int)(count_2 / 100));
   	HAL_Delay(10);
     }
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, LED_RED_Pin|LED_GREEN_Pin|LED_YELLOW_Pin|RED_Pin
                          |GREEN_Pin|YELLOW_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, a_Pin|b_Pin|c_Pin|D_Pin
                          |E_Pin|F_Pin|G_Pin|A_Pin
                          |d_Pin|e_Pin|f_Pin|g_Pin
                          |B_Pin|C_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : LED_RED_Pin LED_GREEN_Pin LED_YELLOW_Pin RED_Pin
                           GREEN_Pin YELLOW_Pin */
  GPIO_InitStruct.Pin = LED_RED_Pin|LED_GREEN_Pin|LED_YELLOW_Pin|RED_Pin
                          |GREEN_Pin|YELLOW_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : a_Pin b_Pin c_Pin D_Pin
                           E_Pin F_Pin G_Pin A_Pin
                           d_Pin e_Pin f_Pin g_Pin
                           B_Pin C_Pin */
  GPIO_InitStruct.Pin = a_Pin|b_Pin|c_Pin|D_Pin
                          |E_Pin|F_Pin|G_Pin|A_Pin
                          |d_Pin|e_Pin|f_Pin|g_Pin
                          |B_Pin|C_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
