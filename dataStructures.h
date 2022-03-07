#ifndef DATA_STRUCTURES_H
#define DATA_STRUCTURES_H

#include <limits.h>

struct PageTableEntry {
	unsigned int vaddr; // virtual address, given
	unsigned int paddr; // physical address, determined in policy
	char wr; // write/read, given
	unsigned int dbit; // dirty bit, determined in policy
};

#endif