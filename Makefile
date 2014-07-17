all:str_del str_reverse str_del_char str_left_rotate str_del_chars str_first_char str_print count_1 binary_tree_to_list str_star_mv str_loop_word odd_even_mv

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

clean:
	rm -f str_del str_reverse str_del_char str_left_rotate str_del_chars str_first_char str_print count_1 binary_tree_to_list str_star_mv str_loop_word odd_even_mv
