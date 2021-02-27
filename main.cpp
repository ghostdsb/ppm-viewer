#include "include/raylib.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

vector<string> split (const string &s, char delim) {
    vector<string> result;
    stringstream ss (s);
    string item;

    while (getline (ss, item, delim)) {
        result.push_back (item);
    }

    return result;
}

int main(int argc, char const* argv[]) 
{
    int imageWidth = 0;
    int imageHeight = 0;
    int maxColorValue = 255;
    int r,g,b;
    vector<string> pixelValues;
    vector<string> dimensions;
    vector<Color> pixelColors;
    string line;
    ifstream myfile (argv[1]);
    if (myfile.is_open()){
        int lineNo = 0;
        while(getline(myfile, line)){
            switch(lineNo){
                case 0:
                    break;
                case 1:
                    dimensions = split(line, ' ');
                    imageWidth = stoi(dimensions.at(0));
                    imageHeight = stoi(dimensions.at(1));
                    cout << imageWidth << imageHeight << endl;
                    break;
                case 2:
                    maxColorValue = stoi(line);
                    cout << "MAX COL:" << maxColorValue << endl;
                    break;
                default:
                    pixelValues = split(line, ' ');
                    r = stoi(pixelValues.at(0));
                    g = stoi(pixelValues.at(1));
                    b = stoi(pixelValues.at(2));
                    Color col = {r,g,b, 255};
                    pixelColors.push_back(col);
            }
            lineNo += 1;
        }
        myfile.close();
    }else{
        cout << "Unable to open file";
    } 

//   return 0;

    // Initialization
    //--------------------------------------------------------------------------------------
    int screenWidth = imageWidth;
    int screenHeight = imageHeight;

    InitWindow(screenWidth, screenHeight, "PPM VIEWER");

    SetTargetFPS(60);
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(RAYWHITE);
        // Color col = {255, 0, 0, 255};

        // DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
        for(int y=0;y<screenHeight;y++){
            for(int x=0;x<screenWidth;x++){
                Color col = pixelColors.at(x+y*screenWidth);
                DrawPixel(x,y, col);
            }
        }

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------   
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}