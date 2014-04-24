// Alexis Giraudet
// Théo Cesbron

#ifndef PARSER_DICTIONNAIRE_HPP
#define PARSER_DICTIONNAIRE_HPP

#include <algorithm>
#include <fstream>
#include "hash_dictionnaire.hpp"
#include "tree_dictionnaire.hpp"

using namespace std;

enum type_dictionnaire {HASH_DICTIONNAIRE, TREE_DICTIONNAIRE, UNKNOWN};

void help();
int main(int argc, char *argv[]);

class parser_dictionnaire
{
    protected:
        abstract_dictionnaire<int>* _dict;

    public:
        parser_dictionnaire(type_dictionnaire type);
        ~parser_dictionnaire();
        static bool compare(const pair<string,int>& first, const pair<string,int>& second);
        static bool is_punctuation(char c);
        void most_frequent(int n=10);
        int parse(ifstream& file);
        void print() const;

    protected:
        void add_word(const string& word);
};

parser_dictionnaire::parser_dictionnaire(type_dictionnaire type): _dict(0)
{
    switch(type)
    {
        case HASH_DICTIONNAIRE: _dict = new hash_dictionnaire<int>();
            break;
        case TREE_DICTIONNAIRE: _dict = new tree_dictionnaire<int>();
            break;
        case UNKNOWN: throw exception();
            break;
    }
}

parser_dictionnaire::~parser_dictionnaire()
{
    delete _dict;
}

void parser_dictionnaire::add_word(const string& word)
{
    try
    {
        (*_dict).associerMot(word,(*_dict).valeurAssociee(word)+1);
    }
    catch(exception& e)
    {
        (*_dict).ajouterMot(word,1);
    }
}

bool parser_dictionnaire::compare(const pair<string,int>& first, const pair<string,int>& second)
{
    return first.second > second.second;
}

bool parser_dictionnaire::is_punctuation(char c)
{
    return (c == '\n') || (c == ' ') || (c == '.') || (c == '?') || (c == '!') || (c == ',') || (c == ';') || (c == ':') || (c == '(') || (c == ')') || (c == '[') || (c == ']') /*|| (c == '«') || (c == '»')*/ || (c == '-');
}

void parser_dictionnaire::most_frequent(int n)
{
    cout << "Mots les plus fréquents:" << endl;
    list<pair<string, int> > ls;
    (*_dict).to_list(ls);
    ls.sort(compare);
    int i=0;
    for(list<pair<string, int> >::iterator it=ls.begin(); (it != ls.end()) && (i<n); i++, it++)
    {
        cout << i+1 << ") " << (*it).first << " (" << (*it).second << ")" << endl;
    }
}

int parser_dictionnaire::parse(ifstream& file)
{
    string word;
    word.clear();
    while(file.good())
    {
        char c(file.get());
        if(file.good())
        {
            if(is_punctuation(c))
            {
                if(!word.empty())
                {
                    transform(word.begin(),word.end(),word.begin(),::tolower);
                    add_word(word);
                    word.clear();
                }
            }
            else
            {
                word.push_back(c);
            }
        }
        else
        {
            if(!word.empty())
            {
                add_word(word);
            }
        }
    }
    file.close();
    /*triplet<string*,int*,int> tr = (*_dict).to_array();
    _words = tr.first;
    _frequencies = tr.second;
    _size = tr.third;*/
    return 0;
}

void parser_dictionnaire::print() const
{
    cout << *_dict;
}

int main(int argc, char *argv[])
{
    if(argc<2)
    {
        cout << "Utilisation : parse [-hash | -tree]  [OPTIONS] [FICHIER]" << endl;
        cout << "Saisissez « parse -help » pour plus d'informations." << endl;
        return 1;
    }

    ifstream file;
    type_dictionnaire type(UNKNOWN);
    bool print(false);
    bool most_frequent(false);

    for(int i=1; i<argc; i++)
    {
        string arg(argv[i]);
        if(argv[i][0] == '-')
        {
            if(arg == "-tree")
            {
                type = TREE_DICTIONNAIRE;
            }
            else if(arg == "-hash")
            {
                type = HASH_DICTIONNAIRE;
            }
            else if(arg == "-print")
            {
                print = true;
            }
            else if(arg == "-most-frequent")
            {
                most_frequent = true;
            }
            else if(arg == "-help")
            {
                help();
                return 0;
            }
            else
            {
                cout << "parse: option invalide - '" << arg <<"'" << endl;
                cout << "Saisissez « parse -help » pour plus d'informations." << endl;

                return 1;
            }
        }
        else
        {
            if(file.is_open())
            {
                cout << "parse: indiquez un seul fichier à charger" << endl;
                cout << "Saisissez « parse -help » pour plus d'informations." << endl;
                return 1;
            }
            else
            {
                file.open(arg);
            }
        }
    }
    
    if(type == UNKNOWN)
    {
        cout << "parse: indiquez la classe dictionnaire à utiliser" << endl;
        cout << "Saisissez « parse -help » pour plus d'informations." << endl;
        return 1;
    }
    if(!file.is_open())
    {
        cout << "parse: impossible d'ouvrir le fichier" << endl;
        cout << "Saisissez « parse -help » pour plus d'informations." << endl;
        return 1;
    }

    parser_dictionnaire parser(type);
    cout << "Mots chargés: " << parser.parse(file) << endl;
    if(print)
    {
        parser.print();
    }
    if(most_frequent)
    {
        parser.most_frequent();
    }

    return 0;
}

void help()
{
    cout << "Utilisation : parser [-hash | -tree]  [OPTIONS] [FICHIER]" << endl;
    cout << "Parcours le fichier passé en paramètre et charge les mots dans la structure de dictionnaire indiquée." << endl << endl;
    cout << "-hash             utilise la classe hash_dictionnaire" << endl;
    cout << "-tree             utilise la classe tree_dictionnaire" << endl;
    cout << "-print            affiche le contenu du dictionnaire" << endl;
    cout << "-most-frequent    affiche les dix mots les plus fréquents" << endl;
    cout << "-help             affiche l'aide" << endl;
}

#endif
