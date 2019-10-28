/****************************************
 ** Profram Filename: Assignment_2.h
 ** Date: 28-04-2019
 ** Author: Sanchit Chopra
 ** Description: This is the h file there are prototyes of  all the functions which I needed in my code.
 ** Input: N/A
 ** Output: In output, it is defining all of the functions.
****************************************/ 
using namespace std;

bool password(string id,employee *ep);
void login_start(employee *ep);
void giving_employee_options(int e_selection);
void giving_customer_options(int c_selection);
void choice(int &e_selection);
void first();
string verify(string var);
int verify_i(int var);
void common_view_hour();
void customer_choice(int &c_selection);
void choice_3();
void removing();
void log_out();
void remove_selected_option();
void order_after_cost(string *array);
void choice_2_customer();
string verify(string var);
void option_remove(string *total,int &i);
void exclude_option(string *total,int &i);
string place_order();
