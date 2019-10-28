 /****************************************
 ** Profram Filename: Assignment_2.cpp 
 ** Date: 28-04-2019
 ** Author: Sanchit Chopra
 ** Description: This is the main funtion, which runs the program by calling a series of funtions.
 ** Input: In this cpp file, we are getting some inputs like whether they are employee,customer and if they want to quit.
 ** Output: In output, it calls those functions and shows the result to the user.
****************************************/ 
#include<iostream>
#include"./pizza.h"
#include"./pizza_func.h"
#include<fstream>
#include<cstring>
using namespace std;
/***************************
** Program filename: main
** Parameter: int argc,char **argv
** Description: As this funtion is main so includes other function and shows the result.
** Input: N/A
** Oupput: This functions call other functions and shows the result to the user.
***************************/
int main(int agrc, char** argv){
	int e_selection,c_selection;
	Restaurant r;Menu m;Orders o;
	string choice,s;
	string id;
	employee *e = new employee();
	employee *b = e;
	cout<<"Welcome to Bytes Pizza!!!"<<endl;
	cout<<"You are an employee or a cutomer, 'E' for an employee, 'C' for a customer or 'Q' for exit: ";
	cin>>s;
	choice = verify(s);
	while(choice != "Q"){
		login_start(b);
		if(choice == "E"){
			giving_employee_options(e_selection);
		}
		if(choice == "C"){
			giving_customer_options(c_selection);
		}
		cout<<"Welcome to Bytes Pizza!!!"<<endl;
		cout<<"You are an employee or a customer,'E' for an employe , 'C' for a customer or 'Q' for exit:";
		cin>>choice;
	}
	r.delete_m();
	m.delete_w();
	return 0;
}
