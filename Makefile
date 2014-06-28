all:str_del str_reverse

str_del:str_del.c
	gcc -o $@ $<

str_reverse:str_reverse.c
	gcc -o $@ $<

clean:
	rm -f str_del
