#ifndef GRAPHICALMETHOD_H_
#define GRAPHICALMETHOD_H_

void graphical() {
	//Degiskenler
	double xVal, delta, epsilon;
	int derece, iraksama = 0, testCounter = 0;
	char devam = 'e';
	//Girdiler
	printf("Ka��nc� dereceden polinomun k�k�n� ar�yorsunuz?: ");
	scanf("%d", &derece);

	//Katsayilar dizisi
	double katsayi[derece];
	int i;
	for (i = derece; i >= 0; i--) {
		printf("%d. derecenin katsay�s�: ", i);
		scanf("%lf", &katsayi[i]);
	}
	//Girdiler
	printf("Ba�lang�� X de�eri: ");
	scanf("%lf", &xVal);

	printf("S�ras�yla, aralar�nda bo�luk b�rakarak\n"
			"Delta ve Epsilon de�erleri: ");
	scanf("%lf %lf", &delta, &epsilon);

	//Fonksiyon
	double f(double xval) {
		double value = 0;
		double thisx = 1;
        int i;
		//Fonksiyonun hesaplandigi dongu
		for ( i= 0; i < (derece + 1); i++) {
			value = katsayi[i] * thisx + value;
			thisx = thisx * xval;
		}
		return value;
	}

	//Kok hesabi
	while ((fabs(f(xVal + delta) - f(xVal)) > epsilon) && (devam == 'e')){
		while ((f(xVal)*f(xVal + delta) > 0) && (devam == 'e')){
			xVal += delta;
			testCounter++;
			if (testCounter % 1000 == 0){
				printf("Verilen de�erler sonucu %d iterasyondur k�k bulunamad�.\n"
		   "X de�eri �u anda \"%.4lf\"\n"
		   "Devam etmek istiyor musunuz (e/h)? ", testCounter, xVal);
				scanf(" %c", &devam);

				//devam karakter kontrolu
				while(devam != 'e' && devam != 'h'){
					printf("\"%c\" ge�erli de�ildir.\n"
						   "L�tfen ge�erli karakter giriniz (e/h): ", devam);
					scanf(" %c", &devam);
				}
			}
		}
		xVal -= delta;
		delta /= 2;
		testCounter = 0;
	}
	//Cikti
	if (devam != 'e'){
		printf("K�k bulunamad� :(");
	} else {
		printf("Fonksiyonun k�k�: %lf", xVal + delta);
	}

}
#endif /* GRAPHICALMETHOD_H_ */
