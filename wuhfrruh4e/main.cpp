#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <mattgui.h>

int main() {
    int opt = matt::gui::gui("Gen/Eval/");
    if(opt==1) {
        std::fstream fin;
        fin.open("data.in", std::ifstream::in | std::ofstream::out);
        std::vector<int> nums;
        while(fin.eof()) {
            int n;
            fin>>n;
            nums.push_back(n);
        }
        sort(nums.begin(),nums.end());
        matt::core::clFile("data.in");
        for(auto &z : nums) {
            fin<<z<<"\n";
        }
    } else if(opt == 0) {
        int n;
        std::cin>>n;
        std::fstream fin;
        fin.open("data.in", std::ofstream::out);
        for(int i = 0; i < n; i++) {
            fin<<matt::core::random(1,100000)<<"\n";
        }
    }

    return 0;
}
