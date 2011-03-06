#  this makefile creates 2 executables   -- add  and sub
#  both add.cc and sub.cc include long.h
#  both executabes depend on long.o 
#  none of these classes are template classes

all: testCircular testCustomer videoList.o videoType.o customerList.o

###########################################################
testCircular: testCircular.o
	g++ testCircular.o -o testCircular

testCircular.o: testCircular.cpp circularList.h
	g++ -c testCircular.cpp

###########################################################

testCustomer: testCustomer.o personType.o customer.o
	g++ -o testCustomer -g testCustomer.o personType.o customer.o

testCustomer.o: customer.h circularList.h personType.h testCustomer.cpp
	g++ -g -c testCustomer.cpp

personType.o: personType.h personType.cpp
	g++ -g -c personType.cpp

customer.o: customer.h customer.cpp
	g++ -g -c customer.cpp
###########################################################
#testOrdCList: testOrdCList.o
#	g++ testOrdCList.o -o testOrdCList

#testOrdCList.o: orderedCircularList.h testOrdCList.cpp
#	g++ -g -c testOrdCList.cpp

###########################################################

videoList.o: videoList.h videoList.cpp
	g++ -g -c videoList.cpp

videoType.o: videoType.h videoTypeImp.cpp
	g++ -g -c videoTypeImp.cpp

customerList.o: customerList.h customerList.cpp
	g++ -g -c customerList.cpp

clean: 
	rm *.o testCircular testCustomer personType circularList testOrdCList videoList videoType customerList
