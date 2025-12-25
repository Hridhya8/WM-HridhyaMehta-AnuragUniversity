/* -----------------------------------------------------
   Route Optimization Pseudocode in C (Conceptual)
   Method: Zone-based clustering + A* shortest path idea
------------------------------------------------------*/

#include <stdio.h>
#include <math.h>

struct Bin {
    int id;
    int fill_level;
    float x, y;                 // location coordinates
};

float distance(float x1, float y1, float x2, float y2)
{
    return sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
}

void generate_route(struct Bin bins[], int n, float driver_x, float driver_y)
{
    printf("Optimized Route Order:\n");

    for(int i = 0; i < n; i++)
    {
        int next = -1;
        float minDist = 99999;

        // find nearest high-priority bin
        for(int j = 0; j < n; j++)
        {
            if(bins[j].fill_level >= 80)      // priority rule
            {
                float d = distance(driver_x, driver_y, bins[j].x, bins[j].y);
                if(d < minDist)
                {
                    minDist = d;
                    next = j;
                }
            }
        }

        if(next == -1) break; // no more bins to collect

        printf("→ Bin %d (Fill: %d%%)\n", bins[next].id, bins[next].fill_level);

        // move driver
        driver_x = bins[next].x;
        driver_y = bins[next].y;
        bins[next].fill_level = 0; // collected → remove from list
    }
}
