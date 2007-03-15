/*
 * xen_internal.h: internal API for direct access to Xen hypervisor level
 *
 * Copyright (C) 2005 Red Hat, Inc.
 *
 * See COPYING.LIB for the License of this software
 *
 * Daniel Veillard <veillard@redhat.com>
 */

#ifndef __VIR_XEN_INTERNAL_H__
#define __VIR_XEN_INTERNAL_H__

#ifdef __cplusplus
extern "C" {
#endif

void	xenHypervisorRegister		(void);
int	xenHypervisorOpen		(virConnectPtr conn,
					 const char *name,
					 int flags);
int	xenHypervisorClose		(virConnectPtr conn);
int	xenHypervisorGetVersion		(virConnectPtr conn,
				 	 unsigned long *hvVer);
unsigned long
        xenHypervisorGetDomMaxMemory	(virConnectPtr conn,
					 int id);
int	xenHypervisorNumOfDomains	(virConnectPtr conn);
int	xenHypervisorListDomains	(virConnectPtr conn,
					 int *ids,
					 int maxids);
int	xenHypervisorNumOfMaxVcpus	(virConnectPtr conn);
int	xenHypervisorDestroyDomain	(virDomainPtr domain);
int	xenHypervisorResumeDomain	(virDomainPtr domain);
int	xenHypervisorPauseDomain	(virDomainPtr domain);
int	xenHypervisorGetDomainInfo	(virDomainPtr domain,
				   	 virDomainInfoPtr info);
int	xenHypervisorGetDomInfo		(virConnectPtr conn,
					 int id,
					 virDomainInfoPtr info);
int	xenHypervisorSetMaxMemory	(virDomainPtr domain,
		      		  	 unsigned long memory);
int	xenHypervisorCheckID		(virConnectPtr conn,
					 int id);
int	xenHypervisorSetVcpus		(virDomainPtr domain,
					 unsigned int nvcpus);
int	xenHypervisorPinVcpu		(virDomainPtr domain,
					 unsigned int vcpu,
					 unsigned char *cpumap,
					 int maplen);
int	xenHypervisorGetVcpus		(virDomainPtr domain,
					 virVcpuInfoPtr info,
					 int maxinfo,
					 unsigned char *cpumaps,
					 int maplen);
int	xenHypervisorGetVcpuMax		(virDomainPtr domain);

#ifdef __cplusplus
}
#endif
#endif                          /* __VIR_XEN_INTERNAL_H__ */
