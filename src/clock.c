#include <stm32f1xx_hal.h>

#include <sys/clock.h>
#include <sys/cc.h>
#include <sys/etimer.h>

#include <SEGGER_RTT.h>

extern __IO uint32_t uwTick;

static volatile unsigned long current_seconds = 0;
static unsigned int second_countdown = CLOCK_SECOND;

void HAL_IncTick(void)
{
    uwTick += uwTickFreq;
    if(etimer_pending() && etimer_next_expiration_time() <= uwTick) {
        etimer_request_poll();
    }
    if(--second_countdown == 0)
    {
        current_seconds++;
        second_countdown = CLOCK_SECOND;
    }
}

void clock_init()
{
}

clock_time_t clock_time(void)
{
    return HAL_GetTick();
}

unsigned long clock_seconds(void)
{
  return current_seconds;
}
