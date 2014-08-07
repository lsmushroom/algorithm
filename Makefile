all:str_del str_reverse str_del_char str_left_rotate str_del_chars str_first_char str_print count_1 binary_tree_to_list str_star_mv str_loop_word odd_even_mv top_min_k rotat_str 10_arr_sum 2_max_sum

count_1:count_1.c
	gcc -o $@ $<

str_del:str_del.c
	gcc -o $@ $<

str_reverse:str_reverse.c
	gcc -o $@ $<

str_del_char:str_del_char.c
	gcc -o $@ $<

str_left_rotate:str_left_rotate.c
	gcc -o $@ $<

str_del_chars:str_del_chars.c
	gcc -o $@ $<

str_first_char:str_first_char.c
	gcc -o $@ $<

str_print:str_print.c
	gcc -o $@ $<

binary_tree_to_list:binary_tree_to_list.cpp
	g++ -g -o $@ $<

str_star_mv:str_star_mv.c
	gcc -g -o $@ $<

str_loop_word:str_loop_word.c
	gcc -g -o $@ $<

odd_even_mv:odd_even_mv.c
	gcc -g -o $@ $<

rotat_str:rotat_str.c
	gcc -g -o $@ $<

10_arr_sum:10_arr_sum.c
	gcc -g -o $@ $<

2_max_sum:2_max_sum.c
	gcc -g -o $@ $<

top_min_k:top_min_k.cpp
	g++ -g -o $@ $<

clean:
	rm -f str_del str_reverse str_del_char str_left_rotate str_del_chars str_first_char str_print count_1 binary_tree_to_list str_star_mv str_loop_word odd_even_mv rotat_str 10_arr_sum 2_max_sum
