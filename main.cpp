#include "Header/BinTree.h"

int main()try
{
    BinTree binTree1{ };
    BinTree binTree2{ };

    std::string str = "34554797861342";

    for (const auto& item : str)
        binTree1.insert(item);

    std::cout << "node = binTree1.find('2'): exped 2: ";
    char tmp = binTree1.find('2')->value;
    if (binTree1.find('2'))
        std::cout << tmp << '\n';

    std::cout << "binTree1.inOrder(): " << '\n';
    binTree1.inOrder();
    std::cout << '\n';

    std::cout << "binTree1.levelOrder(): " << '\n';
    binTree1.levelOrder();

    std::cout << '\n' << "anzahl alle kntoten: " << binTree1.size() << " " << binTree1.AnzahlKnoten(binTree1.wurzel());
    std::cout << '\n' << "anzahl recht: " << binTree1.AnzahlKnoten(binTree1.wurzel()->right);
    std::cout << '\n' << "anzahl left: " << binTree1.AnzahlKnoten(binTree1.wurzel()->left);

    for (const auto& item : str)
        binTree2.insertKnotenWurzel(item);

    std::cout << "\nbinTree2.inOrder(): " << '\n';
    binTree2.inOrder();
    std::cout << '\n';

    return 0;
}
catch (std::exception& e)
{
    std::cerr << e.what();
    return -1;
}
catch (...)
{
    std::cerr << "some wrong";
    return -2;
}
