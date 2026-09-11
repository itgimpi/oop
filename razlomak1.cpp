#include <iostream>
#include <numeric> // gcd

struct Razlomak {
    int brojilac;
    int imenilac;
};

void skrati(Razlomak& r) {
        if (r.imenilac == 0) return;
        int nzd = std::gcd(r.brojilac, r.imenilac);
        r.brojilac /= nzd;
        r.imenilac /= nzd;     }

Razlomak saberi(const Razlomak& a, const Razlomak& b) {
        Razlomak rezultat;
        rezultat.brojilac = a.brojilac * b.imenilac + b.brojilac * a.imenilac;
        rezultat.imenilac = a.imenilac * b.imenilac;
        skrati(rezultat); 
        return rezultat; }

Razlomak oduzmi(const Razlomak& a, const Razlomak& b) {
        Razlomak rezultat;
        rezultat.brojilac = a.brojilac * b.imenilac - b.brojilac * a.imenilac;
        rezultat.imenilac = a.imenilac * b.imenilac;
        skrati(rezultat);
        return rezultat; }

Razlomak pomnozi(const Razlomak& a, const Razlomak& b) {
        Razlomak rezultat;
        rezultat.brojilac = a.brojilac * b.brojilac;
        rezultat.imenilac = a.imenilac * b.imenilac;
        skrati(rezultat);
        return rezultat; }

Razlomak podeli(const Razlomak& a, const Razlomak& b) {
        Razlomak rezultat;
        rezultat.brojilac = a.brojilac * b.imenilac;
        rezultat.imenilac = a.imenilac * b.brojilac;
        skrati(rezultat);
        return rezultat; }


void ispis(Razlomak r) {
        std::cout << r.brojilac << "/" << r.imenilac << std::endl;     }

int main() {
    Razlomak r1 = {1, 2}; // r1 = 1/2
    Razlomak r2 = {1, 3}; // r2 = 1/3

    std::cout << "r1 je "; ispis(r1);
    std::cout << "r2 je "; ispis(r2);
    std::cout << std::endl;

    Razlomak zbir = saberi(r1, r2);
    std::cout << "Zbir je "; ispis(zbir);

    Razlomak razlika = oduzmi(r1, r2);
    std::cout << "Razlika ";  ispis(razlika);

    Razlomak proizvod = pomnozi(r1, r2);
    std::cout << "Proizvod "; ispis(proizvod);

    Razlomak kolicnik = podeli(r1, r2);
    std::cout << "Kol... "; ispis(kolicnik);

    return 0; }
