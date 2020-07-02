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
	//kullanýcýdan bir baþlangýç(Xo) Deðerini Girmesini Ýstiyoruz Ve Bu Deðeri,
	//gx deðiþkenimize atýyoruz bunun sebebi;fonksiyonumuzu iki parçaya ayýrýrken gx kýsmýnda sadece x deðiþkeni kalýyordu ve gerisi
	//hx fonksiyonuna dahil oluyordu.
	//Fonksiyon ayýrmasýný þu þekilde yaptým;
	//gx=x	hx=(-1-sin(x))/2
	double fark=10;		//While döngüsüne saðlýklý girmek için fark deðiþkenimizi oluþturup 10 gibi geçici bir deðer verdim.
	int temp=0;			//Geçici bir deðiþken oluþturdum bunun sebebi ise gx=hx atamasýný 2.adým ve sonrasýnda yapýlmasýnýn daha saðlýklý olucaðý için
	
	//While döngümüz elde edilen farkýnýn(son iki hx deðerlerinin) mutlak deðerinin epsilondan büyük olduðu sürece devam edicektir.
	while(fabs(fark)>epsilon){
		
		if(temp==0){ // temp deðiþkenimizin görevi bu if bloðundan sonra bitiyor
			hx=(-1-sin(x))/2; // Kullanicidan Girilen X degiskenine baðlý(g(x) saydýðýmýz deðer) hx fonksiyonunda iþleme girer.
			fark=fabs(gx-hx); //fabs fonksiyonu ile gx ve hx deðerlerinin farklarýnýn mutlak deðerleri alýnýr.
			printf("g(x)=%lf		h(x)=%lf		|Xk-Xk+1|=%lf\n",gx,hx,fark);	//Elde edilen deðerler sýrasýyla yazdýrýlýr.
			temp+=1;	//temp deðiþkeni arttýrýlýr ve while döngüsü bu bloða birdaha girmez.
		}
		
		gx=hx;	//iterasyon devam ettiði için hx deðeri gx deðiþkenine atýlýr.
		hx=(-1-sin(gx))/2;
		fark=fabs(hx-gx);
		printf("g(x)=%lf		h(x)=%lf		|Xk-Xk+1|=%lf\n",gx,hx,fark);	
	}
	
	printf("Iterasyon Tamamlanmistir Bulunan Kok Degeri=%lf",hx);
	
	return 0;
}

#endif /*BASITITERASYONMETHOD_H_ */
