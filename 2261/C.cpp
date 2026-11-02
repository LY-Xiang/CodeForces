#include <iostream>
int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--)
    {
        int n;
        std::cin >> n;
        int o=0,e=0,x;
        for (int i=0;i<n;++i)
        {
            std::cin >> x;
            if (x%2)++e;
            else ++o;
        }
        if (o==0&&e==0||o==0&&e==3||o==1&&e==1)
            std::cout<<"Larpity"<<std::endl;
        else
            std::cout<<"Moggity"<<std::endl;
    }


}