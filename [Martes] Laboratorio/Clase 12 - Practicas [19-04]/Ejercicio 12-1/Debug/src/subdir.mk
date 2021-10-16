################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Estructuras.c \
../src/Ordenamientos.c \
../src/Utilidades.c \
../src/main.c 

OBJS += \
./src/Estructuras.o \
./src/Ordenamientos.o \
./src/Utilidades.o \
./src/main.o 

C_DEPS += \
./src/Estructuras.d \
./src/Ordenamientos.d \
./src/Utilidades.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


