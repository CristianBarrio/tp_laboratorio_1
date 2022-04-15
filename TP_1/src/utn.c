#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

int menu(int x, int y, int z)
{
    int opcion;

    printf("1. Ingresar Kilometros: (%d KM)\n", x);
    printf("2. Ingresar Precio de Vuelos: (Aerolineas = y, Latam = z)\n");
    printf("  - Precio vuelo Aerolineas: $%d\n", y);
    printf("  - Precio vuelo Latam: $%d\n", z);
    printf("3. Calcular todos los costos: \n"
           "   a) Tarjeta de debito (descuento 10 por ciento)\n"
           "   b) Tarjeta de credito (interes 25 por ciento)\n"
           "   c) Bitcoin (1 BTC -> 4606954.55 Pesos Argentinos)\n"
           "   d) Mostrar precio por km (precio unitario)\n"
           "   e) Mostrar diferencia de precio ingresada (Latam - Aerolineas)\n");
    printf("4. Informar Resultados\n");
    printf("5. Carga forzada de datos\n");
    printf("6. Salir\n");

    printf("Ingrese una opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

int ingresarKm(int* x)
{
    int retorno;

    printf("Ingrese los kilometros del vuelo: ");
    scanf("%d", &(*x));

    if(*x <= 0)
    {
        printf("\nDato invalido.\n");
        retorno = 0;
    }else
    {
        retorno = 1;
    }

    return retorno;
}

void menuPrecios(int* precioAerolineas, int* precioLatam, int* flagAerolineas, int* flagLatam)
{
    char aerolinea;

    printf("Ingrese la empresa de viajes: ");
    fflush(stdin);
    scanf("%c", &aerolinea);

    if(aerolinea == 'y')
    {
        if(ingresarPrecio(precioAerolineas))
        {
            *flagAerolineas = 1;
        }

    }else if(aerolinea == 'z')
    {
        if(ingresarPrecio(precioLatam))
        {
            *flagLatam = 1;
        }
    }else
    {
        printf("Empresa incorrecta.\n");
    }

}

int ingresarPrecio(int* precio)
{
    int retorno = 0;

    printf("Ingrese el precio del vuelo: ");
    scanf("%d", &(*precio));

    if(*precio <= 0)
    {
        printf("Precio invalido.\n");
    }else
    {
        printf("Valor ingresado correctamente.\n");
        retorno = 1;
    }

    return retorno;
}

void mostrarResultadosAerolineas(int km, int precio, float debito, float credito, float btc, float unitario)
{
    printf("KMs Ingresados: %dkm\n\n", km);

    printf("Precio Aerolineas: $%d\n", precio);
    printf("a) Precio con tarjeta de debito: $%.2f\n", debito);
    printf("b) Precio con tarjeta de credito: $%.2f\n", credito);
    printf("c) Precio pagando con Bitcoin: %.6f BTC\n", btc);
    printf("d) Precio unitario: $%.2f\n\n", unitario);

}

void mostrarResultadosLatam(int precio, float debito, float credito, float btc, float unitario, float diferencia)
{
    printf("Precio Latam: $%d\n", precio);
    printf("a) Precio con tarjeta de debito: $%.2f\n", debito);
    printf("b) Precio con tarjeta de credito: $%.2f\n", credito);
    printf("c) Precio pagando con Bitcoin: %.6f BTC\n", btc);
    printf("d) Precio unitario: $%.2f\n\n", unitario);

    printf("La diferencia de precio es: $%.2f\n", diferencia);
}


