#include <iostream>
#include "Hotel.h"

Hotel::Hotel(int id, string name, string county, string city, string address, int rating)
{
	setId(id);
	setName(name);
	setCountry(county);
	setCity(city);
	setRating(rating);
	setAddress(address);
}
Hotel::Hotel(){}

Hotel::~Hotel(){}

void Hotel::print_cost_per_night()
{
	double totalCost = 0;
	int rating_price = 100 * getRating();
	double country_mul = country_booking_mult(getCountry());
	totalCost = rating_price * country_mul;
	cout << "Night in our " + getName() + " hotel that located in " + getCountry() + " will cost " + std::to_string(totalCost) << endl;
}

double Hotel::country_booking_mult(string country)
{
	if (country == "Turkey")
		return 0.9;
	if (country == "UAE")
		return 1.1;
	if (country == "Ukraine")
		return 0.3;
	if (country == "France")
		return 1.3;
	return 1;
}

void Hotel::setAddress(string address)
{
	address_ = address;
}
string Hotel::getAddress()
{
	return address_;
}

void Hotel::setCity(string city)
{
	city_ = city;
}
string Hotel::getCity()
{
	return city_;
}

void Hotel::setName(string name)
{
	name_ = name;
}
string Hotel::getName()
{
	return name_;
}

void Hotel::setRating(int rating)
{
	rating_ = rating;
}
int Hotel::getRating()
{
	return rating_;
}

void Hotel::setContactPerson(string contact_person)
{
	contact_person_ = contact_person;
}
string Hotel::getContactPerson()
{
	return contact_person_;
}

void Hotel::setCountry(string country)
{
	country_ = country;
}
string Hotel::getCountry()
{
	return country_;
}

int Hotel::getId()
{
	return  id_;
}
void Hotel::setId(int id)
{
	id_ = id;
}