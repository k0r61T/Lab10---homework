#include <stdio.h>
#include <string.h>
#include <math.h>
#include <locale.h>

double area_triangle(double a, double h)
{
    return 0.5 * a * h;
}

void ricunok(double a, double h)
{
    if (a <= 0 || h <= 0)
    {
        printf("Ошибка: высота и длина должны быть положительными!\n");
        return;
    }

    int shirina = h;
    double shag = a / (2 * shirina - 1);

    for (int i = 1; i <= shirina; i++)
    {
        int symbols = (2 * i - 1) * shag;
        int probel = (a - symbols) / 2;

        for (int j = 0; j < probel; j++)
        {
            printf(" ");
        }

        for (int j = 0; j < symbols; j++)
        {
            printf("*");
        }
        printf("\n");
    }
}

int main()
{
    setlocale(LC_ALL, "RUS");
    int vibor;
    double a, h, area;

    printf("Домашнее задание по Lab10. Задание 3. Вариант 6\n");
    printf("Составьте программу, которая для заданной пользователем определенной фигуры \n(равнобедренный треугольник) предлагает меню выбора одной из операций:\n1) рассчитать площадь\n2) вывести определение фигуры\n3) нарисовать фигуру\n");

    printf("\nВведите длину основания треугольника (a): ");
    scanf("%lf", &a);
    printf("Введите высоту треугольника (h): ");
    scanf("%lf", &h);

    do
    {
        printf("\nМеню операций:\n");
        printf("1) Рассчитать площадь\n");
        printf("2) Вывести определение фигуры\n");
        printf("3) Нарисовать фигуру\n");
        printf("4) Выйти из программы\n");
        printf("Выберите операцию (1-4): ");
        scanf("%d", &vibor);

        switch (vibor)
        {
        case 1:
            area = area_triangle(a, h);
            printf("\nПлощадь равнобедренного треугольника:\n");
            printf("Основание a = %.2f\n", a);
            printf("Высота h = %.2f\n", h);
            printf("Площадь S = 0.5 * %.2f * %.2f = %.2f\n", a, h, area);
            break;

        case 2:
            printf("\nОпределение равнобедренного треугольника:\n");
            printf("Равнобедренный треугольник - это треугольник, у которого две стороны равны между собой.\nРавные стороны называются боковыми, третья сторона - основанием.\n");
            break;

        case 3:
            printf("\nРавнобедренный треугольник с основанием %.0f и высотой %.0f:\n", a, h);
            printf("\n----------------------------\n\n");
            ricunok(a, h);
            printf("\n----------------------------\n");
            break;

        case 4:
            printf("\nВыход из программы...\n");
            break;

        default:
            printf("\nНеверный выбор! Пожалуйста, выберите число от 1 до 4.\n");
            break;
        }
    } 
    while (vibor != 4);

    return 0;
}