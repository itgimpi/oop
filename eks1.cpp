#include <iostream>
#include <string>

class Djak {
public: // SVI atributi i metode su javno dostupni, ne valja
    std::string ime;
    std::string prezime;
    int razred;
    int odeljenje;
    bool eks;

    // konstruktor bez parametara (podrazumevani konstruktor) za klasu Djak
    Djak() {
        razred = 0;
        odeljenje = 0;
        eks = false;
}

    // JAVNA metoda za unos podataka, OK
    void unos() {
        std::cout << "Unesite ime djaka: ";         std::cin >> ime;        
        std::cout << "Unesite prezime djaka: ";        std::cin >> prezime;        
        std::cout << "Unesite razred: ";        std::cin >> razred;
        std::cout << "Unesite odeljenje: ";        std::cin >> odeljenje;
        std::cout << "da li je bio "; 
        std::string bio; std::cin >> bio;
        if (bio == "da") eks = true;
        else eks = false;

    }

    // JAVNA metoda za ispis podataka
    void ispis() const {
        std::cout << "\n===== PODACI O DJAKU (SVE PUBLIC) =====\n";
        std::cout << "Ime i prezime: " << ime << " " << prezime << "\n";
        std::cout << "Razred: " << razred << "\n";
        std::cout << "Razred: " << razred << "\n";
        std::cout << "Eks: "; 
        if (eks) std::cout << "bio" << "\n";
        else std::cout << "nije" << "\n";
        

        
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
