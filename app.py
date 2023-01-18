import os
import RPi.GPIO as GPIO
import sys
import time
import subprocess

GPIO.setmode(GPIO.BCM) 

# Initialisieren der Pins für den Button Input
GPIO.setup(26, GPIO.IN, pull_up_down=GPIO.PUD_UP)
GPIO.setup(19, GPIO.IN, pull_up_down=GPIO.PUD_UP)

# Funktion um den einen den Command an den Kernel zu senden
def send_command(command): 
    e = """echo "%s" > /dev/led""" % (command) 
    print(e) 
    subprocess.call(e, shell=True)
    
# Endlosschleife die, den Button Input abfrägt
while(True): 
    input_state_down = GPIO.input(26)
    input_state_up = GPIO.input(19)
    if input_state_down == 0: 
        send_command("down")
        time.sleep(0.5)
    if input_state_up == 0: 
        send_command("up") 
        time.sleep(0.5)