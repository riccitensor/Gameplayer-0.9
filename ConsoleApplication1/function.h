#ifndef FUNCTION_H
#define	FUNCTION_H
#endif

#include <vector>
#include <string>


using namespace std;

class function {

/* -----------------------------------------------------------------------------
 									  SPLIT
------------------------------------------------------------------------------ */
public: vector<string> split(const string& s, const string& delim, const bool keep_empty = true) {
    vector<string> result;
    if (delim.empty()) {
        result.push_back(s);
        return result;
    }
    string::const_iterator substart = s.begin(), subend;
    while (true) {
        subend = search(substart, s.end(), delim.begin(), delim.end());
        string temp(substart, subend);
        if (keep_empty || !temp.empty()) {
            result.push_back(temp);
        }
        if (subend == s.end()) {
            break;
        }
        substart = subend + delim.size();
    }
    return result;
}

/* -----------------------------------------------------------------------------
 							       	INT TO STR
----------------------------------------------------------------------------- */
public: int strToInt(string s) {
     int tmp = 0, i = 0;
     bool m = false;
     if(s[0] == '-') {
          m = true;
          i++;
     }
     for(; i < s.size(); i++)
          tmp = 10 * tmp + s[i] - 48;
     return m ? -tmp : tmp;   
}

/* -----------------------------------------------------------------------------
 									STR TO INT
----------------------------------------------------------------------------- */
public: string intToStr(int n) {
     string tmp, ret;
     if(n < 0) {
          ret = "-";
          n = -n;
     }
     do {
          tmp += n % 10 + 48;
          n -= n % 10;
     }
     while(n /= 10);
     for(int i = tmp.size()-1; i >= 0; i--)
          ret += tmp[i];
     return ret;
}

/* -----------------------------------------------------------------------------
 									FILE EXIST
----------------------------------------------------------------------------- */
bool fileExists(const std::string& filename) {
    struct stat buf;
    if (stat(filename.c_str(), &buf) != -1)
    {
        return true;
    }
    return false;
}

/* -----------------------------------------------------------------------------
 									DIR EXIST
----------------------------------------------------------------------------- */

bool dirExists(string dir) {
	if ( _access( dir.c_str(), 0 ) == 0 ) {
		return true;
	} else {
		return false;
	      //kolory->komunikat << "Path doesn't exist." << endl;
	}
}

/* -----------------------------------------------------------------------------
 									RANDOM
----------------------------------------------------------------------------- */
int getRandomInt(int min,int max) {
  // srand(time(NULL));   musi byc poza obrebem funkcji/petli  
  if (min>max) {
	//kolory->komunikat << "error: Random min > Random max\n";
    return 0; 
  }
  if (min==max) {
    //kolory->komunikat << "error: Random min == Random max\n";
	return min; 
  }
  if (max==0) {
    //kolory->komunikat << "error: Random max == 0\n"; 
    return 0; 
  }  
  return min + (rand() % (max - min + 1));
}
    
   
/* -----------------------------------------------------------------------------
 									PAUSE
----------------------------------------------------------------------------- */
   
public: int pause(){

	#ifdef linux
		struct termios oldt,newt;
		int zn;
		tcgetattr( STDIN_FILENO, &oldt );
		newt = oldt;
		newt.c_lflag &= ~( ICANON | ECHO );
		tcsetattr( STDIN_FILENO, TCSANOW, &newt );
		zn = getchar();
		tcsetattr( STDIN_FILENO, TCSANOW, &oldt );
		return zn;
	#else
		_getch();
	#endif
/**/

		return 1;
}
   
    
};

