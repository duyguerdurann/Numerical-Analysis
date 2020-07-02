#ifndef GRAPHICALMETHOD_H_
#define GRAPHICALMETHOD_H_

void graphical() {
	//Degiskenler
	double xVal, delta, epsilon;
	int derece, iraksama = 0, testCounter = 0;
	char devam = 'e';
	//Girdiler
	printf("Kaçýncý dereceden polinomun kökünü arýyorsunuz?: ");
	scanf("%d", &derece);

	//Katsayilar dizisi
	double katsayi[derece];
	int i;
	for (i = derece; i >= 0; i--) {
		printf("%d. derecenin katsayýsý: ", i);
		scanf("%lf", &katsayi[i]);
	}
	//Girdiler
	printf("Baþlangýç X deðeri: ");
	scanf("%lf", &xVal);

	printf("Sýrasýyla, aralarýnda boþluk býrakarak\n"
			"Delta ve Epsilon deðerleri: ");
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
				printf("Verilen deðerler sonucu %d iterasyondur kök bulunamadý.\n"
		   "X deðeri þu anda \"%.4lf\"\n"
		   "Devam etmek istiyor musunuz (e/h)? ", testCounter, xVal);
				scanf(" %c", &devam);

				//devam karakter kontrolu
				while(devam != 'e' && devam != 'h'){
					printf("\"%c\" geçerli deðildir.\n"
						   "Lütfen geçerli karakter giriniz (e/h): ", devam);
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
		printf("Kök bulunamadý :(");
	} else {
		printf("Fonksiyonun kökü: %lf", xVal + delta);
	}

}
#endif /* GRAPHICALMETHOD_H_ */
