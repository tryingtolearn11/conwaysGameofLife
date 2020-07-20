#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::swap;
vector<vector<bool> > world = {
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
};

void generate(vector<vector<bool> >&g,vector<vector<bool> >&newworld)
{
    
    newworld = g;
    for(size_t i = 0; i < g.size();i++) {
        for(size_t j = 0; j < g[i].size();j++) {

            int x = g.size(); //I rows
            int y = g[i].size(); //J columns
            //wrap the edges with formula (x+n)%n  where n = NumOfRows or NumOfCol
                          // Top left                      // top middle          // top right                    // left cell              // right    // etc
            // count all neighbor cells
            int count = g[(((i+1)+x)%x)][(((j-1)+y)%y)] + g[(((i+1)+x)%x)][j] + g[(((i+1)+x)%x)][(((j+1)+y)%y)] + g[i][(((j-1)+y)%y)] +  g[i][(((j+1)+y)%y)] + g[(((i-1)+x)%x)][(((j-1)+y)%y)] + g[(((i-1)+x)%x)][j] + g[(((i-1)+x)%x)][(((j+1)+y)%y)];
            // conditional statement: apply count rules 
            newworld[i][j] = g[i][j] ? (count == 2 || count == 3) : (count == 3);
        }
    }
    std::swap(g,newworld);
}



void display(vector<vector<bool> >&a)
{
    for(size_t row = 0; row <a.size(); row++) {
        for(size_t column = 0; column <a[row].size(); column++){
            if (a[row][column]) {
                cout << 'O';
            }
             else {
                cout << '.';
             }
        }
        cout << '\n';
    }          
}        

int main()
{
    vector<vector<bool> > newworld;
    int x;
    std::cout << "Welcome To Conway's Game of Life" << '\n';
    std::cout << "Enter the number of generations to run :  ";
    std::cin >> x;
     for (int i = 0; i < x+1; ++i)
    {
        display(world);
        std::cout << "Generation : " << i << '\n';
        std::cout << "--------------------------------------------" << '\n';
        std::cout << '\n';
        generate(world, newworld);
    }
  
    return 0;
}