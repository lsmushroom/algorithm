all:str_del

str_del:str_del.c
	gcc -o $@ $<

clean:
	rm -f str_del
