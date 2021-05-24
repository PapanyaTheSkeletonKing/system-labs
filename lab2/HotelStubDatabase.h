#pragma once
#include "list"
#include "Hotel.h"
#include <vector>
#include <forward_list>

class HotelStubDatabase
{
public:
	~HotelStubDatabase();
	
	forward_list<Hotel>* GetHotels();
	void AddHotel(const Hotel& hotel);
	forward_list<Hotel> GetHotelsByCountry(const string& country);
	Hotel GetHotelById(const int& id);
	void InitDB();
	
private:
	forward_list<Hotel> hotels;
};
