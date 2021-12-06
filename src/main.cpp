#include <iostream>
#include "../src/repository/CustomerRepository.cpp"
#include "../src/repository/CarRepository.cpp"
#include "../src/repository/RentRepository.cpp"
#include "../src/controller/CustomerController.cpp"
using namespace std;

int main()
{
	// Unit Test Customer Repository
	CustomerRepository customerRepo = CustomerRepository();
	// Read
	vector<Customer> customerList = customerRepo.readAllData();
	for (int i = 0; i < customerList.size(); i++)
	{
		customerList.at(i).print();
	}
	printf("---------------------------------\n");
	// Create
	Customer customer1 = Customer(3,"Test #1", "City, Province", "62182238","23482347892");
	customerRepo.appendData(customer1);
	// Read
	customerList = customerRepo.readAllData();
	for (int i = 0; i < customerList.size(); i++)
	{
		customerList.at(i).print();
	}
	printf("---------------------------------\n"); 
	// Update
	Customer customer2 = Customer(3, "Test #1", "City, Province", "62333333333","11111111111");
	customerRepo.updateData(customer2);
	// Read
	customerList = customerRepo.readAllData();
	for (int i = 0; i < customerList.size(); i++)
	{
		customerList.at(i).print();
	}
	printf("---------------------------------\n");
	// Delete
	customerRepo.deleteData(3);
	// Read
	customerList = customerRepo.readAllData();
	for (int i = 0; i < customerList.size(); i++)
	{
		customerList.at(i).print();
	}
	printf("---------------------------------\n");
	// Search By Name
	customerRepo.searchByName("Muhammad Rizqi").print();
	printf("---------------------------------\n");


	// Unit Test Car Repository
	CarRepository carRepo = CarRepository();
	// Read
	vector<Car> carList = carRepo.readAllData();
	for (int i = 0; i < carList.size(); i++)
	{
		carList.at(i).print();
	}
	printf("---------------------------------\n");
	// Create
	Car car1 = Car(3, "Test #1", "AA1111BB", false);
	carRepo.appendData(car1);
	// Read
	carList = carRepo.readAllData();
	for (int i = 0; i < carList.size(); i++)
	{
		carList.at(i).print();
	}
	printf("---------------------------------\n");
	// Update
	Car car2 = Car(3, "Test #2", "CC2222DD", true);
	carRepo.updateData(car2);
	// Read
	carList = carRepo.readAllData();
	for (int i = 0; i < carList.size(); i++)
	{
		carList.at(i).print();
	}
	printf("---------------------------------\n");
	// Delete
	carRepo.deleteData(3);
	// Read
	carList = carRepo.readAllData();
	for (int i = 0; i < carList.size(); i++)
	{
		carList.at(i).print();
	}
	printf("---------------------------------\n");
	// Search By Name
	carRepo.searchByName("Gatau Merek Mobil").print();
	printf("---------------------------------\n");

	// Unit Test RentForm Repository
	RentRepository rentformRepo = RentRepository();
	// Read
	vector<RentForm> rentformList = rentformRepo.readAllData();
	for (int i = 0; i < rentformList.size(); i++)
	{
		rentformList.at(i).print();
	}
	printf("---------------------------------\n");
	// Create
	RentForm rentform1 = RentForm(2, 1, 1, "Sleman, Yogyakarta", "2021-12-6", "2021-12-10", "");
	rentformRepo.appendData(rentform1);
	// Read
	rentformList = rentformRepo.readAllData();
	for (int i = 0; i < rentformList.size(); i++)
	{
		rentformList.at(i).print();
	}
	printf("---------------------------------\n");
	// Update
	RentForm rentform2 = RentForm(2, 1, 1, "Sleman, Yogyakarta", "2021-12-6", "2021-12-10", "2022-2-1");
	rentformRepo.updateData(rentform2);
	// Read
	rentformList = rentformRepo.readAllData();
	for (int i = 0; i < rentformList.size(); i++)
	{
		rentformList.at(i).print();
	}
	printf("---------------------------------\n");
	// Delete
	rentformRepo.deleteData(3);
	// Read
	rentformList = rentformRepo.readAllData();
	for (int i = 0; i < rentformList.size(); i++)
	{
		rentformList.at(i).print();
	}
	printf("---------------------------------\n");
	// Search By Customer Id
	for (RentForm rF : rentformRepo.searchByCustomerId(1)){
		rF.print();
	}
		printf("---------------------------------\n");
	// Search By Car Id
		for (RentForm rF : rentformRepo.searchByCarId(1))
		{
			rF.print();
		}
	printf("---------------------------------\n");
	// Search By Rental Date
	for (RentForm rF : rentformRepo.searchByRentalDate("2021-12-6"))
	{
		rF.print();
	}
	printf("---------------------------------\n");
	// Search By Expected Return Date
	for (RentForm rF : rentformRepo.searchByExpectedReturnDate("2021-12-31"))
	{
		rF.print();
	}
	printf("---------------------------------\n");
	// Search By Return Date
	for (RentForm rF : rentformRepo.searchByReturnDate("2022-2-1"))
	{
		rF.print();
	}
	printf("---------------------------------\n");

	// Unit Test Customer Controller
	// Register new Customer
	CustomerController custController = CustomerController();
	// custController.registerCustomer();

	// Update Customer
	custController.updateCustomer();

	return 0;
}
	