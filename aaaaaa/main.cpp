#include <iostream>

using namespace std;
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cout<<"level-"<<i<<":\n  commands:\n    - \"te add %player% "<<10*i<<"\""<<endl;
        cout<<"  messages:\n    - \"&8&l[&bPickaxeLevels&8&l] &7Your pickaxe leveled up to level "<<i<<"\""<<endl;
    }
    return 0;
}
