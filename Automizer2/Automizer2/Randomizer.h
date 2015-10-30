#ifndef RAND
#define	RAND

#include "algo_funkcje.h"
#endif

#include <vector>
#include <map>
#include <string>


using namespace std;


//------------------------------------------------------TU ZAPISANE SA RECE Z DANYCH RANGOW
std::vector <std::vector<std::string> >	 ranges;
std::map <int, int> int_ranges;

vector <int> range6;
vector <int> range9;
vector <int> range12;
vector <int> range15;

vector <int> range18;
vector <int> range22;
vector <int> range26;
vector <int> range30;

vector <int> range34;
vector <int> range38;
vector <int> range42;
vector <int> range46;

vector <int> range50;
vector <int> range54;
vector <int> range58;
vector <int> range62;

vector <int> range66;
vector <int> range70;
vector <int> range74;
vector <int> range100;





void readRanges()
{
	algo_funkcje *a;
	a = new algo_funkcje();
	ranges = a->readRangesFromFile();

	//----------------------------------------------CALA LISTA RAK
	//for (std::vector<int>::size_type i = 0; i != ranges.size(); i++){
	for (int i = 0; i != ranges.size(); i++){

		int_ranges[a->handToNum(ranges[i][0])] = std::stoi(ranges[i][1]);
		//cout << a->handToNum(ranges[i][0]) << "->>>" << int_ranges[a->handToNum(ranges[i][0])] << endl;
	}

	//-----------------------------------------------KONKRETNE ZAKRESY

	range6 = a->handsForRange(int_ranges, 6);
	range9 = a->handsForRange(int_ranges, 9);
	range12 = a->handsForRange(int_ranges, 12);
	range15 = a->handsForRange(int_ranges, 15);

	range18 = a->handsForRange(int_ranges, 18);
	range22 = a->handsForRange(int_ranges, 22);
	range26 = a->handsForRange(int_ranges, 26);
	range30 = a->handsForRange(int_ranges, 30);

	range34 = a->handsForRange(int_ranges, 34);
	range38 = a->handsForRange(int_ranges, 38);
	range42 = a->handsForRange(int_ranges, 42);
	range46 = a->handsForRange(int_ranges, 46);

	range50 = a->handsForRange(int_ranges, 50);
	range54 = a->handsForRange(int_ranges, 54);
	range58 = a->handsForRange(int_ranges, 58);
	range62 = a->handsForRange(int_ranges, 62);

	range66 = a->handsForRange(int_ranges, 66);
	range70 = a->handsForRange(int_ranges, 70);
	range74 = a->handsForRange(int_ranges, 74);
	range100 = a->handsForRange(int_ranges, 100);





	/*
	GRACZ NIEAKTYWNY RANGE 0, NIE LOSUJEMY KART
	*/

}
vector<int> randomHandFromRange(vector<int> range){

	int num = rand() % range.size();
	int karta = range[num];

	int sec = karta % 100;
	int fir = (karta - sec) / 100;

	sec = sec - 10;
	fir = fir - 10;



	//std::cout << "KARTA: " << fir << "," << sec << endl;

	vector<int> ret;
	ret.push_back(fir);
	ret.push_back(sec);
	return ret;
}

