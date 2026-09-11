#include <iostream>
#include <numeric>   
#include <stdexcept> 

class Razlomak {
public:
    int brojilac;
    int imenilac;

    Razlomak(int br = 0, int im = 1) {
        if (im == 0) {
            throw std::invalid_argument("Imenilac ne sme biti nula!");
        }
        brojilac = br;
        imenilac = im;
        skrati(); 
    }

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

    // Preopterećenje operatora << za ispis (cout << r)
    friend std::ostream& operator<<(std::ostream& os, const Razlomak& r) {
        os << r.brojilac << "/" << r.imenilac;
        return os; // Vraćamo tok (stream) da bismo omogućili ulančavanje (npr. cout << r1 << r2)
    }

    // Preopterećenje operatora >> za unos (cin >> r)
    friend std::istream& operator>>(std::istream& is, Razlomak& r) {
        std::cout << "Unesite brojilac: ";
        is >> r.brojilac;
        std::cout << "Unesite imenilac: ";
        is >> r.imenilac;

        if (r.imenilac == 0) {
            throw std::invalid_argument("Imenilac ne sme biti nula!");
        }

        r.skrati(); // Automatski skraćujemo nakon unosa
        return is;
    }
};

int main() {
    try {
        Razlomak r1;
        
        std::cout << "razlomak r1 " << std::endl;
        std::cin >> r1;

        Razlomak r2(1, 3); // 1/3

        // Ispis razlomaka pomoću cout <<
        std::cout << std::endl;
        std::cout << "r1 je " << r1 << std::endl;
        std::cout << "r2 je " << r2 << std::endl;

        // Računanje i direktan ispis rezultata
        std::cout << r1 << " + " << r2 << " = " << (r1 + r2) << std::endl;
        std::cout << r1 << " * " << r2 << " = " << (r1 * r2) << std::endl;

    } catch (const std::invalid_argument& e) {
        std::cerr << "Greska: " << e.what() << std::endl;
    }

    return 0;
}
