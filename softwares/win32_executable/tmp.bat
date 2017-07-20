@echo off
color f0
title AvrDude GUI Command Window
@echo.
@echo. trying to connect to device...
avrdude -p ATMEGA16 -c usbasp -P COM1  -U flash:v:"":i
avrdudeGUI.exe -done
pause