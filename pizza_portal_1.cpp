 /****************************************
 ** Profram Filename: Assignment_2.cpp 
 ** Date: 28-04-2019
 ** Author: Sanchit Chopra
 ** Description: This is one of the cpp file which is compiled together with other cpp files and run the code.
 ** Input: We see what was the customer or employeer choice and then depending upon calling one of the required function.
 ** Output: In output, it is running the functions we choose after having the customer choice and giving the outputs.
****************************************/ 
#include"./pizza.h"
#include"./pizza_func.h"
#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

/*******************************
** Function Filename: remove_from_menu
** Parameters: int index
** Description: This function removes the pizza from the menu that the user want to remove and saves in a new array.
** Input:Passes the index entered by the user.
** Output: This function passes that new array to another function.
*******************************/
void Menu::remove_from_menu(int index){
	int k =0,a;Menu me;
	string s = " ",b="",c="";
	Menu m = menu();
	this-> pizza_1 = new Pizza[(m.get_num_pizzas()+2)];
	this-> new_ing = new string[(m.get_num_pizzas()+2)];
	for(int i =1;i<= m.get_num_pizzas();i++){
		if(i == index){//checking if i is equal to index entered.
			continue;
		}
		else{	//if not thsi loop will move
			pizza_1[i].set_name(m.pizzas[i].get_name());
			pizza_1[i].set_small_cost(m.pizzas[i].get_small_cost());
			pizza_1[i].set_medium_cost(m.pizzas[i].get_medium_cost());
			pizza_1[i].set_large_cost(m.pizzas[i].get_large_cost());
			m.new_ing[i] = m.new_ing[i]; 
			pizza_1[i].set_num_ingredients(m.pizzas[i].get_num_ingredients());
		}		
	}
	for(int i = index ;i<m.get_num_pizzas();i++){//giving index i the value of i+1 and starting the loop from index and sorting it.
		pizza_1[i].set_name(pizza_1[i+1].get_name());//name
		pizza_1[i].set_small_cost(pizza_1[i+1].get_small_cost());//small cost
		pizza_1[i].set_medium_cost(pizza_1[i+1].get_medium_cost());//medium cost
		pizza_1[i].set_large_cost(pizza_1[i+1].get_large_cost());//large cost
		pizza_1[i].set_num_ingredients(pizza_1[i+1].get_num_ingredients());//num of ingredients
		m.new_ing[i] = m.new_ing[i+1];
	}	
	ofstream file;
	file.open("menu.txt");
	for(int i =1;i<=(m.get_num_pizzas()-1);i++){	//outputing the result to the file.
		file<<pizza_1[i].get_name()<<" "<<pizza_1[i].get_small_cost()<<" "<<pizza_1[i].get_medium_cost()<<" "<<pizza_1[i].get_large_cost()<<" "<<pizza_1[i].get_num_ingredients()<<" "<<m.new_ing[i]<<endl;	
	}
	cout<<"Your item has been removed from the menu.."<<endl;
}
/*******************************
** Function Filename: adding_to_menu
** Parameters: N/A
** Description: This function ask the user some question required for the adding pizza.
** Input:get all the inforation and save in each array.
** Output:Passing those all arrays to other function where they are couted.
*******************************/

void Menu::adding_to_menu(){
	int small_cost,medium_cost,large_cost,num_ingredients;
	int play =1,i=0,s,l,mo;
	Menu m;
	Menu me = m.menu();
	string name,tmp,ingredients,d;
		cout<<"What is the name of the Pizza you want to add: ";//asking some question about what the user wants to add
		cin>>d;
		name = verify(d);
		cout<<"How much is the cost for small size of that Pizza you want to add: $";//cost of small size.
		cin>>s;
		small_cost = verify_i(s);
		cout<<"How much is the cost for medium size of that Pizza you want to add: $";//cost of medium size
		cin>>mo;
		medium_cost = verify_i(mo);
		cout<<"How much is the cost for large size of that Pizza you want to add: $";//cost of large size
		cin>>l;
		large_cost = verify_i(l);
		cout<<"How many ingredients are in the Pizza: ";//num of ingredients
		cin>> num_ingredients;
		for(int i =1;i<=num_ingredients;i++){	
			cout<<"Enter your "<<i<<" ingredient: ";//getting all that ingredients
			cin>>tmp;
			ingredients += tmp+" ";
			
		}
	ofstream file ;
	file.open("menu.txt");
	cout<<m.get_num_pizzas()<<endl;
	for(int i =1;i <= (m.get_num_pizzas());i++){	//adding the pizza the user want to see in the menu.
		file<<me.pizzas[i].get_name()<<" "<<me.pizzas[i].get_small_cost()<<" "<<me.pizzas[i].get_medium_cost()<<" "<<me.pizzas[i].get_large_cost()<<" "<<me.pizzas[i].get_num_ingredients()<<" "<<me.new_ing[i]<<endl;
	}
	file<<name<<" "<<small_cost<<" "<<medium_cost<<" "<<large_cost<<" "<<num_ingredients<<" "<<ingredients<<endl;
	cout<<"Your item had been added to the menu."<<endl;
}
/*******************************
** Function Filename: view_menu
** Parameters: N/A
** Description: This function shows the menu to the user.
** Input: N/A
** Output: Shows the menu to the user.
*******************************/

void Menu::view_menu(){
	Menu me;
	Menu m = me. menu();
	for(int i =1;i<=m.get_num_pizzas();i++){//Showing the whole menu.
		cout<<i<<"."<<endl;
		cout<<"Name Of the Pizza: "<<m.pizzas[i].get_name()<<endl;//ordernumber
		cout<<"Price for Small size: "<<m.pizzas[i].get_small_cost()<<endl;//small cost
		cout<<"Price for Medium sixe: "<<m.pizzas[i].get_medium_cost()<<endl;//medium cost
		cout<<"Price for Large size: "<<m.pizzas[i].get_large_cost()<<endl;//large cost
		cout<<"Number Of Ingrediens in it: "<<m.pizzas[i].get_num_ingredients()<<endl;//number of ingredients
		cout<<"The Ingredients are: "<<m.new_ing[i]<<endl;///ingredients.
		cout<<endl;
	}
	
	
}
/*******************************
** Function Filename: menu
** Parameters: N/A
** Description: This funtion gets the menu data from the given file.
** Input:The given file for this function
** Output: Retaurn the whole data as an array and can be used in some other function.
*******************************/

Menu Menu::menu(){
	string line,ingred="";
	int num_pizza=1,i=0,data=0;
	ifstream file;
	file.open("menu.txt");
	while(getline(file,line)){
		set_num_pizzas(num_pizza++);//counting the lines in the file.
	}
	file.close();
	file.open("menu.txt");
	int num = (get_num_pizzas() +3);
	cout<< num<<endl;
	this-> pizzas= new Pizza[num];
	cout<<get_num_pizzas()<<endl;
	cout<<num_pizzas<<endl;
	this->new_ing = new string[num];
	for(int i =1;i<=get_num_pizzas();i++){	
		file>>line; 
		pizzas[i].set_name(line);//getting the name of the pizza
		file>>data;
		pizzas[i].set_small_cost(data);//getting the small cost
		file>>data;
		pizzas[i].set_medium_cost(data);//getting the medium cost
		file>>data;
		pizzas[i].set_large_cost(data);//getting the large cost
		file>>data;
		pizzas[i].set_num_ingredients(data);//getting the num of ingredients
		getline(file,ingred);
		pizzas[i].set_ingredients(&ingred);//getting the ingredients
		new_ing[i] = pizzas[i].get_ingredients();
	}
	return *this;
}
/*******************************
** Function Filename: order
** Parameters: string *array
** Description: This function ask some questions from the user to place order.
** Input: We pass the array in which the orders are saved.
** Output: Passes all the information to other funtion where they are couted.
*******************************/

void Menu::order(string *array){
	Restaurant r;	
	string option = "",size[10],quantity[10],arr[10],p;
	cout<<"Do you want to order the pizzas from your recent result(yes or no): ";//asking theuser if they want to order from there search
	cin >> option;	
	int a=0,b=0,c=0,j=0,i=0,count=0;
	while(option == "yes"){
		cout<<"Enter the number of which pizza you need to order:";//asking the number of pizza
		cin>>a;
		j = verify_i(a);	
		cout<<"What size of "<<array[j]<<" you want to order(S,M,L): ";//what ize they need
		arr[i] = array[j];
		cin>>b;
		size[i] = verify_i(b);
		cout<<"Hw many "<<array[j]<<" you need: ";//howmany they need
		cin>>c;
		quantity[i] = verify_i(c);
		cout<<"Do you want to order any other pizza from the search(yes or no): ";//if they want to add more or not.
		cin >> p;
		option = verify(p);
		i++,count++;
	}	
	r.output_orders(arr,size,quantity,count);//calling another function
}
/*******************************
** Function Filename: orders
** Parameters: N/A
** Description: This function gets the orders from the given file.
** Input:The file given to us.
** Output:Passes all the orders to other function where they are couted. 
*******************************/

Restaurant Restaurant::orders(){
//	Restaurant re;
	int y=1,num_count=0,num=0,var,k=1,count=0,j=0,var_1=0,array[20];
	ifstream file;
	string line,pizza_ordered,pizzas[50],x="";
	file.open("orders.txt");
	while(getline(file,line)){	//counting the lines in the files
		num++;	
	}	
	set_lines(num);
	file.close();
	file.open("orders.txt");
	this->order = new Orders[(get_lines()+3)];
	for(int i =0;i<(get_lines()+3);i++){
		order[i]. pizza_ordered = new Orders[10];	
	}
	for(int i =1;i<=get_lines();i++){	//getting the data of the orders.
		file>>var;order[i].set_order_num(var);//getting the order num
		file>>line;order[i].set_name(line);//getting the customer name
		file>>line;order[i].set_customer_cc(line);//getting the customer_cc
		file>>line;order[i].set_customer_phone(line);//getting the customer phone
		getline(file,x);count =0;
		for(int a =0;a<x.size();a++){
			if(x.at(a) != ' '){
				pizzas[k] += x.at(a);	
			}	
			else if(x.at(a) == ' '){
				k++,count++;	//getting the pizza ordered.
			}
		}
		for(int j=1; j<= (count/3);j++){
			order[i].pizza_ordered[j].set_pizza_name(pizzas[(++y)]);//getting te anme of the pizza
			order[i].pizza_ordered[j].set_pizza_size(pizzas[(++y)]);//getting the size of the pizza
			order[i].pizza_ordered[j].set_quantity(pizzas[(++y)]);//getting the quantity of the pizza
		}
		order[i].set_count(count/3);
	}
	return *this;
}	
/*******************************
** Function Filename:view_order 
** Parameters: N/A
** Description: This function is showing the orders to the user.
** Input:N/A
** Output: Shows the user the orders.
*******************************/

void Restaurant::view_orders(){
	Restaurant r = view_hours();
	r= orders();
	for(int i=1;i<=r.get_lines();i++){//howing fullorder
		cout<<"Order Number: "<<r.order[i].get_order_num()<<endl;//ordernum
		cout<<"Customer Name: "<<r.order[i].get_name()<<endl;//customer name
		cout<<"Custoemr Credit Card Number: "<<r.order[i].get_customer_cc()<<endl;//customer cc
		cout<<"Customer Phone: "<<r.order[i].get_customer_phone()<<endl;//customer phone
		for(int j=1;j<=(r.order[i].get_count());j++){
				cout<<"Pizza Order: "<<r.order[i].pizza_ordered[j].get_pizza_name()<<endl;//pizzaname
				cout<<"Size of Pizza: "<<r.order[i].pizza_ordered[j].get_pizza_size()<<endl;//pizza size
				cout<<"Quantity: "<<r.order[i].pizza_ordered[j].get_quantity()<<endl;//pizza quantity
		}
		cout<<endl;
	}	
	
}
/****************
** Function Name: delete_m
** Paramters: N/A
** Description: This function deletes the dynanmically allocated arrats.
** Input: N/A
** Output: Deletes all the arrays.
***************/
void Restaurant::delete_m(){
	Restaurant r;
	for(int i =0;i<r.get_lines()+3;i++){
		delete[] order;
		delete[] week;
		delete[] employees;
		delete[] order_1;
		delete[] menu;	
	}
}
Restaurant::~Restaurant(){	//Deconstructor for Restaurant
}
Menu::~Menu(){	//Deconstructor for menu.
	
}
Orders::~Orders(){	//Deconstructor for Orderes.

}
/****************
** Function Name: delete_w
** Paramters: N/A
** Description: This function deletes the dynanmically allocated arrats.
** Input: N/A
** Output: Deletes all the arrays.
***************/

void Menu::delete_w(){
	Menu m;
	for(int i =0;i<m.get_num_pizzas();i++){
		delete[] pizzas;
		delete[] pizza_1;	
		delete[] new_ing;
	}
}
