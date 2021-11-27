obj-m := h.o
KDIR := /home/mad_maximuus/Downloads/linux-5.10.76
all:
	$(MAKE) -C $(KDIR) M=$$PWD
you gay
