/*
 * Smart Home Control System
 *
 * This project is part of an academic work created for university purposes.
 * It is provided strictly for educational use, and any other use must comply with the terms of the license.
 *
 * License: MIT License
 * Copyright (c) 2024 Hubert Borysowski
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of this software
 * and associated documentation files (the "Software"), to deal in the Software without restriction,
 * including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO
 * THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS
 * OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#include <iostream>
#include <chrono>
#include <thread>
#include "serial.h"

int main(){
    std::wstring portName = L"COM3";  // Make sure to set the correct COM port
    Serial serial(portName);

    if (!serial.open()){
        std::cerr << "Failed to open serial port!" << std::endl;
        return 1;
    }

    std::string sendData = "Hello, Arduino!";
    std::cout << "Sending string to Arduino: " << sendData << std::endl;
    serial.write(sendData);  // Send the string to Arduino

    std::cout << "Waiting for Arduino to echo the string..." << std::endl;

    std::string receivedData = serial.readString();  // Read the string from Arduino

    std::cout << "Received from Arduino: " << receivedData << std::endl;

    serial.close();
    return 0;
}