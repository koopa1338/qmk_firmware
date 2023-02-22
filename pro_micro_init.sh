#!/bin/bash
avrdude -c usbasp -P usb -p atmega32u4 -U flash:w:lily58_rev1_default_production.hex:a -U lfuse:w:0x5E:m -U hfuse:w:0x99:m -U efuse:w:0xF3:m
