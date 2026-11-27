#include <iostream>
#include <string>
using namespace std;

class Osoba {
private:
    string ime;
    string prezime;
    const int godina;
    string adresa;
    string telefon;
    //int proveriGod(int g) {
    static int proveriGod(int g) {
        int tr = 2026;
        if (g > tr) {
            cout << "Ne valja godina!" << '\n';
            return tr;  }
        return g; }
public:
    Osoba( string ime, string prezime, int godina, string adresa, string telefon ):
            ime(ime), prezime(prezime),
            godina(godina),
            adresa(adresa), telefon(telefon) {}
    // geteri
    string getIme() const {return ime;}
    string getPrezime() const {return prezime;}
    int getGodina() const {return godina;}
    string getAdresa() const {return adresa;}
    string getTelefon() const {return telefon;}
    // metodi
    void promeniAdresu(const string &nova){
        if (!nova.empty())
            adresa = nova;
        else 
            cout << "Ne valja adresa\n";    }
    void promeniTelefon(const string &novi){
        if (novi.length() > 5)
            telefon = novi;
        else
            cout << "Br tel ne valja\n";  }
    
    void ispis() const {
        cout << ime << ' ' << prezime << '\n';
        cout << godina << '\n';
        cout << adresa << '\n';
        cout << telefon << '\n';
    }


};

int main() {
    Osoba o1("Pera","Peric",2000,"Srp. vladara 128","0123456789");
    Osoba o2("Mika","Mikic",2001,"qwertyuiop","76245762345");
    o1.ispis();
    o2.ispis();
    return 0;
}
