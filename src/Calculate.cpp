#include "../include/Calculate.h"

using namespace std;

string postfix_note(string exp){

    Stack<char> opStack(256);
    Stack<char> trackStack(256);

    map <char, int> op;
    op['*'] = 3;
    op['/'] = 3;
    op['+'] = 2;
    op['-'] = 2;
    op['('] = 1;
    op['='] = 0;

    char buff;

    for (int i = 0; i < exp.length(); i++){
        buff = exp[i];
        if (op.count(buff)) {
            if ((!opStack.IsEmpty()) && (op[buff] <= op[opStack.Peek()]) && (buff != '('))
                while ((!opStack.IsEmpty()) && (op[buff] <= op[opStack.Peek()]))
                    trackStack.Push(opStack.Pop());


            opStack.Push(buff);
            continue;
        }

        if (isalpha(buff))	{
            trackStack.Push(buff);
            continue;
        }

        if (buff == ')') {
            while ((!opStack.IsEmpty()) && (opStack.Peek() != '('))
                trackStack.Push(opStack.Pop());
            if (opStack.IsEmpty())
                throw "не правильно расставлены скобки";
            opStack.Pop();
            continue;
        }
        throw "недопустимый символ";
    }
    while (!opStack.IsEmpty()){
        if (opStack.Peek() == '(')
            throw "не правильно расставлены скобки";
        trackStack.Push(opStack.Pop());
    }

    if (trackStack.IsEmpty())
        throw "нет данных";

    string result;
    string tmp;

    while (!trackStack.IsEmpty()) {
        tmp = trackStack.Pop();
        result.insert(0, tmp);
    }
    return result;
}

double Calculate(string exp)
{
    if (exp.empty())
        throw "нет данных";

    Stack<float> trackStack(256);
    char buff;
    float leftOperand;
    float rightOperand;

    map<char, float> val;

    for (int i = 0; i < exp.length(); i++){
        buff = exp[i];
        if (exp[exp.length() - 1] == '=')
            val[exp[0]] = 0;
        if (isalpha(buff)){
            if (!val.count(buff)){
                cout << '\t' << buff << " = ";
                cin >> val[buff];
            }
            trackStack.Push(val[buff]);
            continue;
        }
        if (trackStack.IsEmpty())
            throw "нет совпадения с числом операндов";

        rightOperand = trackStack.Pop();
        if (trackStack.IsEmpty())
            throw "нет совпадения с числом операндов";

        leftOperand = trackStack.Pop();

        switch (buff){
            case '+':{ trackStack.Push(leftOperand + rightOperand); break; }
            case '-':{ trackStack.Push(leftOperand - rightOperand); break; }
            case '*':{ trackStack.Push(leftOperand * rightOperand); break; }
            case '/':{ trackStack.Push(leftOperand / rightOperand); break; }
            default:break;
        }
    }

    float result = trackStack.Pop();
    if (!trackStack.IsEmpty())
        throw "Стэк переполнен";

    return result;
}