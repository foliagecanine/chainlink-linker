include make.config

all: 
	make libs
	ld -r $(OBJ) -o finallibs.o

libs: $(OBJ)
	$(CC) $(CFLAGS) -c -o $@ $(GTKFLAGS)
