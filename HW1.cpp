#include <iostream>
#include <locale.h>
#include <math.h>

#define nl << '\n';

using namespace std;

static void task_1(double b1, double b2, double h) { 
    //Вычислить площадь трапеции с основаниями b1 и b2 и высотой h
    cout << "Площадь трапеции: " << (b1 * b2 * h * 0.5) nl;
}

static void task_2(double r) {
    //Вычислить длину окружности и площадь круга радиуса г.
    double pi = 3.1415;
    cout << "Длина окружности равна: " << (2 * pi * r) nl;
    cout << "Площадь окружности равна: " << (pi * r * r) nl;
}

static void task_3(double a, double b) {
    //Вычислить площадь прямоугольного треугольника и гипотенузу
    cout << "Площадь треугольнка: " << (0.5 * a * b) nl;
    cout << "Гипотенуза равна: " << sqrt(a * a + b * b) nl;
}

static void task_4(int num) {
    //Дано десятичное четырехзначное число. Найти сумму его цифр.
    int sum = 0;
    cout << "Сумма цифр числа " << num;
    while (num) {
        sum += num % 10;
        num /= 10;
    }
    cout << " равна " << sum nl;
}

static void task_5(int x, int y) {
    //Выполнить переход от декартовых координат к полярным
    cout << "Декартовы " << "(" << x << ", " << y << ") => полярные ";
    cout << "ф = " << (atan2(y, x)) << ", r = " << (sqrt(x * x + y * y)) nl;
}

static void task_6(double f, double r) {
    //Выполнить переход от полярных координат к декартовым
    cout << "Полярные " << "ф = " << f << ", r = " << r << " => декартовы (" << (r * cos(f)) << ", " << (r * sin(f)) << ")" nl;
}

static void task_7(double a, double b, double c) {
    //Найти корни квадратного уравнения
    //Используются коэффициенты, где a != 0 по определению
    double d = b * b - (4 * a * c);
    if (d < 0) {
        cout << "У данного уравнения отсутствуют решения среди действительных чисел" nl;
        return;
    }
    else if (d == 1) {
        cout << "Решение одно: " << ((0 - b) / (2 * a)) nl;
    }
    else {
        cout << "Есть два решения: " << ((sqrt(d) - b) / (2 * a)) << ", " << ((0 - sqrt(d) - b) / (2 * a)) nl;
    }
}

static double median(double a, double b, double c) { 
    //вспомогательная функция для задания 8
    return (0.5 * sqrt(2 * (b * b + c * c) - a * a));
}

static void task_8(double a, double b, double c) {
    //Имеется треугольник со сторонами а, b, с. Найти медианы треугольника, сторонами которого являются медианы исходного треугольника
    double s1 = median(a, b, c);
    double s2 = median(b, c, a);
    double s3 = median(c, a, b);
    cout << "Медианы треугольника, сторонами которого являются медианы исходного треугольника: " << median(s1, s2, s3) << ", " << median(s2, s3, s1) << ", " << median(s3, s1, s2) nl;
}

static void task_9(int k) {
    //Идет k-я секунда суток. Определить, сколько целых часов и целых минут прошло с начала суток
    int h = 0;
    int m = 0;
    
    if (k >= 3600) {
        h = k / 3600;
        k -= h * 3600;
    }
    if (k >= 60){
        m = k / 60;
    }
    cout << "С начала суток прошел " << h << " час " << m << " минута" nl;
}

static void task_10(double a, double b, double c) {
    //Определить, является ли треугольник со сторонами a, b, c равнобедренным
    cout << "Данный треугольник является " << (((a == b) || (a == c) || (b == c)) ? "равнобедренным" : "неравнобедренным") nl ;
}

static void task_11(double sum) {
    //Вычислить стоимость покупки с учётом скидки. Скидка в 10% предоставляется, если сумма покупки превышает 1000 рублей
    cout << "Сумма покупки составит: " << ((sum > 1000) ? (sum * 0.9) : sum) nl;
}

static void task_12(int height, int weight) {
    //Дать рекомендации пользователю с известным ростом и весом похудеть или поправиться, если идеальный вес определяется формулой (рост - 100 = идеальный вес)
    int perfect = height - 100;
    if (weight > perfect) {
        cout << "Рекомендуется похудеть" nl;
    }
    else if (weight < perfect) {
        cout << "Рекомендуется поправиться" nl;
    }
    else {
        cout << "Ваш вес идеален" nl;
    }
}

static void task_13() {
    //Программа генерирует два случайных числа в диапазоне от 1 до 9. Тестируемый вводит результат произведения этих чисел. Программа сообщает тестируемому ошибся он или нет
    int mult;
    srand(time(0));
    int x = rand() % 9 + 1;
    int y = rand() % 9 + 1;
    cout << "Введите произведение чисел " << x << ", " << y nl;
    cin >> mult;
    cout << ((x * y == mult) ? "Совершенно верно!" : "Ответ неверный") nl;
}

static void task_14(int duration, int day) {
    //Написать программу вычисления стоимости переговоров, если по субботам и воскресеньям предоставляется скидка 20%. Ввести продолжительность разговора и день недели(число от 1 до 7)
    // Пусть стоимость минуты переговоров 10 рублей
    int price = 10;
    if ((day == 7) || (day == 6)) {
        cout << "Стоимость переговоров составит " << duration * price * 0.8 << "рублей" nl;
    }
    else {
        cout << "Стоимость переговоров составит " << duration * price << "рублей" nl;
    }

}

static void task_15() {
    //Ввести с клавиатуры номер месяца. Выдать сообщение о названии месяца и времени года.
    int month;

    cout << "Введите номер месяца (1-12): ";
    cin >> month;

    switch (month) {
    case 1:
        cout << "Январь - зима" nl;
        break;
    case 2:
        cout << "Февраль - зима" nl;
        break;
    case 3:
        cout << "Март - весна" nl;
        break;
    case 4:
        cout << "Апрель - весна" nl;
        break;
    case 5:
        cout << "Май - весна" nl;
        break;
    case 6:
        cout << "Июнь - лето" nl;
        break;
    case 7:
        cout << "Июль - лето" nl;
        break;
    case 8:
        cout << "Август - лето" nl;
        break;
    case 9:
        cout << "Сентябрь - осень" nl;
        break;
    case 10:
        cout << "Октябрь - осень" nl;
        break;
    case 11:
        cout << "Ноябрь - осень" nl;
        break;
    case 12:
        cout << "Декабрь - зима" nl;
        break;
    default:
        cout << "Некорректный номер месяца" nl;
    }
}

static void task_16(int num) {
    //Определить, является ли шестизначное число "счастливым"
    int l = 0;
    int r = 0;

    for (int i = 0; i < 3; i++) {
        r += num % 10;
        num /= 10;
    };
    for (int i = 0; i < 3; i++) {
        l += num % 10;
        num /= 10;
    };
    cout << "Введенное число " << ((l == r) ? "" : "не ") << "является счастливым" nl;
}

static void task_17() {
    //Написать программу, которая при вводе числа в диапазоне от 1 до 99 добавляет к нему слово "копейка" в правильной форме
    int number;

    cout << "Введите число от 1 до 99: ";
    cin >> number;

    if (number >= 11 && number <= 19) {
        cout << number << " копеек" nl;
    }
    else {
        switch (number) {
        case 1:
            cout << number << " копейка" nl;
            break;
        case 2:
        case 3:
        case 4:
            cout << number << " копейки" nl;
            break;
        default:
            cout << number << " копеек" nl;
        }
    }
}

static void task_18(int number) {
    //Дано натуральное четырехзначное число. Выяснить, является ли оно палиндромом
    int origin, revers = 0;
    
    origin = number;

    while (number > 0) {
        revers = revers * 10 + number % 10;
        number /= 10;
    }

    cout << ((origin == revers) ? "Число является палиндромом" : "Число не является палиндромом") nl;
}

static void task_19(int num) {
    //Дано трёхзначное число. Определить: 19.1 является ли произведение его цифр больше числа b 19.2 кратна ли 7 сумма его цифр
    int mult = 1;
    int sum = 0;
    int origin = num;

    for (int i = 0; i < 3; i++) {
        mult *= num % 10;
        sum += num % 10;
        num /= 10;
    }
    
    cout << "Является ли произведение цифр числа " << origin << " больше самого числа: " << ((mult > origin) ? "Да" : "Нет") nl;
    cout << "Кратна ли 7 сумма цифр этого числа: " <<  ((sum % 7 == 0) ? "Да" : "Нет") nl;
}

static void task_20(double a, double b, double c, double d) {
    //Даны вещественные положительные числа a, b, c, d. Выяснить, можно ли прямоугольник со сторонами a, b поместить в прямоугольник со сторонами c, d так, чтобы стороны одного прямоугольника были параллельны сторонам другого
    bool flag = false;
    if ((a < c && b < d) || (a < d && b < c)) flag = true;
    cout << "Прямоугольник со сторонами " << a << " и " << b << (flag ? " можно" : " нельзя") << " поместить в прямоугольник со сторонами " << c << " и " << d nl;
}

static void task_21() {
    cout << "Размеры основных типов данных:" nl;
    cout << "Размер int: " << sizeof(int) << " байт" nl;
    cout << "Размер float: " << sizeof(float) << " байт" nl;
    cout << "Размер double: " << sizeof(double) << " байт" nl;
    cout << "Размер char: " << sizeof(char) << " байт" nl;
}

int main()
{
    setlocale(LC_ALL, "Russian");

    //task_1(6, 8, 2);
    //task_2(4);
    //task_3(8, 6);
    //task_4(1234);
    //task_5(1, 1);
    //task_6(12, 1);
    //task_7(1, -13, 36); //можно добавить примеров
    //task_8(10, 12, 15);
    //task_9(3660);
    //task_10(5, 5, 3); // равнобедренный
    //task_10(1, 2, 3); // неравнобедренный,
    //task_11(1100); // со скидкой
    //task_11(1000); // без скидки
    //task_12(190, 90);
    //task_13(); // задание с вводом пользователя
    //task_14(10, 6);
    //task_15();
    //task_16(123123);
    //task_17();
    //task_18(1231);
    //task_19(124);
    //task_20(3, 8, 9, 5);
    task_21();
   
    return 0;
}
