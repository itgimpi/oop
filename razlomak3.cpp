#include <iostream>
#include <numeric>  
#include <stdexcept> 

class Razlomak {
public:
    // Podaci su javni i može im se pristupiti direktno van klase
    int brojilac;
    int imenilac;

    // Konstruktor sa podrazumevanim vrednostima
    Razlomak(int br = 0, int im = 1) {
        if (im == 0) 
            throw std::invalid_argument("Imenilac ne sme biti nula!");
        brojilac = br;
        imenilac = im;
        skrati(); 
    }

    // Javna funkcija za skraćivanje
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

    void ispis() const {
        std::cout << brojilac << "/" << imenilac << std::endl;
    }
};

int main() {
    try {
        Razlomak r1(1, 4); // 1/4
        Razlomak r2(2, 4); // 2/4 (automatski postaje 1/2 zbog konstruktora)

        // Pošto je sve public, možemo direktno da menjamo vrednosti (kao kod strukture)
        r1.brojilac = 3; // r1 je sada 3/4
        
        std::cout << "r1 = "; r1.ispis();
        std::cout << "r2 = "; r2.ispis();
        std::cout << std::endl;

        Razlomak zbir = r1 + r2;
        std::cout << "Zbir (3/4 + 1/2): "; zbir.ispis();

        Razlomak proizvod = r1 * r2;
        std::cout << "Proizvod (3/4 * 1/2): "; proizvod.ispis();

    } catch (const std::invalid_argument& e) {
        std::cerr << "Greska: " << e.what() << std::endl;
    }

    return 0;
}
