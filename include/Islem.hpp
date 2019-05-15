
/**        * @file  Islem.hpp
* @description Klasordeki .txt dosyalarýný okuyuo o .txt dosyalarýnýn icindeki kelimeleri alfabetik olarak ekrana yazdiran ve aranan kelimeyi o .txt dosyalarýnda bulan program.
* @course  1.Ogretim A grubu
* @assignment  3. Odev  
* @date  9/12/2017
* @author  Caner KIRCI - caner.kirci@ogr.sakarya.edu.tr  
*/



#ifndef ISLEM_HPP
#define ISLEM_HPP

#include<iostream>
#include<fstream>
#include<dirent.h>
#include"BagilList.hpp"
#include"Agac.hpp"
class BagilList;
class Islem
{
public:

	Islem();
	~Islem();
	void Ara(string,string);
	void Listele(string);

private:
	void AgacaEkleVeYazdir(Agac *&, dirent*,string);
	bool Ara(Agac *&, dirent*, string,string);
	BagilList *liste;
};

#endif
