#include "Customer.h"
#include "Car.h"
#include "Admin.h"
#include "Service.h"
#include "ServiceCost.h"

#ifndef CUSTOMERADD_H
#define CUSTOMERADD_H


class CustomerAdd
{
public:
	int insertCustomer(Customer* customer);
	int deleteCustomer(Customer* customer);
	Customer* selectCustomer(string username);

	int insertCar(Car* car);
	int deleteCar(Car* car);
	Car* selectCar(string platenumber);

	int insertService(Service* service);
	int deleteService(Service* service);

	bool UserLogin(string username, string column);

	bool AdminLogin(string username, string column);

	bool ServiceChoice(string servicetype, string column);

	bool ServiceChoice1(string serviceid, string row);

	bool CheckCar(string platenumber, string column);

	int insertAdmin(Admin* admin);
};
#endif
