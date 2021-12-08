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
        cout <<  " Formulir Penyewaan SEWA.in ";
        cout << " ================== ";
        cout << " Silahkan Isi Formulir Di Bawah Ini";
        cout << "Customer Id \t : ";
        cin >> customerId;
        cout << "Car Id \t : ";
        cin >> carId;
        cout << "Destinasi \t : ";
        cin >> destination;
        cout << "Tanggal Sewa \t : ";
        cin >> expRentDate;
        cout << "Lama Sewa \t : ";
        cin >> expreturn;

        RentForm rentForm = RentForm (0, customerId, carId, destination, expRentDate, expreturn,"");
        rentRepository. appendData (rentForm);

        cout<< "Data Anda Telah Kami Simpan";

}

void RentFormController::returnCar() {
    long custId;
    RentForm oldForm;
    cout << "Formulin Pengembalian SEWA.in";
    cout << "=============================";
    cout << "Masukkan Customer Id Anda \t : ";
    cin >> custId;
    vector<RentForm> result = rentRepository.searchByCustomerId (custId);
    if (result.size()==0){
        oldForm = result.at(0);
        long customerId, carId;
        string destination, expRentDate, expreturn, retDate;
        cout << "Data Anda \n";
        oldForm.print();

        cout << "Masukkan Tanggal Pengembalian";
        cin >> retDate;
        customerId = oldForm.getCustomerId();
        carId = oldForm.getCarId();
        destination = oldForm.getDestination();
        expRentDate = oldForm.getRentalDate();
        expreturn = oldForm.getExpectedReturnDate();

        RentForm newForm = RentForm (0, custId, carId, destination, expRentDate, expreturn, retDate);

        cout << "Konfirumasi Pengembalian Mobil Anda";
        newForm.print();
        cout << "Apakah Anda Yakin Akan Mengembalikan Mobil? (Tekan 'y' untuk ya, 'n' untuk tidak) ";
         while (true)
        {
            char key = getch();
            if (key =='y')
            {
                rentRepository.updateData(newForm);
                printf("-- Terimakasih Telah Menggunakan SEWA.in--");
                break;
            }
            else if (key == 'n')
            {
                printf("-- Pengembalian Mobil Batal --");
                break;
            }
        }

    }
    else {
        cout << "Customer Id Anda Tidak Ditemukan!";
    
    }
    

    
    

}