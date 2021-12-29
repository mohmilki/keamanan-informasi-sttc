#include <iostream>
#include <sstream>
#include <iomanip>
#include <stdlib.h>

using namespace std;
int choice;
void menu_utama(){
	cout <<"========================================================================="<<endl;
 	cout <<"              KRIPTOGRAFI MODERN SEDERHANA X-OR CIPHER"<<endl;
  	cout <<"========================================================================="<<endl;
    cout << "1. Enkripsi\n2. Dekripsi\nPilih(1,2): ";
    cin >> choice;
    cin.ignore();
    system("cls");
}

void percabangan(){
	if (choice == 1){
    	cout << endl << "---Enkripsi---" << endl;
        string msg;
    	cout << "Masukkan Pesan: ";
    	getline(cin, msg);

    	string key;
    	cout << "Masukkan Kata Kunci: ";
    	getline(cin, key);
    	system("cls");

    	string encrypHexa = "";
    	int keyItr = 0;
    	stringstream res;
    	for (int i = 0; i < msg.length(); i++){
        	int temp = msg[i] ^ key[keyItr];

        	res << hex << setfill('0') << std::setw(2) << (int)temp;
        	keyItr++;
       			if (keyItr >= key.length()){
            	// setelah semua huruf kunci digunakan, ulangi kuncinya
            	keyItr = 0;
        }
    }

    res >> encrypHexa;
    cout << "Hasil Enkripsi Pesan: " << encrypHexa<<endl;
    cout <<"Apakah anda akan Enkripsi/Dekripsi lagi?(Y/N) :";
    char pilih;
    cin >> pilih;
	    if (pilih == 'Y' || pilih == 'y'){
	    	system("cls");
	    	menu_utama();
	    	percabangan();
	    }
	    else if (pilih == 'N' || pilih == 'n'){
	    	exit(0);
	    }else{
	    	exit(0);
	    }
    
    } else if (choice == 2){
        cout << endl << "---Dekripsi---" << endl;
        string msg;
    	cout << "Masukkan Pesan: ";
    	getline(cin, msg);

    	string key;
    	cout << "Masukkan kata kunci: ";
    	getline(cin, key);
    	system("cls");

    	string hexToUni = "";
    	for (int i = 0; i < msg.length()-1; i+=2){
        // membagi hex menjadi dua bagian
        	string output = msg.substr(i, 2);
        // mengubah hex menjadi unicode
        	int decimal = strtol(output.c_str(), NULL, 16);
        	hexToUni += (char)decimal;
    }

    string decrypText = "";
    int keyItr = 0;
    for (int i = 0; i < hexToUni.length(); i++){
        int temp = hexToUni[i] ^ key[keyItr];

        decrypText += (char)temp;
        keyItr++;
        if (keyItr >= key.length()){
            // setelah semua huruf kunci digunakan, ulangi kuncinya
            keyItr = 0;
        }
    }

    cout << "Hasil Dekripsi Pesan: " << decrypText<<endl;
    cout <<"Apakah anda akan Enkripsi/Dekripsi lagi?(Y/N) :";
	    char pilih;
	    cin >> pilih;
		    if (pilih == 'Y' || pilih == 'y'){
		    	system("cls");
		    	menu_utama();
		    	percabangan();
		    }
		    else if (pilih == 'N' || pilih == 'n'){
		    	exit(0);
		    }else{
		    	exit(0);
		    }
    } else {
        cout << endl << "Pilihan yang Anda Masukkan Salah" << endl;
    }

}
int main()
{
	menu_utama();
	percabangan();
}
