INCLS = -I ./iterators 
USE_STD = -D__FT=0
USE_FT = -D__FT=1
TEST_SEGV = -DTEST_SEGV=1

## Member functions

## Iterators

## Capacity

## Element Access

vector_access_operator_std :
	@clang++ -g $(USE_STD) VectorException.cpp my_tester/vector/access_operator.cpp my_tester/base.cpp && ./a.out 
vector_access_operator_ft :
	@clang++ -g $(USE_FT) VectorException.cpp my_tester/vector/access_operator.cpp my_tester/base.cpp && ./a.out 

vector_at_std :
	@clang++ -g $(USE_STD) VectorException.cpp my_tester/vector/at.cpp my_tester/base.cpp && ./a.out 
vector_at_ft:
	@clang++ -g $(USE_FT) VectorException.cpp my_tester/vector/at.cpp my_tester/base.cpp && ./a.out 

vector_front_std:
	@clang++ -g $(USE_STD) VectorException.cpp my_tester/vector/front.cpp my_tester/base.cpp  && ./a.out 
vector_front_ft:
	@clang++ -g $(USE_FT) VectorException.cpp my_tester/vector/front.cpp my_tester/base.cpp && ./a.out 

vector_back_std:
	@clang++ -g $(USE_STD) VectorException.cpp my_tester/vector/back.cpp my_tester/base.cpp && ./a.out 
vector_back_ft:
	@clang++ -g $(USE_FT) VectorException.cpp my_tester/vector/back.cpp my_tester/base.cpp && ./a.out

## Modifiers
vector_assign_std :
	@clang++ -g $(USE_STD) VectorException.cpp my_tester/vector/assign.cpp my_tester/base.cpp && ./a.out 
vector_assign_ft :
	@clang++ -g $(USE_FT) VectorException.cpp my_tester/vector/assign.cpp my_tester/base.cpp && ./a.out 

vector_push_back_std : 
	@clang++ -g $(USE_STD) VectorException.cpp my_tester/vector/push_back.cpp my_tester/base.cpp && ./a.out 
vector_push_back_ft : 
	@clang++ -g $(USE_FT) VectorException.cpp my_tester/vector/push_back.cpp my_tester/base.cpp && ./a.out 

vector_pop_back_std : 
	@clang++ -g $(USE_STD) VectorException.cpp my_tester/vector/pop_back.cpp my_tester/base.cpp && ./a.out 
vector_pop_back_ft : 
	@clang++ -g $(USE_FT) VectorException.cpp my_tester/vector/pop_back.cpp my_tester/base.cpp && ./a.out 

#vector_insert_std : 
#	@clang++ -g $(USE_STD) VectorException.cpp my_tester/vector/insert.cpp my_tester/base.cpp && ./a.out 
#vector_insert_ft : 
#	@clang++ -g $(USE_FT) VectorException.cpp my_tester/vector/insert.cpp my_tester/base.cpp && ./a.out 

vector_erase_std : 
	@clang++ -g $(USE_STD) VectorException.cpp my_tester/vector/erase.cpp my_tester/base.cpp && ./a.out 
vector_erase_ft : 
	@clang++ -g $(USE_FT) VectorException.cpp my_tester/vector/erase.cpp my_tester/base.cpp && ./a.out 

vector_swap_std : 
	@clang++ -g $(USE_STD) VectorException.cpp my_tester/vector/swap.cpp my_tester/base.cpp && ./a.out 
vector_swap_ft : 
	@clang++ -g $(USE_FT) VectorException.cpp my_tester/vector/swap.cpp my_tester/base.cpp && ./a.out 

vector_clear_std : 
	@clang++ -g $(USE_STD) VectorException.cpp my_tester/vector/clear.cpp my_tester/base.cpp && ./a.out 
vector_clear_ft : 
	@clang++ -g $(USE_FT) VectorException.cpp my_tester/vector/clear.cpp my_tester/base.cpp && ./a.out 

## Allocator

clear :
	clear
