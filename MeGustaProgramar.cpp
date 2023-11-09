#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max_columnas 3050
#define filas_a_procesar 50
#define longitud_maxima_linea 1000000
#define buffer_size 1024

int main() {
    int i;
    int fila;

    const char *nombre_archivo_csv = "emails.csv";
    FILE *archivo_csv = fopen(nombre_archivo_csv, "r");
    if (!archivo_csv) 
	{
        perror("error al abrir el archivo csv");
        return 1;
    }

    char buffer[longitud_maxima_linea];
    int conteo[max_columnas] = {0};
    char *palabras[max_columnas];
    int identificador = 625;
    int columna_email_no = -1;

    if (fgets(buffer, sizeof(buffer), archivo_csv) != NULL) 
	{
        char *token = strtok(buffer, ",");
        int col = 0;
        while (token && col <= max_columnas) 
		{
            palabras[col] = strdup(token);
            token = strtok(NULL, ",");
            col++;
        }
    }

    for (fila = 0; fila <= identificador && fgets(buffer, sizeof(buffer), archivo_csv); ++fila) 
	{
    }

    for (fila = 0; fila < filas_a_procesar && fgets(buffer, sizeof(buffer), archivo_csv); ++fila) 
	{
        char *token = strtok(buffer, ",");
        int col = 0;
        while (token && col < max_columnas)
		 {
            if (col == columna_email_no) 
			{
            } 
			else {
                conteo[col] += atoi(token);
            }
            token = strtok(NULL, ",");
            col++;
        }
    }

    fclose(archivo_csv);

    FILE *salida = fopen("181626.txt", "w");
    if (!salida) 
	{
        perror("error al abrir el archivo de salida");
        for (i = 0; i < max_columnas; i++) 
		{
            free(palabras[i]);
        }
        return 1;
    }

    for (i = 0; i < max_columnas && palabras[i] != NULL; i++) 
	{
        fprintf(salida, "%s, %d\n", palabras[i], conteo[i]);
        free(palabras[i]);
    }

    fclose(salida);
    printf("tu cosota esta justamente y directamente aqui: 181626.txt\n");

    return 0;
}

