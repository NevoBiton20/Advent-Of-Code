#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

// Part 1
bool is_safe(std::vector<int> report,int index)
{
    int diff = report[0]-report[1];
    for(int i = index; i<report.size()-1;i++)
    {
        int diff2 = report[i] - report[i+1];
        if(diff*diff2 <= 0 || (abs(diff2) != 1 && abs(diff2) != 2 && abs(diff2) != 3))
        {
            return false;
        }
    }
    return true;
}

// Part 2
bool is_tolerant_safe(std::vector<int> report)
{
    for(int i = 0; i<report.size();i++)
    {
        std::vector<int> temp2 = report;
        temp2.erase(temp2.begin() + i);
        if(is_safe(temp2,0))
        {
            return true;
        }
    }
    return false;
}


int main()
{
    int safe_reports=0;
    std::string input;
    while(std::getline(std::cin, input))
    {
        std::istringstream iss(input);
        std::vector<int> report;
        int x;
        while(iss >> x)
        {
            report.push_back(x);
        }
        int diff = report[0]-report[1];
        if(report.size() <= 2)
        {
            safe_reports++;
        }
        else if(is_safe(report,0))
        {
            safe_reports++;
        }
        else if(is_tolerant_safe(report)) // For part 1 delete this else if
        {
            safe_reports++;
        }
    }
    std::cout << safe_reports;
    return 0;
}
