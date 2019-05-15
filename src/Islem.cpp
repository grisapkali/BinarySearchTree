
/**        * @file  Islem.cpp
* @description Klasordeki .txt dosyalarýný okuyuo o .txt dosyalarýnýn icindeki kelimeleri alfabetik olarak ekrana yazdiran ve aranan kelimeyi o .txt dosyalarýnda bulan program.
* @course  1.Ogretim A grubu
* @assignment  3. Odev  
* @date  9/12/2017
* @author  Caner KIRCI - caner.kirci@ogr.sakarya.edu.tr  
*/

#include "Islem.hpp"
#include <string>
#include <fstream>
#include <iostream>
#include <cstdlib>

using namespace  std;


Islem::Islem()	//Yapici metot
{
	liste = new BagilList();
}

Islem::~Islem() //Yikici metot
{
	delete liste;

}

void Islem::AgacaEkleVeYazdir(Agac *&agac,dirent* txtAdi,string klasorYolu) //girilen parametredeki veriyi agaca ekleyip ekleme islemi bittikten sonra agaci inorder olarak yazdiran metot
{																			//Listeyi tamamen temizleyip tekrar ekleme yaparken her ekledigi txt dosyasinin icerisinde tek tek kontrol ediyor.
// C:\\Users\\Caner\\Desktop\\deneme   (ilk olarak kullanicidan almayip kendi atadigim klasor yolu)

	fstream dosya;
	string a = txtAdi->d_name;
	dosya.open(klasorYolu +"\\"+a, ios::in);

	if (dosya.is_open())
	{
		string isim;
		while (dosya >> isim)
		{
			agac->Ekle(isim);
		}
		cout << agac->DosyaAdi() << endl;;
		agac->Inorder();
		cout << endl<<endl;
	}
	dosya.close();
}

void Islem::Ara(string arananKelime,string klasorYolu)//Girilen kelimeyi girilen klasor yolu icerisindeki dosyalarda tek tek arayan metot.(Listeyi temizleyip tekrar listeye ekleme yapýyor eklerken her ekledigi elemanla kontrol ediyor

{
	liste->Temizle();			//listeyi temizle
	DIR *dir;
	struct  dirent *ent;
	const char * c = klasorYolu.c_str(); //string olarak girilen klasor yolunu *char dizisine ceviren kod(opendir metodunun parametresi yalnýzca const * char tipinde veri aliyor. Asiri yukleme yapilmamis
	if ((dir = opendir(c)) != NULL)
	{
		int sayac = 0;								
		bool dosyaVarMi=false;						
		while ((ent = readdir(dir)) != NULL)
		{
			sayac++;
			if (sayac >= 3)
			{

				liste->Ekle(new Agac());									
				string klasorAdi = ent->d_name;
				liste->BasGetir()->agac->fileName(klasorAdi);
				if (Ara(liste->BasGetir()->agac, ent, arananKelime,klasorYolu) == true)
				{
					dosyaVarMi = true;
					break;
				}
			}
		}
			if (dosyaVarMi == true)
			{
				cout << "Aradiginiz kelime " << ent->d_name << " dosyasinin icinde."<<endl;
			}
			else
			{
				cout << "Aradiginiz kelime bulunamadi. "<<endl;
			}
		
		closedir(dir);
	}
	else
	{
		//Dosya Okunamadý Hatasý
		perror("Dosya Okunamadi");
		exit(EXIT_FAILURE);
	}

	
}

bool Islem::Ara(Agac *& agac, dirent * txtAdi, string arananKelime,string klasorYolu)		//yalnizca program icerisinde cagrilabilen ve bircok parametreli metot
{
	fstream dosya;
	string a = txtAdi->d_name;
	dosya.open(klasorYolu+"\\" + a, ios::in);
	int sayac = 0;
	if (dosya.is_open())
	{
		string isim;

		while (dosya >> isim)
		{
			if (arananKelime == isim)
			{
				return true;
			}
		
		}
	
	}
	dosya.close();
	return false;

}

void Islem::Listele(string klasorYolu)				//Girilen klasor yolunda ki verileri AgacaEkleVeYazdir metodunu kullanarak yazdiran metot
{
	DIR *dir;
	struct  dirent *ent;
	const char * c = klasorYolu.c_str();
	if ((dir = opendir(c)) != NULL)
	{
		int sayac = 0;
		while ((ent=readdir(dir))!=NULL)
		{
			sayac++;
			if (sayac >= 3)
			{

				liste->Ekle(new Agac());						//listeye ekliyor
				string klasorAdi = ent->d_name;
				liste->BasGetir()->agac->fileName(klasorAdi);  //ekledigi nesnenin elemanina atama yapiyor.
				AgacaEkleVeYazdir(liste->BasGetir()->agac,ent, klasorYolu);
			}
		}
		closedir(dir);
	}
	else
	{
		//Dosya Okunamadý Hatasý
		perror("Dosya Okunamadi");
		exit (EXIT_FAILURE);
	}

}
