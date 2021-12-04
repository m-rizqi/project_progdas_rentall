#include <iostream>
#include "../src/model/Customer.cpp"
#include "../src/repository/CustomerRepository.cpp"
using namespace std;

int main()
{
	CustomerRepository customerRepo = CustomerRepository();
	vector<Customer> customerList = customerRepo.readAllData();
	for (int i = 0; i < customerList.size(); i++)
	{
		customerList.at(i).print();
	}
	string name, address, phone, KTP_number;
	getline(cin, name);
	getline(cin, address);
	getline(cin, phone);
	getline(cin, KTP_number);

	Customer customer2(0, name, address, phone, KTP_number);
	customerRepo.appendData(customer2);
	customerList = customerRepo.readAllData();
	for (int i = 0; i < customerList.size(); i++)
	{
		customerList.at(i).print();
	}
}