#include <stdint.h>
#include <limits.h>

#include <main.h>
#include <SEGGER_RTT.h>
//#include <pt.h>

#include <stm32f1xx.h>
#include <stm32f1xx_ll_bus.h>
#include <stm32f1xx_ll_gpio.h>

//#include <timer.h>

#include <sys/process.h>
#include <sys/clock.h>
#include <sys/etimer.h>
#include <sys/ctimer.h>

void SystemClock_Config(void);


static struct ctimer ct1;
static struct etimer et1;

PROCESS(example_process, "example process");
PROCESS_THREAD(example_process, ev, data)
{
    PROCESS_BEGIN();

    (void) data;
    (void) ev;

    LL_APB2_GRP1_EnableClock(LL_APB2_GRP1_PERIPH_GPIOC);
    LL_GPIO_SetPinMode(GPIOC, LL_GPIO_PIN_13, LL_GPIO_OUTPUT_PUSHPULL);
    LL_GPIO_SetPinSpeed(GPIOC, LL_GPIO_PIN_13, LL_GPIO_SPEED_FREQ_LOW);

    while(1)
    {
        etimer_set(&et1, CLOCK_SECOND);
        PROCESS_WAIT_EVENT_UNTIL(etimer_expired(&et1));

        LL_GPIO_TogglePin(GPIOC, LL_GPIO_PIN_13);
        SEGGER_RTT_printf(0, "etimer expired\n");
    }

    PROCESS_END();
}

PROCESS(idle_process, "idle process");
PROCESS_THREAD(idle_process, ev, data)
{
    (void)ev;
    (void)data;

    PROCESS_BEGIN();

    while(1)
    {
        SEGGER_RTT_printf(0, "idle\n");
        PROCESS_YIELD();
    }

    PROCESS_END();
}

static void callback(void *ptr)
{
    (void)ptr;

    SEGGER_RTT_printf(0, "ctimer callback\n");
    ctimer_reset(&ct1);
}

int main(void)
{
    HAL_Init();
    SystemClock_Config();

    clock_init();
    process_init();
    process_start(&etimer_process, NULL);
    ctimer_init();

    process_start(&example_process, NULL);
    process_start(&idle_process, NULL);

    ctimer_set(&ct1, CLOCK_SECOND, callback, NULL);

    while(1)
    {
        int r = 0;
        do {
          r = process_run();
        } while(r > 0);
//        __WFI();
    }
}
