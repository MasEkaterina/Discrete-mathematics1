#include <iostream>
#include <algorithm>
using namespace std;
int n, n1, n2, n3, numb1, numb2, w;
int* m1, * m2, * m3;

int size()
{
    cout << "Введите размер множества: ";
    cin >> n;
    while (n > 41 || n < 0)
    {
        cout << "Ошибка. Введите размер ещё раз!" << endl;
        cin >> n;
    }
    return n;
}

int Action()
{
    cout << "\tДЕЙСТВИЯ НАД МНОЖЕСТВАМИ" << endl;
    cout << "Выберите действие: " << "\n1 Пересечение" << "\n2 Объединение"
    << "\n3 Разность" << "\n4 Симметричная разность" << "\n5 Дополнение" << endl;
    cin >> w;
    return w;
}

void Choice()
{
    cout << "Введите номера множеств: " << endl;
    cin >> numb1;
    cin >> numb2;
}

void Print(int* mas, int s)
{
    for (int i = 0; i < s; i++)
        cout << mas[i] << " ";
    cout << endl;
}

int* RandCreate()
{
    srand(time(0));
    int* mas1 = new int[n1];
    for (int i = 0; i < n1; i++)
    {
    a: mas1[i] = rand() % 41 - 20;
        for (int j = 0; j < i; j++)
            if (mas1[j] == mas1[i]) goto a;
    }
    Print(mas1, n1);
    return mas1;
}

int* KeyBoard()
{
    int elem, x;
    int* mas2 = new int[n2];
    for (int i = 0; i < n2; i++)
    {
    again: cout << "Введите " << i+1 << " элемент множества: ";
        cin >> elem;
        while (elem < -20 || elem > 20)
        {
            cout << "Ошибка. Введите элемент множества ещё раз: ";
            cin >> elem;
        }
        mas2[i] = elem;
        for (int j = 0; j < i; j++)
        {
            if (mas2[j] == mas2[i]) goto again;
        }
    }
    Print(mas2, n2);
    return mas2;
}

int* PlusMinus(int x)
{
    srand(time(0));
    int* mas3 = new int[n3];
    if (x == 1)
    {
        for (int i = 0; i < n3; i++)
        {
        a: mas3[i] = rand() % 20;
            for (int j = 0; j < i; j++)
                if (mas3[j] == mas3[i]) goto a;
        }
        Print(mas3, n3);
    }
    if (x == 2)
    {
        for (int i = 0; i < n3; i++)
        {
        b: mas3[i] = -(rand() % 20);
            for (int j = 0; j < i; j++)
                if (mas3[j] == mas3[i]) goto b;
        }
        Print(mas3, n3);
    }
    return mas3;
}

int* ChNot(int x)
{
    srand(time(0));
    int* mas4 = new int[n3];
    if (x == 3)
    {
        for (int i = 0; i < n3; i++)
        {
            mas4[i] = rand() % 41 - 20;
            while (!(mas4[i] % 2 == 0))
            {
                a: mas4[i] = rand() % 41 - 20;
                for (int j = 0; j < i; j++)
                    if (mas4[j] == mas4[i]) goto a;
            }
        }
        Print(mas4, n3);
    }
    if (x == 4)
    {
        for (int i = 0; i < n3; i++)
        {
            mas4[i] = rand() % 41 - 20;
            while (mas4[i] % 2 == 0)
            {
            b: mas4[i] = rand() % 41 - 20;
                for (int j = 0; j < i; j++)
                    if (mas4[j] == mas4[i]) goto b;
            }
        }
        Print(mas4, n3);
    }
    return mas4;
}

int* Kratn()
{
    int a;
    cout << "Введите кратное число: ";
    cin >> a;
    int* mas5 = new int[n3];
    for (int i = 0; i < n3; i++)
    {
        mas5[i] = rand() % 41 - 20;
        while (!(mas5[i] % a == 0))
        {
        b: mas5[i] = rand() % 41 - 20;
            for (int j = 0; j < i; j++)
                if (mas5[j] == mas5[i]) goto b;
        }
    }
    Print(mas5, n3);
    return mas5;
}

int* Condition()
{
    int elem, x;
    int* arr = { 0 };
    cout << "Выберите, по какому условию сформировать множество: "
        << "\n1 Только положительные" << "\n2 Только отрицательные" << "\n3 Только четные"
        << "\n4 Только нечетные" << "\n5 Элементы кратны заданному числу" << endl;
    cin >> x;
    while (x < 0 || x > 5)
    {
        cout << "Ошибка. Введите ещё раз";
        cin >> x;
    }
    switch (x)
    {
    case 1: arr = PlusMinus(x); break;
    case 2: arr = PlusMinus(x); break;
    case 3: arr = ChNot(x); break;
    case 4: arr = ChNot(x); break;
    case 5: arr = Kratn(); break;
    }
    return arr;
}

void PrintAct(int* mas, int size)
{
    for (int i = 0; i < size; i++)
        cout << mas[i] << " ";
    cout << endl;
}

void Intersection(int *&m1, int *&m2, int*&m3)
{
    int* mas1{ 0 }, * mas2{ 0 }, r;
    int* mas3 = new int[n];
    r = numb1;
    switch (r)
    {
    case 1: mas1 = m1; break;
    case 2: mas1 = m2; break;
    case 3: mas1 = m3; break;
    }
    r = numb2;
    switch (r)
    {
    case 1: mas2 = m1; break;
    case 2: mas2 = m2; break;
    case 3: mas2 = m3; break;
    }
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            if (mas1[i] == mas2[j])
                cout << mas1[i] << " ";
        }
    }
    
}

void Union(int*& m1, int*& m2, int*& m3)
{
    int* mas1{ 0 }, * mas2{ 0 }, r, size1, size2;
    int* mas3 = new int[n];
    r = numb1;
    switch (r)
    {
    case 1: mas1 = m1; size1 = n1; break;
    case 2: mas1 = m2; size1 = n2; break;
    case 3: mas1 = m3; size1 = n3; break;
    }
    r = numb2;
    switch (r)
    {
    case 1: mas2 = m1; size2 = n1; break;
    case 2: mas2 = m2; size2 = n2; break;
    case 3: mas2 = m3; size2 = n3; break;
    }
    for (int i = 0; i < size1+size2; i++) 
    {
        if (i < size1)
        {
            mas3[i] = mas1[i];
            cout << mas3[i] << " ";
        }
        else
        {
            mas3[i] = mas2[i - size1];
            cout << mas3[i] << " ";
        }
    }
}

void Difference(int*& m1, int*& m2, int*& m3)
{
    int* mas1{ 0 }, * mas2{ 0 }, r, size1, size2, count = 0;
    int* mas3 = new int[n];
    r = numb1;
    switch (r)
    {
    case 1: mas1 = m1; size1 = n1; break;
    case 2: mas1 = m2; size1 = n2; break;
    case 3: mas1 = m3; size1 = n3; break;
    }
    r = numb2;
    switch (r)
    {
    case 1: mas2 = m1; size2 = n1; break;
    case 2: mas2 = m2; size2 = n2; break;
    case 3: mas2 = m3; size2 = n3; break;
    }
    for (int i = 0; i < size1; ++i)
    {
        int isRepeat = 0;
        for (int j = 0; j < size2; ++j)     //Поиск среди второго "множества" 
            if (mas1[i] == mas2[j])      //если элементы равны
            {
                isRepeat = 1;       //продолжаем итерацию цикла
                break;
            }
        if (isRepeat == 0)
        {
            mas3[i] = mas1[i];
            cout << mas3[i] << " ";
        }
    }
}

void  SymmetricDifference(int*& m1, int*& m2, int*& m3)
{
    int* mas1{ 0 }, * mas2{ 0 }, r, size1, size2, n = 0;
    int* mas3 = new int[n];
    int* mas4 = new int[n];
    r = numb1;
    switch (r)
    {
    case 1: mas1 = m1; size1 = n1; break;
    case 2: mas1 = m2; size1 = n2; break;
    case 3: mas1 = m3; size1 = n3; break;
    }
    r = numb2;
    switch (r)
    {
    case 1: mas2 = m1; size2 = n1; break;
    case 2: mas2 = m2; size2 = n2; break;
    case 3: mas2 = m3; size2 = n3; break;
    }
    //for (int i = 0; i < size1 + size2; i++)
    //{
    //    if (i < size1)
    //        mas3[i] = mas1[i];
    //    else
    //        mas3[i] = mas2[i - size1];
    //    //cout << mas3[i] << " ";
    //}
    //n = size1 + size2;
    //for (int i = 0; i < n - 1; i++)
    //{
    //    for (int j = i + 1; j < n; j++)
    //    {
    //        if (mas3[i] == mas3[j])
    //        {
    //            for (int k = j; k < n; k++)
    //                mas3[k] = mas3[k + 1];
    //            n--;
    //            j--;
    //        }
    //    }
    //    cout << mas3[i] << " ";
    //}
    n = size1 + size2;
    int pos = 0;
    for (int i = 0; i < size1; i++)
        mas3[i] = mas1[i];
    for (int i = size1; i < n; i++)
        mas3[i] = mas2[i - size1];
    for (int i = 0; i < n; i++)
        cout << mas3[i] << " ";
    for (int i = 0; i < n; i++) 
    {
        for (int k = 5; k > i; k - 1) 
        {
            if (mas3[i] == mas3[k])
            {
                mas4[pos] = mas3[i];
                pos++;
            }
        }
    }
    for (int i = 0; i < pos; i++)
    {
        cout << mas4[i] << " ";
    }
}
   /* for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (mas3[i] != mas3[j])
            {
                mas4[pos] = mas3[i];
                pos++;
            }
        }
    }*/


int main()
{
    setlocale(LC_ALL, "rus");
    cout << "\tВВОД МНОЖЕСТВ" << "\nПервое множество (автозаполнение): " << endl;
    n1 = size();
    m1 = RandCreate();
    cout << "\nВторое множество (ручной ввод): " << endl;
    n2 = size();
    m2 = KeyBoard();
    cout << "\nТретье множество (ввод по условию): " << endl;
    n3 = size();
    m3 = Condition();
    w = Action(); //дейтсвие
    Choice(); // какие 2 множества
    switch (w)
    {
    case 1: Intersection(m1, m2, m3); break;
    case 2: Union(m1, m2, m3); break;
    case 3: Difference(m1, m2, m3);  break;
    case 4: SymmetricDifference(m1, m2, m3);  break;
    case 5: break;
    }


    
}

