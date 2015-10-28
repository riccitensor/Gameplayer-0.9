#ifndef ALGO_H
#define	ALGO_H
#endif


class algo_funkcje {


	public: algo_funkcje(){

	}	

	public: void showVector(vector<int> a){
		for (std::vector<int>::size_type i = 0; i != a.size(); i++) {
			cout << a[i] << endl;
		}
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
	
	vector<int> matrix2cards(bool input[13][4]){


		int tab[13][4];

		tab[0][0] = 14;
		tab[1][0] = 13;
		tab[2][0] = 12;
		tab[3][0] = 11;
		tab[4][0] = 10;
		tab[5][0] = 9;
		tab[6][0] = 8;
		tab[7][0] = 7;
		tab[8][0] = 6;
		tab[9][0] = 5;
		tab[10][0] = 4;
		tab[11][0] = 3;
		tab[12][0] = 2;
		tab[0][1] = 27;
		tab[1][1] = 26;
		tab[2][1] = 25;
		tab[3][1] = 24;
		tab[4][1] = 23;
		tab[5][1] = 22;
		tab[6][1] = 21;
		tab[7][1] = 20;
		tab[8][1] = 19;
		tab[9][1] = 18;
		tab[10][1] = 17;
		tab[11][1] = 16;
		tab[12][1] = 15;
		tab[0][2] = 40;
		tab[1][2] = 39;
		tab[2][2] = 38;
		tab[3][2] = 37;
		tab[4][2] = 36;
		tab[5][2] = 35;
		tab[6][2] = 34;
		tab[7][2] = 33;
		tab[8][2] = 32;
		tab[9][2] = 31;
		tab[10][2] = 30;
		tab[11][2] = 29;
		tab[12][2] = 28;
		tab[0][3] = 53;
		tab[1][3] = 52;
		tab[2][3] = 51;
		tab[3][3] = 50;
		tab[4][3] = 49;
		tab[5][3] = 48;
		tab[6][3] = 47;
		tab[7][3] = 46;
		tab[8][3] = 45;
		tab[9][3] = 44;
		tab[10][3] = 43;
		tab[11][3] = 42;
		tab[12][3] = 41;
		
		vector<int> a;

		for (int i = 0; i < 13; i++){
			for (int j = 0; j < 4; j++){
				if (input[i][j] == true){

					a.push_back(tab[i][j]);

				}
			}
		}

		return a;

	}



	public: int whoWins(int k1 = 0, int k2 = 0, int k3 = 0, int k4 = 0, int k5 = 0, 
		int k6 = 0, int k7 = 0

		){
		

		 
		cout << "Flop:" << printCard(k1) + printCard(k2) + printCard(k3) << endl;
		cout << "T:" << printCard(k4) << endl;
		cout << "R:" << printCard(k5) << endl;


		/*
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


		*/


		return 1;
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
		int debug = 0;
		
		for (std::map <int, int>::iterator i = ranges.begin(); i != ranges.end(); ++i){
			if (i->second <= range){
				debug++;
				v.push_back(i->first);
			}

		}
		cout << "For range:" << range << " lines: " << debug << endl;
		return v;
	}


				

};

