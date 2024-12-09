#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<string> map;


struct Point{
    int x,y;

    bool operator<(const Point& other) const {
        if (x == other.x)
            return y < other.y;
        return x < other.x;
    }
};
set<Point> antinodes;
set<Point> antinodesNew;
void addLine(Point a, Point b)
{
    antinodesNew.insert(a);
    antinodesNew.insert(b);
    if(a.x > b.x)
    {
        int dheight = a.x - b.x;
        int dwidth = a.y - b.y;
        int uheight = dheight*-1; 
        int uwidth =  dwidth*-1;
        int x = a.x + dheight,y = a.y + dwidth;
        while(x >=0 && x < map.size() && y >=0 && y < map[0].size())
        {
            Point p = {x,y};
            antinodesNew.insert(p);
            x += dheight;
            y += dwidth;
        }

        int x1 = b.x + uheight,y1 = b.y + uwidth;
        while(x1 >=0 && x1 < map.size() && y1 >=0 && y1 < map[0].size())
        {
            Point p = {x1,y1};
            antinodesNew.insert(p);
            x1 += uheight;
            y1 += uwidth;
        }
    }
    else
    {
        int dheight = b.x - a.x;
        int dwidth = b.y - a.y;
        int uheight = dheight*-1; 
        int uwidth =  dwidth*-1;
        int x = b.x + dheight,y = b.y + dwidth;
        while(x >=0 && x < map.size() && y >=0 && y < map[0].size())
        {
            Point p = {x,y};
            antinodesNew.insert(p);
            x += dheight;
            y += dwidth;
        }

        int x1 = a.x + uheight,y1 = a.y + uwidth;
        while(x1 >=0 && x1 < map.size() && y1 >=0 && y1 < map[0].size())
        {
            Point p = {x1,y1};
            antinodesNew.insert(p);
            x1 += uheight;
            y1 += uwidth;
        }
    }
}

pair<Point,Point> findTwoAntinodes(Point a, Point b)
{
    int width = abs(a.y - b.y);
    int height = abs(a.x - b.x);
    Point c,d;
    
    if(a.y == b.y)
    {
        if(a.x > b.x)
        {
            c = {a.x + height, a.y};
            d = {b.x - height, b.y};
        }
        else
        {
            c = {a.x - height, a.y};
            d = {b.x + height, b.y};
        }
    }
    
    if(a.x > b.x)
    {
        if(a.y > b.y)
        {
            c = {a.x + height, a.y + width};
            d = {b.x - height, b.y - width};
        }
        else
        {
            c = {a.x + height, a.y - width};
            d = {b.x - height, b.y + width};
        }
    }
    else if(a.x < b.x)
    {
        if(a.y > b.y)
        {
            c = {a.x - height, a.y + width};
            d = {b.x + height, b.y - width};
        }
        else
        {
            c = {a.x - height, a.y - width};
            d = {b.x + height, b.y + width};
        }
    }
    else
    {
        if(a.y > b.y)
        {
            c = {a.x, a.y + width};
            d = {b.x, b.y - width};
        }
        else
        {
            c = {a.x, a.y - width};
            d = {b.x, b.y + width};
        }
    }
    pair<Point,Point> points = {c,d};
    return points;
}

int main()
{
    string line;
    while(getline(cin,line))
    {
        map.push_back(line);
    }
    for(int i=0; i<map.size(); i++)
    {
        for(int j=0; j<map[0].size(); j++)
        {
            if(map[i][j] == '.')
                continue;
            for(int k=0; k<map.size(); k++)
            {
                for(int h=0; h<map[0].size(); h++)
                {
                    if(map[i][j] == '.')
                        continue;
                    if(k==i && h==j)
                        continue;
                    
                    if(map[k][h] == map[i][j])
                    {
                        Point a = {k,h}, b = {i,j};
                        pair<Point,Point> points = findTwoAntinodes(a,b);
                        Point c = points.first;
                        Point d = points.second;
                        if(c.x >= 0 && c.x < map.size() && c.y >= 0 && c.y < map[0].size())
                            antinodes.insert(c);
                        if(d.x >= 0 && d.x < map.size() && d.y >= 0 && d.y < map[0].size())
                            antinodes.insert(d);
                        addLine(a,b);
                    } 
                }
            }
        }
    }
    cout << "Part 1: " << antinodes.size() << endl;
    cout << "Part 2: " << antinodesNew.size() << endl;
    return 0;
}