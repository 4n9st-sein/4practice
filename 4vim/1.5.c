#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>


int main(void) {
	
	int error = rmdir("foo");
	if(error < 0) {
		perror("rmdir");
		if (errno == ENOTEMPTY) {
			system("ls -l foo");
		}
		exit(1);
	}
}