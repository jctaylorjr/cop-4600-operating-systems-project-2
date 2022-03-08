#include "dataStructures.h"

unsigned int generateVpn(struct PageTableEntry *pte)
{
	return pte->vpn = (pte->addr & VPN_MASK) >> SHIFT_OFFSET;
}

unsigned int generateOffset(struct PageTableEntry *pte)
{
	return pte->offset = (pte->addr & OFFSET_MASK);
}