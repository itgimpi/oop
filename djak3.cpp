#include <iostream>
#include <string>
#include <vector>

class Djak {
public: // SVI atributi i metode su javno dostupni, ne valja
    std::string ime;
    std::string prezime;
    int razred;
    std::vector<int> ocene;

    // Konstruktor
    Djak() {
    razred = 0;
}

    // JAVNA metoda za unos podataka, OK
    void unos() {
        std::cout << "Unesite ime djaka: ";         std::cin >> ime;        
        std::cout << "Unesite prezime djaka: ";        std::cin >> prezime;        
        std::cout << "Unesite razred: ";        std::cin >> razred;
        int brojOcena;        std::cout << "Koliko ocena zelite da unesete? ";        std::cin >> brojOcena;
        ocene.resize(brojOcena);
        for (int i = 0; i < brojOcena; i++) {
            std::cout << "Unesite " << i + 1 << ". ocenu: ";
            std::cin >> ocene[i];
        }
    }

    // JAVNA metoda za ispis podataka
    void ispis() const {
        std::cout << "\n===== PODACI O DJAKU (SVE PUBLIC) =====\n";
        std::cout << "Ime i prezime: " << ime << " " << prezime << "\n";
        std::cout << "Razred: " << razred << "\n";
        std::cout << "Ocene: ";
        for (int ocena : ocene) {
            std::cout << ocena << " ";
        }
    }
};

int main() {
    Djak ucenik;

    ucenik.unos();
    ucenik.ispis();

    // 2. Pošto je sve PUBLIC, možemo "nasilno" da promenimo podatke van funkcije:
    // PRIMER BANKOMAT
    std::cout << "\n--- Menjanje javnih podataka direktno u main-u ---\n";
    ucenik.ime = "Neko_Drugo_Ime"; // Menjamo ime bez ikakve kontrole
    //ucenik.prosek = 9.9;          // Upisujemo nemoguć prosek, kompajler to dozvoljava
    
    // Ponovni ispis da vidimo izmenjene podatke
    ucenik.ispis();

    return 0;
}
