all:str_del str_reverse str_del_char str_left_rotate str_del_chars

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

clean:
	rm -f str_del str_reverse str_del_char str_left_rotate str_del_chars
