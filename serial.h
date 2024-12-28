#ifndef SERIAL_H
#define SERIAL_H

#include <windows.h>
#include <string>

class Serial
{
public:
    Serial(const std::wstring& portName);  // Use wide string
    ~Serial();

    bool open();
    void close();
    bool isOpen() const;
    void write(char data);
    char read();

private:
    std::wstring portName;  // Use wide string
    HANDLE hSerial;
};

#endif