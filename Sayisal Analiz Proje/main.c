//Tumlesik kutuphaneler
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

//Yazilan kutuphaneler //
#include "graphicalMethod.h"
#include "bisectionMethod.h"
#include "regulafalsiMethod.h"
#include "newtonrapsonMethod.h"
#include "trapezodialMethod.h"
#include "simpsonMethod.h"
#include "gaussJordanMethod.h" 
#include "secantMethod.h"
#include "cramerMethod.h"
#include "basititerasyonMethod.h"
#include "gaussseidalMethod.h"
#include "gausseliminasyonMethod.h"
int main() {

	//Turkcelestirme
	setlocale(LC_ALL, "Turkish");

	//Onemli Uyarilar
	printf("Kullanýlacak fonksiyonlarý lütfen polinom olarak veriniz.\n\n");

	//Degisken tanimlari
	int islem = 0;
	char tekrar = 'e';

	while (tekrar == 'e') {
		//Islem secimi
		printf( "\n\n               *************************************\n"
		     	"                  Lineer Olmayan Denklem Takýmlarý         \n"
		        "                  Kapalý Yöntemler:                       \n"
		        "                    1- Grafik Metodu                 \n"
				"                    2- Bisection Metodu              \n"
				"                    3- Regula Falsi Metodu           \n"
				"                  Açýk Yöntemler:                    \n"
				"                    4- Newton Raphson Metodu         \n"
				"                    5- Basit Ýterasyon Metodu         \n"
				"                    6- Secant Kiris Metodu             \n\n"                             
	            "                  Lineer (Doðrusal) Denklem Takýmlarý    \n"
				"                  Dolaysýz Yöntemler:                  \n"
				"                    7-Cramer Metodu                 \n"
				"                    8-Gauss Eliminasyon Metodu       \n"
				"                    9-Gauss Jordan Metodu          \n"
				"                  Dolaylý Yöntemler:              \n"
				"                    10- Gauss-Seidal Metodu       \n\n"
			    "                  Ýntegral Formülleri            \n"
				"                    11- Trapez Metodu             \n"
				"                    12- Simpson Metodu           \n"
				"\n               *************************************\n"
				"\nYapmak istediginiz iþlemin numarasini giriniz: ");
		scanf("%d", &islem);

		switch (islem) {
		case (1):
			graphical();
			break;
		case (2):
			bisection();
			break;
		case (3):
			regulaFalsi();
			break;
		case (4):
			newtonRaphson();
			break;
	    case (5):
			basit_iterasyon();
			break;
	    case (6):
			secant_kiris();
			break;
		case (7):
			cramer();
			break;
	    case (8):
		    gausseliminasyon();
			break;
		case (9):
			gaussJordan();
			break;
		case (10):
			gaussseidal();
			break;
		case (11):
			trapezodial();
			break;
     	case (12):
			simpson();
			break;
		default:
			printf("Ýþlem seçilmedi.");
		}
		//Tekrarlayim mi?
		tekrar = 'h';
		printf("\n\nTekrar iþlem yapmak istiyor musunuz (e/h)? ");
		scanf(" %c", &tekrar);

		//tekrar karakter kontrolu
		while(tekrar != 'e' && tekrar != 'h'){
			printf("\"%c\" geçerli deðildir.\n"
		  "Lütfen geçerli karakter giriniz (e/h): ", tekrar);
			scanf(" %c", &tekrar);
		}

		printf("\n");
	}

	return 0;
}
