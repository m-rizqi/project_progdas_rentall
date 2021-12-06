#include <fstream>
#include <sstream>
#include <string>
#include "../../include/controller/CustomerController.h"

/**
 * Controller implementation
 */

/**
 * constructor
 */
CustomerController::CustomerController() {}

/**
 * function to register a customer
 */
void CustomerController::registerCustomer()
{
    string name, address, phone, KTP_number;
    printf("------------------------------\n");
    printf("Form Customer Baru\n");
    printf("------------------------------\n");
    printf("Nama lengkap : \n");
    getline(cin, name);
    printf("Alamat (Format : Kabupaten, Provinsi) : \n");
    getline(cin, address);
    printf("Nomor handphone (Format 62XXXXXXXX: ) : \n");
    getline(cin, phone);
    printf("Nomor KTP / NIK : \n");
    getline(cin, KTP_number);
    printf("------------------------------\n");
    Customer customer = Customer(0, name, address, phone, KTP_number);
    CustomerRepository().appendData(customer);
    printf("-- customer berhasil disimpan! --");
}

/**
 * function to edit and save a customer
 */
void CustomerController::updateCustomer()
{
}

/**
 * function to delete a customer
 */
void CustomerController::deleteCustomer()
{
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
}