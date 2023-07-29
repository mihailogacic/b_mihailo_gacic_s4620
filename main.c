#include <stdio.h>
#include <stdlib.h>

int main()
{//Gacic Mihailo s46\20
    int n;
    Zaposleni niz[100];
    while(1)
    {
        int opcija;
        printf("1)Dodaj novog zaposlenog.\n");
        printf("2)Ispisi sve zaposlene.\n");
        printf("3)Ucitaj zaposlene iz fajla.\n");
        printf("4)Pretraga po nazivu kompanije.\n");
        printf("5)Zaposleni sa najvecom zaradom.\n");
        printf("6)Pretraga po broju godina provedenih u kompaniji.\n");
        printf("7)Sacuvaj u fajl i zavrsi program.\n");
        scanf("%d",&opcija);
        if(opcija<1&&opcija>7)
        {
            printf("Opcija %d ne postoji u datom meniju.",opcija);
        }
        else if(opcija==1)
        {
            niz[n++]=unos();
        }
        else if(opcija==2)ispis_niza(niz,n);
        else if(opcija==3)
        {
            char naziv_fajla[21];
            printf("Unesi naziv fajla:");
            fflush(stdin);
            gets(naziv_fajla);
            n=ucitaj_iz_fajla(niz, naziv_fajla);
        }
        else if(opcija==4)
        {
            char pretraga[51];
            printf("Unesi pretragu:");
            fflush(stdin);
            gets(pretraga);
            pretraga_po_nazivu_kompanije(niz,n,pretraga);
        }
        else if(opcija==5)
        {
            Zaposleni z=zaposljeni_sa_najvecom_zaradom(niz,n);
            ispis(z);
        }
        else if(opcija==6)
        {
            int pretraga;
            printf("Unesi pretragu:");
            scanf("%d",&pretraga);
            pretraga_po_broju_godina_u_kompaniji(niz,n,pretraga);
        }
        else if(opcija==7)
        {
            char naziv_fajla[21];
            printf("Unesi naziv fajla:");
            fflush(stdin);
            gets(naziv_fajla);
            ispisi_u_fajl(niz,n,naziv_fajla);
            return 0;
        }
    }

    return 0;
}
