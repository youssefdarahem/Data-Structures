#include <iostream>
#include <vector>
#include <string>

struct student
{
    int id;
    std::string name;
};

int main()
{

    student std1 = student();
    std1.id = 45;
    std1.name = "name1";

    std::vector<int> vec;

    vec.push_back(5);
    vec.push_back(3);
    vec.push_back(4);

    // std::cout << vec.size() << std::endl;

    for (int i = 0; i < vec.size(); i++)
    {
        std::cout << vec.at(i) << std::endl;
    }

    for (int num : vec)
    {
        std::cout << num << " ";
    }

    return 0;
}