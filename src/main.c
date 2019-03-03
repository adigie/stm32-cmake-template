#include "main.h"
#include "cmsis_os.h"
#include "gpio.h"

void SystemClock_Config(void);
void MX_FREERTOS_Init(void);
void StartDefaultTask(void const * argument);

int main(void)
{
    HAL_Init();
    SystemClock_Config();

    MX_GPIO_Init();
    MX_FREERTOS_Init();

    osKernelStart();

    while (1)
    {
    }
}

void StartDefaultTask(void const * argument)
{
    UNUSED(argument);

    HAL_GPIO_TogglePin(LD_G_GPIO_Port, LD_G_Pin);
    for(;;)
    {
        HAL_GPIO_TogglePin(LD_G_GPIO_Port, LD_G_Pin);
        HAL_GPIO_TogglePin(LD_R_GPIO_Port, LD_R_Pin);
        osDelay(1000);
    }
}