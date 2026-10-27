#include <iostream>
#include <string>
#include <vector>

struct Djak {
    std::string ime;    std::string prezime;
    int razred; int odeljenje;
    std::vector<int> ocene;
    double prosek; };

void unosDjaka(Djak &d) {
    std::cout << "Unesite ime djaka: ";     std::cin >> d.ime;
    std::cout << "Unesite prezime djaka: ";     std::cin >> d.prezime;
    std::cout << "Unesite razred i odeljenje: ";     std::cin >> d.razred; std::cin >> d.odeljenje;
    int brojOcena;     std::cout << "broj ocena? ";     std::cin >> brojOcena;
    d.ocene.resize(brojOcena);
    for(int i = 0; i < brojOcena; i++) {
        std::cin >> d.ocene[i]; }
}

// Funkcija za ispis podataka o đaku
void ispisDjaka(const Djak &d) {
    std::cout << "Podaci o djaku " << "\n";
    std::cout << "Ime i prezime: " << d.ime << " " << d.prezime << "\n";
    std::cout << "Razred: " << d.razred << ' ' << d.odeljenje << "\n";
    
    for(int ocena : d.ocene) {
        std::cout << ocena << " ";     }
    
    /*std::cout << "\nProsek ocena: " << d.prosek << "\n";
    std::cout << "==========================\n";*/
}

int main() {
    Djak djak;
    unosDjaka(djak);
    ispisDjaka(djak);

    return 0; }
