CC?=gcc
INSTALL?=install

all: pwrite 

pwrite: pwrite.c
	$(CC) pwrite.c -o pwrite
	
install: pwrite
	$(INSTALL) pwrite -D /usr/bin/pwrite
	
	
