#include <stdio.h>
#include <stdlib.h>
#include "calcular.h"

void calcularCostoDebito(int num, float* resultado)
{
    *resultado = (float) num - (num * 10 / 100);
}

void calcularCostoCredito(int num, float* resultado)
{
    *resultado = (float) num + num * 25 / 100;

}

void calcularCostoBtc(int num, float* resultado)
{
    *resultado = (float) num / 4606954.55;

}

void calcularCostoUnitario(int num, int km, float* resultado)
{
    *resultado = (float) num / km;

}

void calcularDiferencia(int num1, int num2, int* resultado)
{
    if(num1 > num2)
    {
        *resultado = num1 - num2;
    }else
    {
        *resultado = num2 - num1;
    }

}

