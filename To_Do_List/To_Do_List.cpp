#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

struct Do {
    string name;
    string priority;
    string description;
    int day;
    int month;
    int year;
    int hour;
    int min;
};

int i = 0, size_add=0;//Глобальные переменные нужны для для записи о добавленных делах
//Главное меню
int main_menu(int& menu_item);
//Добавление дел
Do* add_case(Do* arr_do_list, int& size, int& size_add);
//Вывод
void output_case(Do* arr_do_list, int& size_add, int& d, int& m, int& y, int& h, int& mi);
//Удаление
Do* delete_case(Do* arr_do_list, string& del_name, int& size_add);
//Изменение
Do* change_case(Do* arr_do_list, int& size_add);
//Поиск
void search_case(Do* arr_do_list, int& size_add, int& d, int& m, int& y, int& h, int& mi);

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "\tСписок дел\n\n";
    int menu_item = 0, size=10;//выбор в главном меню //размер списка
    string del_name;//Для записи названия дела, которое нужно удалить
    int d = 0, m = 0, y = 0, h = 0, mi = 0;//Для записи даты и времени
    Do* arr_do_list = new Do[size];//массив с делами
    do {
        main_menu(menu_item);
        switch (menu_item) {
        case 1: {
            add_case(arr_do_list, size, size_add);
            system("cls");
            break;
        }
        case 2: {
            delete_case(arr_do_list, del_name, size_add);
            system("cls");
            break;
        }
        case 3: {
            change_case(arr_do_list, size_add);
            system("cls");
            break;
        }
        case 4: {
            search_case(arr_do_list, size_add,d,m,y,h,mi);
            break;
        }
        case 5: {
            output_case(arr_do_list, size_add,d, m, y, h, mi);
            system("pause");
            system("cls");
            break;
        }
        }
    } while (menu_item != 0);

}

int main_menu(int& menu_item) {

    cout << "\tМеню: \n"
        << "[1] - Добавление дел;\n"
        << "[2] - Удаление дел;\n"
        << "[3] - Редактирование дел;\n"
        << "[4] - Поиск дел;\n"
        << "[5] - Отобразить список дел ;\n"
        << "[0] - Выход из программы;\n";
    cin >> menu_item;
    if (menu_item == 0) {
        exit(0);
    }
    return menu_item;
}

Do* add_case(Do* arr_do_list, int& size, int& size_add) {
    int j = 0; //для выбора добавления нового дела
    int priority_sel = 0; //для выбора приоритета

    do {
        cout << "Введите наименование дела: \n";
        cin.get();
        getline(cin, arr_do_list[i].name);
        cout << "Добавьте описание: \n";
        getline(cin, arr_do_list[i].description);
        cout << "Введите число: \n";
        cin >> arr_do_list[i].day;
        cout << "Введите месяц: \n";
        cin >> arr_do_list[i].month;
        cout << "Введите год: \n";
        cin >> arr_do_list[i].year;
        cout << "Введите часы: \n";
        cin >> arr_do_list[i].hour;
        cout << "Введите минуты: \n";
        cin >> arr_do_list[i].min;
        cout << "Выберите приоритет: \n"
            << "[1] - Низкий приоритет \n"
            << "[2] - Средний приоритет \n"
            << "[3] - Высокий приоритет \n";
        cin >> priority_sel;
        if (priority_sel == 1) {
            arr_do_list[i].priority = "Низкий приоритет";
        }
        else if (priority_sel == 2) {
            arr_do_list[i].priority = "Средний приоритет";
        }
        else if (priority_sel == 3) {
            arr_do_list[i].priority = "Высокий приоритет";
        }
        size_add++;//добавляем для цикла вывода
        i++;
        cout << "Добавить ещё одно дело? [1] - Да / [2] - Нет \n";
        cin >> j;
        if (j == 1) {
            continue;
        }
        else
            break;

    } while (i != size);
    return arr_do_list;
}

void output_case(Do* arr_do_list, int& size_add, int& d, int& m, int& y, int& h, int& mi)
{
    int och = 0;//для выбора в меню отображения
    if (size_add == 0) {//проверка, есть ли записанные данные
        cout << "\n\tНет данных!\n";
        Sleep(800);
    }
    do {
        cout << "За какой период отобразить? :\n"
            << "[1] - День \n"
            << "[2] - Неделя \n"
            << "[3] - Месяц \n"
            << " \n"
            << "[4] - Сортировка по времени \n"
            << "[5] - Сортировка по приоритету \n"
            << "[0] - Выход в главное меню \n";
        cin >> och;
        switch (och) {
        case 1: {
            cout << "\nВведите число: \n";
            cin >> d;
            cout << "\nВведите месяц: \n";
            cin >> m;
            cout << "\nВведите год: \n";
            cin >> y;
            for (int i = 0; i < size_add; i++) {
                if (arr_do_list[i].day == d && arr_do_list[i].month == m && arr_do_list[i].year == y) {
                    cout << "Номер в списке дел [" << i + 1 << "] \n";
                    cout << arr_do_list[i].name << " \n";
                    cout << arr_do_list[i].description << " \n";
                    cout << arr_do_list[i].priority << " \n";
                    cout << arr_do_list[i].day << '.' << arr_do_list[i].month << '.'
                        << arr_do_list[i].year << ' ' << arr_do_list[i].hour << ':'
                        << arr_do_list[i].min << " \n\n";
                }

            }
            system("pause");
            system("cls");
            break;
        }
        case 2: {
            cout << "\nВведите число: \n";
            cin >> d;
            cout << "\nВведите месяц: \n";
            cin >> m;
            cout << "\nВведите год: \n";
            cin >> y;
            for (int i = 0; i <= 7; ++i) {//цикл счёта недели

                for (int j = 0; j < size_add; j++) {
                    if (arr_do_list[j].day == d && arr_do_list[j].month == m && arr_do_list[j].year == y) {
                        cout << arr_do_list[j].name << " \n";
                        cout << arr_do_list[j].description << " \n";
                        cout << arr_do_list[j].priority << " \n";
                        cout << arr_do_list[j].day << '.' << arr_do_list[j].month << '.'
                            << arr_do_list[j].year << ' ' << arr_do_list[j].hour << ':'
                            << arr_do_list[j].min << " \n\n";
                    }
                }
                if (d == 30) {//проверка окончания месяца
                    m++;
                    d = 0;
                }
                else if (m > 12) {//проверка окончания года
                    y++;
                    d = 0;
                    m = 0;
                }
                else {
                    d++;//увеличение числа
                }
            }
            system("pause");
            system("cls");
            break;
        }
        case 3: {
            cout << "\nВведите число: \n";
            cin >> d;
            cout << "\nВведите месяц: \n";
            cin >> m;
            cout << "\nВведите год: \n";
            cin >> y;
            for (int i = 0; i < 30; ++i) {//цикл счета месяца

                for (int j = 0; j < size_add; j++) {
                    if (arr_do_list[j].day == d && arr_do_list[j].month == m && arr_do_list[j].year == y) {
                        cout << arr_do_list[j].name << " \n";
                        cout << arr_do_list[j].description << " \n";
                        cout << arr_do_list[j].priority << " \n";
                        cout << arr_do_list[j].day << '.' << arr_do_list[j].month << '.'
                            << arr_do_list[j].year << ' ' << arr_do_list[j].hour << ':'
                            << arr_do_list[j].min << " \n\n";
                    }
                }
                if (d == 30) {
                    m++;
                    d = 0;
                }
                else if (m > 12) {
                    y++;
                    d = 0;
                    m = 0;
                }
                else {
                    d++;
                }
            }
            system("pause");
            system("cls");
            break;
        }
        case 4: {
            
            Do temp;
            for (int i = 0; i < size_add; i++)
            {
                for (int j = 0; j < size_add; j++)
                {
                    if ((arr_do_list[i].year * 365 + arr_do_list[i].month * 30 + arr_do_list[i].day) ==//сравнение даты
                        (arr_do_list[j].year * 365 + arr_do_list[j].month * 30 + arr_do_list[j].day)) {
                        if ((arr_do_list[i].hour * 60 * 60 + arr_do_list[i].min * 60) <//сравнение по времени
                            (arr_do_list[j].hour * 60 * 60 + arr_do_list[j].min * 60))
                        {
                            temp = arr_do_list[i];
                            arr_do_list[i] = arr_do_list[j];
                            arr_do_list[j] = temp;
                        }
                    }
                    else if ((arr_do_list[i].year * 365 + arr_do_list[i].month * 30 + arr_do_list[i].day) <
                        (arr_do_list[j].year * 365 + arr_do_list[j].month * 30 + arr_do_list[j].day)) {
                        temp = arr_do_list[i];
                        arr_do_list[i] = arr_do_list[j];
                        arr_do_list[j] = temp;
                         }
                    
                }
            }
            for (int i = 0; i < size_add; i++) {
                
                    cout << arr_do_list[i].name << " \n";
                    cout << arr_do_list[i].description << " \n";
                    cout << arr_do_list[i].priority << " \n";
                    cout << arr_do_list[i].day << '.' << arr_do_list[i].month << '.'
                        << arr_do_list[i].year << ' ' << arr_do_list[i].hour << ':'
                        << arr_do_list[i].min << " \n\n";
                
            }
        }
              system("pause");
              system("cls");
              break;
        case 5: {
            Do temp;
            for (int i = 0; i < size_add; i++)
            {
                for (int j = 0; j < size_add; j++)
                {
                    if (arr_do_list[i].priority == "Высокий приоритет" )
                    {
                        temp = arr_do_list[i];
                        arr_do_list[i] = arr_do_list[j];
                        arr_do_list[j] = temp;
                    }
                    else if (arr_do_list[i].priority == "Средний приоритет") {
                        temp = arr_do_list[i];
                        arr_do_list[i] = arr_do_list[j];
                        arr_do_list[j] = temp;
                    }
                }
            }
            system("pause");
            system("cls");
            break;
            for (int i = 0; i < size_add; i++) {

                cout << arr_do_list[i].name << " \n";
                cout << arr_do_list[i].description << " \n";
                cout << arr_do_list[i].priority << " \n";
                cout << arr_do_list[i].day << '.' << arr_do_list[i].month << '.'
                    << arr_do_list[i].year << ' ' << arr_do_list[i].hour << ':'
                    << arr_do_list[i].min << " \n\n";

            }
        }
        default:
            break;
        }

    } while (och != 0);

}

Do* delete_case(Do* arr_do_list, string& del_name, int& size_add) {
    int temp = 0;
    cout << "Введите имя дела, которое хотите удалить: \n";
    cin.get();
    getline(cin, del_name);
    for (int i = 0; i < size_add; i++) {

        if (arr_do_list[i].name == del_name) {
            arr_do_list[i].name = arr_do_list[i + 1].name;
            arr_do_list[i].description = arr_do_list[i + 1].description;
            arr_do_list[i].priority = arr_do_list[i + 1].priority;
            arr_do_list[i].day = arr_do_list[i + 1].day;
            arr_do_list[i].month = arr_do_list[i + 1].month;
            arr_do_list[i].year = arr_do_list[i + 1].year;
            arr_do_list[i].hour = arr_do_list[i + 1].hour;
            arr_do_list[i].min = arr_do_list[i + 1].min;
            temp++;
        }

        if (temp == 1) {
            arr_do_list[i].name = arr_do_list[i + 1].name;
            arr_do_list[i].description = arr_do_list[i + 1].description;
            arr_do_list[i].priority = arr_do_list[i + 1].priority;
            arr_do_list[i].day = arr_do_list[i + 1].day;
            arr_do_list[i].month = arr_do_list[i + 1].month;
            arr_do_list[i].year = arr_do_list[i + 1].year;
            arr_do_list[i].hour = arr_do_list[i + 1].hour;
            arr_do_list[i].min = arr_do_list[i + 1].min;
        }
    }
    if (temp == 1) {
        cout << "\n\tУдалено!\n\n";
        Sleep(800);
        size_add--;//если одно из дел удалено, отображение уменьшается 
        i--;
    }
    else if (temp != 1) {
        cout << "\n\tНет совпадений!\n";
        Sleep(800);
    }

    return arr_do_list;
}

Do* change_case(Do* arr_do_list, int& size_add) {
    string change_c;
    int chng = 0, count1 = 0;
    cout << "Введите название дела, которое хотите отредактировать: \n";
    cin.get();
    getline(cin, change_c);
    for (int i = 0; i < size_add; i++) {
        if (arr_do_list[i].name == change_c) {
            cout << "Номер в списке дел [" << i + 1 << "] \n";
            cout << arr_do_list[i].name << " \n";
            cout << arr_do_list[i].description << " \n";
            cout << arr_do_list[i].priority << " \n";
            cout << arr_do_list[i].day << '.' << arr_do_list[i].month << '.'
                << arr_do_list[i].year << ' ' << arr_do_list[i].hour << ':'
                << arr_do_list[i].min << " \n\n";
            count1++;
        }

        if (count1 == 1) {
            cout << "Введите наименование дела: \n";
            getline(cin, arr_do_list[i].name);
            cout << "Добавьте описание: \n";
            getline(cin, arr_do_list[i].description);
            cout << "Введите число: \n";
            cin >> arr_do_list[i].day;
            cout << "Введите месяц: \n";
            cin >> arr_do_list[i].month;
            cout << "Введите год: \n";
            cin >> arr_do_list[i].year;
            cout << "Введите часы: \n";
            cin >> arr_do_list[i].hour;
            cout << "Введите минуты: \n";
            cin >> arr_do_list[i].min;
            cout << "Выберите приоритет: \n"
                << "[1] - Низкий приоритет \n"
                << "[2] - Средний приоритет \n"
                << "[3] - Высокий приоритет \n";
            cin >> chng;
            if (chng == 1) {
                arr_do_list[i].priority = "Низкий приоритет";
            }
            else if (chng == 2) {
                arr_do_list[i].priority = "Средний приоритет";
            }
            else if (chng == 3) {
                arr_do_list[i].priority = "Высокий приоритет";
            }
            break;
        }
        
    }
    if (count1 == 0) {
        cout << "\n\tНет данных!\n";
    }
    cout << "\n\tСохранено!\n";
    Sleep(800);
    return arr_do_list;
}

void search_case(Do* arr_do_list, int& size_add, int& d, int& m, int& y, int& h, int& mi) {
    // это функция сортировки, убрать ее отсюда
   
    
    int srch = 0, prior_srch = 0, count = 0;//srch - для выбора в меню поиска, prior_srch - для поиска по приоритету, 
    string search_name;                       //count - для проверки записи, search_name - для поиска по имени и описанию
    
    cout << "\t\nПоиск:\n"
        << "[1] - По названию \n"
        << "[2] - По приоритету \n"
        << "[3] - По описанию \n"
        << "[4] - По дате и времени \n";

    cin >> srch;
    switch (srch) {
    case 1: {
        cout << "Введите имя дела, которое хотите найти: \n";
        cin.get();
        getline(cin, search_name);
        for (int i = 0; i < size_add; i++) {
            if (arr_do_list[i].name == search_name) {
                cout << "Номер в списке дел [" << i + 1 << "] \n";
                cout << arr_do_list[i].name << " \n";
                cout << arr_do_list[i].description << " \n";
                cout << arr_do_list[i].priority << " \n";
                cout << arr_do_list[i].day << '.' << arr_do_list[i].month << '.'
                    << arr_do_list[i].year << ' ' << arr_do_list[i].hour << ':'
                    << arr_do_list[i].min << " \n\n";
                count++;
            }
        }
        if (count == 0) {
            cout << "\n\tНет данных!\n";
        }
        else
            count = 0;
        system("pause");
        system("cls");
        break;
    }
    case 2: {
        cout << "Выберите тип приоритета, по которому будет осуществляться поиск: \n"
            << "[1] - Низкий приоритет \n"
            << "[2] - Средний приоритет \n"
            << "[3] - Высокий приоритет \n";
        cin >> prior_srch;
        switch (prior_srch) {
        case 1: {
            for (int i = 0; i < size_add; i++) {
                if (arr_do_list[i].priority == "Низкий приоритет") {
                    cout << "Номер в списке дел [" << i + 1 << "] \n";
                    cout << arr_do_list[i].name << " \n";
                    cout << arr_do_list[i].description << " \n";
                    cout << arr_do_list[i].priority << " \n";
                    cout << arr_do_list[i].day << '.' << arr_do_list[i].month << '.'
                        << arr_do_list[i].year << ' ' << arr_do_list[i].hour << ':'
                        << arr_do_list[i].min << " \n\n";
                    count++;
                }
            }
            if (count == 0) {
                cout << "\n\tНет данных!\n";
            }
            else
                count = 0;
            system("pause");
            system("cls");
            break;
        }
        case 2: {
            for (int i = 0; i < size_add; i++) {
                if (arr_do_list[i].priority == "Средний приоритет") {
                    cout << "Номер в списке дел [" << i + 1 << "] \n";
                    cout << arr_do_list[i].name << " \n";
                    cout << arr_do_list[i].description << " \n";
                    cout << arr_do_list[i].priority << " \n";
                    cout << arr_do_list[i].day << '.' << arr_do_list[i].month << '.'
                        << arr_do_list[i].year << ' ' << arr_do_list[i].hour << ':'
                        << arr_do_list[i].min << " \n\n";
                    count++;
                }
            }
            if (count == 0) {
                cout << "\n\tНет данных!\n";
            }
            else
                count = 0;
            system("pause");
            system("cls");
            break;
        }
        case 3: {
            for (int i = 0; i < size_add; i++) {
                if (arr_do_list[i].priority == "Высокий приоритет") {
                    cout << "Номер в списке дел [" << i + 1 << "] \n";
                    cout << arr_do_list[i].name << " \n";
                    cout << arr_do_list[i].description << " \n";
                    cout << arr_do_list[i].priority << " \n";
                    cout << arr_do_list[i].day << '.' << arr_do_list[i].month << '.'
                        << arr_do_list[i].year << ' ' << arr_do_list[i].hour << ':'
                        << arr_do_list[i].min << " \n\n";
                    count++;
                }
            }
            if (count == 0) {
                cout << "\n\tНет данных!\n";
            }
            else
                count = 0;
            system("pause");
            system("cls");
            break;
        }
        default:
        {
            cout << "\t\nНет такого пункта!\n";
            Sleep(800);
            break;
        }

        }
        system("pause");
        system("cls");
        break;
    }
    case 3: {
        cout << "Введите описание, по которому хотите найти дело: \n";
        cin.get();
        getline(cin, search_name);
        for (int i = 0; i < size_add; i++) {
            if (arr_do_list[i].description == search_name) {
                cout << "Номер в списке дел [" << i + 1 << "] \n";
                cout << arr_do_list[i].name << " \n";
                cout << arr_do_list[i].description << " \n";
                cout << arr_do_list[i].priority << " \n";
                cout << arr_do_list[i].day << '.' << arr_do_list[i].month << '.'
                    << arr_do_list[i].year << ' ' << arr_do_list[i].hour << ':'
                    << arr_do_list[i].min << " \n\n";
                count++;
            }
        }
        if (count == 0) {
            cout << "\n\tНет данных!\n";
        }
        else
            count = 0;
        system("pause");
        system("cls");
        break;
    }
    case 4: {

        cout << "Введите дату и время выполнения (дд.мм.гггг чч:мм) : \n";
        cout << "Введите число: \n";
        cin >> d;
        cout << "Введите месяц: \n";
        cin >> m;
        cout << "Введите год: \n";
        cin >> y;
        cout << "Введите часы: \n";
        cin >> h;
        cout << "Введите минуты: \n";
        cin >> mi;
        for (int i = 0; i < size_add; i++) {
            if (arr_do_list[i].day == d &&
                arr_do_list[i].month == m &&
                arr_do_list[i].year == y &&
                arr_do_list[i].hour == h &&
                arr_do_list[i].min == mi) 
            {
                cout << "Номер в списке дел [" << i + 1 << "] \n";
                cout << arr_do_list[i].name << " \n";
                cout << arr_do_list[i].description << " \n";
                cout << arr_do_list[i].priority << " \n";
                cout << arr_do_list[i].day << '.' << arr_do_list[i].month << '.'
                    << arr_do_list[i].year << ' ' << arr_do_list[i].hour << ':'
                    << arr_do_list[i].min << " \n\n";
                count++;

            }
        }
        if (count == 0) {
            cout << "\n\tНет данных!\n";
        }
        else
            count = 0;
        system("pause");
        system("cls");
        break;
    }
    }
}