#include <iostream>

using namespace std;

int main() {
    int n1;
    int v1[100];
    cin>>n1;
    for(int i=0; i<n1; i++)
        cin>>v1[i];
    int elemCaut;
    cin>>elemCaut;

    int gasit = -1;

    int st = 0, dr = n1-1;
    while(st<=dr) {
        int p1 = (st+dr)/3,p2 = ((st+dr)*2)/3;
        if(elemCaut==v1[p1]){
            gasit = p1;
            break;
        }
        else if(elemCaut==v1[p2]){
            gasit = p2;
            break;
        }
        else if(elemCaut<p1)
            dr = p1-1;
        else if(elemCaut>p2)
            st = p2+1;
        else{
            st = p1+1;
            dr = p2-1;
        }
        cout<<st<<" "<<dr<<endl;
    }

    if(gasit!=-1)
        cout<<"Se afla "<<gasit;
    else
        cout<<"Nu prea";
    return 0;
}
