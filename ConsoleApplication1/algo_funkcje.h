#ifndef ALGO_H
#define	ALGO_H
#endif

#include "CSVRow.h"

class algo_funkcje {
	public: algo_funkcje(){
		karty = new int[10];
		kkk = new int[10];
		ooo = new int[10];
		tabpom1 = new int[10];
		tabpom2 = new int[10];
		tabpom3 = new int[10];
		wspolnymianownik = new int[10];
		temp2 = new int[20];
		//cout << "konsturktor " << endl;
		
		licznik = 0;
	}	

    public: int* karty; //orginalna
    public: int* kkk;//tymczasowa
    public: int* ooo;//tymczasowa
    public: int* temp2;//tymczasowa
    public: int* tabpom1;//tymczasowa
    public: int* tabpom2;//tymczasowa
    public: int* tabpom3;//tymczasowa
    
    public: int* wspolnymianownik;//tymczasowa
    
    public: int mt;
    public: int mt2;
    public: int mt3;
    public: int mt4;
    public: int returned_typ;
    public: int returned_color;
    public: int returned_moc;
    public: int returned_moc2;
    public: int returned_moc3;
    public: int returned_moc4;
    public: int returned_moc5;
    public: int returned_ace;
    
    
    public: int debug;
    public: int ace;
    public: int oesd;
    public: int licznik;
    
    public: int xx;
	public: int yy;
	public: int zz;

    public: void zeruj(){
        for (int xx=1;xx<=7;xx++){
            kkk[xx]=0;
            ooo[xx]=0;
            tabpom1[xx]=0;
            tabpom2[xx]=0;
            tabpom3[xx]=0;
        }
        for (int xx=0;xx<=19;xx++){
            temp2[xx]=0;
        }
        mt=0;
        mt2=0;
        mt3=0;
        mt4=0;        
        returned_typ=0;
        returned_color=0;
		returned_moc=0;
		returned_moc2=0;
		returned_moc3=0;
		returned_moc4=0;
		returned_moc5=0;
        ace=0;
        oesd=0;        
    }
    
    public: void wspolny_mianownik(){
       //tablic ktora zmieni 15,16,17 na mniejsze liczby 2,3,4
       //zamiana do wspolnego mianwnika 2-14
       for (int xx=1;xx<=7;xx++){
         if ((karty[xx]>=2) & (karty[xx]<=14)){  wspolnymianownik[xx]=karty[xx];  }
         if ((karty[xx]>=15) & (karty[xx]<=27)){  wspolnymianownik[xx]=karty[xx]-13;  }
         if ((karty[xx]>=28) & (karty[xx]<=40)){  wspolnymianownik[xx]=karty[xx]-26;  }
         if ((karty[xx]>=41) & (karty[xx]<=53)){  wspolnymianownik[xx]=karty[xx]-39;  }
       }
    }


/*******************************************************************************
*
*                         1. POKER KROLEWSKI
*
*******************************************************************************/
    public: bool uklad1(){
        zeruj();
        int mmx=0;
        for (int mx=1;mx<=4;mx++){
            if (mx==1){mmx=0;}
            if (mx==2){mmx=-13;}
            if (mx==3){mmx=-26;}
            if (mx==4){mmx=-39;}
            kkk[1]=karty[1]+mmx;
            kkk[2]=karty[2]+mmx;
            kkk[3]=karty[3]+mmx;
            kkk[4]=karty[4]+mmx;
            kkk[5]=karty[5]+mmx;
            kkk[6]=karty[6]+mmx;
            kkk[7]=karty[7]+mmx;
            for (int i=1;i<=7;i++){
                if (this->kkk[i]==10){
                    this->kkk[i]=0;
                    for (int j=1;j<=7;j++){
                        if (this->kkk[j]==11){
                            this->kkk[j]=0;
                            for (int k=1;k<=7;k++){
                                if (kkk[k]==12){
                                    kkk[k]=0;
                                    for (int l=1;l<=7;l++){
                                        if (kkk[l]==13){
                                            kkk[l]=0;
                                            for (int m=1;m<=7;m++){
                                                if (kkk[m]==14){
                                                    kkk[m]=0;
                                                    if ((kkk[6]==0) ||(kkk[7]==0)) {                              
                                                        returned_typ=1;
                                                        returned_color=mx;
                                                        if (debug==1) {kolory->komunikat(" FUNCTION (1) pokerkrolewski -> true \n");} 
                                                        return 1;                                                                                     
                                                    } else {
                                                        if (debug==1) {kolory->komunikat(" FUNCTION (1) pokerkrolewski -> false \n");}
                                                        return 0;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        if (debug==1) {kolory->komunikat(" FUNCTION (1) pokerkrolewski -> false \n");}
        return 0;
    }


/*******************************************************************************
*
*                         2. POKER
*
*******************************************************************************/
    public: bool uklad2(){
        zeruj();
        int mmx=0;
        for (int mx=1;mx<=4;mx++){
            if (mx==1){mmx=0;}
            if (mx==2){mmx=-13;}
            if (mx==3){mmx=-26;}
            if (mx==4){mmx=-39;}
            for (int nn=0;nn<=7;nn++){
                kkk[1]=karty[1]+mmx;
                kkk[2]=karty[2]+mmx;
                kkk[3]=karty[3]+mmx;
                kkk[4]=karty[4]+mmx;
                kkk[5]=karty[5]+mmx;
                kkk[6]=karty[6]+mmx;
                kkk[7]=karty[7]+mmx;
                for (int i=1;i<=7;i++){          
                    if (kkk[i]==(2+nn)){
                        ooo[2]=kkk[i];
                        kkk[i]=0;
                        for (int j=1;j<=7;j++){                            
                            if (kkk[j]==3+nn){
                                kkk[j]=0;
                                for (int k=1;k<=7;k++){
                                    if (kkk[k]==4+nn){
                                        kkk[k]=0;
                                        for (int l=1;l<=7;l++){
                                            if (kkk[l]==5+nn){
                                                kkk[l]=0;
                                                for (int m=1;m<=7;m++){
                                                    if (kkk[m]==6+nn){
                                                        kkk[m]=0;
                                                        if ((kkk[6]==0) || (kkk[7]==0)) {
                                                            returned_typ=2;
                                                            returned_moc=2+nn;
                                                            returned_color=mx;
                                                            //szukacz=1;
                                                            if (debug==1) {kolory->komunikat(" FUNCTION (2) poker -> true \n"); }
                                                            return 1;
                                                        } else {
                                                            if (debug==1) {kolory->komunikat(" FUNCTION (2) poker -> false \n"); }
                                                            return 0;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        if (debug==1) {kolory->komunikat(" FUNCTION (2) poker -> false \n"); }
        return 0;
    }



/*******************************************************************************
*
*                         3. KARETA
*
*******************************************************************************/
    
    public: bool uklad3(){
        zeruj();
        kkk[1]=karty[1];
        kkk[2]=karty[2];
        kkk[3]=karty[3];
        kkk[4]=karty[4];
        kkk[5]=karty[5];
        kkk[6]=karty[6];
        kkk[7]=karty[7];

        //powzcuanie kart do odpowiednich stoisk w talbicy
        for (int zz=0;zz<=12;zz++){
            for (int xx=1;xx<=7;xx++){
                if ((kkk[xx]==2+zz) || (kkk[xx]==15+zz) || (kkk[xx]==28+zz) || (kkk[xx]==41+zz)){
                    temp2[zz+1]=temp2[zz+1]+1;
                }
            }
        }
        
        //wyszukanie najwyzszego elemntu w tablicy
        for (int zz=1;zz<=13;zz++){
          if (temp2[zz]==4) {
              mt=zz+1;
        }}
        //zamiana do wspolnego mianwnika 2-14
        /////////System.arraycopy(wspolny_mianownik(impor), 0, tabpom1, 0,  10);
        //tabpom1=wspolny_mianownik(impor);
        
		wspolny_mianownik();

        //znalezienie w puli czworki i wyzerowanie jej
        for (int zz=1;zz<=4;zz++){
            for (int xx=1;xx<=7;xx++){
                if (wspolnymianownik[xx]==mt){
                    wspolnymianownik[xx]=0;
                    break;
                }
            }
        }

        //sorotowanie od najwiekszej do najmniejszej
        tabpom3[1]=wspolnymianownik[1];
        tabpom3[2]=wspolnymianownik[2];
        tabpom3[3]=wspolnymianownik[3];
        tabpom3[4]=wspolnymianownik[4];
        tabpom3[5]=wspolnymianownik[5];
        tabpom3[6]=wspolnymianownik[6];
        tabpom3[7]=wspolnymianownik[7];

        //znajduje najwyzsza karte poza kareta
        int pom=0;
        int el=0; //element do wymazania
        for (xx=1;xx<=7;xx++){
			if (pom<tabpom3[xx]){
				pom=tabpom3[xx];  //pom2=i;
				el=xx;
			}
        }
        tabpom3[el]=0;

        //sprawdzenie czy karta 1 znajduje sie w Twoich rekach
        kkk[1]=karty[1];
        kkk[2]=karty[2];
        kkk[3]=karty[3];
        kkk[4]=karty[4];
        kkk[5]=karty[5];
        kkk[6]=karty[6];
        kkk[7]=karty[7];

        //System.out.println("test1: "+kkk[1]+"/"+kkk[2]+"/" +kkk[3]+"/" +kkk[4]+"/" +kkk[5]+"/" +kkk[6]+"/" +kkk[7]);
        //System.out.println("test2: "+tabpom2[1]+"/"+tabpom2[2]+"/" +tabpom2[3]+"t/" +tabpom2[4]+"/" +tabpom2[5]+"/" +tabpom2[6]+"/" +tabpom2[7]);
        //System.out.println("test3: "+wspolnymianownik[1]+"/"+wspolnymianownik[2]+"/" +wspolnymianownik[3]+"/" +wspolnymianownik[4]+"/" +wspolnymianownik[5]+"/" +wspolnymianownik[6]+"/" +wspolnymianownik[7]);
        int kontrol2=0;
        if ((mt==kkk[6]) || (mt==kkk[7])) {
           kontrol2=1;
        }
        if ((tabpom3[6]==0) || (tabpom3[7]==0)) { //jesli ktoras z twoich kart byla wzieta to ma teraz 0
           kontrol2=1;
        }

        if (mt!=0) {
            if (((wspolnymianownik[6]==0) || (wspolnymianownik[7]==0) || (kontrol2 == 1)) && (mt!=0))  {  
                // expor[1]=3;
                // expor[2]=mt;
                // expor[3]=pom;
                // szukacz=1;
                returned_typ=3;
                returned_moc=mt;
                if (debug==1) {kolory->komunikat( " FUNCTION (3) kareta -> true \n"); }
                return 1;

            } else { 
                if (debug==1) {kolory->komunikat( " FUNCTION (3) kareta -> false \n"); }
                return 0;
            } 
        }      
        if (debug==1) {kolory->komunikat( " FUNCTION (3) kareta -> false \n"); }
        return 0;
    }


/*******************************************************************************
*
*                         4. FULL
*
*******************************************************************************/
    public: bool uklad4(){
        zeruj();
        kkk[1]=karty[1];
        kkk[2]=karty[2];
        kkk[3]=karty[3];
        kkk[4]=karty[4];
        kkk[5]=karty[5];
        kkk[6]=karty[6];
        kkk[7]=karty[7];
        
        //powzcuanie kart do odpowiednich stoisk w talbicy
        for (zz=2;zz<=14;zz++){
            for (xx=1;xx<=7;xx++){
                if ((kkk[xx]==zz) || (kkk[xx]==13+zz) || (kkk[xx]==26+zz) || (kkk[xx]==39+zz)){
                    temp2[zz]=temp2[zz]+1;
                }
            }
        }

        //wyszukanie par i trojek
        for (zz=2;zz<=14;zz++){
                if (temp2[zz]==3) {
                temp2[zz]=0;
                mt=zz;
                break;
            }
        }

        for (zz=2;zz<=14;zz++){
            if (temp2[zz]==3) {
                temp2[zz]=0;
                mt3=zz;
                break;
            }
        }

        for (zz=2;zz<=14;zz++){
            if (temp2[zz]==2) {
                temp2[zz]=0;
                mt2=zz;
                break;
            }
        }

        for (zz=2;zz<=14;zz++){
            if (temp2[zz]==2) {
                temp2[zz]=0;
                mt4=zz;
                break;
            }
        }

        wspolny_mianownik();

        

        
        

        if (mt>mt3) {
        //wyzerowanie kart ktore tworza uklad
            for (xx=1;xx<=7;xx++) {
                if (wspolnymianownik[xx]==mt) wspolnymianownik[xx]=0;
            }
            if (mt3!=0) {
                //wyzerowanie kart ktore tworza uklad
                for (xx=1,licznik=1;xx<=7;xx++) {
                    if (wspolnymianownik[xx]==mt3) {
                        if (licznik<3){
                            wspolnymianownik[xx]=0;
                            licznik++;
                        }
                    }
                }
            }
        } else {
            int tempa=mt;  //gorsze karty
            int tempb=mt3; //leszpe karty
            mt=tempb; //leszpe karty
            mt2=tempa; //gorsze karty
            //wyzerowanie kart ktore tworza uklad
            for (xx=1;xx<=7;xx++) {
                if (wspolnymianownik[xx]==mt) wspolnymianownik[xx]=0;
            }
            //wyzerowanie kart ktore tworza uklad
            for (xx=1, licznik=1;xx<=7;xx++) {
                if (wspolnymianownik[xx]==mt2){
                    if (licznik<3) {
                        wspolnymianownik[xx]=0;
                        licznik++;
                    }
                }
            }
        }

        
        
        
        
        if (mt3==0) {
            if (mt2>mt4) {
            //wyzerowanie kart ktore tworza uklad
                for (xx=1;xx<=7;xx++) {
                if (wspolnymianownik[xx]==mt2)
                wspolnymianownik[xx]=0;
                }
            } else {
                int tempb=mt4; //leszpe karty
                mt2=tempb; //leszpe karty
                //wyzerowanie kart ktore tworza uklad
                for (xx=1;xx<=7;xx++) {
                    if (wspolnymianownik[xx]==mt2) wspolnymianownik[xx]=0;
                }
            }
        }

        //sprawdzenie czy karta 1 i 2 znajduje sie w Twoich rekach
        kkk[1]=karty[1];
        kkk[2]=karty[2];
        kkk[3]=karty[3];
        kkk[4]=karty[4];
        kkk[5]=karty[5];
        kkk[6]=karty[6];
        kkk[7]=karty[7];

        
        if ((mt!=0) && (mt2!=0)) {
            if ((wspolnymianownik[6]==0) || (wspolnymianownik[7]==0))  {
                //expor[1]=4;
                //expor[2]=mt;
                //expor[3]=mt2;
                //szukacz=1;
                if (debug==1) { kolory->komunikat(" FUNCTION (4) full -> true \n"); }
                returned_typ=4;
                returned_moc=mt;
                returned_moc2=mt2;
                return 1;
            } else {
               if (debug==1) { kolory->komunikat(" FUNCTION (4) full -> false \n"); }
                return 0;
            }
        }
        if (debug==1) { kolory->komunikat( " FUNCTION (4) full -> false \n"); }
        return 0;
    }


    
/*******************************************************************************
*
*                         5. KOLOR
*
*******************************************************************************/
    public: bool uklad5(){
        zeruj();
        int mmx=0;
        for (int mx=1;mx<=4;mx++){
            if (mx==1){mmx=0;}
            if (mx==2){mmx=-13;}
            if (mx==3){mmx=-26;}
            if (mx==4){mmx=-39;}
            kkk[1]=karty[1]+mmx;
            kkk[2]=karty[2]+mmx;
            kkk[3]=karty[3]+mmx;
            kkk[4]=karty[4]+mmx;
            kkk[5]=karty[5]+mmx;
            kkk[6]=karty[6]+mmx;
            kkk[7]=karty[7]+mmx;

            for (int n=2;n<=9;n++){
                ooo[n]=0;
            }
            int j=2;
            for (int i=1;i<=7;i++){
                if ((kkk[i]>=2) & (kkk[i]<=14)){
                    ooo[j]=kkk[i];
                    kkk[i]=0;
                    j++;
                }
            }
            
            //jesli znajduje sie 5 elementow tego samego koloru
            if (ooo[6]!=0){
                ooo[1]=5;
                //int temp=array(); zamienione tabpom2
                int pom=0;
                int pom2=0; //gdzie ostatnio bylo i
                //sortowanie od najwiekszej do najmniejszej
                for (int a=2;a<=j;a++){
                    int i=0;
                    for (i=2;i<=j;i++){
                        if (pom<ooo[i]){
                            pom=ooo[i];  pom2=i;
                        }
                    }
                    ooo[pom2]=0;
                    tabpom2[a]=pom;
                    pom=0;
                }
                tabpom1[1]=tabpom2[2];
                tabpom1[2]=tabpom2[3];
                tabpom1[3]=tabpom2[4];
                tabpom1[4]=tabpom2[5];
                tabpom1[5]=tabpom2[6];
                tabpom1[6]=0;
                tabpom1[7]=0;

                kkk[1]=karty[1]+mmx;
                kkk[2]=karty[2]+mmx;
                kkk[3]=karty[3]+mmx;
                kkk[4]=karty[4]+mmx;
                kkk[5]=karty[5]+mmx;
                kkk[6]=karty[6]+mmx;
                kkk[7]=karty[7]+mmx;

                int kontrol=0;
                //sprawdzenie czy kolory znajduja sie w puli gracza
                for (xx=1;xx<=5;xx++){
                    if ((tabpom1[xx]==kkk[6]) || (tabpom1[xx]==kkk[7])){
                        kontrol=1;
                    }
                }
                if (kontrol ==1){
                    if (debug==1) {kolory->komunikat(" FUNCTION (5) kolor -> true \n"); }
                    return 1;
                    returned_typ = 5;
                    returned_moc = tabpom1[1];
                    returned_moc2 = tabpom1[2];
                    returned_moc3 = tabpom1[3];
                    returned_moc4 = tabpom1[4];
                    returned_moc5 = tabpom1[5];
                    returned_color = mx;
                    //szukacz=1;
                    //expor[1]=5;
                    //expor[2]=tabpom1[1];
                    //expor[3]=tabpom1[2];
                    //expor[4]=tabpom1[3];
                    //expor[5]=tabpom1[4];
                    //expor[6]=tabpom1[5];
                    //expor[7]=mx;
                } else { 
                    if (debug==1) {kolory->komunikat(" FUNCTION (5) kolor -> false \n"); }
                    return 0;
                }
            }
        }
        if (debug==1) {kolory->komunikat(" FUNCTION (5) kolor -> false \n"); }
        return 0;
    }





/*******************************************************************************
*
*                         6. STRIT
*
*******************************************************************************/
    public: bool uklad6(){
		zeruj();
		int mmx=0;
		for (int nn=0;nn<=7;nn++){
		    //wspolny mianownik
		    for (zz=1;zz<=7;zz++){
		        int pom=karty[zz];
		        if ((pom>=2) & (pom<=14)) {mmx=0;}
		        if ((pom>=15) & (pom<=27)) {mmx=-13;}
		        if ((pom>=28) & (pom<=40)) {mmx=-26;}
		        if ((pom>=41) & (pom<=53)) {mmx=-39;}
		        kkk[zz]=karty[zz]+mmx;
		    }
			for (int i=1;i<=7;i++){
				if (kkk[i]==2+nn){
					ooo[2]=kkk[i];
					kkk[i]=0;
					for (int j=1;j<=7;j++){
						if (kkk[j]==3+nn){
							kkk[j]=0;
							for (int k=1;k<=7;k++){
								if (kkk[k]==4+nn){
									kkk[k]=0;
									for (int l=1;l<=7;l++){
										if (kkk[l]==5+nn){
										kkk[l]=0;
										    for (int m=1;m<=7;m++){
												if (kkk[m]==6+nn){
												kkk[m]=0;
												//    if (kkk[6]!=0){ooo[4]=kkk[6]; kkk[6]=0;}
												//    if (kkk[7]!=0){ooo[5]=kkk[7]; kkk[7]=0;}
												if ((kkk[6]==0) ||(kkk[7]==0)) {
													ooo[1]=6;
													ooo[3]=0;
													ooo[4]=0;
													ooo[5]=0;
													//expor[1]=6;
													//expor[2]=2+nn;
													//szukacz=1;
													returned_typ = 6;
													returned_moc = 2+nn;													
													
													if (debug==1) {kolory->komunikat(" FUNCTION (6) strit -> true \n"); }
														return 1;
													} else { 
														if (debug==1) {kolory->komunikat(" FUNCTION (6) strit -> false \n"); }
														return 0;
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		
		//---- szukanie strita z Asem
		mmx=0;
		kkk[1]=karty[1]+mmx;
		kkk[2]=karty[2]+mmx;
		kkk[3]=karty[3]+mmx;
		kkk[4]=karty[4]+mmx;
		kkk[5]=karty[5]+mmx;
		kkk[6]=karty[6]+mmx;
		kkk[7]=karty[7]+mmx;
		//wspolny mianownik
		for (zz=1;zz<=7;zz++){
			int pom=karty[zz];
			if ((pom>=2) & (pom<=14)) {mmx=0;}
			if ((pom>=15) & (pom<=27)) {mmx=-13;}
			if ((pom>=28) & (pom<=40)) {mmx=-26;}
			if ((pom>=41) & (pom<=53)) {mmx=-39;}
			kkk[zz]=karty[zz]+mmx;
		}
		
		for (int i=1;i<=7;i++){
			if (kkk[i]==14){
				kkk[i]=0;
				for (int j=1;j<=7;j++){
					if (kkk[j]==2){
						kkk[j]=0;
						for (int k=1;k<=7;k++){
							if (kkk[k]==3){
								kkk[k]=0;
								for (int l=1;l<=7;l++){
									if (kkk[l]==4){
										kkk[l]=0;
										for (int m=1;m<=7;m++){
											if (kkk[m]==5){
												kkk[m]=0;	
												ooo[1]=2;
												ooo[2]=1;
												ooo[3]=0;
												ooo[4]=0;
												ooo[5]=0;
												if ((kkk[6]==0) ||(kkk[7]==0)) {
													
													returned_typ = 6;
													returned_moc = 1;
													returned_ace = 1;
													
													if (debug==1) {kolory->komunikat(" FUNCTION (6) true \n"); }
													return 1;
												} else { 
													if (debug==1) {kolory->komunikat(" FUNCTION (6) false \n"); }
													return 0;
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		
		if (debug==1) {kolory->komunikat(" FUNCTION (6) strit -> false  \n"); }
		return 0;
	}
	

/*******************************************************************************
*
*                         7. TROJKA
*
*******************************************************************************/
    public: bool uklad7(){
        zeruj();
        mt=0;
        kkk[1]=karty[1];
        kkk[2]=karty[2];
        kkk[3]=karty[3];
        kkk[4]=karty[4];
        kkk[5]=karty[5];
        kkk[6]=karty[6];
        kkk[7]=karty[7];
		//powzcuanie kart do odpowiednich stoisk w talbicy
		for (zz=0;zz<=12;zz++){
			for (xx=1;xx<=7;xx++){
				if ((kkk[xx]==2+zz) || (kkk[xx]==15+zz) || (kkk[xx]==28+zz) || (kkk[xx]==41+zz)){
					temp2[zz+1]=temp2[zz+1]+1;
				}
			}
		}
		
		//wyszukanie najwyzszego elemntu w tablicy
		for (zz=1;zz<=13;zz++){
			if (temp2[zz]==3) {
				mt=zz+1;
			}
		}
		//zamiana do wspolnego mianwnika 2-14
		wspolny_mianownik();

		//znalezienie w puli trojki i wyzerowanie jej
		for (zz=1;zz<=3;zz++){
			for (xx=1;xx<=7;xx++){
				if (wspolnymianownik[xx]==mt){
					wspolnymianownik[xx]=0;
					break;
				}
			}
		}
		
		//sorotowanie od najwiekszej do najmniejszej
		tabpom3[1]=wspolnymianownik[1];
		tabpom3[2]=wspolnymianownik[2];
		tabpom3[3]=wspolnymianownik[3];
		tabpom3[4]=wspolnymianownik[4];
		tabpom3[5]=wspolnymianownik[5];
		tabpom3[6]=wspolnymianownik[6];
		tabpom3[7]=wspolnymianownik[7];
		
		int pom=0;
		int pom3=0;

		for (int a=1;a<=7;a++){
			if (pom<tabpom3[a]){
				pom=tabpom3[a];
				// tabpom3[a]=0;
				pom3=a;
			}
		}

		ooo[3]=0;
		ooo[3]=tabpom3[pom3];
		tabpom3[pom3]=0; //po znalezieniu najwyzszej karty pierwszej wyzeruj j¹
		
		int pom2=0;
		pom3=0;
		for (int a=1;a<=7;a++){
			if (pom2<tabpom3[a]){
				pom2=tabpom3[a];
				pom3=a;
			}
		}
		ooo[4]=0;
		ooo[4]=tabpom3[pom3];
		tabpom3[pom3]=0;

		//sprawdzenie czy karta 1 i 2 znajduje sie w Twoich rekach
        kkk[1]=karty[1];
        kkk[2]=karty[2];
        kkk[3]=karty[3];
        kkk[4]=karty[4];
        kkk[5]=karty[5];
        kkk[6]=karty[6];
        kkk[7]=karty[7];
		int kontrol2=0;
		if ((tabpom3[6]==0) || (tabpom3[7]==0)) {
			kontrol2=1;
		}

		if (mt!=0) {
			if ((wspolnymianownik[6]==0) || (wspolnymianownik[7]==0) || kontrol2 == 1)  {
				//expor[1]=7;
				//expor[2]=mt;
				//expor[3]=ooo[3];
				//expor[4]=ooo[4];
				
				returned_typ = 7;
				returned_moc = mt;
				returned_moc2 = ooo[3];
				returned_moc3 = ooo[4];				
				
				//szukacz=1;
				if (debug==1) {kolory->komunikat( " FUNCTION (7) trojka -> true \n"); }
				return 1;
			} else { 
				if (debug==1) {kolory->komunikat( " FUNCTION (7) trojka -> false \n"); }
				return 0;
			}
		}
		if (debug==1) {kolory->komunikat( " FUNCTION (7) trojka -> false \n"); }
	}


/*******************************************************************************
*
*                         8.
*
*******************************************************************************/
    public: bool uklad8(){
        zeruj();
        
        kkk[1]=karty[1];
        kkk[2]=karty[2];
        kkk[3]=karty[3];
        kkk[4]=karty[4];
        kkk[5]=karty[5];
        kkk[6]=karty[6];
        kkk[7]=karty[7];


		//powzcuanie kart do odpowiednich stoisk w talbicy
		for (zz=0;zz<=12;zz++){
			for (xx=1;xx<=7;xx++){
				if ((kkk[xx]==2+zz) || (kkk[xx]==15+zz) || (kkk[xx]==28+zz) || (kkk[xx]==41+zz)){
					temp2[zz+1]=temp2[zz+1]+1;
				}
			}
		}
		
		//wyszukanie najwyzszego elemntu w tablicy
		for (zz=1;zz<=13;zz++){
			if (temp2[zz]==2) {
				mt=zz+1;
			}
		}

		for (zz=1;zz<=13;zz++){
			if ((temp2[zz]==2) && (zz!=mt-1)) {
				mt2=zz+1;
			}
		}
		
		//zamiana do wspolnego mianwnika 2-14
		wspolny_mianownik();

		//znalezienie w puli dwojki i wyzerowanie jej
		for (zz=1;zz<=2;zz++){
			for (xx=1;xx<=7;xx++){
				if (wspolnymianownik[xx]==mt){
					wspolnymianownik[xx]=0;
					break;
				}
			}
		}

		for (zz=1;zz<=2;zz++){
			for (xx=1;xx<=7;xx++){
				if (wspolnymianownik[xx]==mt2){
					wspolnymianownik[xx]=0;
					break;
				}
			}
		}

		//sorotowanie od najwiekszej do najmniejszej
		tabpom3[1]=wspolnymianownik[1];
		tabpom3[2]=wspolnymianownik[2];
		tabpom3[3]=wspolnymianownik[3];
		tabpom3[4]=wspolnymianownik[4];
		tabpom3[5]=wspolnymianownik[5];
		tabpom3[6]=wspolnymianownik[6];
		tabpom3[7]=wspolnymianownik[7];
		int pom2=0;
		int pom3=0;
		for (int a=1;a<=7;a++){
			if (pom2<tabpom3[a]){
				pom2=tabpom3[a];
				pom3=a;
			}
		}
		ooo[4]=0;
		ooo[4]=tabpom3[pom3];
		tabpom3[pom3]=0;

		//texta.append("8@ dwie karty: test tabpom2 ab "+tabpom2[1]+"/"+tabpom2[2]+"/"+tabpom2[3]+"/"+tabpom2[4]+"/"+tabpom2[5]+"/"+tabpom2[6]+"/"+tabpom2[7]+"/"+"\n");
		//sprawdzenie czy karta 1 i 2 znajduje sie w Twoich rekach
        kkk[1]=karty[1];
        kkk[2]=karty[2];
        kkk[3]=karty[3];
        kkk[4]=karty[4];
        kkk[5]=karty[5];
        kkk[6]=karty[6];
        kkk[7]=karty[7];


		int kontrol2=0;
		if ((tabpom3[6]==0) || (tabpom3[7]==0)) {
			kontrol2=1;
		}
		
		if ((mt!=0) && (mt2!=0) && (mt2!=mt)) {
			if ((wspolnymianownik[6]==0) || (wspolnymianownik[7]==0) || kontrol2 == 1) {
				//expor[1]=8;
				
				returned_typ = 8;
				
				if (mt2>mt) { //expor[2]=mt2; expor[3]=mt; 
					returned_moc = mt2;
					returned_moc2 = mt;
				}
				if (mt>mt2) { //expor[2]=mt; expor[3]=mt2; 
					returned_moc = mt;
					returned_moc2 = mt2;
				}
				
				returned_moc3 = ooo[4]; //ostatnia karta
				
				
				//expor[4]=ooo[4];
				// szukacz=1;
				if (debug==1) {kolory->komunikat( " FUNCTION (8) dwiepary -> true \n"); }
				return 1;
			} else {
				if (debug==1) {kolory->komunikat( " FUNCTION (8) dwiepary -> false \n"); }
				return 0;
			}
		}
        
        
		if (debug==1) {kolory->komunikat( " FUNCTION (8) dwiepary -> false \n"); }
		return 0;       
	}
	
/*******************************************************************************
*
*                         9. para
*
*******************************************************************************/
    public: bool uklad9(){
        zeruj();
        
        kkk[1]=karty[1];
        kkk[2]=karty[2];
        kkk[3]=karty[3];
        kkk[4]=karty[4];
        kkk[5]=karty[5];
        kkk[6]=karty[6];
        kkk[7]=karty[7];

		//nowe
		tabpom1[1]=0;
		tabpom1[2]=0;
		tabpom1[3]=0;
		tabpom1[4]=0;
		tabpom1[5]=0;
		tabpom1[6]=0;
		tabpom1[7]=0;

		//powzcuanie kart do odpowiednich stoisk w talbicy
		for (zz=0;zz<=12;zz++){
			for (xx=1;xx<=7;xx++){
				if ((kkk[xx]==2+zz) || (kkk[xx]==15+zz) || (kkk[xx]==28+zz) || (kkk[xx]==41+zz)){
					temp2[zz+1]=temp2[zz+1]+1;
				}
			}
		}

		//wyszukanie najwyzszego elemntu w tablicy
		for (zz=1;zz<=13;zz++){
			if (temp2[zz]==2) {
				mt=zz+1;
			}
		}



		//zamiana do wspolnego mianwnika 2-14
		wspolny_mianownik();
		
		//znalezienie w puli dwojki i wyzerowanie jej
		for (zz=1;zz<=2;zz++){
			for (xx=1;xx<=7;xx++){
				if (wspolnymianownik[xx]==mt){
					wspolnymianownik[xx]=0;
					break;
				}
			}
		}

		//sorotowanie od najwiekszej do najmniejszej
		tabpom3[1]=wspolnymianownik[1];
		tabpom3[2]=wspolnymianownik[2];
		tabpom3[3]=wspolnymianownik[3];
		tabpom3[4]=wspolnymianownik[4];
		tabpom3[5]=wspolnymianownik[5];
		tabpom3[6]=wspolnymianownik[6];
		tabpom3[7]=wspolnymianownik[7];


		int pom=0;
		int pom2=0;
		int pom3=0;
		for (int a=1;a<=7;a++){
			if (pom<tabpom3[a]){
				pom=tabpom3[a];
				// tabpom3[a]=0;
				pom3=a;
			}
		}
		ooo[3]=0;
		ooo[3]=tabpom3[pom3];
		tabpom3[pom3]=0; //po znalezieniu najwyzszej karty pierwszej wyzeruj j¹


		pom=0;
		pom2=0;
		pom3=0;
		for (int a=1;a<=7;a++){
			if (pom2<tabpom3[a]){
				pom2=tabpom3[a];
				pom3=a;
			}
		}
		ooo[4]=0;
		ooo[4]=tabpom3[pom3];
		tabpom3[pom3]=0;

		pom=0;
		pom2=0;
		pom3=0;
		for (xx=1;xx<=7;xx++){
			if (pom2<tabpom3[xx]){
				pom2=tabpom3[xx];
				pom3=xx;
			}
		}
		ooo[5]=0;
		ooo[5]=tabpom3[pom3];
		tabpom3[pom3]=0;

		//sprawdzenie czy karta 1 i 2 znajduje sie w Twoich rekach
        kkk[1]=karty[1];
        kkk[2]=karty[2];
        kkk[3]=karty[3];
        kkk[4]=karty[4];
        kkk[5]=karty[5];
        kkk[6]=karty[6];
        kkk[7]=karty[7];

		int kontrol2=0;
		if ((tabpom3[6]==0) || (tabpom3[7]==0)) {
		   kontrol2=1;
		}

		if (mt!=0) {
			if ((wspolnymianownik[6]==0) || (wspolnymianownik[7]==0) || kontrol2 == 1)  {
				// expor[1]=9;
				//  expor[2]=mt;
				// expor[3]=ooo[3];
				// expor[4]=ooo[4];
				// expor[5]=ooo[5];
				// szukacz=1;
				returned_typ = 9;
				returned_moc = mt;
				returned_moc2 = ooo[3];
				returned_moc3 = ooo[4];
				returned_moc4 = ooo[5];
				
				if (debug==1) {kolory->komunikat( " FUNCTION (9) para -> true \n"); }
				return 1;
			} else { 
				if (debug==1) {kolory->komunikat( " FUNCTION (9) para -> false \n"); }
				return 0;
			}
		}

		if (debug==1) {kolory->komunikat( " FUNCTION (9) para -> false \n"); }
		return 0;   
	}
	
   
/*******************************************************************************
*
*                         10. wysoka karta
*
*******************************************************************************/
    public: bool uklad10(){
        zeruj();
        kkk[1]=karty[1];
        kkk[2]=karty[2];
        kkk[3]=karty[3];
        kkk[4]=karty[4];
        kkk[5]=karty[5];
        kkk[6]=karty[6];
        kkk[7]=karty[7];
		//zamiana do wspolnego mianwnika 2-14
		
		wspolny_mianownik();
		
		tabpom3[1]=wspolnymianownik[1];
		tabpom3[2]=wspolnymianownik[2];
		tabpom3[3]=wspolnymianownik[3];
		tabpom3[4]=wspolnymianownik[4];
		tabpom3[5]=wspolnymianownik[5];
		tabpom3[6]=wspolnymianownik[6];
		tabpom3[7]=wspolnymianownik[7];

		int pom=0;
		int pom2=0;
		int pom3=0;
		for (xx=1;xx<=7;xx++){
			if (pom<tabpom3[xx]){
				pom=tabpom3[xx];
				// tabpom3[xx]=0;
				pom3=xx;
			}
		}
		
		ooo[2]=0;
		ooo[2]=tabpom3[pom3];
		tabpom3[pom3]=0; //po znalezieniu najwyzszej karty pierwszej wyzeruj j¹
		
		pom=0;
		pom2=0;
		pom3=0;
		for (xx=1;xx<=7;xx++){
			if (pom<tabpom3[xx]){
				pom=tabpom3[xx];
				// tabpom3[xx]=0;
				pom3=xx;
			}
		}
		
		ooo[3]=0;
		ooo[3]=tabpom3[pom3];
		tabpom3[pom3]=0; //po znalezieniu najwyzszej karty pierwszej wyzeruj j¹

		pom=0;
		pom2=0;
		pom3=0;
		for (xx=1;xx<=7;xx++){
			if (pom2<tabpom3[xx]){
				pom2=tabpom3[xx];
				pom3=xx;
			}
		}
		ooo[4]=0;
		ooo[4]=tabpom3[pom3];
		tabpom3[pom3]=0;
		
		pom=0;
		pom2=0;
		pom3=0;
		for (xx=1;xx<=7;xx++){
			if (pom2<tabpom3[xx]){
				pom2=tabpom3[xx];
				pom3=xx;
			}
		}
		ooo[5]=0;
		ooo[5]=tabpom3[pom3];
		tabpom3[pom3]=0;
		
		pom=0;
		pom2=0;
		pom3=0;
		for (xx=1;xx<=7;xx++){
			if (pom2<tabpom3[xx]){
				pom2=tabpom3[xx];
				pom3=xx;
			}
		}
		ooo[6]=0;
		ooo[6]=tabpom3[pom3];
		tabpom3[pom3]=0;

        kkk[1]=karty[1];
        kkk[2]=karty[2];
        kkk[3]=karty[3];
        kkk[4]=karty[4];
        kkk[5]=karty[5];
        kkk[6]=karty[6];
        kkk[7]=karty[7];

		int kontrol=0;

		if (tabpom3[6]==0){
			kontrol=1;
		}
		if (tabpom3[7]==0){
			kontrol=1;
		}

		
		if (kontrol==1) {
			// expor[1]=10;
			// expor[2]=ooo[2];
			// expor[3]=ooo[3];
			// expor[4]=ooo[4];
			// expor[5]=ooo[5];
			// expor[6]=ooo[6];
			
			returned_typ = 10;
			returned_moc = ooo[2];
			returned_moc2 = ooo[3];
			returned_moc3 = ooo[4];
			returned_moc4 = ooo[5];
			returned_moc5 = ooo[6];
			
			if (debug==1) { kolory->komunikat( " FUNCTION (10) wysokakarta -> true \n"); }
			return 1;
		} else { 
			if (debug==1) { kolory->komunikat( " FUNCTION (10) wysokakarta -> false \n"); }
			return 0;
		}

		if (debug==1) { kolory->komunikat( " FUNCTION (10) wysokakarta -> false \n"); }
		return 0;
    }
	
	

		public: int whatHand(int k1=0,int k2=0,int k3=0,int k4=0,int k5=0,int k6=0,int k7=0){

			karty[1]=k1; 
			karty[2]=k2;
			karty[3]=k3;  
			karty[4]=k4;  
			karty[5]=k5;
			karty[6]=k6; 
			karty[7]=k7;   /* */  

			int x = -1;
                     
			if (uklad1()){
				x = 10;
				return 10;
			}
			if (uklad2()){
				x = 9;
				return 9;
			}
			if (uklad3()){
				x = 8;
				return 8;
			}
			if (uklad4()){
				x = 7;
				return 7;
			}

			if (uklad5()){
				x = 6;
				return 6;
			}
			if (uklad6()){
				x = 5;
				return 5;
			}
			if (uklad7()){
				x = 4;
				return 4;
			}
			if (uklad8()){
				x = 3;
				return 3;
			}
			if (uklad9()){
				x = 2;
				return 2;
			}
			if (uklad10()){
				x = 1;
				return 1;
			}

		


		}

	public: int findMax(int n, ...)
	{
		int i, val, largest;
		va_list vl;
		va_start(vl, n);
		largest = va_arg(vl, int);
		for (i = 1; i<n; i++)
		{
			val = va_arg(vl, int);
			largest = (largest>val) ? largest : val;
		}
		va_end(vl);
		return largest;
	}
	public: string printCard(int a){


		int rank = (a-1) % 13;
		int col = (a-1) / 13;

		string s_col;
		string s_rank;

		
		if (a <= 14){
			s_col = "h";
		}
		else if (a > 14 && a <= 27){
			s_col = "d";
		}
		else if (a > 27 && a <= 40){
			s_col = "c";
		}
		else if (a > 0 && a <= 53){
			s_col = "s";
		}
		else{
			s_col = "???????????????????????????????????";
		}

		switch (rank){
			case 1:
				s_rank = "2";
				break;

			case 2:
				s_rank = "3";
				break;

			case 3:
				s_rank = "4";
				break;

			case 4:
				s_rank = "5";
				break;

			case 5:
				s_rank = "6";
				break;

			case 6:
				s_rank = "7";
				break;

			case 7:
				s_rank = "8";
				break;

			case 8:
				s_rank = "9";
				break;

			case 9:
				s_rank = "T";
				break;

			case 10:
				s_rank = "J";
				break;

			case 11:
				s_rank = "Q";
				break;

			case 12:
				s_rank = "K";
				break;
			
			case 0:
				s_rank = "A";
				break;

		}

	//	cout << "KARTA:" << s_rank + s_col << endl;
		return s_rank + s_col;
	}

	public: int cardToNum(string card){
		
		int col = -1;
		int offset = -1;
		
		//str Ad
		string first = card.substr(0, 1);
		string second = card.substr(1, 1);

		if (second == "h"){
			col = 0;
		}
		else if (second == "d"){
			col = 1;
		}
		else if (second == "c"){
			col = 2;
		}
		else{
			col = 3;
		}

		if (first == "2"){
			offset = 0;
		}
		else if (first == "3"){
			offset = 1;
		}
		else if (first == "4"){
			offset = 2;
		}		
		else if (first == "5"){
			offset = 3;
		}
		else if (first == "6"){
			offset = 4;
		}
		else if (first == "7"){
			offset = 5;
		}
		else if (first == "8"){
			offset = 6;
		}
		else if (first == "9"){
			offset = 7;
		}
		else if (first == "T" || first == "t"){
			offset = 8;
		}
		else if (first == "J" || first == "j"){
			offset = 9;
		}
		else if (first == "Q" || first == "q"){
			offset = 10;
		}
		else if (first == "K" || first == "k"){
			offset = 11;
		}
		else if (first == "A" || first == "a"){
			offset = 12;
		}
		else{
			cout <<card << " ERROR" << endl;
		}


		///cout << "First: " << first <<endl;
		//cout << "Second: " << second << endl;
		//cout << "First offset: " << offset << endl;
		//cout << "Second color: " << col << endl;


		int num = 0;

		num = 2 + col * 13 + offset;

		//cout << "NUM: " << num << endl;
		return num;
	}

	public: int handToNum(string hand, int debug = 0){
		int num = 0;


		string first = hand.substr(0, 2);
		string second = hand.substr(2, 2);
		int ifirst = cardToNum(first);
		int isec = cardToNum(second);

		num = 100 * (ifirst+10) + (isec+10);

		if (debug)
			cout << "Hand:" << num << endl;

		return num;
	}

	public: string NumToHand(int num, int debug = 0){
		string hand;
		
		int second = num % 100;
		int first = (num - second) / 100;
		second = second - 10;
		first = first - 10;
	
		hand = printCard(first) + printCard(second);
 
		if (debug)
			cout << "Hand:" << hand << endl;

		return hand;
	}



	public: string printHand(int a, int b){

		string c = printCard(a) + printCard(b);
		cout << "KARTA: " << c << endl;
		return c;
	}

	public: int whoWins(int k1 = 0, int k2 = 0, int k3 = 0, int k4 = 0, int k5 = 0, 
		int k6 = 0, int k7 = 0, 
		int k8 = 0, int k9 = 0,
		int k10 = 0, int k11 = 0,
		int k12 = 0, int k13 = 0,
		int k14 = 0, int k15 = 0,
		int k16 = 0, int k17 = 0

		){
		
		int a1 = whatHand(k1, k2, k3, k4, k5, k6, k7);
		if (k6 == 0 || k7 == 0) a1 = -1;
		int a2 = whatHand(k1, k2, k3, k4, k5, k8, k9);
		if (k8 == 0 || k9 == 0) a2 = -1;
		int a3 = whatHand(k1, k2, k3, k4, k5, k10, k11);
		if (k10 == 0 || k11 == 0) a3 = -1;
		int a4 = whatHand(k1, k2, k3, k4, k5, k12, k13);
		if (k12 == 0 || k13 == 0) a4 = -1;
		int a5 = whatHand(k1, k2, k3, k4, k5, k14, k15);
		if (k14 == 0 || k15 == 0) a5 = -1;
		int a6 = whatHand(k1, k2, k3, k4, k5, k16, k17);
		if (k16 == 0 || k17 == 0) a6 = -1;

		int hands[6];
		hands[0] = a1;
		hands[1] = a2;
		hands[2] = a3;
		hands[3] = a4;
		hands[4] = a5;
		hands[5] = a6;

		 
		cout << "Flop:" << printCard(k1) + printCard(k2) + printCard(k3) << endl;
		cout << "T:" << printCard(k4) << endl;
		cout << "R:" << printCard(k5) << endl;

		cout << "UKLAD 1: " << a1 << endl;
		cout << "UKLAD 2: " << a2 << endl;
		cout << "UKLAD 3: " << a3 << endl;
		cout << "UKLAD 4: " << a4 << endl;
		cout << "UKLAD 5: " << a5 << endl;
		cout << "UKLAD 6: " << a6 << endl;

		printHand(k6, k7);
		printHand(k8, k9);
		printHand(k10, k11);
		printHand(k12, k13);
		printHand(k14, k15);
		printHand(k16, k17);


		/*
		KODY KART

		2 = 2h			15 = 2d			28 = 2c			41 = 2s
		..				..				..				..

		13 = Kh			26 = Kd			39 = Kc			52 = Ks
		14 = Ah			27 = Ad			40 = Ac			53 = As

		*/


		int maximum = hands[0];
		int winid = -1;

		for (int c = 0; c < 6; c++)
		{
			if (hands[c] > maximum)
			{
				maximum = hands[c];
				winid = c;
				c = c + 1;
				
			}
		}

		cout << "WINNER: " << winid << endl;
		return maximum;
	}

	void shuffle(int *arr, size_t n)
	{
		if (n > 1)
		{
			size_t i;
			srand(time(NULL));
			for (i = 0; i < n - 1; i++)
			{
				size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
				int t = arr[j];
				arr[j] = arr[i];
				arr[i] = t;
			}
		}
	}


	std::vector<std::string> getNextLineAndSplitIntoTokens(std::istream& str)
	{
		std::vector<std::string>   result;
		std::string                line;
		std::getline(str, line);

		std::stringstream          lineStream(line);
		std::string                cell;

		while (std::getline(lineStream, cell, ';'))
		{
			result.push_back(cell);
		}
		return result;
	}

		

	public: std::vector <std::vector<std::string> > readRangesFromFile(){

		std::ifstream      file("powerpush.txt");

		//std::vector <std::vector<std::string> > ranges;
		std::vector <std::vector<std::string> > ranges;


		while (!file.eof()){
			std::vector<std::string> line = getNextLineAndSplitIntoTokens(file);

			//line[1] = line[1].c_str().


			//cout << line[0] << " - " << stoi(line[1]) << endl;
			ranges.push_back(line);
		}
		return ranges;
	}

	public: vector <int> handsForRange(map <int, int> ranges, int range){

		vector <int> v;
		
		for (std::map <int, int>::iterator i = ranges.begin(); i != ranges.end(); ++i){
			if (i->second < range){
				v.push_back(i->first);
			}
			
		}

		return v;
	}




	public: int equityvsRange(int h1, int h2, 
		int range1 = 0, int range2 = 0, int range3= 0,
		int range4 = 0, int range5 = 0, int range6 = 0){

		//wylistowac range dla zakresow przykladowych
		
		//dla reki dla wszystkich boardow dla wszystkich rak z zakres policzyc jak czesto wygraja

		int temp[52]; int board[5];	

		

		//-----------------------------------------------losuj reke z zakresu


		

		//-----------------------------------------------dla 10000 boardow

		for (int b = 0; b < 50000; b++){



			//-----------------------------------------------losuj board
			for (int i = 0; i < 52; i++){
				temp[i] = i;
			}
			shuffle(temp, 52);

			int count = 0;

			for (int i = 0; i < 52; i++){

				if (temp[i] != h1 && temp[i] != h2){

					if (count < 5){
						board[count] = temp[i];
						count++;
					}

				}

			}
			cout << "BOARD: ";
			 
			for (int i = 0; i < 5; i++){
				cout << board[i]+10<<"-";
			}



			//-----------------------------------------------losujesz reke


			//-----------------------------------------------who wins
			//whoWins(board[0], board[1], board[2], board[3], board[4],
			//	reka[0], reka[1], )

			getchar();
		}

		return 1;
	}

				

};

