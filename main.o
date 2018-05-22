#include <windows.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <conio.h>
#include "hdonki.h"
#include "persona_model.h"
//#include <stdlib.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_RIGHT_E 224
int MAXW = 50;
int MAXROWS = 20;
int NCHOICES = 5;
int ASK_LINE_Y = 26;
int CONTENT_LINE_Y = 6;
int CONTENT_LINE_MAX_Y = 25;
string CHOICES[5][3];
std::map<std::string, std::string (*)()> m;
vector<Person*> people;
//
//string** CHOICES;
//float CHOICES[0] = new string[3];
//string CHOICES = new string * [3];
//const nchoices = 5;
//string choices[nchoices][3];

void locate_at_content() {
	COORD xy ;
	xy.X = 0 ;
    for(int i = CONTENT_LINE_Y; CONTENT_LINE_MAX_Y > i; i++) {
    	xy.Y = i;
	    SetConsoleCursorPosition( 
	    	GetStdHandle(STD_OUTPUT_HANDLE), xy);
	    cout << string(100, ' ');
	}
	xy.Y = CONTENT_LINE_Y;
    SetConsoleCursorPosition( 
    	GetStdHandle(STD_OUTPUT_HANDLE), xy);    
}

void render_title(string _str){
	for(int i = 0; MAXW > i; i++) {
		cout<<"=";
	}
	cout<<endl;
	cout<<"                      "<<_str<<"                       "<<endl;
	for(int i = 0; MAXW > i; i++) {
		cout<<"=";
	}
}

void render_subtitle(string _str){
	cout<<endl<<"--- "<<_str<<endl;
}

void render_menu(){
	for(int i = 0; NCHOICES > i; i++) {
		cout<<CHOICES[i][0]<<"("<<CHOICES[i][1]<<")"<<" | ";
	}
}

void breakline(){
	cout<<endl;
}

void render_content() {
	locate_at_content();
	TablePrinter tp;
tp(&std::cout);
tp.AddColumn("Name", 25);
tp.AddColumn("Age", 5);
tp.AddColumn("Position", 30);
tp.AddColumn("Allowance", 9);

tp.PrintHeader();
tp << "Dat Chu" << 25 << "Research Assistant" << -0.00000000001337;
tp << "John Doe" << 26 << "Too much float" << 125456789.123456789;
tp << "John Doe" << 26 << "Typical Int" << 1254;
tp << "John Doe" << 26 << "Typical float" << 1254.36;
tp << "John Doe" << 26 << "Too much negative" << -125456789.123456789;
tp << "John Doe" << 26 << "Exact size int" << 125456789;
tp << "John Doe" << 26 << "Exact size int" << -12545678;
tp << "John Doe" << 26 << "Exact size float" << -1254567.8;
tp << "John Doe" << 26 << "Negative Int" << -1254;
tp << "Jane Doe" << bprinter::endl();
tp << "Tom Doe" << 7 << "Student" << -M_PI;
tp.PrintFooter();	
	
	/*
    TextTable t( '-', '|', '+' );

    t.add( "ID" );
    t.add( "DNI" );
    t.add( "NOMBRES" );
    t.add( "APELLIDOS" );
    t.endOfRow();	

	for(int i = 0; people.size() > i; i++) {
		Person person_current = Person(* people[i]);
	    t.add( person_current.get_id() + "" );
	    t.add( person_current.get_dni() );
	    t.add( person_current.get_first_name() );
	    t.add( person_current.get_last_name() );
	    t.endOfRow();
	}
	for(int i = 0; (MAXROWS - people.size()) > i; i++) {
	    t.add("");
	    t.add("");
	    t.add("");
	    t.add("");
	    t.endOfRow();
	}
    t.setAlignment( 2, TextTable::Alignment::RIGHT );
    cout << t;*/
}

string ask_command() {
	string command;
	cout<<"";
	cin>>command;
	return command;
}

string do_new() {
	char i = 'a';
	locate_at_content();
	string first_name;
	string dni;
	string last_name;
	cout<<"                    "<<"Registro nuevo"<<endl;
	cout<<"DNI: ";
	cin>>dni;
	cout<<"Nombres: ";
	cin>>first_name;
	cout<<"Apellidos: ";
	cin>>last_name;

	bool fail = false;
	do {
		if ( fail ) {
			cout<<"Por favor, ingrese una opcion valida."<<endl;	
		}
		
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, BACKGROUND_GREEN);
		cout<<"Guardar (G)";
		SetConsoleTextAttribute(hConsole, 15);
		cout<<"\t";
		SetConsoleTextAttribute(hConsole, BACKGROUND_RED);
		cout<<"Cancelar (R)"<<endl;
		SetConsoleTextAttribute(hConsole, 15);
		cin>>i;
		if ( i != 'G' && i != 'g' && i != 'r' && i != 'R' ) {
			fail = true;
		} else {
			fail = false;
		}
	} while(fail);
	
	Person *a = new Person((people.size() + 1), dni, first_name, last_name);
	people.push_back(a);
	
	//manage_arrows();
//	cout<<"\e[3;31;42mGuardar";
//	cout<<"\e[31m"<< "Hello" << "\e[0m" <<"World" <<endl;
	return "";
}

string do_edit() {
	cout<<"Edit";
	return "";
}

string do_delete() {
	cout<<"Delete";
	return "";
}

string do_close() {
	cout<<"Close";
	return "";
}

string do_about() {
	cout<<"About";
	return "";
}

void exec_command(string _command) {
	for(int i = 0; NCHOICES > i; i++) {
		if ( _command == CHOICES[i][1] ) {
			m[CHOICES[i][2]]();
		}
	}
	render_content();
}

void locate_at_question() {
    COORD xy ;
    xy.X = 0 ;
    xy.Y = ASK_LINE_Y;
    SetConsoleCursorPosition( 
    	GetStdHandle(STD_OUTPUT_HANDLE), xy);
    
    cout << string(10, ' ');    	

    SetConsoleCursorPosition( 
    	GetStdHandle(STD_OUTPUT_HANDLE), xy);    
}

void manage_arrows() {
//	while(true)
//	{
		if (GetAsyncKeyState(VK_ESCAPE))
		{
			cout << "DUDE! You've pressed the escape key";
			cin.ignore();
		} else if (GetAsyncKeyState(VK_UP)) {
			cout << "UP";
			cin.ignore();			
		} else if (GetAsyncKeyState(VK_LEFT)) {
			cout << "LEFT";
			cin.ignore();			
		} else if (GetAsyncKeyState(VK_RIGHT)) {
			cout << "RIGHT";
			cin.ignore();			
		} else if (GetAsyncKeyState(VK_DOWN)) {
			cout << "DOWN";
			cin.ignore();
		}
//	}
}


int main(int argc, char** argv) {
//	int nchoices = 5;
	string todo = "";
//	CHOICES = new string[NCHOICES][3];
//	string choices[nchoices][3];
	render_title("Usuarios");
	render_subtitle("Version 1.2");
	
	CHOICES[0][0] = "Nuevo";
	CHOICES[0][1] = "N";
	CHOICES[0][2] = "do_new";

	CHOICES[1][0] = "Editar";
	CHOICES[1][1] = "E";
	CHOICES[1][2] = "do_edit";
	
	CHOICES[2][0] = "Eliminar";
	CHOICES[2][1] = "D";
	CHOICES[2][2] = "do_delete";
	
	CHOICES[3][0] = "Cerrar";
	CHOICES[3][1] = "C";
	CHOICES[3][2] = "do_close";
	
	CHOICES[4][0] = "Acerca de";
	CHOICES[4][1] = "A";
	CHOICES[4][2] = "do_about";
	
	m["do_new"] = &do_new;
	m["do_edit"] = &do_edit;
	m["do_delete"] = &do_delete;
	m["do_close"] = &do_close;
	m["do_about"] = &do_about;
	
	
    
//	m["bar"] = &bar;
	
//	std::map<int, void*> fnMap;		
//	fnMap["do_new"] = &do_new;
//    int result = reinterpret_cast<int(*)(int)>(fnMap["do_new"])(1);
//	fnMap["do_new"]();
//	fnMap["inverse"] = &inverse;
	
	breakline();
	render_menu();
	breakline();
	render_content();
	do {
		locate_at_question();
		//cout << string(50, '\n');
		todo = ask_command();
		exec_command(todo);
	} while(true);
	
	
	
	return 0;
}
