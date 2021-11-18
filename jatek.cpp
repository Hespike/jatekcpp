#include <iostream>

using namespace std;

class Jatek {
    string gyarto;
    string nev;
    double meret;
    int ar;

    int eredetiAr;

public:
    Jatek() = default;

    Jatek(const string &gyarto, const string &nev, double meret, int ar) : gyarto(gyarto), nev(nev), meret(meret), ar(ar) {}

    void learazas(int learazas) {
        eredetiAr = ar;
        ar = ar * (100 - learazas) / 100;
    }

    void visszaallit() {
        ar = eredetiAr;
    }

    bool operator==(const Jatek& masik) const {
        return gyarto == masik.gyarto && nev == masik.nev;
    }

};

class Jatekkonyvtar{
    string jatekosnev;

    Jatek jatekok[100];
    int aktualis_meret;

public:
    Jatekkonyvtar(const string &jatekosnev) : jatekosnev(jatekosnev), aktualis_meret(0) {}

    Jatekkonyvtar& operator+=(const Jatek& jatek) {
        if (aktualis_meret < 100) {
            jatekok[aktualis_meret] = jatek;
            aktualis_meret++;
        }

        return *this;
    }

    Jatekkonyvtar& operator-=(const Jatek& jatek) {
        for (int i = 0; i < aktualis_meret; i++) {
            if (jatekok[i] == jatek) {
                for (int j = i; j < aktualis_meret-1; j++) {
                    jatekok[j] = jatekok[j+1];
                }
                aktualis_meret--;
                break;
            }
        }

        return *this;
    }

    const Jatek& operator[](unsigned int index) const {
        if (index < aktualis_meret){
            return jatekok[index];
        }

        return jatekok[0];
    }

    Jatek& operator[](unsigned int index) {
        if (index < aktualis_meret) {
            return jatekok[index];
        }

        return jatekok[0];
    }

};
