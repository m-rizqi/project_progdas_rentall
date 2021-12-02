#include <iostream>
#include "../src/model/Customer.cpp"
#include "../src/repository/CustomerRepository.cpp"
using namespace std;

int main()
{
	// Customer customer(1,"Muhammad Rizqi","Yogyakarta, Indonesia", "62123456789", "1234567890");
	// customer.print();
	CustomerRepository *customerRepo = CustomerRepository::getInstance();
	vector<Customer> customerList = customerRepo->readObjectFile();
	for (int i = 0; i < customerList.size(); i++)
	{
		customerList.at(i).print();
	}
	// string id, name, address, phone, KTP_number;
	// getline(cin, id);
	// getline(cin, name);
	// getline(cin, address);
	// getline(cin, phone);
	// getline(cin, KTP_number);

	// Customer customer2(stol(id), name, address, phone, KTP_number);
	// customerRepo->writeCustomerFile(customer2);
	// customerList = customerRepo->readCustomerFile();
	// for (int i = 0; i < customerList.size(); i++)
	// {
	// 	customerList.at(i).print();
	// }
}