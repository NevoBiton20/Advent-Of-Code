#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> map;
int main()
{
    int x = 0, y = 0;
    bool found = false;

    std::string currentLine = "";
    int currentLineIndex = 0;

    int dx = -1;
    int dy = 0;

    char ch;
    while (std::cin.get(ch)) {
        if (!found && ch == '^') {
            x = currentLineIndex;
            y = currentLine.length();
            found = true;
        }
        
        if (ch == '\n') { 
            map.push_back(currentLine);
            currentLine.clear();
            currentLineIndex++;
        } else {
            currentLine += ch;
        }
    }

    if (!currentLine.empty()) {
        map.push_back(currentLine);
    }
    std::vector<int> location(2);
    std::vector<int> direction(2);
    location[0] = x;
    location[1] = y;
    direction[0] = dx;
    direction[1] = dy;

    int x_turn = 1;
    int y_turn = 1;

    int obsLoops = 0;
    int runs=0;
    for(int i=0; i<map.size(); i++)
    {
        for(int j=0; j<map[0].size();j++)
        {
            if (map[i][j] == '#' || map[i][j] == '^')
                continue;
            map[i][j] = '#';
            location[0] = x;
            location[1] = y;
            direction[0] = dx;
            direction[1] = dy;
            int x_turn = 1;
            int y_turn = 1;

            int runs=0;

            while(location[0] != 0 && location[0] != map.size() -1 && location[1] != 0 && location[1] != map[0].size() -1)
            {
                runs++;
                if(runs == map.size()*map[0].size()*4)
                    break;
                while(location[0] > 0 && location[0] < map.size()-1 && location[1] > 0 && location[1] < map[0].size() - 1 && map[location[0] + direction[0]][location[1] + direction[1]] != '#')
                {   
                    location[0] += direction[0];
                    location[1] += direction[1];
                }

                if(direction[0] == 1)
                {
                    x_turn = -1;
                }
                else if(direction[0] == -1)
                {
                    x_turn = 1;
                }

                if(direction[1] == 1)
                {
                    y_turn = -1;
                }
                else if(direction[1] == -1)
                {
                    y_turn = 1;
                }

                direction[0] += x_turn;
                direction[1] += y_turn;
            }  
            map[i][j] = '.';
            if(runs == map.size()*map[0].size()*4)
                obsLoops++;
        }
    }
    std::cout << "Part 2: " << obsLoops << std::endl;
    return 0; 
}