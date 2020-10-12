#include <string>
#include <iostream>
using namespace std;
 
 
int main(int argc, char* argv[]){
   int boardWidth=3;
   int boardHeight=5;
 
   int gameboard[3][5]={
      {0,0,0,0,1},
      {0,0,1,0,0},
      {0,0,1,0,0}
   };
   // Iterate thorugh grid
   for (int x=0 ; x<boardWidth; x++){
       for (int y=0; y<boardHeight; y++){
 
           int livingNeighbors = 0;
          
           //iterate through neighbors
           for (int i =-1 ; i<=1; i++){
               for(int j =-1; j<=1;j++){
 
                   //check not current cell
                   if(!(i==0 && j==0)){
 
                       //add living neighbir
                       if (gameboard[x+i][x+y]){
                           livingNeighbors++;
                       }
                   }
                  
               }
           }
           //Apply cell rules to current cell
           int currentcell= gameboard[x][y];
 
           //living cell with less than 2 neighbors dies
           if (currentcell && livingNeighbors<2){
               currentcell=0;
           }
           //living cell with 2 or 3 neighbors lives on
           if (currentcell && ((livingNeighbors==2) || (livingNeighbors==3))){
               currentcell=1;
           }
 
           //living cell with more than 3 neighbors dies
           if (currentcell && livingNeighbors>3){
               currentcell==0;
           }
 
           //dead cell with exactly 3 neigbors comes alive
           if(!currentcell && livingNeighbors==3) {
               currentcell=1;
           }
       }
   }
 
 
   for (int x=0 ; x<boardWidth; x++){
       cout << "/n";
       for (int y=0; y<boardHeight; y++){
           cout << gameboard[x][y];
 
       }
   }
 
   return 1;
 
}
