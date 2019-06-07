#include <iostream>
#include <string>

struct shoe
{
    /*union  // anonymous union
    {
        char stdSize;
        int eurSize;
    }; */
    union size // the union typename "size" can be omitted
    {
        char stdSize;
        int eurSize;
    }m_size;
    bool type; // true means Standard Size, false means Euroupe Size
    std::string name;
};

// show the basic information of a shoe
void showTag(shoe &s)
{
    if (true == s.type)
    {
        std::cout << "Name: "  << s.name << ", Size is " << s.m_size.stdSize << std::endl;
    }
    else
    {
        std::cout << "Name: "  << s.name << ", Size is " << s.m_size.eurSize << std::endl;
    }
}

int main()
{
    /*shoe nike_air_force = {'M', "Nike Air Force Classic"};
    shoe new_balance_911 = {43, "New balance Model 911"};

    std::cout << "Name: "  << nike_air_force.name << ", Size is " << nike_air_force.stdSize << std::endl;
    std::cout << "Name: "  << new_balance_911.name << ", Size is " << new_balance_911.eurSize << std::endl; */
    shoe nike_air_force;
    nike_air_force.type = true;
    nike_air_force.name = "Nike Air Force Classical";
    nike_air_force.m_size.stdSize = 'L';

    shoe new_balance_911;
    new_balance_911.type = false;
    new_balance_911.name = "New balance Model 911";
    new_balance_911.m_size.eurSize = 44;

    showTag(nike_air_force);
    showTag(new_balance_911);

    return 0;
}