// Lab1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Hotel.h"

int main()
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

	stack_hotel1.print_cost_per_night();
	stack_hotel2.print_cost_per_night();
	stack_hotel3.print_cost_per_night();

	Hotel* heap_hotel1 = new Hotel();
	heap_hotel1->setId(0);
	heap_hotel1->setRating(3);
	heap_hotel1->setName("first inst");
	stack_hotel1.setCountry("Ukraine");
	Hotel* heap_hotel2 = new Hotel();
	heap_hotel2->setId(1);
	heap_hotel2->setRating(5);
	heap_hotel2->setName("second inst");
	heap_hotel2->setCountry("UAE");
	Hotel* heap_hotel3 = new Hotel();
	heap_hotel3->setId(2);
	heap_hotel3->setRating(2);
	heap_hotel3->setName("third inst");
	heap_hotel3->setCountry("France");

	heap_hotel1->print_cost_per_night();
	heap_hotel2->print_cost_per_night();
	heap_hotel3->print_cost_per_night();

	delete heap_hotel1;
	delete heap_hotel2;
	delete heap_hotel3;
	
	
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
