CC=gcc
OBJS= bignum_main.o bignum_funcs.o

bignum: $(OBJS)
	$(CC) $(OBJS) -o bignum -Wall -Wextra -lm

clean:
	rm *.o bignum

bignum_main.o: bignum_main.c bignum_funcs.h
bignum_funcs.o: bignum_funcs.c
