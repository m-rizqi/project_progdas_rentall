#include <fstream>
#include <sstream>
#include <string>
#include <conio.h>
#include <iostream>
#include "../../include/controller/RentFormController.h"
using namespace std;

RentFormController::RentFormController()
{
    this->rentRepository = RentRepository();
}

void RentFormController::rentCar(){
    long customerId, carId;
    string destination, expRentDate, expreturn; 
        cout <<  "   Formulir Penyewaan SEWA.in \n";
        cout << " ================================== \n";
        cout << " Silahkan Isi Formulir Di Bawah Ini\n";
        cout << "Customer Id \t\t\t\t : ";
        cin >> customerId;
        cout << "Car Id \t\t\t\t\t : ";
        cin >> carId;
        cout << "Destinasi \t\t\t\t : ";
        cin >> destination;
        cout << "Tanggal Sewa (dd-mm-yy)\t\t\t : ";
        cin >> expRentDate;
        cout << "Estimasi Tanggal Pengembalian (dd-mm-yy) : ";
        cin >> expreturn;
        cout << endl << endl;

        RentForm rentForm = RentForm (0, customerId, carId, destination, expRentDate, expreturn,"");
        rentRepository. appendData (rentForm);

        cout<< "Data Anda Telah Kami Simpan\n";

}

void RentFormController::returnCar() {
    string temp;
    long custId;
    RentForm oldForm;
    cout << "Formulin Pengembalian SEWA.in\n";
    cout << "==============================\n" ;
    cout << "Masukkan Customer Id Anda : "; 
    cin >> custId;
    vector<RentForm> result = rentRepository.searchByCustomerId (custId);
    if (result.size()==0){
        cout << "Customer Id Anda Tidak Ditemukan!\n";

    }
    else {
        oldForm = result.at(0);
        long customerId, carId, id;
        string destination, expRentDate, expreturn, retDate;
        cout << "Data Anda \n";
        oldForm.print();

        cout << "Masukkan Tanggal Pengembalian (dd-mm-yy) : ";
        cin >> retDate;
        cout << endl << endl;
        customerId = oldForm.getCustomerId();
        carId = oldForm.getCarId();
        destination = oldForm.getDestination();
        expRentDate = oldForm.getRentalDate();
        expreturn = oldForm.getExpectedReturnDate();
        id = oldForm.getId();

        RentForm newForm = RentForm (id, custId, carId, destination, expRentDate, expreturn, retDate);

        cout << "Konfirumasi Pengembalian Mobil Anda\n";
        newForm.print();

        cout << "Apakah Anda Yakin Akan Mengembalikan Mobil? (Tekan 'y' untuk ya, 'n' untuk tidak)  \n";
         while (true)
        {
            char key = getch();
            if (key =='y')
            {
                rentRepository.updateData(newForm);
                printf("-- Terimakasih Telah Menggunakan SEWA.in--\n");
                break;
            }
            else if (key == 'n')
            {
                printf("-- Pengembalian Mobil Batal --");
                break;
            }
        }
    
    }


    

}