INCLS = -I ./iterators 
USE_STD = -D__FT=0
USE_FT = -D__FT=1

all : clear std ft

std : clear
	@clang++ main.cpp -g TestClass.cpp $(INCLS) -D __FT=0 -o a.out && ./a.out

ft : clear
	@clang++ main.cpp -g TestClass.cpp $(INCLS) -D __FT=1 -o a.out && ./a.out

vector_assign_std :
	@clang++ -g $(USE_STD) VectorException.cpp my_tester/vector/assign.cpp my_tester/base.cpp && ./a.out 

vector_assign_ft :
	@clang++ -g $(USE_FT) VectorException.cpp my_tester/vector/assign.cpp my_tester/base.cpp && ./a.out 

vector_push_back_std : 
	@clang++ -g $(USE_STD) VectorException.cpp my_tester/vector/push_back.cpp my_tester/base.cpp && ./a.out 

vector_push_back_ft : 
	@clang++ -g $(USE_FT) VectorException.cpp my_tester/vector/push_back.cpp my_tester/base.cpp && ./a.out 

clear :
	clear
