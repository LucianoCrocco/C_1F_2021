################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/itoa\ e\ atoi\ test.c 

OBJS += \
./src/itoa\ e\ atoi\ test.o 

C_DEPS += \
./src/itoa\ e\ atoi\ test.d 


# Each subdirectory must supply rules for building sources it contributes
src/itoa\ e\ atoi\ test.o: ../src/itoa\ e\ atoi\ test.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/itoa e atoi test.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


