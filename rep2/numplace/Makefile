CC=gcc
OBJS= numplace_main.o numplace_print.o numplace_refine.o numplace_check.o numplace_matop.o

numplace: $(OBJS)
	$(CC) $(OBJS) -o numplace -Wall -Wextra -lm

clean:
	rm *.o numplace

numplace_main.o: numplace_main.c numplace_print.h numplace_refine.h
numplace_print.o: numplace_print.c
numplace_refine.o: numplace_refine.c numplace_check.h numplace_matop.h
numplace_check.o: numplace_check.c
numplace_matop.o: numplace_matop.c
