#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <direct.h>
#include "model/mnist.h"

void print_data(float data[1][784], int expected)
{
    int col = 0;
    for(int index = 0; index<784; index++)
    {
        printf("%f", data[0][index]);
        col++;
        if (col == 28)
        {
            printf("\n");
            col = 0;
        }
    }
    printf("\n");
    printf("Expected: %d\n", expected);
}

void predict(float data[1][784], int expected)
{
    float output[1][10]; 
    entry(data, output);

    char predictions_str[1024]; 
    char predictions_buffer[1024];
    printf("Expected: %d\n", expected);
    for (int x=0; x<10; x++)
    {
        printf("%f ", output[0][x]);
        
        gcvt(output[0][x], 7, predictions_buffer);
        strcat(predictions_str, predictions_buffer);
        strcat(predictions_str, ", ");
    }
    printf("\n");

    float max = -1;
    int index = 0; 


    for (int x=0; x<10; x++)
    {
        if (output[0][x] > max)
        {
            max = output[0][x];
            index = x;
        }
    }
    printf("Predicted: %d\n", index);

    // Write to CSV File
    FILE *fpt;
    fpt = fopen("..\\predictions\\c_inferences.csv", "a");
    fprintf(fpt, "%d, %d, %s\n", expected, index, predictions_str);
    fclose(fpt);

}

void process_txt_data(char dataset[])
{
    if (strcmp(dataset, "training") == 0 || strcmp(dataset, "validation") == 0)
    {
        char original_path[200];
        _getcwd(original_path, 200);

        char path[] = "..\\txt_data\\";
        strcat(path, dataset);

        _chdir(path);
        char current_path[200];
        _getcwd(current_path, 200);

        //printf("CWD: %s\n", current_path);
        strcat(current_path, "\\*.txt");

        WIN32_FIND_DATA FindFileData;
        HANDLE hFind;

        hFind = FindFirstFile(current_path, &FindFileData);
        if (hFind == INVALID_HANDLE_VALUE) 
        {
            printf ("FindFirstFile failed (%d)\n", GetLastError());
            exit(-1);
        } 
        else 
        {
            do
            {
                printf("\n");
                //printf("Processing File: %s\n", FindFileData.cFileName);
                FILE *fpt;
                fpt = fopen(FindFileData.cFileName, "r");
                
                if (fpt==NULL)
                {
                    printf("Something Failed opening the file %s", FindFileData.cFileName);  
                }
                else
                {
                    char str[1024];
                    float data[1][784];
                    int index = 0;
                    int scan_read;
                    int expected;

                    while (fgets(str, 1024, fpt) != NULL)
                    {
                        if (index == 784)
                        {
                            sscanf(str, "%d", &expected);
                        }
                        else
                        {
                            scan_read = sscanf(str, "%f", &data[0][index]);  
                        }
                        index++;
                    }
                    //print_data(data, expected);
                    predict(data, expected);
                    fclose(fpt);
                }
            } while (FindNextFile(hFind, &FindFileData));
            FindClose(hFind);
        }
        chdir(original_path);
    }
    else
    {
        printf("The read dataset argument of the read_data function requires either 'training' or 'validation'.");
        exit(-1);
    }
}

int main()
{
    process_txt_data("training");
    process_txt_data("validation");
    
    char ch;
    ch = fgetc(stdin);
    exit(EXIT_SUCCESS);
}