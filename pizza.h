/****************************************
 ** Profram Filename: Assignment_2.h
 ** Date: 28-04-2019
 ** Author: Sanchit Chopra
 ** Description: This is the h file defining all the classes and the struct which I needed in my code.
 ** Input: N/A
 ** Output: In output, it is defining these classes and structs.
****************************************/ 

#include<iostream>

using namespace std;
#ifndef PIZZA_H
#define PIZZA_H
struct employee{
	int id;
	string password;
	string first_name;	
	string last_name;
};

struct hours{
	string day;	
	string open_hour;
	string close_hour;
};	
class Pizza{
	private:
		string name;
		int small_cost;
		int medium_cost;
		int large_cost;
		int num_ingredients;
		string* ingredients;	
	public:
		Pizza();
		void set_name(const string name);
		string get_name()const;
		~Pizza();
		void set_num_ingredients(const int num);
		int get_num_ingredients()const;
		void set_small_cost(const int cost_1);
		int get_small_cost()const;
		void set_medium_cost(const int cost_2);
		int get_medium_cost()const;
		void set_large_cost(const int cost_3);
		int get_large_cost()const;
		void set_ingredients(string *ing);
		string get_ingredients();
};


class Menu{
	private:
		int num_pizzas;
		Pizza* pizzas;
		Pizza* pizza_1;
	public:	
		Menu();
		Menu search_pizza_by_cost(int &max);
		Menu search_pizza_by_ingredients_to_exclude();
		Menu search_pizza_by_ingredients_to_include();
		void add_to_menu(string name,int small_cost,int medium_cost,int large_cost,int num_ingredients, string ingredients);
		string* new_ing;
		void delete_w();
		void order(string *array);
		void removing_item(int &index);
		void remove_from_menu(int index_of_pizza_on_menu);
		void adding_to_menu();
		void set_num_pizzas(const int pizza);
		void exclude_ingredients_order(bool remover[]);
		Menu(const Menu &m);
		void include_ingredients_order(bool remover[]);
		void single_order();
		int get_num_pizzas()const;
		Menu menu();
		~Menu();
		void set_pizza_cost(int max);
		void set_pizza_cost_result(int max);
		void view_menu();
};
class Orders{
	private:
		int order_num,count;
		string name;
		string pizza_name;
		string Customer_cc;
		string customer_phone;
		string Pizza_size;
		string quantity;
	public:
		Orders();
		Orders* pizza_ordered;
		Orders* pizza_ordered_1;
		void set_order_num(const int num);
		int get_order_num()const;
		void set_name(const string name);
		void delete_o();
		string get_name()const;
		void set_customer_cc(const string cc);
		string get_customer_cc()const;
		void set_customer_phone(const string phone);
		string get_customer_phone()const;
		void set_count(const int co);
		int get_count()const;
		void set_pizza_size(const string size);
		string get_pizza_size()const;
		void set_quantity(string qt);
		string get_quantity()const;
		void set_pizza_name(const string pizza);
		string get_pizza_name()const;
		~Orders();
};
class Restaurant{
	private:
		int num_of_lines,emp;
		Menu* menu;
		employee* employees;
		hours* week;
		int num;
		string name;
		string phone;
		string address;
		Orders* order;
		Orders* order_1;
	public:
		Restaurant();
		int set_lines(const int line);
		void set_days(const int e);
		int get_days()const;
		int get_lines()const;
		string var;
		string get_name(const string name);
		void order_sorting(int &num);
		string set_name()const;
		void set_employees(employee ep);
		void place_order4(string *array,string *size,int *quantity,int &count);
		employee* get_employees();
		void delete_m();
		void set_menu(Menu m);
		Menu* get_menu();
		bool login(employee *ep);
		void hours_show();
		Restaurant view_hours();
		void view_address();
		void view_phone();
		void deleting_order(int &num);
		void set_employees(const int p);
		int get_employees()const;
		void search_menu_by_price();
		void search_by_ingredients();
		void place_order();
		Restaurant change_hours();
		void add_to_menu();
		void place_order1(int *array_order,string *array,string *size,string *quantity,int &count);
		void output_hours();
		void output_orders(string *arr,string *size,string *quantity,int &count);
		void remove_from_menu();
		Restaurant orders();
		void view_orders();
		void remove_orders();
		Restaurant(const Restaurant& r);
		~Restaurant();
};
#endif

