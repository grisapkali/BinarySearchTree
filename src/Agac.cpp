
/**        * @file  Agac.cpp
* @description Klasordeki .txt dosyalar�n� okuyuo o .txt dosyalar�n�n icindeki kelimeleri alfabetik olarak ekrana yazdiran ve aranan kelimeyi o .txt dosyalar�nda bulan program.
* @course  1.Ogretim A grubu
* @assignment  3. Odev  
* @date  9/12/2017
* @author  Caner KIRCI - caner.kirci@ogr.sakarya.edu.tr  
*/


#include "Agac.hpp"

Dugum::Dugum(string &vr, Dugum *sl=NULL, Dugum *sg=NULL) //Yap�c� metot(dugum yap�s�)
{
	Veri = vr;
	pSol = sl;
	pSag = sg;
}
Agac::Agac() //Yap�c� metot(Agac s�n�f�)
{
	pKok = NULL;
}

void Agac::Temizle()//temizle metodu 
{
	while (!BosMu())
	{
		DugumSil(pKok);
	}
}

bool Agac::BosMu() //Agacin bos olup olmadigini kontrol eden metot
{
	return pKok == NULL;;
}

void Agac::Ekle(string &yeni) //Kullaninin kullanacagi ekle metodu
{
	AraveEkle(pKok, yeni);
}

void Agac::Inorder()
{
	Inorder(pKok);
}

void Agac::fileName(string a)
{
	dosyaAdi = a;
}

string Agac::DosyaAdi()
{
	return dosyaAdi;
}

void Agac::AraveEkle(Dugum *&alt_Dugum, string &yeni) //yaln�zca program icerisinde cagrilan kullan�c�n�n erisemedigi ekle metotu
{
	if (alt_Dugum == NULL)
		alt_Dugum = new Dugum(yeni);
	else if (yeni < alt_Dugum->Veri)
		AraveEkle(alt_Dugum->pSol, yeni);
	else if (yeni > alt_Dugum->Veri)
		AraveEkle(alt_Dugum->pSag, yeni);
	else
		return;

}

void Agac::Inorder(Dugum *altDugum ) //Agacin icinde ki verileri inorder olarak s�ralayan metot
{
	if (altDugum != NULL)
	{
		Inorder(altDugum->pSol);
		cout << altDugum->Veri << " ";
		Inorder(altDugum->pSag);
	}
}

bool Agac::DugumSil(Dugum *&altDugum) //parametre olarak girilen dugumu agacin yapisin� bozmadan silen metot
{
	Dugum *silinecekDugum = altDugum;
	if (altDugum->pSag == NULL)
		altDugum = altDugum->pSol;
	else if (altDugum->pSol == NULL)
		altDugum = altDugum->pSag;
	else
	{
		silinecekDugum=altDugum->pSol;
		Dugum *ebeveyn = altDugum;
		while (silinecekDugum->pSag!=NULL)
		{
			ebeveyn = silinecekDugum;
			silinecekDugum = silinecekDugum->pSag;
		}
		altDugum->Veri = silinecekDugum->Veri;
		if (ebeveyn = altDugum)
			altDugum->pSol = silinecekDugum->pSol;
		else
			ebeveyn->pSag = silinecekDugum->pSol;

		delete silinecekDugum;
		return true;
	}

	return false;
}

Agac::~Agac() //yikici metot
{
	Temizle();
}
