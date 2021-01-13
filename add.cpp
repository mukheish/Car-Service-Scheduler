#include <iostream>
#include <string>
using namespace std;

#include <mysql/jdbc.h>
using namespace sql;

#include "DatabaseConnection.h"
#include "Customer.h"
#include "CustomerAdd.h"
#include "Car.h"
#include "Service.h"
#include "ServiceCost.h"


int CustomerAdd::insertCustomer(Customer* customer)
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("INSERT INTO customer VALUES (?, ?, ?, ?, ?, ?)");

	ps->setString(1, customer->username);
	ps->setString(2, customer->icnumber);
	ps->setString(3, customer->phonenumber);
	ps->setString(4, customer->address);
	ps->setString(5, customer->password);
	ps->setString(6, customer->customerid);
	

	int status = ps->executeUpdate();

	delete ps;

	return status;
}

int CustomerAdd::deleteCustomer(Customer* customer)
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("DELETE FROM customer WHERE username=?;");

	ps->setString(1, customer->username);

	int status = ps->executeUpdate();

	delete ps;

	return status;
}

Customer* CustomerAdd::selectCustomer(string username)
{
	Customer* customer = NULL;
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("SELECT * FROM customer WHERE username = ?");

	ps->setString(1, username);

	ResultSet* rs = ps->executeQuery();

	if (rs->next())
	{
		customer = new Customer();

		customer->username = rs->getString(1);
		customer->icnumber = rs->getString(2);
		customer->phonenumber = rs->getString(3);
		customer->address = rs->getString(4);

	}

	delete rs;
	delete ps;

	return customer;
}


int CustomerAdd::insertCar(Car* car)
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("INSERT INTO car VALUES (?, ?, ?, ?)");

	ps->setString(1, car->platenumber);
	ps->setString(2, car->carname);
	ps->setString(3, car->carcolour);
	ps->setString(4, car->username);

	int status = ps->executeUpdate();

	delete ps;

	return status;
}

int CustomerAdd::deleteCar(Car* car)
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("DELETE FROM car WHERE platenumber=?;");

	ps->setString(1, car->platenumber);

	int status = ps->executeUpdate();

	delete ps;

	return status;
}

Car* CustomerAdd::selectCar(string platenumber)
{
	Car* car = NULL;
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("SELECT * FROM car WHERE platenumber = ?");

	ps->setString(1, platenumber);

	ResultSet* rs = ps->executeQuery();

	if (rs->next())
	{
		car = new Car();

		car->platenumber = rs->getString(1);
		car->carname = rs->getString(2);
		car->carcolour = rs->getString(3);
		
	}
	else
	{
		cout << "NO";
	}

	delete rs;
	delete ps;

	return car;
}

int CustomerAdd::insertService(Service* service)
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("INSERT INTO service VALUES (?, ?, ?, ?)");

	ps->setString(1, service->servicetype);
	ps->setString(2, service->servicecost);
	ps->setString(3, service->serviceid);
	ps->setString(4, service->platenumber);

	int status = ps->executeUpdate();

	delete ps;

	return status;
}

int CustomerAdd::deleteService(Service* service)
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("DELETE FROM service WHERE serviceid=?;");

	ps->setString(1, service->serviceid);

	int status = ps->executeUpdate();

	delete ps;

	return status;
}


bool CustomerAdd::UserLogin(string username, string column) 
{
	bool stat = false;
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("SELECT * FROM customer WHERE " + column + " = ?");

	ps->setString(1, username);

	ResultSet* rs = ps->executeQuery();

	if (rs->next())
	{
		stat = true;
		return stat;
	}
	else
	{
		return stat;
	}

	delete rs;
	delete ps;
}

bool CustomerAdd::AdminLogin(string username, string column)
{
	bool stat = false;
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("SELECT * FROM admin WHERE " + column + " = ?");

	ps->setString(1, username);

	ResultSet* rs = ps->executeQuery();

	if (rs->next())
	{
		stat = true;
		return stat;
	}
	else
	{
		return stat;
	}

	delete rs;
	delete ps;
}

int CustomerAdd::insertAdmin(Admin* admin)
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("INSERT INTO admin VALUES (?, ?)");

	ps->setString(1, admin->username);
	ps->setString(2, admin->password);



	int status = ps->executeUpdate();

	delete ps;

	return status;
}

bool CustomerAdd::ServiceChoice(string servicetype, string column)
{
	bool stat = false;
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("SELECT * FROM service WHERE " + column + " = ?");

	ps->setString(1, servicetype);

	ResultSet* rs = ps->executeQuery();

	if (rs->next())
	{
		stat = true;
		return stat;
	}
	else
	{
		return stat;
	}

	delete rs;
	delete ps;
}

bool CustomerAdd::ServiceChoice1(string serviceid, string row)
{
	bool stat = false;
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("SELECT * FROM service WHERE " + row + " = ?");

	ps->setString(1, serviceid);

	ResultSet* rs = ps->executeQuery();

	if (rs->next())
	{
		stat = true;
		return stat;
	}
	else
	{
		return stat;
	}

	delete rs;
	delete ps;
}
bool CustomerAdd::CheckCar(string platenumber, string column)
{
	bool stat = false;
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("SELECT * FROM car WHERE " + column + " = ?");

	ps->setString(1, platenumber);

	ResultSet* rs = ps->executeQuery();

	if (rs->next())
	{
		stat = true;
		return stat;
	}
	else
	{
		return stat;
	}

	delete rs;
	delete ps;
}
