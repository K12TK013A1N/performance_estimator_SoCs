#!/bin/bash

as output.S -o output.o
ld output.o -o output
time ./output