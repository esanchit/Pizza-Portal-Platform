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

/*********************
** Function Name: placing_order
** Paramters:N/A
** Description: This function is mainly asking the general information of sutomer ordeing the pizza.
** Input:User input their name,credit card,phone number.
** Output: In output , this funtion add these all in a string and passes to other function.
*********************/

string placing_order(){
	string name,cc,phone,selection,n,c,p;
	cout<<"Enter the you name: ";//asking the user to enter the name
	cin>>n;
	name = verify(n);
	cout<<"Enter your credit card Number: ";//asking the user to enter the credit carf
	cin>>c;
	cc = verify(c);
	cout<<"Enter your phone Number: ";//asking the user to enter the phone number
	cin>>p;
	phone = verify(p);
	selection = name + " "+ cc +" "+ phone + " ";//adding all those in a string
	return selection;
}
/*********************
** Function Name:output_orders 
** Paramters:string *arr,atring *size,string *quantity,int &count
** Description:This function outputs the order into the orders file.
** Input:We passes all the arrays of the orders to this function.
** Output: It outputs all the orders to the order file.
*********************/

void Restaurant::output_orders(string *arr,string *size,string *quantity,int &count){
	Restaurant r = view_hours();
	r = orders();
	int k=1;
	string s_tmp = placing_order();
	ofstream file_out;
	file_out.open("orders.txt");
	for(int i = 1;i <= r.get_lines();i++){//outputng theorder tothe file.
		file_out<<r.order[i].get_order_num()<<" "<<r.order[i].get_name()<<" "<<r.order[i].get_customer_phone()<<" ";
		for(int y=1;y<=(r.order[i].get_count());y++){
			file_out<<r.order[i].pizza_ordered[y].get_pizza_name()<<" "<<r.order[i].pizza_ordered[y].get_pizza_size()<<" ";
			file_out<<r.order[i].pizza_ordered[y].get_quantity()<<endl;	
		}
		if(i == r.get_lines()){
			k = r.get_lines();	
		}
	}	
	k++;
	file_out<<k<<" "<<s_tmp;
	for(int i =0;i<count;i++){
		file_out<<arr[i]<<" "<<size[i]<<" "<<quantity[i]<<" ";	
	}
	file_out<<endl;
	cout<<"Your order number is: "<<k<<endl;
}
/*********************
** Function Name: set_pizza_cost_result
** Paramters:int max
** Description:This function gets the pizzas that are less the max the user can spent on the pizza.
** Input:We passes the max thatthe user enters for the pizza.
** Output: pass that sorted array into other funtion where it is couted.
*********************/


void Menu::set_pizza_cost_result(int max){
	int k=1,j=1;
	Menu s_tmp = menu();
	string* array= new string[20];
	string array_1[20];
	cout<<s_tmp.get_num_pizzas()<<endl;
	for(int i=1;i<=(s_tmp.get_num_pizzas()+1);i++){
		if(s_tmp.pizzas[i].get_small_cost() > max){
			s_tmp.pizzas[i].set_small_cost(-1); 		//checking the small cost is less than max or greater than max
		}
		if(s_tmp.pizzas[i].get_medium_cost() >max){
			s_tmp.pizzas[i].set_medium_cost(-1);	//checking the medium cost id leass than or greater than max
		}		
		if(s_tmp.pizzas[i].get_large_cost() >max){
			s_tmp.pizzas[i].set_large_cost(-1);	//checking the large cost
		}
	}
	for(int i=1;i<=(s_tmp.get_num_pizzas()+1);i++){
		if(s_tmp.pizzas[i].get_small_cost() > 0){//if the small cost is less tahn max
			cout<<k<<". "<<"Small: "<<s_tmp.pizzas[i].get_name()<<". Price: $ "<<s_tmp.pizzas[i].get_small_cost()<<" "<<s_tmp.new_ing[i]<<endl;
			array[k] = s_tmp.pizzas[i].get_name();
			k++;
		}
	}
	cout<<endl;
	for(int i=1;i<=(s_tmp.get_num_pizzas()+1);i++){	//if the medium cost is less than max
		if(s_tmp.pizzas[i].get_medium_cost() > 0){
			cout<<k<<". "<<"Medium : "<<s_tmp.pizzas[i].get_name()<<".Price: $ "<<s_tmp.pizzas[i].get_medium_cost()<<" "<<s_tmp.new_ing[i]<<endl;
			array[k] = s_tmp.pizzas[i].get_name();
			k++;
		}			
	}
	cout<<endl;
	for(int i =1;i<=(s_tmp.get_num_pizzas()+1);i++){	//if the large cost is less than max
		if(s_tmp.pizzas[i].get_large_cost() > 0){
			cout<<k<<" "<<"Large:"<<s_tmp.pizzas[i].get_name()<<". Price: $ "<<s_tmp.pizzas[i].get_large_cost()<<" "<<s_tmp.new_ing[i]<<endl;
			array[k] = s_tmp.pizzas[i].get_name();	
			k++;
		}
	}
	order_after_cost(array);		
}
/*********************
** Function Name: single_order
** Paramters:N/A
** Description:This function lets the user palce an order.
** Input:We get all the details of the pizza the user want to place order.
** Output: Output that into the orders file.
*********************/


void Menu::single_order(){
	Restaurant r;Menu m;
	int x=0,a=0,count =0,k=1,value=2,array_order[20];
	string option,array[20],size[20],quantity[20],q,s,o;
	Menu s_tmp = m.menu();
	cout<<"Do you want to look over the menu to place order(yes or no): ";//asking if they want to look over menu
	cin>>option;
	if(option == "yes"){
		m.view_menu();
	}	
	do{
	cout<<"Enter the the number (index) of the Pizza you want to eat: ";//asking the user to enterthe index of that pizza.
	cin>>a;
	x = verify_i(a);
	for(int i =1;i<=s_tmp.get_num_pizzas();i++){
			if(i == x){
				array_order[k] = value;
				cout<<"What size of "<<s_tmp.pizzas[i].get_name()<<"you want to order: ";//asking the sixe of the pizza
				cin>>q;
				quantity[k] = verify(q);	
				cout<<"How many of "<<s_tmp.pizzas[i].get_name()<<"you want: ";//asking thw quantity ofthe pizza
				cin>>s;
				size[k] = verify(s);
				array[k] = s_tmp.pizzas[i].get_name();
				k++,value++;
			}
		}
		cout<<"Do you want to add any other pizza in your order(yes or no): ";//if they want ot add more.
		cin>>o;
		option = verify(o);
		count++;
	}while(option =="yes");
	r.place_order1(array_order,array,size,quantity,count);
}	
/*********************
** Function Name: place_order1
** Paramters:int *array,string *array,string *size,string *quantity,int &count
** Description:This function outputs the orders into order file.
** Input:We passes the array in which the orders are there.
** Output: Outputs the orders into the order file.
*********************/


void Restaurant::place_order1(int *array_order,string *array,string *size,string *quantity,int &count){	
	int k=1;
	string s = placing_order();
	Restaurant r = view_hours();
	r = orders();
	ofstream file;
	file.open("orders.txt");
	for(int i=1;i<= r.get_lines();i++){//outputing teh order to teh given file.
		file<<r.order[i].get_order_num()<<" "<<r.order[i].get_name()<<" "<<r.order[i].get_customer_cc()<<" ";
		file<<r.order[i].get_customer_phone()<<" ";
		for(int y=1;y<=(r.order[i].get_count());y++){
			file<<r.order[i].pizza_ordered[y].get_pizza_name()<<" "<<r.order[i].pizza_ordered[y].get_pizza_size()<<" ";
			file<<r.order[i].pizza_ordered[y].get_quantity()<<endl;	
		}
		if(i==r.get_lines()){
			k = r.order[i].get_order_num();	
		}	
	}
	k++;
	file<< k<<" ";
	file<< s;
	for(int i=1;i<=count;i++){
		file<<array[i]<<" "<<size[i]<<" "<<quantity[i]<<" ";

	}
	file<<endl;
	cout<<"Your order number is : "<<k<<endl;
}
/*********************
** Function Name: order_after_cost
** Paramters:strng *array
** Description:This function ask the user some questions for palacing order after the pizza by cost search.
** Input:We passes the string which includes the pizza after the search.
** Output: output the order placed by the user.
*********************/
void order_after_cost(string *array){
	Restaurant re;
	string selection;
	string tmp;
	string array_1[10],size[10];
	int a,b[10],c=1,i=1,count=0;
	do{
		cout<<"Which pizza from the above result you like to order(enter the number): ";//asking the pizza theywant to order	
		cin>>a;
		cout<<array[a]<<endl;
		cout<<"How many of "<<array[a]<<" you need to order: ";//how many they need
		array_1[i] = array[a];
		cin>>b[i];
		cout<<"what is the size of you want ";cin>>size[i];
		i++,count++;
		cout<<"If you want to order more enter 1 , to cancel enter 0 or if you want to checkout just press enter: ";//
		getchar();
		selection = cin.get();
		if(selection =="\n"){
			cout<<"You selected to checkout.Provide with some details"<<endl;
			re.place_order4(array_1,size,b,count);
			break;
		}
		else if (selection =="1"){//if the selection is 1.
			re.place_order4(array_1,size,b,count);
			continue;
		}
		else if (selection == "0"){
			cout<<"YOur order has been cancelled, Thank You a nice day!!!"<<endl;//if the user entered zero
			break;
		}
	}while(c==1);
}
	
/*********************
** Function Name: place_order4
** Paramters:int *array,string *array,string *size,string *quantity,int &count
** Description:This function outputs the orders into order file.
** Input:We passes the array in which the orders are there.
** Output: Outputs the orders into the order file.
*********************/

void Restaurant::place_order4(string *array,string *size,int *quantity,int &count){	
	int k=1;
	string s = placing_order();
	Restaurant r = view_hours();
	r = orders();
	ofstream file;
	file.open("orders.txt");
	for(int i=1;i<= r.get_lines();i++){//outputing teh order to teh given file.
		file<<r.order[i].get_order_num()<<" "<<r.order[i].get_name()<<" "<<r.order[i].get_customer_cc()<<" ";
		file<<r.order[i].get_customer_phone()<<" ";
		for(int y=1;y<=(r.order[i].get_count());y++){
			file<<r.order[i].pizza_ordered[y].get_pizza_name()<<" "<<r.order[i].pizza_ordered[y].get_pizza_size()<<" ";
			file<<r.order[i].pizza_ordered[y].get_quantity()<<endl;	
		}
		if(i==r.get_lines()){
			if(i==1){
				k=0;	
			}
			k = r.order[i].get_order_num();	
		}	
	}
	k++;
	file<< k<<" ";
	file<< s;
	for(int i=1;i<=count;i++){
		file<<array[i]<<" "<<size[i]<<" "<<quantity[i]<<" ";

	}
	file<<endl;
	cout<<"Your order number is : "<<k<<endl;
}

