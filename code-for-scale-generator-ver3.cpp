#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <map>
#include <cmath>
#include <cstdlib>
#include <ctime>

std::vector<int> generateRandomNumbers() {
    std::vector<int> numbers;
    std::vector<int> pool = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    std::random_device rd;
    std::mt19937 gen(rd());
    std::shuffle(pool.begin(), pool.end(), gen);
    
    numbers.push_back(0); // Insert 0 at the beginning
    for (int i = 0; i < 6; ++i) {
        numbers.push_back(pool[i]);
    }
    
    return numbers;
}

void sortNumbers(std::vector<int>& numbers) {
    std::sort(numbers.begin(), numbers.end());
}

std::vector<std::string> assignMusicalNotes(const std::vector<int>& orderedNumbers) {
    std::map<int, std::string> noteMap = {
        {0, "C"}, {1, "C#/Db"}, {2, "D"}, {3, "D#/Eb"},
        {4, "E"}, {5, "F"}, {6, "F#/Gb"}, {7, "G"},
        {8, "G#/Ab"}, {9, "A"}, {10, "A#/Bb"}, {11, "B"}
    };
    
    std::vector<std::string> notes;
    for (int number : orderedNumbers) {
        if (noteMap.find(number) != noteMap.end()) {
            notes.push_back(noteMap[number]);
        }
    }
    return notes;
}

std::string generateBinaryNumber(const std::vector<int>& indices) {
    std::string binaryNumber(12, '0');
    for (int index : indices) {
        if (index >= 0 && index < 12) {
            binaryNumber[11 - index] = '1';
        }
    }
    return binaryNumber;
}

int binaryToDecimal(const std::string& binaryNumber) {
    int decimalNumber = 0;
    for (size_t i = 0; i < binaryNumber.size(); ++i) {
        if (binaryNumber[binaryNumber.size() - 1 - i] == '1') {
            decimalNumber += std::pow(2, i);
        }
    }
    return decimalNumber;
}

std::vector<std::string> generateChordProgression() {
    std::vector<std::vector<std::string>> progressions = {
        {"I", "IV", "V"},
        {"ii", "V", "I"},
        {"I", "vi", "IV", "V"},
        {"I", "IV", "ii", "V"},
        {"I", "V", "vi", "iii"},
        {"IV", "V", "I"},
        {"vi", "IV", "I", "V"}
    };

    std::srand(std::time(0));
    int index = std::rand() % progressions.size();
    return progressions[index];
}


int main() {
    std::vector<int> randomNumbers = generateRandomNumbers();
    //test numbers
    for (int num : randomNumbers) {
        std::cout << num << " ";
    } 
    
    std::cout << "\n";
    //sort numbers
    sortNumbers(randomNumbers);
    for (int num : randomNumbers) {
        std::cout << num << " ";
    }

    std::cout << "\n";
    //assign note names
    std::vector<std::string> musicalNotes = assignMusicalNotes(randomNumbers);
    for (const std::string& note : musicalNotes) {
        std::cout << note << " ";
    }
    
    std::cout << "\n";
    //generate ID numbers for scales
    std::vector<int> indices = randomNumbers;
    std::string binaryNumber = generateBinaryNumber(indices);
    int decimalNumber = binaryToDecimal(binaryNumber);
    std::cout << "BinID: " << binaryNumber << std::endl;
    std::cout << "DecID: " << decimalNumber << std::endl;
    
    std::cout << "Chords you can use: ";
    //generate random chord progression to use
    std::vector<std::string> progression = generateChordProgression();
    for (const auto& chord : progression) {
        std::cout << chord << " ";
    }

    return 0;
}