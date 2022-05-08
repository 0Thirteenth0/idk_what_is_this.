#include <iostream>
#include <iomanip>
#include <unistd.h>
#include <fstream>
using namespace std;

class pic
{
private:
    string *grid;
    string bullet;
    string tankF[3];
    string boom[8];
    int size;

public:
    pic() : grid(nullptr), size(0), bullet("~=>") {
        tankF[0] = "/`-   ";
        tankF[1] = "`~].=-";
        tankF[2] = "\\`-   ";
        boom[0] = "          _ ._  _ , _ ._         ";
        boom[1] = "        (_ ' ( `  )_  .__)       ";
        boom[2] = "      ( (  (    )   `)  ) _)     ";
        boom[3] = "     (__ (_   (_ . _) _) ,__)    ";
        boom[4] = "         `~~`\\ ' . /`~~`         ";
        boom[5] = "              ;   ;              ";
        boom[6] = "              /   \\              ";
        boom[7] = "_____________/_ __ \\_____________";
        
    }
    pic(pic &cpy)
    {
        *this = cpy;
    }
    void operator=(pic &cpy)
    {
        if (grid != nullptr)
            delete[] grid;
        size = cpy.size;
        grid = new string[size];
        for (int i = 0; i < size; i++)
            grid[i] = cpy.grid[i];
    }
    ~pic()
    {
        if (grid != nullptr)
            delete[] grid;
    }
    bool recordPic(string fname)
    {
        ifstream ifile(fname);
        if (!ifile.is_open())
        {
            cout << "File_Open_Attempt_Failed: Please Enter a Proper Filename.\n";
            return false;
        }
        while (!ifile.eof())
        {
            string *temp = new string [size + 1];
            for (int i = 0; i < size; i++)
                temp[i] = grid[i];
            getline(ifile, temp[size], '\n');
            if (grid != nullptr)
                delete[] grid;
            grid = temp;
            temp = nullptr;
            size++;
        }
        return true;
    }
    void print_grid(const unsigned int c, int &yb, int &xb, int tic, int xc){
        const int s = 10, cs = 12;//size for color and arr arrays.
        int length = grid[0].length(), y = 0, z = 0, x = 0;
        int arr[s] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        string color[cs] = { "\e[0;31m", //0red
                            "\e[0;32m", //1green
                            "\e[0;33m", //2yellow
                            "\e[0;34m", //3blue
                            "\e[0;35m", //4purple
                            "\e[0;36m", //5cyan
                            "\e[1;33m", //6boldYellow
                            "\e[1;31m", //7boldRed
                            "\e[1;30m", //8boldblack
                            "\e[1;37m", //9boldWhite
                            "\e[0;100m" //10blackBack
                            "\e[0;107m" //11whiteBack
                            //
                            };//ANSI escape code that changes color of terminal output.
        string reset = "\e[0m";
        cout << "\033[0;0H"; //puts terminal cursor back to 0,0 \033[x;yH.
        for (int i = 0; i < size; i++)
        {
            y = 0, z = 0;
            for (int j = 0; j < length; j++)
            {
                if (tic > 0 && tic < 30)
                {
                    if (grid[i][j] == '/' || grid[i][j] == '\\' || grid[i][j] == '[' || grid[i][j] == ']' || grid[i][j] == '"' || grid[i][j] == '#')
                    {
                        cout << color[1] << grid[i][j] << reset;
                    }
                    else if (grid[i][j] != ' ')
                    {
                        cout << color[8] << grid[i][j] <<  reset;
                    }
                    else
                    {
                        cout << color[0] << " " <<  reset;
                    }
                }
                else if (tic > 30 && tic < 33)
                { 
                    if(i == 3 && j >= xb - 2 && j <= xb + 3)
                    {
                        do
                            x = rand() % 2 + 6;
                        while( x == xc);
                        xc = x;
                        cout << color[x] << tankF[0][y++] << reset;
                    }
                    else if(i == 4 && j >= xb - 2 && j <= xb + 3)
                    {
                        do
                            x = rand() % 2 + 6;
                        while( x == xc);
                        xc = x;
                        cout << color[x] << tankF[1][y++] << reset;
                    }
                    else if(i == 5 && j >= xb - 2 && j <= xb + 3)
                    {
                        do
                            x = rand() % 2 + 6;
                        while(x == xc);
                        xc = x;
                        cout << color[x] << tankF[2][y++] << reset;
                    }
                    else if (grid[i][j] == '/' || grid[i][j] == '\\' || grid[i][j] == '[' || grid[i][j] == ']' || grid[i][j] == '"' || grid[i][j] == '#')
                    {
                        cout << color[1] << grid[i][j] << reset;
                    }
                    else if (grid[i][j] != ' ')
                    {
                        cout << color[8] << grid[i][j] <<  reset;
                    }
                    else
                    {
                        cout << color[0] << " " <<  reset;
                    }
                }
                else if (tic > 33 && tic < 36)
                {
                    if (i == 4 && j > 7 && j < 35)
                    {
                        cout << color[1] << grid[i][j+1] << reset;
                    }
                    else if(i == 3 && j >= xb - 2 && j <= xb + 3)
                    {
                        do
                            x = rand() % 2 + 6;
                        while( x == xc);
                        xc = x;
                        cout << color[x] << tankF[0][y++] << reset;
                    }
                    else if(i == 4 && j >= xb - 2 && j <= xb + 3)
                    {
                        do
                            x = rand() % 2 + 6;
                        while( x == xc);
                        xc = x;
                        cout << color[x] << tankF[1][y++] << reset;
                    }
                    else if(i == 5 && j >= xb - 2 && j <= xb + 3)
                    {
                        do
                            x = rand() % 2 + 6;
                        while(x == xc);
                        xc = x;
                        cout << color[x] << tankF[2][y++] << reset;
                    }
                    else if (grid[i][j] == '/' || grid[i][j] == '\\' || grid[i][j] == '[' || grid[i][j] == ']' || grid[i][j] == '"' || grid[i][j] == '#')
                    {
                        cout << color[1] << grid[i][j] << reset;
                    }
                    else if (grid[i][j] != ' ')
                    {
                        cout << color[8] << grid[i][j] <<  reset;
                    }
                    else
                    {
                        cout << color[0] << " " <<  reset;
                    }
                }
                else if (tic > 36 && tic < 39)
                {
                    if (i == 4 && j > 5 && j < 35)
                    {
                        cout << color[1] << grid[i][j+4] << reset;
                    }
                    else if(i == 3 && j >= xb - 2 && j <= xb + 3)
                    {
                        do
                            x = rand() % 2 + 6;
                        while( x == xc);
                        xc = x;
                        cout << color[x] << tankF[0][y++] << reset;
                    }
                    else if(i == 4 && j >= xb - 2 && j <= xb + 3)
                    {
                        do
                            x = rand() % 2 + 6;
                        while( x == xc);
                        xc = x;
                        cout << color[x] << tankF[1][y++] << reset;
                    }
                    else if(i == 5 && j >= xb - 2 && j <= xb + 3)
                    {
                        do
                            x = rand() % 2 + 6;
                        while(x == xc);
                        xc = x;
                        cout << color[x] << tankF[2][y++] << reset;
                    }
                    else if (grid[i][j] == '/' || grid[i][j] == '\\' || grid[i][j] == '[' || grid[i][j] == ']' || grid[i][j] == '"' || grid[i][j] == '#')
                    {
                        cout << color[1] << grid[i][j] << reset;
                    }
                    else if (grid[i][j] != ' ')
                    {
                        cout << color[8] << grid[i][j] <<  reset;
                    }
                    else
                    {
                        cout << color[0] << " " <<  reset;
                    }
                }
                else if (tic > 39 && tic < 42)
                {
                    if (i == 4 && j > 8 && j < 34)
                    {
                        cout << color[1] << grid[i][j+1] << reset;
                    }
                    else if (i == 4 && j > xb - 3 && j < xb + 1)
                    {
                        if (z == 0)
                            cout << color[6] << bullet[z++] << reset;
                        else
                            cout << color[5] << bullet[z++] << reset;
                    }
                    else if(i == 3 && j >= 36 && j <= 41)
                    {
                        do
                            x = rand() % 2 + 6;
                        while( x == xc);
                        xc = x;
                        cout << color[x] << tankF[0][y++] << reset;
                    }
                    else if(i == 4 && j >= 36 && j <= 41)
                    {
                        do
                            x = rand() % 2 + 6;
                        while( x == xc);
                        xc = x;
                        cout << color[x] << tankF[1][y++] << reset;
                    }
                    else if(i == 5 && j >= 36 && j <= 41)
                    {
                        do
                            x = rand() % 2 + 6;
                        while(x == xc);
                        xc = x;
                        cout << color[x] << tankF[2][y++] << reset;
                    }
                    else if (grid[i][j] == '/' || grid[i][j] == '\\' || grid[i][j] == '[' || grid[i][j] == ']' || grid[i][j] == '"' || grid[i][j] == '#')
                    {
                        cout << color[1] << grid[i][j] << reset;
                    }
                    else if (grid[i][j] != ' ')
                    {
                        cout << color[8] << grid[i][j] <<  reset;
                    }
                    else
                    {
                        cout << color[0] << " " <<  reset;
                    }
                    
                }
                else if (tic > 42 && tic < 45)
                {
                    if (i == 4 && j > 9 && j < 35)
                    {
                        cout << color[1] << grid[i][j] << reset;
                    }
                    else if (i == 4 && j > xb - 3 && j < xb + 1)
                    {
                        if (z == 0)
                            cout << color[6] << bullet[z++] << reset;
                        else
                            cout << color[5] << bullet[z++] << reset;
                    }
                    else if(i == 3 && j >= 36 && j <= 41)
                    {
                        do
                            x = rand() % 2 + 6;
                        while( x == xc);
                        xc = x;
                        cout << color[x] << tankF[0][y++] << reset;
                    }
                    else if(i == 4 && j >= 36 && j <= 41)
                    {
                        do
                            x = rand() % 2 + 6;
                        while( x == xc);
                        xc = x;
                        cout << color[x] << tankF[1][y++] << reset;
                    }
                    else if(i == 5 && j >= 36 && j <= 41)
                    {
                        do
                            x = rand() % 2 + 6;
                        while(x == xc);
                        xc = x;
                        cout << color[x] << tankF[2][y++] << reset;
                    }
                    else if (grid[i][j] == '/' || grid[i][j] == '\\' || grid[i][j] == '[' || grid[i][j] == ']' || grid[i][j] == '"' || grid[i][j] == '#')
                    {
                        cout << color[1] << grid[i][j] << reset;
                    }
                    else if (grid[i][j] != ' ')
                    {
                        cout << color[8] << grid[i][j] <<  reset; //x for random coloring, y for all same coloring.
                    }
                    else
                    {
                        cout << color[0] << " " <<  reset;
                    }
                    
                }
                else if (tic > 45 && tic <= 76)
                {
                    if (i == 4 && j > xb - 3 && j < xb + 1)
                    {
                        if (z == 0)
                            cout << color[6] << bullet[z++] << reset;
                        else
                            cout << color[5] << bullet[z++] << reset;
                    }
                    else if (grid[i][j] == '/' || grid[i][j] == '\\' || grid[i][j] == '[' || grid[i][j] == ']' || grid[i][j] == '"' || grid[i][j] == '#')
                    {
                        cout << color[1] << grid[i][j] << reset;
                    }
                    else if (grid[i][j] != ' ')
                    {
                        cout << color[8] << grid[i][j] <<  reset; //x for random coloring, y for all same coloring.
                    }
                    else
                    {
                        cout << color[0] << " " <<  reset;
                    }
                    
                }
                else if (tic > 76 && tic <= 125)
                {
                    if (i == 0 && j == 0)
                    {
                        do
                            x = rand() % 2 + 9;
                        while (x == xc);
                        xc = x;
                    }
                    if (x - 9 == 1 || tic == 150)
                    {
                        cout << color[10] << " " <<  reset;
                    }
                    else if (i == 4 && j > xb - 3 && j < xb + 1)
                    {
                        cout << color[x] << bullet[z++] << reset;
                    }
                    else if (grid[i][j] == '/' || grid[i][j] == '\\' || grid[i][j] == '[' || grid[i][j] == ']' || grid[i][j] == '"' || grid[i][j] == '#')
                    {
                        cout << color[1] << grid[i][j] << reset;
                    }
                    else if (grid[i][j] != ' ')
                    {
                        cout << color[8] << grid[i][j] <<  reset; //x for random coloring, y for all same coloring.
                    }
                    else
                    {
                        cout << color[0] << " " <<  reset;
                    }
                }
                else if (tic > 125 && tic < 250)
                {
                    do 
                        x = rand() % 2 + 6;
                    while(x == xc);
                    xc = x;
                    if (j >= (grid[i].length() / 2) - (boom[i].length() / 2) && j <= (grid[i].length() / 2) + (boom[i].length() / 2))
                    {
                        cout << color[x] << boom[i][y++] << reset;
                    }
                    else if (i == 7)
                    {
                       cout << color[x] << "_" << reset;
                    }
                    else
                    {
                        cout << color[x + 3] << " " << reset;
                    }
                    
                }
                
                
            }
            cout << endl;
        }
        cout << "tick : " << tic << endl;
        cout << "\033[0;30mTo stop the program:\nOn window: ctrl+c\nMac: ^+c\n\033[0m";
    }
};

int main(int argc, char **argv)
{
    int yBullet = 4, xBullet = 35, ywall = 4, xwall = 98, tick = 0, cr = 0;
    unsigned int c = 0;
    pic p;
    if (p.recordPic("pic9.txt"))
    {
        srand(time(NULL));
        system("clear");//clears terminal.
        while (true)
        {
            p.print_grid(c, yBullet, xBullet, tick, cr);
            if (tick >= 250)
                yBullet = 4, xBullet = 35, tick = 0;
            c++;
            tick++;
            if (tick >= 45 && tick <= 76)
            {
                xBullet += 2;
            }
            usleep(28000);// set terminal to sleep 1/100 sec.
        }
    }
    return 0;
}
