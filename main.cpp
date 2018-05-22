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

int MAXROWS = 20;
int NCHOICES = 6;
int ASK_LINE_Y = 30;
int CONTENT_LINE_Y = 6;
int CONTENT_LINE_MAX_Y = 25;
int CONTENT_LINE_MAX_X = 78;
int CONTENT_DNI_COLUMN = 10;
int CONTENT_NAME_COLUMN = 30;
int CONTENT_LAST_COLUMN = 30;
string current_dni;

string CHOICES[6][3];
std::map<std::string, std::string (*)()> m;
vector<Person*> people;
//
//string** CHOICES;
//float CHOICES[0] = new string[3];
//string CHOICES = new string * [3];
//const nchoices = 5;
//string choices[nchoices][3];

#include <sstream>



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
//	for(int i = 0; MAXW > i; i++) {
//		cout<<"=";
//	}
	fill_text("=", CONTENT_LINE_MAX_X, "=");
	cout<<endl;
	center_text(_str, CONTENT_LINE_MAX_X);
	cout<<endl;
	fill_text("=", CONTENT_LINE_MAX_X, "=");
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
string fill_text(string text, int max, string complete) {
	int fill = 0;
	if ( max > text.length() ) {
		fill = max - text.length();
		cout<<text;
		for(int i = 0; fill > i; i++) {
			cout<<complete;
		}
	} else {
		cout<<text.substr(0, max);
	}
	return "";
}
string fill_text(string text, int max) {
	int fill = 0;
	if ( max > text.length() ) {
		fill = max - text.length();
		cout<<text;
		for(int i = 0; fill > i; i++) {
			cout<<" ";
		}
	} else {
		cout<<text.substr(0, max);
	}
	return "";
}
void render_footer(int n_render) {
	for(int i = 0; (MAXROWS - n_render - 1) > i; i++) {
	    fill_text(" ", CONTENT_DNI_COLUMN);
	    cout<<" | ";
	    fill_text(" ", CONTENT_NAME_COLUMN);
	    cout<<" | ";
	    fill_text(" ", CONTENT_LAST_COLUMN);
	    cout<<endl;
	}
	    fill_text("-", CONTENT_DNI_COLUMN+1, "-");
	    cout<<"+";
	    fill_text("-", CONTENT_NAME_COLUMN+2, "-");
	    cout<<"+";
	    fill_text("-", CONTENT_LAST_COLUMN+2, "-");
	    cout<<endl;
}
void render_one(Person p) {
	locate_at_content();
	current_dni = p.get_dni();
//	for(int i = 0; people.size() > i; i++) {
//		Person person_current = Person(* people[i]);
//		if ( p.get_dni() == person_current.get_dni() ) {
//			person_current.set_selected(true);
//		}
//	}	
	//p;
	
	render_header();
	    fill_text(p.get_dni(), CONTENT_DNI_COLUMN);
	    cout<<" | ";
	    fill_text(p.get_first_name(), CONTENT_NAME_COLUMN);
	    cout<<" | ";
	    fill_text(p.get_last_name(), CONTENT_LAST_COLUMN);
	    cout<<endl;
	render_footer(1);
}
void render_header() {
	//cout<<"+";
	fill_text("-", CONTENT_DNI_COLUMN+1, "-");
	cout<<"+";
	fill_text("-", CONTENT_NAME_COLUMN+2, "-");
	cout<<"+";
	fill_text("-", CONTENT_LAST_COLUMN+2, "-");
	cout<<"+";
	cout<<endl;	
	fill_text("DNI", CONTENT_DNI_COLUMN);
	cout<<" | ";
	fill_text("NOMBRES", CONTENT_NAME_COLUMN);
	cout<<" | ";
	fill_text("APELLIDOS", CONTENT_LAST_COLUMN);
	cout<<endl;	
	//cout<<"+";
	fill_text("-", CONTENT_DNI_COLUMN+1, "-");
	cout<<"+";
	fill_text("-", CONTENT_NAME_COLUMN+2, "-");
	cout<<"+";
	fill_text("-", CONTENT_LAST_COLUMN+2, "-");
	cout<<"+";
	cout<<endl;	
}
void render_content() {
	locate_at_content();
	render_header();
		
	for(int i = 0; people.size() > i; i++) {
		Person person_current = Person(* people[i]);
	    //fill_text(person_current.get_id() + "", 5);
	    //cout<<" | ";
	    fill_text(person_current.get_dni(), CONTENT_DNI_COLUMN);
	    cout<<" | ";
	    fill_text(person_current.get_first_name(), CONTENT_NAME_COLUMN);
	    cout<<" | ";
	    fill_text(person_current.get_last_name(), CONTENT_LAST_COLUMN);
	    cout<<endl;

	}
	render_footer(people.size());
 
}

string ask_command() {
	string command;
	cout<<"";
	cin>>command;
	return command;
}
void center_text(string _str, int max) {
//	int u =  - _str.length();
	int first = max/2 - (_str.length()/2);
	for(int i = 0; first > i; i++) {
		cout<<" ";
	}
	cout<<_str;
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
	bool found = false;
	for(int i = 0; people.size() > i; i++) {
		Person person_current = Person(* people[i]);
		if ( person_current.get_dni() == current_dni ) {
			found = true;
			people.erase(people.begin() + i);
		}
	}
	if ( found ) {
		cout<<"Se elimino el registro.";
	} else {
	cout<<"No se encontro ningun registro.";
	}

	return "";
}

string do_list() {
	return "";
}

string do_about() {
	locate_at_content();
	center_text("LISTA DE PERSONAL", CONTENT_LINE_MAX_X);
	cout<<endl;
	center_text("Version 1.2", CONTENT_LINE_MAX_X);
	cout<<endl;
	
	center_text("Es una aplicacion para controlar a nuestro personal.", CONTENT_LINE_MAX_X);
	cout<<endl;
	center_text("Creditos:", CONTENT_LINE_MAX_X);
	cout<<endl;
	center_text("- Ray Rojas", CONTENT_LINE_MAX_X);
	return "stop";
}

string do_search() {
	locate_at_question();
	string _codigo;
	cout<<"Ingrese DNI: ";
	cin>>_codigo;
	for(int i = 0; people.size() > i; i++) {
		Person person_current = Person(* people[i]);
	    if ( person_current.get_dni() == _codigo ) {
	    	render_one(person_current);
		}
	}
	return "stop";
}

void exec_command(string _command) {
	string response = "";
	for(int i = 0; NCHOICES > i; i++) {
		if ( _command == CHOICES[i][1] ) {
			response = m[CHOICES[i][2]]();
		}
	}
	if ( response != "stop" ) {
			render_content();

	}
}

void locate_at_question() {
    COORD xy ;
    xy.X = 0 ;
    xy.Y = ASK_LINE_Y;
    SetConsoleCursorPosition( 
    	GetStdHandle(STD_OUTPUT_HANDLE), xy);
    
    cout << string(CONTENT_LINE_MAX_X, ' ');    	

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

void load_database() {
	Person *d = new Person((people.size() + 1), "78163782", "Juanito", "Alcachofa");
	people.push_back(d);
	Person *a = new Person((people.size() + 1), "46004343", "Ray", "Rojas");
	people.push_back(a);	
	Person *b = new Person((people.size() + 1), "20000090", "Carmen", "Enciso");
	people.push_back(b);
	Person *c = new Person((people.size() + 1), "78463781", "Jack", "Destripador");
	people.push_back(c);
}


int main(int argc, char** argv) {
//	int nchoices = 5;
	string todo = "";
//	CHOICES = new string[NCHOICES][3];
//	string choices[nchoices][3];
	render_title("Usuarios");
	CHOICES[0][0] = "Listar";
	CHOICES[0][1] = "L";
	CHOICES[0][2] = "do_list";
	
	CHOICES[1][0] = "Buscar";
	CHOICES[1][1] = "B";
	CHOICES[1][2] = "do_search";
	
	CHOICES[2][0] = "Nuevo";
	CHOICES[2][1] = "N";
	CHOICES[2][2] = "do_new";

	CHOICES[3][0] = "Editar";
	CHOICES[3][1] = "E";
	CHOICES[3][2] = "do_edit";
	
	CHOICES[4][0] = "Eliminar";
	CHOICES[4][1] = "D";
	CHOICES[4][2] = "do_delete";
	
	CHOICES[5][0] = "Acerca de";
	CHOICES[5][1] = "A";
	CHOICES[5][2] = "do_about";


	m["do_new"] = &do_new;
	m["do_edit"] = &do_edit;
	m["do_delete"] = &do_delete;
	m["do_list"] = &do_list;
	m["do_search"] = &do_search;
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
	load_database();
	render_content();
	do {
		locate_at_question();
		//cout << string(50, '\n');
		todo = ask_command();
		exec_command(todo);
	} while(true);
	
	
	
	return 0;
}
