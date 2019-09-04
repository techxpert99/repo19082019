/**
  * @author Ritik Jain
  * @date 25/08/2019
  * @file dictionary.h
  * @brief Dictionary Headers File
  */

#ifndef DICTIONARY_H
#define DICTIONARY_H

//The alphabet set size
const int ALPH_SIZ = 26;

//The buffer size
const int BUF_SZ = 1024;

/**
 * @brief The Node for the Trie Structure
 * @author Ritik Jain
 * @date 25/08/2019
 */
struct Node
{
    //The value of the node
    char *v = nullptr;
    //The children of the node (ALPH_SIZ = 26 in all)
    Node *c[ALPH_SIZ];
};

/**
 * @brief The Trie datastructure for the Dictionary
 * @author Ritik Jain
 * @date 25/08/2019
 */
class Trie
{
public:

    /**
     * @brief Trie's Constructor
     * @date 25/08/2019
     * @author Ritik Jain
     */
    Trie();

    /**
     * @brief Inserts the <word, meaning> in the trie
     * @author Ritik Jain
     * @date 25/08/2019
     * @param word  The word to be inserted in the trie
     * @param mean  The meaning of the word to be inserted
     * @return Returns whether the word was inserted or not
     */
    bool insert(char* word, char* mean);

    /**
     * @brief search
     * @author Ritik Jain
     * @date 25/08/2019
     * @param word The word to be searched in the trie
     * @return Returns the meaning of the word if it exists else a null pointer
     */
    char* search(char* word);

    ~Trie();

private:
    //The root of the trie
    Node *root = nullptr;
};

/**
 * @brief The Dictionary
 * @author Ritik Jain
 * @date 25/08/2019
 */
class Dictionary
{
public:
    /**
     * @brief Constructor for the Dictionary
     * @date 25/08/2019
     * @author Ritik Jain
     */
    Dictionary();

    /**
     * @brief Loads the dictionary and stores it in a trie
     * @author Ritik Jain
     * @date 25/08/2019
     * @param file  The location of the dictionary
     * @return Whether or not the dictionary was loaded
     */
    bool load(char* file);

    /**
     * @brief Searches for a word in the dictionary
     * @author Ritik Jain
     * @date 25/08/2019
     * @param word  The word to be searched
     * @return Returns the word if found; otherwise returns a null pointer
     */
    char* search(char* word);


    ~Dictionary();
private:

    /**
     * @brief Formats a string to convert it into a valid word depending on the mode
     * @author Ritik Jain
     * @date 25/08/2019
     * @param s  The string to be formatted
     * @param mod  The mode in which the string is to be formatted
     * @return The word if valid; otherwise null pointer
     */
    char* format(char* s, int mod);

    /**
     * @brief Trims a string
     * @param s  The string to be trimmed
     * @return The trimmed string ; otherwise null pointer
     */
    char* trim(char* s);

    //The trie datastructure for the dictionary
    Trie data;
};

#endif // DICTIONARY_H
