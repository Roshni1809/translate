#include "translate.hpp"
#include <iostream>
#include <fstream>
#include <algorithm>

void Translate::ReadWordsFromFile(std::string file_name) {
    std::ifstream stream(file_name);
    stream >> std::noskipws;
    std::string temp;
    char c;

    while(stream >> c) {
        if(c == ' ' || c == '\t' || c == '\n') {
            if(!temp.empty()) {
                words_in_file.push_back(temp);
                temp.clear();
            }
            temp += c;
            words_in_file.push_back(temp);
            temp.clear();
        }
        else {
            temp += c;
        }
    }
}

void Translate::ReadDictonary(std::string file_name) {
    std::ifstream stream(file_name);
    stream >> std::noskipws;
    std::string temp_key;
    std::string temp_value;
    char c;
    while(stream >> c) {
        if(c == ',') {
            while(stream >>c && c != '\n') {
                temp_value += c;
            }
            dictonary[temp_key] = temp_value;
            temp_key.clear();
            temp_value.clear();
        }
        else {
            temp_key += c;
        }
    }
    InitializeOccuranceDictonary();
}

void Translate::InitializeOccuranceDictonary() {
    for(auto word : dictonary) {
    occurance_dictonary[word.first] = 0;
  }
}

void Translate::WriteWordsIntoFile(std::string file_name) {
    std::fstream file;
    file.open(file_name);
 
    for(auto word : words_in_file)
    {
        file<<word;
    }
 
    file.close();
}

void Translate::WriteOccuranceIntoFile(std::string file_name) {
    std::fstream file;
    file.open(file_name);
 
    for(auto word : dictonary)
    {
        std::string sentence = word.first + "," + word.second + "," + std::to_string(occurance_dictonary[word.first]) +  "\n";
        file<<sentence<<"";
    }
 
    file.close();
}

bool Translate::CheckWordInDictonary(std::string &word) {
    int start_position = 0,
        size = word.size();
    int end_position = size - 1;
        
    
    //Check if Word Start or end with special character. E.g (),;
    if(!isalpha(word.at(0))) {
        start_position++;
        size--;
    }
    if(!isalpha(word.at(end_position))) {
        size--;
    }

    std::string temp_word = word.substr(start_position, size);

    if(dictonary.find(temp_word) != dictonary.end()) {
        occurance_dictonary[temp_word] ++;  // Update Occurance Dictonary
        temp_word = dictonary[temp_word];
        word.replace(start_position, size, temp_word);
        return true;
    }
    return false;
}

void Translate::PerformTranslation() {
    for(int i = 0; i < words_in_file.size(); i ++) {
    std::string word = words_in_file[i];
    if(CheckWordInDictonary(word)) {
        words_in_file[i] = word;
    }
  }
}

 