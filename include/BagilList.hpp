
/**        * @file  BagilList.hpp
* @description Klasordeki .txt dosyalarýný okuyuo o .txt dosyalarýnýn icindeki kelimeleri alfabetik olarak ekrana yazdiran ve aranan kelimeyi o .txt dosyalarýnda bulan program.
* @course  1.Ogretim A grubu
* @assignment  3. Odev  
* @date  9/12/2017
* @author  Caner KIRCI - caner.kirci@ogr.sakarya.edu.tr  
*/



#ifndef BAGILLIST_HPP
#define BAGILLIST_HPP

#include<string>
#include<iostream>
using namespace std;

class Agac;
struct ListDugum
{

	ListDugum *pSonraki;
	ListDugum(Agac*);
	Agac *agac;
};

class BagilList
{
public:

	BagilList();
	~BagilList();

	void Ekle(Agac *);
	ListDugum *BasGetir();
	void Temizle();
private:
	ListDugum *pBas;
	bool BosMu();

};


#endif
