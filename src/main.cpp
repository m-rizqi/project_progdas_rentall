#include <iostream>
#include "../src/model/Customer.cpp"
#include "../src/repository/CustomerRepository.cpp"
using namespace std;

int main()
{
	Customer customer(1,"Muhammad Rizqi","Yogyakarta, Indonesia", "62123456789", "1234567890");
	customer.print();
	CustomerRepository *customerRepo = CustomerRepository::getInstance();
	vector<Customer> customerList = customerRepo->readCustomerFile();
	for (int i = 0; i < customerList.size(); i++)
	{
		customerList.at(i).print();
	}
}