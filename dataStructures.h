#ifndef DATA_STRUCTURES_H
#define DATA_STRUCTURES_H

#include <limits.h>

#define PAGETABLE_SIZE (UINT_MAX >> 12)
#define TBL_SIZE (UINT_MAX >> 20)

struct PageTableEntry {
	unsigned int vaddr; // virtual address, given
	unsigned int paddr; // physical address, determined in policy
	char wr; // write/read, given
	unsigned int dbit; // dirty bit, determined in policy
};

#endif