#include <iostream>
#include <string>
int main()
{
    std::string line;
    std::string input;
    bool is_do = true;
    while(std::getline(std::cin, line))
    {
        input += line;
    }
    long total=0;
    for(int i=0; i<input.size();i++)
    {
        if(i<input.size()-7 && input.substr(i,7) == "don't()")
        {
            is_do = false;
        }
        else if(i<input.size()-4 && input.substr(i,4) == "do()")
        {
            is_do = true;
        }
        else if(i<input.size()-4 && input.substr(i,4) == "mul(" && is_do)
        {
            int num1;
            int j=i+4;
            if(input[j] <= '0' || input[j] > '9')
            {
                continue;
            }

            num1 = input[j] - '0';
            j++;
            while(j < input.size() && input[j] >= int('0') && input[j] <= int('9'))
            {
                num1 *= 10;
                num1 += input[j] - '0';
                j++;
            }

            if(j+2 >= input.size() || input[j] != ',')
            {
                continue;
            }
            j++;

            int num2;
            if(input[j] <= '0' || input[j] > '9')
            {
                continue;
            }

            num2 = input[j] - '0';
            j++;
            while(j < input.size() && input[j] >= int('0') && input[j] <= int('9'))
            {
                num2 *= 10;
                num2 += input[j] - '0';
                j++;
            }

            if(j >= input.size() || input[j] != ')')
            {
                continue;
            }
            std::cout << "num1: " << num1 << " " << "num2: " << num2 << std::endl;
            total += num1*num2;
            i=j;
        }
    }
    std::cout << total <<std::endl;
    return 0;
}