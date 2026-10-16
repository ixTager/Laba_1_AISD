#include <iostream>
#include <string>
#include <sstream>
#include "DoublyLinkedList.h"
#include "DynamicList.h"
#include "Stack.h"
#include "SYA.h"

bool isValidPostfix(const std::string& postfix) {
    if (postfix.empty()) return false;

    if (postfix.find('(') != std::string::npos || postfix.find(')') != std::string::npos) {
        return false;
    }
    return true;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string inputExpression;

    if (!std::getline(std::cin, inputExpression)) {
        std::cerr << "Ошибка" << std::endl;
        return 1;
    }

    std::cout << inputExpression << "\n";

    std::cout << "\n";

    std::string postfixResult;

    try {
        postfixResult = SYA::convert(inputExpression);
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << "\n";
        return 1;
    }

    if (!isValidPostfix(postfixResult)) {
        std::cerr << "Ошибка" << std::endl;
        return 1;
    }

    std::stringstream ss(postfixResult);
    std::string token;

    while (ss >> token) {
        std::cout << token << ",";
    }
    std::cout << "\n";

    return 0;
}
