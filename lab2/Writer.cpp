#include "Writer.h"
#include "HotelStubDatabase.h"
using namespace std;

void Writer::WriteToFile(const char* path,HotelStubDatabase& data)
{
	forward_list<Hotel> to_write = *(data.GetHotels());
	
        FILE* fp = fopen(path, "w+");
	
	for (auto& hotel : to_write)
	{
		string write = "Id: " + std::to_string(hotel.getId()) + "Name : " + hotel.getName();
		fputs(write.c_str(),fp);
	}
	fclose(fp);
}
