#include "translate.hpp"
#include <chrono>
#include <iostream>

int main() {

    auto start_time = std::chrono::high_resolution_clock::now();   //To Track the execution time

    
    Translate translate;

    translate.ReadWordsFromFile("t8.shakespeare.txt");
    translate.ReadDictonary("french_dictionary.csv");

    translate.PerformTranslation();

    translate.WriteWordsIntoFile("t8.shakespeare.translated.txt");
    translate.WriteOccuranceIntoFile("frequency.csv");

    
    auto end_time = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
    std::cout<<"Time Taken is: "<<duration.count()<<" milliseconds\n";

    return 0;
}