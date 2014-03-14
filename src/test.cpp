// Alexis Giraudet
// Théo Cesbron

#include "dictionary.hpp"
#include "hash_table.hpp"
#include "hash_multi_set.hpp"
#include "link_multi_set.hpp"

int main(/*int argc, char *argv[]*/)
{
    const int s=10;
    
    std::cout << "Axiomes hash_multi_set" << std::endl;
    
    std::cout << "remove(add(hms, x), x) = hms" << std::endl;
    hash_multi_set<int,s> hms0;
    hms0.add(0);
    hms0.remove(0);
    hash_multi_set<int,s> hms1;
    if(hms0.equal(hms1))
    {
        std::cout << "Success" << std::endl;
    }
    else
    {
        std::cout << "Failure" << std::endl;
    }

    std::cout << "remove(ajouter(hms, y), x) = add(remove(hms, x), y); x != y" << std::endl;
    hash_multi_set<int,s> hms2;
    hms2.add(0);
    hms2.add(1);
    hms2.remove(0);
    hash_multi_set<int,s> hms3;
    hms3.add(0);
    hms3.remove(0);
    hms3.add(1);
    if(hms2.equal(hms3))
    {
        std::cout << "Success" << std::endl;
    }
    else
    {
        std::cout << "Failure" << std::endl;
    }

    std::cout << "remove_all(empty_hms, _) = empty_hms" << std::endl;
    hash_multi_set<int,s> hms4;
    hms4.remove_all(0);
    hash_multi_set<int,s> hms5;
    if(hms4.equal(hms5))
    {
        std::cout << "Success" << std::endl;
    }
    else
    {
        std::cout << "Failure" << std::endl;
    }

    std::cout << "remove_all(ajouter(hms, x), x) = remove_all(hms, x)" << std::endl;
    hash_multi_set<int,s> hms6;
    hms6.add(0);
    hms6.remove_all(0);
    hash_multi_set<int,s> hms7;
    hms7.remove_all(0);
    if(hms6.equal(hms7))
    {
        std::cout << "Success" << std::endl;
    }
    else
    {
        std::cout << "Failure" << std::endl;
    }

    std::cout << "remove_all(ajouter(hms, y), x) = add(remove_all(hms, x), y); x != y" << std::endl;
    hash_multi_set<int,s> hms8;
    hms8.add(0);
    hms8.add(1);
    hms8.remove_all(0);
    hash_multi_set<int,s> hms9;
    hms9.add(0);
    hms9.remove_all(0);
    hms9.add(1);
    if(hms8.equal(hms9))
    {
        std::cout << "Success" << std::endl;
    }
    else
    {
        std::cout << "Failure" << std::endl;
    }

    std::cout << "is_empty(empty_hms) = true" << std::endl;
    hash_multi_set<int,s> hms10;
    if(hms10.is_empty())
    {
        std::cout << "Success" << std::endl;
    }
    else
    {
        std::cout << "Failure" << std::endl;
    }

    std::cout << "is_empty(add(hms, _)) = false" << std::endl;
    hash_multi_set<int,s> hms11;
    hms11.add(0);
    if(!hms11.is_empty())
    {
        std::cout << "Success" << std::endl;
    }
    else
    {
        std::cout << "Failure" << std::endl;
    }

    std::cout << "count(empty_hms, _) = 0" << std::endl;
    hash_multi_set<int,s> hms12;
    if(hms12.count(0) == 0)
    {
        std::cout << "Success" << std::endl;
    }
    else
    {
        std::cout << "Failure" << std::endl;
    }

    std::cout << "count(add(hms, x), x) = 1 + count(hms, x)" << std::endl;
    hash_multi_set<int,s> hms13;
    hms13.add(0);
    hash_multi_set<int,s> hms14;
    if(hms13.count(0) == hms14.count(0)+1)
    {
        std::cout << "Success" << std::endl;
    }
    else
    {
        std::cout << "Failure" << std::endl;
    }

    std::cout << "count(add(hms, y), x) = count(hms, x); x != y" << std::endl;
    hash_multi_set<int,s> hms15;
    hms15.add(0);
    hms15.add(1);
    hash_multi_set<int,s> hms16;
    hms16.add(0);
    if(hms15.count(0) == hms16.count(0))
    {
        std::cout << "Success" << std::endl;
    }
    else
    {
        std::cout << "Failure" << std::endl;
    }

    std::cout << std::endl;

    std::cout << "Axiomes link_multi_set" << std::endl;
    
    std::cout << "remove(add(lms, x), x) = lms" << std::endl;
    link_multi_set<int> lms0;
    lms0.add(0);
    lms0.remove(0);
    link_multi_set<int> lms1;
    if(lms0.equal(lms1))
    {
        std::cout << "Success" << std::endl;
    }
    else
    {
        std::cout << "Failure" << std::endl;
    }

    std::cout << "remove(ajouter(lms, y), x) = add(remove(lms, x), y); x != y" << std::endl;
    link_multi_set<int> lms2;
    lms2.add(0);
    lms2.add(1);
    lms2.remove(0);
    link_multi_set<int> lms3;
    lms3.add(0);
    lms3.remove(0);
    lms3.add(1);
    if(lms2.equal(lms3))
    {
        std::cout << "Success" << std::endl;
    }
    else
    {
        std::cout << "Failure" << std::endl;
    }

    std::cout << "remove_all(empty_lms, _) = empty_lms" << std::endl;
    link_multi_set<int> lms4;
    lms4.remove_all(0);
    link_multi_set<int> lms5;
    if(lms4.equal(lms5))
    {
        std::cout << "Success" << std::endl;
    }
    else
    {
        std::cout << "Failure" << std::endl;
    }

    std::cout << "remove_all(ajouter(lms, x), x) = remove_all(lms, x)" << std::endl;
    link_multi_set<int> lms6;
    lms6.add(0);
    lms6.remove_all(0);
    link_multi_set<int> lms7;
    lms7.remove_all(0);
    if(lms6.equal(lms7))
    {
        std::cout << "Success" << std::endl;
    }
    else
    {
        std::cout << "Failure" << std::endl;
    }

    std::cout << "remove_all(ajouter(lms, y), x) = add(remove_all(lms, x), y); x != y" << std::endl;
    link_multi_set<int> lms8;
    lms8.add(0);
    lms8.add(1);
    lms8.remove_all(0);
    link_multi_set<int> lms9;
    lms9.add(0);
    lms9.remove_all(0);
    lms9.add(1);
    if(lms8.equal(lms9))
    {
        std::cout << "Success" << std::endl;
    }
    else
    {
        std::cout << "Failure" << std::endl;
    }

    std::cout << "is_empty(empty_lms) = true" << std::endl;
    link_multi_set<int> lms10;
    if(lms10.is_empty())
    {
        std::cout << "Success" << std::endl;
    }
    else
    {
        std::cout << "Failure" << std::endl;
    }

    std::cout << "is_empty(add(lms, _)) = false" << std::endl;
    link_multi_set<int> lms11;
    lms11.add(0);
    if(!lms11.is_empty())
    {
        std::cout << "Success" << std::endl;
    }
    else
    {
        std::cout << "Failure" << std::endl;
    }

    std::cout << "count(empty_lms, _) = 0" << std::endl;
    link_multi_set<int> lms12;
    if(lms12.count(0) == 0)
    {
        std::cout << "Success" << std::endl;
    }
    else
    {
        std::cout << "Failure" << std::endl;
    }

    std::cout << "count(add(lms, x), x) = 1 + count(lms, x)" << std::endl;
    link_multi_set<int> lms13;
    lms13.add(0);
    link_multi_set<int> lms14;
    if(lms13.count(0) == lms14.count(0)+1)
    {
        std::cout << "Success" << std::endl;
    }
    else
    {
        std::cout << "Failure" << std::endl;
    }

    std::cout << "count(add(lms, y), x) = count(lms, x); x != y" << std::endl;
    link_multi_set<int> lms15;
    lms15.add(0);
    lms15.add(1);
    link_multi_set<int> lms16;
    lms16.add(0);
    if(lms15.count(0) == lms16.count(0))
    {
        std::cout << "Success" << std::endl;
    }
    else
    {
        std::cout << "Failure" << std::endl;
    }

    return 0;
}
