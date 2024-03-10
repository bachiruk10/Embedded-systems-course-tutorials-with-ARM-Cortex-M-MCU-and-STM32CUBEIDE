#Embedded systems course tutorials with ARM Cortex M MCU and STM32CUBEIDE 

This repository presents tutorials with solutions to teach fundamental aspects of embedded software design using ARM microcontrollers.   

The projects presented in these tutorials cover the following topics in microcontrollers:
1.	Software Development Platforms
2.	Digital Input and Output
3.	Interrupts and Power Management
4.	Timing Operations
5.	Conversion Between Analog and Digital Values
6.	Digital Communication
7.	Memory Operations
8.	Real-time Operating Systems FreeRTOS
9.	Digital Signal Processing.
    
The tutorials originate or are based on the listing examples in the book “Embedded System Design with ARM Cortex-M Microcontrollers” by Cem Ünsalan, Hüseyin Deniz Gürhan & Mehmet Erkin Yücel, published by Springer, 2021.
It is recommended to have a copy of the book to support understanding of the topics covered by the tutorials, and also to access information that in some cases is required by the tutorials like figures illustrating hardware setup. The book can be obtained online or through the site: https://link.springer.com/book/10.1007/978-3-030-88439-0

**************************************************************************************
Tutorials requirements: 

•	Download STM32CUBE IDE through the link:
https://www.st.com/en/development-tools/stm32cubeide.html
•	STM32F429 Discovery board. 
•	Hardware and components as requested in description of some of the tutorials
The tutorials use the HAL library of functions, which allows portability across STM32 boards, so the user can modify the solution by using another board without loosing the learning benefit intended by the tutorial. 
As you can see in the list of tutorials in the repository, the naming follows the template:
•	Chapter number – MCU Topic – Tutorial number – Description of the tutorial
for example:
•	CH10 FreeRTOS - Tutorial 10-3 Task management Example 1 
Hence, the user can refer to the example listing 10.3 in Chapter 10 of the book addressing FreeRTOS, where the exercise presents an example on Task management in microcontrollers. 
Tutorial description in main.c file:
In each tutorial, you will find in the main.c file, a description of the project to form, and a list of the tags for the topics (or MCU peripherals) which form part of the tutorial. This helps the reader to get an idea of the project without referring to the book, or to select which tutorial would be more appropriate for him or her.
In this repository, the tutorials use the language C to form solution of the projects. 
***************************************************************************************

A note about the Book:

This textbook introduces basic and advanced embedded system topics through Arm Cortex M microcontrollers, covering programmable microcontroller usage starting from basic to advanced concepts using the STMicroelectronics Discovery development board. Designed for use in upper-level undergraduate and graduate courses on microcontrollers, microprocessor systems, and embedded systems, the book explores fundamental and advanced topics, real-time operating systems via FreeRTOS and Mbed OS, and then offers a solid grounding in digital signal processing, digital control, and digital image processing concepts — with emphasis placed on the usage of a microcontroller for these advanced topics. The book uses C language, “the” programming language for microcontrollers, C++ language, and MicroPython, which allows Python language usage on a microcontroller. Sample codes and course slides are available for readers and instructors, and a solutions manual is available to instructors. The book will also be an ideal reference for practicing engineers and electronics hobbyists who wish to become familiar with basic and advanced microcontroller concepts. 
