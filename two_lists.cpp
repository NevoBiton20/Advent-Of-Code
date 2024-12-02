#include <vector>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <map>

//Part 2
long similarity(std::vector<int> a, std::vector<int> b)
{
    std::map<int,int> frequency;
    for(int i=0; i<a.size();i++)
    {
        frequency[a[i]] = 0;
    }

    for(int i=0; i<b.size();i++)
    {
        if(frequency.find(b[i]) != frequency.end())
        {
            frequency[b[i]]++;
        }
    }
    long similar = 0;
    for (const auto& [key, value] : frequency) {
        similar += key*value;
    }
    return similar;
}

// Part 1
int main()
{
    std::vector<int> l1;
    std::vector<int> l2;   

    while (true) {
        int x=-1,y=-1;
        std::cin >> x >> y;
        if(x==-1)
        {
            break;
        }
        l1.push_back(x);
        l2.push_back(y);
    }
    sort(l1.begin(), l1.end());
    sort(l2.begin(), l2.end());
    int total_dstncs = 0;
    for(int i=0; i<l1.size(); i++)
    {
        total_dstncs += abs(l1[i] - l2[i]);
    }
    std::cout << "Total Distances: " << total_dstncs<<std::endl;
    std::cout << "Similarity: " << similarity(l1,l2);

    return 0;
}
