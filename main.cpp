#include "Header/BinTree.h"
#include "Header/Test.h"
#include "Header/QuickSort.h"
#include <vector>

int main()try
{
    std::vector<int> vectorTMP { 3, 0, 1, 8, 9, 6, 4, 7, 5, 2 };
    BinTree<int> binTree1{ };
    BinTree<int> binTree2{ };

    for (const auto& item : vectorTMP)
        binTree1.insert(item);

    check<int>(1, binTree1.find(1)->value, "Find '1' in Tree");

    std::cout << "binTree1.inOrder(): " << '\n';
    binTree1.inOrder();
    std::cout << '\n';

    std::cout << "binTree1.levelOrder(): " << '\n';
    binTree1.levelOrder();

    std::cout << '\n' << "anzahl alle kntoten: " << binTree1.size() << " " << binTree1.AnzahlKnoten(binTree1.getRoot());
    std::cout << '\n' << "anzahl recht: " << binTree1.AnzahlKnoten(binTree1.getRoot()->right);
    std::cout << '\n' << "anzahl left: " << binTree1.AnzahlKnoten(binTree1.getRoot()->left);

    std::cout << "\nbinTree2.inOrder(): " << '\n';
    binTree2.inOrder();
    std::cout << '\n';

    std::cout << "quicksort\n";
    std::vector<int> v1{7,4,345,43,51,364,732};
    quickSort(v1, 0, v1.size() - 1);
    for(const int& item : v1)
        std::cout << item << '\n';

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
