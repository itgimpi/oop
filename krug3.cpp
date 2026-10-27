#include <iostream>
#include <cmath>

// Klasa koja predstavlja tačku u 2D prostoru
class Tacka {
private:
    double x;
    double y;

public:
    // Konstruktor
    Tacka(double x = 0, double y = 0) : x(x), y(y) {}

    // Getter metode
    double getX() const { return x; }
    double getY() const { return y; }

    // Metoda za računanje rastojanja između dve tačke
    double rastojanjeDo(const Tacka& druga) const {
        return std::sqrt(std::pow(druga.x - this->x, 2) + std::pow(druga.y - this->y, 2));
    }
};

// Klasa koja predstavlja kružnicu
class Kruznica {
private:
    Tacka centar;  // Centar kružnice je objekat klase Tacka (Kompozicija)
    double radijus;

public:
    // Konstruktor
    Kruznica(Tacka c, double r) : centar(c) {
        radijus = (r > 0) ? r : 1.0;     }

    // Metoda za proveru položaja tačke u odnosu na kružnicu
    double getR() const { return radijus; }
    void proveri(const Tacka& t) const {
        double d = centar.rastojanjeDo(t); // Rastojanje od centra do tačke t

        std::cout << "Rastojanje od centra do tacke je: " << d << std::endl;

        if (std::abs(d - radijus) < 1e-9) { // Zbog preciznosti double tipa
            std::cout << "Tacka se nalazi NA kruznici." << std::endl;
        } else if (d < radijus) {
            std::cout << "Tacka se nalazi UNUTAR kruznice." << std::endl;
        } else {
            std::cout << "Tacka se nalazi VAN kruznice." << std::endl;         }    } };

int main() {
    // Definisanje centra i kreiranje kružnice
    Tacka centarKruga(0, 0); 
    double r = 5.0;
    Kruznica k(centarKruga, r);
    //Kruznica k((0, 0), 5);

    std::cout << centarKruga.getX() << centarKruga.getY() << k.getR() << "\n" << std::endl;

    // Testiranje različitih tačaka
    Tacka t1(3, 4);   // Rastojanje je koren(3^2 + 4^2) = 5 (Na kružnici)
    Tacka t2(1, 1);   // Rastojanje je koren(2) ≈ 1.41 (Unutar)
    Tacka t3(6, 0);   // Rastojanje je 6 (Van)

    std::cout << "Provera za tacku T1(3, 4):" << std::endl;
    k.proveri(t1);

    std::cout << "\nProvera za tacku T2(1, 1):" << std::endl;
    k.proveri(t2);

    std::cout << "\nProvera za tacku T3(6, 0):" << std::endl;
    k.proveri(t3);

    return 0;
}
