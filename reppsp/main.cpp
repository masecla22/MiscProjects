#include <iostream>
#include <fstream>
#include <mattgui.h>
#include <vector>


int main()
{
    size_t a = matt::gui::gui("Generate a new set   /Sort the set   /");
    if(a){

    }
    else{
        system("cls");
        size_t theObj;
        std::cin>>theObj;
        std::fstream out;
        out.open("data.in",std::ofstream::out);
        for(size_t i=0;i<theObj;i++)
            out<<matt::core::random(0,theObj)<<"\n";
        out.close();
        main();
    }



    return 0;
}
