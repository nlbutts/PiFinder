EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:General
LIBS:PiFinder-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L VL53L0X U1
U 1 1 583A4C95
P 5750 3150
F 0 "U1" H 5700 2400 60  0000 C CNN
F 1 "VL53L0X" H 5700 3600 60  0000 C CNN
F 2 "KicadLibrary:VL53L0x" H 5750 3150 60  0001 C CNN
F 3 "" H 5750 3150 60  0001 C CNN
	1    5750 3150
	1    0    0    -1  
$EndComp
$Comp
L R R3
U 1 1 583A4CD2
P 4550 2450
F 0 "R3" V 4630 2450 50  0000 C CNN
F 1 "2k" V 4550 2450 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" V 4480 2450 50  0001 C CNN
F 3 "" H 4550 2450 50  0000 C CNN
	1    4550 2450
	1    0    0    -1  
$EndComp
$Comp
L R R1
U 1 1 583A4D3F
P 4300 2450
F 0 "R1" V 4380 2450 50  0000 C CNN
F 1 "2k" V 4300 2450 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" V 4230 2450 50  0001 C CNN
F 3 "" H 4300 2450 50  0000 C CNN
	1    4300 2450
	1    0    0    -1  
$EndComp
Wire Wire Line
	4550 2850 5100 2850
Wire Wire Line
	4550 2600 4550 2850
Wire Wire Line
	4000 2950 5100 2950
Wire Wire Line
	4300 2950 4300 2600
$Comp
L CONN_01X05 P1
U 1 1 583A4D71
P 3150 2650
F 0 "P1" H 3150 2950 50  0000 C CNN
F 1 "CONN_01X05" V 3250 2650 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x05" H 3150 2650 50  0001 C CNN
F 3 "" H 3150 2650 50  0000 C CNN
	1    3150 2650
	-1   0    0    -1  
$EndComp
$Comp
L C C1
U 1 1 583A4DA8
P 6700 3150
F 0 "C1" H 6725 3250 50  0000 L CNN
F 1 "100n" H 6725 3050 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805" H 6738 3000 50  0001 C CNN
F 3 "" H 6700 3150 50  0000 C CNN
	1    6700 3150
	1    0    0    -1  
$EndComp
$Comp
L VCC #PWR01
U 1 1 583A4DE7
P 3500 2100
F 0 "#PWR01" H 3500 1950 50  0001 C CNN
F 1 "VCC" H 3500 2250 50  0000 C CNN
F 2 "" H 3500 2100 50  0000 C CNN
F 3 "" H 3500 2100 50  0000 C CNN
	1    3500 2100
	1    0    0    -1  
$EndComp
Wire Wire Line
	3500 2450 3350 2450
Wire Wire Line
	3500 2100 3500 2450
Wire Wire Line
	4550 2200 4550 2300
Wire Wire Line
	3500 2200 4550 2200
Connection ~ 3500 2200
Wire Wire Line
	4300 2300 4300 2200
Connection ~ 4300 2200
Wire Wire Line
	3350 2550 4050 2550
Wire Wire Line
	4050 2550 4050 2700
Wire Wire Line
	4050 2700 4550 2700
Connection ~ 4550 2700
Wire Wire Line
	3350 2650 4000 2650
Wire Wire Line
	4000 2650 4000 2950
Connection ~ 4300 2950
Wire Wire Line
	3350 2750 3850 2750
Wire Wire Line
	3850 2750 3850 3450
Wire Wire Line
	3850 3450 5100 3450
$Comp
L GND #PWR02
U 1 1 583A4EC8
P 3500 3000
F 0 "#PWR02" H 3500 2750 50  0001 C CNN
F 1 "GND" H 3500 2850 50  0000 C CNN
F 2 "" H 3500 3000 50  0000 C CNN
F 3 "" H 3500 3000 50  0000 C CNN
	1    3500 3000
	1    0    0    -1  
$EndComp
Wire Wire Line
	3350 2850 3500 2850
Wire Wire Line
	3500 2850 3500 3000
$Comp
L GND #PWR03
U 1 1 583A4F02
P 6700 3950
F 0 "#PWR03" H 6700 3700 50  0001 C CNN
F 1 "GND" H 6700 3800 50  0000 C CNN
F 2 "" H 6700 3950 50  0000 C CNN
F 3 "" H 6700 3950 50  0000 C CNN
	1    6700 3950
	1    0    0    -1  
$EndComp
Wire Wire Line
	6700 3750 6400 3750
Wire Wire Line
	6700 3300 6700 3950
Wire Wire Line
	6400 3650 6700 3650
Connection ~ 6700 3750
Wire Wire Line
	6400 3550 6700 3550
Connection ~ 6700 3650
Wire Wire Line
	6400 3450 6700 3450
Connection ~ 6700 3550
Wire Wire Line
	6400 3350 7050 3350
Connection ~ 6700 3450
$Comp
L C C2
U 1 1 583A503F
P 7050 3150
F 0 "C2" H 7075 3250 50  0000 L CNN
F 1 "4.7u" H 7075 3050 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805" H 7088 3000 50  0001 C CNN
F 3 "" H 7050 3150 50  0000 C CNN
	1    7050 3150
	1    0    0    -1  
$EndComp
Connection ~ 6700 3350
Wire Wire Line
	7050 3350 7050 3300
Wire Wire Line
	6400 2950 7050 2950
Connection ~ 6700 2950
Wire Wire Line
	6400 2850 6700 2850
Wire Wire Line
	6700 2700 6700 3000
Wire Wire Line
	7050 2950 7050 3000
$Comp
L R R4
U 1 1 583A539A
P 4600 3900
F 0 "R4" V 4680 3900 50  0000 C CNN
F 1 "10k" V 4600 3900 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" V 4530 3900 50  0001 C CNN
F 3 "" H 4600 3900 50  0000 C CNN
	1    4600 3900
	1    0    0    -1  
$EndComp
$Comp
L R R2
U 1 1 583A53E7
P 4400 3900
F 0 "R2" V 4480 3900 50  0000 C CNN
F 1 "10k" V 4400 3900 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" V 4330 3900 50  0001 C CNN
F 3 "" H 4400 3900 50  0000 C CNN
	1    4400 3900
	1    0    0    -1  
$EndComp
$Comp
L VCC #PWR04
U 1 1 583A54B4
P 4100 4150
F 0 "#PWR04" H 4100 4000 50  0001 C CNN
F 1 "VCC" H 4100 4300 50  0000 C CNN
F 2 "" H 4100 4150 50  0000 C CNN
F 3 "" H 4100 4150 50  0000 C CNN
	1    4100 4150
	1    0    0    -1  
$EndComp
Wire Wire Line
	4100 4150 4600 4150
Wire Wire Line
	4400 4150 4400 4050
Wire Wire Line
	4600 4150 4600 4050
Connection ~ 4400 4150
Wire Wire Line
	4600 3750 4600 3550
Wire Wire Line
	4600 3550 5100 3550
Wire Wire Line
	4400 3450 4400 3750
Connection ~ 4400 3450
$Comp
L VCC #PWR05
U 1 1 583A52DA
P 6700 2700
F 0 "#PWR05" H 6700 2550 50  0001 C CNN
F 1 "VCC" H 6700 2850 50  0000 C CNN
F 2 "" H 6700 2700 50  0000 C CNN
F 3 "" H 6700 2700 50  0000 C CNN
	1    6700 2700
	1    0    0    -1  
$EndComp
Connection ~ 6700 2850
NoConn ~ 6400 3100
$EndSCHEMATC
