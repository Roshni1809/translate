#include <string>
#include <vector>
#include <unordered_map>

using Dictionary = std::unordered_map<std::string, std::string>;
using OccuranceDictonary =  std::unordered_map<std::string, int>;

class Translate {

private:
    Dictionary dictonary;
    OccuranceDictonary occurance_dictonary;
    std::vector<std::string> words_in_file;
    bool CheckWordInDictonary(std::string &word);
    void InitializeOccuranceDictonary();

public:
    void ReadWordsFromFile(std::string file_name);
    void ReadDictonary(std::string file_name);
    void WriteWordsIntoFile(std::string file_name);
    void WriteOccuranceIntoFile(std::string file_name);
    void PerformTranslation();

};