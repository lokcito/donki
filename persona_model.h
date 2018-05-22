#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Person
{
  private:
  	string first_name;
  	string last_name;
  	string dni;
  	bool selected;
  	int id;
  public:
  	Person(int _id, string _dni, string _first_name, string _last_name);
  	string get_first_name();
  	string get_last_name();
  	string get_dni();
  	bool get_selected();
  	void set_selected(bool value);
  	int get_id();
};

Person::Person(int _id, string _dni, string _first_name, string _last_name)
{ 
	id = _id;
	first_name = _first_name;
	last_name = _last_name;
	dni = _dni;
}

bool Person::get_selected() {
	return selected;
}

void Person::set_selected(bool value) {
	selected = value;
	//cout<<"ooo";
}

int Person::get_id()
{
  return id;
}

string Person::get_dni()
{
  return dni;
}

string Person::get_first_name()
{
  return first_name;
}

string Person::get_last_name()
{
  return last_name;
}

