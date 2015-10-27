#ifndef ALGO_H
#define	ALGO_H
#endif

#include "CSVRow.h"

class algo_funkcje {


	public: algo_funkcje(){

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

	public: string NumToString(int num){

		/*
		KODY KART

		2 = 2h			15 = 2d			28 = 2c			41 = 2s
		..				..				..				..

		13 = Kh			26 = Kd			39 = Kc			52 = Ks
		14 = Ah			27 = Ad			40 = Ac			53 = As

		*/
		num = num - 2;

		string cards[52];

		cards[0] = "2h";
		cards[1] = "3h";
		cards[2] = "4h";
		cards[3] = "5h";
		cards[4] = "6h";
		cards[5] = "7h";
		cards[6] = "8h";
		cards[7] = "9h";
		cards[8] = "Th";
		cards[9] = "Jh";
		cards[10] = "Qh";
		cards[11] = "Kh";
		cards[12] = "Ah";

		cards[13] = "2d";
		cards[14] = "3d";
		cards[15] = "4d";
		cards[16] = "5d";
		cards[17] = "6d";
		cards[18] = "7d";
		cards[19] = "8d";
		cards[20] = "9d";
		cards[21] = "Td";
		cards[22] = "Jd";
		cards[23] = "Qd";
		cards[24] = "Kd";
		cards[25] = "Ad"; 

		cards[26] = "2c";
		cards[27] = "3c";
		cards[28] = "4c";
		cards[29] = "5c";
		cards[30] = "6c";
		cards[31] = "7c";
		cards[32] = "8c";
		cards[33] = "9c";
		cards[34] = "Tc";
		cards[35] = "Jc";
		cards[36] = "Qc";
		cards[37] = "Kc";
		cards[38] = "Ac";

		cards[39] = "2s";
		cards[40] = "3s";
		cards[41] = "4s";
		cards[42] = "5s";
		cards[43] = "6s";
		cards[44] = "7s";
		cards[45] = "8s";
		cards[46] = "9s";
		cards[47] = "Ts";
		cards[48] = "Js";
		cards[49] = "Qs";
		cards[50] = "Ks";
		cards[51] = "As";

		return cards[num];

	}

	public: int convert(int a){

		int converter[52];
		converter[0] = 14;
		converter[1] = 13;
		converter[2] = 12;
		converter[3] = 11;
		converter[4] = 10;
		converter[5] = 9;
		converter[6] = 8;
		converter[7] = 7;
		converter[8] = 6;
		converter[9] = 5;
		converter[10] = 4;
		converter[11] = 3;
		converter[12] = 2;

		converter[13] = 27;
		converter[14] = 26;
		converter[15] = 25;
		converter[16] = 24;
		converter[17] = 23;
		converter[18] = 22;
		converter[19] = 21;
		converter[20] = 20;
		converter[21] = 19;
		converter[22] = 18;
		converter[23] = 17;
		converter[24] = 16;
		converter[25] = 15;

		converter[26] = 40;
		converter[27] = 39;
		converter[28] = 38;
		converter[29] = 37;
		converter[30] = 36;
		converter[31] = 35;
		converter[32] = 34;
		converter[33] = 33;
		converter[34] = 32;
		converter[35] = 31;
		converter[36] = 30;
		converter[37] = 29;
		converter[38] = 28;

		converter[39] = 53;
		converter[40] = 52;
		converter[41] = 51;
		converter[42] = 50;
		converter[43] = 49;
		converter[44] = 48;
		converter[45] = 47;
		converter[46] = 46;
		converter[47] = 45;
		converter[48] = 44;
		converter[49] = 43;
		converter[50] = 42;
		converter[51] = 41;

		return converter[a];
	}

	public: void showMatrixCards(bool m[13][4]){


		/*
		KODY KART

		2 = 2h			15 = 2d			28 = 2c			41 = 2s
		..				..				..				..

		13 = Kh			26 = Kd			39 = Kc			52 = Ks
		14 = Ah			27 = Ad			40 = Ac			53 = As

		*/

		int temp[7];
		int hand[7];
		int counter = 0;

		


		for (int i = 0; i < 13; i++){
			for (int j = 0; j < 4; j++){
				
				//karty
				if (m[i][j] == true && counter < 7){
					
					temp[counter] = j * 13 + i;
					cout << counter << ": " << temp[counter] << endl;
					hand[counter] = convert(temp[counter]);
					counter++;


				}
				if (counter > 7){
					cout << "BLAD counter >7" << endl;
				}
			}
		}


		for (int i = 0; i < 7; i++){
			cout << NumToString(hand[i]) << "-";
		}

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

