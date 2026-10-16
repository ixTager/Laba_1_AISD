#include <iostream>
#include <string>
#include "DoublyLinkedList.h"
#include "DynamicList.h"
#include "Stack.h"

void printList(DoublyLinkedList<int>& list) {
    std::cout << "Текущий список: ";
    int i = 0;
    while (true) {
        auto node = list.getByIndex(i);
        if (node == nullptr) break;
        std::cout << *(node->data) << " <-> ";
        i++;
    }
    std::cout << "nullptr\n";
}

void printIntList(const DynamicList<int>& list) {
    std::cout << "Текущий массив (int): [ ";
    for (int i = 0; i < list.size(); i++) {
        std::cout << list.get(i) << " ";
    }
    std::cout << "]\n";
}

void printStringList(const DynamicList<std::string>& list) {
    std::cout << "Текущий массив (string): [ ";
    for (int i = 0; i < list.size(); i++) {
        std::cout << list.get(i) << " ";
    }
    std::cout << "]\n";
}

int main() {
    std::cout << "Двусвязный список\n\n";

    int val1 = 10;
    int val2 = 20;
    int val3 = 30;
    int val4 = 40;

    DoublyLinkedList<int> list;
    list.add(0, &val1);
    printList(list);

    list.add(0, &val2);
    printList(list);

    list.add(5, &val3);
    printList(list);

    list.add(1, &val4);
    printList(list);

    std::cout << "\nПоиск\n";
    auto searchNodeByIndex = list.getByIndex(1);
    if (searchNodeByIndex != nullptr) {
        std::cout << "Элемент по индексу 1: " << *(searchNodeByIndex->data) << " (Ожидалось: 40)\n";
    }

    auto searchNodeByVal = list.getByVal(&val3);
    if (searchNodeByVal != nullptr) {
        std::cout << "Найден адрес значения 30. Значение узла: " << *(searchNodeByVal->data) << "\n";
    }

    std::cout << "\nУдаление\n";
    list.remove(1);
    printList(list);

    list.remove(0);
    printList(list);



    std::cout << "\n\nДинамический массив (тип: int)\n\n";

    DynamicList<int> intList(2);

    intList.add(0, 10);
    intList.add(1, 30);
    intList.add(2, 40);
    std::cout << "После добавления 3-х элементов в конец:\n";
    printIntList(intList);

    intList.add(1, 20);
    std::cout << "\nПосле вставки числа 20 на индекс 1:\n";
    printIntList(intList);

    std::cout << "\nПоиск по значению\n";
    int index20 = intList.getIndexByVal(20);
    std::cout << "Индекс числа 20: " << index20 << " (Ожидалось: 1)\n";

    int indexMissing = intList.getIndexByVal(999);
    std::cout << "Индекс несуществующего числа 999: " << indexMissing << " (Ожидалось: -1)\n";

    std::cout << "\nНеверный ввод\n";
    int badData = intList.get(10);
    std::cout << "Полученное дефолтное значение: " << badData << " (Ожидалось: 0)\n";

    std::cout << "\nПроверка удаления\n";
    intList.remove(2);
    std::cout << "После удаления элемента с индекса 2:\n";
    printIntList(intList);


    std::cout << "\n\n Динамический массив (тип: string)\n\n";

    DynamicList<std::string> stringList;
    stringList.add(0, "Hello");
    stringList.add(1, "Kitty");
    stringList.add(1, "Nyamy");

    printStringList(stringList);


    std::cout << "\n\nСтек на основе двусвязного списка\n\n";

    Stack<int> myStack;
    int s1 = 100;
    int s2 = 200;
    int s3 = 300;

    std::cout << "Стек пуст? " << (myStack.isEmpty() ? "Да" : "Нет") << " (Ожидалось: Да)\n";

    myStack.push(&s1);
    myStack.push(&s2);
    myStack.push(&s3);

    std::cout << "Размер стека после 3-х push: " << myStack.size() << " (Ожидалось: 3)\n";

    if (myStack.getFirstElement() != nullptr) {
        std::cout << "Вершина стека (getFirstElement): " << *(myStack.getFirstElement()) << " (Ожидалось: 300)\n";
    }

    std::cout << "\nУдаляем элемент с вершины (pop)...\n";
    myStack.pop();

    std::cout << "Новая вершина стека: " << *(myStack.getFirstElement()) << " (Ожидалось: 200)\n";
    std::cout << "Текущий размер стека: " << myStack.size() << " (Ожидалось: 2)\n";

    myStack.pop();
    myStack.pop();

    std::cout << "\nПосле извлечения всех элементов:\n";
    std::cout << "Стек пуст? " << (myStack.isEmpty() ? "Да" : "Нет") << " (Ожидалось: Да)\n";
    std::cout << "Размер стека: " << myStack.size() << " (Ожидалось: 0)\n";

    return 0;
}
