MODULE_NAME = wilc1000


obj-$(CONFIG_WILC1000) += $(MODULE_NAME).o
obj-$(CONFIG_WILC1000_PREALLOCATE_DURING_SYSTEM_BOOT) += wilc_exported_buf.o

EXTRA_CFLAGS += -DEXPORT_SYMTAB
EXTRA_CFLAGS += -D__CHECK_ENDIAN__


DEBFLAGS = -O -g


ifeq ($(strip $(CONFIG_WILC1000_SDIO)),y)
	EXTRA_CFLAGS += -DWILC_SDIO
	EXTRA_CFLAGS += -DWILC_OPTIMIZE_SLEEP_INT
	$(MODULE_NAME)-objs += driver/linux/source/linux_wlan_sdio.o

	ifeq ($(strip $(CONFIG_WILC1000_HW_OOB_INTR)),y)
		EXTRA_CFLAGS += -DWILC_SDIO_IRQ_GPIO
	endif
else
	EXTRA_CFLAGS += -DWILC_SPI
	$(MODULE_NAME)-objs += driver/linux/source/linux_wlan_spi.o
endif

#------------------------------------------------------------------------------
#[[ version 9.0
EXTRA_CFLAGS += -DNMC_ASIC_A0
EXTRA_CFLAGS += -DPLL_WORKAROUND
EXTRA_CFLAGS += -DCONNECT_DIRECT
EXTRA_CFLAGS += -DWILC_PARSE_SCAN_IN_HOST

#EXTRA_CFLAGS += -DTCP_ACK_FILTER
EXTRA_CFLAGS += -DAGING_ALG
EXTRA_CFLAGS += -DDISABLE_PWRSAVE_AND_SCAN_DURING_IP

EXTRA_CFLAGS += -DWILC_PLATFORM=WILC_LINUXKERNEL  
EXTRA_CFLAGS += -Wno-unused-function
EXTRA_CFLAGS += -DUSE_WIRELESS

#	[[ Add KR Team
EXTRA_CFLAGS += -DSTATIC_MACADDRESS
EXTRA_CFLAGS += -DCOMPLEMENT_BOOT

ifeq ($(strip $(CONFIG_WILC1000_PREALLOCATE_DURING_SYSTEM_BOOT)),y)
	EXTRA_CFLAGS += -DNMC_PREALLOC_AT_BOOT
# for rx_buffer
	EXTRA_CFLAGS += -DMEMORY_STATIC
else
	ifeq ($(strip $(CONFIG_WILC1000_PREALLOCATE_AT_LOADING_DRIVER)),y)
		EXTRA_CFLAGS += -DMEMORY_STATIC
		EXTRA_CFLAGS += -DNMC_PREALLOC_AT_INSMOD
	else
		ifeq ($(strip $(CONFIG_WILC1000_DYNAMICALLY_ALLOCATE_MEMROY)),y)
			EXTRA_CFLAGS += -DNMC_NORMAL_ALLOC
		endif
	endif
endif


#[[ include
EXTRA_CFLAGS += -I$(src)/wilc_oswrapper/include/ 
EXTRA_CFLAGS += -I$(src)/
EXTRA_CFLAGS += -I$(src)/driver/include/
EXTRA_CFLAGS += -I$(src)/driver/
EXTRA_CFLAGS += -I$(src)/driver/linux/include/

#------------------------------------------------------------------------------
$(MODULE_NAME)-objs += driver/linux/source/wilc_wfi_netdevice.o
$(MODULE_NAME)-objs += driver/linux/source/wilc_wfi_cfgoperations.o
$(MODULE_NAME)-objs += driver/linux/source/linux_wlan.o
$(MODULE_NAME)-objs += driver/linux/source/linux_mon.o

$(MODULE_NAME)-objs += wilc_oswrapper/source/linuxkernel/source/wilc_memory.o
$(MODULE_NAME)-objs += wilc_oswrapper/source/linuxkernel/source/wilc_msgqueue.o
$(MODULE_NAME)-objs += wilc_oswrapper/source/linuxkernel/source/wilc_semaphore.o
$(MODULE_NAME)-objs += wilc_oswrapper/source/linuxkernel/source/wilc_sleep.o
$(MODULE_NAME)-objs += wilc_oswrapper/source/linuxkernel/source/wilc_strutils.o
$(MODULE_NAME)-objs += wilc_oswrapper/source/linuxkernel/source/wilc_thread.o
$(MODULE_NAME)-objs += wilc_oswrapper/source/linuxkernel/source/wilc_time.o
$(MODULE_NAME)-objs += wilc_oswrapper/source/linuxkernel/source/wilc_timer.o

$(MODULE_NAME)-objs += driver/core_configurator/coreconfigurator.o
$(MODULE_NAME)-objs += driver/wilc_driver_interface/host_interface.o
$(MODULE_NAME)-objs += driver/core_simulator/fifo_buffer.o
$(MODULE_NAME)-objs += driver/wilc_sdio.o
$(MODULE_NAME)-objs += driver/wilc_spi.o
$(MODULE_NAME)-objs += driver/wilc_wlan_cfg.o

WILC1000_SRC_VERSION = 9.4
PATCHLEVEL = 4
WILC1000_FW_VERSION = 0

EXTRA_CFLAGS += -D__DRIVER_VERSION__=\"$(WILC1000_SRC_VERSION).$(PATCHLEVEL)\"