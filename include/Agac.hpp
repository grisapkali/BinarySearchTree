
/**        * @file  Agac.hpp
* @description Klasordeki .txt dosyalarýný okuyuo o .txt dosyalarýnýn icindeki kelimeleri alfabetik olarak ekrana yazdiran ve aranan kelimeyi o .txt dosyalarýnda bulan program.
* @course  1.Ogretim A grubu
* @assignment  3. Odev  
* @date  9/12/2017
* @author  Caner KIRCI - caner.kirci@ogr.sakarya.edu.tr  
*/


#ifndef AGAC_HPP
#define AGAC_HPP


#include<string>
#include<iostream>
using namespace std;

struct Dugum
{
	string Veri;
	Dugum *pSol;
	Dugum *pSag;

	Dugum(string&, Dugum*, Dugum*);
};

class Agac 
{
public:
	Agac();
	~Agac();
	void Temizle();
	bool BosMu();
	void Ekle(string &yeni);
	void Inorder();
	void fileName(string);
	string DosyaAdi();
private:
	string dosyaAdi;
	Dugum *pKok;
	void AraveEkle(Dugum *&, string&);
	void Inorder(Dugum *);
	bool DugumSil(Dugum *&altDugum);

};




#endif // !AGAC_HPP
