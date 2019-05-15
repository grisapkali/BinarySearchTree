
/**        * @file  Test.cpp
* @description Klasordeki .txt dosyalarýný okuyuo o .txt dosyalarýnýn icindeki kelimeleri alfabetik olarak ekrana yazdiran ve aranan kelimeyi o .txt dosyalarýnda bulan program.
* @course  1.Ogretim A grubu
* @assignment  3. Odev  
* @date  9/12/2017
* @author  Caner KIRCI - caner.kirci@ogr.sakarya.edu.tr  
*/


#include"Islem.hpp"
#include<iostream>

using namespace std;

int main()
{
	Islem *a = new Islem();
	string klasorYolu;
	int secim;
	cout << "Klasor yolu giriniz :" << endl;
	cin >> klasorYolu;
	while (true)
	{
		
		system("cls");
		cout << "1 - Arama Yap :" << endl;
		cout << "2 - Listele :" << endl;
		cout << "3 - Cikis :" << endl;
		cin >> secim;
		if (secim == 1)	//Arama yap
		{
			string aranacakKelime;
			cout << "Aranan : ";
			cin >> aranacakKelime;
			a->Ara(aranacakKelime,klasorYolu);
			system("pause");
		}
		else if (secim == 2)	//Listele
		{
			system("cls");
			a->Listele(klasorYolu);
			system("pause");
		}
		else if (secim == 3) //cikis yap
			break;	

	}
	return 0;

}
