#include <stdio.h>

// Insertion sort algoritmas� ile verilen dizi s�ralan�r
void is(int dizi[], int dboyutu) {
	int k; //de�i�ken atan�r
    for ( k= 1; k < dboyutu; k++) {
        int key = dizi[k]; // Anahtar eleman olarak k. eleman se�ilir
        int j = k - 1;  //j, anahtar eleman�n solundaki eleman� g�stermek i�in kullan�l�r
        
        // Dizi elemanlar�, anahtar eleman�ndan b�y�k oldu�u s�rece bir sonraki elemana kayd�r�l�r
        while (j >= 0 && dizi[j] > key) {
            dizi[j+1] = dizi[j]; // dizi eleman� bir sonraki pozisyona kayd�r�l�r
            j = j - 1;
        }
        
        // Anahtar eleman uygun konuma atan�r.
        dizi[j+1] = key;
    }
}

// Binary search algoritmas� ile verilen dizi i�inde eleman aran�r
// Ba�lang�� ve biti� indeksleri verilir.
int bs(int dizi[], int bas, int son, int aranan) {
	// Dizinin ba�lang�� ve biti� indisleri aras�nda arama yap�l�r
    if (son >= bas) { 
        int orta = bas + (son - bas) / 2;
        
        // Aranan eleman orta elemana e�itse orta eleman�n indisi d�nd�r�l�r
        if (dizi[orta] == aranan) {
            return orta;
        }
        
        // Aranan eleman orta elemandan k���kse sol yar�da arama yap�l�r
        if (dizi[orta] > aranan) {
            return bs(dizi, bas, orta - 1, aranan);
        }
        
        // Aranan eleman orta elemandan b�y�kse sa� yar�da arama yap�l�r
        return bs(dizi, orta + 1, son, aranan);
    }
    
    // Aranan eleman bulunamad�ysa -1 d�nd�r�r
    return -1;
}

int main() {
    int dizi[] = {4, 8, 3, 84, 47, 76, 9, 24, 68}; // Dizi tan�mlan�r
    int dboyutu = sizeof(dizi) / sizeof(dizi[0]);  //Dizinin boyutu hesaplan�r
    
    is(dizi, dboyutu); // Dizi yazd���m�z fonksiyon �a�r�larak s�ralan�r
    
    int asayi; // Aranan sayi i�in de�i�ken atan�r
    printf("Lutfen aranan sayiyi giriniz: "); // Kullan�cadan aranan sayiyi girmesi istenir
    scanf("%d",&asayi);
    printf("\n");


    int sonuc = bs(dizi, 0, dboyutu - 1, asayi); // Yazd���m�z binary search algoritmas� fonksiyonu �a�r�larak aranan eleman�n indisini bulunur ve sonuc de�i�kenine atan�r
    
    
    if (sonuc == -1) { // E�er aranan sayi bulunamazsa bu k�s�m �al���r
        printf("%d sayisi bulunamadi\n", asayi); 
    } else { // E�er aranan sayi bulunursa bu k�s�m �al���r
        printf("%d sayisi %d. indisinde bulundu\n", asayi, sonuc);
    }
    printf("\n\n");
	printf("ISIM: TAHA YASIN\n");
	printf("SOYISIM: CICEK\n");
	printf("OGRENCI NO: 1220505012\n");
    printf("PROGRAMIN YAPTIGI ISLEM: Binary search kullanarak bir dizi icinde eleman aramak");
    
    
    return 0;
}

