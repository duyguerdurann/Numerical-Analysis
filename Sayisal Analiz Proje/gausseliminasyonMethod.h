#ifndef GAUSSELIMINASYONMETHOD_H_
#define GAUSSELIMINASYONMETHOD_H_

gausseliminasyon() {
  int i,j,n,k;
  float A[30][30],C[n],X[n],sum,B[30][30],c[n];
      /*katsayilar matrisini alma*/
  printf("Bilinmeyen sayisini giriniz:");   scanf("%d",&n);
  printf("Sirasiyla katsayilar matrisinin elemanlarini giriniz:\n");
  for(i=1;i<=n;i++){
   for(j=1;j<=n;j++){
     printf("A[%d][%d] :", i,j);scanf("%f",&A[i][j]);
     B[i][j]=A[i][j];
                    }
                   }
     /*B[][] yedek katsayilar matrisi*/
system("cls");
     /*sonuc matrisinin elemanlarini alma */
  printf("sirasiyla sonuc matrisinin elemanlarini giriniz:\n"); 
  for(j=1;j<=n;j++){
   printf("C[%d] :",j);
   scanf("%f", &C[j]);
                   }
/*yedek sonuc matrisi*/
for(i=1;i<=n;i++){
c[i]=C[i];
                 }

system("cls");

printf("\n");

for(i=1;i<=n;i++){ // matrisi yazdirdik
for(j=1;j<=(n);j++){
printf("%.2f ",A[i][j]);
}
printf("|%.2f\n",C[i]);
}

for(k=1;k<=n;k++){                    //ust ucgen matris olusumu
for(i=k;i<=n;i++){
printf("\n%d . satir A[%d][%d] e bolunur",i,i,k);
for(j=(k+1);j<=n;j++){
A[i][j]=A[i][j]/A[i][k];
}

C[i]=C[i]/A[i][k];
A[i][k]=1;

printf("\n");


for(i=1;i<=n;i++){ // matrisi yazdirdik
for(j=1;j<=(n);j++){
printf("%.2f ",A[i][j]);
}
printf("|%.2f\n",C[i]);
}


}
for(i=(k+1);i<=n;i++){
printf("\n%d . satirdan %d. satir cikarilir",i,k);
for(j=1;j<=n;j++){
A[i][j]=A[i][j]-A[k][j];

}
C[i]=C[i]-C[k];
printf("\n");


for(i=1;i<=n;i++){ // matrisi yazdirdik
for(j=1;j<=(n);j++){
printf("%.2f ",A[i][j]);
}
printf("|%.2f\n",C[i]);
}

}
printf("\n devam etmek icin bir tusa basin");
getch();
system("cls");
}

system("pause");

printf("\n devam etmek icin bir tusa basin");
getch();
system("cls");

X[n]=C[n]/A[n][n];

for(i=(n-1);i>=1;i--){
sum=0;
for(j=(i+1); j<=n;j++){
sum=sum+A[i][j]*X[j];
}
X[i]=(C[i]-sum)/A[i][i];
}

printf("\nGauss eliminasyon yontemine gore sonuclar: \n");

for(i=1;i<=n;i++){
printf("\nX%d=%.2f",i,X[i]);
}

printf("\n\n");
for(i=1;i<=n;i++){
for(j=1;j<=n;j++){
printf("+(%.2f)* %.2f ",X[j],B[i][j]);
}
printf("=%.2f\n",c[i]);
printf("\n");
}

return 0;

}

#endif /* GAUSSELIMINASYONMETHOD_H_ */
