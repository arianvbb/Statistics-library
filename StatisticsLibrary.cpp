/*

PS: This is made mainly for comma seperated files, CSVs. Make sure this code and a CSV share the same
folder and then change File.open() to include your file name. This is statistics so we do using
templates allow for float, double or int but strings and chars would mess with calculations so that
will return errors.

*/

//-------------------------------------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <string>
#include <map>
#include <cmath>

template<typename T>
void Print(const std::vector<T>& Data);

template<typename T>
void Median(std::vector<T> Data);

template<typename T>
void Average(const std::vector<T>& Data);

template<typename T>
void MinMax(const std::vector<T>& Data);

template<typename T>
void Variance(const std::vector<T>& Data);

template<typename T>
void Mode(const std::vector<T>& Data);

template<typename T>
void SDeviation(const std::vector<T>& Data);

template<typename T>
void Count(const std::vector<T>& Data);

int main(){
    std::vector<std::string> DataOne;
    std::vector<double> Data;


    int column;
    std::cout << "Which column in the CSV do you wanna read?: ";
    std::cin >> column;

    // Reads our csv file
    std::ifstream File;
    File.open("robotics_telemetry.csv");
    if(File.is_open()){
        std::string line;
        while(getline(File, line)){
            // Removes all data in the columns before the wanted data.
            for(int i = 0; i < column - 1; i++){
                line.erase(0, line.find(',') + 1);
            }
            // Removes remaining data in the rest of the columns after the wanted column.
            if(line.find(',') != std::string::npos){
                line.erase(line.find(','), line.length() - line.find(','));
            }
            DataOne.emplace_back(line);
        }
    }
    // For instances where the file isn't encountered, terminates the program.
    else{
        std::cout << "Error opening file.\n";
        return 1;
    }

    File.close();

    // Removes the header (text that ruins our datatype conversion)
    DataOne.erase(DataOne.begin());


    // Turn the string data type to double
    for(const std::string& s : DataOne){
        Data.emplace_back(std::stod(s));
    }

    bool state = true;
    int answer;

    while(state == true){
        std::cout << "Welcome to the statistics library, what would you like to do with your data?:\n";
        std::cout << "******************************\n";
        std::cout << "1. Print it.\n";
        std::cout << "2. Find the median.\n";
        std::cout << "3. Find the average.\n";
        std::cout << "4. Find lowest & highest value.\n";
        std::cout << "5. Find the variance.\n";
        std::cout << "6. Find the mode.\n";
        std::cout << "7. Standard deviation.\n";
        std::cout << "8. Count.\n";
        std::cout << "9. Exit.\n";
        std::cin >> answer;
        switch(answer){
            case 1: Print(Data); break;
            case 2: Median(Data); break;
            case 3: Average(Data); break;
            case 4: MinMax(Data); break;
            case 5: Variance(Data); break;
            case 6: Mode(Data); break;
            case 7: SDeviation(Data); break;
            case 8: Count(Data); break;
            case 9: state = false; break;
            default: std::cout << "Not a valid input!\n"; break;
        }
    }

    std::cout << "Have a wonderful day!\n";

    return 0;
}

template<typename T>
void Print(const std::vector<T>& Data){
    std::cout << "*************\n";
    for(size_t i = 0; i < Data.size(); i++){
        std::cout << Data[i] << '\n';
    }
    std::cout << "*************\n";
}

template<typename T>
void Median(std::vector<T> Data){
    std::sort(Data.begin(), Data.end());
    std::cout << "*************\n";
    std::cout << "Median: " << Data[(int) Data.size() / 2] << '\n';
    std::cout << "*************\n";
}

template<typename T>
void Average(const std::vector<T>& Data){
    double Total = 0;
    for(size_t i = 0; i < Data.size(); i++){
        Total += Data[i];
    }
    std::cout << "*************\n";
    std::cout << "Average: " << Total / Data.size() << '\n';
    std::cout << "*************\n";
}

template<typename T>
void MinMax(const std::vector<T>& Data){
    // Using max_element and min_element to find the highest and lowest value in our dataset.
    double max = *std::max_element(Data.begin(), Data.end());
    double min = *std::min_element(Data.begin(), Data.end());
    std::cout << "*************\n";
    std::cout << "Lowest: " << min << '\n';
    std::cout << "Highest: " << max << '\n';
    std::cout << "*************\n";
}

template<typename T>
void Variance(const std::vector<T>& Data){
    // Calculate mean
    double Total = 0;
    for(size_t i = 0; i < Data.size(); i++){
        Total += Data[i];
    }

    // Calculate variance
    double variance = 0;
    for(size_t i = 0; i < Data.size(); i++){
        variance += std::pow(Data[i] - (Total / Data.size()), 2);
    }
    std::cout << "*************\n";
    std::cout << "Variance: " << variance / Data.size() << '\n';
    std::cout << "*************\n";
}

template<typename T>
void Mode(const std::vector<T>& Data){

    std::map<T, int> FrequencyCounter;
    for(size_t i = 0; i < Data.size(); i++){
        if(FrequencyCounter.count(Data[i]) >= 1){
            FrequencyCounter[Data[i]] ++;
        }
        else{
            FrequencyCounter.insert({Data[i], 1});
        }
    }
    auto Result = std::max_element(FrequencyCounter.begin(), FrequencyCounter.end(),
        [](const auto& a, const auto& b){
            return a.second < b.second;
        });
    std::cout << "*************\n";
    std::cout << "Most common value: " << Result->first << '\n';
    std::cout << "*************\n";
}

template<typename T>
void SDeviation(const std::vector<T>& Data){
    // Calculate mean
    double Total = 0;
    for(size_t i = 0; i < Data.size(); i++){
        Total += Data[i];
    }

    // Calculate variance
    double variance = 0;
    for(size_t i = 0; i < Data.size(); i++){
        variance += std::pow(Data[i] - (Total / Data.size()), 2);
    }

    std::cout << "*************\n";
    std::cout << "Standard deviation: " << std::sqrt(variance / Data.size()) << '\n';
    std::cout << "*************\n";
}

template<typename T>
void Count(const std::vector<T>& Data){
    std::cout << "*************\n";
    std::cout << "Count: " << Data.size() << '\n';
    std::cout << "*************\n";
}