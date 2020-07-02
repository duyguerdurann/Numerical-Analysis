#ifndef GAUSSJORDANMETHOD_H_
#define GAUSSJORDANMETHOD_H_
	
void gaussJordan() {
	//Matris okuma degiskenleri
	int i = 0, j = 0, n = 0, determinant = 1;
	int step;
	printf( "Matrisler AX=C formatinda olmak üzere\n A kare matrisinin satir sayisini giriniz: " );
	scanf("%d", &n);

	//Matris tanimlamalari ve okumasi
	double matrix[n][n];
	double inverse[n][n];
	double constants[n][1];

	//A matrisi okuma
	printf("Elemanlar arasina bosluk birakarak satirlari teker teker giriniz: \n",
			n * n);
	for (i = 0; i < n; i++) {
		printf("%d. Satir: ", i+1);
		for (j = 0; j < n; j++) {
			scanf("%lf", &matrix[i][j]);
		}
	}

	//C matrisi okuma
	printf("C matrisinin elemanlarini teker teker giriniz: \n", n);
	for (i = 0; i < n; i++) {
	    printf("%d. Satir: ", i+1);
		scanf("%lf", &constants[i][0]);
	}

	//nxn birim matris
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (i == j) {
				inverse[i][j] = 1;
			} else {
				inverse[i][j] = 0;
			}
		}
	}

	//Degisken tanimlama
	double tempVal;
	int diagLocZero = 0, diagLocNonZero = 0, diagZero = 0, found = 0;

	//Kosegendeki tum degerler 0 mi kontrolu
    while(matrix[diagLocZero][diagLocZero] == 0){
        diagLocZero ++;
        if(diagLocZero == (n - 1)){
            diagZero = 2;
        }
    }

    //diagLocZero 0lama
    diagLocZero = 0;

	//Kosegendeki 0'larin tespiti
	while(diagZero == 0){
		if (matrix[diagLocZero][diagLocZero] == 0){ //Kosegendeki 0i tespit
			diagLocNonZero = 0;
			for(j = 0; j < n; j++){
				while(matrix[diagLocNonZero][diagLocZero] == 0 && found == 0) { //Kosegeni 0 olmayan satiri tespit
					diagLocNonZero++;
				}
				//Hem matrixte hem de inverste yer degistirme
				tempVal = matrix[diagLocZero][j];
				matrix[diagLocZero][j] = matrix[diagLocNonZero][j];
				matrix[diagLocNonZero][j] = tempVal;
				tempVal = inverse[diagLocZero][j];
				inverse[diagLocZero][j] = inverse[diagLocNonZero][j];
				inverse[diagLocNonZero][j] = tempVal;
				found = 1; //Kosegeni 0 olmayan satirin indisi artmamasi icin konulan degisken
			}
			tempVal = constants[diagLocZero][0];
			constants[diagLocZero][0] = constants[diagLocNonZero][0];
			constants[diagLocNonZero][0] = tempVal;
		}
		//0 tespiti icin kosegeni arttirma found'i 0lama
		diagLocZero++;
		found = 0;
		if (diagLocZero == n){
			diagZero = 1;
		}
	}

	//Ana matrisi ust ucgen formatina getirme

	for ( step = 0; step < n; step++) {
		tempVal = matrix[step][step];
		constants[step][0] /= tempVal;
		for (j = 0; j < n; j++) {
			matrix[step][j] /= tempVal;
			inverse[step][j] /= tempVal;
		}
		for (i = step + 1; i < n; i++) {
			tempVal = matrix[i][step];
			constants[i][0] -= constants[step][0] * tempVal;
			for (j = 0; j < n; j++) {
				matrix[i][j] -= matrix[step][j] * tempVal;
				inverse[i][j] -= inverse[step][j] * tempVal;
			}
		}
	}

	//Ust ucgen matrisi birim matris formatina getirme

	for (step = 0; step < n; step++) {
		for (i = step + 1; i < n; i++) {
			tempVal = matrix[step][i];
			constants[step][0] -= constants[i][0] * matrix[step][i];
			for (j = 0; j < n; j++) {
				matrix[step][j] -= matrix[i][j] * tempVal;
				inverse[step][j] -= inverse[i][j] * tempVal;
			}
		}
	}

	//Degelerin -nan bulunmasi durumu kontrolu
	for(i = 0; i<n; i++){
		if(constants[i][0] != constants[i][0]){
			determinant = 0;
		}
	}

	if(diagZero == 2){
        printf("Asal kösegendeki tüm elemanlar 0 oldugundan hesaplanamadi.\n"
               "Lütfen baska bir matris veriniz.");
    }else if(determinant == 0){
		printf("Determinanti 0 olan matrisin inversi olmadigindan bilinmeyen degerler de bulunamadi.");
	}else{
        printf("\nX degerleri:\n");

        for (i = 0; i < n; i++) {
            printf("X(%d)= %.4f\n", i + 1, constants[i][0]);
        }
    }
}

#endif /* GAUSSJORDANMETHOD_H_ */
