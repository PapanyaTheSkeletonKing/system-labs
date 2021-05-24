#include "HotelStubDatabase.h"

forward_list<Hotel>* HotelStubDatabase::GetHotels()
{
	return &hotels;
}

HotelStubDatabase::~HotelStubDatabase()
{
	delete &hotels;
}


void HotelStubDatabase::InitDB()
{
	Hotel stack_hotel1;
	stack_hotel1.setId(0);
	stack_hotel1.setRating(5);
	stack_hotel1.setName("hasbin");
	stack_hotel1.setCountry("Turkey");
	Hotel stack_hotel2;
	stack_hotel2.setId(1);
	stack_hotel2.setRating(4);
	stack_hotel2.setName("vesna");
	stack_hotel2.setCountry("Ukraine");
	Hotel stack_hotel3;
	stack_hotel3.setId(2);
	stack_hotel3.setRating(4);
	stack_hotel3.setName("trivago");
	stack_hotel3.setCountry("France");

	this->AddHotel(stack_hotel1);
	this->AddHotel(stack_hotel2);
	this->AddHotel(stack_hotel3);

	
	Hotel* heap_hotel1 = new Hotel();
	heap_hotel1->setId(3);
	heap_hotel1->setRating(3);
	heap_hotel1->setName("first inst");
	stack_hotel1.setCountry("Ukraine");
	Hotel* heap_hotel2 = new Hotel();
	heap_hotel2->setId(4);
	heap_hotel2->setRating(5);
	heap_hotel2->setName("second inst");
	heap_hotel2->setCountry("UAE");
	Hotel* heap_hotel3 = new Hotel();
	heap_hotel3->setId(5);
	heap_hotel3->setRating(2);
	heap_hotel3->setName("third inst");
	heap_hotel3->setCountry("France");

	this->AddHotel(*heap_hotel1);
	this->AddHotel(*heap_hotel2);
	this->AddHotel(*heap_hotel3);
}


void HotelStubDatabase::AddHotel(const Hotel& hotel)
{
	GetHotels()->push_front(hotel);
}


forward_list<Hotel> HotelStubDatabase::GetHotelsByCountry(const string& country)
{
	forward_list<Hotel> selectedItems;
	for (auto& hotel : hotels)
	{
                if (hotel.getCountry() == country)
		{
			selectedItems.push_front(hotel);
		}
	}
	return selectedItems;
}

Hotel HotelStubDatabase::GetHotelById(const int& id)
{
	for (auto& hotel : hotels)
	{
		if (hotel.getId() == id)
		{
			return hotel;
		}
	}
}
