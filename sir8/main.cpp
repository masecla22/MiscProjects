#include <iostream>
#include <windows.h>

using namespace std;
int main()
{
    ///char(219);

    int marime;
    cin>>marime;

    int j=1;
    while(j<=marime){


        int n = j;
        int i=0;
        while(i<n)
        {
            cout<<char(219);
            i++;
        }



        cout<<endl;
        j++;

    }


    return 0;
}
