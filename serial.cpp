#include "serial.h"
#include <iostream>

Serial::Serial(const std::wstring& portName)
    : portName(portName), hSerial(INVALID_HANDLE_VALUE)
{
}

Serial::~Serial()
{
    close();
}

bool Serial::open()
{
    hSerial = CreateFileW(   // Use CreateFileW for wide character support
        portName.c_str(), GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0, NULL
    );

    if (hSerial == INVALID_HANDLE_VALUE)
    {
        std::cerr << "Error opening serial port: " << GetLastError() << std::endl;
        return false;
    }

    DCB dcbSerialParams = { 0 };
    if (!GetCommState(hSerial, &dcbSerialParams))
    {
        std::cerr << "Error getting serial port state: " << GetLastError() << std::endl;
        return false;
    }

    dcbSerialParams.BaudRate = CBR_9600;
    dcbSerialParams.ByteSize = 8;
    dcbSerialParams.StopBits = ONESTOPBIT;
    dcbSerialParams.Parity = NOPARITY;

    if (!SetCommState(hSerial, &dcbSerialParams))
    {
        std::cerr << "Error setting serial port state: " << GetLastError() << std::endl;
        return false;
    }

    return true;
}

void Serial::close()
{
    if (hSerial != INVALID_HANDLE_VALUE)
    {
        CloseHandle(hSerial);
        hSerial = INVALID_HANDLE_VALUE;
    }
}

bool Serial::isOpen() const
{
    return hSerial != INVALID_HANDLE_VALUE;
}

void Serial::write(char data)
{
    DWORD bytesWritten;
    if (!WriteFile(hSerial, &data, 1, &bytesWritten, NULL))
    {
        std::cerr << "Error writing to serial port: " << GetLastError() << std::endl;
    }
}

char Serial::read()
{
    char data = 0;
    DWORD bytesRead;
    if (!ReadFile(hSerial, &data, 1, &bytesRead, NULL))
    {
        std::cerr << "Error reading from serial port: " << GetLastError() << std::endl;
    }
    return data;
}