#include <iostream>

class Zivotinja {
public:
    // virtual omogućava polimorfizam
    virtual void zvuk() {
        std::cout << "Zivotinja proizvodi neki zvuk." << std::endl;
    } };

class Pas : public Zivotinja {
public:
    void zvuk() override {
        std::cout << "Pas laje: Av! Av!" << std::endl;
    } };

class Macka : public Zivotinja {
public:
    void zvuk() override {
        std::cout << "Macka mjauce: Mjau!" << std::endl;
    } };

int main() {
    Zivotinja* z;

    Zivotinja zz;
    Pas p;
    Macka m;

    // Pokazivač usmeravamo na Psa
    z = &p;
    z->zvuk(); // Štampa: Pas laje: Av! Av!

    // Isti taj pokazivač usmeravamo na Macku
    z = &m;
    z->zvuk(); // Štampa: Macka mjauce: Mjau!

    z = &zz;
    z->zvuk();
    return 0;
}
