#include <string>
#ifndef AIRLINES_H
#define AIRLINES_H

using namespace std;

class Airlines
{
private:
	string ticketType;
	double ticketPrice;
	int ticketQuantity;

public:
	Airlines(string, double, int);

	void setTicketQuantity(int);
	int getticketQuantity() const;
	double getTicketPrice() const;
	double getTicketSubTotal() const;
	double getTax() const;
	string getTicketType() const;
	double getTicketTotal() const;

	~Airlines(){};
};


#endif