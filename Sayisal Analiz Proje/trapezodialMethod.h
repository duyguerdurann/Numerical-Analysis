#ifndef TRAPEZODIALMETHOD_H_
#define TRAPEZODIALMETHOD_H_
void trapezodial() {
	//Degiskenler
	double height, altsinir, ustsinir, area, toplam = 0;
	int derece, division;
	//Girdiler
	printf("Ka��nc� dereceden polinomun integralini alacaks�n�z?: ");
	scanf("%d", &derece);
	//Katsayilar dizisi
	double katsayi[derece];
	int i;
	for ( i= derece; i >= 0; i--) {
		printf("%d. derecenin katsayisi: ", i);
		scanf("%lf", &katsayi[i]);
	}
	//Fonksiyon
	double f(double xval) {
		double value = 0;
		double thisx = 1;

		//Fonksiyonun hesaplandigi dongu
		int i;
		for ( i= 0; i < (derece+1); i++) {
			value = katsayi[i] * thisx + value;
			thisx = thisx * xval;
		}
		return value;
	}

	printf("S�ras�yla, aralar�nda bo�luk b�rakarak\n"
			"�ntegralin Alt ve �st limitleri: ");
	scanf("%lf %lf", &altsinir, &ustsinir);
	//n degeri alma
	printf("Ayr�lacak olan b�lge say�s� (n de�eri): ");
	scanf("%d", &division);
	//Height hesabi
	height = (ustsinir - altsinir) / division;
	//f(x) degerlerinin altsinir+height'tan ustsinir'a kadar toplanmasi
	for (i=1; i<division; i++){
		toplam = toplam + f(altsinir + i*height);
	}
	//Trapez yontemiyle integral hesabi
	area = height*((f(altsinir)+f(ustsinir))/2 + toplam);
	printf("�ntegralin sonucu: %lf", area);
}
#endif /* TRAPEZODIALMETHOD_H_ */
