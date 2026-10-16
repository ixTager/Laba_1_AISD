#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>
#include "Stack.h"

class SYA {
private:
    static int getPriority(const std::string& op) {
        if (op == "sin" || op == "cos") return 4;
        if (op == "^") return 3;
        if (op == "*" || op == "/") return 2;
        if (op == "+" || op == "-") return 1;
        return 0;
    }

    static bool isOperator(const std::string& token) {
        return token == "+" || token == "-" || token == "*" || token == "/" || token == "^";
    }

    static bool isFunction(const std::string& token) {
        return token == "sin" || token == "cos";
    }

    static bool isNumber(const std::string& token) {
        if (token.empty()) return false;
        for (char c : token) {
            if (c < '0' || c > '9') return false;
        }
        return true;
    }

public:
    static std::string convert(const std::string& input) {
        Stack<std::string> operatorStack;
        std::string result = "";

        std::stringstream ss(input);
        std::string token;

        while (ss >> token) {
            if (isNumber(token)) {
                result += token + " ";
            }
            else if (isFunction(token)) {
                operatorStack.push(new std::string(token));
            }
            else if (token == "(") {
                operatorStack.push(new std::string(token));
            }
            else if (token == ")") {
                while (!operatorStack.isEmpty() &&
                    *(operatorStack.getFirstElement()) != "(") {
                    std::string* topOp = operatorStack.getFirstElement();

                    result += *topOp + " ";
                    operatorStack.pop();
                    delete topOp;
                }

                if (operatorStack.isEmpty()) {
                    throw std::runtime_error("mismatched parentheses");
                }

                std::string* leftBracket = operatorStack.getFirstElement();
                operatorStack.pop();
                delete leftBracket;

                if (!operatorStack.isEmpty() &&
                    isFunction(*(operatorStack.getFirstElement()))) {
                    std::string* func = operatorStack.getFirstElement();

                    result += *func + " ";
                    operatorStack.pop();
                    delete func;
                }
            }

            else if (isOperator(token)) {
                while (!operatorStack.isEmpty()) {
                    std::string topOp = *(operatorStack.getFirstElement());

                    bool condition = false;
                    if (token == "^") {
                        condition = (getPriority(topOp) > getPriority(token));
                    }
                    else {
                        condition = (getPriority(topOp) >= getPriority(token));
                    }

                    if (condition || isFunction(topOp)) {
                        std::string* opToDelete = operatorStack.getFirstElement();
                        result += *opToDelete + " ";
                        operatorStack.pop();
                        delete opToDelete;
                    }
                    else {
                        break;
                    }
                }
                operatorStack.push(new std::string(token));
            }
            else {
                throw std::runtime_error("unknown token: " + token);
            }
        }

        while (!operatorStack.isEmpty()) {
            std::string* op = operatorStack.getFirstElement();

            if (*op == "(") {
                delete op;
                operatorStack.pop();
                throw std::runtime_error("mismatched parentheses");
            }

            result += *op + " ";
            operatorStack.pop();
            delete op;
        }

        if (!result.empty()) {
            result.pop_back();
        }

        return result;
    }
};