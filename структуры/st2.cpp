/*Dynamic6. Дана вершина A1 стека, содержащего не менее десяти элементов.

Извлечь из стека первые девять элементов и вывести их значения. Выве-
сти также ссылку на новую вершину стека. После извлечения элементов

из стека освобождать ресурсы, которые они использовали, вызывая для
этих элементов метод Dispose.*/

#include <iostream>

class Element {
public:
    int value;
    Element* next;

    Element(int value) {
        this->value = value;
        this->next = nullptr;
    }

    ~Element() {
        // освобождаем ресурсы, используемые элементом
        Dispose(this->value);
    }
};

int main() {
    // создаем первый элемент стека
    Element* A1 = new Element(10);

    // добавляем остальные элементы в стек
    for (int i = 9; i > 0; i--) {
        Element* e = new Element(i * 10);
        e->next = A1;
        A1 = e;
    }

    Element* A2 = A1->next; // сохраняем ссылку на новую вершину стека

    // извлекаем первые девять элементов из стека и выводим их значения
    for (int i = 1; i <= 9; i++) {
        Element* e = A1;
        A1 = A1->next;
        std::cout << e->value << std::endl;
        delete e; // удаляем элемент из памяти
    }

    // выводим ссылку на новую вершину стека
    if (A2 != nullptr) {
        std::cout << "A2: " << A2 << std::endl;
    } else {
        std::cout << "A2 = null" << std::endl;
    }

    delete A1; // удаляем последний элемент из памяти

    return 0;
}