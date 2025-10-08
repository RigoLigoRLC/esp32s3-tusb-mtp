| Supported Targets | ESP32-S3 |
| ----------------- | -------- |

# ESP32-S3 TinyUSB MTP Example

This repository incorporates the USB MTP Class implementation and example which is an excerpt from TinyUSB repository on 2025-10-06. The MTP related pieces are merged inside [my own fork of Espressif TinyUSB component](https://github.com/RigoLigoRLC/espressif-tinyusb-component/tree/release/v0.18-with-mtp), applied atop of v0.18 release branch.

Build with ESP-IDF 5.5.1.

The current SDK configuration sets Flash size to 16MiB, and has a partition table configured with 11MiB left for a littlefs filesystem.

# What works

You can copy files into LittleFS and out. You can delete files. Simple tests with files ranging from kilobytes to around 7MB seem to work fine.

Directories are not fully done yet, and IS ABSOLUTELY NOT TESTED AT ALL. Due to the nasty nature of MTP requiring the responder device to provide persistent handles to the host, the current design used a mega handle table in the RAM, and it is consistent with all objects in the filesystem. To further limit complexity, only 1 level directory is supported in the current code. Deleting directory is not tested.

# License

MIT License
