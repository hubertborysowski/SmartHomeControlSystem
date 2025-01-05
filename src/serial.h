#ifndef SERIAL_H
#define SERIAL_H

#include <windows.h>
#include <string>

class Serial {
public:
    Serial(const std::wstring& portName);
    ~Serial();

    bool open();
    void close();
    bool isOpen() const;
    void write(char data);  // Method to write a single byte
    void write(const std::string& data);  // Method to send a string
    char read();  // Method to read a single byte
    void flush();
    std::string readString();  // Method to read an entire string

private:
    std::wstring portName;
    HANDLE hSerial;
};

#endif