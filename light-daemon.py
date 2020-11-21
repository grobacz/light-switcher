import serial
import time
import os

devicePath = "/dev/ttyACM0"

if not os.path.exists(devicePath):
    print("Switch device is missing")
    exit(1)

ser = serial.Serial(devicePath, 9600)
ser.baudrate = 9600
gateIp = os.getenv("LIGHTIFY_GATE_IP")

lastTrigger = time.time()
nextState = "on"

print("daemon started")

# todo: discovery of device with port 4000 open - lightify gateway
# todo: initial state reading?
# todo: wait loop for arduino if disconnected?
# todo: print only in verbose/dev mode

while True:
    read_ser = ser.readline().rstrip().decode("utf-8")
    # print(read_ser)
    if read_ser == "light switch" and time.time() - 3 > lastTrigger:
        print("switching " + nextState)
        lastTrigger = time.time()
        os.system('/home/grobacz/Device-Osram-Lightify/bin/ol --hub ' + gateIp + ' --all-' + nextState)
        nextState = "off" if nextState == "on" else "on"
