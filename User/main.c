#include "gd32f4xx.h"
#include "systick.h"
#include <stdio.h>
#include "app.h"
#include "FreeRTOS.h"
#include "task.h"

TaskHandle_t Task1_handle = NULL;


// 任务栈溢出回调函数
void vApplicationStackOverflowHook(TaskHandle_t xTask, char *pcTaskName) {
    printf("Stack overflow in task %s\r\n", pcTaskName);
}

void lib_timer5_on_cb() {
	
}

//void lib_usart0_on_recv(uint8_t* data, uint16_t len) {
//	
//}
void Task1(void *pvParameters) {
    while(1) {
        printf("Task1 is running\r\n");
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}

int main(void) {

//	nvic_priority_group_set(NVIC_PRIGROUP_PRE2_SUB2);

//    systick_config();
	nvic_priority_group_set(NVIC_PRIGROUP_PRE4_SUB0);
	lib_peripheral_init();
	
	printf("MCU start\r\n");
	
	App_init();
	xTaskCreate(Task1, "Task1", 128, NULL, 2, &Task1_handle);

	vTaskStartScheduler();
	
    while(1) {
		
    }

}