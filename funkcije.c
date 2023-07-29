#include <stdio.h>
#include <stdlib.h>
#include "funkcije.h"

Zaposleni unos()
{
    Zaposleni z;
    printf("ID:");
    scanf("%d",&z.id);
    printf("Ime i prezime:");
    fflush(stdin);
    gets(z.ime_prezime);
    printf("Kompanija:");
    fflush(stdin);
    gets(z.kompanija);
    printf("Zarada:");
    scanf("%f",&z.zarada);
    printf("Broj godina u kompaniji:");
    scanf("%d",&z.broj_godina_u_kompaniji);
    return z;
}

void ispis(Zaposleni z)
{
    printf("ID:%d\n",z.id);
    printf("Ime i prezime:%s\n",z.ime_prezime);
    printf("Kompanija:%s\n",z.kompanija);
    printf("Zarada:%.2f\n",z.zarada);
    printf("Broj godina u kompaniji:%d\n",z.broj_godina_u_kompaniji);
}

void unos_niza(Zaposleni niz[], int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d)\n",i+1);
        niz[i]=unos();
    }
}

void ispis_niza(Zaposleni niz[], int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d)\n",i+1);
        ispis(niz[i]);
    }
}

int ucitaj_iz_fajla(Zaposleni niz[],const char naziv_fajla[])
{
    int brojac=0;
    FILE *f=fopen(naziv_fajla,"r");
    if(f==NULL)
    {
        printf("Fajl ne postoji.");
        return 1;
    }
    Zaposleni z;
    while(!feof(f))
    {
        fscanf(f,"%d\n",&z.id);
        fgets(z.ime_prezime,101,f);
        fgets(z.kompanija,51,f);
        fscanf(f,"%f\n",&z.zarada);
        fscanf(f,"%d\n",&z.broj_godina_u_kompaniji);
        skini_red(z.ime_prezime);
        skini_red(z.kompanija);
        niz[brojac]=z;
        brojac++;
    }
    fclose(f);
    return brojac;
}

void skini_red(char tekst[])
{
    int n=strlen(tekst);
    tekst[n-1]='\0';
}

void ispisi_u_fajl(Zaposleni niz[], int n, const char naziv_fajla[])
{
    FILE *f=fopen(naziv_fajla,"w");
    for(int i=0;i<n;i++)
    {
        fprintf(f,"%d\n",niz[i].id);
        fprintf(f,"%s\n",niz[i].ime_prezime);
        fprintf(f,"%s\n",niz[i].kompanija);
        fprintf(f,"%.2f\n",niz[i].zarada);
        fprintf(f,"%d\n",niz[i].broj_godina_u_kompaniji);
    }
    fclose(f);
}

void pretraga_po_nazivu_kompanije(Zaposleni niz[], int n, char pretraga[])
{
    int x=0;
    for(int i=0;i<n;i++)
    {
        if(strstr(niz[i].kompanija,pretraga))
        {
            x++;
            printf("%d)\n",i+1);
            ispis(niz[i]);
        }
    }
    if(x==0)printf("Nema podudaranja sa pretragom.\n");
}

Zaposleni zaposljeni_sa_najvecom_zaradom(Zaposleni niz[], int n)
{
    float maks=niz[0].zarada;
    Zaposleni zaposleni_koji_ima_najvecu_zaradu=niz[0];
    for(int i=0;i<n;i++)
    {
        if(niz[i].zarada>maks)
        {
            maks=niz[i].zarada;
            zaposleni_koji_ima_najvecu_zaradu=niz[i];
        }
    }
    return zaposleni_koji_ima_najvecu_zaradu;
}

void pretraga_po_broju_godina_u_kompaniji(Zaposleni niz[], int n, int pretraga)
{
    int x=0;
    for(int i=0;i<n;i++)
    {
        if(niz[i].broj_godina_u_kompaniji>=pretraga)
        {
            x++;
            printf("%d)\n",i+1);
            ispis(niz[i]);
        }
    }
    if(x==0)printf("Nema podudaranja sa pretragom.\n");
}