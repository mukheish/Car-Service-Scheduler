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
	PreparedStatement* ps = dbConn.prepareStatement("INSERT INTO customer VALUES (?, ?, ?, ?, ?, ?, ?, ?)");

	ps->setString(1, customer->username);
	ps->setString(2, customer->firstname);
	ps->setString(3, customer->lastname);
	ps->setString(4, customer->icnumber);
	ps->setString(5, customer->phonenumber);
	ps->setString(6, customer->address);
	ps->setString(7, customer->password);
	ps->setInt(8, customer->customerid);
	

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
		customer->firstname = rs->getString(2);
		customer->lastname = rs->getString(3);
		customer->icnumber = rs->getString(4);
		customer->phonenumber = rs->getString(5);
		customer->address = rs->getString(6);

	}

	delete rs;
	delete ps;

	return customer;
}

Customer* CustomerAdd::selectCustomerAll(int customerid)
{
	Customer* customer = NULL;
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("SELECT * FROM customer WHERE customerid = ?");

	ps->setInt(1, customerid);

	ResultSet* rs = ps->executeQuery();

	if (rs->next())
	{
		customer = new Customer();

		customer->username = rs->getString(1);
		customer->firstname = rs->getString(2);
		customer->lastname = rs->getString(3);
		customer->icnumber = rs->getString(4);
		customer->phonenumber = rs->getString(5);
		customer->address = rs->getString(6);
		customer->password = rs->getString(7);
		customer->customerid = rs->getInt(8);

	}

	delete rs;
	delete ps;

	return customer;
}


int CustomerAdd::insertCar(Car* car)
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("INSERT INTO car VALUES (?, ?, ?, ?, ?)");

	ps->setString(1, car->platenumber);
	ps->setString(2, car->carname);
	ps->setString(3, car->carcolour);
	ps->setString(4, car->username);
	ps->setInt(5, car->carid);

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
		car->username = rs->getString(4);
		car->carid = rs->getInt(5);
		
	}
	else
	{
		cout << "NO";
	}

	delete rs;
	delete ps;

	return car;
}

Car* CustomerAdd::selectCarAll(int carid)
{
	Car* car = NULL;
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("SELECT * FROM car WHERE carid = ?");

	ps->setInt(1, carid);

	ResultSet* rs = ps->executeQuery();

	if (rs->next())
	{
		car = new Car();

		car->platenumber = rs->getString(1);
		car->carname = rs->getString(2);
		car->carcolour = rs->getString(3);
		car->username = rs->getString(4);
		car->carid = rs->getInt(5);

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
	PreparedStatement* ps = dbConn.prepareStatement("INSERT INTO service VALUES (?, ?, ?, ?, ?, ?)");

	ps->setString(1, service->servicetype);
	ps->setString(2, service->servicestatus);
	ps->setInt(3, service->serviceid);
	ps->setString(4, service->platenumber);
	ps->setString(5, service->date);
	ps->setString(6, service->time);

	int status = ps->executeUpdate();

	delete ps;

	return status;
}

int CustomerAdd::deleteService(Service* service)
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("DELETE FROM service WHERE serviceid=?;");

	ps->setInt(1, service->serviceid);

	int status = ps->executeUpdate();

	delete ps;

	return status;
}


Service* CustomerAdd::selectService(int serviceid)
{
	Service* service = NULL;
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("SELECT * FROM service WHERE serviceid = ?");

	ps->setInt(1, serviceid);

	ResultSet* rs = ps->executeQuery();

	if (rs->next())
	{
		service = new Service();

		service->servicetype = rs->getString(1);
		service->servicestatus= rs->getString(2);
		service->serviceid = rs->getInt(3);
		service->platenumber = rs->getString(4);
		service->date = rs->getString(5);
		service->time = rs->getString(6);

	}

	delete rs;
	delete ps;

	return service;
}

Service* CustomerAdd::selectServiceid(string platenumber)
{
	Service* service = NULL;
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("SELECT * FROM service WHERE platenumber = ?");

	ps->setString(1, platenumber);

	ResultSet* rs = ps->executeQuery();

	if (rs->next())
	{
		service = new Service();

		service->servicetype = rs->getString(1);
		service->servicestatus = rs->getString(2);
		service->serviceid = rs->getInt(3);
		service->platenumber = rs->getString(4);
		service->date = rs->getString(5);
		service->time = rs->getString(6);

	}

	delete rs;
	delete ps;

	return service;
}

Service* CustomerAdd::selectServiceidd(string platenumber ,string servicestatus)
{
	Service* service = NULL;
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("SELECT * FROM service WHERE (platenumber = ? AND servicestatus= ?)");

	ps->setString(1, platenumber);
	ps->setString(2, servicestatus);
	

	ResultSet* rs = ps->executeQuery();

	if (rs->next())
	{
		service = new Service();

		service->servicetype = rs->getString(1);
		service->servicestatus = rs->getString(2);
		service->serviceid = rs->getInt(3);
		service->platenumber = rs->getString(4);
		service->date = rs->getString(5);
		service->time = rs->getString(6);

	}

	delete rs;
	delete ps;

	return service;
}

bool CustomerAdd::validservice(int serviceid) 
{
	bool stat = false;
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("SELECT * FROM service WHERE  serviceid = ?");

	ps->setInt(1, serviceid);

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

bool CustomerAdd::validcar(int carid)
{
	bool stat = false;
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("SELECT * FROM car WHERE  carid = ?");

	ps->setInt(1, carid);

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

int CustomerAdd::insertServiceCost(Servicecost* servicecost)
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("INSERT INTO servicecost VALUES (?, ?, ?, ?, ?, ?)");

	ps->setString(1, servicecost->minorservice);
	ps->setString(2, servicecost->majorservice);	
	ps->setInt(3, servicecost->additionalservice);
	ps->setInt(4, servicecost->servicecostid);
	ps->setInt(5, servicecost->servicetotal);
	ps->setInt(6, servicecost->costid);


	int status = ps->executeUpdate();

	delete ps;

	return status;
}

int CustomerAdd::deleteServiceCost(Servicecost* servicecost)
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("DELETE FROM servicecost WHERE servicecostid=?;");

	ps->setInt(1, servicecost->servicecostid);

	int status = ps->executeUpdate();

	delete ps;

	return status;
}

Servicecost* CustomerAdd::selectServiceCost(int servicecostid)
{
	Servicecost* servicecost = NULL;
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("SELECT * FROM servicecost WHERE servicecostid = ?");

	ps->setInt(1, servicecostid);

	ResultSet* rs = ps->executeQuery();

	if (rs->next())
	{
		servicecost = new Servicecost();

		servicecost->majorservice = rs->getString(1);
		servicecost->minorservice = rs->getString(2);
		servicecost->additionalservice = rs->getInt(3);
		servicecost->servicecostid = rs->getInt(4);
		servicecost->servicetotal = rs->getInt(5);
		servicecost->costid = rs->getInt(6);

	}

	delete rs;
	delete ps;

	return servicecost;
}

Servicecost* CustomerAdd::selectCost(int costid)
{
	Servicecost* servicecost=NULL;
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("SELECT * FROM servicecost WHERE costid = ?");

	ps->setInt(1, costid);

	ResultSet* rs = ps->executeQuery();

	if (rs->next())
	{
		servicecost = new Servicecost();

		servicecost->majorservice = rs->getString(1);
		servicecost->minorservice = rs->getString(2);
		servicecost->additionalservice = rs->getInt(3);
		servicecost->servicecostid = rs->getInt(4);
		servicecost->servicetotal = rs->getInt(5);
		servicecost->costid = rs->getInt(6);

	}

	delete rs;
	delete ps;

	return servicecost;
}



bool CustomerAdd::validcost(int costid)
{
	bool stat = false;
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("SELECT * FROM servicecost WHERE  costid = ?");

	ps->setInt(1, costid);

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

bool CustomerAdd::validcostservice(int servicecostid)
{
	bool stat = false;
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("SELECT * FROM servicecost WHERE servicecostid = ?");

	ps->setInt(1, servicecostid);

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

bool CustomerAdd::validcustomer(int customerid)
{
	bool stat = false;
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("SELECT * FROM customer WHERE  customerid = ?");

	ps->setInt(1, customerid);

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

bool CustomerAdd::ServiceCheckOne(string servicestatus, string column)
{
	bool stat = false;
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("SELECT * FROM service WHERE " + column + " = ?");

	ps->setString(1, servicestatus);

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

bool CustomerAdd::ServiceCheck(string servicestatus, string row)
{
	bool stat = false;
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("SELECT * FROM service WHERE " + row + " = ?");

	ps->setString(1, servicestatus);

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

bool CustomerAdd::ServiceChoice(int serviceid, string servicetype)
{
	bool stat = false;
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("SELECT * FROM service WHERE  (serviceid =? AND  servicetype= ?)");

	ps->setInt(1, serviceid);
	ps->setString(2, servicetype);

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

bool CustomerAdd::ServiceTime(string date, string column)
{
	bool stat = false;
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("SELECT * FROM service WHERE " + column + " = ?");

	ps->setString(1, date);

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

int CustomerAdd::Calculate(string table, string column)
{
	int num = 0;
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("SELECT COUNT(" + column + ") FROM " + table);

	ResultSet* rs = ps->executeQuery();

	if (rs->next())
	{
		num = rs->getInt(1);
	}

	delete rs;
	delete ps;

	return num;
}

//int CustomerAdd::updateservice(Service* service) {
//
//	DatabaseConnection dbConn;
//	PreparedStatement* ps = dbConn.prepareStatement("INSERT INTO service VALUES (?, ?, ?, ?, ?, ?) WHERE serviceid=?");
//
//	ps->setInt(1, service->serviceid);
//	ps->setString(2, service->servicestatus);
//	ps->setString(3, service->servicestatus);
//	ps->setString(4, service->servicestatus);
//	ps->setString(5, service->servicestatus);
//	ps->setString(6, service->servicestatus);
//
//	ps->executeUpdate();
//
//}

int CustomerAdd::updateservice(Service* service)
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("UPDATE service SET servicestatus=? WHERE serviceid=?;");

	ps->setString(1, service->servicestatus);
	ps->setInt(2, service->serviceid);

	int status = ps->executeUpdate();

	delete ps;

	return status;
}

int CustomerAdd::updateservicecost(Servicecost* servicecost)
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("UPDATE service SET paymentstatus=? WHERE servicecostid=?;");

	ps->setString(1, servicecost->paymentstatus);
	ps->setInt(2, servicecost->servicecostid);

	int status = ps->executeUpdate();

	delete ps;

	return status;
}
