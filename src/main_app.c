#include <main.h>
#include <gpio.h>

void SystemClock_Config(void);

int main(void)
{
    HAL_Init();
    SystemClock_Config();

    MX_GPIO_Init();

    HAL_GPIO_TogglePin(LD_R_GPIO_Port, LD_R_Pin);
    while (1)
    {
        HAL_GPIO_TogglePin(LD_G_GPIO_Port, LD_G_Pin);
        HAL_GPIO_TogglePin(LD_R_GPIO_Port, LD_R_Pin);
        HAL_Delay(500);
    }
}
