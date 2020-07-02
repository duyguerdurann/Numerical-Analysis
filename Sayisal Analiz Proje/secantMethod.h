#ifndef SECANT_KIRIS_H_
#define SECANT_KIRIS_H_
// verilen fonksiyona göre kodlanmistir.
float f(float x)
{
    //return(x*x*x*x-4*x*x*x+7*x*x-10*x-6); // f(x)= x^4-4x^3+7x^2-10x-6
    return(2*x*x*x-5*x*x-3*x+7.5); // f(x)= 2x^3-5x^2-3x+7,5
}

secant_kiris()
{   
    float a,b,c,d,e;
    int count=1,n;
    printf("\n\n alt limit ile ust limiti bosluk birakarak girin:\n"); //(a,b) 
    scanf("%f%f",&a,&b);
    printf("epsilon degeri ve maksimum iterasyon sayisini bosluk birakarak girin:\n");
    scanf("%f %d",&e,&n);
    do
    {
        if(f(a)==f(b))
        {
            printf("\n Bu aralikta cözüm bulunamadi.\n");
        return;
        }
        c=(a*f(b)-b*f(a))/(f(b)-f(a));
        a=b;
        b=c;
        printf("Iterasyon Sayisi-%d    x=%f\n",count,c);
        count++;
        if(count==n)
        {
        break;
        }
    } while(fabs(f(c))>e);
    printf("\n sonuc: %f\n",c);
 
}


#endif /* SECANT_KIRIS_H_ */
