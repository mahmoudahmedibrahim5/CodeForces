#include <stdio.h>
#include <math.h>

int main()
{
    double r, xOld, yOld, xNew, yNew;
    scanf("%lf %lf %lf %lf %lf", &r, &xOld, &yOld, &xNew, &yNew);

    double distance = sqrt( 
                            (yNew - yOld) * (yNew - yOld) 
                        +   (xNew - xOld) * (xNew - xOld)
                        );
    int answer = (int)ceil(distance / (2.0 * r));
    printf("%d\n", answer);

    return 0;
}
