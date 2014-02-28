// Alexis Giraudet
// Théo Cesbron

#include "dictionary.hpp"
//#include "hash_table.hpp"

int main(int argc, char *argv[])
{
    dictionary<int,int> test_map;
    
    //On vérifie que la map est vide
    std::cout << test_map.is_empty() << std::endl;
    
    //On ajoute un élement de clé 1 et de valeur 1
    test_map.put(1,1);
    
    //On affiche la valeur correspondant a la clé 1
    std::cout << test_map.get(1) << std::endl;
    
    //On ajoute une deuxieme valeur
    test_map.put(2,2);
    
    //On vérifie si la clé 2 existe
    std::cout << test_map.contains_key(2) << std::endl;
    
    //On verifie si la valeur 2 existe
    std::cout << test_map.contains_value(2) << std::endl;
    
    //On affiche la taille de la chaine
    std::cout << test_map.size() << std::endl;
    
    //On supprime toute la map
    test_map.remove(2);
    
    //On affiche la map
    std::cout << test_map;
    
    //On supprime toute la map
    test_map.clear();
    
    //On vérifie que la map est vide
    std::cout << test_map.is_empty() << std::endl;

    return 0;
}
