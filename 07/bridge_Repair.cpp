#include <iostream>
#include <vector>
#include <cmath>
#include <sstream>

void increment(std::vector<bool>& elements)
{
    int n = elements.size();
    bool carry = true;

    for (int i = n - 1; i >= 0 && carry; --i) {
        if (elements[i]) {
            elements[i] = false;
        } else {
            elements[i] = true;
            carry = false;
        }
    }
}

void incrementTernary(std::vector<int>& ternary) {
    int carry = 1;
    for (size_t i = 0; i < ternary.size(); ++i) {
        ternary[i] += carry;
        if (ternary[i] < 3) {
            carry = 0;
            break;
        } else {
            ternary[i] = 0;
        }
    }
}

long long merge(long long a, long long b)
{
    long long temp = b;
    int digits = 0;
    while(temp!=0)
    {
        temp/=10;
        digits++;
    }
    return a*pow(10,digits) + b;
}

bool can_be_computed(long long target, std::vector<int> elements)
{
    long long possibilities = pow(2,elements.size()-1);
    std::vector<bool> operators(elements.size()-1, false);
    for(long long i=0; i < possibilities; i++)
    {
        long long result = elements[0];
        for(long long j=1; j<elements.size(); j++)
        {
            if(operators[j-1])
                result += elements[j];
            else
                result *= elements[j];
        }
        if(result == target)
            return true;

        increment(operators);
    }
    return false;
}

bool can_be_computed_2(long long target, std::vector<int> elements)
{
    long long possibilities = pow(3,elements.size()-1);
    std::vector<int> operators(elements.size()-1, 0);
    for(long long i=0; i < possibilities; i++)
    {
        long long result = elements[0];
        for(long long j=1; j<elements.size(); j++)
        {
            if(operators[j-1] == 0)
                result += elements[j];
            else if(operators[j-1] == 1)
                result *= elements[j];
            else
            {
                result = merge(result,elements[j]);
            }
        }
        if(result == target)
            return true;

        incrementTernary(operators);
    }
    return false;
}

int main()
{
    std::string line;
    long long total=0;
    long long total2 = 0;
    long long testNumber;
    char colon;
    while(std::getline(std::cin, line))
    {
        std::istringstream iss(line);
        char colon;
        std::vector<int> numbers;

        iss >> testNumber >> colon;
        int num;

        while (iss >> num) {
            numbers.push_back(num);
        }
        
        if(can_be_computed(testNumber, numbers))
        {
            total += testNumber;
        }
        else if(can_be_computed_2(testNumber, numbers))
        {
            total2 += testNumber;
        }
    }
    std::cout << "Part 1: " << total << std::endl;
    std::cout << "Part 2: " << total + total2;
    
    return 0;
}