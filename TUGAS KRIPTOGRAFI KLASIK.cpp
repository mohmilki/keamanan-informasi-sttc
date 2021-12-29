#include <iostream>
#include <cstdlib>
using namespace std;
int choice;
void nama_fungsi(){
  cout <<"========================================================================="<<endl;
  cout <<"          KRIPTOGRAFI SEDERHANA SUBSTITUSI CAESAR CIPHER"<<endl;
  cout <<"========================================================================="<<endl;
  cout << "1. Enkripsi" << endl << "2. Dekripsi" << endl << "Silahkan Pilih(1,2): ";
  cin >> choice;
  cin.ignore();
  system("cls");
}

void percabangan(){
  if (choice == 1){
        // enkripsi
        string msg;
        cout << "Pesan hanya dalam bentuk alfabet" << endl;
        cout << "Masukkan Pesan :";
        getline(cin, msg);

        int key;
        cout << "Masukkan kunci Perulangan (0-25): ";
        cin >> key;
        cin.ignore();
        system("cls");

        string encryptedText = msg;

        for (int i = 0; i < msg.size(); i ++){

            if(msg[i]==32){
                continue; //32 merupakan karakter spasi pada ASCII
            } else {

                if((msg[i]+key) > 122) {
                    //setelah huruf kecil dari z kembali lagi ke  a, kode z ASCII 122
                    int temp = (msg[i] + key) - 122;
                    encryptedText[i] = 96 + temp; // 96 merupakan katakter ` sebelum a
                } else if (msg[i] + key > 90 && msg[i] <= 96){ // 90 Merupakan huruf Z kapital
                    //setelah huruf besar Z kembali lagi ke A, 90 merupakan Z pada ASCII
                    int temp = (msg[i] + key) - 90;
                    encryptedText[i] = 64 + temp; //64 merupakan karakter @ sebelum A kapital
                } else {
                    //merupakan karater ketika diantara A-Z & a-z
                    encryptedText[i] += key;
                }

            } //if
        } // for

        cout << "Hasil enkripsi pesan :" << encryptedText<<endl;
        cout << "Apakah akan enkripsi/dekripsi lagi? Y/N" << endl;
        char pilih;
        cin >> pilih;
        if (pilih == 'Y' || pilih == 'y'){
          system("cls");
		  nama_fungsi();
          percabangan();
        }
        else if (pilih == 'n' || pilih == 'N'){
          cout << "Keluar dari aplikasi";
          exit(0);
        }
        else{
          exit(0);
        }

    } else if (choice == 2){
        //dekripsi

        string encpMsg;
        cout << "Pesan hanya dalam bentuk alfabet" << endl;
        cout << "Masukkan pesan enkripsi: ";
        getline(cin, encpMsg);

        int dcyptKey;
        cout << "Masukkan kunci (0-25): ";
        cin >> dcyptKey;
        cin.ignore();
        system("cls");

        string decryptedText = encpMsg;

        for (int i = 0; i < encpMsg.size(); i++){
            if(encpMsg[i]==32){
                continue; //melewatkan karakter spasi
            } else {
                if((encpMsg[i] - dcyptKey) < 97 && (encpMsg[i] - dcyptKey) > 90){ // 97 huruf a kecil, 90 Z kapital
                    int temp = (encpMsg[i] - dcyptKey) + 26;
                    decryptedText[i] = temp;
                } else if((encpMsg[i] - dcyptKey) < 65){
                    int temp = (encpMsg[i] - dcyptKey) + 26;
                    decryptedText[i] = temp;
                } else {
                    decryptedText[i] = encpMsg[i] - dcyptKey;
                }
            }
        }

        cout << "Hasil dekripsi Pesan :" << decryptedText << endl;
        cout << "Apakah akan enkripsi/dekripsi lagi? Y/N" << endl;
        char pilih;
        cin >> pilih;
        if (pilih == 'Y' || pilih == 'y'){
          system("cls");
		  nama_fungsi();
          percabangan();
        }
        else if (pilih == 'n' || pilih == 'N'){
          cout << "Keluar dari aplikasi";
          exit(0);
        }
        else{
          exit(0);
        }

    } else {
        cout << "Pilihan yang anda masukkan salah"<<endl;
          nama_fungsi();
          percabangan();
    }
}

int main() {
  
  nama_fungsi();
  percabangan();
} 
