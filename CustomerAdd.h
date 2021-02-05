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
	Customer* selectCustomerAll(int customerid);

	int insertCar(Car* car);
	int deleteCar(Car* car);
	Car* selectCar(string platenumber);
	Car* selectCarAll(int carid);

	int insertService(Service* service);
	int deleteService(Service* service);
	Service* selectService(int serviceid);
	Service* selectServiceid(string platenumber);
	Service* selectServiceidd(string platenumber ,string servicestatus);

	int insertServiceCost(Servicecost* servicecost);
	int deleteServiceCost(Servicecost* servicecost);
	Servicecost* selectServiceCost(int servicecostid);
	Servicecost* selectCost(int costid);

	int updateservice(Service* service);

	int updateservicecost(Servicecost* servicecost);

	bool validservice(int serviceid);

	bool validcustomer(int customerid);

	bool validcar(int carid);

	bool validcost(int costid);

	bool validcostservice(int servicecostid);

	bool UserLogin(string username, string column);

	bool ServiceCheckOne(string servicestatus, string column);

	bool ServiceCheck(string servicestatus, string row);

	bool AdminLogin(string username, string column);

	bool ServiceChoice(int serviceid, string servicetype);

	bool CheckCar(string platenumber, string column);

	bool ServiceTime(string date, string column);

	int insertAdmin(Admin* admin);

	int Calculate(string table, string column);

	
};
#endif
