all: cool_cat cool_echo cool_head cool_wc

cool_cat: cool_cat.c
	gcc -o cool_cat cool_cat.c

cool_echo: cool_echo.c
	gcc -o cool_echo cool_echo.c

cool_head: cool_head.c
	gcc -o cool_head cool_head.c

cool_wc: cool_wc.c
	gcc -o cool_wc cool_wc.c

clean:
	rm -f cool_cat cool_echo cool_head cool_wc
