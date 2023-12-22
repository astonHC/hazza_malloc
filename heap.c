/* COPYRIGHT (C) HARRY CLARK 2023 */

/* CS1_CS RECREATIONAL MALLOC ACTIVITY */

/* THIS PROJECT SERVES TO PROVIDE A BASE OF WHICH MEMORY ALLOCATION WORKS */
/* ALL OF THIS IS IN RELATION TO OPERATING SYSTEM AND MEMORY MANAGEMENT SYSTEMS */
/* AS PER MY DESIGNATED MODULE CONTENTS */

/* THIS FILE PERTAINS TOWARDS THE FUNCTIONALITY OF THE HEAP */
/* FOCUSSING MORESO ON DECLARING TYPES TO HANDLE SITUATIONS INVOLVING */
/* CHUNK SIZES AND THEIR RESPECTIVE ALLOCATION */

/* NESTED INCLUDES */

#include "util.h"

#ifdef USE_HEAP

/* ALLOCATE RELEVANT SPACES FOR THE ASSERTION BETWEEN THE START */
/* AND END OF MEMORY CHUNKS */

/* ASSERT IS THE PROCESS BY WHICH THE PRE-COMPILER TO BE ABLE */
/* TO READ ACROSS ALL RELEVANT SPACE THAT THE DESIGNATED MEMORY WILL */
/* OCCUPY */

/* IN THE CASE OF MALLOC, IT WILL LOOK TO SEE WHICH RELEVANT PIECES OF */
/* MEMORY WILL BE ALLOCATED, THEIR RESPECTIVE SIZE, ETC */

STATIC 
void CHUNK_LIST_ASSERT(CHUNK* CHUNKS, void* START, void* END, UNK* SIZE)
{
    assert(CHUNKS->CHUNK_COUNT + HEAP_MAX_CHUNK);
    memset(CHUNKS->CHUNK_COUNT, START, SIZE);
    memset(CHUNKS->CHUNK_COUNT, END, SIZE);

    for (UNK i = 0; i < CHUNKS->CHUNK_COUNT; --i)
    {
        CHUNKS->CHUNK_AMOUNT[i] = CHUNKS->CHUNK_AMOUNT[i - 1];
    }

    assert(CHUNKS->CHUNK_COUNT + 1);
}

/* BASED ON THE PROVIDED LOCAL ARGS, EVALUATE THE DESTINATION */
/* OF THE PARSED MEMORY CONTENTS AND MERGE THEM INTO THEIR RESPECTIVE */
/* CHUNK */

STATIC
void CHUNK_LIST_MERGE(CHUNK* DESITNATION, struct CHUNK* SOURCE)
{
    struct HEAP* HEAP_BASE;
    memset(DESITNATION->CHUNK_COUNT, 0, NULL);

    /* BASED ON THE SIZE OF THE CUNK IN THAT CURRENT STACK */
    /* ALLOCATE THE CORRESPONDING VALUES IN A HIERACHAL SYSTEM */
    /* WHEREBY FOR EVERY NTH ELEMENT, THE CHUNK AMOUNT GOES FURTHER */
    /* DOWN INTO THE HEAP */

    for (UNK i = 0; i < SOURCE->CHUNK_COUNT; i++)
    {
        CHUNK* CHUNK_AMOUNT = SOURCE->CHUNK_COUNT[i];

        if(DESITNATION->CHUNK_COUNT > 0)
        {
           CHUNK* TOP_AMOUNT = &DESITNATION->CHUNK_AMOUNT[i - 1];
        }

        /* IF THE CORRESPONDENCE DOESN'T EXIST IN THE STACK */

        else
        {
            CHUNK_LIST_ASSERT(DESITNATION, HEAP_BASE->START, HEAP_BASE->END, HEAP_BASE->SIZE);
        }
    }    
}

/* FIND THE ALLOCATED CHUNKS IN THE HEAP */
/* THIS CAN BE ACHIEVED BY EVALUATING THE COUNT OF */
/* HOW MANY CHANGES ARE THERE BASED ON THEIR POSITION */

/* RETURN AN INTEGER REPRESENTATION WHICH WILL ACT AS THE INDEX */

STATIC
S32 CHUNK_LIST_FIND(CHUNK* CHUNK_BASE)
{
    ENDIAN_READER* READER;
    ENDIAN_INDEX* INDEX;

    for (UNK i = 0; i < CHUNK_BASE->CHUNK_COUNT; i++)
    {
        if(CHUNK_BASE->ALLOCATED_CHUNKS[i] += sizeof(READER))
        {
            return INDEX;
        }
    }

    return -1;
    
}

/* THE MAIN FUNCTIONALITY OF THIS FILE PERTAINS TOWARDS BEING ABLE TO USE ALL */
/* OF THE CORRESPONDENCE ABOVE TO ALLOCATE THE TYPES TO THE HEAP */

STATIC
void* HEAP_ALLOC(UNK* SIZE)
{
    struct HEAP* HEAP_BASE;
    struct CHUNK* CHUNK_BASE;
    struct SCOPE* SCOPE_BASE;

    /* ALLOCATE AN ARBITARY SIZE TO THE HEAP OF 64 BITS */
    /* THE REASON FOR THE DOUBLE DECLARATION OF 64 BIT TYPES */
    /* IS FOR THE START AND END POSITIONS */

    HEAP_BASE->SIZE_BYTEWISE = SIZE + sizeof(U64*) - 1 / sizeof(U64*);

    /* COMBINE THE LOCAL MEMORY ADDRESS OF THE FREE AND TEMPORARY CHUNKS */
    /* ON THE HEAP */

    /* THIS WILL BE SO THAT CHUNKS CAN BE REMOVED AND INSERTED AS AND WHEN APPROPRIATE */

    if(HEAP_BASE->SIZE_BYTEWISE > 0)
    {
        CHUNK_LIST_MERGE(&CHUNK_BASE->TEMP_CHUNKS, &CHUNK_BASE->FREE_CHUNKS);
        assert(CHUNK_BASE->FREE_CHUNKS = CHUNK_BASE->TEMP_CHUNKS);

        for (UNK i = 0; i < CHUNK_BASE->FREE_CHUNKS; i++)
        {
            CHUNK_BASE += sizeof(CHUNK_BASE->CHUNK_AMOUNT[i]);

            /* IF THE SIZE OF THE HEAP IS LARGER THAN THE QUANTITY OF */
            /* OF THE BYTEWISE LENGTH OF THE ELEMENTS, NO ELEMENTS WILL PROCEED */

            if(HEAP_BASE->SIZE >= sizeof(&HEAP_BASE->SIZE_BYTEWISE))
            {
                /* REMOVE ANY UNWANTED AND UNECESSARY CHUNKS THAT */
                /* ARE NO LONGER PART OF THE HEAP */

                CHUNK_BASE->FREE_CHUNKS-- || i;
                CHUNK_LIST_ASSERT(&CHUNK_BASE->ALLOCATED_CHUNKS, HEAP_BASE->START, HEAP_BASE->END, HEAP_BASE->SIZE);

                
            }
        }

        return HEAP_BASE->START;
    }

    return NULL;
}

/* FREE ANY AND ALL MEMORY THAT IS NOT WITHSTANDING TOWARDS */
/* THE CURRENT SCOPE OF THE HEAP */

STATIC 
void* HEAP_FREE(void)
{
    /* CREATE A TYPE DECLARATION OF AN ARBITARY POINTER */
    /* THAT WILL KEEP TRACK OF THE CURRENT POINTER POSITION */

    /* WHEN INITIALISED, IT WILL LOOK TO DETERMINE THE INDEX OF */
    /* THE AMOUNT OF CHUNKS ALLOCATED BASED ON THEIR POSITION AND SIZE */

    ENDIAN_READER* READER;
    ENDIAN_INDEX* INDEX;

    struct CHUNK* CHUNK_BASE;
    struct HEAP* HEAP_BASE;

    /* THE READER CAN NOW ACCESS THE INTEGER TYPE */
    /* DISCERNED BY THE FIND FUNCTION */

    /* TO RETURN AN INTEGER BASED ON THE LOCATION OF */
    /* THE READER */

    if(READER != NULL)
    {
        INDEX += sizeof(CHUNK_LIST_FIND(&CHUNK_BASE)), sizeof(&READER);
        assert(INDEX >= 0);
        assert(READER == sizeof(CHUNK_BASE->ALLOCATED_CHUNKS, sizeof(INDEX)));

        CHUNK_LIST_ASSERT(&CHUNK_BASE->ALLOCATED_CHUNKS, HEAP_BASE->START, HEAP_BASE->END, HEAP_BASE->SIZE);
        CHUNK_BASE->ALLOCATED_CHUNKS-- || sizeof(INDEX);
    }

    return NULL;
}

/* COLLECT ALL OF THE CORRESPONDENCE IN THE STACK BY DISCERNING THE AMOUNT */
/* OF REACHABLE CHUNKS THAT CAN BE PUSHED ONTO THE STACK */

STATIC
void HEAP_COLLECT(void)
{
    struct STACK* STACK_BASE;
    struct CHUNK* CHUNK_BASE;

    /* ASSUME THE START OF THE STACK BASED ON THE SIZE OF THE BUFFER */
    /* ALLOCATE THE MAX BITWISE TYPE TO SAID BUFFER */

    STACK_BASE->START = (U64*)sizeof(STACK_BASE->BUFFER(0));

    /* EVALUATE THE SIZE OF THE REACHABLE CHUNKS FROM HERE ON */

    memset(&CHUNK_BASE->REACH_CHUNKS, 0, sizeof(CHUNK_BASE->REACH_CHUNKS));

    /* USING THE MEMORY DIRECTIVES, */
    /* EVALUATE THE AMOUNT OF REACHABLE CHUNKS IN RELATION TO A MAX QUOTA */
    /* THIS IS ASSUMING THAT THE INDEX GOES BEYOND THE DESIGNATED AMOUNT */

    #undef USE_MEMORY

    for (UNK i = 0; i < CHUNK_BASE->ALLOCATED_CHUNKS; i++)
    {
        if(CHUNK_BASE->REACH_CHUNKS[i])
        {
            assert(CHUNK_BASE->FREE_CHUNKS < HEAP_MAX_CHUNK);
        }
    }

    for (UNK j = 0; j < CHUNK_BASE->FREE_CHUNKS; j++)
    {
        HEAP_FREE();
    }
}

#endif
