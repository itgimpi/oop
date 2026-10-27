#include <iostream>
#include <string>
#include <vector>

struct Djak {
    std::string ime;    
    std::string prezime;
    int razred; 
    int odeljenje;
    std::vector<int> ocene; };

int main() {
    Djak noviDjak;     // Kreiranje i inicijalizacija jednog objekta strukture
    noviDjak.ime = "Marko";    
    noviDjak.prezime = "Markovic";
    noviDjak.razred = 3;    
    noviDjak.odeljenje = 5;
    noviDjak.ocene = {5, 4, 5, 5, 4};

    // Ispis podataka o đaku
    std::cout << "Podaci o djaku:" << std::endl;
    std::cout << "Ime: " << noviDjak.ime << " Prezime: " << noviDjak.prezime << "\n";
    std::cout << "Razred: " << noviDjak.razred <<'\n';
    std::cout << "odeljenje: " << noviDjak.odeljenje << '\n';
    std::cout << "Ocene: ";
    for (auto o : noviDjak.ocene) std::cout << o << ' ';

    return 0;
}
