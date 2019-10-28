 /****************************************
 ** Profram Filename: Assignment_2.cpp 
 ** Date: 28-04-2019
 ** Author: Sanchit Chopra
 ** Description: This is one of the cpp file which is compiled together with other cpp files and run the code.
 ** Input: We see what was the customer or employeer choice and then depending upon calling one of the required function.
 ** Output: In output, it is running the functions we choose after having the customer choice and giving the outputs.
****************************************/ 
#include"./pizza.h"
#include<iostream>
#include"./pizza_func.h"
#include<fstream>
#include<cstring>
using namespace std;

/******************************
** Function Name: change_hours
** Parameter: N/A
** Description:This function ask the user which hours of theday they want to change.
** Input:The day and new open and close hours ofthe restaurant.
** Output: Passes that all information to other function where it is couted.
******************************/
Restaurant Restaurant::change_hours(){
	string day,o,cl,e;
	Restaurant r = view_hours();
	cin.ignore();
	cout<<"Which day you want to change your hours: ";//askin the day for which the user want ot change the timins
	getline(cin,e);
	day = verify(e);
	cout<<"What is your new opening timings: ";//getting the new timings
	getline(cin,o);
	int n = o.length();
	char change[n+1],x[10];
	strcpy(change,o.c_str());
	cout<<"What is your new closing timings: ";//getting the new timings
	getline(cin,cl);
	int y= cl.length();
	char change_1[n+1],a[10];
	strcpy(change_1,cl.c_str());
	for(int i =1;i<8;i++){
		if((r.week[i].day).compare(day)==0){
			r.week[i].open_hour = " ";
			r.week[i].close_hour = " ";	
			for(int y=0;y<n;y++){
				r.week[i].open_hour +=change[y];//changing the old n with anew one
				r.week[i].close_hour += change_1[y];	//changing the old one with a new one.
			}
		}
	}
	return r;	
	
}
/******************************
** Function Name: output_hours
** Parameter: N/A
** Description:This functions shows the changed hours of the restaurantby the user.
** Input:N/A
** Output: Shows the changed hours.
******************************/

void Restaurant::output_hours(){
	ifstream file;
	file.open("restaurant.txt");
	getline(file,name);
	getline(file,phone);
	getline(file,address);
	file.close();
	Restaurant r = change_hours();
	ofstream file_out;
	file_out.open("restaurant.txt");	
	cout<<"This is your new hours: "<<endl;
	file_out<<name<<endl<<phone<<endl<<address<<endl;
	for(int i =1;i<8;i++){//showing the new changed hours
		cout<<r.week[i].day<<" "<<r.week[i].open_hour<<" "<<r.week[i].close_hour<<endl;
		file_out<<r.week[i].day<<" "<<r.week[i].open_hour<<" "<<r.week[i].close_hour<<endl;
		
	}

}
/******************************
** Function Name: view_hours
** Parameter: N/A
** Description:This function shoes the hours of the restaurant each day to the user.
** Input: N/A
** Output: Shows the hours to the user.
******************************/

Restaurant Restaurant::view_hours(){
	string line;
	int num_of_lines=0,i=1;
	this->week = new hours[10]; 
	ifstream file;
	file.open("restaurant.txt");
	getline(file,name);
	getline(file,phone);
	getline(file,address);
	file>>week[i].day;
	file>>week[i].open_hour;
	file>>week[i].close_hour;
	i++;
	while(getline(file,line)){
		file>>week[i].day;//getting the hours from the fle.
		file>>week[i].open_hour;
		file>>week[i].close_hour;
		i++;
	}
	set_days(i);
	return *this;
}	
void Restaurant::hours_show(){	
	Restaurant r = view_hours();
	for(int j = 1;j <= (r.get_days()-2); j++){//showing the hours
		cout<<r.week[j].day<<" "<<r.week[j].open_hour<<" "<<r.week[j].close_hour<<endl;	
	}
	cout<<"aa"<<endl;

}
/******************************
** Function Name: view_phone
** Parameter: N/A
** Description:This function shows the user the phone number of the restaurant.
** Input:N/A
** Output: Shows the phone number of the restaurant.
******************************/

void Restaurant::view_phone(){
	ifstream file;
	file.open("restaurant.txt");
	getline(file,name);
	getline(file,phone);//showing the phone number
	cout<<"The phone Number is: "<<phone<<endl;
}
/******************************
** Function Name: view_address
** Parameter: N/A
** Description:This function shows user the address of the restaurant.
** Input:N/A
** Output: Shows the address to the user.
******************************/

void Restaurant::view_address(){
	ifstream file;
	file.open("restaurant.txt");
	getline(file,name);
	getline(file,phone);
	getline(file,address);//showing the address
	cout<<"The address is: "<<address<<endl;	
}
/******************************
** Function Name:set_pizza_cost 
** Parameter: int max
** Description: This function shows the user the result of pizzas depending upon what max cost they enter.
** Input: We passing the max the user can pay for the pizza.
** Output: We are showing the user, the pizzas that are less than or equal to their max.
******************************/

void Menu::set_pizza_cost(int max){
	string line,ingred="";
	int num_pizza=0,i=0,data=0;
	ifstream file;
	file.open("menu.txt");
	while(getline(file,line)){
		set_num_pizzas(num_pizza++);//coutnting the lines
	}
	file.close();
	file.open("menu.txt");
	int num = (get_num_pizzas() +3);
	cout<< num<<endl;
	this-> pizzas= new Pizza[num];
	cout<<get_num_pizzas()<<endl;
	this->new_ing = new string[num];
	for(int i =1;i<=get_num_pizzas()+1;i++){	
		file>>line; 
		cout<<line<<" ";
		file>>data;
		if(data > max){
			cout<< "N/A"<<" ";	//if the data is gretaer than max
		}
		else{
			cout<<data<<" ";	
		}
		file>>data;
		if(data > max){	//if the data is greater thanx max
			cout<<"N/A"<<" ";	
		}
		else{
			cout<<data<<" ";
		}
		file>>data;
		if(data > max){	//if the data is greater than max
			cout<<"N/A"<<" ";
		}
		else{
			cout<<data<<" ";	
		}
		file>>data;
		cout<<data<<" ";
		getline(file,ingred);//getting therest data in one line
		cout<<ingred<<endl;
		cout<<"enbd"<<endl;
	}
}
/**********************************
** Function Name: verify
** Description: This function checks if the input by the user is a string as needed.
** Parameter: string var
** Input: we passs the input by the user
** Output: checks and tell if the inputis true.
************************************/	
string verify(string var){
	bool error = true;
	for(int i =0;i<var.size();i++){
		if((var.at(i) >= '0' && var.at(i) <= '9')){
			cout<<"You should not enter any int,please see the option again: ";
			error = true;
			break;
		}
		else{
			error = false;
		}
	}
	if(error == true){
		cin>>var;	
		verify(var);
	}
	string y;	
	y = var;		
	return y;
}
/**********************************
** Function Name: verify_i
** Description: This function checks if the input by the user is an integer as needed.
** Parameter: string var
** Input: we passs the input by the user
** Output: checks and tell if the inputis true.
************************************/	

int verify_i(int var){
	bool error = true;
		if(!(var >= '0' && var <= '9')){
			cout<<"You should enter int only,please see the option again: ";
			error = true;
		}
		else{
			error = false;
		}
	if(error == true){
		cin>>var;	
		verify_i(var);
	}
	int y;
	y = var;		
	return y;
}
			
