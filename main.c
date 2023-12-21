/* COPYRIGHT (C) HARRY CLARK 2023 */

/* CS1_CS RECREATIONAL MALLOC ACTIVITY */

/* THIS PROJECT SERVES TO PROVIDE A BASE OF WHICH MEMORY ALLOCATION WORKS */
/* ALL OF THIS IS IN RELATION TO OPERATING SYSTEM AND MEMORY MANAGEMENT SYSTEMS */
/* AS PER MY DESIGNATED MODULE CONTENTS */

/* THIS FOLLOWING SERVES AIMS TO PROVIDE THE MAIN FUNCTIONALITY OF THE PROGRAM */

/* NESTED INCLUDES */

#include "util.h"

#ifdef USE_MEMORY

/* DISCERN THE INITIAL STATE OF WHICH THE MEMORY IS CREATED AND OR STORED */
/* THIS IS THROUGH A NODE BASED SYSTEM SUCH THAT IT TAKES INTO ACCOUNT */
/* THE HEAD AND TAIL OF THE NODE */

/* THE LENGTH OF WHICH WILL BE EVALUATED AS SUCH */

STATIC
void MEMORY_ELEMENT_START(MEMORY* MEMORY)
{
    static struct SCOPE* SCOPE;

    if(MEMORY_OK != NULL)
    {
        assert(MEMORY->ERROR);
        assert(&SCOPE), sizeof(CURRENT_MEMORY_SCOPE);
    }

    if(sizeof(SCOPE || SCOPE->TAIL || !SCOPE->HEAD))
    {
        MEMORY_WRITE_LENGTH(&MEMORY, NULL, 0);
    }
}

/* EVALUATE THE LENGTH OF THE MEMORY ALLOCATION POOL BASED ON THE FUNCTION ABOVE */

STATIC
void MEMORY_WRITE_LENGTH(MEMORY* MEMORY, const char* BUFFER, UNK* SIZE)
{
    if(MEMORY->ERROR == MEMORY_OK)
    {
        if(MEMORY->WRITE(sizeof(BUFFER), 1, SIZE, sizeof(MEMORY) < SIZE))
        {
            MEMORY->ERROR = 1;
        }

        return NULL;
    }
}

/* EVALUATE THE CURRENT MEMORY ALLOCATION BASED ON THE SIZE OF THE SCOPE */
/* THIS IS BY ASSUMING THE CURRENT CONTEXT BY WHICH THE HEAP IS LOOKING AT */

/* IF THERE IS NO DISCERNABLE SCOPE BEING ASSUMED, AN ERROR CHECK WILL BE PASSED */
/* TO ENSURE THAT IF ANYTHING SHOULD GO WRONG, IT CAN FALL BACK ON THE CURRENT EVENT */

STATIC
SCOPE* CURRENT_MEMORY_SCOPE(MEMORY* MEMORY)
{
    if(MEMORY->ERROR == MEMORY_WRITE_ERROR)
    {
        if(MEMORY->SCOPE_SIZE >= 0)
        {
            return &MEMORY->SCOPES[MEMORY->SCOPE_SIZE - 1];
        }
    }
}

#endif
