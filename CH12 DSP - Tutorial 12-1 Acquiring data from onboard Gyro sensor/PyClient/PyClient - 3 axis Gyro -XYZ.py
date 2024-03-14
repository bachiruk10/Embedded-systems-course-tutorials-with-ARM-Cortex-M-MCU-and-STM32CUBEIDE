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
from collections import deque


ports = list_ports.comports()
for port in ports: print(port)


def animate(i, data1, data2, data3, ser):
    
    
    s_bytes = ser.readline(4)
    if (len(s_bytes) == 4):
        data = struct.unpack('f', s_bytes)
        data1.append(data[0])
    else:
        try:
            s_bytes += ser.readline(4-len(s_bytes))
            data = struct.unpack_from('f', s_bytes, 0)
            data1.append(data[0])
        except:
            print ("missing bytes")
            

    s_bytes = ser.readline(4)
    if (len(s_bytes) == 4):
        data = struct.unpack('f', s_bytes)
        data2.append(data[0])
    else:
        try:
            s_bytes += ser.readline(4-len(s_bytes))
            data = struct.unpack_from('f', s_bytes, 0)
            data2.append(data[0])
        except:
            print ("missing bytes")



    s_bytes = ser.readline(4)
    if (len(s_bytes) == 4):
        data = struct.unpack('f', s_bytes)
        data3.append(data[0])
    else:
        try:
            s_bytes += ser.readline(4-len(s_bytes))
            data = struct.unpack_from('f', s_bytes, 0)
            data3.append(data[0])
        except:
            print ("missing bytes")


    #print (data1[0])
    #print (data2[0])
    #print (data3[0])
    

    data1 = data1[-100:]                           # Fix the list size so that the animation plot 'window' is x number of points
    data2 = data2[-100:]                           # Fix the list size so that the animation plot 'window' is x number of points
    data3 = data3[-100:]                           # Fix the list size so that the animation plot 'window' is x number of points
    
    ax1.clear()                                          # Clear last data frame
    ax2.clear()
    ax3.clear()


    ax1.plot(data1)                                   # Plot new data frame
    ax1.set_ylim([-1000, 1000]) 
    ax1.set_ylabel("X axis (dps)")                              # Set title of y axis 

                                                        # Clear last data frame
    ax2.plot(data2)
    ax2.set_ylim([-1000, 1000])          
    ax2.set_ylabel("Y axis (dps)")

                                                      # Clear last data frame
    ax3.plot(data3)  
    ax3.set_ylim([-1000, 1000])        
    ax3.set_ylabel("Z axis (dps)")

    #ax1.set_ylim([0, 4])                                  # Set Y axis limit of plot
    ax1.set_title("3 Axis Gyro I3G4250D")                        # Set title of figure
   



data1 = []
data2 = []
data3 = []

t = []

fig, (ax1, ax2, ax3) = plt.subplots(3,1)                # Create Matplotlib plots fig is the 'higher level' plot window
ax1.clear()
ax2.clear()
ax3.clear()

ax1.set_ylabel("Pot_Ch1 (V)")
ax2.set_ylabel("Pot_Ch2 (V)")
ax3.set_ylabel("Pot_Ch3 (V)")



ser = serial.Serial('COM3', 2000000)                     # Open Serial port attached to COM3 with Barudrate 115200 b/s

time.sleep(2)                                           # Time delay for STM32 Serial initialization 


str = input("Send (g) or (r) to start/stop ADC: ")      # Send a byte character to STM32 to start or stop the ADC 
ser.write(bytes(str, "utf8"))
                                                        # Matplotlib Animation Fuction that takes takes care of real time plot.
                                                        # Note that 'fargs' parameter is where we pass in our dataList and Serial object. 
if (str == 'g'):
    ani = animation.FuncAnimation(fig, animate, fargs=(data1, data2, data3, ser), interval=1)
    plt.show() 

                                                        # Keep Matplotlib plot persistent on screen until it is closed
ser.close()                                             # Close Serial connection when plot is closed

