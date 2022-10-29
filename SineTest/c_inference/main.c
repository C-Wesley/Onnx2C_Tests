#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <direct.h>
#include "model/sine.h"

void get_data_from_txt(float data[1000], int *num_values)
{

    char path[] = "..\\txt_data\\x_values.txt";

    FILE *fpt;
    fpt = fopen(path, "r");

    if (fpt==NULL)
    {
        printf("Something failed opening the file %s", path);
    }
    else
    {
        char str[1024];
        int index = 0;

        while (fgets(str, 1024, fpt) != NULL)
        {
            sscanf(str, "%f", &data[index]);
            index ++;
        }
        *num_values = index;
        fclose(fpt);
    }
}

void make_predictions(float data[1000], float predictions[1000], int *num_values)
{
    float input[1]; 
    float prediction[1][1]; 
    for (int n=0; n<*num_values; n++)
    {
        input[0] = data[n]; 
        entry(input, prediction);
        predictions[n] = prediction[0][0]; 
    }
}

int main()
{
    int num_values; 
    float data[1000];
    get_data_from_txt(data, &num_values);
    float predictions[1000];
    make_predictions(data, predictions, &num_values);

    for (int j = 0; j<num_values; j++)
    {
        printf("Input: %f\n", data[j]);
        printf("Output: %f\n", predictions[j]);
        printf("\n");
    }

    getchar();
    return 0;
}
