#ifndef GAUSSSEIDALMETHOD_H_
#define GAUSSSEIDALMETHOD_H_
// denklemin kendisine göre kodlanmistir.
/* maksimum olan  diyogonel eslenmis denklemin hali
   3x -2y +z = 2
   x + 4y -3z = 0
   2x -y + 3z = 9
*/
/* denklem cözümü 
   x= (2+2*y-z)/3
   y= (0-x+3*z)/4
   z= (9-2*x+y)/3
*/
/* tanimladik */
#define f1(x,y,z)  (2+2*y-z)/3
#define f2(x,y,z)  (0-x+3*z)/4
#define f3(x,y,z)  (9-2*x+y)/3


int gaussseidal()
{
 float x0=0, y0=0, z0=0, x1, y1, z1, e1, e2, e3, e;
 int count=1;

 printf("epsilon degerini girin:\n");
 scanf("%f", &e);

 printf("\nCount\tx\ty\tz\n");
 do
 {
  /* hesaplama */
  x1 = f1(x0,y0,z0);
  y1 = f2(x1,y0,z0);
  z1 = f3(x1,y1,z0);
  printf("%d\t%0.4f\t%0.4f\t%0.4f\n",count, x1,y1,z1);

  /* hata */
  e1 = fabs(x0-x1);
  e2 = fabs(y0-y1);
  e3 = fabs(z0-z1);

  count++;

  /* bir sonraki iterasyon degerleri */
  x0 = x1;
  y0 = y1;
  z0 = z1;

 }while(e1>e && e2>e && e3>e);

 printf("\n Kokler:  x=%0.2f, y=%0.2f and z = %0.2f\n",x1,y1,z1);

 getch();
 return 0;
}

#endif /* GAUSSSEIDALMETHOD_H_ */
