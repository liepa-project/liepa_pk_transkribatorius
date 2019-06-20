///////////////////////////////////////////////////////////////////////////////////////////////////
//
// Projektas LIEPA (https://liepa.ra�tija.lt)
// Sintezatoriaus komponentas transcrLUSS.dll
// Failas Skiemen.cpp
// Autorius dr. Pijus Kasparaitis (pkasparaitis@yahoo.com)
// 2015 08 11
//
///////////////////////////////////////////////////////////////////////////////////////////////////
//#include "stdafx.h"
#include <string.h>
#include <stdio.h>
#define Kiek 138

void skiem(char eil[], char SkPb[])
{
static const char *SkirSkiem[Kiek]={
"AA","A�","AE","A�","A�","AIE","AY","A�","AO","AUO","A�","A�",
"�A","��","�E","��","��","�I","�Y","��","�O","�U","��","��",
"EA","E�","EE","E�","E�","EIE","EY","E�","EO","EUI","EUO","E�","E�",
"�A","��","�E","��","��","�I","�Y","��","�O","�U","��","��",
"�A","��","�E","��","��","�I","�Y","��","�O","�U","��","��",
"IEI","I�","I�","II","IY","I�",
"YA","Y�","YE","Y�","Y�","YI","YY","Y�","YO","YU","Y�","Y�",
"�A","��","�E","��","��","�I","�Y","��","�O","�U","��","��",
"OA","O�","OE","O�","O�","OIE","OY","O�","OO","OUO","O�","O�",
"UA","U�","UE","U�","U�","UIE","UY","U�","UU","U�","U�",
"�A","��","�E","��","��","�I","�Y","��","�O","�U","��","��",
"�A","��","�E","��","��","�I","�Y","��","�O","�U","��","��"};

int i;
char* ek;

i=strlen(SkPb)-1;

if(SkPb[i] & 1) SkPb[i]++; //eilutes pabaiga
while(i>0)
	{
	while(!strchr("A�E��IY�OU�� ",eil[i])&&(i>0)) i--;
	while(strchr("A�E��IY�OU��",eil[i])&&(i>0)) i--;
	if((i>0)&&!(SkPb[i] & 2)&&strchr("JLMNRV",eil[i])) i--;
	if((i>1)&&!(SkPb[i] & 2)&&((eil[i]=='Z')&&(eil[i-1]=='D')
		||(eil[i]=='�')&&(eil[i-1]=='D')
		||(eil[i]=='H')&&(eil[i-1]=='C'))) i-=2;
	else if((i>0)&&!(SkPb[i] & 2)&&strchr("BDGKPTC�FH",eil[i])) i--;
	if((i>0)&&!(SkPb[i] & 2)&&(strchr("S�",eil[i])
		||strchr("Z�",eil[i])&&(eil[i-1]!='D'))) i--;

	if(SkPb[i] & 1) SkPb[i]++;
	if(eil[i]==' ') {if(i>0) i--; if(SkPb[i] & 1) SkPb[i]++;}
	}

// negalimu balsiu kombinaciju priskyrimas skirtingiems skiemenims
for(i=0; i<Kiek; i++)
	{
	ek=eil-1;
	while(((ek=strstr(ek+1,SkirSkiem[i]))!=0)&&(SkPb[ek-eil] & 1))
		SkPb[ek-eil]++;
	}
}
