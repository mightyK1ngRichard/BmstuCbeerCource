#include "Header.h"
#include "message.h"
#include "figure.h"
#include <Windows.h>

// var_1
/*
void ReadList(const list<message>& info);

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    message info_1("89168559942", "Здравствуйте ваше величество, Ваш код великолепен как всегда");
    message info_2("8916777777", "Здарова Стэээээс, поздравь пж Сослана с др");
    
    list<message> list;
    list.push_back(info_1);
    list.push_back(info_2);
    ReadList(list);
    return 0;
}
void ReadList(const list<message>& info) {
    for (size_t i = 0; i < info.size(); ++i) {
        std::cout << "===Вышка #" << i+1 << std::endl;
        std::cout << info[i].GetNumber() << std::endl;
        std::cout << info[i].GetText() << std::endl;
        std::cout << std::endl;
    }
}
*/

// child_lvl_task
void Menu() {
    std::cout << "-*-*-*-*-*- Menu -*-*-*-*-*-\n";
    std::cout
        << "1. Добавить фигуру.\n"
        << "2. Удалить фигуру.\n"
        << "3. Чтение списка.\n"
        << "4. узнать коорднаты фигуры.\n"
        << "5. Очистить список.\n"
        << "6. Выход.\n";
}
template<typename T>
void PrintList(list<T>& list) {
    return;
}
template<>
void PrintList(list<figure>& list) {
    for (size_t i = 0; i < list.size(); ++i) {
        list[i].Print();
    }
}
template<typename T>
void Add(list<T>& list) {
    bool ok = true;
    figure new_figure;
    // создаём фигуру и задаем координаты
    do {
        new_figure.Creat();
        new_figure.Print();
        std::cout << "| Подтвердить добавление этой фигуры в список? (1|0): ";
        std::cin >> ok;
        // если что-то не понравилось то:
        if (!ok) {
            bool ok1;
            system("cls");
            std::cout << "| Хотите повторить ввод? (1|0): ";
            std::cin >> ok1;
            // если хотим повторить ввод, перезапускаем
            ok = !ok1;
        }
    } while (!ok);

    // добавляем в список
    PrintList(list);
    std::cout << "| Куда добавить фигуру? \n";
    std::cout << "1. В начало списка \n";
    std::cout << "2. В конец списка \n";
    std::cout << "3. Ввести свой индекс \n";
    size_t reply_adder = 0;
    std::cin >> reply_adder;
    switch (reply_adder)
    {
    case 1:
        list.push_front(new_figure);
        break;
    case 2:
        list.push_back(new_figure);
        break;
    case 3:
        std::cout << "| Введите индекс для вклейки в массив: ";
        std::cin >> reply_adder;
        list.insert(reply_adder, new_figure);
        break;
    default:
        break;
    }
}
template<typename T>
void Delete(list<T>& list) {
    system("cls");
    PrintList(list);
    std::cout << "1. Удалить в начале. \n2. Удалить в конце.\n3. Удалить по индексу" << std::endl;
    std::cout << "| Выберите пункт меню: ";
    size_t reply;
    std::cin >> reply;
    switch (reply)
    {
    case 1:list.pop_front(); break;
    case 2: list.pop_back(); break;
    case 3: 
        std::cout << "| Введите индекс: ";
        std::cin >> reply;
        list.removeIndex(reply);
        break;

    default:
        break;
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    list<figure> list;
    while (true) {
        Menu();
        int reply;
        std::cout << "Введите пункт меню: ";
        std::cin >> reply;
        switch (reply) {
        case 1: 
            system("cls");
            Add(list);
            break;
        case 2: 
            Delete(list);
            break;
        case 3: 
            PrintList(list);
            break;
        case 4: 
            size_t reply;
            std::cout << "| Введите индекс: ";
            std::cin >> reply;
            list[reply].Print();
            break;
        case 5:
            list.clear();
            break;

        case 6: 
            return 0;

        default:
            break;
        }
    }
}