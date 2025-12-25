/* -----------------------------------------------------
   MQTT Data Processing Logic (Conceptual C-style)
------------------------------------------------------*/

#include <stdio.h>
#include <string.h>

void process_packet(char *json)
{
    int fill;
    float battery;

    sscanf(json, "{fill:%d,battery:%f}", &fill, &battery);

    // Alert checks
    if(fill >= 80)
        printf("[ALERT] Bin Full → Add to collection route\n");

    if(battery <= 3.10)
        printf("[WARNING] Battery Low → Maintenance required\n");

    // Store to database (concept)
    printf("Data saved → %s\n", json);
}
