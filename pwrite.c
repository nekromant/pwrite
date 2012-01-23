#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/io.h>
#include <sys/types.h>
#include <fcntl.h>

#define BASEPORT 0x80 /* The place POST card should be sitting at */

int main(int argc, char* argv[]) {
	char c;
	int n, tem;
	if (argc<2)
	{
		printf("Set the current POST code\n");
		printf("USAGE: %s code\n", argv[0]);
		printf("Example: %s 0xfa\n", argv[0]);
		printf("This is Free Software, GPLv3 terms apply\n");
		printf("(c) Necromant 2012\n");
		exit(1);
	}
	//set permissions to access port
	sscanf(argv[1], "0x%hhx", &c);
	if (ioperm(BASEPORT, 3, 1)) {perror("ioperm"); exit(1);}
	tem = fcntl(0, F_GETFL, 0);
	fcntl (0, F_SETFL, (tem | O_NDELAY));
	outb(c, BASEPORT);
	printf("POST: 0x%hhx\n", c);
	fcntl(0, F_SETFL, tem);
	//take away permissions to access port
	if (ioperm(BASEPORT, 3, 0)) {perror("ioperm"); exit(1);}
	
	exit(0);
}
