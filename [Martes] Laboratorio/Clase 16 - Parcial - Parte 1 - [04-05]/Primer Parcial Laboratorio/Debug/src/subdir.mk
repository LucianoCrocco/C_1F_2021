################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Utilidades.c \
../src/eServicio.c \
../src/eTrabajo.c \
../src/main.c \
../src/nexoEstructuras.c 

OBJS += \
./src/Utilidades.o \
./src/eServicio.o \
./src/eTrabajo.o \
./src/main.o \
./src/nexoEstructuras.o 

C_DEPS += \
./src/Utilidades.d \
./src/eServicio.d \
./src/eTrabajo.d \
./src/main.d \
./src/nexoEstructuras.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


