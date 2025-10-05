| Supported Targets | ESP32-S3 |
| ----------------- | -------- |

# ESP32-S3 TinyUSB MTP Example

This repository incorporates the USB MTP Class implementation and example which is an excerpt from TinyUSB repository on 2025-10-06. The MTP related pieces are merged inside [my own fork of Espressif TinyUSB component](https://github.com/RigoLigoRLC/espressif-tinyusb-component/tree/release/v0.18-with-mtp), applied atop of v0.18 release branch.

Build with ESP-IDF 5.5.1.

The current SDK configuration sets Flash size to 16MiB, and has a partition table configured with 11MiB left for a littlefs filesystem.

littlefs integration is not implemented for now. It will be worked on later.
