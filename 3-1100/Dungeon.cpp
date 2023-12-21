#include <iostream>

int main()
{
    int n;
    std::cin >> n;
    int a, b, c;
    for(int i = 0; i < n; i++)
    {
        std::cin >> a >> b >> c;
        if((a+b+c)%9 == 0){
            int enhancedShots = (a+b+c)/9;
            if(a >= enhancedShots && b >= enhancedShots && c>= enhancedShots)
                std::cout << "YES" << std::endl;
            else
                std::cout << "NO" << std::endl;
        }
        else
            std::cout << "NO" << std::endl;
    }
    return 0;
}
