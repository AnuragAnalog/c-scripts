#!/bin/bash

gcc -c bitop.c
gcc -Wall bits.c bitop.o -o bitoper
