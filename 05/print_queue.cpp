#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

std::vector<std::string> ruler;

bool is_correct(std::vector<int> update) // Part 1
{
    for(int i=0; i<update.size()-1; i++)
    {
        std::string str = std::to_string(update[i]);
        str += '|';
        str += std::to_string(update[i+1]);

        if(std::find(ruler.begin(), ruler.end(), str) == ruler.end())
        {
            return false;
        }
    }
    return true;
}

bool compare(int a, int b) // <
{
    std::string str = std::to_string(a);
    str += '|';
    str += std::to_string(b);

    return(std::find(ruler.begin(), ruler.end(), str) != ruler.end());
}

std::vector<int> correct(std::vector<int> update) // Part 2
{
    std::sort(update.begin(), update.end(), compare);
    return update;
}

std::vector<int> split(std::string str)// receives a line of numbers seperated by "," and returns a vector containing those numbers
{
    std::vector<int> numbers;
    size_t start = 0;
    size_t end = str.find(',');

    while (end != std::string::npos) {
        numbers.push_back(std::stoi(str.substr(start, end - start)));
        start = end + 1;
        end = str.find(',', start);
    }

    numbers.push_back(std::stoi(str.substr(start)));
    return numbers;
}

int main()
{
    std::string line;
    while(std::getline(std::cin, line))
    {
        if(line == "")
            break;
        ruler.push_back(line);
    }
    int total=0;
    int incorrect_update_total = 0;
    while(std::getline(std::cin, line))
    {
        std::vector<int> update = split(line);
        if(is_correct(update)) // Part 1
        {
            total += update[update.size()/2];
        }
        else // Part 2
        {
            std::vector<int> corrected = correct(update);
            incorrect_update_total += corrected[update.size()/2];
        }
    }
    std::cout << "Part 1: " << total << std::endl;
    std::cout << "Part 2: " << incorrect_update_total << std::endl;
    return 0;
}