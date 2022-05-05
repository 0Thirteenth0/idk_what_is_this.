#include <iostream>
#include <iomanip>
#include <unistd.h>
#include <fstream>
using namespace std;

class pic
{
private:
    string *grid;
    int size;

public:
    pic() : grid(nullptr), size(0) {}
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
    void print_grid(const int &c){
        const int s = 10;//size for color and arr arrays.
        int length = grid[0].length(), y = 0, x = 0;
        int arr[s] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        string color[s] = { "\033[0;32m", 
                            "\033[0;31m", 
                            "\033[0;33m", 
                            "\033[0;34m", 
                            "\033[0;35m", 
                            "\033[0;36m", 
                            "\033[1;33m", 
                            "\033[1;32m", 
                            "\033[1;33m", 
                            "\033[1;34m"};//ANSI escape code that changes color of terminal output.
        srand(time(NULL));
        x = rand() % 10;// x for index will have same color.
        cout << "\033[0;0H"; //puts terminal cursor back to 0,0 \033[x;yH.
        y = c % 10;
        for (int i = 0; i < size; i++)
        {
            y += i;
            for (int j = 0; j < length; j++)
            {
                if (y >= s)
                    y = c % 10;
                if (grid[i][j] != ' ')
                    cout << color[y] << grid[i][j] << "\033[0m"; //x for random coloring, y for all same coloring.
                else
                    cout << "\033[0;30m" << " " << "\033[0m";
                y++;
            }
            cout << endl;
        }
        cout << "\033[0;30mTo stop the program:\nOn window: ctrl+c\nMac: ^+c\n\033[0m";
    }
};

int main(int argc, char **argv)
{
    if (argc > 1)
    {
        int count = 0, c = 0;
        pic p;
        if (p.recordPic(argv[1]))
        {
            system("clear");//clears terminal.
            while (true)
            {
                p.print_grid(c); 
                while (count < 10000000) //loop to slow down the process.
                    count++;
                count = 0;
                c++;
                usleep(1);// set terminal to sleep 1/100 sec.
            }
        }
    }
    return 0;
}
