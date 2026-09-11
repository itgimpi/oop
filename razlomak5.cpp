#include <iostream>
#include <numeric> 
#include <stdexcept>

class Razlomak {

private:
    int brojilac;
    int imenilac;

    // Privatna pomoćna funkcija za skraćivanje
    void skrati() {
        if (imenilac == 0) return;
        int nzd = std::gcd(brojilac, imenilac);
        brojilac /= nzd;
        imenilac /= nzd;
        if (imenilac < 0) {
            brojilac = -brojilac;
            imenilac = -imenilac;
        }
    }

public:
    // Konstruktor sa podrazumevanim vrednostima
    Razlomak(int br = 0, int im = 1) {
        if (im == 0) {
            throw std::invalid_argument("Imenilac ne sme biti nula!");
        }
        brojilac = br;
        imenilac = im;
        skrati(); 
    }

    // Get metode (ako zatreba čitanje vrednosti van klase, pošto su privatne)
    int getBrojilac() const { return brojilac; }
    int getImenilac() const { return imenilac; }

    // Operatori
    Razlomak operator+(const Razlomak& drugi) const {
        return Razlomak(brojilac * drugi.imenilac + drugi.brojilac * imenilac, imenilac * drugi.imenilac);
    }

    Razlomak operator-(const Razlomak& drugi) const {
        return Razlomak(brojilac * drugi.imenilac - drugi.brojilac * imenilac, imenilac * drugi.imenilac);
    }

    Razlomak operator*(const Razlomak& drugi) const {
        return Razlomak(brojilac * drugi.brojilac, imenilac * drugi.imenilac);
    }

    Razlomak operator/(const Razlomak& drugi) const {
        if (drugi.brojilac == 0) {
            throw std::invalid_argument("Deljenje nulom nije dozvoljeno!");
        }
        return Razlomak(brojilac * drugi.imenilac, imenilac * drugi.brojilac);
    }

    // Preopterećenje operatora << za ispis (sada bezbedno pristupa privatnim članovima)
    friend std::ostream& operator<<(std::ostream& os, const Razlomak& r) {
        os << r.brojilac << "/" << r.imenilac;
        return os;
    }

    // Preopterećenje operatora >> za unos
    friend std::istream& operator>>(std::istream& is, Razlomak& r) {
        std::cout << "Unesi brojilac ";
        is >> r.brojilac;
        std::cout << "Unesi imenilac ";
        is >> r.imenilac;

        if (r.imenilac == 0) {
            throw std::invalid_argument("Imenilac ne sme biti nula!");
        }

        r.skrati(); // Poziv privatne metode je dozvoljen unutar friend funkcije
        return is;
    }
};

int main() {
    try {
        Razlomak r1;
        
        std::cout << "Unos razlomka r1" << std::endl;
        std::cin >> r1;

        Razlomak r2(1, 4); // 1/4


        std::cout << "r1 = " << r1 << std::endl;
        std::cout << "r2 = " << r2 << std::endl;

        // Direktno računanje i ulančani ispis kroz cout <<
        std::cout << "Zbir: " << (r1 + r2) << std::endl;
        std::cout << "Proizvod: " << (r1 * r2) << std::endl;

        // r1.brojilac = 5; // GRESKA! Ovo više ne radi jer je "brojilac" privatni član.

    } catch (const std::invalid_argument& e) {
        std::cerr << "Greska: " << e.what() << std::endl;
    }

    return 0;
}
