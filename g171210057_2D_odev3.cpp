/****************************************************************************
**							SAKARYA �N�VERS�TES�
**			        B�LG�SAYAR VE B�L���M B�L�MLER� FAK�LTES�
**						 B�LG�SAYAR M�HEND�SL��� B�L�M�
**				           PROGRAMLAMAYA G�R��� DERS�
**
**				�DEV NUMARASI�...:3
**				��RENC� ADI...............:OKAN YE��LO�LU
**				��RENC� NUMARASI.:G171210057
**				DERS GRUBU����:2D
****************************************************************************/

#include <iostream>
#include <locale.h>
#include <iomanip>
using namespace std;
int kontrol(int satir, int sutun, struct islem);//kayma miktari ve giris matrisinin boyutuna g�re islemin yap�l�p yap�lamayaca��n� hesaplar
void hesapla(struct islem matris);//istenilen iteratif i�lemlerin yap�lmas�n� sa�lar
int boyut_x(struct islem);//giris matrisinin  satir boyutunu hesaplayama yarar b�ylece giris matrisinin boyutu de�i�se bile i�lemler yap�labilir
int boyut_y(struct islem matris);//giris matrisinin  sutun boyutunu hesaplayama yarar b�ylece giris matrisinin boyutu de�i�se bile i�lemler yap�labilir
void giris(struct islem matris);//�ekirdek matrisinin giri�inin yap�lmas�n� sa�lar
int sonuc_X(struct islem);//giri� matrisi ile �ekirdek matrisinin hesaplamas�n�n ard�ndan sonuclar�n yazd�r�laca�� matrisin boyutunu belirler
int sonuc_Y(struct islem);//giri� matrisi ile �ekirdek matrisinin hesaplamas�n�n ard�ndan sonuclar�n yazd�r�laca�� matrisin boyutunu belirler
void yazdir(struct islem);//sonuc matrisini yazd�rmaya yarar.
struct  islem {
	int giris[5][5] = {
						3,2,5,1,4,
						6,2,1,0,7,
						3,0,0,2,0,
						1,1,3,2,2,
						0,3,1,0,0
	};
	int kaymaMiktari;
	float sonuc[100][100];
	int cekirdek[5][5];
	int cekirdekBoyut;
};
int main() {
	setlocale(LC_ALL, "turkish");
	islem matris;//yukar�da tan�mlad���m�z yap�dan bir degisken t�retiyoruz.
	cout << "�ekirdek[m][m] kare matrisi i�in\nm de�eri giriniz: ";
	cin >> matris.cekirdekBoyut;
	cout << "Kayma miktar�n� giriniz: ";
	cin >> matris.kaymaMiktari;
	if (kontrol(boyut_x(matris), boyut_y(matris), matris)) {
		giris(matris);
	}
	system("pause");
	return 0;
}
void giris(struct islem matris) {//�ekirdek matrisinin degerlerinin girilmesine yarar.
	for (int i = 0; i < matris.cekirdekBoyut; i++) {
		for (int j = 0; j < matris.cekirdekBoyut; j++) {

			cout << "cekirdek[" << i << "][" << j << "] = ";
			cin >> matris.cekirdek[i][j];
		}
		cout << endl;
	}
	hesapla(matris);

}
int kontrol(int satir, int sutun, struct islem matris) {//satir stun boyut x ve y fonksiyonlar�ndan gelen de�erleri al�r
	if ((satir - matris.cekirdekBoyut) % matris.kaymaMiktari == 0 && (sutun - matris.cekirdekBoyut) % matris.kaymaMiktari == 0) {
		return 1;
	}
	else {
		cout << "Bu i�lem yap�lamaz..";
	}
	return 0;
}
void hesapla(struct islem matris) {
	int a = 0;
	int b = 0;
	int counter = 0;
	float toplam = 0;
	int q = 0, t = 0;
	for (int m = 0; m < sonuc_X(matris); m = m + matris.kaymaMiktari) {//sat�r kayd�rmak i�in
		for (int n = 0; n < sonuc_Y(matris); n = n + matris.kaymaMiktari) {//s�tun kayd�rmak i�in
			for (int x = 0; x < matris.cekirdekBoyut; x++) {//�ekirdek matrisi ile giris matrisinin �arp�mlar�n�n yap�ld�� yer
				for (int y = 0; y < matris.cekirdekBoyut; y++)
				{
					toplam = toplam + (matris.giris[x + m][y + n] * matris.cekirdek[x][y]);
					counter++;
					if (counter == matris.cekirdekBoyut*matris.cekirdekBoyut) {
						matris.sonuc[a][b] = toplam;
						counter = 0;
						b++;
						toplam = 0;
						if (b == sonuc_X(matris)) {
							b = 0;
							if (a < sonuc_Y(matris)) {
								a++;
								if (b == sonuc_X(matris)
									) {
									break;
								}
							}
						}
					}
				}
			}
		

		}
	
	}
	yazdir(matris);
}
void yazdir(struct islem matris) {
	for (int i = 0; i < sonuc_Y(matris); i++) {
		for (int j = 0; j < sonuc_X(matris); j++) {
			cout << setw(10) << matris.sonuc[i][j] << setw(10);
		}
		cout << endl;
	}
}
int boyut_x(struct islem matris) {//giri� matrisinin boyutunu �grenme
	int x = sizeof(matris.giris) / sizeof(matris.giris[0]);//satir

	return x;
}
int boyut_y(struct islem matris) {//giris matrisinin sat�r degerini �grenme
	int y = sizeof(matris.giris[0]) / sizeof(matris.giris[0][0]);//sutun
	return y;
}
int sonuc_X(struct islem matris) {//sutun  sonuc matrisinin boyutunu hesaplama
	return ((boyut_y(matris) - matris.cekirdekBoyut) / matris.kaymaMiktari) + 1;
}
int sonuc_Y(struct islem matris) {//sat�r
	return ((boyut_x(matris) - matris.cekirdekBoyut) / matris.kaymaMiktari) + 1;
}