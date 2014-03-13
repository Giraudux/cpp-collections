// Alexis Giraudet
// Théo Cesbron

#include "dictionary.hpp"
#include "hash_table.hpp"
#include "hash_multi_set.hpp"
#include "link_multi_set.hpp"

int main(/*int argc, char *argv[]*/)
{
    hash_multi_set<int,10> hms;
    link_multi_set<int> lms;
    
    hms.add(0);
    hms.add(1);
    hms.add(1);
    hms.add(1);
    hms.add(2);
    hms.add(2);
    hms.add(3);
    hms.add(4);
    
    std::cout << hms.count(0) << std::endl;
    std::cout << hms.count(1) << std::endl;
    std::cout << hms.count(2) << std::endl;
    std::cout << hms.count(3) << std::endl;
    std::cout << hms.count(4) << std::endl;
    std::cout << hms.count(14) << std::endl;
    std::cout << hms.size() << std::endl;

    return 0;
}
