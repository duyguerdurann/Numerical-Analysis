#ifndef CRAMERMETHOD_H_
#define CRAMERMETHOD_H_

float det3(int a[3][3])
{
	return (a[0][0]*a[1][1]*a[2][2])-(a[0][0]*a[1][2]*a[2][1]),
				+(a[0][1]*a[1][2]*a[2][0])-(a[0][1]*a[1][0]*a[2][2]),
				+(a[0][2]*a[1][0]*a[2][1])-(a[0][2]*a[1][1]*a[2][0]);
}


void cramer()

	{
	    int A[3][3];

	    int B[3];

	    printf("Katsayilar seklinde giriniz. sonucta girilcektir. ör: 2 -6 4 8 .");

	    printf("\n\n 1.satir: ");

	    scanf("%f %f %f %f", &A[0][0], &A[0][1], &A[0][2], &B[0]);

	    printf(" 2.satir: ");

	    scanf("%f %f %f %f", &A[1][0], &A[1][1], &A[1][2], &B[1]);

	    printf(" 3.satir: ");

	    scanf("%f %f %f %f", &A[2][0], &A[2][1], &A[2][2], &B[2]);

	    /* determinant bulma*/

	    int detx[3][3] = {{B[0],A[0][1],A[0][2]},{B[1],A[1][1],A[1][2]},

	                          {B[2],A[2][1],A[2][2]}};

	    int dety[3][3] = {{A[0][0],B[0],A[0][2]},{A[1][0],B[1],A[1][2]},

	                          {A[2][0],B[2],A[2][2]}};

	    int detz[3][3] = {{A[0][0],A[0][1],B[0]},{A[1][0],A[1][1],B[1]},

	                          {A[2][0],A[2][1],B[2]}};

	    /* tek cözüm varsa */

	      if(det3(A)!=0)

	             printf("\n Tek cözüm: ( %.2f, %.2f, %.2f)",

	            (float)det3(detx)/det3(A), (float)det3(dety)/det3(A), (float)det3(detz)/det3(A));

	      else

	             printf("\ncözüm yok determinant  0");

	   // return 0;

	}

#endif /* CRAMERMETHOD_H_ */
