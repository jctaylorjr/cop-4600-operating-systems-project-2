#ifndef DATA_STRUCTURES_H
#define DATA_STRUCTURES_H

#include <limits.h>
#include <stdbool.h>

#define SHIFT_OFFSET 12

struct Buffer {
	const char *trace_file, *policy, *debug_mode;
	int nframes, memory_percent;

	int trace_count, read_count, write_count, buffer_size;

	struct PageTableEntry *buffer;
};

struct PageTableEntry {
	unsigned int addr; // virtual address, given
	char rw; // write/read, given
	unsigned int vpn; // (VirtualAddress & VPN_MASK) >> SHIFT
};

unsigned int generateVpn(struct PageTableEntry *pte);
bool isPteInBuffer(struct PageTableEntry *pte, struct Buffer *buf);
void addDirtyBit(struct PageTableEntry *pte, struct Buffer *buf);
void addPte(struct PageTableEntry *pte, struct Buffer *buf);

#endif