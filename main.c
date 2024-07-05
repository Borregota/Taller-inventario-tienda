#include <stdio.h>
#include "funcioneslol.h"

#define tamanomatriz 10

int main(int argc, char const *argv[])
{
    char productoABus[30];
    int opcion1, opcion2;
    int tam = tamanomatriz; // crear variable para almacenar tamaño de la matriz

    char Nproducto[tam][30];
    float cantidadPrecio[tam][2];

    cargarProductos("productos.txt", Nproducto, cantidadPrecio, &tam);

    do
    {
        printf("Seleccione una opcion: \n1. Ingresar Productos\n2. Imprimir productos\n3. Buscar Producto\n4. Editar Producto\n5. Eliminar Producto\n>>");
        scanf("%d", &opcion1);
        switch (opcion1)
        {
        case 1:
            ingresarProductos(Nproducto, cantidadPrecio, tam);
            guardarProductos("productos.txt", Nproducto, cantidadPrecio, tam);
            break;
        case 2:
            imprimirProductos(Nproducto, cantidadPrecio);
            break;
        case 3:
            printf("Ingrese el nombre del producto a buscar: \n>>");
            fflush(stdin);
            scanf("%s", productoABus);
            int *indices = buscarProductoXNom(Nproducto, productoABus, tam);
            imprimirProductoXIndex(productoABus, Nproducto, cantidadPrecio, indices);
            break;
        case 4:
            editarProducto(Nproducto, cantidadPrecio, tam);
            guardarProductos("productos.txt", Nproducto, cantidadPrecio, tam);
            break;
        case 5:
            eliminarProducto(Nproducto, cantidadPrecio, tam);
            guardarProductos("productos.txt", Nproducto, cantidadPrecio, tam);
            break;
        default:
            break;
        }
        printf("Desea elegir una nueva opcion: 1.si / 2.No\n>>");
        scanf("%d",&opcion2);
    } while (opcion2 == 1);
    return 0;
}
