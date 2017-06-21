ifneq ($(KERNELRELEASE),)
obj-m := hello_version.o
else
KDIR := $(HOME)/linux
all:
	$(MAKE) -C $(KDIR) M=$$PWD
endif
