#include <iostream>

using namespace std;

int n,c,i,j;

int main()
{

    cin >> c >> n;

    if(c==1)
    {
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
                cout << i;
            cout << endl;
        }
    }

    else if(c==2)
    {
        int k=n-1;
        int l=1;

        for(i=1;i<=n;i++)
        {
            for(j=1;j<=k;j++)
                cout << " ";
            for(j=1;j<=l;j++)
                cout << i;
            cout << endl;
            k--;
            l+=2;
        }

        k++;
        l-=2;

        for(i=n-1;i>=1;i--)
        {
            k++;
            l-=2;
            for(j=1;j<=k;j++)
                cout << " ";
            for(j=1;j<=l;j++)
                cout << i;
            cout << endl;
        }
    }

 else if(c==3)
    {
    for(i=1;i<=n;i++)
        {
            for(j=1;j<=n*2;j++)
                cout << i;
            cout << endl;
        }
    }

    else if(c==4)
    {
    int k=n-1;
        int l=1;

        for(i=1;i<=n;i++)
        {
            for(j=1;j<=k;j++)
            cout << " ";
            for(j=1;j<=l;j++)
            cout << i;
            cout << endl;
            k--;
            l+=2;
        }
    }

    return 0;
}
