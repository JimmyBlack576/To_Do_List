﻿#include <iostream>
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



int i = 0, size_add=0;

int main_menu(int &menu_item) {
    
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

Do* add_case(Do* arr_do_list, int &size, int &size_add) {
    int j=0;
    int priority_sel=0;
    //if (i > 0) {
       // i++;
        
    //}
    do{
        
        cout << "Введите наименование дела: \n";
        cin.get();
        getline(cin,  arr_do_list[i].name);
        cout << "Добавьте описание: \n";
        //cin.get();
        getline(cin, arr_do_list[i].description);
        cout << "Введите время выполнения (дд.мм.гггг чч:мм) \n";
        //cin.get();
        cin >> arr_do_list[i].day 
            >> arr_do_list[i].month 
            >> arr_do_list[i].year 
            >> arr_do_list[i].hour 
            >> arr_do_list[i].min;
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
        size_add++;
        i++;
        cout << "Добавить ещё одно дело? [1] - Да / [2] - Нет \n";
        cin >> j;
        if (j == 1) {
            //i++;
            continue;
        }
        else
            break;
        
    } while (i != size);
    return arr_do_list;
}

void output_case(Do* arr_do_list, int& size_add)
{
    if (size_add == 0) {
        cout << "\n\tНет данных!\n";
        Sleep(800);
    }
    for (int i = 0; i < size_add; i++) {
        cout << "Номер в списке дел [" << i + 1 << "] \n";
        cout << arr_do_list[i].name << " \n";
        cout << arr_do_list[i].description << " \n";
        cout << arr_do_list[i].priority << " \n";
        cout << arr_do_list[i].day<<'.'<< arr_do_list[i].month<<'.'
            << arr_do_list[i].year<<' '<< arr_do_list[i].hour<<':'
            << arr_do_list[i].min << " \n\n";
    }
}

Do* delete_case(Do* arr_do_list, string &del_name, int &size_add ) {
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
            size_add--;
            i--;
        }
        else if (temp != 1) {
            cout << "\n\tНет совпадений!\n";
            Sleep(800);
        }
           
    return arr_do_list;
}

Do* change_case(Do* arr_do_list, int& size_add) {
    int change_c;
    output_case(arr_do_list, size_add);
    
        cout << "Введите номер дела, которое хотите отредактировать: \n";
        cin >> change_c;
    
    cout << "Введите наименование дела: \n";
    cin.get();
    getline(cin, arr_do_list[change_c-1].name);
    cout << "Добавьте описание: \n";
    getline(cin, arr_do_list[change_c-1].description);
    cout << "Введите время выполнения (дд.мм.гггг чч:мм) \n";
    cin >> arr_do_list[change_c - 1].day 
        >> arr_do_list[change_c - 1].month 
        >> arr_do_list[change_c - 1].year 
        >> arr_do_list[change_c - 1].hour 
        >> arr_do_list[change_c - 1].min;
    cout << "Выберите приоритет: \n"
        << "[1] - Низкий приоритет \n"
        << "[2] - Средний приоритет \n"
        << "[3] - Высокий приоритет \n";
    cin >> change_c;
    if (change_c == 1) {
        arr_do_list[change_c - 1].priority = "Низкий приоритет";
    }
    else if (change_c == 2) {
        arr_do_list[change_c - 1].priority = "Средний приоритет";
    }
    else if (change_c == 3) {
        arr_do_list[change_c - 1].priority = "Высокий приоритет";
    }
    cout << "\n\tСохранено!\n";
    Sleep(800);
    return arr_do_list;
}

void search_case(Do* arr_do_list, int &size_add) {
    // это функция сортировки, убрать ее отсюда
   /* Do temp;
    for (int i = 0; i < size_add; i++)
    {
        for (int j = 0; j < size_add; j++)
        {
            if (strcmp(arr_do_list[i].name.c_str(), arr_do_list[j].name.c_str()) == 1)
            {
                temp = arr_do_list[i];
                arr_do_list[i] = arr_do_list[j];
                arr_do_list[j] = temp;
            }
        }
    }*/
    int srch = 0, prior_srch=0, count=0;
    string search_name;


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
        int d=0, m=0, y=0, h=0, mi=0;
        cout << "Введите дату и время выполнения (дд.мм.гггг чч:мм) : \n";
        cin >> d >> m >> y >> h>> mi;
        for (int i = 0; i < size_add; i++) {
            if (arr_do_list[i].day == d&&
                arr_do_list[i].month == m&&
                arr_do_list[i].year == y&&
                arr_do_list[i].hour == h&&
                arr_do_list[i].min == mi) {
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


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "\tСписок дел\n\n";
    int menu_item = 0, size=10;
    string del_name;
    Do* arr_do_list = new Do[size];
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
            search_case(arr_do_list, size_add);
            break;
        }
        case 5: {
            output_case(arr_do_list, size_add);
            system("pause");
            system("cls");
            break;
        }
        }
    } while (menu_item != 0);
    
    output_case(arr_do_list, size_add);

}
