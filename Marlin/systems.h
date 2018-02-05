#ifndef SYSTEMS_H
#define SYSTEMS_H

#define STRINGIFY_MACRO(x) STR(x)
#define STR(x) #x
#define EXPAND(x) x
#define CONCAT(n1, n2) STRINGIFY_MACRO(EXPAND(n1)EXPAND(n2))
#define CONCAT3(n1, n2, n3) STRINGIFY_MACRO(EXPAND(n1)EXPAND(n2)EXPAND(n3))
#define CONCAT5(n1, n2, n3, n4, n5) STRINGIFY_MACRO(EXPAND(n1)EXPAND(n2)EXPAND(n3)EXPAND(n4)EXPAND(n5))
#define CONCAT_(a, b) a ## b
#define SYSTEM gigabot

#define SYSTEM_SETTINGS     CONCAT(SYSTEM,.h)
#define SYSTEM_SETTINGS_ADV CONCAT(SYSTEM,_adv.h)
#define SYSTEM_CODE         CONCAT(SYSTEM,.cpp)

#define SECTION(section) section
#define SUBSECTION(section, subsection)    CONCAT_(section, subsection)
#define IS_SECTION(section) (SYSTEM_SECTION == section)
#define IS_SUBSECTION(section, subsection) (SYSTEM_SECTION == SUBSECTION(section, subsection))

#define SYSTEM_UNKNOWN -1


#define INFO        1
#define MACHINE     2
#define EXTRUDER    3
#define TEMPERATURE 4
#define HOMING      5
#define MOTION      6
#define PROBES      7

#define LCD         8
#define EXTRAS      9

#define AZTEEG_X3_PRO 10

//#define MARLIN_MAIN_GLOBAL  11
//#define MARLIN_MAIN_SETUP   12
//#define MARLIN_MAIN_LOOP    13

#define PINS                14
#define EXTRAS1           15
#define EXTRAS_02           16

//#pragma message ("ISS = " STRINGIFY(IS_SUBSECTION(EXTRAS, 1)))


#define SYSTEM_SECTION SYSTEM_UNKNOWN

#endif // SYSTEMS_H
