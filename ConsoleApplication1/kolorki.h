#ifndef KOLORKI_H
#define	KOLORKI_H
#endif

using namespace std;

class kolorki {
	#ifdef linux	
	#else
		HANDLE hOut;
	#endif
		
	public: kolorki(){
		komunikaty = true;
		
		
		#ifdef linux	
		#else
			hOut = GetStdHandle( STD_OUTPUT_HANDLE );
		#endif
	}
		
	#ifdef linux
		public: void ustawKolor(string kolor){	
			if (komunikaty){	
				if (!kolor.compare("White")){ cout << "\033[0;37m"; 
				} else 
				if (!kolor.compare("LightRed")){ cout << "\033[0;31m"; 
				} else 
				if (!kolor.compare("Grey")){ cout << "\033[0;37m";
				} else 
				if (!kolor.compare("Red")){ cout << "\033[0;31m";
				} else 
				if (!kolor.compare("LightGreen")){ cout << "\033[0;38m";
				} else 
				if (!kolor.compare("LightBlue")){ cout << "\033[0;36m";
				} else 
				if (!kolor.compare("Cyan")){ cout << "\033[0;36m";
				} else 
				if (!kolor.compare("Yellow")){ cout << "\033[0;33m";
				} else 
				if (!kolor.compare("Orange")){ cout << "\033[0;33m";
				} else 
				if (!kolor.compare("LightPurple")){ cout << "\033[0;35m";
				} else {
					cout << "\033[0;30m";
				}	
			}	
		}
	#else
		public: enum Color {
		        _Black       = 0,
		        _Grey        = FOREGROUND_INTENSITY,
		        _LightGrey   = FOREGROUND_RED   | FOREGROUND_GREEN | FOREGROUND_BLUE,
		        _White       = FOREGROUND_RED   | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY,
		        _Blue        = FOREGROUND_BLUE,
		        _Green       = FOREGROUND_GREEN,
		        _Cyan        = FOREGROUND_GREEN | FOREGROUND_BLUE,
		        _Red         = FOREGROUND_RED,
		        _Purple      = FOREGROUND_RED   | FOREGROUND_BLUE,
		        _LightBlue   = FOREGROUND_BLUE  | FOREGROUND_INTENSITY,
		        _LightGreen  = FOREGROUND_GREEN | FOREGROUND_INTENSITY,
		        _LightCyan   = FOREGROUND_GREEN | FOREGROUND_BLUE  | FOREGROUND_INTENSITY,
		        _LightRed    = FOREGROUND_RED   | FOREGROUND_INTENSITY,
		        _LightPurple = FOREGROUND_RED   | FOREGROUND_BLUE  | FOREGROUND_INTENSITY,
		        _Orange      = FOREGROUND_RED   | FOREGROUND_GREEN,
		        _Yellow      = FOREGROUND_RED   | FOREGROUND_GREEN | FOREGROUND_INTENSITY,
		        _test = 0xEC,
		};	
	
		public: void ustawKolor(string kolor){			
			if (!kolor.compare("White")){ SetConsoleTextAttribute(hOut,_White);
			} else 
			if (!kolor.compare("LightRed")){ SetConsoleTextAttribute(hOut,_LightRed);
			} else 
			if (!kolor.compare("Grey")){ SetConsoleTextAttribute(hOut,_Grey);
			} else 
			if (!kolor.compare("Red")){ SetConsoleTextAttribute(hOut,_Red);
			} else 
			if (!kolor.compare("LightGreen")){ SetConsoleTextAttribute(hOut,_LightGreen);
			} else 
			if (!kolor.compare("LightBlue")){ SetConsoleTextAttribute(hOut,_LightBlue);
			} else 
			if (!kolor.compare("Cyan")){ SetConsoleTextAttribute(hOut,_Cyan);
			} else 
			if (!kolor.compare("Yellow")){ SetConsoleTextAttribute(hOut,_Yellow);
			} else 
			if (!kolor.compare("Orange")){ SetConsoleTextAttribute(hOut,_Orange);
			} else 
			if (!kolor.compare("LightPurple")){ SetConsoleTextAttribute(hOut,_LightPurple);
			} else {
				SetConsoleTextAttribute(hOut,_Grey);
			}			
		}
	#endif	
	
	public: void White(){ ustawKolor("White"); }	
	public: void LightRed(){ ustawKolor("LightRed"); }	
	public: void KolorOpisu(){ ustawKolor("Grey"); }	
	public: void Red(){ ustawKolor("Red"); }	
	public: void LightGreen(){ ustawKolor("LightGreen"); }	
	public: void LightBlue(){ ustawKolor("LightBlue"); }	
	public: void Cyan(){ ustawKolor("Cyan"); }	
	public: void Yellow(){ ustawKolor("Yellow"); }	
	public: void Orange(){ ustawKolor("Orange"); }		
	public: void LightPurple(){ ustawKolor("LightPurple"); }	
	
	
	bool komunikaty;
	
	public: void komunikat(string komunikat){		
		if (komunikaty){
			cout << komunikat;
		}
	}
	
	public: void komInt(int value,int enter = 0){
		if (komunikaty){			
			cout << funkcje->intToStr(value);			
			if (enter==1) { cout << "\r\n"; }			
		}
	}
	
		
	
};


