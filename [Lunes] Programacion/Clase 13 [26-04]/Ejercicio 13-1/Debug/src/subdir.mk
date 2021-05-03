################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Utilidades.c \
../src/eAuxiliar.c \
../src/eNacionalidad.c \
../src/eProductos.c \
../src/eTipoProducto.c \
../src/main.c \
../src/nexoEstructuras.c 

OBJS += \
./src/Utilidades.o \
./src/eAuxiliar.o \
./src/eNacionalidad.o \
./src/eProductos.o \
./src/eTipoProducto.o \
./src/main.o \
./src/nexoEstructuras.o 

C_DEPS += \
./src/Utilidades.d \
./src/eAuxiliar.d \
./src/eNacionalidad.d \
./src/eProductos.d \
./src/eTipoProducto.d \
./src/main.d \
./src/nexoEstructuras.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


