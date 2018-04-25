#include "Airlines.h"
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

const double TAX = 0.0775;

Airlines::Airlines(string type = NULL , double price = 0.0 , int quantity = 0.0)
{
	ticketType = type;
	ticketPrice = price;
	ticketQuantity = quantity;
}

void Airlines::setTicketQuantity(int quantity)
{
	ticketQuantity += quantity;
}

int Airlines::getticketQuantity() const
{
	return ticketQuantity;
}

double Airlines::getTicketPrice() const
{
	return ticketPrice;
}

double Airlines::getTicketSubTotal() const
{
	return ticketPrice * ticketQuantity;
}
double Airlines::getTax() const
{
	return getTicketSubTotal() * TAX;
}
string Airlines::getTicketType() const
{
	return ticketType;
}

double Airlines::getTicketTotal() const
{
	return getTicketSubTotal() + getTax();
}