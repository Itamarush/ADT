#include "AdptArray.h"
#include <stdio.h>
#include <stdlib.h>

struct AdptArray_ {
    PElement *elementArray;
    int capacity;
    PRINT_FUNC printFun;
    COPY_FUNC copyFun;
    DEL_FUNC deleteFun;
};

PAdptArray CreateAdptArray(COPY_FUNC copy, DEL_FUNC delete, PRINT_FUNC print)
{
    PAdptArray pAdptArray = (PAdptArray) malloc(sizeof(struct AdptArray_));
    if (!pAdptArray)
        {
            return NULL;
        }

    pAdptArray->elementArray = NULL;
    pAdptArray->capacity = 0;
    pAdptArray->copyFun = copy;
    pAdptArray->deleteFun = delete;
    pAdptArray->printFun = print;
    return pAdptArray;
}

void DeleteAdptArray(PAdptArray arrToDelete)
{
    if (!arrToDelete)
    {
        // it means the argument is NULL so just return;
        return;
    }

    for (size_t i = 0; i < arrToDelete->capacity; i++)
    {
        if (arrToDelete->elementArray[i])
        {
            arrToDelete->deleteFun(arrToDelete->elementArray[i]);
        }
        
    }
    free(arrToDelete);
}

void PrintDB(PAdptArray arrToPrint)
{
    // if the array is a valid address than just call for the print function for every element using for loop 
    if (!arrToPrint) 
    {
        return;
    }
    
    for (size_t i = 0; i < arrToPrint->capacity; i++)
    {
        if (arrToPrint->elementArray[i] != NULL)
        {
            arrToPrint->printFun(arrToPrint->elementArray[i]);
        }
    }
}

int GetAdptArraySize(PAdptArray arrGetSize)
{   
    // if the array is a valid address than just return the array capacity
    if (arrGetSize == NULL)
    {
        return -1;
    }

    return arrGetSize->capacity;
}

PElement GetAdptArrayAt(PAdptArray array, int index)
{
    // if the array is a valid address && index is positive && index is smaller than capacity than just return
    // the element using the copy function
    if (array == NULL || index < 0 || index >= array->capacity || array->elementArray[index] == NULL) 
    {
        return NULL;
    }
    
    return array->copyFun(array->elementArray[index]);
}

Result SetAdptArrayAt(PAdptArray arrayToSet, int index, PElement element)
{
    // if the array is not an address or the index is negative
    if (!arrayToSet || index < 0)
    {
        return FAIL;
    }

    // if the given index is bigger than the current array capacity
    if (arrayToSet->capacity <= index)
    {

        arrayToSet->elementArray = (PElement*) realloc (arrayToSet->elementArray, (index+1)*sizeof(element));

        if (arrayToSet->elementArray == NULL)
        {
            return FAIL;
        }
            
        for (size_t i = arrayToSet->capacity ; i < index + 1; i++)
        {
            arrayToSet->elementArray[i] = NULL;
        }
        arrayToSet->capacity = index + 1; 

    if (arrayToSet->elementArray[index] != NULL)
    {
        arrayToSet->deleteFun(arrayToSet->elementArray[index]);
    }

    arrayToSet->elementArray[index] = arrayToSet->copyFun(element);
    return SUCCESS;
    }
}
