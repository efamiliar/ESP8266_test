#!/bin/bash
cu -l /dev/ttyUSB1 -s 115200
cat </dev/ttyUSB1
