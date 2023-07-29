#ifndef FUNKCIJE_H_INCLUDED
#define FUNKCIJE_H_INCLUDED

typedef struct Zaposleni
{
    int id, broj_godina_u_kompaniji;
    char ime_prezime[101],kompanija[51];
    float zarada;
}Zaposleni;

Zaposleni unos();
void unos_niza(Zaposleni niz[], int n);
void ispis(Zaposleni z);
void ispis_niza(Zaposleni niz[], int n);
int ucitaj_iz_fajla(Zaposleni niz[],const char naziv_fajla[]);
void skini_red(char tekst[]);
void ispisi_u_fajl(Zaposleni niz[], int n, const char naziv_fajla[]);
void pretraga_po_nazivu_kompanije(Zaposleni niz[], int n, char pretraga[]);
Zaposleni zaposljeni_sa_najvecom_zaradom(Zaposleni niz[], int n);
void pretraga_po_broju_godina_u_kompaniji(Zaposleni niz[], int n, int pretraga);

#endif // FUNKCIJE_H_INCLUDED
