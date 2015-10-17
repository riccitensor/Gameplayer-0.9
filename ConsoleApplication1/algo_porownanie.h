#ifndef ALGO_H
#define	ALGO_H
#endif

class algo_porownanie {
	public: algo_porownanie(){		
		int a = 12;		
		int b = 12;
		sumator = new int*[a+1];  
		for (int x = 0; x <= b; x++) { 
			sumator[x] = new int[a+1]; 
		}
		
		
		player = new int*[a+1];  
		for (int x = 0; x <= b; x++) { 
			player[x] = new int[a+1]; 
		}
		
		
	}	
	
	public: void sum_clean(){
		sum_licznik=0;	
		for (int x=0;x<=10;x++){
			for (int y=0;y<=10;y++){
				sumator[x][y]=0;
			}
		}
	}
	
	public: void players_clean(){
		for (int x=0;x<=10;x++){
			for (int y=0;y<=10;y++){
				player[x][y]=0;
			}
		}
	}
	
	
	
	
	
	public: int** player;
	public: int** sumator;
	public: int sum_licznik;
	
	
	public: void setPlayers(){
		
		
	}

	public: void oblicz(){
	
	
		for (int nn=1;nn<=10;nn++){
		// System.out.println("player["+nn+"] uklad:  "+player[nn][0]+" / "+player[nn][1]+" / "+player[nn][2]+" / "+player[nn][3]+" / "+player[nn][4]+" / "+player[nn][5]+" / "+player[nn][6]+" / "+player[nn][7]);
		}
		
		
		
		
		
		sum_clean();
		players_clean();
		sum_licznik=1;
		
		
		
		player[1][1] = 1;
		player[2][1] = 2;
		player[3][1] = 1;
		player[4][1] = 2;
		player[5][1] = 1;
		player[6][1] = 2;
		
		
		
		for (int x=1;x<=10;x++){
			if (player[x][1]==0){
				continue;
			}
			
			cout << "xtest" << x << endl;
			
			if (((player[x][1]<sumator[1][1]) && (sumator[1][1]!=0)) || (sumator[1][1]==0)){
				sum_clean();
				sumator[1][0]=x;
				sumator[1][1]=player[x][1];
				sumator[1][2]=player[x][2];
				sumator[1][3]=player[x][3];
				sumator[1][4]=player[x][4];
				sumator[1][5]=player[x][5];
				sumator[1][6]=player[x][6];
				sumator[1][7]=player[x][7];
				//continue;
			}
			
			if (player[x][1]==sumator[1][1]){
				cout << "rrrr" << x << endl;
			
				//---------------------------------------------------------------------------
				//                         1. KROLEWSKI POKER
				//---------------------------------------------------------------------------
				if (player[x][1]==1) {
					sum_licznik++;
					sumator[1+sum_licznik][0]=x; //numer gracza ze stolu
					sumator[1+sum_licznik][1]=player[x][1];
					sumator[1+sum_licznik][2]=player[x][2];
				}
			
				//---------------------------------------------------------------------------
				//                         2. POKER
				//---------------------------------------------------------------------------
				if (player[x][1]==2) {
					if (player[x][2]==sumator[1][2]){
						sum_licznik++;
						sumator[1+sum_licznik][0]=x; //numer gracza ze stolu
						sumator[1+sum_licznik][1]=player[x][1];
						sumator[1+sum_licznik][2]=player[x][2];
						sumator[1+sum_licznik][3]=player[x][3];
					} else
					if (player[x][2]<sumator[1][2]){
						//continue;
					} else
					if (player[x][2]>sumator[1][2]){
						sum_clean();
						sumator[1][0]=x;
						sumator[1][1]=player[x][1];
						sumator[1][2]=player[x][2];
						sumator[1][3]=player[x][3];
					}
					// sumator[1+sum_licznik][0]=x; //numer gracza ze stolu
				}
	
			
			}
		}
		
		
		for (int nn=1;nn<=10;nn++){
			cout << "najlepszy [" << nn << "] uklad: " << sumator[nn][0] << " / " << sumator[nn][1] << " / " << sumator[nn][2] << " / " << sumator[nn][3] << " / " << sumator[nn][4] << " / " << sumator[nn][5] << " / " << sumator[nn][6] << " / " << sumator[nn][7] << "\n";
		}
		
			
		
	}


};

