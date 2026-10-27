#include <iostream>
#include <string>
#include <vector>

class Djak {
    /*Ako bi atributi (kao što su prosek ili ocene) bili javni (public), 
    bilo ko bi mogao da ih promeni direktno iz main funkcije na pogrešan način.*/
private:
    // Privatni atributi - dostupni samo unutar klase
    std::string ime;
    std::string prezime;
    int razred;
    std::vector<int> ocene;
    double prosek;

    // Privatna pomoćna metoda za računanje proseka
    void izracunajProsek() {
        if (ocene.empty()) {
            prosek = 0.0;
            return;
        }
        double suma = 0;
        for (int ocena : ocene) {
            suma += ocena;
        }
        prosek = suma / ocene.size();
    }

public:
    /* Metode i konstruktori moraju biti public 
    jer oni predstavljaju "daljinski upravljač" za našu klasu. 
    Da bi neko u main funkciji uopšte mogao da koristi našu klasu, 
    te funkcije moraju biti vidljive spolja.*/
    
    // Konstruktor - postavlja početne vrednosti
    /* Kompajler kreira promenljive i odmah ih u istom trenutku inicijalizuje na 0 i 0.0. 
    Ovo je efikasnije i brže, posebno kod kompleksnijih tipova podataka.*/
    
    Djak() : razred(0), prosek(0.0) {}

    // Metoda za unos podataka
    void unos() {
        std::cout << "Unesite ime djaka: ";
        std::cin >> ime;
        
        std::cout << "Unesite prezime djaka: ";
        std::cin >> prezime;
        
        std::cout << "Unesite razred: ";
        std::cin >> razred;
        
        int brojOcena;
        std::cout << "Koliko ocena zelite da unesete? ";
        std::cin >> brojOcena;
        
        ocene.resize(brojOcena);
        for (int i = 0; i < brojOcena; i++) {
            std::cout << "Unesite " << i + 1 << ". ocenu: ";
            std::cin >> ocene[i];
        }
        
        // Nakon unosa ocena, automatski računamo prosek
        izracunajProsek();
        std::cout << "------------------------------------\n";
    }

    // Metoda za ispis podataka (const označava da metoda ne menja objekat)
    void ispis() const {
        std::cout << "\n===== PODACI O DJAKU (KLASA) =====\n";
        std::cout << "Ime i prezime: " << ime << " " << prezime << "\n";
        std::cout << "Razred: " << razred << "\n";
        
        std::cout << "Ocene: ";
        for (int ocena : ocene) {
            std::cout << ocena << " ";
        }
        
        std::cout << "\nProsek ocena: " << prosek << "\n";
        std::cout << "==================================\n";
    }
};

int main() {
    // Pravljenje objekta klase Djak
    Djak ucenik;

    // Pozivanje metoda nad objektom
    ucenik.unos();
    ucenik.ispis();

    return 0;
}
