#include <iostream>
#include <numeric>

struct Razlomak {
    int brojilac;
    int imenilac;

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
    // r1 + r2 poziva r1.operator+(r2).
    // const garantuje da operacija neće promeniti originalne razlomke r1 i r2, 
    // samo kreira novi, treći kao rezultat.
    Razlomak operator+(const Razlomak& drugi) const {
        Razlomak rezultat;
        rezultat.brojilac = this->brojilac * drugi.imenilac + drugi.brojilac * this->imenilac;
        rezultat.imenilac = this->imenilac * drugi.imenilac;
        rezultat.skrati(); // Svaka operacija automatski poziva skrati() pre nego što vrati konačan rezultat
        return rezultat;
    }

    Razlomak operator-(const Razlomak& drugi) const {
        Razlomak rezultat;
        rezultat.brojilac = this->brojilac * drugi.imenilac - drugi.brojilac * this->imenilac;
        rezultat.imenilac = this->imenilac * drugi.imenilac;
        rezultat.skrati();
        return rezultat;
    }

    Razlomak operator*(const Razlomak& drugi) const {
        Razlomak rezultat;
        rezultat.brojilac = this->brojilac * drugi.brojilac;
        rezultat.imenilac = this->imenilac * drugi.imenilac;
        rezultat.skrati();
        return rezultat;
    }

    Razlomak operator/(const Razlomak& drugi) const {
        Razlomak rezultat;
        rezultat.brojilac = this->brojilac * drugi.imenilac;
        rezultat.imenilac = this->imenilac * drugi.brojilac;
        rezultat.skrati();
        return rezultat;
    }

    void ispis() const {
        std::cout << brojilac << "/" << imenilac << std::endl;     }
};

int main() {
    Razlomak r1 = {1, 2}; // r1 = 1/2
    Razlomak r2 = {1, 3}; // r2 = 1/3

    std::cout << "r1 je "; r1.ispis();
    std::cout << "r2 je "; r2.ispis();
    std::cout << std::endl;

    Razlomak zbir = r1 + r2;
    std::cout << "Zbir je "; zbir.ispis();

    Razlomak razlika = r1 - r2;
    std::cout << "Razlika "; razlika.ispis();

    Razlomak proizvod = r1 * r2;
    std::cout << "Proizvod "; proizvod.ispis();

    Razlomak kolicnik = r1 / r2;
    std::cout << "Kol... "; kolicnik.ispis();

    return 0; }
