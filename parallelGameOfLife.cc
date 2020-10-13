#include <string>
#include <iostream>
#include <omp.h>
using namespace std;
 
 
int main(int argc, char* argv[]){
   int boardWidth=3;
   int boardHeight=5;
 
   int gameboard[3][5]={
      {0,1,0,0,1},
      {0,0,1,0,0},
      {0,0,1,0,0}
   };
   int resultboard[3][5]={
        {0,1,0,0,1},
      {0,0,1,0,0},
      {0,0,1,0,0}
   };
   // Iterate thorugh grid
   #pragma omp simd
   for (int x=0 ; x<boardWidth; x++){
       for (int y=0; y<boardHeight; y++){
 
           int livingNeighbors = 0;
          
           //iterate through neighbors
           for (int i =-1 ; i<=1; i++){
               for(int j =-1; j<=1;j++){

                   //check if out of bounds 
                   if ((x+i>=0 && x+i<boardWidth) && (y+j>=0) && (y+j<boardHeight)){
                       //check not current cell
                        if(!(i==0 && j==0)){
    
                            //add living neighbir
                            if (gameboard[x+i][y+j]){
                                livingNeighbors++;
                                cout << "gameboard" <<"["<<x <<"]"<<"["<<y <<"]" <<endl;
                                cout << "vecinos" <<"["<<x+i <<"]"<<"["<<y+j <<"]" <<endl;
                                cout << livingNeighbors<<endl;
                            }
                    }

                   }                  
               }
           }
           //Apply cell rules to current cell
           int currentcell= gameboard[x][y];
 
           //living cell with less than 2 neighbors dies
           if (currentcell && livingNeighbors<2){
               resultboard[x][y]=0;
           }
           //living cell with 2 or 3 neighbors lives on
           if (currentcell && ((livingNeighbors==2) || (livingNeighbors==3))){
              resultboard[x][y]=1;
           }
 
           //living cell with more than 3 neighbors dies
           if (currentcell && livingNeighbors>3){
               resultboard[x][y]==0;
           }
 
           //dead cell with exactly 3 neigbors comes alive
           if(!currentcell && livingNeighbors==3) {
               resultboard[x][y]=1;
           }
       }
   }
 
 
   for (int x=0 ; x<boardWidth; x++){
       cout << endl;
       for (int y=0; y<boardHeight; y++){
           cout << resultboard[x][y];
 
       }
   }
 
   return 1;
 
}
