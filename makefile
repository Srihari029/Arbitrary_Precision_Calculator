OBJ=$(patsubst %.c,%.o,$(wildcard *.c))
apc.out : $(OBJ)
	gcc -o $@ $^
clean :
	rm *.o *.out

