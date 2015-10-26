INC=-I/usr/include/CUnit/
LIB=-L/usr/lib64/
#gcc -o test -I /usr/include/CUnit/ -L /usr/lib64/ -lcunit *.c
all: cal.c testcal.c test.c
	gcc $^ -o hello $(INC) $(LIB) -lcunit
clean:
	rm -rf hello
