# Gesture Controlled Car

The following project is a car that is controlled by the hand gesture. The ESP32 micro-controller connected on the car receives the change in direction signals from the
mobile phone that is held by the user. The mobile phone and the ESP32 are connected via a bluetooth. An accelometer of the mobile phone is used to measure the direction
and send it to the ESP32 which according to the x and y axis values of the mobile phone position, drives the motors.

# Hardware Components: 

1 - ESP32 with built in bluetooth and Wifi

2 - Chassis Kit (body of the car)

3 - Motot Driver Sheild

4 - Batteries, jumper wires, and switches 


# Gesture Controlled Car with camera module

A camera equipped ESP32 is added on the top of the gesture controlled car as an extension to the project. Once supplied with power, the camera records a video in the form of high frequency of images and on real time, the video is streamed on the web server on the given IP address. 
