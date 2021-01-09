#include "namespace_ex.h"

int main()
{
    meow_mur::Algorithm A;
    std::fstream file;
    file.open("T2.txt", std::ios::out);
    try {
        if (!file.is_open())
        {
            throw 1;
        }
        std::cout << "File T2 is open!" << std::endl;
    }
    catch (int i)
    {
        meow_mur::Exception ex(i);
        ex.Print();
        return 0;
    }
    std::list<meow_mur::exam> list;
    meow_mur::exam student1("Alexey", 10, 1), student2("Andrey", 7, 2), student3("Sergey", 6, 3), student4("Vadim", 5, 4), student5("Gleb", 4, 5);
    file << student1;
    file << student2;
    file << student3;
    file << student4;
    file << student5;
    file.close();
    A.algorithm_1("7");
    list.push_back(student1);
    list.push_back(student2);
    list.push_back(student3);
    list.push_back(student4);
    list.push_back(student5);
    try {
        if (list.size() <= 0)
        {
            throw 2;
        }
    }
    catch (int i)
    {
        meow_mur::Exception eax(i);
        eax.Print();
        return 0;
    }
    std::list<meow_mur::exam>::iterator It;
    It = list.begin();
    while (It != list.end())
    {
        std::cout << *It;
        It++;
    }
    A.algorithm_2(It = list.begin(), It = list.end());
    A.algorithm_3(It = list.begin(), It = list.end());
    return 0;
}
