/*
	belle-sip - SIP (RFC3261) library.
    Copyright (C) 2010  Belledonne Communications SARL

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#ifndef belle_sip_resolver_h
#define belle_sip_resolver_h

#include "belle_sip_internal.h"

#define BELLE_SIP_RESOLVER_HINT_IPV6		(1)
#define BELLE_SIP_RESOLVER_HINT_SRV			(1<<1)


typedef struct belle_sip_resolver_context belle_sip_resolver_context_t;

/**
 * Callback prototype for asynchronous DNS resolution. The result addrinfo must be taken and (possibly later) freed by 
 * the callee, using freeaddrinfo().
**/
typedef void (*belle_sip_resolver_callback_t)(void *data, const char *name, struct addrinfo *result);


struct belle_sip_resolver_context{
	belle_sip_source_t source;
	belle_sip_resolver_callback_t cb;
	void *cb_data;
	char *name;
	int port;
	struct addrinfo *ai;
	unsigned int hints;
	pthread_t thread;
	int ctlpipe[2];
	uint8_t cancelled;
	uint8_t exited;
};

struct addrinfo * belle_sip_ip_address_to_addrinfo(const char *ipaddress, int port);
unsigned long belle_sip_resolve(const char *name, int port, unsigned int hints, belle_sip_resolver_callback_t cb , void *data, belle_sip_main_loop_t *ml);

void belle_sip_get_src_addr_for(const struct sockaddr *dest, socklen_t destlen, struct sockaddr *src, socklen_t *srclen);


#endif
