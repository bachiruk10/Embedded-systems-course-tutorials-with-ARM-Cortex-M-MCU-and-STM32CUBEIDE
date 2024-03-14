## Program: Python client to communicate with STM32 ADC with Serial UART

from serial.tools import list_ports
import numpy as np
import serial
import time
import struct

import re
import matplotlib.pyplot as plt
import matplotlib.animation as animation
import matplotlib


ports = list_ports.comports()
for port in ports: print(port)


def animate(i, dataList, ser):

    s_bytes = ser.readline(4)
    if (len(s_bytes) == 4):
        data = struct.unpack('f', s_bytes)
        dataList.append(data)
    else:
        try:
            s_bytes += ser.readline(4-len(s_bytes))
            data = struct.unpack_from('f', s_bytes, 0)
            dataList.append(data)
        except:
            print ("missing bytes")

    dataList = dataList[-100:]                           # Fix the list size so that the animation plot 'window' is x number of points
    
    ax.clear()                                          # Clear last data frame
    ax.plot(dataList)                                   # Plot new data frame
    
    ax.set_ylim([-1000, 1000])                                  # Set Y axis limit of plot
    ax.set_title("ADC STM32 Data")                        # Set title of figure
    ax.set_ylabel("Voltage")                              # Set title of y axis 



dataList = []                                           # Create empty list variable to store ADC data

t = []

fig = plt.figure()                                      # Create Matplotlib plots fig is the 'higher level' plot window
ax = fig.add_subplot(111)                               # Add subplot to main fig window


ser = serial.Serial('COM3', 115200)                     # Open Serial port attached to COM3 with Barudrate 115200 b/s

time.sleep(2)                                           # Time delay for STM32 Serial initialization 


str = input("Send (g) or (r) to start/stop ADC: ")      # Send a byte character to STM32 to start or stop the ADC 
ser.write(bytes(str, "utf8"))
                                                        # Matplotlib Animation Fuction that takes takes care of real time plot.
                                                        # Note that 'fargs' parameter is where we pass in our dataList and Serial object. 
if (str == 'g'):
    ani = animation.FuncAnimation(fig, animate, fargs=(dataList, ser), interval=1)
    plt.show() 

                                                        # Keep Matplotlib plot persistent on screen until it is closed
ser.close()                                             # Close Serial connection when plot is closed

