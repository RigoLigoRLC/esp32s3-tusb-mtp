
#include <assert.h>
#include "tasks.h"
#include "tusb.h"
#include <esp_log.h>

void TaskTinyusb(void *pvParameters)
{
    while (true) {
        tud_task();
    }
}
