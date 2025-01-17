@echo off 
@echo Debugging the nrf52 using Black Magic Probe

if exist C:\Users\pierre\Documents\Arduino\hardware\Adafruit\Adafruit_nRF52_Arduino (
    set prefix=C:\Users\pierre\Documents\Arduino\hardware\Adafruit\Adafruit_nRF52_Arduino
) else (
    set prefix=%localappdata%\Arduino15\packages\adafruit\hardware\nrf52
)

set bmpprefix=%localappdata%\Arduino15\packages\adafruit\tools\arm-none-eabi-gcc\9-2019q4\bin\arm-none-eabi-gdb.exe

if exist %bmpprefix% (
    @echo Found arm-none-eabi-gdb.exe
) else (
    @echo NOT Found arm-none-eabi-gdb.exe
)

set filename=C:\Users\levih\Documents\Projects\Keyboards\BlueMicro_BLE\output\owl\owl-feather52832-nrfmicro-default-left.elf

%bmpprefix%  %filename% -ex "target extended-remote \\.\%1"  -ex "mon swdp_scan" -ex "att 1" 

