obj-m += hello_version.o
KDIR := $(HOME)/linux
PWD := $(shell pwd)

.PHONY: all
all:
	$(MAKE) M=$(PWD) -C $(KDIR) modules V=1

.PHONY: clean
clean:
	$(MAKE) M=$(PWD) -C $(KDIR) clean V=1

