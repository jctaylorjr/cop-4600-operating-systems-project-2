#include "dataStructures.h"
#include "error_check.h"
#include <stdbool.h>

unsigned int generateVpn(struct PageTableEntry *pte)
{
	return pte->vpn = pte->addr >> SHIFT_OFFSET;
}

bool isPteInBuffer(struct PageTableEntry *pte, struct Buffer *buf)
{
	for (int i = 0; i < buf->buffer_size; i++) {
		if (pte->vpn == buf[i].buffer->vpn) {
			return true;
		}
	}
	return false;
}

// Changing R to W when new pte is W simulates dirty bit
void addDirtyBit(struct PageTableEntry *pte, struct Buffer *buf)
{
	for (int i = 0; i < buf->buffer_size; i++) {
		if (pte->vpn == buf[i].buffer->vpn && pte->rw == 'W' &&
		    buf[i].buffer->rw == 'R') {
			buf[i].buffer->rw = 'W';
		}
	}
}

void addPte(struct PageTableEntry *pte, struct Buffer *buf)
{
	if (buf->buffer_size >= buf->nframes) {
		if (buf->buffer[0].rw == 'W') {
			buf->write_count++;
		}
		buf->buffer[0]
	}
}