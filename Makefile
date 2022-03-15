INCLS = -I ./iterators 

all : clear std ft

std : clear
	@clang++ main.cpp -g TestClass.cpp $(INCLS) -D __FT=0 -o a.out && ./a.out

ft : clear
	@clang++ main.cpp -g TestClass.cpp $(INCLS) -D __FT=1 -o a.out && ./a.out

test :
	clang++ -g VectorException.cpp my_tester/vector/assign.cpp && ./a.out 

clear :
	clear
