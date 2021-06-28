################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Controller.c \
../src/LinkedList.c \
../src/Piloto.c \
../src/Vuelos.c \
../src/bibliotecaGen.c \
../src/main.c \
../src/nexoEstructuras.c \
../src/parser.c 

OBJS += \
./src/Controller.o \
./src/LinkedList.o \
./src/Piloto.o \
./src/Vuelos.o \
./src/bibliotecaGen.o \
./src/main.o \
./src/nexoEstructuras.o \
./src/parser.o 

C_DEPS += \
./src/Controller.d \
./src/LinkedList.d \
./src/Piloto.d \
./src/Vuelos.d \
./src/bibliotecaGen.d \
./src/main.d \
./src/nexoEstructuras.d \
./src/parser.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


