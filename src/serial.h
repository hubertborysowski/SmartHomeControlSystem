#ifndef SERIAL_H
#define SERIAL_H

#include <windows.h>
#include <string>

class Serial{
public:
    Serial(const std::wstring& portName);
    ~Serial();

    bool open();
    void close();
    bool isOpen() const;
    void write(char data);  // Existing function to write a single byte
    void write(const std::string& data);  // New function to send a string
    char read();  // Existing function to read a single byte
    std::string readString();  // New function to read an entire string

private:
    std::wstring portName;
    HANDLE hSerial;
};

#endif