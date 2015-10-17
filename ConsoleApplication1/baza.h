#ifndef BAZA_H
#define	BAZA_H
#endif

using namespace std;

class baza {
	public: baza(){		

		
		version = "poker-0.001-alpha";
		
		input_source = "AO_DOWNLOAD";
		input_preferences = "AO_CONST";
		output_debug = "_debug.html";
		output_plan_zajec = "_plan_zajec.html";
		output_plan_nauczycieli = "_plan_nauczycieli.html";
		output_plan_sal = "_plan_sal.html";
		output_sql = "_baza.sql";
		output_dir = "";
		output_n = "";
		komunikaty = true;
		
		author = "Slawomir Kudla";
	}
	



	
	int SALE_MAX; //ilosc faktycznych sal
	int SALE_CONST; //ilosc rekordow w pliku const
	int MIEDZYODDZIALOWE_MAX;	
	

	

	

	string version;
	
	string input_source;
	string input_preferences;
	string output_debug;
	string output_plan_zajec;
	string output_plan_nauczycieli;
	string output_plan_sal;
	string output_sql;
	
	string author;
	public: string output_dir;	
	public: string output_n;
	
	public: bool komunikaty;
	
 };  
  

