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
            break;
        
        total += (stoi(numbers[i])*i);
    }
    return total;
}

int updateIndex(int x,vector<string> line)
{
    while(line[x] != ".")
        x++;
    return x;
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
    int firstFreeDotIndex = updateIndex(0,disk);

    

    for(int i = disk.size()-1; i>=0; i--)
    {
        if(firstFreeDotIndex >= i)
            break;
        if(disk[i] == ".")
            continue;

            

        disk[firstFreeDotIndex] = disk[i];
        disk[i] = ".";
        firstFreeDotIndex = updateIndex(firstFreeDotIndex,disk);
    }
    cout << "Part 1: " << checksum(disk) << endl;
    return 0;
}