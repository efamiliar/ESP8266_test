#!/bin/bash
cu -l /dev/ttyUSB0 -s 115200
cat </dev/ttyUSB0
