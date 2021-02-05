#include <iostream>
#include <string>
#include <iomanip>
#include <conio.h>
#include <mysql.h>
#include <cstdlib>

using namespace std;

void CustomerRegister();
void AddCar();
void User();
void CustomerLogin();
void CustomerOption();
void AdminLogin();
void AdminRegister();
void AdminOption();
void CustomerDelete();
void CarDelete();
void ViewCar();
void ViewCarAll();
void ViewSpecificCustomer();
void ViewCustomerAll();
void ViewService();
void ServiceBook();
void ServiceDelete();
void ViewServiceAll();
void ServiceDisplay();
void ServiceCount();
void bookrules();
void ServicePaymentAll();
void ViewPayment();
void stats();



#include "Customer.h"
#include "CustomerAdd.h"
#include "Car.h"
#include "Service.h"
#include "ServiceCost.h"


int main()
{
	
	int choice=0;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~CAR SERVICE~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" << endl<<endl;
	cout << "\n1:Customer\n2:Admin\n3:Exit" << endl;
	cin >> choice;

	switch (choice)
	{
	case 1:
		User();
		break;
	
	case 2:
		AdminLogin();
		break;
	case 3:
		exit(0);
		break;
	}
}

void User()
{
	int choice = 0;
	cout << "\nHere are your options:\n1:Register\n2:Login\n3:Exit" << endl;
	cin >> choice;

	switch (choice)
	{
	case 1:
		CustomerRegister();
		break;

	case 2:
		CustomerLogin();
		break;
	case 3:
		exit(0);
		break;
	}
}

void AdminOption()
{
	int choice = 0;
	cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~CAR SERVICE ADMINISTRATION~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" << endl << endl;
	cout << "Here are your options:\n1: View all registered customers\n2: View the full details of a customer\n3: Delete a customer? \n4: View all the registered cars\n5: Delete a Car? \n6: View services booked\n7: Authorize service bookings" << endl;
	cout << "8: View All the service costs\n9: View the statistics\n10: Exit";
	cin >> choice;
	switch (choice)
	{
	case 1:
		ViewCustomerAll();
		break;
	case 2:
		ViewSpecificCustomer();
		break;
	case 3:
		CustomerDelete();
		break;
	case 4:
		ViewCarAll();
		break;
	case 5:
		CarDelete();
		break;
	case 6:
		ViewServiceAll();
		break;
	case 7:
		ServiceCount();
		break;
	case 8:
		ServicePaymentAll();
		break;
	case 9:
		stats();
		break;
	case 10:
		exit(0);
		break;
	}
}

void CustomerOption()
{
	int choice = 0;
	cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~CAR SERVICE~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" << endl << endl;
	cout << "\nWhat do you want to do?\n1: Add a new Car\n2: View your car details\n3: View the service schedule \n4: Book a service\n5: Delete a service\n6: View your booked Service" << endl;
	cout << "7: Check out your payments for your service\n8: exit the program\n\n" << endl;
	cin >> choice;

	switch (choice)
	{
	case 1:
		AddCar();
		break;
	case 2:
		ViewCar();
		break;
	case 3:
		ServiceDisplay();
		break;
	case 4:
		ServiceBook();
		break;
	case 5:
		ServiceDelete();
		break;
	case 6:
		ViewService();	
		break;
	case 7:
		ViewPayment();
		break;
	case 8:
		exit(0);
		break;
	}
}

void CustomerLogin()
{
		Customer* customer = new Customer();
		CustomerAdd login;
		string pass, search, column = "username";
		char back = '0';

		system("cls");
		cout << "[Log In]\n\n";

		cout << "Username: ";
		cin >> search;

		cout << "Password: \n";
		cin >> pass;

		bool stat = login.UserLogin(search, column);

		if (stat == false) {
			cout << "\n\n[Username is incorrect or doesn't exist]\n\nPress 1 to relogin\nPress 2 to go back\n";
			cin >> back;
			if (back == '1')
				CustomerLogin();
			if (back == '2')
				main();
		}
		column = "password";
		stat = login.UserLogin(pass, column);

		if (stat == false)
		{
			cout << "\n\n[Password is incorrect]\n\nPress 1 to relogin\nPress 2 to go back\n";
			cin >> back;
			if (back == '1')
				CustomerLogin();
			if (back == '2')
				main();
		}
		if (stat == true) 
		{
			CustomerOption();
		}
		
}

void AdminLogin()
{

	Admin* admin = new Admin();
	CustomerAdd login;
	string pass, search, column = "username";
	char choice = '0';

	system("cls");
	cout << "[Log In]\n\n";

	cout << "Username: ";
	cin >> search;

	cout << "Password: \n";
	cin >> pass;

	bool stat = login.AdminLogin(search, column);

	if (stat == false) {
		cout << "\n\n[Username is incorrect or doesn't exist]\n\nPress 1 to relogin\nPress 2 to go back\n";
		cin >> choice;
		if (choice == '1')
			AdminLogin();
		if (choice == '2')
			main();
	}
	column = "password";
	stat = login.AdminLogin(pass, column);

	if (stat == false) {
		cout << "\n\n[Password is incorrect]\n\nPress 1 to relogin\nPress 2 to go back\n";
		cin >> choice;
		if (choice == '1')
			AdminLogin();
		if (choice == '2')
			main();
	}
	if (stat == true)
	{
		AdminOption();
	}

}

void CustomerDelete()
{
	Customer* customer = new Customer();
	cout << "Delete:\n\n";
	cout << "Customer's username: ";

	getline(cin, customer->username);
	getline(cin, customer->username);



	CustomerAdd customerdel;
	int status = customerdel.deleteCustomer(customer);

	if (status != 0) {
		system("cls");
		cout << "[Successfully deleted a customer]\n\nPress enter to continue\n" << endl;
		AdminOption();
	}
	else {
		system("cls");
		cout << "[Unable to delete a customer]\n\nPress enter to continue\n" << endl;
		AdminOption();
	}
}

void CarDelete()
{
;	Car* car = new Car();
	CustomerAdd check;
	string search, column = "username";
	int choice;

	cout << "Please enter the owner of the car" << endl;

	cout << "Username: " << endl;
	cin >> search;


	bool stat = check.CheckCar(search, column);

	if (stat == true) {



		cout << "Delete:\n\n";
		cout << "Plate Number of the car: ";

		getline(cin, car->platenumber);
		getline(cin, car->platenumber);



		CustomerAdd cardel;
		int status = cardel.deleteCar(car);

		if (status != 0) {
			system("cls");
			cout << "[Successfully removed a car]\n\nPress enter to continue\n\n" << endl;
			AdminOption();
		}
		else {
			system("cls");
			cout << "[Unable to removed a car]\n\nPress enter to continue\n\n" << endl;
			AdminOption();
		}
	}
	if (stat == false)
	{
		cout << "The username is incorrect, press 1 to retry or 2 exit to menu\n" << endl;
		cin >> choice;
		if (choice == 1)
		{
			CarDelete();
		}
		if (choice == 2)
		{
			AdminOption();
		}
	}
}

void CustomerRegister()
{
	Customer* customer = new Customer();
	CustomerAdd login;
	string pass, search, column = "username";
	int choice;

	cout << "Please enter your details" << endl;

	cout << "username: " << endl;
	cin >> search;
	

	bool stat = login.UserLogin(search, column);

	if (stat == true) {
		cout << "\n\n[Username is already taken ]\n\nPress 1 to enter new username\nPress 2 to go back\n";
		cin >> choice;

		if (choice == '1') 
			CustomerRegister();
		else 
			main();
	}
	
	if (stat == false) 
	{
		customer->username = search;

		cout << "First Name: " << endl;
		getline(cin, customer->firstname);
		getline(cin, customer->firstname);

		cout << "Last Name: " << endl;
		getline(cin, customer->lastname);

		
		cout << "icnumber " << endl;
		getline(cin, customer->icnumber);

		
		cout << "phonenumber: " << endl;
		getline(cin, customer->phonenumber);

		cout << "adddress: " << endl;
		getline(cin, customer->address);

		cout << "password: " << endl;
		getline(cin, customer->password);


		CustomerAdd customerAdd;
		int status = customerAdd.insertCustomer(customer);

		if (status != 0)
			cout << "You are now already registered! You can now login into your account\n" << endl;
		else
			cout << "Unable to register" << endl;
		if (status != 0)
			User();
	}
}

void AdminRegister()
{
	Admin* admin = new Admin();

	cout << "Please enter your details" << endl;

	cout << "username: " << endl;
	getline(cin, admin->username);

	cout << "username: " << endl;
	getline(cin, admin->username);

	cout << "password " << endl;
	getline(cin, admin->password);


	CustomerAdd AdminAdd;
	int status = AdminAdd.insertAdmin(admin);

	if (status != 0)
		cout << "Successfully added a new admin" << endl;
	else
		cout << "Unable to add a new admin" << endl;

}

void AddCar()
{
	Car* car = new Car();
	CustomerAdd check;
	string search, column = "platenumber";
	int choice;

	cout << "Please enter your details accordingly" << endl;

	cout << "Your Car Plate Number " << endl;
	cin >> search;


	bool stat = check.CheckCar(search, column);

	if (stat == true) {
		cout << "\n\n[This Car is already registered, Pls press 1 to go back\n";
		cin >> choice;

		if (choice == '1')
			CustomerOption();
		else
			CustomerOption();
	}

	if (stat == false) {
		car->platenumber = search;

		cout << "The Name of your car: " << endl;
		getline(cin, car->carname);
		getline(cin, car->carname);

		cout << "The colour of your car: " << endl;
		getline(cin, car->carcolour);

		Customer* customer = new Customer();
		CustomerAdd login;
		string find, column = "username";

		cout << "Please enter your username to confirm ownership of this car" << endl;
		cin >> find;

		bool stat = login.UserLogin(find, column);
		if (stat == true)
		{
			car->username = find;
			car->carid;

			CustomerAdd carAdd;
			int status = carAdd.insertCar(car);

			if (status != 0) {
				cout << "You have Successfully added a new car\n" << endl;
				CustomerOption();
			}
			else {
				cout << "Unable to add a new car\n" << endl;
				CustomerOption();
			}
		}
		if (stat == false)
		{
			cout << "The username you have entered is wrong or the owner of the car is not yet registered, Please go back and register first if so" << endl;
			cout << "Press 1 to Retry or 2 to register or 3 to go back to menu\n" << endl;
			cin >> choice;
			if (choice == 1)
			{
				AddCar();
			}
			if (choice == 2)
			{

				main();
			}
			if (choice == 3)
			{
				CustomerOption();
			}

		}
	}
	
}

void ViewSpecificCustomer()
{

	CustomerAdd customerAdd;
	string username;

	cout << "Please enter the username of the customer you want to search:" << endl
		<< "Username:\t";
	getline(cin, username);
	getline(cin, username);

	Customer* customer = customerAdd.selectCustomer(username);

	cout << "\n\nThe details of the searched customer is\n " << "Username" << setw(20) <<"First Name"<<setw(20)<<"Last Name"<<setw(22)<< "IC Number" << setw(22) << "Phone Number" << setw(22) << "Address" << endl;
	cout<< customer->username << setw(20) << customer->firstname<<setw(20)<<customer->lastname<<setw(27)<<customer->icnumber << setw(20) << customer->phonenumber << setw(24) << customer->address << endl;
	cout << "\n" << endl;
	AdminOption();
}

void ViewCustomerAll()
{

	Customer* customer;
	CustomerAdd check;
	CustomerAdd chec;
	int num = 1;
	bool stat = false;

	cout << "\n\nThe registered customers are\n\n " << "|CUSTOMER ID|"<< setw(20)<< "|USERNAME|"<<setw(20)<<"|FIRST NAME|"<<setw(20)<<"|LAST NAME|"<<endl;

	while (num<40) {
		stat = check.validcustomer(num);
		if (stat == true) 
		{
			customer = chec.selectCustomerAll(num);
			cout << setw(10) << customer->customerid << setw(23) <<customer->username <<setw(18)<<customer->firstname<<setw(20)<<customer->lastname << endl;
			num++;
		}

		if (stat == false)
		{
			num++;
		}
	
	}
	

	cout << endl;
	AdminOption();

}

void ViewService()
{
	CustomerAdd serviceadd;
	int serviceid,choice;
	string num,status="pending";

	cout << "Please enter your car plate number " << endl;
	cout << "Plate Number: " << endl;
	cin >> num;

	cout << "\nPlease check if your service has already been approved or not in the service schedule" << endl;
	cout << "Has your service been approved? press 1 to check the details. \nPress 2 if for your service details if your service is still pending" << endl;
	cin >> choice;

	if (choice == 1) {
		Service* service = serviceadd.selectServiceid(num);
		cout << "\n\nThe details of the service booking is\n\n " << "|Service Type|" << setw(20) << "|Booking status|" << setw(20) << "|Service Id|" << setw(20) << "|Plate Number|" << setw(20) << "|Date|" << setw(20) << "|Time|" << endl;
		cout << setw(10) << service->servicetype << setw(20) << service->servicestatus << setw(20) << service->serviceid << setw(25) << service->platenumber << setw(20) << service->date << setw(20) << service->time << endl << endl;
		cout << "\n";
	}
	if (choice == 2) {
		Service* service = serviceadd.selectServiceidd(num,status);
		cout << "\n\nThe details of the service booking is\n\n " << "|Service Type|" << setw(20) << "|Booking status|" << setw(20) << "|Service Id|" << setw(20) << "|Plate Number|" << setw(20) << "|Date|" << setw(20) << "|Time|" << endl;
		cout << setw(10) << service->servicetype << setw(20) << service->servicestatus << setw(20) << service->serviceid << setw(25) << service->platenumber << setw(20) << service->date << setw(20) << service->time << endl << endl;
		cout << "\n";
	}
	//cin >> serviceid;


	//Service* service = serviceadd.selectService(serviceid);
	//cout << "The details of the service booking is\n\n " << "|Service Type|" << setw(20) << "|Booking status|" << setw(20) << "|Service Id|" << setw(20) << "|Plate Number|" <<setw(20)<<"|Date|"<<setw(20)<<"|Time|"<< endl;
	//cout << setw(10) << service->servicetype << setw(20) << service->servicestatus << setw(20) << service->serviceid << setw(25) << service->platenumber << setw(20) << service->date << setw(20) << service->time << endl << endl;
	//cout << "\n";
	CustomerOption();

}

void ViewServiceAll()
{
	Service* service;
	CustomerAdd check;
	int num=1;
	bool stat = false;

	cout << "\n\nThe details services booked are\n\n " << "|Service Type|" << setw(20) << "|Booking Status|" << setw(20) << "|Service Id|" << setw(20) << "|Plate Number|" << setw(20)<<"|Date|"<<setw(20)<<"|Time|"<< endl;
	
	while (num<50) 
	{
		stat = check.validservice(num);
		if (stat == true) {
			service = check.selectService(num);
			cout <<setw(10)<< service->servicetype << setw(20) << service->servicestatus << setw(20) << service->serviceid << setw(21) << service->platenumber << setw(23)<<service->date<<setw(22)<<service->time << endl;
			num++;
		}
		if (stat == false)
		{
			num++;
		}
		
	}

	cout <<"\n"<< endl;
	AdminOption();
	
}

void ServiceDisplay()
{
	Service* service;
	CustomerAdd check;
	int num = 1;
	bool stat = false;

	cout << "\n\nThe details of the service schedule is\n\n " <<"|Service Type|" << setw(20) << "|Booking Status|" << setw(15) <<"|Date|"<<setw(20)<< "|Time|" << endl;

	while (num < 50) {
		stat = check.validservice(num);
		if (stat == true) {
			service = check.selectService(num);
			cout <<setw(10)<< service->servicetype << setw(20) << service->servicestatus  << setw(20) << service->date<<setw(20)<< service->time << endl;
			num++;
		}
		if (stat == false)
		{
			num++;
		}

	}
	cout << "\n" << endl;
	CustomerOption();
}

void ViewCar()
{

	CustomerAdd caradd;
	string platenumber;

	cout << "Please enter number plate of the car you want to search:" << endl
		<< "Number Plate:\t";
	getline(cin, platenumber);
	getline(cin, platenumber);

	Car* car = caradd.selectCar(platenumber);
	cout << "\nThe details the searched car is\n\n " << "|PLATE NUMBER|" << setw(20) << "|CAR NAME|" << setw(20) << "|CAR COLOUR|" << endl;
	cout << setfill(' ') <<setw(10)<< car->platenumber << setw(22) << car->carname << setw(20)<<car->carcolour << endl;
	cout << "\n" << endl;
	CustomerOption();
}

void ViewCarAll()
{
	Car* car;
	CustomerAdd check;
	int num = 1;
	bool stat = false;

	cout << "\n\nThe details of all the registered cars are \n\n " << "|PLATE NUMBER|" << setw(20) << "|CAR NAME|" << setw(20) << "|CAR COLOUR|" << setw(20) << "|USERNAME|" << endl;

	while (num < 40) {
		stat = check.validcar(num);
		if (stat == true) {
			car = check.selectCarAll(num);
			cout << setfill(' ')<< setw(10) << car->platenumber << setw(22) << car->carname << setw(20) << car->carcolour << setw(20) << car->username << setw(30) << endl;
			num++;
		}
		if (stat == false)
		{
			num++;
		}
		
	}

	cout <<"\n"<< endl << endl;
	AdminOption();
}

void ServiceBook()
{
	Service* service = new Service();
	Car* car = new Car();
	CustomerAdd check;
	CustomerAdd serv;
	string pass, clock, date, search, row, columnn = "date", column = "platenumber";
	int choice,option;

	cout << "\n\nYou should read the rules for booking a service if you didn't already know" << endl;
	cout << "Press 1 to continue with the booking or 2 to read the rules before continuing\n" << endl;
	cin >> option;
	if (option == 1)
	{
		cout << "Your Car Plate Number " << endl;
		cin >> search;

		bool stat = check.CheckCar(search, column);

		if (stat == true)
		{

			cout << "Please enter the date you want to service your car, using the date format of DD/MM (example 20/1)" << endl;
			cin >> date;

			bool stat = serv.ServiceTime(date, columnn);
			if (stat == true)
			{

				columnn = "time";
				cout << "Please enter a time slot that has not already been taken, for example 9.00am or 1.00pm" << endl;
				cin >> clock;

				bool stat = serv.ServiceTime(clock, columnn);
				if (stat == true) {

					cout << "The time slot has already been booked, Please Enter another empty time slot" << endl;
					ServiceBook();
				}
				else

					cout << "The type of your service: " << endl;
				getline(cin, service->servicetype);
				int choice = 0;
				cout << "Select 1 or 2\n1 for major service or 2 for minor service " << endl;
				cin >> choice;

				if (choice == 1)
				{
					service->servicetype = "major";
				}
				else
				{
					service->servicetype = "minor";
				}

				service->servicestatus = "pending";
				service->platenumber = search;
				service->date = date;
				service->time = clock;



				CustomerAdd serviceAdd;
				int status = serviceAdd.insertService(service);

				if (status != 0) {
					cout << "Successfully added a new service\n" << endl;
					CustomerOption();
				}
				else {
					cout << "Unable to add a new service\n" << endl;
					CustomerOption();
				}
			}
			if (stat == false)
			{
				columnn = "time";
				cout << "Please enter a time slot that has not already been taken" << endl;
				cin >> clock;



				cout << "The type of your service: " << endl;
				getline(cin, service->servicetype);
				int choice = 0;
				cout << "Select 1 or 2\n1 for major service or 2 for minor service " << endl;
				cin >> choice;

				if (choice == 1)
				{
					service->servicetype = "major";
				}
				else
				{
					service->servicetype = "minor";
				}

				service->servicestatus = "pending";
				service->platenumber = search;
				service->date = date;
				service->time = clock;


				CustomerAdd serviceAdd;
				int status = serviceAdd.insertService(service);

				if (status != 0) {
					cout << "Successfully added a new service\n" << endl;
					cout << service->serviceid << endl;
					CustomerOption();
				}
				else {
					cout << "Unable to add a new service\n" << endl;
					CustomerOption();
				}
			}



		}
		else {
			cout << "Car doesnt exist, Please go back and register your car first before booking a service" << endl;
			CustomerOption();
		}
	}
	else
	bookrules();
}

//void servicetest()
//{
//	Service* service = new Service();
//	Car* car = new Car();
//	CustomerAdd check;
//	CustomerAdd checkone;
//	string search,row,column="platenumber";
//
//	cout << "Search platenumber" << endl;
//	cin >> search;
//
//	bool stat = check.ServiceCheckOne(search, column);
//	if (stat == true)
//	{
//		
//		row = "pending";
//
//		bool stat = checkone.ServiceCheck(row,search);
//		if (stat == true) {
//			cout << "YOur service already been booked" << endl;
//		}
//		else
//			cout << "hi" << endl;
//	}
//	else
//		cout << "hi" << endl;
//
//}

void ServiceDelete()
{
	Service* service = new Service();
	cout << "Delete:\n\n";
	cout << "Service id: ";

	cin >> service->serviceid;

	CustomerAdd servicedel;
	int status = servicedel.deleteService(service);

	if (status != 0) {
		system("cls");
		cout << "[Successfully deleted a service]\n\nPress enter to continue\n" << endl;
		CustomerOption();
	}
	else {
		system("cls");
		cout << "[Unable to delete a service]\n\nPress enter to continue\n" << endl;
		CustomerOption();
	}
}

//void ServiceTotal()
//{
//	ServiceCost* servicecost = new ServiceCost();
//	Service* service = new Service();
//	CustomerAdd cost;
//	string search1, row, column="serviceid";
//	int choice,calc=0,addcalc,total,servicetotal;
//	int num, additionalservice;
//
//	cout << "id"<<endl;
//		cin >> num;
//	bool stat = cost.ServiceChoice1(num);
//
//	if (stat == true) {
//		search1 = "major";
//		getline(cin, servicecost->majorservice);
//		getline(cin, servicecost->minorservice);
//		bool stat = cost.ServiceChoice(search1, num);
//
//		if (stat == true)
//		{
//			servicecost->majorservice = "major";
//			calc = 600;
//		}
//		else
//		{
//			servicecost->minorservice = "minor";
//			calc = 200;
//		}
//
//		cout << "Enter any additional service cost made" << endl;
//		cin >> addcalc;
//		additionalservice = addcalc;
//		servicecost->additionalservice;
//
//		total = calc + addcalc;
//		servicetotal = total;
//
//		servicecost->servicetotal;
//		servicecost->servicetotal;
//		AdminOption();
//	}
//	else
//	{
//		cout << "wrong service Id" << endl;
//		AdminOption();
//	}
//	AdminOption();
//}

void ServiceCount()
{
	Service* service;
	Servicecost* servicecost = new Servicecost();
	CustomerAdd check;
	int num;
	int cal, addi, total,choice;
	string type="major";
	bool stat = false;

	cout << "Please enter the Service ID of the service you want to authorize" << endl;
	cin >> num;
	
		stat = check.validservice(num);
		if (stat == true) {



			cout << "Was This a MINOR or MAJOR service" << endl;
			cout << "1 for MINOR OR 2 for MAJOR" << endl;
			cin >> choice;
			switch (choice) {
			case 1:
				servicecost->minorservice = "200";
				servicecost->majorservice = "-";
				cal = 200;
				break;
			case 2:
				servicecost->minorservice = "-";
				servicecost->majorservice = "600";
				cal = 600;
				break;
			}
			Service* service = new Service();
			cout << "Please enter any additional service costs" << endl;

			cout << "additional costs: " << endl;
			cin >> addi;
			servicecost->additionalservice = addi;

			servicecost->servicecostid = num;

			total = cal + addi;

			servicecost->servicetotal = total;


			CustomerAdd ServicecostAdd;
			int statu = ServicecostAdd.insertServiceCost(servicecost);

			if (statu != 0) {
				cout << "Successfully added a new service cost\n" << endl;
			}
			else {
			cout << "Unable to add a new service cost\n" << endl;
			AdminOption();
			}
			service->serviceid = num;

			service->servicestatus = "approved";
			CustomerAdd serviceup;
			int status = serviceup.updateservice(service);
			if (status != 0) {
				system("cls");
				cout << "[Successfully updated the service]\n" << endl;
				AdminOption();
			}
			else {
				system("cls");
				cout << "[Unable to update the service]\n" << endl;
				AdminOption();
			}
		}
		else
			cout << "The service ID you have entered is wrong, Please Re-Enter\n" << endl;
		ServiceCount();
	
}

//void ServiceUpdate()
//{
//	Service* service = new Service();
//	CustomerAdd check;
//
//	cout << "Enter the service ID" << endl;
//	cin >> service->serviceid;
//
//	 service->servicestatus = "approved";
//
//	CustomerAdd serviceup;
//	int status = serviceup.updateservice(service);
//
//	if (status != 0) {
//		system("cls");
//		cout << "[Successfully updated the service]" << endl;
//		AdminOption();
//	}
//	else {
//		system("cls");
//		cout << "[Unable to update the service]" << endl;
//		AdminOption();
//	}
//}
void bookrules() {

	cout << "[Welcome to your service booking, please note that each service time slot is hourly and is reserved for 1 customer]\n" << endl;
	cout << "[The first slot is 9.00am and the last is 4.00pm]\n" << endl;
	cout << "[Whoever books first will get their service booking reviewed for approval earlier]\n" << endl;
	cout << "[There may be only one service booking pending per time slot]\n" << endl;
	cout << "[If you booked the same service for your car twice or more there may be a penalty charged, So please check if you already have a service booking pending before entering multiple bookings.]\n" << endl;
	cout << "[Please enter your details accordingly, Any falsely entered details may result in your service booking being rejected]\n\n" << endl;

	ServiceBook();
}

void ServicePaymentAll()
{
	Servicecost* servicecost;
	CustomerAdd check;
	int num = 1;
	bool stat = false;

	cout << "\n\nThe costs of the  services are\n\n " << "|MINOR SERVICE|" << setw(20) << "|MAJOR SERVICE|" << setw(20) << "|ADDITIONAL SERVICE|" << setw(20) << "|SERVICE ID|" << setw(20) << "|SERVICE TOTAL|" << endl;

	while (num < 40)
	{
		stat = check.validcost(num);
		if (stat == true) {
			servicecost = check.selectCost(num);
			cout << setw(10) << servicecost->minorservice << setw(20) << servicecost->majorservice << setw(20) << servicecost->additionalservice << setw(21) << servicecost->servicecostid << setw(21) << servicecost->servicetotal << endl;
			num++;
		}
		if (stat == false)
		{
			num++;
		}

	}

	cout << "\n" << endl;
	AdminOption();

}

void ViewPayment()
{
	Servicecost* servicecost;
	CustomerAdd check;
	int num ;
	bool stat = false;

	cout << "Enter your service id" << endl;
	cin >> num;

	stat = check.validcostservice(num);
	if (stat == true) {
		cout << "\nThe costs of the services are\n\n " << "|MAJOR SERVICE|" << setw(20) << "|MINOR SERVICE|" << setw(25) << "|ADDITIONAL SERVICE|" << setw(20) << "|SERVICE ID|" << setw(20) << "|SERVICE TOTAL|" << endl;
		servicecost = check.selectServiceCost(num);
		cout << setw(10) << servicecost->minorservice << setw(20) << servicecost->majorservice << setw(20) << servicecost->additionalservice << setw(23) << servicecost->servicecostid << setw(21) << servicecost->servicetotal << endl;

	}
	else
	{
		cout << "The service either has not been approved or is invalid\n" << endl;
	}
	
	CustomerOption();
}

void stats()
{
	
		CustomerAdd check;
		cout << "\n\n[STATISTICS VIEWS]\n\n";
		cout << "Total registered customers: ";
		cout << check.Calculate("customer", "username");

		cout << "\n\nNumber of cars registered: ";
		cout << check.Calculate("car", "platenumber");

		cout << "\n\nTotal service bookings: ";
		cout << check.Calculate("service", "serviceid");

		cout << "\n\n" << endl;
	
		AdminOption();
}

//void Payment()
//{
//	Service* service;
//	Servicecost* servicecost= new Servicecost();
//	CustomerAdd check;
//	bool stat = false;
//	int num, choice;
//	
//	cout << "service id";
//	cin >> num;
//
//	servicecost->servicecostid = num;
//	servicecost->paymentstatus = "PAID";
//
//	
//	CustomerAdd serviceup;
//	int status = serviceup.updateservicecost(servicecost);
//	if (status != 0) {
//		system("cls");
//		cout << "[Successfully updated the service]\n" << endl;
//		AdminOption();
//	}
//	else {
//		system("cls");
//		cout << "[Unable to update the service]\n" << endl;
//		AdminOption();
//	}
//
//}