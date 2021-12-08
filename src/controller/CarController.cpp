/**
 * Project Untitled
 */


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
    string temp;        //temp buat apa si?

    Car oldCar;         //??

    cout<< "-- U P D A T E  C A R --\n";
    cout<< "Update akan berjalan berdasarkan Id\n";
    cout<< "Silahkan masukkan Id : \n";
    long id;
    cin>> id;
    getline(cin, temp);
    
    oldCar = carRepository.findData(id);  // ini find data apa?

    if (oldCar.getId() == 0)
    {
        cout<< "Maaf, nomor polisi tidak ditemukan\n";
    }
    else
    {
        string nama_mobil;

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
    
    cout<< "Apakah nomor polisi dari mobil? (y untuk yes, n untuk no) : \n";
    while(true){
        char opsi = getch();
        if (opsi == 'y'){
            cout<< "Nomor polisi baru: ";
            long nomor_polisi;
            cin>> nomor_polisi;
            break;
        }
        else if (opsi == 'n'){
            long nomor_polisi;
            nomor_polisi = oldCar.getPoliceNumber(); // ini get apa
            break;
        }
    }

    Car newCar = Car(oldCar.getId() // ini fungsinya apa
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
    cout<< "Mobil akan dihapus berdasarkan nomor polisi\n";

    cout<< "Silahkan masukkan nomor polisi dari mobil yang ingin dihapus: \n";
    long nomor_polisi;
    cin>> nomor_polisi;
    cin>> temp;

    car = carRepository.findData(nomor_polisi);     //ini find data apa

    if (car.getId() == 0)   // get apaaa
    {
        cout<< "Maaf, nomor polisi tidak ditemukan\n";
    }
    else{
        cout<< "-- Konfirmasi --\n";
        cout<< " Silahkan dicek kembali data mobil yang ingin dihapus\n";
        car.print();

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
    vector<Cars> carList = carRepository.readAllData();
    entry = CarList.size() > entry ?  entry: CarList.size();
    int idx = 0;
    for(int i = idx; i < entry; i++){
     CarList.at(i).print();
    }


}// close program