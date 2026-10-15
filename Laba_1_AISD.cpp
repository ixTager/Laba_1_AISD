#include <iostream>
#include "DoublyLinkedList.h"

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

int main()
{
    std::cout << "=== Тестирование двусвязного списка ===\n\n";

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

    std::cout << "\n--- Проверка поиска ---\n";
    auto searchNodeByIndex = list.getByIndex(1);
    if (searchNodeByIndex != nullptr) {
        std::cout << "Элемент по индексу 1: " << *(searchNodeByIndex->data) << " (Ожидалось: 40)\n";
    }

    auto searchNodeByVal = list.getByVal(&val3);
    if (searchNodeByVal != nullptr) {
        std::cout << "Найден адрес значения 30. Значение узла: " << *(searchNodeByVal->data) << "\n";
    }

    std::cout << "\n--- Проверка удаления ---\n";
    list.remove(1);
    printList(list);

    list.remove(0);
    printList(list);
}
