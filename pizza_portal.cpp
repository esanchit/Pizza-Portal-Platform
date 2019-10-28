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

/****************************
* Function Name: login
* Paramters: string user_id,string password
** Description:This funtion is getting the data from the file and checking if the login was successful or not.
** Input: Id entered and password.
** Output:If the login was successful or not.
****************************/
bool Restaurant::login(employee *ep){
	bool flag = true;
	string user_id;
	cout<<"Enter Your ID: ";
	while(flag){
		getline(cin,user_id);//asking the user to enter the id
		for(unsigned int i = 0;i<user_id.size();i++){
			if(user_id[i] >='0' && user_id[i] <='9'){//checking if the id has all ints.
				flag = false;	
			}	
			else{
				flag = true;
				cout<<"Please enter id with only ints: ";
				break;	
			}
		}	
	}
	return password(user_id,ep);
}	
bool password(string user_id,employee *ep){
	int id = stoi(user_id);
	string line,password;
	ifstream file;
	int number_of_employee=0;
	file.open("employee.txt");
	while(getline(file,line)){
		number_of_employee++;	
	}
	cout<<"Enter Your Password: ";//asking the user to enter the password
	getline(cin, password);
	cout<<number_of_employee<<endl;
	file.close();
	file.open("employee.txt");
	while(number_of_employee--){
	employee e;
	file>>e.id;//getting te id
	file>>e.password;//getting the password
	file>>e.first_name;//getting the first name
	file>>e.last_name;//getting the last name
		if(e.id == id && password == e.password){
			ep->first_name = e.first_name;
			ep->last_name = e.last_name;
			return true;
		}	
		else{
			break;	
		}
	getline(file,line);
	}
	return false;
}
/****************************
* Function Name: login_start
* Paramters: string &id,string &password, employee *e
** Description:This funtion is checking if the login was successful or not.
** Input:We are having the idand password entered by the user.
** Output: Showing if the login was successful or not.
****************************/
void login_start (employee *e){
	Restaurant r;
	if((r.login(e))){	//if the password and id matches
			cout<<"Welcome"<<e->first_name<<e->last_name<<endl;	
	}	
	else{
		cout<<"Login Failed. Try Again!!!"<<endl;//if the id and password doesnot match
		login_start(e);	
	}
}
/****************************
* Function Name: giving_employee_options
* Paramters: int e_selection
** Description: In this function, we are just couting some statments are asking which choice they need.
** Input:What user enters as their choice is an input.
** Output:Passing that choice to other funtion.
****************************/

void giving_employee_options(int e_selection){
	string day,open_time,close_time;
	int i =0;
	do{
		cout<<endl;
		cout<<"Want to Change Hours(Press 1)."<<endl;//want to chang hours	
		cout<<"Want to view orders(Press 2)."<<endl;//want to view orders
		cout<<"Want to Remove Order(Press3)."<<endl;//want to remove orders.
		cout<<"Want to add Item to Menu(Press 4)."<<endl;//want to add item
		cout<<"Want to Remove Item from Menu(Press 5)."<<endl;//want to reomve an item
		cout<<"Want to View Menu(Press 6)."<<endl;//want to view menu
		cout<<"Want to view Hours(Press 7)."<<endl;//want t view hours
		cout<<"Want to view Address(Press 8)."<<endl;//want to view address
		cout<<"Want to view Phone(Press 9)."<<endl;//want to view phone
		cout<<"Want to log out(Press 10)."<<endl;//want to logout.
		cout<<"Enter your choice: ";
		cin>>i;
		e_selection = i;
		choice(e_selection);
	}while(e_selection != 10);
}
/****************************
* Function Name: choice
* Paramters: int &e_selection
** Description:In this function, we are implementing the particular function repect ot the user choice.
** Input: We are taken what the user choice was as an input.
** Output:we are calling that particular funtion for that particular choice.
****************************/

void choice(int &e_selection){
	Restaurant e;
	Menu me;
		if(e_selection == 1){	//if the user enters 1
			e.output_hours();
		}
		if(e_selection == 2){	//if the user enter 2
			e.view_orders();	
		}
		if(e_selection == 3){//if the user enter 3
			e.remove_orders();	
		}
		if(e_selection == 4){//if the user enter 4
			me.adding_to_menu();
		}
		if(e_selection == 6){//if the user enters 6
			me.view_menu();
		}	
		if(e_selection == 5){//if the user enter 5
			remove_selected_option();
		}
		if(e_selection == 7){//if the user enters7
			e.hours_show();
		}	
		if(e_selection == 8){//if the user enter 8
			e.view_address();	
		}
		if(e_selection == 9){//if the user enter 9
			e.view_phone();	
		}
	
}
/****************************
* Function Name: giving_cutomer_options
* Paramters: int c_selection
** Description:In this function, we are mainly couting some statments and asking what they want to choice.
** Input:We get the user choice in this function.
** Output:Passes the user choice to other function.
****************************/

void giving_customer_options(int c_selection){
	int j=0;
	do{
		cout<<endl;
		cout<<"Want to view Menu(Press 1)."<<endl;//if they wantto see the menu
		cout<<"Want to search Pizza by Cost(Press 2)."<<endl;//want ot search pizza by cost
		cout<<"Want to search Pizza by Ingredients(Press 3)."<<endl;//want to seaarch pizza by ingredients
		cout<<"Want to place order(Press 4)."<<endl;//want toplace order
		cout<<"Want to view hours(Press 5)."<<endl;//wnat to view hours
		cout<<"Want to view Address(Press 6)."<<endl;//want tp view address
		cout<<"Want to view Phone(Press 7)."<<endl;//wantto view phone
		cout<<"Want to log out(Press 8)."<<endl;//want ot logout
		cout<<"Enter your choice: ";
		cin>>j;
		c_selection =j;
		customer_choice(c_selection);
	}while(c_selection != 8);
}
/****************************
* Function Name: customer_choice
* Paramters: int &c_selection
** Description:This function is implementing the function depending upon the user choice.
** Input:We passing what the user passes as a choice.
** Output:Implements the particular funtion for that choice.
****************************/

void customer_choice(int &c_selection){
	Menu me;
	Restaurant re;
	if(c_selection == 1){	//ifthe user enter 1.
		me.view_menu();	
	}
	if(c_selection == 2){	//if the user enter 2.
		choice_2_customer();
	}
	if(c_selection == 3){	//if the user enter 3.
		choice_3();	
	}
	if(c_selection == 4){//if the user enter 4.
		me.single_order();	
	}
	if(c_selection == 5){//ifthe user enter 5.
		re.hours_show();
		}	
	if(c_selection == 6){//if teh user enter 6.
		re.view_address();	
	}
	if(c_selection == 7){//if the user enter 7
		re.view_phone();	
	}

}
/****************************
* Function Name: choice_3
* Paramters: N/A
** Description:This function is asking whether the user wnat to include or exclude any ingredient.
** Input:N/A
** Output:Calling the function of include or exclude depending upon the user choice.
****************************/

void choice_3(){
	Menu me;
	string choice,c;
	cout<<"Do you want to include(I) an item or exclude(E) an item for a search: ";//asking whether the user want to include or exclude
	cin>>c;
	choice = verify(c);
	if(choice.compare("I")==0){
		me.search_pizza_by_ingredients_to_include();	//ifthe user say include
	}
	if(choice.compare("E")==0){
		me.search_pizza_by_ingredients_to_exclude();//ifthe user say exclude
	}
}
/****************************
* Function Name: choice_2_customer
* Paramters: N/A
** Description:This funtion is mainly asking some questions if they decided to seach by cost.
** Input:N/A
** Output:passes the max amount of money they can spent on the pizza.
****************************/

void choice_2_customer(){
	Menu me;
	string selection,s;
	int max,m=0;
	cout<<"What is the maximum amount you can pay for the pizzas: ";//asking what is themax amount the user can pay
	cin>> m;
	max = verify_i(m);
	me.set_pizza_cost(max);	
	cout<<"Do you want to place an order from the above result(yes or no)";//if the user wants to place an order of that.
	cin >> s;
	selection = verify(s);
	if(selection == "yes"){
		me.set_pizza_cost_result(max);
	}
}
/****************************
* Function Name: remove_selected_option
* Paramters: N/A
** Description:This function is mainly asking if the user want to see the menu before deleting the pizza from menu.
** Input:N/A
** Output:Passes the number of pizza they want to delete from menu to other function.
****************************/

void remove_selected_option(){
	int index,option,a=0;
	Menu m;
	cout<<"Do you want to look at the menu before deciding which pizza you want to delete(if yes enter 1 or enter 0)";//askign if the user want to look at the menu.
	cin>>a;
	option = verify_i(a);
	if(option==1){
		m.view_menu();	
	}
	cout<<"Enter the number(index) of the pizza which you want to delete: ";//asking to enter the index value of that pizza.
	cin>>index;
	m.remove_from_menu(index);	
}
/****************************
* Function Name: remove_orders
* Paramters: N/A
** Description:This function is showing the user the orders first and then asking which number of order they want to remove.
** Input: N/A
** Output:This function, passses the num of order the user want to remove to other funtion.
****************************/

void Restaurant::remove_orders(){
	int num;
	Restaurant r = view_hours();
	r = orders();
	for(int i =1;i<= (get_lines());i++){//telling theuser whatt all order wehave 
		cout<<"Order number: "<<r.order[i].get_order_num()<<" ,for"<<r.order[i].get_name()<<endl;
	}
	cout<<"Enter the order number you want to remove: ";	//assking whihc one they need to remve
	cin>>num;
	r.deleting_order(num);
}
/****************************
* Function Name: order_sorting
* Paramters: int &num
** Description:This funtion is sorting the orders if the user decided to remove any order.
** Input:We are passing the index at which the user want the order to be deleted.
** Output:In output, it deletes that order.
****************************/
	
void Restaurant::order_sorting(int &num){
	Restaurant r = orders();
	this->order_1 = new Orders[r.get_lines()+2];
	for(int i =1;i<(r.get_lines()+2);i++){
		order_1[i].pizza_ordered_1= new Orders[11];	
	}
	for(int i =1;i<=r.get_lines();i++){
		if(i == num){ // if i is equal to num what the user enters
			continue;	
		}	
		else{// if they are not same 
			order_1[i].set_order_num(r.order[i].get_order_num());//getting all the values in a new array
			order_1[i].set_name(r.order[i].get_name());	
			order_1[i].set_customer_cc(r.order[i].get_customer_cc());	
			order_1[i].set_customer_phone(r.order[i].get_customer_phone());	
			for(int j=1;j<=(r.order[i].get_count());j++){
				order_1[i].pizza_ordered_1[j].set_pizza_name(r.order[i].pizza_ordered[j].get_pizza_name());	
				order_1[i].pizza_ordered_1[j].set_pizza_size(r.order[i].pizza_ordered[j].get_pizza_size());	
				order_1[i].pizza_ordered_1[j].set_quantity(r.order[i].pizza_ordered[j].get_quantity());	
			}
		}
	}
	for(int i = num ;i<=(r.get_lines());i++){//sorting that array by putting index value of i+1 in i starting with that index only.
		r.order[i].set_order_num(r.order[i+1].get_order_num());	
		r.order[i].set_name(r.order[i+1].get_name());	
		r.order[i].set_customer_cc(r.order[i+1].get_customer_cc());	
		r.order[i].set_customer_phone(r.order[i+1].get_customer_phone());	
		for(int j=1;j<(r.order[i].get_count());j++){
			r.order[i].pizza_ordered[j].set_pizza_name(r.order[i+1].pizza_ordered[j+1].get_pizza_name());	
			r.order[i].pizza_ordered[j].set_pizza_size(r.order[i+1].pizza_ordered[j+1].get_pizza_size());	
			r.order[i].pizza_ordered[j].set_quantity(r.order[i+1].pizza_ordered[j+1].get_quantity());	
		}
	}
}
/****************************
* Function Name: deleteing_order
* Paramters: int &num
** Description:This funtion is deleting the orders if the user decided to remove any order.
** Input:We are passing the index at which the user want the order to be deleted.
** Output:In output, it deletes that order.
****************************/
	
void Restaurant::deleting_order(int &num){	
	Restaurant r ;
	r.order_sorting(num);	
	ofstream file;
	file.open("orders.txt");
	for(int i= 1;i<=(r.get_lines()-1);i++){//removing that value from the menu
			file<<r.order[i].get_order_num()<<" "<<r.order[i].get_name()<<" "<<r.order[i].get_customer_cc()<<" "<<r.order[i].get_customer_phone()<<" ";
			for(int j=1;j<(r.order[i].get_count());j++){
				file<<r.order[i].pizza_ordered[j].get_pizza_name()<<" "<<r.order[i].pizza_ordered[j].get_pizza_size()<<" "<<r.order[i].get_quantity()<<endl;	
			}
	}
	cout<<"Your order had been removed ..."<<endl;
}
/****************************
* Function Name: search_pizza_by_ingredients
* Paramters: N/A
** Description:This function is mainly asking what ingredients the user want to include in the search.
** Input:N/A
** Output:This function is passing the array in which the ingredients are saved.
****************************/

Menu Menu::search_pizza_by_ingredients_to_include(){
	Menu m = menu();
	string item,s,option,output[m.get_num_pizzas()],total[12];
	int i =1;
	do{
	cout<<"Which item you want to want to include in your search: ";//asking which item they want to add
	cin>>s;
	item = verify(s);
	total[i] = item;
	i++;
	cout<<"Do you want to include other item(yes or no): ";//if they wan to add more or no
	cin>>s;
	option = verify(s);	
	}while(option.compare("yes")==0);
	option_remove(total,i);
}
/****************************
* Function Name: option_remove
* Paramters: string *total.int &i
** Description:This function is searching which pizzas are similar to user search and saving into an array.
** Input:We are passing the array which store what ingredients the user want to include.
** Output: In output, it passes that array to other function where it is cout.
****************************/
	
void option_remove(string *total,int &i){	
	Menu m;
	m.menu();
	bool remover[m.get_num_pizzas() + 1];
	for(int i = 1; i< m.get_num_pizzas() + 1; i++){
		remover[i] = true;
	}
	string x = "";
	int j = 0;
	for(;j<=m.get_num_pizzas();j++){
		x = "";
		for(int y=1;y<m.new_ing[j].size();y++){
			if(m.new_ing[j][y] != ' '){//checking if the character at that point id space or not
				x += m.new_ing[j][y];//if the character is not space
			}	
			else{
				for(int z=1;z<i;z++){//if the charac is space
					if(x == total[z] || (x == " " + total[z])){
						remover[j] = false;
						break;			
					}	
				}
				x = "";	
			}
		}
		for(int z=1;z<i;z++){
			if(x == total[z] || (x == " " + total[z])){	//checking again that we have what the user want to have.
				remover[j] = false;
				break;
			}	
		}
	}
	m.include_ingredients_order(remover);//calling another function
}
/****************************
* Function Name: include_ingredients_order
* Paramters: bool remover[]
** Description:This funtions shows the classified search of the ingredients the user want to see.
** Input:We are passing an array in which it is stored which pizzas needs to be printed.
** Output:In output, it shows the user search.
****************************/

void Menu::include_ingredients_order(bool remover[]){
	Menu m;Restaurant r;
	m.menu();
	int k=1;
	string opt,size,array[50];
	for(int i = 1; i <= m.get_num_pizzas(); i++){
		if(!remover[i]){//shoeing the result which inludes what the user also want.
			cout<< m.pizzas[i].get_name()<<" "<<m.pizzas[i].get_small_cost()<<" "<<m.pizzas[i].get_medium_cost()<<" "<<m.pizzas[i].get_large_cost()<<" "<<m.new_ing[i]<<endl;
			array[k] += m.pizzas[i].get_name();
			k++;	
		}		
	}
	m.order(array);//calling other function
}
/****************************
* Function Name: search_by_ingredients_to_exclude
* Paramters: N/A
** Description:This function is asking the user which items they want to exclude and stores in an array.
** Input: N/A
** Output:This function passes the array of choice of user to other function where it is being cout.
****************************/
	
Menu Menu::search_pizza_by_ingredients_to_exclude(){
	Menu m;
	m.menu();
	string item,option,s,output[m.get_num_pizzas()],total[12];
	int i =1;
	do{
	cout<<"Which item you want to want to exclude in your search: ";//asking whihc item they want to exclude
	cin>>s;
	item = verify(s);
	total[i] = item;
	i++;
	cout<<"Do you want to exclude other item(yes or no): ";//ifthey want to exclude more or not.
	cin>>s;
	option = verify(s);	
	}while(option.compare("yes")==0);
	exclude_option(total,i);
}
/****************************
* Function Name: exclude_option
* Paramters: string *total,int &i
** Description: This function is searching the pizza which matches user needs and stores in another array.
** Input: We passing the array which contains what the user need to include or exclude.
** Output: In output, it gives us the array which tells which pizzas need to be printed.
****************************/
		
void exclude_option(string *total,int &i){
	Menu m;
	m.menu();	
	bool remover[m.get_num_pizzas() + 1];
	string x = "";
	int j = 0;
	for(;j<=m.get_num_pizzas();j++){
		x = "";
		for(int y=1;y<m.new_ing[j].size();y++){
			if(m.new_ing[j][y] != ' '){//checking if the that character in the array is a space or not
				x += m.new_ing[j][y];//if its not space
			}	
			else{
				for(int z=1;z<i;z++){//if its space
					if(x == total[z] || (x == " " + total[z])){
						remover[j] = true;
						break;			
					}	
				}
				x = "";	
			}
		}
		for(int z=1;z<i;z++){
			if(x == total[z] || (x == " " + total[z])){//checking again that we don't have what the user lso do not need.
				remover[j] = true;
				break;
			}	
		}
	}
	m.exclude_ingredients_order(remover);
}
/****************************
* Function Name: exclude_ingredients_order
* Paramters: bool remover[]
** Description: This function basically will show the classified search after the choice what they want to exclude.
** Input: We are passing an array of bool which at each index stores which output is to be shown.
** Output:We get the result of that search in output.
****************************/

void Menu::exclude_ingredients_order(bool remover[]){
	Menu m;
	m.menu();
	int k=1;
	string option = "",array[50];
	for(int i = 1; i <= m.get_num_pizzas(); i++){
		if(!remover[i]){//showing the pizzas that are does not include what the user do not want.
			cout<<m.pizzas[i].get_name()<<" "<<m.pizzas[i].get_small_cost()<<" "<<m.pizzas[i].get_medium_cost()<<" "<<m.pizzas[i].get_large_cost()<<" "<<m.pizzas[i].get_ingredients()<<" "<< m.new_ing[i]<<endl;		
		array[k] = m.pizzas[i].get_name();
		k++;
		}
	}	
	m.order(array);
}	

