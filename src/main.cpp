#include <iostream>
#include "../src/model/Customer.cpp"
using namespace std;

int main()
{
	Customer customer;
	customer.setId(1);
	printf("%d", customer.getId());
}