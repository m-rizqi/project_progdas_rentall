#include <fstream>
#include <sstream>
#include <string>
#include <conio.h>
#include "../../include/controller/CustomerController.h"

/**
 * Controller implementation
 */

/**
 * constructor
 */
CustomerController::CustomerController()
{
    this->customerRepository = CustomerRepository();
}

/**
 * function to register a customer
 */
void CustomerController::registerCustomer()
{
    printf("-- R E G I S T E R   C U S T O M E R --\n");
    printf("Berapa customer yang ingin Anda masukkan? \n");
    int n;
    cin >> n;
    printf("Silahkan isi form berikut dengan benar\n");
    for (int i = 1; i <= n; i++)
    {
        string name, address, phone, KTP_number;
        printf("------------------------------\n");
        printf("Form Customer %d\n", i);
        printf("------------------------------\n");
        printf("Nama lengkap : ");
        getline(cin, name);
        getline(cin, name);
        printf("Alamat (Format : Kabupaten, Provinsi) : ");
        getline(cin, address);
        printf("Nomor handphone (Format 62XXXXXXXX: ) : ");
        getline(cin, phone);
        printf("Nomor KTP / NIK : ");
        getline(cin, KTP_number);
        printf("------------------------------\n");
        Customer customer = Customer(0, name, address, phone, KTP_number);
        customerRepository.appendData(customer);
        printf("-- customer berhasil disimpan! --\n\n");
    }
}

/**
 * function to edit and save a customer
 */
void CustomerController::updateCustomer()
{
    printf("--  U P D A T E   C U S T O M E R  --\n");
    printf("Update user berdasarkan : \n");
    printf("1. Id\n");
    printf("2. Nama\n");
    printf("Opsi yang dipilih : \n");
    string temp;
    int option;
    cin >> option;
    getline(cin, temp);
    Customer oldCustomer;
    switch (option)
    {
    case 1:
    {
        printf(">> Update berdasarkan Id\n");
        printf("Masukkan Id customer : \n");
        long id;
        cin >> id;
        getline(cin, temp);
        oldCustomer = customerRepository.findData(id);
    }
    break;
    case 2:
    {
        printf(">> Update berdasarkan nama\n");
        printf("Masukkan nama customer : \n");
        string _name;
        getline(cin, _name);
        vector<Customer> result = customerRepository.searchByName(_name);
        if(result.size() == 0){
            oldCustomer = result.at(0);
        }else{
            printf("!! Terdapat beberapa customer dengan nama yang sama !!\n");
            for(Customer c : result){
                c.print();
                printf("\n");
            }
            printf("Masukkan Id dari customer yang dimaksud!\n");
            long id;
            cin>>id;
            getline(cin, temp);
            oldCustomer = customerRepository.findData(id);
        }
    }
    break;
    default:
        break;
    }
    if (oldCustomer.getId() == 0)
    {
        printf("Maaf!, Customer tidak ditemukan\n");
    }
    else
    {
        string name, address, phone, KTP_number;
        printf("* Data Customer Lama\n");
        oldCustomer.print();
        printf("Apakah nama ingin diubah ? ...\n(Tekan \"y\" untuk yes, \"n\" untuk no)\n");
        while(true){
            char key = getch();
            if (key == 'y')
            {
                printf("Nama : ");
                getline(cin, name);
                break;
            }
            else if (key == 'n')
            {
                name = oldCustomer.getName();
                break;
            }
        }
        printf("Apakah alamat ingin diubah ? ...\n(Tekan \"y\" untuk yes, \"n\" untuk no)\n");
        while (true)
        {
            char key = getch();
            if (key == 'y')
            {
                printf("Alamat : ");
                getline(cin, address);
                break;
            }
            else if (key == 'n')
            {
                address = oldCustomer.getAddress();
                break;
            }
        }
        printf("Apakah nomor handphone ingin diubah ? ...\n(Tekan \"y\" untuk yes, \"n\" untuk no)\n");
        while (true)
        {
            char key = getch();
            if (key == 'y')
            {
                printf("Nomor Handphone : ");
                getline(cin, phone);
                break;
            }
            else if (key == 'n')
            {
                phone = oldCustomer.getPhone();
                break;
            }
        }
        printf("Apakah nomor KTP / NIK ingin diubah ? ...\n(Tekan \"y\" untuk yes, \"n\" untuk no)\n");
        while (true)
        {
            char key = getch();
            if (key == 'y')
            {
                printf("Nomor KTP / NIK : ");
                getline(cin, KTP_number);
                break;
            }
            else if (key == 'n')
            {
                KTP_number = oldCustomer.getKTPNumber();
                break;
            }
        }
        Customer newCustomer = Customer(oldCustomer.getId(), name, address, phone, KTP_number);
        printf("--- Konfirmasi ---\n");
        printf(">>> Data Customer Lama\n");
        oldCustomer.print();
        printf(">>> Data Customer Baru\n");
        newCustomer.print();
        printf("Tekan \"y\" untuk mengubah data...\n");
        printf("Tekan \"n\" untuk batal mengubah...\n");
        while (true)
        {
            char key = getch();
            if (key =='y')
            {
                customerRepository.updateData(newCustomer);
                printf("-- Data Customer Berhasil Diubah --");
                break;
            }
            else if (key == 'n')
            {
                printf("-- Data Customer Batal Diubah --");
                break;
            }
        }
    }
}

/**
 * function to delete a customer
 */
void CustomerController::deleteCustomer()
{
    printf("--  D E L E T E   C U S T O M E R  --\n");
    printf("Hapus user berdasarkan : \n");
    printf("1. Id\n");
    printf("2. Nama\n");
    printf("Opsi yang dipilih : \n");
    string temp;
    int option;
    cin >> option;
    getline(cin, temp);
    Customer customer;
    switch (option)
    {
    case 1:
    {
        printf(">> Update berdasarkan Id\n");
        printf("Masukkan Id customer : \n");
        long id;
        cin >> id;
        getline(cin, temp);
        customer = customerRepository.findData(id);
    }
    break;
    case 2:
    {
        printf(">> Update berdasarkan nama\n");
        printf("Masukkan nama customer : \n");
        string _name;
        getline(cin, _name);
        vector<Customer> result = customerRepository.searchByName(_name);
        if (result.size() == 0)
        {
            customer = result.at(0);
        }
        else
        {
            printf("!!! Terdapat beberapa customer dengan nama yang sama !!!\n");
            for (Customer c : result)
            {
                c.print();
                printf("\n");
            }
            printf("Pilih Id dari customer yang dimaksud!\n");
            long id;
            cin >> id;
            getline(cin, temp);
            customer = customerRepository.findData(id);
        }
    }
    break;
    default:
        break;
    }
    if (customer.getId() == 0)
    {
        printf("Maaf!, Customer tidak ditemukan\n");
    }else{
        printf("--- Konfirmasi ---\n");
        printf(">>> Data Customer\n");
        customer.print();
        printf("Tekan \"y\" untuk menghapus data...\n");
        printf("Tekan \"n\" untuk batal menghapus...\n");
        while (true)
        {
            char key = getch();
            if (key == 'y')
            {
                customerRepository.deleteData(customer.getId());
                printf("-- Data Customer Berhasil Dihapus --");
                break;
            }
            else if (key == 'n')
            {
                printf("-- Data Customer Batal Dihapus --");
                break;
            }
        }
    }
}

/**
 * function to show multiple customer
 */
void CustomerController::displayCustomers()
{

}

/**
 * function to show previous page of display customer
 */
void CustomerController::navigatePrevious()
{
}

/**
 * function to show next page of display customer
 */
void CustomerController::navigateNext()
{
}

/**
 * function to search one or multiple customer by condition
 */
void CustomerController::searchCustomer()
{
    printf("--  S E A R C H   C U S T O M E R  --\n");
    printf("Masukkan nama customer : \n");
    string name;
    getline(cin, name);
    vector<Customer> result = customerRepository.searchByName(name);
    printf("Hasil pencarian : \n");
    for(Customer c : result){
        c.print();
        printf("\n");
    }
}