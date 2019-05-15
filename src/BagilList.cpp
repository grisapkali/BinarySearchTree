
/**        * @file  BagilList.cpp
* @description Klasordeki .txt dosyalar�n� okuyuo o .txt dosyalar�n�n icindeki kelimeleri alfabetik olarak ekrana yazdiran ve aranan kelimeyi o .txt dosyalar�nda bulan program.
* @course  1.Ogretim A grubu
* @assignment  3. Odev  
* @date  9/12/2017
* @author  Caner KIRCI - caner.kirci@ogr.sakarya.edu.tr  
*/


#include "BagilList.hpp"

ListDugum::ListDugum(Agac * agac) //Yap�c� metot(Dugum)
{
	pSonraki = NULL;
	this->agac = agac;
}


BagilList::BagilList() //Yap�c� metot(Ba��l Liste)
{
	pBas = NULL;
}


void BagilList::Temizle() //Temizle metodu(Listenin bas eleman� NULL olana kadar t�m elemanlar� tek tek siler)
{
	while (pBas != NULL)
	{
		ListDugum* silinecek = pBas;
		pBas = pBas->pSonraki;
		delete silinecek;
	}
}


bool BagilList::BosMu() //Liste bos mu diye kontrol eden metot
{
	return pBas==NULL;
}

void BagilList::Ekle(Agac * agac) //Girilen parametreyi listede yeni dugum olusturarak o dugume ekleyen metot
{	
	ListDugum* gecici = this->pBas;
	if (gecici == NULL)
	{
		pBas = new ListDugum(agac);
	}
	else
	{
		while (gecici->pSonraki !=NULL)
		{
			gecici = gecici->pSonraki;

		}
		gecici->pSonraki = new ListDugum(agac);
	}
	
}


ListDugum * BagilList::BasGetir() //Listenin en son elemanini getiren metot
{	
	ListDugum* gecici = this->pBas;
	while (gecici->pSonraki != NULL)
	{
		gecici = gecici->pSonraki;

	}
		return gecici;
}



BagilList::~BagilList()//Yikici metot
{
	Temizle();
}
