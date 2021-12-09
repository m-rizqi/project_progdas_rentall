#include <iostream>
#include "../src/controller/CustomerController.cpp"
#include "../src/controller/CarController.cpp"
#include "../src/controller/RentFormController.cpp"
using namespace std;

void menu()
{
	CustomerController custController = CustomerController();
	CarController carController = CarController();
	RentFormController rentformController = RentFormController();
	bool stop = false;
	while (!stop)
	{
		printf("S E W A . I N : Car Rent Management Program\n");
		printf("Menu : \n");
		printf("-----------------------\n");
		printf("1. Register Customer \n");
		printf("2. Update Customer \n");
		printf("3. Hapus Customer \n");
		printf("4. Lihat Customer \n");
		printf("5. Cari Customer \n");
		printf("-----------------------\n");
		printf("6. Register Mobil \n");
		printf("7. Update Mobil \n");
		printf("8. Hapus Mobil \n");
		printf("9. Lihat Mobil \n");
		printf("10. Cari Mobil \n");
		printf("-----------------------\n");
		printf("11. Sewa Mobil\n");
		printf("12. Pengembalian Mobil\n");
		printf("-----------------------\n");
		printf("13. Keluar\n");
		printf("\nMenu yang dipilih : ");
		string temp;
		getline(cin, temp);
		int option = stoi(temp);
		switch (option)
		{
		case 1:
			custController.registerCustomer();
			break;
		case 2:
			custController.updateCustomer();
			break;
		case 3:
			custController.deleteCustomer();
			break;
		case 4:
			custController.displayCustomers(3);
			break;
		case 5:
			custController.searchCustomer();
			break;
		case 6:
			carController.registerCar();
			break;
		case 7:
			carController.updateCar();
			break;
		case 8:
			carController.deleteCar();
			break;
		case 9:
			carController.displayCars(3);
			break;
		case 10:
			carController.searchCar();
			break;
		case 11:
			rentformController.rentCar();
			break;
		case 12:
			rentformController.returnCar();
			break;
		default:
			stop = true;
			break;
		}
	}
};

int main()
{
	menu();
	return 0;
}
