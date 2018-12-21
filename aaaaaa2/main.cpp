#include <iostream>
#include <algorithm>
#include <vector>
int matrixElementsSum(std::vector<std::vector<int>> matrix) {
    int sum=0;
    for(unsigned int x=0;x<matrix.at(0).size();x++){
        for(unsigned int y=0;y<matrix.size();y++)
        {
               std::cout<<matrix.at(x).at(y);
               sum+=matrix.at(x).at(y);
            if(matrix.at(x).at(y)==0)
                y = INT_MAX;

        }
    }
    return sum;
}

int main() {
    std::vector<std::vector<int>> matrix={{0,1,1,2}, {0,5,0,0}, {2,0,3,3}};
    matrixElementsSum(matrix);

    return 0;
}
