#include <stdio.h>
#include <stdlib.h>
#include "calcular.h"

float calcularCostoDebito(int num, float* resultado)
{
    *resultado = (float) num - (num * 10 / 100);
    return *resultado;
}

float calcularCostoCredito(int num, float* resultado)
{
    *resultado = (float) num + num * 25 / 100;

    return *resultado;
}

float calcularCostoBtc(int num, float* resultado)
{
    *resultado = (float) num / 4606954.55;

    return *resultado;
}

float calcularCostoUnitario(int num, int km, float* resultado)
{
    *resultado = (float) num / km;

    return *resultado;
}

int calcularDiferencia(int num1, int num2, int* resultado)
{
    if(num1 > num2)
    {
        *resultado = num1 - num2;
    }else
    {
        *resultado = num2 - num1;
    }

    return *resultado;
}

