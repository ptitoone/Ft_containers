all : clear std ft

std : clear
	@clang++ main.cpp TestClass.cpp -D __FT=0 -o a.out && ./a.out

ft : clear
	@clang++ main.cpp TestClass.cpp -D __FT=1 -o a.out && ./a.out

clear :
	clear