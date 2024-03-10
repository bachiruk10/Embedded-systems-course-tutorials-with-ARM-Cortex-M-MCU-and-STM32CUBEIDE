/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */

	/***************************** Tutorial Tags ******************************
		 FreeRTOS
		 Memory pool
		 Queue
		 Timer interrupts
		 Tasks
		 GPIO output
	 **************************************************************************/

	/* 10.6 Queue and Mail in FreeRTOS: **************************************
	 * Tutorial -10-22: The second memory pool example in FreeRTOS

    WARNING: Code written mostly without help of CubeMX. If you regenerate code using CubeMX
	you will lose the code here.

    In this tutorial, we show how memory pool and
	queue can be used with interrupts and multiple tasks. To do so, we use the same
	structure introduced in the previous example. Now, we create a queue with size
	two. Data in the queue slots have the size of the constructed structure. The memory
	pool is initialized at the beginning of the function StartDefaultTask with ten
	elements and data size of the constructed structure. We configure the timer modules
	Timer 2 and Timer 3 to trigger interrupts every 1 s and 2 s, respectively. Both timers
	have their own counter and put data containing the counter value and timer id to
	the queue whenever related interrupt is triggered. At the same time, the default task
	waits until data is put to the queue. It then prints the counter value and id of the
	timer which holds this counter value. As in Tutorial 10.20, we do not want to miss
	any printing. However, priorities of timer interrupts are always higher than priority
	of a task. Hence, we create two more tasks named myTask02 and myTask03 with
	priorities lower than the default task. We associate them with Timer 2 and Timer 3
	respectively using an event. Therefore, whenever a timer interrupt is triggered, the
	related task is called. Then, the memory block is allocated from the memory pool.
	The counter value is written to the first element of the buffer array and the id is
	set according to the timer interrupt source. Afterward, the message is added to the
	queue. The default task will be waiting for the message to be added to the queue.
	Afterward, it receives the message. If the id in the incoming message is 2, then the
	string “TIM2 cnt = �? is printed with the cnt value in the message. The green LED
	on the STM32F4 board is toggled. If the id in the incoming message is 3, then the
	string “TIM3 cnt = �? is printed with the cnt value in the message. The red LED
	on the STM32F4 board is toggled. Then, the allocated memory block is freed and
	returned to the memory pool.

	We should modify ITM properties as explained in
	Sect. 3.4.1.1 of the book to observe printing results in this example.


	***************************************************************************/

/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "stdio.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
# define FLAG 0x01
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
TIM_HandleTypeDef htim2;
TIM_HandleTypeDef htim3;

/********************************Definition tasks******************************/

osThreadId_t defaultTaskHandle;
const osThreadAttr_t defaultTask_attributes = {
  .name = "defaultTask",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityNormal,
};

osThreadId_t myTask02Handle;
const osThreadAttr_t myTask02_attributes = {
  .name = "myTask02",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityBelowNormal,
};

osThreadId_t myTask03Handle;
const osThreadAttr_t myTask03_attributes = {
  .name = "myTask03",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityBelowNormal,
};

/********************************Definition queues******************************/
osMessageQueueId_t Queue1Handle;
osMessageQueueAttr_t Queue1_attributes = {
		.name = "Queue1",
};

/********************************Definition event******************************/
osEventFlagsId_t Event1Handle;
osEventFlagsAttr_t Event1_attributes = {
		.name = "Event1",
};

/********************************Definition Memory pool***************************/
osMemoryPoolId_t MemoryPoolHandle;
osMemoryPoolAttr_t MemoryPool_attributes = {
		.name = "MemoryPool",
};

/* USER CODE BEGIN PV */
typedef struct {
	int arr[10];
	int id;
} mystruct;


/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_TIM2_Init(void);
static void MX_TIM3_Init(void);
void StartDefaultTask(void *argument);
void StartTask02(void *argument);
void StartTask03(void *argument);

/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
/*Function needed to use printf on CONSOLE*/
int _write(int file, char *ptr, int len){
	  int i = 0;
	  for (i=0; i<len; i++)
		  ITM_SendChar((*ptr++));
	  return len;
}
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_TIM2_Init();
  MX_TIM3_Init();
  /* USER CODE BEGIN 2 */
  /*Start Timer 2 and 3 in interrupt mode.*/
  if (__HAL_TIM_GET_FLAG(&htim2 , TIM_FLAG_UPDATE) != RESET)
  __HAL_TIM_CLEAR_FLAG(&htim2 , TIM_FLAG_UPDATE);
  if (__HAL_TIM_GET_FLAG(&htim3 , TIM_FLAG_UPDATE) != RESET)
  __HAL_TIM_CLEAR_FLAG(&htim3 , TIM_FLAG_UPDATE);
  HAL_TIM_Base_Start_IT(&htim2);
  HAL_TIM_Base_Start_IT(&htim3);

  /* USER CODE END 2 */

  /* Init scheduler */
  osKernelInitialize();

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* USER CODE BEGIN RTOS_QUEUES */
  uint8_t queue_size = 2;
  Queue1Handle =  osMessageQueueNew(queue_size, sizeof(mystruct), &Queue1_attributes);

  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */

  defaultTaskHandle = osThreadNew(StartDefaultTask, NULL, &defaultTask_attributes);
  myTask02Handle = osThreadNew(StartTask02, NULL, &myTask02_attributes);
  myTask03Handle = osThreadNew(StartTask03, NULL, &myTask03_attributes);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

  /* USER CODE BEGIN RTOS_EVENTS */
  Event1Handle = osEventFlagsNew(&Event1_attributes);
  /* USER CODE END RTOS_EVENTS */

  /* Start scheduler */
  osKernelStart();

  /* We should never get here as control is now taken by the scheduler */
  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 4;
  RCC_OscInitStruct.PLL.PLLN = 180;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 7;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Activate the Over-Drive mode
  */
  if (HAL_PWREx_EnableOverDrive() != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief TIM2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM2_Init(void)
{

  /* USER CODE BEGIN TIM2_Init 0 */

  /* USER CODE END TIM2_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM2_Init 1 */

  /* USER CODE END TIM2_Init 1 */
  htim2.Instance = TIM2;
  htim2.Init.Prescaler = 9000-1;
  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim2.Init.Period = 20000-1;
  htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim2, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM2_Init 2 */

  /* USER CODE END TIM2_Init 2 */

}

/**
  * @brief TIM3 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM3_Init(void)
{

  /* USER CODE BEGIN TIM3_Init 0 */

  /* USER CODE END TIM3_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM3_Init 1 */

  /* USER CODE END TIM3_Init 1 */
  htim3.Instance = TIM3;
  htim3.Init.Prescaler = 9000-1;
  htim3.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim3.Init.Period = 40000-1;
  htim3.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim3.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim3) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim3, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim3, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM3_Init 2 */

  /* USER CODE END TIM3_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
/* USER CODE BEGIN MX_GPIO_Init_1 */
/* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOG_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOG, GPIO_PIN_13|GPIO_PIN_14, GPIO_PIN_RESET);

  /*Configure GPIO pins : PG13 PG14 */
  GPIO_InitStruct.Pin = GPIO_PIN_13|GPIO_PIN_14;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOG, &GPIO_InitStruct);

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/* USER CODE BEGIN Header_StartDefaultTask */
/**
  * @brief  Function implementing the defaultTask thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_StartDefaultTask */
void StartDefaultTask(void *argument)
{
  /* USER CODE BEGIN 5 */
  mystruct re_data;
  /*Creaye memory pool with 10 blocks*/
  MemoryPoolHandle = osMemoryPoolNew(10, sizeof(re_data), &MemoryPool_attributes);

   // Infinite loop
  for(;;)
  {

	int ret;

	ret = osMessageQueueGet(Queue1Handle, &re_data, (uint8_t*) osPriorityNormal, osWaitForever);
	if (ret!=0){
		printf("Error retrieving memory ptr TIM2 \n");

	}
	else {

		if (re_data.id == 2){
			HAL_GPIO_TogglePin(GPIOG, GPIO_PIN_13);
			printf("TIME2 cnt: %d \n", re_data.arr[0]);
		}
	}

	ret = osMessageQueueGet(Queue1Handle, &re_data, (uint8_t*) osPriorityNormal, osWaitForever);
	if (ret!=0){
		printf("Error retrieving memory ptr TIM3 \n");
	}
	else {

		if (re_data.id == 3){
			HAL_GPIO_TogglePin(GPIOG, GPIO_PIN_14);
			printf("TIME3 cnt: %d \n", re_data.arr[0]);

		}

	}


  }
}
/* USER CODE BEGIN Header_StartTask02 */
/**
* @brief Function implementing the myTask02 thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartTask02 */
void StartTask02(void *argument)
{
  /* USER CODE BEGIN StartTask02 */
    mystruct * data;
	int ret;
    int cnt = 0;
	/* Infinite loop */
	for(;;)
	{

		osEventFlagsWait(Event1Handle, FLAG, osFlagsWaitAny, osWaitForever);

		data =  (mystruct *) osMemoryPoolAlloc(MemoryPoolHandle, 0U);

		data->arr[0] = cnt;
		data->id = 2;  // Timer 2

		ret = osMessageQueuePut(Queue1Handle, (mystruct *) data, osPriorityNormal, osWaitForever);

		if (ret!=0){
			  printf("Error putting Memory pointer (Timer 2) in queue\n");
		}
		else {
			printf("Memory ptr TIM2 in queue successfully \n\n");
			// Free the block of memory
			ret = osMemoryPoolFree(MemoryPoolHandle , data);
			if (ret !=0)
				printf("Error freeing memory block from the memory pool\n");
		}
		cnt++;
		osEventFlagsClear(Event1Handle, FLAG);

	}
  /* USER CODE END StartTask02 */
}

void StartTask03(void *argument)
{
  /* USER CODE BEGIN StartTask03 */
    mystruct *data;
	int ret;
    int cnt = 0;
	/* Infinite loop */
	for(;;)
	{

		osEventFlagsWait(Event1Handle, FLAG, osFlagsWaitAny, osWaitForever);

		data =  (mystruct *) osMemoryPoolAlloc(MemoryPoolHandle, 0U);

		data->arr[0] = cnt;
		data->id = 3;  // Timer 3

		ret = osMessageQueuePut(Queue1Handle, (mystruct *) data, osPriorityNormal, osWaitForever);
		if (ret!=0){
			  printf("Error putting Memory pointer (Timer 3) in queue\n");
		}
		else {
			printf("Memory ptr TIM3 in queue successfully \n\n");
			// Free the block of memory
			ret = osMemoryPoolFree(MemoryPoolHandle , data);
			if (ret !=0)
				printf("Error freeing memory block from the memory pool\n");

		}
		cnt++;
		osEventFlagsClear(Event1Handle, FLAG);
	}

  /* USER CODE END StartTask03 */
}



/**
  * @brief  Period elapsed callback in non blocking mode
  * @note   This function is called  when TIM6 interrupt took place, inside
  * HAL_TIM_IRQHandler(). It makes a direct call to HAL_IncTick() to increment
  * a global variable "uwTick" used as application time base.
  * @param  htim : TIM handle
  * @retval None
  */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{

  if (htim->Instance == TIM6) {
    HAL_IncTick();
  }
  else if (htim->Instance == TIM2){
	  osEventFlagsSet(Event1Handle, FLAG);

  }
  else if (htim->Instance == TIM3){
	  osEventFlagsSet(Event1Handle, FLAG);
  }

}

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
