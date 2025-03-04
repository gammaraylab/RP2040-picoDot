## RP2040 firmware for picoDot

This firmware is a customized version of the existing grblHAL. The modifications include:
- New `board map` with minor pin changes to suit specific hardware layout.
- A script to automatically copy the built `UF2` file to the `RP2040` to facilitate development of firmware.

The rest of the functionality remains similar to the standard `grblHAL RP2040` implementation.

### CLion
Made changes in `CMakeLists.txt` to work with `Intellij CLion`

---


__Important__ download information can be found [here](https://github.com/grblHAL/core/wiki/Compiling-grblHAL).  
The project has been updated to/now uses [SDK version 2.1.0](https://github.com/raspberrypi/pico-sdk/releases).
