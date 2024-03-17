CC = gcc
CFLAGS = -pedantic -g
OBJ = list.o test.o
EXEC = test.out

$(EXEC) : $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

test.o : test.c test.h list.h
	$(CC) -c test.c $(CFLAGS)

list.o : list.c list.h
	$(CC) -c list.c $(CFLAGS)

clean :
	rm $(OBJ) $(EXEC)

run : $(EXEC)
	./$(EXEC)