#include <fstream>
#include <sstream>
#include <string>
#include <conio.h>
#include <iostream>
#include "../../include/controller/CarController.h"

/**
 * CarController implementation
 * 
 * Child class from Controller to handle about car
 */

CarController::CarController()
{
    this->carRepository = CarRepository();
}

void CarController::registerCar(){

    int n;

    cout<<"-- R E G I S T E R   C A R --\n";
    
    cout<<"Berapa Mobil yang ingin Anda dimasukkkan: \n";
    cin>>n;

    cout<<"Silahkan isi form berikut dengan benar\n";

    for(int i=1; i <= n; i++){

        string nama_mobil, nomor_polisi;
        bool rent_status;
        
        cout<<"Nama Mobil";
        cin>>nama_mobil;

        cout<<"Nomor Polisi: ";
        cin>>nomor_polisi;

        cout<<"Rented: ";
        cin>>rent_status;

        Car car = Car(0, nama_mobil, nomor_polisi, rent_status);
        carRepository.appendData(car);

        cout<<"Data sudah tersimpan";
    }

}   /**
    Function to edit a car  
    */
void CarController::updateCar(){

    //deklarasi di sini
    string temp;       
    Car oldCar;

    cout<< "-- U P D A T E  C A R --\n";
    cout<< "Update akan berjalan berdasarkan Id\n";
    cout<< "Silahkan masukkan Id : \n";
    long id;
    cin>> id;
    getline(cin, temp);
    
    oldCar = carRepository.findData(id);  // ini find data apa?
    string nama_mobil;
    if (oldCar.getId() == 0)
    {
        cout<< "Maaf, mobil tidak ditemukan\n";
    }
    else
    {
        cout<< "Data dari mobil lama\n";
        oldCar.print();
        
        cout<< "Data apa yang ingin diubah?\n";
        cout<< "Apakah nama mobil? (y untuk yes, n untuk no) : \n";
        while(true){
            char opsi = getch();
            if (opsi = 'y'){
                cout<< "Nama: ";
                cin>> nama_mobil;
                break;
            }
            else if (opsi == 'n'){
                nama_mobil = oldCar.getName(); // ini get apa
                break;
            }
        }
    } // dari else
    string nomor_polisi;
    cout<< "Apakah nomor polisi dari mobil? (y untuk yes, n untuk no) : \n";
    while(true){
        char opsi = getch();
        if (opsi == 'y'){
            cout<< "Nomor polisi baru: ";
            cin>> nomor_polisi;
            break;
        }
        else if (opsi == 'n'){
            nomor_polisi = oldCar.getPoliceNumber(); // ini get apa
            break;
        }
    }

    Car newCar = Car(oldCar.getId(),nama_mobil,nomor_polisi, oldCar.isRented());
    cout<< "--- Konfirmasi ---\n";
    cout<< "Silahkan dicek kembali datanya\n";
    cout<< "Data mobil lama\n";
    oldCar.print();

    cout<< "Data mobil yang baru\n";
    newCar.print();

    cout<<"Tekan y \t untuk mengubah data...\n";
    cout<<"Tekan n \t untuk batal mengubah...\n";
    while(true)
    {
        char opsi = getch();
        if (opsi == 'y'){
            carRepository.updateData(newCar);
            cout<<"=== Selamat! Data mobil berhasil diubah ===";
            break;
        }
        else if(opsi == 'n')
        {
            cout<< "--- Data mobil batal diubah";
            break;
        }
    }


}

/* function to delete a Car
 */
void CarController::deleteCar(){

    string temp;

    Car car;        // ini?

    cout<< "-- D E L E T E  C A R --\n";
    cout<< "Mobil akan dihapus berdasarkan Id\n";

    cout<< "Silahkan masukkan Id yang ingin dihapus: \n";
    long id;
    cin>> id;
    getline(cin, temp);

    car = carRepository.findData(id);     //bener ga ya

    if (car.getId() == 0) 
    {
        cout<< "Maaf, Id tidak ditemukan\n";
    }
    else{
        cout<< "-- Konfirmasi --\n";
        cout<< " Silahkan dicek kembali data mobil yang ingin dihapus\n";
        car.print();

        cout<< "Apakah anda sudah yakin dan ingin menghapus?";
        cout<< "Tekan y untuk menghapus data...\n";
        cout<< "Tekan n untuk batal menghapus...\n";
        while(true){
            char opsi = getch();
            if (opsi == 'y'){
                carRepository.deleteData(car.getId());  //ini get apaa
                cout<< "=== Selamat! Data mobil berhasil dihapus === ";
                break;
            }
            else if (opsi == 'n'){
                cout<< "--- Data mobil batal dihapus ---";
                break;
            }
        }
    }

}// close program

/*
 *function to show multiple cars
 */
void CarController::displayCars(int entry) // belum selesai gaess
{
    system("CLS");
    string temp;
    
    cout<<"-- D I S P L A Y  C A R S --\n";
    cout<<"----------------------------\n";
    vector<Car> carList = carRepository.readAllData();
    entry = carList.size() > entry ?  entry: carList.size();
    int idx = 0;
    for(int i = idx; i < entry; i++){
    carList.at(i).print();
    }
    cout<<"===================================\n";
    cout<< "%d car/page                page: 1\n", entry;
    cout<< "\nOpsi lainnya : \n";
    cout<< "1. previous page\n";
    cout<< "2. next page\n";
    cout<< "3. stop display\n";
    
    cout<< "Silahkan pilih opsi: ";     
    int option;
    cin>> option;
    getline(cin,temp);
    switch (option)
    {
        case 1:
        navigatePrevious(entry, idx, carList);
        break;

        case 2:
        navigateNext(entry, idx, carList);
        break;
        
        default:
        break;
    }

}// close program

/**
 * function to show previous page of display car
 */
void CarController::navigatePrevious(int entry, int idx, vector<Car> carList)
{
    system("CLS");
    string temp;
    bool stop = false;
    while (!stop)
    {
        if ((idx - entry) >= 0)
        {
            idx -= entry;
            for (int i = idx; i < idx + entry; i++)
            {
                carList.at(i).print();
            }
        }
        else
        {
            for (int i = 0; i < (entry > carList.size() ? carList.size() : entry); i++)
            {
                carList.at(i).print();
            }
            printf("\nAnda berada di page pertama. Pilih opsi lainnya !!\n\n");
        }
        printf("---------------------------------------\n");
        printf("%d cars/page                 page : %d\n", entry, ((idx / entry) + 1));
        printf("\nOpsi lainnya : \n");
        printf("1. previous page\n");
        printf("2. next page\n");
        printf("3. stop display\n");
        printf("Opsi yang dipilih\n");
        int option;
        cin >> option;
        getline(cin, temp);
        switch (option)
        {
        case 1:
            navigatePrevious(entry, idx, carList);
            break;
        case 2:
            navigateNext(entry, idx, carList);
            break;
        default:
            stop = true;
            break;
        }
    }
}

/**
 * function to show next page of display car
 */
void CarController::navigateNext(int entry, int idx, vector<Car> carList)
{
    system("CLS");
    string temp;
    bool stop = false;
    while (!stop)
    {
        if ((idx + entry) < carList.size())
        {
            idx += entry;
            for (int i = idx; i < entry + idx; i++)
            {
                carList.at(i).print();
            }
        }
        else
        {
            for (int i = idx; i < carList.size(); i++)
            {
                carList.at(i).print();
            }
            printf("\nAnda berada di page terakhir. Pilih opsi lainnya !!\n\n");
        }
        printf("---------------------------------------\n");
        printf("%d customers/page              page : %d\n", entry, ((idx / entry) + 1));
        printf("\nOpsi lainnya : \n");
        printf("1. previous page\n");
        printf("2. next page\n");
        printf("3. stop display\n");
        printf("Opsi yang dipilih\n");
        int option;
        cin >> option;
        getline(cin, temp);
        switch (option)
        {
        case 1:
            navigatePrevious(entry, idx, carList);
            break;
        case 2:
            navigateNext(entry, idx, carList);
            break;
        default:
            stop = true;
            break;
        }
    }
}

/**
 * function to search one or multiple car by condition
 */
void CarController::searchCar()
{
    printf("--  S E A R C H   C A R  --\n");
    printf("Masukkan nama mobil : \n");
    string name;
    getline(cin, name);
    vector<Car> result = carRepository.searchByName(name);
    printf("Hasil pencarian : \n");
    for (Car c : result)
    {
        c.print();
        printf("\n");
    }
}