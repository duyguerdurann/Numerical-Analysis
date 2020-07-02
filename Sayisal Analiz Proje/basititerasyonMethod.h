#ifndef BASITITERASYONMETHOD_H_
#define BASITITERASYONMETHOD_H_


basit_iterasyon() {
	// fonksiyon=2*x-1-sin(x*pi/180);
	double x;
	double gx;
	double hx;
	double epsilon;
	printf("Baslangic Icin Bir Epsilon Degeri Girin. (En Cok 4 Decimal Olmalidir):");
	scanf("%lf",&epsilon);
	
	printf("X Icin Bir Baslangic Degeri Girin:");
	scanf("%lf",&x);
	gx=x;
	//kullan�c�dan bir ba�lang��(Xo) De�erini Girmesini �stiyoruz Ve Bu De�eri,
	//gx de�i�kenimize at�yoruz bunun sebebi;fonksiyonumuzu iki par�aya ay�r�rken gx k�sm�nda sadece x de�i�keni kal�yordu ve gerisi
	//hx fonksiyonuna dahil oluyordu.
	//Fonksiyon ay�rmas�n� �u �ekilde yapt�m;
	//gx=x	hx=(-1-sin(x))/2
	double fark=10;		//While d�ng�s�ne sa�l�kl� girmek i�in fark de�i�kenimizi olu�turup 10 gibi ge�ici bir de�er verdim.
	int temp=0;			//Ge�ici bir de�i�ken olu�turdum bunun sebebi ise gx=hx atamas�n� 2.ad�m ve sonras�nda yap�lmas�n�n daha sa�l�kl� oluca�� i�in
	
	//While d�ng�m�z elde edilen fark�n�n(son iki hx de�erlerinin) mutlak de�erinin epsilondan b�y�k oldu�u s�rece devam edicektir.
	while(fabs(fark)>epsilon){
		
		if(temp==0){ // temp de�i�kenimizin g�revi bu if blo�undan sonra bitiyor
			hx=(-1-sin(x))/2; // Kullanicidan Girilen X degiskenine ba�l�(g(x) sayd���m�z de�er) hx fonksiyonunda i�leme girer.
			fark=fabs(gx-hx); //fabs fonksiyonu ile gx ve hx de�erlerinin farklar�n�n mutlak de�erleri al�n�r.
			printf("g(x)=%lf		h(x)=%lf		|Xk-Xk+1|=%lf\n",gx,hx,fark);	//Elde edilen de�erler s�ras�yla yazd�r�l�r.
			temp+=1;	//temp de�i�keni artt�r�l�r ve while d�ng�s� bu blo�a birdaha girmez.
		}
		
		gx=hx;	//iterasyon devam etti�i i�in hx de�eri gx de�i�kenine at�l�r.
		hx=(-1-sin(gx))/2;
		fark=fabs(hx-gx);
		printf("g(x)=%lf		h(x)=%lf		|Xk-Xk+1|=%lf\n",gx,hx,fark);	
	}
	
	printf("Iterasyon Tamamlanmistir Bulunan Kok Degeri=%lf",hx);
	
	return 0;
}

#endif /*BASITITERASYONMETHOD_H_ */
