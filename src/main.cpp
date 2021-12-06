#include <iostream>
#include "../src/repository/CustomerRepository.cpp"
#include "../src/repository/CarRepository.cpp"
#include "../src/repository/RentRepository.cpp"
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
	for (int i = 0; i < customerList.size(); i++)
	{
		customerList.at(i).print();
	}
	printf("---------------------------------\n"); 
	// Update
	Customer customer2 = Customer(3, "Test #1", "City, Province", "62333333333","11111111111");
	customerRepo.updateData(customer2);
	// Read
	for (int i = 0; i < customerList.size(); i++)
	{
		customerList.at(i).print();
	}
	printf("---------------------------------\n");
	// Delete
	customerRepo.deleteData(3);
	// Read
	for (int i = 0; i < customerList.size(); i++)
	{
		customerList.at(i).print();
	}
	printf("---------------------------------\n");

	return 0;
}
	