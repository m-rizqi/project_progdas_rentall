#include <iostream>
#include "../src/model/Customer.cpp"
using namespace std;

int main()
{
	Customer customer(1,"Muhammad Rizqi","Yogyakarta, Indonesia", "62123456789", "1234567890");
	customer.print();
}