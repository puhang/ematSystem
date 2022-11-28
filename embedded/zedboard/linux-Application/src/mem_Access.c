#include "mem_Access.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <stddef.h>

int Mem_Write(unsigned int base,unsigned int offset,unsigned int value){
	int fd = open("/dev/mem", O_RDWR|O_SYNC);
	int *virAddr;
	virAddr = (int*)mmap(NULL, MMAP_SIZE, PROT_READ|PROT_WRITE|PROT_EXEC, MAP_SHARED|MAP_LOCKED, fd, base);
	*((int *)((char *)virAddr+offset)) = value;
	munmap(virAddr,MMAP_SIZE);
	close(fd);
	return 0;
}
