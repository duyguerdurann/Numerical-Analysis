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
	printf("Kullan�lacak fonksiyonlar� l�tfen polinom olarak veriniz.\n\n");

	//Degisken tanimlari
	int islem = 0;
	char tekrar = 'e';

	while (tekrar == 'e') {
		//Islem secimi
		printf( "\n\n               *************************************\n"
		     	"                  Lineer Olmayan Denklem Tak�mlar�         \n"
		        "                  Kapal� Y�ntemler:                       \n"
		        "                    1- Grafik Metodu                 \n"
				"                    2- Bisection Metodu              \n"
				"                    3- Regula Falsi Metodu           \n"
				"                  A��k Y�ntemler:                    \n"
				"                    4- Newton Raphson Metodu         \n"
				"                    5- Basit �terasyon Metodu         \n"
				"                    6- Secant Kiris Metodu             \n\n"                             
	            "                  Lineer (Do�rusal) Denklem Tak�mlar�    \n"
				"                  Dolays�z Y�ntemler:                  \n"
				"                    7-Cramer Metodu                 \n"
				"                    8-Gauss Eliminasyon Metodu       \n"
				"                    9-Gauss Jordan Metodu          \n"
				"                  Dolayl� Y�ntemler:              \n"
				"                    10- Gauss-Seidal Metodu       \n\n"
			    "                  �ntegral Form�lleri            \n"
				"                    11- Trapez Metodu             \n"
				"                    12- Simpson Metodu           \n"
				"\n               *************************************\n"
				"\nYapmak istediginiz i�lemin numarasini giriniz: ");
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
			printf("��lem se�ilmedi.");
		}
		//Tekrarlayim mi?
		tekrar = 'h';
		printf("\n\nTekrar i�lem yapmak istiyor musunuz (e/h)? ");
		scanf(" %c", &tekrar);

		//tekrar karakter kontrolu
		while(tekrar != 'e' && tekrar != 'h'){
			printf("\"%c\" ge�erli de�ildir.\n"
		  "L�tfen ge�erli karakter giriniz (e/h): ", tekrar);
			scanf(" %c", &tekrar);
		}

		printf("\n");
	}

	return 0;
}
