INCLS = -I ./iterators 
USE_STD = -D__FT=0
USE_FT = -D__FT=1
TEST_SEGV = -DTEST_SEGV=1

## Member functions
vector_default_constructor_std :
	@clang++ -g $(USE_STD) VectorException.cpp my_tester/vector/default_constructor.cpp my_tester/base.cpp && ./a.out 
vector_default_constructor_ft :
	@clang++ -g $(USE_FT) VectorException.cpp my_tester/vector/default_constructor.cpp my_tester/base.cpp && ./a.out 

vector_fill_constructor_std :
	@clang++ -g $(USE_STD) VectorException.cpp my_tester/vector/fill_constructor.cpp my_tester/base.cpp && ./a.out 
vector_fill_constructor_ft :
	@clang++ -g $(USE_FT) VectorException.cpp my_tester/vector/fill_constructor.cpp my_tester/base.cpp && ./a.out 

vector_range_constructor_std :
	@clang++ -g $(USE_STD) VectorException.cpp my_tester/vector/range_constructor.cpp my_tester/base.cpp && ./a.out 
vector_range_constructor_ft :
	@clang++ -g $(USE_FT) VectorException.cpp my_tester/vector/range_constructor.cpp my_tester/base.cpp && ./a.out 

vector_copy_constructor_std :
	@clang++ -g $(USE_STD) VectorException.cpp my_tester/vector/copy_constructor.cpp my_tester/base.cpp && ./a.out 
vector_copy_constructor_ft :
	@clang++ -g $(USE_FT) VectorException.cpp my_tester/vector/copy_constructor.cpp my_tester/base.cpp && ./a.out 

#vector_destructor_std :
#	@clang++ -g $(USE_STD) VectorException.cpp my_tester/vector/destructor.cpp my_tester/base.cpp && ./a.out 
#vector_destructor_ft :
#	@clang++ -g $(USE_FT) VectorException.cpp my_tester/vector/destructor.cpp my_tester/base.cpp && ./a.out 

vector_equal_operator_std :
	@clang++ -g $(USE_STD) VectorException.cpp my_tester/vector/equal_operator.cpp my_tester/base.cpp && ./a.out 
vector_equal_operator_ft :
	@clang++ -g $(USE_FT) VectorException.cpp my_tester/vector/equal_operator.cpp my_tester/base.cpp && ./a.out 

## Iterators
vector_begin_std :
	@clang++ -g $(USE_STD) VectorException.cpp my_tester/vector/begin.cpp my_tester/base.cpp && ./a.out 
vector_begin_ft :
	@clang++ -g $(USE_FT) VectorException.cpp my_tester/vector/begin.cpp my_tester/base.cpp && ./a.out 

vector_end_std :
	@clang++ -g $(USE_STD) VectorException.cpp my_tester/vector/end.cpp my_tester/base.cpp && ./a.out 
vector_end_ft :
	@clang++ -g $(USE_FT) VectorException.cpp my_tester/vector/end.cpp my_tester/base.cpp && ./a.out 

vector_rbegin_std :
	@clang++ -g $(USE_STD) VectorException.cpp my_tester/vector/rbegin.cpp my_tester/base.cpp && ./a.out 
vector_rbegin_ft :
	@clang++ -g $(USE_FT) VectorException.cpp my_tester/vector/rbegin.cpp my_tester/base.cpp && ./a.out 

vector_rend_std :
	@clang++ -g $(USE_STD) VectorException.cpp my_tester/vector/rend.cpp my_tester/base.cpp && ./a.out 
vector_rend_ft :
	@clang++ -g $(USE_FT) VectorException.cpp my_tester/vector/rend.cpp my_tester/base.cpp && ./a.out 

## Capacity
vector_size_std :
	@clang++ -g $(USE_STD) VectorException.cpp my_tester/vector/size.cpp my_tester/base.cpp && ./a.out 
vector_size_ft :
	@clang++ -g $(USE_FT) VectorException.cpp my_tester/vector/size.cpp my_tester/base.cpp && ./a.out 

vector_max_size_std :
	@clang++ -g $(USE_STD) VectorException.cpp my_tester/vector/max_size.cpp my_tester/base.cpp && ./a.out 
vector_max_size_ft :
	@clang++ -g $(USE_FT) VectorException.cpp my_tester/vector/max_size.cpp my_tester/base.cpp && ./a.out 

#vector_resize_std :
#	@clang++ -g $(USE_STD) VectorException.cpp my_tester/vector/resize.cpp my_tester/base.cpp && ./a.out 
#vector_resize_ft :
#	@clang++ -g $(USE_FT) VectorException.cpp my_tester/vector/resize.cpp my_tester/base.cpp && ./a.out 

vector_capacity_std :
	@clang++ -g $(USE_STD) VectorException.cpp my_tester/vector/capacity.cpp my_tester/base.cpp && ./a.out 
vector_capacity_ft :
	@clang++ -g $(USE_FT) VectorException.cpp my_tester/vector/capacity.cpp my_tester/base.cpp && ./a.out 

vector_empty_std :
	@clang++ -g $(USE_STD) VectorException.cpp my_tester/vector/empty.cpp my_tester/base.cpp && ./a.out 
vector_empty_ft :
	@clang++ -g $(USE_FT) VectorException.cpp my_tester/vector/empty.cpp my_tester/base.cpp && ./a.out 

vector_reserve_std :
	@clang++ -g $(USE_STD) VectorException.cpp my_tester/vector/reserve.cpp my_tester/base.cpp && ./a.out 
vector_reserve_ft :
	@clang++ -g $(USE_FT) VectorException.cpp my_tester/vector/reserve.cpp my_tester/base.cpp && ./a.out 

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
#vector_get_allocator_std : 
#	@clang++ -g $(USE_STD) VectorException.cpp my_tester/vector/get_allocator.cpp my_tester/base.cpp && ./a.out 
#vector_get_allocator_ft : 
#	@clang++ -g $(USE_FT) VectorException.cpp my_tester/vector/get_allocator.cpp my_tester/base.cpp && ./a.out 

# Non-member function overloads
vector_is_equal_std : 
	@clang++ -g $(USE_STD) VectorException.cpp my_tester/vector/is_equal.cpp my_tester/base.cpp && ./a.out 
vector_is_equal_ft : 
	@clang++ -g $(USE_FT) VectorException.cpp my_tester/vector/is_equal.cpp my_tester/base.cpp && ./a.out 

vector_is_not_equal_std : 
	@clang++ -g $(USE_STD) VectorException.cpp my_tester/vector/is_not_equal.cpp my_tester/base.cpp && ./a.out 
vector_is_not_equal_ft : 
	@clang++ -g $(USE_FT) VectorException.cpp my_tester/vector/is_not_equal.cpp my_tester/base.cpp && ./a.out 

vector_is_less_std : 
	@clang++ -g $(USE_STD) VectorException.cpp my_tester/vector/is_less.cpp my_tester/base.cpp && ./a.out 
vector_is_less_ft : 
	@clang++ -g $(USE_FT) VectorException.cpp my_tester/vector/is_less.cpp my_tester/base.cpp && ./a.out 

vector_is_less_or_equal_std : 
	@clang++ -g $(USE_STD) VectorException.cpp my_tester/vector/is_less_or_equal.cpp my_tester/base.cpp && ./a.out 
vector_is_less_or_equal_ft : 
	@clang++ -g $(USE_FT) VectorException.cpp my_tester/vector/is_less_or_equal.cpp my_tester/base.cpp && ./a.out 

vector_is_greater_std : 
	@clang++ -g $(USE_STD) VectorException.cpp my_tester/vector/is_greater.cpp my_tester/base.cpp && ./a.out 
vector_is_greater_ft : 
	@clang++ -g $(USE_FT) VectorException.cpp my_tester/vector/is_greater.cpp my_tester/base.cpp && ./a.out 

vector_is_greater_or_equal_std : 
	@clang++ -g $(USE_STD) VectorException.cpp my_tester/vector/is_greater_or_equal.cpp my_tester/base.cpp && ./a.out 
vector_is_greater_or_equal_ft : 
	@clang++ -g $(USE_FT) VectorException.cpp my_tester/vector/is_greater_or_equal.cpp my_tester/base.cpp && ./a.out 

#vector_swap_overload_std : 
#	@clang++ -g $(USE_STD) VectorException.cpp my_tester/vector/swap_overload.cpp my_tester/base.cpp && ./a.out 
#vector_swap_overload_ft : 
#	@clang++ -g $(USE_FT) VectorException.cpp my_tester/vector/swap_overload.cpp my_tester/base.cpp && ./a.out 

clear :
	clear
