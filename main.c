#include <stdio.h>

// Insertion sort algoritmasý ile verilen dizi sýralanýr
void is(int dizi[], int dboyutu) {
	int k; //deðiþken atanýr
    for ( k= 1; k < dboyutu; k++) {
        int key = dizi[k]; // Anahtar eleman olarak k. eleman seçilir
        int j = k - 1;  //j, anahtar elemanýn solundaki elemaný göstermek için kullanýlýr
        
        // Dizi elemanlarý, anahtar elemanýndan büyük olduðu sürece bir sonraki elemana kaydýrýlýr
        while (j >= 0 && dizi[j] > key) {
            dizi[j+1] = dizi[j]; // dizi elemaný bir sonraki pozisyona kaydýrýlýr
            j = j - 1;
        }
        
        // Anahtar eleman uygun konuma atanýr.
        dizi[j+1] = key;
    }
}

// Binary search algoritmasý ile verilen dizi içinde eleman aranýr
// Baþlangýç ve bitiþ indeksleri verilir.
int bs(int dizi[], int bas, int son, int aranan) {
	// Dizinin baþlangýç ve bitiþ indisleri arasýnda arama yapýlýr
    if (son >= bas) { 
        int orta = bas + (son - bas) / 2;
        
        // Aranan eleman orta elemana eþitse orta elemanýn indisi döndürülür
        if (dizi[orta] == aranan) {
            return orta;
        }
        
        // Aranan eleman orta elemandan küçükse sol yarýda arama yapýlýr
        if (dizi[orta] > aranan) {
            return bs(dizi, bas, orta - 1, aranan);
        }
        
        // Aranan eleman orta elemandan büyükse sað yarýda arama yapýlýr
        return bs(dizi, orta + 1, son, aranan);
    }
    
    // Aranan eleman bulunamadýysa -1 döndürür
    return -1;
}

int main() {
    int dizi[] = {4, 8, 3, 84, 47, 76, 9, 24, 68}; // Dizi tanýmlanýr
    int dboyutu = sizeof(dizi) / sizeof(dizi[0]);  //Dizinin boyutu hesaplanýr
    
    is(dizi, dboyutu); // Dizi yazdýðýmýz fonksiyon çaðrýlarak sýralanýr
    
    int asayi; // Aranan sayi için deðiþken atanýr
    printf("Lutfen aranan sayiyi giriniz: "); // Kullanýcadan aranan sayiyi girmesi istenir
    scanf("%d",&asayi);
    printf("\n");


    int sonuc = bs(dizi, 0, dboyutu - 1, asayi); // Yazdýðýmýz binary search algoritmasý fonksiyonu çaðrýlarak aranan elemanýn indisini bulunur ve sonuc deðiþkenine atanýr
    
    
    if (sonuc == -1) { // Eðer aranan sayi bulunamazsa bu kýsým çalýþýr
        printf("%d sayisi bulunamadi\n", asayi); 
    } else { // Eðer aranan sayi bulunursa bu kýsým çalýþýr
        printf("%d sayisi %d. indisinde bulundu\n", asayi, sonuc);
    }
    printf("\n\n");
	printf("ISIM: TAHA YASIN\n");
	printf("SOYISIM: CICEK\n");
	printf("OGRENCI NO: 1220505012\n");
    printf("PROGRAMIN YAPTIGI ISLEM: Binary search kullanarak bir dizi icinde eleman aramak");
    
    
    return 0;
}

