
#include "tasks.h"
#include "tusb.h"
#include "esp_log.h"
#include "esp_private/usb_phy.h"

#define TAG "init"

int init_hardware_usb_phy(void)
{
    static usb_phy_handle_t handle;
    usb_phy_config_t phy_conf = {
        .controller = USB_PHY_CTRL_OTG,
        .otg_mode = USB_OTG_MODE_DEVICE,
        .target = USB_PHY_TARGET_INT,
    };
    usb_new_phy(&phy_conf, &handle);
    return ESP_OK;
}

int init_hardware(void)
{
    ESP_ERROR_CHECK(init_hardware_usb_phy());

    return ESP_OK;
}

int init_tinyusb(void)
{
    bool usb_init = tusb_init();
    if (!usb_init) {
        ESP_LOGE(TAG, "USB Device Stack Init Fail");
        return ESP_FAIL;
    }
    return ESP_OK;
}

int init_software(void)
{
    ESP_ERROR_CHECK(init_tinyusb());

    return ESP_OK;
}

int init_tasks(void)
{
    BaseType_t ret;
    ret = xTaskCreate(
        TaskTinyusb,
        "tinyusb",
        1024 * 8,
        NULL,
        5,
        &hTaskTinyusb);
    if (ret != pdPASS) return ESP_FAIL;
    
    return ESP_OK;
}
