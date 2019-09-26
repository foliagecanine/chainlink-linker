include make.config

all: 
	make gtk
	ld -r $(OBJ) -o finalgtk.o

gtk: $(OBJ)
	$(CC) $(CFLAGS) -c -o $@ $(GTKFLAGS)
