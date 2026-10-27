#include <iostream>
#include <string>

// Bazna klasa
class Zivotinja {
public:
    std::string ime;

    // Funkcija koju imaju sve životinje
    void kako() {
        std::cout << "Ja sam zivotinja i zovem se " << ime << "." << std::endl;
    }
};

// Klasa Pas nasleđuje klasu Zivotinja
class Pas : public Zivotinja {
public:
    void glas() {
        std::cout << ime << " kaze: Av, av!" << std::endl;
    }
};

// Klasa Macka nasleđuje klasu Zivotinja
class Macka : public Zivotinja {
public:
    void glas() {
        std::cout << ime << " kaze: Mjau!" << std::endl;
    }
};

int main() {
    // Kreiramo objekat psa i dajemo mu ime
    Pas p1;
    p1.ime = "Beks";
    
    // Pas koristi funkciju iz bazne klase, a onda svoju funkciju
    p1.kako();
    p1.glas();

    std::cout << "------------------" << std::endl;

    // Kreiramo objekat mačke i dajemo joj ime
    Macka m1;
    m1.ime = "m1";
    
    // Mačka koristi funkciju iz bazne klase, a onda svoju funkciju
    m1.kako();
    m1.glas();

    return 0;
}
