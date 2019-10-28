CC = g++ -std=c++11
exe_file = play_game

$(exe_file): driver.o pizza_portal.o private_acc.o pizza_portal_1.o pizza_order.o pizza_restaurant.o
	$(CC)  driver.o pizza_portal.o private_acc.o pizza_portal_1.o pizza_order.o pizza_restaurant.o -o $(exe_file)  
driver.o: driver.cpp
	$(CC) -c driver.cpp 
pizza_portal.o: pizza_portal.cpp
	$(CC) -c pizza_portal.cpp
private_cc.o: private_acc.cpp
	$(CC) -c private_acc.cpp	
pizza_portal_1: pizza_portal_1.cpp
	$(CC): -c pizza_portal_1.cpp
pizza_order: pizza_order.cpp
	$(CC): -c pizza_order.cpp	
pizza_restaurant: pizza_restaurant.cpp
	$(CC): -c pizza_restaurant.cpp	
clean:
	rm -f *.out *.o $(exe_file)

			
