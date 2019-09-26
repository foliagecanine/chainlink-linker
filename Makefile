include make.config
export CC

.SILENT: all clean

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $< $(GTKFLAGS) 

all:
	make clean
	$(MAKE) -C main
	$(MAKE) -C libs
	$(MAKE) -C gtk
	echo Compiling final object
	make chainlink

chainlink: main/main.o
	$(CC) $(CFLAGS) -o chainlink main/finalmain.o libs/finallibs.o gtk/finalgtk.o $(GTKFLAGS)

.PHONY: clean install install-desktop uninstall

clean:
	find . -name "*.o" -type f -delete
	rm -f chainlink

install-desktop:
	make install
	cp desktop/chainlink.de desktop/chainlink.desktop
	echo Exec=$(INSTALLDIR)/bin/chainlink >> desktop/chainlink.desktop
	echo Icon=$(INSTALLDIR)/share/chainlink/res/chainlink.png >> desktop/chainlink.desktop
	mv desktop/chainlink.desktop $(INSTALLDIR)/share/applications/chainlink.desktop

install:
	$(INSTALL) -m 0755 chainlink $(INSTALLDIR)/bin
	$(INSTALL) -d $(INSTALLDIR)/share/chainlink/res
	$(INSTALL) -m 0644 res/* $(INSTALLDIR)/share/chainlink/res

uninstall-desktop:
	make uninstall
	$(UNINSTALL) $(INSTALLDIR)/share/applications/chainlink.desktop

uninstall:
	$(UNINSTALL) $(INSTALLDIR)/bin/chainlink
	$(UNINSTALL) $(INSTALLDIR)/share/chainlink
