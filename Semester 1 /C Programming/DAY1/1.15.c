// Quadratic Equation
#include <math.h>
#include <stdio.h>
int main() {
    double a, b, c, D, r1, r2, realPart, imagPart;
    printf("Haritha R\t126018017\n");
    printf("Enter coefficients a, b and c: ");
    scanf("%lf %lf %lf", &a, &b, &c);
    D = b * b - 4 * a * c;
    if (D > 0) 
    {
        r1 = (-b + sqrt(D)) / (2 * a);
        r2 = (-b - sqrt(D)) / (2 * a);
        printf("root1 = %.2lf and root2 = %.2lf", r1, r2);
    }
    else if (D == 0) 
    {
        r1 = r2 = -b / (2 * a);
        printf("root1 = root2 = %.2lf;", r1);
    }
    else 
    {
        realPart = -b / (2 * a);
        imagPart = sqrt(-D) / (2 * a);
        printf("root1 = %.2lf+%.2lfi and root2 = %.2f-%.2fi", realPart, imagPart, realPart, imagPart);
    }
return 0;
} 
