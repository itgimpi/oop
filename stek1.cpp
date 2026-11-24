#include <iostream>
// Stek sa statickim nizom
const int KAPACITET = 5;
class Stek {
private:
    int niz[KAPACITET];
    int vrh;
public:
    Stek(){
        vrh = -1; }
    // Da li je stek prazan?
    bool prazan() {
        //if ( vrh == -1 ) return true;
        //return false;
        return vrh == -1; }
    // Da li je pun?
    bool pun() {
        return vrh == KAPACITET-1; }
    // metod push
    void dodaj(int vrednost){
        // ako je niz pun?
        if ( pun() ) {
            std::cout << "Stek je pun, broj nije dodat!" << '\n';
            return;  }
        // nije pun?
        niz[++vrh] = vrednost; }
    // pop
    void izbaci(){
        if ( prazan() ) {
            std::cout << "Stek je prazan, nista nije izbaceno!";
            return; }
        vrh--; }
    int vr(){
        if ( prazan() ) {
            std::cout << "Nema nista na steku!" << '\n';
            return -1; }
        return niz[vrh];  }


 
};

int main() {
    Stek s;
    s.dodaj(10);
    s.dodaj(100);
    s.dodaj(1000);
    s.dodaj(10000);
    s.dodaj(100000);
    if (s.pun()) std::cout << "Pun je" << '\n';
    else std::cout << "Nije pun" << '\n';
    std::cout << s.vr() << '\n'; 
    s.dodaj(1000000);
    s.izbaci();s.izbaci();s.izbaci();s.izbaci();s.izbaci();
    std::cout << s.vr() << '\n'; 
    if (s.prazan()) std::cout << "Prazan je" << '\n';
    else std::cout << "Nije prazan" << '\n';
    
    
    return 0;
}
