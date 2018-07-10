#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "empleado.h"

// funciones privadas
int resizeUp(ArrayList* this);
int expand(ArrayList* this,int index);
int contract(ArrayList* this,int index);

#define AL_INCREMENT      10
#define AL_INITIAL_VALUE  10
//___________________

/** \brief Allocate a new arrayList with AL_INITIAL_VALUE elements.
 * \param void
 * \return ArrayList* Return (NULL) if Error [if can't allocate memory]
 *                  - (pointer to new arrayList) if ok
 */
ArrayList* al_newArrayList(void)
{
    ArrayList* this;
    ArrayList* returnAux = NULL;
    void* pElements;
    this = (ArrayList *)malloc(sizeof(ArrayList));

    if(this != NULL)
    {
        pElements = malloc(sizeof(void *)*AL_INITIAL_VALUE );
        if(pElements != NULL)
        {
            this->size=0;
            this->pElements=pElements;
            this->reservedSize=AL_INITIAL_VALUE;
            this->add=al_add;
            this->len=al_len;
            this->set=al_set;
            this->remove=al_remove;
            this->clear=al_clear;
            this->clone=al_clone;
            this->get=al_get;
            this->contains=al_contains;
            this->push=al_push;
            this->indexOf=al_indexOf;
            this->isEmpty=al_isEmpty;
            this->pop=al_pop;
            this->subList=al_subList;
            this->containsAll=al_containsAll;
            this->deleteArrayList = al_deleteArrayList;
            this->sort = al_sort;
            this->generarSueldo= al_map;
            returnAux = this;
        }
        else
        {
            free(this);
        }
    }

    return returnAux;
}


/** \brief  Add an element to arrayList and if is
 *          nessesary resize the array
 * \param pList ArrayList* Pointer to arrayList
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer] - (0) if Ok
 *
 */
int al_add(ArrayList* this, void* pElement)
{
    int returnAux=-1;
    int okResize;
    if(this!=NULL&&pElement!=NULL)
    {
        if(this->size==this->reservedSize)
        {
            okResize=resizeUp(this);
            if(!okResize)
            {
                printf("no se pudo encontrar espacio");
                return 0;
            }
        }
        *(this->pElements + this->size)=pElement;
        this->size++;
        returnAux = 0;
    }
    return returnAux;
}

/** \brief  Delete arrayList
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer] - (0) if Ok
 *
 */
int al_deleteArrayList(ArrayList* this)
{
    //free pElements free this
    int returnAux = -1;
    if(this!=NULL)
    {
        if(this->size==0)
        {
            returnAux=0;
        }
        else
        {
            returnAux=1;
        }
            free(this->pElements);
            free(this);
    }
    return returnAux;
}

/** \brief  Delete arrayList
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return length of array or (-1) if Error [pList is NULL pointer]
 *
 */
int al_len(ArrayList* this)
{
    int returnAux = -1;
    if(this!=NULL)
    {
        returnAux =this->size;
    }

    return returnAux;
}


/** \brief  Get an element by index
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return void* Return (NULL) if Error [pList is NULL pointer or invalid index] - (Pointer to element) if Ok
 *
 */
void* al_get(ArrayList* this, int index)
{
    void* returnAux = NULL;

    if(this!=NULL&&index>=0&&index<this->len(this))
    {
        returnAux=this->pElements[index];
    }

    return returnAux;
}


/** \brief  Find if pList contains at least one element pElement
 * \param pList ArrayList* Pointer to arrayList
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer]
 *                  - ( 0) if Ok but not found a element
 *                  - ( 1) if this list contains at least one element pElement
 *
 */
int al_contains(ArrayList* this, void* pElement)
{
    int returnAux = -1;
    int i;
    if(this!=NULL && pElement!=NULL)
    {
        for(i=0;i<(this->len(this));i++)
        {
            returnAux=0;
            if(*(this->pElements+i)==pElement)
            {
                returnAux = 1;
                break;
            }
        }
    }

    return returnAux;
}


/** \brief  Set a element in pList at index position
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer or invalid index]
 *                  - ( 0) if Ok
 *
 */
int al_set(ArrayList* this, int index,void* pElement)
{
    int returnAux = -1;
    if(this!=NULL && pElement!=NULL && index>=0)
    {
        if(index==this->len(this))
        {
            if(this->add(this,pElement)==0)
            {
                returnAux=0;
            }
        }
        else
        {
            if(index<this->size)
            {
                this->pElements[index]=pElement;
                returnAux=0;
            }
        }
    }
    return returnAux;
}


/** \brief  Remove an element by index
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (-1) if Error [pList is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int al_remove(ArrayList* this,int index)
{
    int returnAux = -1;
    void* aux;
    if(this!=NULL && index>=0 && index<this->len(this))
    {
        aux=this->get(this,index);
         if(contract(this, index)==0)
         {
            returnAux=0;
         }
    }
    return returnAux;
}



/** \brief Removes all of the elements from this list
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer]
 *                  - ( 0) if Ok
 */
int al_clear(ArrayList* this)
{
    int returnAux = -1;
    if(this!=NULL)
    {
        this->pElements=(void**)realloc(this->pElements, sizeof(void*)*AL_INITIAL_VALUE);
        this->size=0;
        this->reservedSize=AL_INITIAL_VALUE;
        returnAux=0;
    }

    return returnAux;

}



/** \brief Returns an array containing all of the elements in this list in proper sequence
 * \param pList ArrayList* Pointer to arrayList
 * \return ArrayList* Return  (NULL) if Error [pList is NULL pointer]
 *                          - (New array) if Ok
 */
ArrayList* al_clone(ArrayList* this)
{

    ArrayList* returnAux = NULL;
    int i;
    void* elementAux;
    if(this!=NULL)
    {
        returnAux=al_newArrayList();

        for(i=0; i<this->len(this) ; i++)
        {
            elementAux=this->get(this,i);
            returnAux->add(returnAux,elementAux);
        }
    }
    return returnAux;
}




/** \brief Inserts the element at the specified position
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int al_push(ArrayList* this, int index, void* pElement)
{
    int returnAux = -1;
    if(this!=NULL && pElement!=NULL && index>=0 )
    {
        if(index == this->len(this) )
        {
            if(this->add(this,pElement)==0)
            {
                returnAux=0;
            }
        }
        else
            {
                if(index<this->len(this))
                {
                    if(expand(this,index)==0)
                    {
                        if(this->set(this,index,pElement)==0)
                        {
                            returnAux=0;
                        }
                    }
                }
            }
    }

    return returnAux;
}



/** \brief Returns the index of the first occurrence of the specified element
 * \param pList ArrayList* Pointer to arrayList
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer] - (index to element) if Ok
 */
int al_indexOf(ArrayList* this, void* pElement)
{
    int returnAux = -1;
    int i;

    if(this!=NULL && pElement!=NULL)
    {
        for(i=0;i<this->len(this); i++)
        {
            if(this->get(this,i)==pElement)
            {
                returnAux=i;
                break;
            }
        }
    }

    return returnAux;
}



/** \brief Returns true if this list contains no elements.
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer] - (0) if Not Empty - (1) if is Empty
 */
int al_isEmpty(ArrayList* this)
{
    int returnAux = -1;

    if(this!=NULL)
    {
        if(this->len(this) > 0 )
        {
            returnAux=0;
        }
        else
        {
            returnAux=1;
        }
    }

    return returnAux;
}




/** \brief Remove the item at the given position in the list, and return it.
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (NULL) if Error [pList is NULL pointer or invalid index]
 *                  - ( element pointer) if Ok
 */
void* al_pop(ArrayList* this,int index)
{
    void* returnAux = NULL;

    if(this!=NULL && index>=0 && index<this->len(this))
    {

        returnAux=this->get(this,index);
        contract(this,index);
        if(this->reservedSize-this->len(this)>AL_INCREMENT)
            {
                this->pElements =(void**)realloc(this->pElements,sizeof(void*)*(this->reservedSize-AL_INCREMENT));
            }
    }

    return returnAux;
}


/** \brief Returns a new arrayList with a portion of pList between the specified
 *         fromIndex, inclusive, and toIndex, exclusive.
 * \param pList ArrayList* Pointer to arrayList
 * \param from int Initial index of the element (inclusive)
 * \param to int Final index of the element (exclusive)
 * \return int Return (NULL) if Error [pList is NULL pointer or invalid 'from' or invalid 'to']
 *                  - ( pointer to new array) if Ok
 */
ArrayList* al_subList(ArrayList* this,int from,int to)
{
    ArrayList* returnAux = NULL;
    int i;
    void* elementAux;
    void** aux;
    if(this!=NULL && from>=0 && to<=this->len(this) && from<to )
    {

        returnAux=al_newArrayList();

        if(returnAux!=NULL)
        {
             for(i=from;i<to;i++)
            {
                elementAux=this->get(this,i);
                returnAux->add(returnAux,elementAux);
            }
            // resizeDOWN reserverdsize-size>increment
            /*
            if(this->reserverdSize-this->len(this)>AL_INCREMENT)
            {
                returnAux->pElements =(void**)realloc(returnAux->pElements,sizeof(void*)*(returnAux->reservedSize-AL_INCREMENT));
            }
            */
        }

    }
    return returnAux;
}

/** \brief Returns true if pList list contains all of the elements of pList2
 * \param pList ArrayList* Pointer to arrayList
 * \param pList2 ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList or pList2 are NULL pointer]
 *                  - (0) if Not contains All - (1) if is contains All
 */
int al_containsAll(ArrayList* this,ArrayList* this2)
{
    int returnAux = -1;
    int i;
    if(this!=NULL && this2!=NULL)
    {

        for(i=0;i<(this->len(this));i++)
        {
            if(*(this->pElements+i)==*(this2->pElements+i))
            {
                returnAux = 1;
            }
            else
            {
                returnAux=0;
                break;
            }
        }
    }

    return returnAux;
}

/** \brief Sorts objects of list, use compare pFunc
 * \param pList ArrayList* Pointer to arrayList
 * \param pFunc (*pFunc) Pointer to fuction to compare elements of arrayList
 * \param order int  [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [pList or pFunc are NULL pointer]
 *                  - (0) if ok
 */
int al_sort(ArrayList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux = -1;
    void* pElementAux=NULL;
    void* p1;
    void* p2;
    int i,j;
    if(this!=NULL && pFunc!=NULL && (order==1 || order==0))
    {
        for(i=0;i<this->len(this)-1;i++)
        {
            for(j=i+1;j<this->len(this);j++)
            {
                p1=this->get(this,i);
                p2=this->get(this,j);
                if(order==1)
                {
                    if(pFunc(p1,p2)==1)
                    {
                        pElementAux=this->get(this,i);
                        this->set(this,i,this->get(this,j));
                        this->set(this,j,pElementAux);
                    }
                }
                else
                {
                    if(pFunc(p1,p2)==-1)
                    {
                        pElementAux=this->get(this,i);
                        this->set(this,i,this->get(this,j));
                        this->set(this,j,pElementAux);
                    }
                }
            }
        }
        returnAux=0;
    }
    return returnAux;
}


/** \brief Increment the number of elements in pList in AL_INCREMENT elements.
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer or if can't allocate memory]
 *                  - (0) if ok
 */
int resizeUp(ArrayList* this)
{
    int returnAux = -1;
    void** aux;
    if(this!=NULL)
    {
        aux =(void**)realloc(this->pElements,sizeof(void*)*(this->reservedSize+AL_INCREMENT));
        if(aux==NULL)
        {
            printf("no se pudo conseguir lugar \n");
            returnAux= -1;
        }
        else
        {
            this->pElements=aux;
            this->reservedSize+=AL_INCREMENT;

        }
    }

    return returnAux;

}

/** \brief  Expand an array list
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (-1) if Error [pList is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int expand(ArrayList* this,int index)
{
    int returnAux = -1;
    int i;
    if(this!=NULL)
    {
            this->size++;
            resizeUp(this);
            for(i=this->len(this) ; i>index ; i--)
            {
                this->pElements[i]=this->pElements[i-1];
            }
            returnAux=0;
    }

    return returnAux;
}

/** \brief  Contract an array list
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (-1) if Error [pList is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int contract(ArrayList* this,int index)
{
    int returnAux = -1;
    int i;
    if(this!=NULL && index>=0 && index<this->len(this))
    {
        for(i=index ; i< (this->len(this)-1) ; i++)
        {
            this->pElements[i]=this->pElements[i+1];
        }
        this->size-=1;
        returnAux=0;
    }

    return returnAux;
}


int al_map(ArrayList *listaEmpleados,int (*cSueldo)(void*))
{
    int i;
    void* persona;
    int retornoAux=-1;
    if(listaEmpleados!=NULL && cSueldo!=NULL )
    {
        for(i=0;i<listaEmpleados->len(listaEmpleados); i++)
            {
                persona=listaEmpleados->get(listaEmpleados,i);
                cSueldo(persona);
            }
            retornoAux=0;
    }
    return retornoAux;
}

