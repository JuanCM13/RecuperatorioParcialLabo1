#include "eLocalidad.h"
/*
int inicializarArrayLocalidades(eLocalidad lista[] , int rango)
{
    int ret;
    int i;

    ret = -1;

    if(lista != NULL && rango > 0)
    {
        ret = 0;

        for(i=0 ; i<rango ; i++)
        {
            lista[i].isEmpty = 1;
        }
    }

    return ret;
}

//------------------------------------------------------------------------------

int isEmptyLocalidades(eLocalidad lista[] , int rango)
{
    int i;
    int ret;

    ret = -1;

    if(lista != NULL && rango > 0)
    {
        for(i=0 ; i<rango ; i++)
        {
            if(lista[i].isEmpty == 0)
            {
                ret = 0;
                break;
            }
        }
    }

    return ret;
}


//------------------------------------------------------------------------------

int hayLugarLocalidades(eLocalidad lista[] , int rango)
{
    int i;
    int ret;

    ret = -1;

    if(lista != NULL && rango > 0)
    {
        for(i=0 ; i<rango ; i++)
        {
            if(lista[i].isEmpty == 1)
            {
                ret = 0;
                break;
            }
        }
    }

    return ret;
}


//------------------------------------------------------------------------------

int getIndexLocalidad(eLocalidad lista[] , int rango)
{
    int i;
    int ret;

    ret = -1;

    if(lista != NULL && rango > 0)
    {
        for(i=0 ; i<rango ; i++)
        {
            if(lista[i].isEmpty == 1)
            {
                ret = i;
                break;
            }
            else
            {
                ret = -2;
            }
        }
    }

    return ret;

}*/

int getIndexLocalidadIdRelacion(eLocalidad lista[] , int rango , int idRelacion)
{
    int i;
    int ret;

    ret = -1;

    if(lista != NULL && rango > 0)
    {
        for(i=0 ; i<rango ; i++)
        {
            if(lista[i].isEmpty == 0)
            {
                if(lista[i].idLocalidad == idRelacion)
                {
                    ret = i;
                    break;
                }
            }
            else
            {
                ret = -2;
            }
        }
    }

    return ret;

}
