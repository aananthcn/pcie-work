#ifndef PCI_TYPES_DOT_H
#define PCI_TYPES_DOT_H

// Macros
#define PWR_MGMT_CAPABILITY_ID	0x01


// types

typedef struct {
	unsigned short vendor_id;
	unsigned short device_id;
	char device_str[256];
	char device_type[128];
	unsigned short cmd_reg;
	unsigned short stat_reg;
	unsigned char  rev_id;
	unsigned int   class_code;
	unsigned char  cache_line;
	unsigned char  lat_timer;
	unsigned char  hdr_type; /* bits[6:0] decides if type-0 or type-1*/
	unsigned char  bist;
	unsigned char  cap_ptr;
	unsigned char  irq_line;
	unsigned char  irq_pin;
} pci_cfg_common_t;


typedef struct {
	pci_cfg_common_t cmn;
	unsigned int   bar0;
	unsigned int   bar1;
	unsigned int   bar2;
	unsigned int   bar3;
	unsigned int   bar4;
	unsigned int   bar5;
	unsigned int   card_bus_p;
	unsigned short subsys_vid;
	unsigned short subsys_did;
	unsigned int   exp_rom_ba;
} pci_cfg_type0_t;


typedef struct {
	pci_cfg_common_t cmn;
	unsigned int   bar0;
	unsigned int   bar1;
	unsigned char  pri_bus_n;
	unsigned char  sec_bus_n;
	unsigned char  sbo_bus_n;
	unsigned char  sec_lat_tm;
	unsigned char  io_base;
	unsigned char  io_limit;
	unsigned char  sec_status;
	unsigned short mem_base;
	unsigned short mem_limit;
	unsigned short pf_mem_base;
	unsigned short pf_mem_limit;
	unsigned int   pf_base_u32;
	unsigned int   pf_limit_u32;
	unsigned short io_base_u16;
	unsigned short io_limit_u16;
	unsigned int   exp_rom_ba;
	unsigned short bridge_ctrl;
} pci_cfg_type1_t;


typedef struct {
	pci_cfg_common_t cmn;
	union {
		pci_cfg_type0_t t0;
		pci_cfg_type1_t t1;
	} u;
} pci_cfg_t;


typedef struct {
	unsigned short pmc;
	unsigned short pmcsr;
	unsigned short data;
} pci_pmr_mgmt_cap_t;


typedef struct {
	unsigned short cap_id;
	unsigned char cap_ver;
	unsigned short next_cap_ptr;
} pci_ext_cap_t;


#endif