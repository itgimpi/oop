#include <iostream>
#include <string>

// BAZNA KLASA - Sva vozila imaju ovo
class Vozilo {
public:
    std::string marka;
    void trubi() {
        std::cout << marka << " svira: Bi-bip!" << std::endl;     }
};

class Automobil : public Vozilo { // 1. IZVEDENA KLASA: Automobil
public:
    int brojVrata;

    void info() {
        std::cout << "Ovo je automobil " << marka << " sa " << brojVrata << " vrata." << std::endl;
    }
};

// 2. IZVEDENA KLASA: Kamion
class Kamion : public Vozilo {
public:
    int nosivost; // u tonama

    void info() {
        std::cout << "Kamion " << marka << " je infoo " << nosivost << " tona tereta." << std::endl;
    }
};

// 3. IZVEDENA KLASA: Motocikl
class Motocikl : public Vozilo {
public:
    bool imaPrikolicu;

    void info() {
        std::cout << "Motocikl " << marka;
        if (imaPrikolicu) {
            std::cout << " ima bocnu prikolicu." << std::endl;
        } else {
            std::cout << " nema prikolicu." << std::endl;
        }
    }
};

int main() {
    // Pravimo automobil
    Automobil auto1;
    auto1.marka = "Peugeot";
    auto1.brojVrata = 3;
    auto1.info();
    auto1.trubi(); // Nasleđeno

    std::cout << "-----------------------------------" << std::endl;

    // Pravimo kamion
    Kamion kamion1;
    kamion1.marka = "Volvo";
    kamion1.nosivost = 20;
    kamion1.info();
    kamion1.trubi(); // Nasleđeno

    std::cout << "-----------------------------------" << std::endl;

    // Pravimo motocikl
    Motocikl moto1;
    moto1.marka = "Yamaha";
    moto1.imaPrikolicu = false;
    moto1.info();
    moto1.trubi(); // Nasleđeno

    return 0;
}
