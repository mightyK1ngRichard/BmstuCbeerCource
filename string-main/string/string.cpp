#include "Header.h"

int main() {
    std::cout << "-----------------SUM-----------------\n";
    String surname("Permyakov"), name("Dmitriy");
    std::cout << name << " + " << surname << " = ";
    String MyFullName = name + surname;
    std::cout << MyFullName << std::endl;
    MyFullName += name;
    std::cout << MyFullName << " + " << name << " = ";
    std::cout << MyFullName << std::endl;

    std::cout << "\n------------SIZE+FIND+EMPTY------------\n";
    String one("111112233333"), two("223");
    std::cout << "WORD: (" << one << ")\n";
    std::cout << "Find: " << one.Find(two) << std::endl;
    ;
    std::cout << "Empty: " << one.Empty() << std::endl;
    std::cout << "Size: " << one.Size() << std::endl;

    std::cout << "\n--------------Comparison--------------\n";
    std::cout << " OUR WORDS: (" << one << ")  (" << two << ")\n";
    if (one == two)
        std::cout << one << " == " << two << std::endl;
    else
        std::cout << one << " != " << two << std::endl;
    if (one != two)
        std::cout << one << " != " << two << std::endl;
    else
        std::cout << one << " == " << two << std::endl;
    if (one < two)
        std::cout << one << " < " << two << std::endl;
    else
        std::cout << two << " < " << one << std::endl;
    if (one > two)
        std::cout << one << " > " << two << std::endl;
    else
        std::cout << two << " > " << one << std::endl;

    std::cout << "\n-----------------SWAP-----------------\n";
    std::cout << "=Before swap:\n";
    std::cout << one << std::endl;
    std::cout << two << std::endl;
    std::cout << "=After swap:\n";
    one.swap(two);
    std::cout << one << std::endl;
    std::cout << two << std::endl;

    std::cout << "\n-----------------TRIM-----------------\n";
    String str("______string_______");
    std::cout << str << std::endl;
    str.RTrim('_');
    std::cout << str << std::endl;
    str.LTrim('_');
    std::cout << str << std::endl;

    std::cout << "\n============Multiplication============\n";
    String MultiplicationString("AAO");
    std::cout << " WORD: (" << MultiplicationString << ")\n";
    String NewMultiplicationString = MultiplicationString * 3;
    std::cout << NewMultiplicationString << std::endl;
    MultiplicationString *= 4;
    std::cout << MultiplicationString << std::endl;
    std::cout << MultiplicationString * 5 << std::endl;

    std::cout << "\n============Replace============\n";
    String wordReplace("Hello World!");
    std::cout << "Before: " << wordReplace << std::endl;
    wordReplace.Replace('l', 'e');
    std::cout << "After: " << wordReplace << std::endl;

    std::cout << "\n------------Operetor []------------\n";
    std::cout << wordReplace << std::endl;
    std::cout << "wordReplace[6]: " << wordReplace[6] << std::endl;
    wordReplace[0] = 'E';
    std::cout << wordReplace << std::endl;
    return 0;
}
