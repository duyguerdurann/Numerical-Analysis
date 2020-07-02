#ifndef SIMPSONMETHOD_H_
#define SIMPSONMETHOD_H_

void simpson() {

	//Degiskenler
	double height, altsinir, ustsinir, area, sumOfOdds = 0, sumOfEvens = 0;
	int derece, division,i,k;

	//Girdiler
	printf("Kaçinci dereceden polinomun integralini alacaksiniz?: ");
	scanf("%d", &derece);

	//Katsayilar dizisi
	double katsayi[derece];
	for ( i = derece; i >= 0; i--) {
		printf("%d. derecenin katsayisi: ", i);
		scanf("%lf", &katsayi[i]);
	}

	//Fonksiyon
	double f(double xval) {
		double value = 0;
		double thisx = 1;
        //int i=0;
		//Fonksiyonun hesaplandigi dongu
		for ( i = 0; i < (derece + 1); i++) {
			value = katsayi[i] * thisx + value;
			thisx = thisx * xval;
		}
		return value;
	}

	
	printf("Sirasiyla, aralarinda bosluk birakarak\n"
			"Integralin Alt ve Üst limitleri: ");
	scanf("%lf %lf", &altsinir, &ustsinir);

	//n degeri alma
	printf("Ayrilacak olan bölge sayisi (n degeri): ");
	do {
		scanf("%d", &division);
		if (division % 2 == 1){
			printf("\nn degeri çift olmalidir!\nLütfen tekrar giriniz: ");
		}
	} while (division % 2 == 1);

	//Height hesabi
	height = (ustsinir - altsinir) / division;
   
	//f(x)'in tek degerlerinin altsinir+height'tan ustsinir'a kadar toplanmasi
	for (k = 1; k < division; i+=2) {
		sumOfOdds = sumOfOdds + f(altsinir + i*height);
	}

	//f(x)'in cift degerlerinin altsinir+2*height'tan ustsinir-2*height'a kadar toplanmasi
	for ( k = 2; k < division-1; k+=2) {
		sumOfEvens = sumOfEvens + f(altsinir + i*height);
	}

	//Simpson yontemiyle integral hesabi
	area = (height/3)*(f(altsinir) + f(ustsinir) + 4*sumOfOdds + 2*sumOfEvens);

	printf("Integralin sonucu: %lf", area);
}

#endif /* SIMPSONMETHOD_H_ */
