#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long checksum(vector<string> numbers)
{
    long long total=0;
    for(int i=1; i<numbers.size(); i++) 
    {
        if(numbers[i]==".")
            continue;
        
        total += (stoi(numbers[i])*i);
    }
    return total;
}

int updateIndex(vector<string> line, int amount, int until)
{
    int count;
    int index = 0;
    for(int i=0; i<until; i++)
    {
        if(line[i] != ".")
            continue;
        count = 1;
        int index = i;
        while(i<until && line[i+1] == ".")
        {
            count++;
            i++;
        }
        if(count >= amount)
        {
            return index;
        }
    }
    return -1;
}

vector<string> convertToDots(string line)
{
    bool mode = true;
    vector<string> dots;
    int id = 0;
    for(int i=0; i<line.size(); i++)
    {
        if(mode)
        {
            for(int j=0; j < (line[i] - '0'); j++)
            {
                dots.push_back(to_string(id));
            }
            id++;
        }
        else
        {
            int dotAmount = (line[i] - '0');
            for(int k=0; k<dotAmount; k++)
            {
                dots.push_back(".");
            }
        }
        mode=!mode;
    }

    return dots;
}

int main()
{
    string line;
    getline(cin,line);
    vector<string> disk = convertToDots(line);
    int firstFreeDotIndex = 0;

    for(int i = disk.size()-1; i>=0; i--)
    {
        if(firstFreeDotIndex >= i)
            break;
        if(disk[i] == ".")
            continue;

        int amount=1;
        while(i > 0 && disk[i] == disk[i-1])
        {
            amount++;
            i--;
        }
        if(i <= 0)
        {
            break;
        }
        firstFreeDotIndex = updateIndex(disk, amount, i);
        if(firstFreeDotIndex == -1)
        {
            continue;
        }

        int k = i;
        for(int j = firstFreeDotIndex; j< firstFreeDotIndex + amount; j++)
        {
            disk[j] = disk[k];
            disk[k] = ".";
            k++;
        }
    }

    cout << "Part 2: " << checksum(disk) << endl;
    return 0;
}