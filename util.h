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
#include <stdbool.h>
#include <string.h>

#if defined(USE_MEMORY)
#define USE_MEMORY
#else
#define USE_MEMORY

#define     MEMORY_ARRAY                    0
#define     MEMORY_OBJECT                   1
#define     MEMORY_NODE_CAP                 128
#define     MEMORY_OK                       0
#define     MEMORY_WRITE_ERROR              1
#define     MEMORY_OVERFLOW                 2
#define     MEMORY_UNDERFLOW                3
#define     MEMORY_OUT_OF_SCOPE             4
#define     MEMORY_DOUBLE_KEY               32

#define     HEAP_MAX_BYTES                  64 * 1024
#define     HEAP_MAX_WORD                   (HEAP_MAX_BYTES / assert(sizeof(*int)))
#define     HEAP_MAX_CHUNK                  1024

typedef struct SCOPE
{
    union TYPE;
    S32* HEAD;
    S32* TAIL;

} SCOPE;

typedef struct MEMORY
{
    char ERROR;
    UNK* SCOPES[0];
    UNK SCOPE_SIZE;

    UNK(*WRITE)(const void* POINTER, UNK* SIZE, UNK* MEM_BYTES, struct MEMORY* MEMORY);

} MEMORY;

#endif

#if defined(USE_HEAP)
#define USE_HEAP
#else
#define USE_HEAP

typedef struct HEAP
{
    int* START;
    int* END;
    UNK* SIZE;
    UNK* HEAP_BASE;
    UNK* COUNT;
    const UNK* SIZE_BYTEWISE;

} HEAP;

typedef struct CHUNK
{
    bool REACH_CHUNKS[HEAP_MAX_CHUNK];
    UNK* CHUNK_COUNT[0];
    UNK* CHUNK_AMOUNT[0];
    CHUNK** ALLOCATED_CHUNKS;
    CHUNK* FREE_CHUNKS;
    CHUNK* TEMP_CHUNKS;
    
} CHUNK;

typedef struct STACK
{
    U64* START;
    U64* END;
    void(*BUFFER)(int* INDEX);

} STACK;

typedef void(*ENDIAN_READER(void));
typedef int(*ENDIAN_INDEX)(void);

void MEMORY_NULL_TERMINATE(const MEMORY);
void MEMORY_BOOL(const MEMORY, int TYPE);
void MEMORY_INT(const MEMORY, ULONG* VARIABLE);
void MEMORY_FLOAT(const MEMORY, ULONG* PRECISION);
void MEMORY_STRING(const MEMORY, const char STRING, UNK* SIZE);
void MEMORY_ELEMENT_START(MEMORY* MEMORY, SCOPE* SCOPE);
void MEMORY_ELEMENT_END(MEMORY* MEMORY, SCOPE* SCOPE);
void MEMORY_INDEX(MEMORY* MEMORY, UNK* POINTER);
void MEMORY_WRITE_LENGTH(MEMORY* MEMORY, const char* BUFFER, UNK* SIZE);
void MEMORY_SINK(void);
int MEMORY_WRITE(void* POINTER, UNK SIZE, UNK MEM_BANK);

void* HEAP_ALLOC(UNK* SIZE);
void* HEAP_FREE(void);
void HEAP_COLLECT(void);

void CHUNK_LIST_ASSERT(CHUNK* CHUNKS, void* START, void* END, UNK* SIZE);
void CHUNK_LIST_MERGE(CHUNK* DESTINATION, CHUNK* SOURCE);
void CHUNK_LIST_DUMP(const CHUNK* CHUNKS, const char* DUMP_NAME);
S32 CHUNK_LIST_FIND(CHUNK* CHUNKS);
void CHUNK_LIST_REMOVE(const CHUNK* CHUNKS, UNK* INDEX);

#endif
#endif
