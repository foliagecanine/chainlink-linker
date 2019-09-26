include make.config

all: 
	make main
	ld -r $(OBJ) -o finalmain.o

main: $(OBJ)
	$(CC) $(CFLAGS) -c -o $@ $(GTKFLAGS)
