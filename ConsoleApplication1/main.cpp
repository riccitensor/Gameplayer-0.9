using namespace std;
#include <stdio.h>     /* for printf */
#include <stdlib.h>    /* for exit */
#include <getopt.h>

//#include <unistd.h>
//#include <iomanip>

#ifdef linux
	#include <termios.h>
	#include <sys/io.h>
#else
	#include <io.h>
	#include <windows.h>
	#include <conio.h>
#endif

#include <stdlib.h>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <sys/stat.h>
#include <math.h>
#include <time.h>
#include <algorithm>

#include "function.h"
function *funkcje;

#include "kolorki.h"
kolorki *kolory;

#include "baza.h"
baza *base;

#include "logi.h"
logi *logs;


#include "algo_funkcje.h"
algo_funkcje *alg_funkcje;

#include "algo_porownanie.h"
algo_porownanie *alg_porownanie;

#include "algo.h"
algo *alg;



int main(int argc, char *argv[]) {
	
	
	funkcje = new function();
	kolory = new kolorki();
	base = new baza();
	logs = new logi();
	logs->logo();
	
	
	
	
	kolory->komunikat("test\n");
	
	
	
	
	
	
	
	
	
	#include "algo_funkcje.h"
	algo_funkcje *alg_funkcje;
	alg_funkcje = new algo_funkcje();
	
	alg_funkcje->zeruj();
	
	algo_porownanie *alg_porownanie;
	alg_porownanie = new algo_porownanie();
	
	
	
	
	#include "algo.h"
	algo *alg;
	alg = new algo();
	
	
	alg->game();
	
	
	//alg_funkcje->test(13,5,10,11,12,2,14);
	
	
	alg_porownanie->oblicz();
	
	
	
	return 0;
}
