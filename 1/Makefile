# Makefile for building the kernel and setting up the bootable image with GRUB

# Tools
ASM = nasm
CC = gcc
LD = ld
DD = dd
LOSETUP = losetup
PARTED = parted
MKFS = mkfs.ext2
MOUNT = mount
UMOUNT = umount
GRUB_INSTALL = grub-install
QEMU = qemu-system-x86_64

# Directories
BUILD_DIR = build
BOOT_DIR = $(BUILD_DIR)/boot
MOUNT_POINT = /mnt/kernel_image
SRC_DIR = srcs

# Files
KERNEL_BIN = $(BOOT_DIR)/kernel.bin
BOOT_IMG = kernel.img
GRUB_CFG = grub.cfg

# Compilation flags
CFLAGS = -m32 -ffreestanding -fno-builtin -fno-exceptions -fno-stack-protector -nostdlib -nodefaultlibs
LDFLAGS = -m elf_i386

# Kernel sources
ASM_SOURCES = $(SRC_DIR)/boot.asm
C_SOURCES = $(SRC_DIR)/kernel.c $(SRC_DIR)/scrolling.c $(SRC_DIR)/color_support.c $(SRC_DIR)/printf.c $(SRC_DIR)/keyboard.c
ASM_OBJECTS = $(ASM_SOURCES:$(SRC_DIR)/%.asm=$(BUILD_DIR)/%.o)
C_OBJECTS = $(C_SOURCES:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

# Default target
all: $(BOOT_IMG)

# Create a bootable image
$(BOOT_IMG): $(KERNEL_BIN) grub_install kernel.img
	LOOP_DEVICE=$(shell sudo losetup -f --show $(BOOT_IMG))
	sudo $(PARTED) $(LOOP_DEVICE) --script mklabel msdos
	sudo $(PARTED) $(LOOP_DEVICE) --script mkpart primary ext2 1MiB 100%
	sudo $(MKFS) -t ext2 $${LOOP_DEVICE}p1
	sudo $(MOUNT) $${LOOP_DEVICE}p1 $(MOUNT_POINT)
	sudo mkdir -p $(MOUNT_POINT)/boot/grub
	sudo cp $(KERNEL_BIN) $(MOUNT_POINT)/boot/
	sudo cp $(GRUB_CFG) $(MOUNT_POINT)/boot/grub/
	sudo $(GRUB_INSTALL) --root-directory=$(MOUNT_POINT) --no-floppy --modules="normal part_msdos ext2 multiboot" $${LOOP_DEVICE}
	sudo $(UMOUNT) $(MOUNT_POINT)
	sudo losetup -d $${LOOP_DEVICE}

# Create the kernel image file
kernel.img:
	$(DD) if=/dev/zero of=$(BOOT_IMG) bs=1M count=10

# Compile the kernel
$(KERNEL_BIN): $(ASM_OBJECTS) $(C_OBJECTS)
	mkdir -p $(BOOT_DIR)
	$(LD) $(LDFLAGS) -T linker.ld -o $(KERNEL_BIN) $(ASM_OBJECTS) $(C_OBJECTS)

# Assemble ASM sources
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.asm | $(BUILD_DIR)
	$(ASM) -f elf32 $< -o $@

# Compile C sources
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Ensure the build directory exists
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# GRUB configuration
grub_install: $(GRUB_CFG)

# Clean build artifacts
clean:
	rm -f $(BUILD_DIR)/*.o $(KERNEL_BIN) $(BOOT_IMG)
	rm -rf $(BUILD_DIR)

# Run the kernel using QEMU
run: $(BOOT_IMG)
	$(QEMU) -drive file=$(BOOT_IMG),format=raw

.PHONY: all clean run grub_install
