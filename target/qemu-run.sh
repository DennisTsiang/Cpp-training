#!/bin/sh

# /Applications/GNU\ ARM\ Eclipse/QEMU/2.4.50-201510290935-dev/bin/qemu-system-gnuarmeclipse --verbose --board STM32F4-Discovery --mcu STM32F407VG -d unimp,guest_errors --image build/debug/C-501.elf --semihosting-config enable=on,target=native

# Path to QEMU
#
QEMU_path='/home/feabhas/opt/gnuarmeclipse/qemu/2.8.0-201703022210-head/bin'

# Invoke QEMU
#
"$QEMU_path"/qemu-system-gnuarmeclipse              \
    --verbose                                       \
    --board STM32F4-Discovery                       \
    --mcu STM32F407VG                               \
    -d unimp,guest_errors                           \
    --semihosting-config enable=on,target=native    \
    --image "$1" 
