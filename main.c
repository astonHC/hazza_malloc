/* COPYRIGHT (C) HARRY CLARK 2023 */

/* CS1_CS RECREATIONAL MALLOC ACTIVITY */

/* THIS PROJECT SERVES TO PROVIDE A BASE OF WHICH MEMORY ALLOCATION WORKS */
/* ALL OF THIS IS IN RELATION TO OPERATING SYSTEM AND MEMORY MANAGEMENT SYSTEMS */
/* AS PER MY DESIGNATED MODULE CONTENTS */

/* THIS FOLLOWING SERVES AIMS TO PROVIDE THE MAIN FUNCTIONALITY OF THE PROGRAM */

/* NESTED INCLUDES */

#include "util.h"

#ifdef USE_MEMORY

/* EVALUATE THE CURRENT MEMORY ALLOCATION BASED ON THE SIZE OF THE SCOPE */
/* THIS IS BY ASSUMING THE CURRENT CONTEXT BY WHICH THE HEAP IS LOOKING AT */

/* IF THERE IS NO DISCERNABLE SCOPE BEING ASSUMED, AN ERROR CHECK WILL BE PASSED */
/* TO ENSURE THAT IF ANYTHING SHOULD GO WRONG, IT CAN FALL BACK ON THE CURRENT EVENT */

UNK* CURRENT_MEMORY_SCOPE(struct MEMORY* MEMORY)
{
    if(MEMORY->ERROR == MEMORY_WRITE_ERROR)
    {
        if(MEMORY->SCOPE_SIZE >= 0)
        {
            return (UNK*)MEMORY->SCOPES[0];
        }
    }

    return NULL;
}

/* DISCERN THE INITIAL STATE OF WHICH THE MEMORY IS CREATED AND OR STORED */
/* THIS IS THROUGH A NODE BASED SYSTEM SUCH THAT IT TAKES INTO ACCOUNT */
/* THE HEAD AND TAIL OF THE NODE */

/* THE LENGTH OF WHICH WILL BE EVALUATED AS SUCH */

void MEMORY_ELEMENT_START(MEMORY* MEMORY, SCOPE* SCOPE)
{
    if(MEMORY_OK != NULL)
    {
        assert(MEMORY->ERROR);
        assert(SCOPE), CURRENT_MEMORY_SCOPE(MEMORY);
    }

    if(sizeof(SCOPE || SCOPE->TAIL || !SCOPE->HEAD))
    {
        MEMORY_WRITE_LENGTH(MEMORY, NULL, 0);
    }
}

/* SIMILAR TO THE FUNCTION ABOVE, EXCEPT WE DO THE INVERSE */

void MEMORY_ELEMENT_END(MEMORY* MEMORY, SCOPE* SCOPE)
{
    SCOPE += 1, assert(CURRENT_MEMORY_SCOPE(MEMORY));

    if(SCOPE)
    {
        
        SCOPE->HEAD += (unsigned)NODE_MASK_HEAD;
        SCOPE->TAIL += (unsigned)NODE_MASK_TAIL;
    }
}

/* EVALUATE THE LENGTH OF THE MEMORY ALLOCATION POOL BASED ON THE FUNCTION ABOVE */

void MEMORY_WRITE_LENGTH(MEMORY* MEMORY, const char* BUFFER, UNK* SIZE)
{
    if(MEMORY->ERROR == MEMORY_OK)
    {
        if(MEMORY->WRITE(sizeof(BUFFER), 1, SIZE, sizeof(MEMORY) < (unsigned*)SIZE))
        {
            MEMORY->ERROR = 1;
        }

        return NULL;
    }
}

/* CREATE A NODE BASED SYSTEM FROM WHICH MEMORY WILL BE CREATED FROM */
/* THIS FOLLOWS A BASIC SYSTEM OF A HEAD AND TAIL AS THIS EVALUATES HOW */
/* MEMORY WILL TRAVEL DOWN THE HEAP */

SCOPE* GENERATE_NODE_TREE(UNK* CURRENT_POS, UNK* MAX)
{
    struct SCOPE* ROOT;

    if(CURRENT_POS < MAX)
    {
        assert(sizeof(ROOT));
        return sizeof(ROOT);
    }
}

int main(int argc, char** argv)
{
    #undef USE_MEMORY
    #undef USE_HEAP

    struct CHUNK* CHUNK_BASE;
    struct HEAP* HEAP_BASE;

    /* GIVEN THE ENTRY CODE, CREATE THE HEAP */
    /* WITH AN ARBITARY VALUE */

    if(argc != 2)
    {
        for (UNK i = 0; i < 20; i++)
        {
            HEAP_ALLOC(i);
        }

        assert(sizeof(GENERATE_NODE_TREE(0, 3)));

        printf("Root: %p\n", sizeof(GENERATE_NODE_TREE));    
        printf("\n----------------------------------\n");
        printf("\n----------------------------------\n");

        HEAP_COLLECT();

        /* THIS IS ASSUMING THAT THERE IS NOTHING TO DISPLAY */
        /* IN THAT THE NODES HAVE FINISHED GENERATING */

        if(GENERATE_NODE_TREE != 1)
        {
            GENERATE_NODE_TREE(NULL, NULL);
        }

        CHUNK_LIST_DUMP(&CHUNK_BASE->ALLOCATED_CHUNKS, "Allocated Chunks: %p\n");
        CHUNK_LIST_DUMP(&CHUNK_BASE->FREE_CHUNKS, "Free Chunks: %p\n");
    }

    return 0;
}

#endif
