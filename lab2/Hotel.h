#pragma once
#include <string>
using namespace std;

class Hotel
{
public:

	Hotel(int id, string name, string country, string city, string address, int rating);
	Hotel();
	~Hotel();
	
	int getId();
	void setId(int id);

	void setName(string name);
	string getName();
	void setCountry(string country);
	string getCountry();
	void setCity(string city);
	string getCity();
	void setAddress(string address);
	string getAddress();
	void setRating(int rating);
	int getRating();
	void setContactPerson(string contactPerson);
	string getContactPerson();

	void print_cost_per_night();
	double country_booking_mult(string country);

private:
	int id_ = 0;

	string name_;
	string country_;
	string city_;
	string address_;
	int rating_ = 0;
	string contact_person_;
};
