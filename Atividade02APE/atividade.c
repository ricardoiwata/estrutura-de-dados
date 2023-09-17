#include <stdio.h>
#include <string.h>

void swap(char *arr[], int i, int j)
{
    char *temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int findMedian(char *arr[], int low, int high)
{
    int mid = (low + high) / 2;

    if (strcmp(arr[low], arr[mid]) > 0)
    {
        swap(arr, low, mid);
    }

    if (strcmp(arr[mid], arr[high]) > 0)
    {
        swap(arr, mid, high);
    }

    return mid;
}

void quicksort(char *arr[], int low, int high, int *comparisons, int *swaps)
{
    if (low < high)
    {
        int pivotIndex = findMedian(arr, low, high);
        char *pivot = arr[pivotIndex];

        int i = low - 1;
        for (int j = low; j < high; j++)
        {
            (*comparisons)++;
            if (strcmp(arr[j], pivot) < 0)
            {
                i++;
                (*swaps)++;
                swap(arr, i, j);
            }
        }
        (*swaps)++;
        swap(arr, i + 1, high);

        quicksort(arr, low, i, comparisons, swaps);
        quicksort(arr, i + 2, high, comparisons, swaps);
    }
}

int main()
{
    char *arr[20] = {
        "maca", "banana", "pera", "uva", "laranja", "abacaxi", "limao", "manga", "abacate", "kiwi",
        "cereja", "morango", "pessego", "goiaba", "melancia", "framboesa", "amora", "caqui", "figo", "papaya"};

    int comparisons = 0;
    int swaps = 0;

    int n = sizeof(arr) / sizeof(arr[0]);

    quicksort(arr, 0, n - 1, &comparisons, &swaps);

    printf("Vetor Ordenado:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%s\n", arr[i]);
    }

    FILE *outputFile;
    outputFile = fopen("output.txt", "w");
    for (int i = 0; i < n; i++)
    {
        fprintf(outputFile, "%s\n", arr[i]);
    }
    fclose(outputFile);

    printf("\nNumero de Comparacoes: %d\n", comparisons);
    printf("Numero de Trocas: %d\n", swaps);

    char *median = arr[n / 2];
    printf("\nMediana: %s\n", median);

    return 0;
}
