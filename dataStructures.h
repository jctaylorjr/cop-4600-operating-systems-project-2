#ifndef DATA_STRUCTURES_H
#define DATA_STRUCTURES_H

#include <limits.h>

#define PAGETABLE_SIZE (UINT_MAX >> 12)
#define TBL_SIZE (UINT_MAX >> 20)
#define VPN_MASK (UINT_MAX << 12) // highest 20 bits
#define OFFSET_MASK (UINT_MAX >> 20) // lowest 12 bits
#define SHIFT_OFFSET 12

struct PageTableEntry {
	unsigned int addr; // virtual address, given
	char rw; // write/read, given
	unsigned int vpn; // (VirtualAddress & VPN_MASK) >> SHIFT
	unsigned int offset; // VirtualAddress & OFFSET_MASK
	unsigned int pte_addr; // PageTableBaseRegister + (VPN * sizeof(PTE))
	unsigned int phys_addr; // (PFN << SHIFT) | offset
	unsigned int vbit; // valid bit
	unsigned int dbit; // dirty bit
	unsigned int pbit; // present bit
	unsigned int rbit; // reference bit
};

struct PageTableEntry PageTable[PAGETABLE_SIZE]; // 2^20 total entries

unsigned int generateVpn(struct PageTableEntry *pte);
unsigned int generateOffset(struct PageTableEntry *pte);

#endif