 
#include <fstream>
#include <iostream>
#include <string>
#include <math.h>
#include <sstream>
#include <cmath>
#include <cstdio>
using namespace std;

int main() {
    
    
    
    int size;
    cout<<"enter size of Magic Square"<<endl;
    cin>>size;
    //following lines of code are the first position of the magic square.
    int height = size/2;
    int width = size - 1;
    
    
    int *square[size]; //initializes pointer to an array.
    
    //loop now points each reference to a new array in dynamic memory.
    //making a 2D array.
    for (int i = 0; i < size; i++) {
        square[i] = new int[size];
    }
    
    //the following loop fills the 2D array with 0's.
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            square[i][j] = 0;
        }
    }
    
    int newHeight = 0;
    int newWidth = 0;
    square[height][width] = 1; //sets the first square tp value of 1.
    //the following loop will fill the square with numbers from 2 to size*size.
    for(int i = 2; i <= (size*size); i++) {
        //the following if statements will check if the future height-1 and 
        //width + 1 are out of range of the 2D array, if so then newHeight,
        //and newWidth wrap around to 0 and size-1.
        //this control flow sets the position to where the new number is to be placed.
        if(height - 1 == -1) {
            newHeight = size - 1;
        }
        
        else {
            newHeight = height - 1; //if it does not wrap around then height is decremented by 1.
        }
        
        if(width + 1 == size) {
            newWidth = 0;
        }
        
        else {
            newWidth = width + 1; //if it does not wrap around then width is incremented by 1.
        }
        
        //if the new position already has a number that is not 0, then height
        //must increment by 1, and width must decrement by 2, but if these 
        //new positions also have a number they must follow this process again, hence
        //the while loop.
        while(square[newHeight][newWidth] != 0) {
            newHeight += 1;
            newWidth -= 2;
           
            if(newWidth == -1) {
                newWidth = size-1; //if width is out of range it wraps around.
             }
            if(newWidth == -2) {
                newWidth = size - 2;
            }
            if(newHeight == size) {
                newHeight = 0; //if width is out of range it wraps around.
            }
        }
        
        square[newHeight][newWidth] = i; //sets new position with value of 0 to the value i.
        
        //the values height and width are then set to the newHeight and newWidth, which,
        //when the loop begins again become the old positions.
        height = newHeight;
        width = newWidth;
    
    }
    

    //the following loop simply prints the magic square to the console.
    for(int i = 0; i < size; i++) {
        cout << endl;
        for(int j = 0; j < size; j++) {
            cout << square[i][j] << " ";
        }
    }
    
    
    return 0;
}