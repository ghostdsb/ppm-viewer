g++ main.cpp -o ppm.exe -O1 -Wall -Wno-missing-braces -I include/ -L lib/ -lraylib -lopengl32 -lgdi32 -lwinmm 
./ppm.exe image.ppm