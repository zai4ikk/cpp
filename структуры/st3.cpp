/*Dynamic9◦

. Даны вершины A1 и A2 двух непустых стеков. Перемещать эле-
менты из первого стека во второй, пока значение вершины первого стека

не станет четным (перемещенные элементы первого стека будут распола-
гаться во втором стеке в порядке, обратном исходному). Если в первом

стеке нет элементов с четными значениями, то переместить из первого

стека во второй все элементы. Вывести ссылки на новые вершины пер-
вого и второго стека (если первый стек окажется пустым, то вывести для

него константу null). Новые объекты типа Node не создавать.*/

#include <iostream>
#include <stack>

int main() {
    // инициализируем первый стек A1
    std::stack<int> A1;
    A1.push(1);
    A1.push(3);
    A1.push(5);
    A1.push(2);
    A1.push(4);
    A1.push(6);

    // инициализируем второй стек A2
    std::stack<int> A2;

    // перемещаем элементы из первого стека во второй, пока значение вершины первого стека не станет четным
    while (!A1.empty() && A1.top() % 2 != 0) {
        A2.push(A1.top());
        A1.pop();
    }

    // перемещаем оставшиеся элементы из первого стека во второй
    while (!A1.empty()) {
        A2.push(A1.top());
        A1.pop();
    }

    // выводим ссылки на новые вершины первого и второго стека
    if (!A1.empty()) {
        std::cout << "New top of A1: " << &A1.top() << std::endl;
    } else {
        std::cout << "A1 = null" << std::endl;
    }

    if (!A2.empty()) {
        std::cout << "New top of A2: " << &A2.top() << std::endl;
    } else {
        std::cout << "A2 = null" << std::endl;
    }

    return 0;
}