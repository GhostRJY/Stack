#include<iostream>
#include"StackR.h"

int main()
{

    StackR<int> s1;
    StackR<int> s3;
    s3 = s1;

    if(s3.isEmpty())
        std::cout << "+\n";
    else
        std::cout << "-\n";

    s1.push(10);
    s1.push(15);
    s1.push(20);

    std::cout <<"S1 elements count " << s1.size() << '\n';
    s1.show("S1");

    if(s1.contains(11))
        std::cout << "S1 contains element\n";
    else
        std::cout << "S1 not contains element\n";

    //вношу меньшее значение
    std::cout << "Input less value\n";
    s1.pushLessValue(9);
    s1.show("S1");

    std::cout << "Input bigger value\n";
    s1.pushLessValue(10);
    s1.show("S1");

    //вношу уникальное значение
    std::cout << "Input unique value\n";
    s1.pushUnique(11);
    s1.show("S1");
    
    //вношу не уникальное значение
    std::cout << "Input not unique value\n";
    s1.pushUnique(9);
    s1.show("S1");

    StackR<int> s2 = s1;
    s2.show("S2");

    s3 = s2;
    s3.show("S3");

    if(s3.isEmpty())
        std::cout << "+";
    else
        std::cout << "-";


    return 0;
}