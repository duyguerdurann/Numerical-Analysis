#ifndef BISECTIONMETHOD_H_
#define BISECTIONMETHOD_H_

void bisection(){
	//Degiskenler
	double xVal1, xVal2, epsilon;
	int derece, iraksama = 0;

	//Girdiler
	printf("Ka��nc� dereceden polinomun k�k�n� ar�yorsunuz?: ");
	scanf("%d", &derece);

	//Katsayilar dizisi
	double katsayi[derece+1];
	int i;
	for ( i = derece; i >= 0; i--) {
		printf("%d. derecenin katsay�s�: ", i);
		scanf("%lf", &katsayi[i]);
	}

	//Girdiler
	printf("S�ras�yla, aralar�nda bo�luk b�rakarak\nBa�lang�� X1 ve X2 de�erleri: ");
	scanf("%lf %lf", &xVal1, &xVal2);

	printf("Epsilon degeri: ");
	scanf("%lf", &epsilon);

	//Fonksiyon
	double f(double xval) {
		double value = 0;
		double thisx = 1;
int i;
		//Fonksiyonun hesaplandigi dongu
		for ( i = 0; i < (derece+1); i++) {
			value = katsayi[i] * thisx + value;
			thisx = thisx * xval;
		}
		return value;
	}

	//Ilk ortanca deger atamasi
	double xValMid = (xVal1 + xVal2) / 2;

	//Hesaplama Dongusu
	while (fabs(f(xValMid)) > epsilon && (iraksama == 0)) {

		//Eger kok birinci ve ortanca deger arasindaysa yeni ortanca ikinci deger
		if (f(xVal1) * f(xValMid) < 0) {
			xVal2 = xValMid;
		}
		//Eger kok birinci ve ortanca deger arasinda degilse yeni ortanca birinci deger
		else {
			xVal1 = xValMid;
		}

		//Iraksama kontrolu
		if (fabs(xValMid - ((xVal1 + xVal2)/2)) <= epsilon){
			iraksama = 1;
		}

		//Yeni ortanca hesabi
		xValMid = (xVal1 + xVal2)/2;
	}

	//Cikti
	if (iraksama == 1){
		printf("K�k bulunamad� :(");
	} else {
		printf("Fonksiyonun k�k�: %lf", xValMid);
	}
}

#endif /* BISECTIONMETHOD_H_ */
