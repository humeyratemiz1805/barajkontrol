/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;


int yukseklikbelirle(double rezerv) {
    if (rezerv < 30000)
        return 1;   
    else if (rezerv <= 70000)
        return 2;   
    else
        return 3;  
}


string modAdi(int mod) {
    if (mod == 1) return "Acil";
    if (mod == 2) return "Tasarruf";
    return "Normal";
}


string yorum(double gun) {
    if (gun > 100) return "Sürdürülebilir Seviye";
    else if (gun >= 50) return "İyileştirme Gerekiyor";
    else return "Acil Önlem Alınmalı";
}

int main() {

    ifstream veri("veri1.txt");
    ofstream cikti("GrupX_sonuclar.txt");

    if (!veri.is_open()) {
        cout << "veri1.txt bulunamadi!" << endl;
        return 0;
    }

    string sehir;
    double rezerv, tuketim, yagis, buhar;

    while (veri >> sehir >> rezerv >> tuketim >> yagis >> buhar) {

        int mod = yukseklikbelirle(rezerv);
        string modisim = modAdi(mod);


        double net = tuketim - yagis + (rezerv * buhar);


        double gun = rezerv / net;


        string oneri = yorum(gun);

        cout << "Şehir: " << sehir << endl;
        cout << "Mod: " << modisim << endl;
        cout << "Günlük Net Tüketim: " << net << " m³" << endl;
        cout << "Dayanma Süresi: " << gun << " gün" << endl;
        cout << "Öneri: " << oneri << endl;
        cout << "------------------------------------\n";

        cikti << sehir << " "
              << modisim << " "
              << net << " "
              << gun << " "
              << oneri << endl;
    }

    cout << "\nÇıktı kaydedildi: GrupX_sonuclar.txt\n";

    return 0;
}
