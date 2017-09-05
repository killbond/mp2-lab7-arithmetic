#include "include/Calculate.h"


using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Введите выражение в общем виде" << endl;
    cout << "input=" << endl;
    string input;
    cout << '\t';
    cin >> input;
    string notation;
    double result;
    try {
        notation = postfix_note(input);
        result = Calculate(notation);
    }
    catch (...){
        cout << "Ошибка выражения" << endl;
        return 1;
    }

    cout << endl;
    cout << "Польская форма" << endl;
    cout << '\t' << notation << endl;
    cout << endl;
    cout << "Результат" << endl;
    cout << '\t' << result << endl;
}