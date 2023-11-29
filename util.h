/* COPYRIGHT (C) HARRY CLARK 2023 */

/* CS1_CS RECREATIONAL MALLOC ACTIVITY */

/* THIS PROJECT SERVES TO PROVIDE A BASE OF WHICH MEMORY ALLOCATION WORKS */
/* ALL OF THIS IS IN RELATION TO OPERATING SYSTEM AND MEMORY MANAGEMENT SYSTEMS */
/* AS PER MY DESIGNATED MODULE CONTENTS */

#ifndef UTIL
#define UTIL

/* NESTED INCLUDES */

#include "common.h"

/* SYSTEM INCLUDES */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#if defined(USE_HEAP)
#define USE_HEAP
#else
#define USE_HEAP

#define     MEMORY_ARRAY                    0
#define     MEMORY_OBJECT                   1
#define     MEMORY_NODE_CAP                 128
#define     MEMORY_OK                       0
#define     MEMORY_WRITE_ERROR              1
#define     MEMORY_OVERFLOW                 2
#define     MEMORY_UNDERFLOW                3
#define     MEMORY_OUT_OF_SCOPE             4
#define     MEMORY_DOUBLE_KEY               32   

typedef struct SCOPE
{
    struct TYPE{};
    S32* HEAD;
    S32* TAIL;

} SCOPE;

typedef struct MEMORY
{
    typedef void(*MEMORY_SINK());
    typedef UNK (*MEMORY_WRITE)(const void* POINTER, UNK SIZE, UNK MEM_BANK, void* MEMORY_SINK); 

} MEMORY;

#endif

#endif