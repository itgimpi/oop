#include <iostream>
#include <string>

class Djak {
private:
    std::string ime;
    std::string prezime;
    int ocena;
    double prosek;
public:
    Djak() : ime(""), prezime(""), ocena(0), prosek(0.0) {}

    Djak(std::string ime2, std::string prezime2, int ocena2, double prosek2) {
        ime = ime2;
        prezime = prezime2;
        setOcena(ocena2);
        setProsek(prosek2); }
    /*Djak() {  // def. const. old way
        ime = ""; 
        prezime = ""; 
        ocena = 0;
        prosek = 0.0; }*/

    /*Djak(std::string ime, std::string prezime, int ocena, double prosek) {
        this->ime = ime;
        this->prezime = prezime;
        setOcena(ocena);
        setProsek(prosek); }

    Djak(std::string ime2, std::string prezime2, int ocena2, double prosek2) {
        ime = ime2;
        prezime = prezime2;
        setOcena(ocena2);
        setProsek(prosek2); }

    Djak(std::string ime2, std::string prezime2, int ocena2, double prosek2)
        : ime(ime2), prezime(prezime2), ocena(ocena2), prosek(prosek2){}

    Djak(std::string ime2, std::string prezime2, int ocena2, double prosek2) {
        ime = ime2;
        prezime = prezime2;
        ocena = ocena2;
        prosek = prosek2; }*/

    // Seteri
    void setIme(std::string ime2){
        ime = ime2; }
    void setPrezime(std::string prezime2) {
        prezime = prezime2; }
    void setOcena(int ocena2) {
        // ovde moze provera, da li je ocena od 1 do 5
        ocena = ocena2;     }
    void setProsek(double prosek2) {
        // provera
        prosek = prosek2;  }

    // Geteri
    std::string getIme() const {
        return ime;  }
    std::string getPrezime() const {
        return prezime;  }
    int getOcena() const {
        return ocena;     }
    double getProsek() const {
        return prosek;
    }
    
    void unos() {
        std::cout << "ime:";
        std::string ime2;
        std::cin >> ime2;
        setIme(ime2);

        std::cout << "prezime:";
        std::string prezime2;
        std::cin >> prezime2;
        setPrezime(prezime2);

        std::cout << "ocena:";
        int ocena2;
        std::cin >> ocena2;
        setOcena(ocena2);

        std::cout << "prosek:";
        double prosek2;
        std::cin >> prosek2;
        setProsek(prosek2);     }

    void ispis() const {
        std::cout << '\n' << getIme() << " " << getPrezime() << '\n';
        std::cout << getOcena() << '\n';
        std::cout << getProsek() << '\n'; 
    }

};

int main() {
    Djak d1;

    d1.unos();
    d1.ispis();

    Djak d2("Pera", "Peric", 5, 4.5);
    d2.ispis();
    
    



}