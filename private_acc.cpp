 /****************************************
 ** Profram Filename: Assignment_2.cpp 
 ** Date: 28-04-2019
 ** Author: Sanchit Chopra
 ** Description: This is one of the cpp file in which all the constructors,mutator and accessor are defined.
 ** Input: The function in this file are passed some value specific to for what they are made.
 ** Output: In output, these functions give us the value of that private character.
****************************************/ 

#include"./pizza.h"
#include"./pizza_func.h"
#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

Pizza::Pizza(){				// Constructor for Pizza
	name="";
	small_cost=0;
	medium_cost=0;
	large_cost=0;
	num_ingredients=0;
	ingredients=NULL;		
}
Menu::Menu(){ 				//Constructor for Menu
	num_pizzas=0;
	pizzas=NULL;
	pizza_1=NULL;

}
void Pizza::set_name(const string name){		//Mutator for pizza name.
	this-> name= name;
}
string Pizza::get_name()const{		//Accessor for pizza name
	return name;
}
void Pizza::set_num_ingredients(const int num){		//Mutator for num of ingredients.
	this-> num_ingredients = num;
}
int Pizza::get_num_ingredients()const{		//Accessor for num of ingredients.
	return num_ingredients;	
}
void Pizza::set_small_cost(const int small){	//Mutator for small cost.
	this-> small_cost = small;	
}
int Pizza::get_small_cost()const{	//Accessor for small cost.
	return small_cost;	
}
void Pizza::set_medium_cost(const int medium){		//Mutator for medium cost
	this-> medium_cost = medium;	
}
int Pizza::get_medium_cost()const{			//Accessor for medium cost.
	return medium_cost;	
}
void Pizza::set_large_cost(const int large){		//Mutator for large cost.
	this-> large_cost = large;	
}
int Pizza::get_large_cost()const{			//Accessor for large cost.
	return large_cost;	
}

void Pizza::set_ingredients(string *ing){		//Mutator for ingredients.
	this-> ingredients = ing;	
}
string Pizza::get_ingredients(){		//Accessor for ingredients.
	return *ingredients;	
}

void Orders::set_count(const int co){		//Mutator for count.
	this->count = co;	
}
int Orders::get_count()const{		//Accessor for count
	return count;	
}
Pizza::~Pizza(){		//Deconstructor for Pizza
	delete[]  this->ingredients;
	delete &name;
}
Restaurant::Restaurant(){	//Coonstructore for Restaurant
	num_of_lines=0;
	menu=NULL;
	employees=NULL;
	week=NULL;
	name="";
	phone="";
	address="";
	order=NULL;
	order_1=NULL;

}
Orders::Orders(){	//Constructore  for Restaurant
	order_num=0,count=0;
	name="";
	pizza_name="";
	Customer_cc="";
	customer_phone="";
	Pizza_size="";
	quantity="";
}		
void Restaurant::set_employees(const int p){		//Mutator for employees.
	this->emp = p;	
}
int Restaurant::get_employees()const{		//Accessor for employees.
	return emp;	
}
void Orders::set_order_num(const int num){	//Mutator for order num.
	this->order_num = num;	
}
int Orders::get_order_num()const{	//Accessor for order num.
	return order_num;	
}
void Orders::set_name(const string name){	//Mutator for name
	this->name = name;	
}
string Orders::get_name()const{		//Accessor for name
	return name;	
}
void Orders::set_customer_cc(const string cc){	//Mutator for customer_cc
	this->Customer_cc = cc;	
}
string Orders::get_customer_cc()const{     //Accessor for customer_cc
	return Customer_cc;	
}
void Orders::set_customer_phone(const string phone){	//Accessor for custoomer phone
	this->customer_phone = phone;	
}
string Orders::get_customer_phone()const{	//Mutator for customer phone
	return customer_phone;	
}
void Orders::set_pizza_size(const string size){	//Mutator for pizza size
	this->Pizza_size= size;	
}
string Orders::get_pizza_size()const{	//Accessor for pizzza size
	return Pizza_size;	
}
void Orders::set_quantity(string quant){	// Mutator for quantity
	this->quantity = quant;	
}
string Orders::get_quantity()const {		//Accessor for quantity
	return quantity;	
}
void Orders::set_pizza_name(const string pizza){	//Mutator for pizza name
	this->pizza_name = pizza;	
}
string Orders::get_pizza_name()const{		//Accessor for pizza name
	return pizza_name;	
}
int  Restaurant::set_lines(const int line){	//Mutator for lines
	this->num_of_lines = line;	
}
int Restaurant::get_lines()const{	//Accessor for lines
	return num_of_lines;	
}

void Restaurant::set_employees(employee ep){	//Mutator for employees
	this->employees = &ep;	
}
employee* Restaurant::get_employees(){	//Accessor for employees
	return employees;
}
void Restaurant::set_menu(Menu m){	//Mutator for menu
	this -> menu = &m;	
}
Menu* Restaurant::get_menu(){		//Accessor for menu
	return menu;	
}
void Menu::set_num_pizzas(const int pizzas){	//Mutator for num pizzas.
	this-> num_pizzas = pizzas;	
}
int Menu::get_num_pizzas()const{	//Accessor for num pizzas
	return num_pizzas;	
}
void Restaurant::set_days(const int q){
	this->num = q;
}	
int Restaurant::get_days()const{
	return num;	
}
Restaurant::Restaurant(const Restaurant &rest){		//Copy Constructor of restaurant
	this->week = new hours[8];
	set_days(rest.get_days());
	for(int i=1;i<=(get_days()-2);i++){
		week[i].day = rest.week[i].day;
		week[i].open_hour = rest.week[i].open_hour;
		week[i].close_hour = rest.week[i].close_hour;	
	}
	set_lines(rest.get_lines());
	this->order = new Orders[get_lines()+3];
	for(int i= 0;i<(get_lines()+3);i++){
		order[i].pizza_ordered = new Orders[11];
	}
	for(int i =1;i<=(get_lines());i++){
		order[i].set_order_num(rest.order[i].get_order_num());
		order[i].set_name(rest.order[i].get_name());
		order[i].set_customer_cc(rest.order[i].get_customer_cc());
		order[i].set_customer_phone(rest.order[i].get_customer_phone());
		order[i].set_count(rest.order[i].get_count());
		for(int j=1;j<=(order[i].get_count());j++){
			order[i].pizza_ordered[j].set_pizza_name(rest.order[i].pizza_ordered[j].get_pizza_name());	
			order[i].pizza_ordered[j].set_pizza_size(rest.order[i].pizza_ordered[j].get_pizza_size());
			order[i].pizza_ordered[j].set_quantity(rest.order[i].pizza_ordered[j].get_quantity());
		
		}
	}

}
Menu::Menu(const Menu &m){		//Copy Constructor for Menu.
	set_num_pizzas(m.get_num_pizzas());
	pizzas = new Pizza[(get_num_pizzas()+3)];
	new_ing = new string[(get_num_pizzas()+3)];
	for(int i=1;i<=(get_num_pizzas()+1);i++){
		pizzas[i].set_name(m.pizzas[i].get_name());
		pizzas[i].set_small_cost(m.pizzas[i].get_small_cost());
		pizzas[i].set_medium_cost(m.pizzas[i].get_medium_cost());
		pizzas[i].set_large_cost(m.pizzas[i].get_large_cost());
		pizzas[i].set_num_ingredients(m.pizzas[i].get_num_ingredients());
		new_ing[i] = m.new_ing[i];
	}
}	
