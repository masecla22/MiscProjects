#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;
int random(int min, int max)
{
   static bool first = true;
   if (first)
   {
      srand( time(NULL) );
      first = false;
   }
   return min + rand() % (( max + 1 ) - min);
}
int maxlayer = 0;
void quicksort(int a[],int start,int ends,int layer = 0) {
    if(start>=ends)
        return ;
    int piv = (start+ends)/2,elempiv = a[piv],lpos = 0,rpos = ends-1;
    if(layer>maxlayer){
        maxlayer = layer;
    }
    int auxs[ends+1] = {0};
    for(int i=0;i<ends;i++)
    {
        if(i==piv)
            continue;
        if(a[i]>elempiv)
            auxs[rpos--]=a[i];
        else
            auxs[lpos++]=a[i];
    }
    auxs[rpos]=elempiv;
    quicksort(auxs,0,piv-1,layer+1);
    quicksort(auxs,piv+1,ends,layer+1);
    for(int i=0;i<ends;i++)
        a[i]=auxs[i];
}
int main() {
/**
    ofstream fout("data.ibn");
    for(int i=0;i<500;i++)
        fout<<random(1,1000)<<" ";
*/

    ifstream fin("data.ibn");
    int a[5000];
    int n;
    fin>>n;
    for(int i=0; i<n; i++)
        fin>>a[i];

    quicksort(a,0,n);

    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";

    return 0;
}
