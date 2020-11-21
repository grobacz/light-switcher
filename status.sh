#!/bin/bash

echo "podejść do światła i sprawdzić czy włączone"

echo "czy brama lightify nasłuchuje"
ncat -znv 192.168.0.19 4000

echo "czy demon światła działa"
ssh pi ps aux | grep light-daemon

echo "czy arduino podłączone"
ssh pi ls -la /dev/ttyACM0
