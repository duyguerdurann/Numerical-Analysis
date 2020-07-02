#ifndef NEWTONRAPHSONMETHOD_H_
#define NEWTONRAPHSONMETHOD_H_

void newtonRaphson() {
	//Degiskenler
	double xVal, xValTemp, epsilon;
	int derece;
	//Girdiler
	printf("Ka��nc� dereceden polinomun k�k�n� ar�yorsunuz?: ");
	scanf("%d", &derece);
	//Katsayilar dizisi
	double katsayi[derece + 1];
	int i;
	for ( i= derece; i >= 0; i--) {
		printf("%d. derecenin katsay�s�: ", i);
		scanf("%lf", &katsayi[i]);
	}
	//Analitik turevin katsayiar dizisi
	double tkatsayi[derece];
	for ( i = (derece - 1); i >= 0; i--) {
		tkatsayi[i] = katsayi[i + 1] * (i + 1);
	}
	//Girdiler
	printf("S�ras�yla, aralar�nda bo�luk b�rakarak\n"
			"Baslang�� X ve Epsilon de�erleri: ");
	scanf("%lf %lf", &xVal, &epsilon);
	//Fonksiyon
	double f(double xval) {
		double value = 0;
		double thisx = 1;
		//Fonksiyonun hesaplandigi dongu
		int i;
		for ( i= 0; i < (derece + 1); i++) {
			value = katsayi[i] * thisx + value;
			thisx = thisx * xval;
		}
		return value;
	}
	double df(double xval) {
		double value = 0;
		double thisx = 1;

		//Fonksiyonun analitik turevinin hesaplandigi dongu
		int i;
		for (i = 0; i <derece; i++) {
			value = tkatsayi[i] * thisx + value;
			thisx = thisx * xval;
		}
		return value;
	}
	//Newton Raphson yontemiyle kokun bulundugu dongu
	do {
		//X(k) tutmak icin
		xValTemp = xVal;
		///X(k+1) hesabi
		xVal = xVal - (f(xVal) / df(xVal));
	} while (fabs(xVal - xValTemp) > epsilon);
	printf("Fonksiyonun k�k�: %lf", xVal);
}
#endif /* NEWTONRAPHSONMETHOD_H_ */
