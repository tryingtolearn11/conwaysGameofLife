#include <iostream>
#include <vector>

using gof_t = std::vector<std::vector<bool>>;
gof_t world = {
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
void generate(gof_t& g, gof_t& newworld)
{
    for(size_t i = 0, x = g.size(); i < x; i++)
    {
        for(size_t j = 0, y = g[i].size(); j < y; j++)
        {
            size_t i_prev = (i + x - 1) % x;
            size_t i_next = (i + 1) % x;
            size_t j_prev = (j + y - 1) % y;
            size_t j_next = (j + 1) % y;

            int count = g[i_prev][j_prev] + g[i_prev][j] + g[i_prev][j_next]
                      + g[i     ][j_prev]                + g[i     ][j_next]
                      + g[i_next][j_prev] + g[i_next][j] + g[i_next][j_next];



            newworld[i][j] = g[i][j] ? (count == 2 || count == 3) : (count == 3);
        }
    }
    std::swap(g, newworld);
}

void display(gof_t const& a)
{
    for(size_t row = 0; row < a.size(); row++)
    {
        for(size_t column = 0; column < a[row].size(); column++)
        {
            std::cout << ".O"[a[row][column]];
        }
        std::cout << '\n';
    }          
}        

int main()
{

    gof_t newworld(world);
    
    for (int i = 0; i < 20; ++i)
    {
        display(world);
        std::cout << '\n';
        generate(world, newworld);
    }
    return 0;
}
