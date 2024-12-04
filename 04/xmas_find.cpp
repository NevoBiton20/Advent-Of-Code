#include <iostream>
#include <string>
#include <vector>

int count_xmas(std::vector<std::string> word_search, int i,int j)
{
    static const int dx[] = {-3, -3, -3,  0, 0,  3, 3, 3};
    static const int dy[] = {-3,  0,  3, -3, 3, -3, 0, 3};
    int rows = word_search.size();
    int cols = word_search[0].size();
    int total=0;
    for (int k = 0; k < 8; k++) {
        int nx = i + dx[k];
        int ny = j + dy[k];
        if (nx >= 0 && ny >= 0 && nx < rows && ny < cols && word_search[i + dx[k]/3][j + dy[k]/3] == 'M' && word_search[i + dx[k]*2/3][j + dy[k]*2/3] == 'A' && word_search[nx][ny] == 'S' )
            total++;

    }
    return total;
}

bool count_x_mas(std::vector<std::string> word_search, int i,int j)
{
    if(i > 0 && j>0 && i<word_search.size()-1 && j < word_search[0].size()-1)
    {
        if(word_search[i-1][j-1] == 'M' && word_search[i+1][j+1] == 'S' || (word_search[i+1][j+1] == 'M' && word_search[i-1][j-1] == 'S'))
        {
            if(word_search[i+1][j-1] == 'M' && word_search[i-1][j+1] == 'S' || (word_search[i-1][j+1] == 'M' && word_search[i+1][j-1] == 'S'))
            {
                return true;
            }
        }
    }
    return false;
}
int main()
{
    std::string line;
    std::vector<std::string> word_search;
    while(std::getline(std::cin, line))
    {
        word_search.push_back(line);
    }
    int total_xmas=0;
    for(int i=0; i<word_search.size(); i++)
    {
        for(int j=0; j<word_search[i].size(); j++)
        {
            //Part 2
            if(word_search[i][j] != 'A')
                continue;
            
            if(count_x_mas(word_search, i,j))
            {
                total_xmas ++;
            }

            //Part 1
            /*
            if(word_search[i][j] != 'X')
                continue;
            */
            //total_xmas += count_xmas(word_search, i,j);
        }
    }
    std::cout << total_xmas;
    return 0;
}