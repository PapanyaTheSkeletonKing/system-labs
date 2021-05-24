// Lab1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Hotel.h"
#include "HotelStubDatabase.h"
#include "Writer.h"

void printMenu()
{
	cout << "|----------Main menu---------|" << endl;
	cout << "1) Print all hotels." << endl;
	cout << "2) Print hotels by county." << endl;
	cout << "3) Print hotel's per night price." << endl;
	cout << "4) Write to file." << endl;
	cout << "5) Exit." << endl;
	cout << "|----------------------------|" << endl;

}

void printOptions(forward_list<Hotel> hotels)
{
	for (auto& hotel : hotels)
	{
	    cout << "Id: " << hotel.getId()
			 << " | Name: " << hotel.getName()
			 << " | Country: " << hotel.getCountry()
			 << endl;
	}
}

string CountrySelectionMenu() {
	cout << "Please enter country: " << endl;
	
	string country;
	cin >> country;

	return country;
}

int HotelSelectionMenu() {
	cout << "Please enter hotel id: " << endl;

	int id;
	cin >> id;

	return id;
}
	

int main()
{
	
	HotelStubDatabase* hotelDatabase = new HotelStubDatabase();
	hotelDatabase->InitDB();
	auto* writer = new Writer();
	bool continueFlag = true;
	do
	{
		int result;
		cout << "Main menu:" << endl;
		printMenu();
		
		cin >> result;
		switch (result)
		{
		case 1:
			printOptions(*hotelDatabase->GetHotels());
			break;
		case 2:
			printOptions(hotelDatabase->GetHotelsByCountry(CountrySelectionMenu()));
			break;
		case 3:
			hotelDatabase->GetHotelById(HotelSelectionMenu()).print_cost_per_night();
			break;
		case 4: {
			writer->WriteToFile("test.txt", *hotelDatabase);
			break;
		}
		case 5:
			continueFlag = false;
			break;
		default:
			break;
		}
	}
	while (continueFlag);

	delete hotelDatabase;
	delete writer;
	return 0;
}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started:
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file