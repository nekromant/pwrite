CC?=gcc
INSTALL?=install
DESTDIR?=/usr/local/bin
all: pwrite 

pwrite: pwrite.c
	$(CC) pwrite.c -o pwrite
	
install: pwrite
	$(INSTALL) pwrite -D $(DESTDIR)/pwrite
clean:
	rm -f pwrite	
	
