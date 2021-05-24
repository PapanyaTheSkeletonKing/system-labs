#pragma once
#include <string>

class HotelStubDatabase;

class Writer
{
public:
	void WriteToFile(const char* path, HotelStubDatabase& data);
};
