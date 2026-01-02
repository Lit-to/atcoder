#include <iostream>
/**
 * trueのとき"Yes"/Falseのとき"No"を返す関数
 */
void sayYesNo(bool value)
{
    if (value)
    {
        std::cout << "Yes" << std::endl;
    }
    else
    {
        std::cout << "No" << std::endl;
    }
}