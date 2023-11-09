#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max_columnas 3200  
#define filas_a_procesar 50
#define longitud_maxima_linea 65001

int main() {
    FILE *csv = fopen("emails.csv", "r");
    if (!csv) 
	{
        perror("Error al abrir tu cosota CSV");
        return 1;
    }

    char buffer[longitud_maxima_linea];
    char *palabras[max_columnas];
    int conteo[max_columnas]={0};
    int id=626; 

    if (fgets(buffer, sizeof(buffer), csv)) 
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

    for (int fila = 0; fila <= id && fgets(buffer, sizeof(buffer), csv); ++fila) {
    }

    for (int fila = 0; fila < filas_a_procesar && fgets(buffer, sizeof(buffer), csv); ++fila) 
	{
        char *token = strtok(buffer, ",");
        int col = 0;
        while (token && col < max_columnas) 
		{
            conteo[col] += atoi(token);  
            token = strtok(NULL, ",");
            col++;
        }
    }

    fclose(csv);

    FILE *salida = fopen("181626.txt", "w");
    if (!salida) 
	{
        perror("Error al abrir el archivo de salida");
        for (int i = 0; i < max_columnas; i++) 
		{
            free(palabras[i]);
        }
        return 1;
    }

    for (int i = 0; i < max_columnas && palabras[i] != NULL; i++) 
	{
        fprintf(salida, "%s, %d\n", palabras[i], conteo[i]);
        free(palabras[i]); 
    }

    fclose(salida);
    printf("Tu cosota esta justamente y directamente aqui 181626.txt\n");

    return 0;
}
