#include <iostream>
#include <string>
#include <vector>

class Djak {
    /* Ako bi atributi (kao što su prosek ili ocene) bili javni (public), 
    bilo ko bi mogao da ih promeni direktno iz main funkcije na pogrešan način.*/
private:
    // Privatni atributi - dostupni samo unutar klase
    std::string ime;
    std::string prezime;
    int razred;
    int odeljenje;
    bool eks;

public:
    /* Metode i konstruktori moraju biti public 
    jer oni predstavljaju "daljinski upravljač" za našu klasu. 
    Da bi neko u main funkciji uopšte mogao da koristi našu klasu, 
    te funkcije moraju biti vidljive spolja.*/
    
    // Konstruktor - postavlja početne vrednosti
    /* Kompajler kreira promenljive i odmah ih u istom trenutku inicijalizuje na 0 i 0.0. 
    Ovo je efikasnije i brže, posebno kod kompleksnijih tipova podataka.*/
    
    // Konstruktor
    Djak() : razred(0), odeljenje(0), eks(false) {}

    // Metoda za unos podataka
    void unos() {
        std::cout << "Unesite ime djaka: ";
        std::cin >> ime;
        
        std::cout << "Unesite prezime djaka: ";
        std::cin >> prezime;
        
        std::cout << "Unesite razred: ";
        std::cin >> razred;
        
        std::cout << "Unesite odeljenje: ";
        std::cin >> odeljenje;
        

        
        std::cout << "da li je bio "; 
        std::string bio; std::cin >> bio;
        if (bio == "da") eks = true;
        else eks = false;
    }

    // Metoda za ispis podataka (const označava da metoda ne menja objekat)
    void ispis() const {
        std::cout << "\n===== PODACI O DJAKU (KLASA) =====\n";
        std::cout << "Ime i prezime: " << ime << " " << prezime << "\n";
        std::cout << "Razred: " << razred << "\n";
        std::cout << "Razred: " << odeljenje << "\n";
        std::cout << "Eks: "; 
        if (eks) std::cout << "bio" << "\n";
        else std::cout << "nije" << "\n";        

        

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
