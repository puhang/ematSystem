################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/default_Config_Menu.c \
../src/display_Terminal.c \
../src/dynamic_Config_Menu.c \
../src/ematController_terminal.c \
../src/emat_Initial.c \
../src/key_Logic.c \
../src/main_Menu.c \
../src/mem_Access.c \
../src/register_Config.c \
../src/save_Menu.c 

OBJS += \
./src/default_Config_Menu.o \
./src/display_Terminal.o \
./src/dynamic_Config_Menu.o \
./src/ematController_terminal.o \
./src/emat_Initial.o \
./src/key_Logic.o \
./src/main_Menu.o \
./src/mem_Access.o \
./src/register_Config.o \
./src/save_Menu.o 

C_DEPS += \
./src/default_Config_Menu.d \
./src/display_Terminal.d \
./src/dynamic_Config_Menu.d \
./src/ematController_terminal.d \
./src/emat_Initial.d \
./src/key_Logic.d \
./src/main_Menu.d \
./src/mem_Access.d \
./src/register_Config.d \
./src/save_Menu.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM v7 Linux gcc compiler'
	arm-linux-gnueabihf-gcc -Wall -O0 -g3 -c -fmessage-length=0 -MT"$@" --sysroot=/home/puhang/Documents/workspace/vitis/ematController_linux/export/ematController_linux/sw/ematController_linux/linux_domain/sysroot/cortexa9t2hf-neon-xilinx-linux-gnueabi -I/home/puhang/Documents/workspace/vitis/ematController_linux/export/ematController_linux/sw/ematController_linux/linux_domain/sysroot/cortexa9t2hf-neon-xilinx-linux-gnueabi/usr/include -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


