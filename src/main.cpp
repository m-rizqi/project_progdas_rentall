#include <iostream>
#include "../src/model/Customer.cpp"
#include "../src/repository/CustomerRepository.cpp"
#include "../src/repository/CarRepository.cpp"
using namespace std;

int main()
{
	CarRepository carRepo = CarRepository();
	vector<Car> carList = carRepo.readAllData();
	for (int i = 0; i < carList.size(); i++)
	{
		carList.at(i).print();
	}
	// cout<<customerList.size();
	// string name, address, phone, KTP_number, id;
	// getline(cin, id);
	// getline(cin, name);
	// getline(cin, address);
	// getline(cin, phone);
	// getline(cin, KTP_number);

	// Customer customer2(1, "name", "address", "phone", "KTP_number");
	// customerRepo.appendData(customer2);
	// customerList = customerRepo.readAllData();
	// for (int i = 0; i < customerList.size(); i++)
	// {
	// 	customerList.at(i).print();
	// }
	// customerRepo.findData(1).print();
	// customerRepo.deleteData(1);
}