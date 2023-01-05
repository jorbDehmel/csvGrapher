// CSV grapher

// Jordan "Jorb" Dehmel, 2023
// jdehmel@outlook.com, github.com/jorbDehmel

// Full installation command for graphing library:
// gh repo clone jorbDehmel/jgraph && cd jgraph/jgraph && make && cd ../..

// Add this to compilation command:
// `sdl2-config --cflags --libs` -lSDL2_ttf

// If you get the error 'Cannot open source file "begin_code.h"', don't worry,
// it doesn't matter. (It's a bug in a dependancy library)

#include <jgraph/jgraph.hpp>
#include <string>
using namespace std;

CSV<double> *output;
int pos = 0;

bool a(double &x, double &y)
{
    x = (*output->data[0])[pos];
    y = (*output->data[1])[pos];

    pos++;

    if (pos >= output->data[0]->size())
    {
        pos = 0;
        return false;
    }
    else
    {
        return true;
    }
}

bool b(double &x, double &y)
{
    x = (*output->data[0])[pos];
    y = (*output->data[2])[pos];

    pos++;

    if (pos >= output->data[0]->size())
    {
        pos = 0;
        return false;
    }
    else
    {
        return true;
    }
}

int main()
{
    // Get CSV path
    string path;
    cout << "Path: ";
    cin >> path;

    // Set graph metavariables
    jgraph::TITLE = path;
    jgraph::WIDTH = jgraph::HEIGHT = 1028;
    jgraph::FONT_PATH = "/usr/include/jgraph/fonts/Open_Sans/static/OpenSans/OpenSans-Bold.ttf";
    jgraph::FONT_POINTS = 28;
    jgraph::XMIN = 0;
    jgraph::XMAX = 10;
    jgraph::YMAX = 0;
    jgraph::YMIN = -5;
    jgraph::XMAX_OFFSET.x += 10;
    jgraph::XMIN_OFFSET.x = -200;

    // Can change to loadHorizontalCSVF if you need that
    CSV<double> temp = loadVerticalCSVF(path.c_str());
    output = &temp;

    DotGraph g;

    g.equations.push_back(a);
    g.equations.push_back(b);

    mainLoop(&g);

    return 0;
}
