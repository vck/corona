# bruteforce /dev/USB

import serial, time

port = 0

print "detecting arduino..."
for i in range(100):
    try:

        ard = serial.Serial('/dev/ttyUSB{}'.format(i), 9600)
        port = i
    except:
        continue

print "arduino found on /dev/ttyUSB{}".format(port)

def get_temp():
    return int(open('/sys/class/thermal/thermal_zone0/temp', 'r').read().strip('\n'))

while get_temp()/1000 > 40:
    print get_temp()/1000
    ard.write('5')
    time.sleep(60*5)
