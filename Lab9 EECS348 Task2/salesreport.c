#include <stdio.h>
char *months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

void monthlySalesReport(double salesArray[]) {
    printf("Month\t\t\tSales\n");
    for (int i = 0; i <= 11; i++) {
        if (strlen(months[i]) > 7) {
            printf("%s\t\t$%.2lf\n", months[i], salesArray[i]);
        }
        else {
            printf("%s\t\t\t$%.2lf\n", months[i], salesArray[i]);
        }
    }
}

void salesSummary(double salesArray[]) {
    double max = 0;
    char *maxMonth = " ";
    for (int i = 0; i <= 11; i++) {
        if (salesArray[i] >= max) {
            max = salesArray[i];
            maxMonth = months[i];
        }
    }

    double min = salesArray[0];
    char *minMonth = " ";
    for (int i = 0; i <= 11; i++) {
        if (salesArray[i] <= min) {
            min = salesArray[i];
            minMonth = months[i];
        }
    }
    
    double sum = 0;
    for (int i = 0; i <= 11; i++) {
        sum += salesArray[i];
    }
    double average = (sum / 12);
    printf("\nSales summary:\n");
    printf("Minimum sales:\t$%.2lf\t%s\n", min, minMonth);
    printf("Maximum sales:\t$%.2lf\t%s\n", max, maxMonth);
    printf("Average sales:\t$%.2lf\t\n", average);
}

void sixMonthMovingAverageReport(double salesArray[]) {
    printf("\nSix-Month Moving Average Report:\n");
    double sum = 0;
    double average = 0;
    double sixMonthReport[7];
    for (int i = 0; i <= 6; i++) {
        sum = 0;
        average = 0;
        for (int j = i + 5; j >= i; j--) {
            sum += salesArray[j];
        }
        average = sum / 6;
        if (strlen(months[i]) == 8) {
            printf("%s\t-  %s\t\t$%.2lf\n", months[i], months[i+5], average);
        }
        else if (strlen(months[i]) == 7) {
            printf("%s\t\t-  %s\t\t$%.2lf\n", months[i], months[i+5], average);
        }
        else {
            printf("%s\t\t-  %s\t$%.2lf\n", months[i], months[i+5], average);
        }
    }
    printf("\n");
}

void highToLowReport(double salesArray[]) {
    printf("Sales Report (Highest to Lowest):\n");
    printf("Month\t\t\tSales\n");
    int salesOrdered[12];
    for (int i = 0; i < 12; i++) {
        salesOrdered[i] = i;
    }

    for (int i = 0; i < 11; i++) {
        for (int j = i + 1; j < 12; j++) {
            if (salesArray[salesOrdered[i]] < salesArray[salesOrdered[j]]) {
                int temp = salesOrdered[i];
                salesOrdered[i] = salesOrdered[j];
                salesOrdered[j] = temp;
            }
        }
    }

    for (int k = 0; k <= 11; k++) {
        int index = salesOrdered[k];
        if (strlen(months[index]) < 7){
            printf("%s \t\t\t$%.2lf \n", months[index], salesArray[index]);
        }
        else {
            printf("%s \t\t$%.2lf \n", months[index], salesArray[index]);
        }
    }
}

int main()
{
    double monthlySales[12] = {23458.01, 40112.00, 56011.85, 37820.88, 37904.67, 60200.22, 72400.31, 56210.89, 67230.84, 68233.12, 80950.34, 95225.22};
    monthlySalesReport(monthlySales);
    salesSummary(monthlySales);
    sixMonthMovingAverageReport(monthlySales);
    highToLowReport(monthlySales);

    return 0;
}