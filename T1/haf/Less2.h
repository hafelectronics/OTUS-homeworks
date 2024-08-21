#include <mask.h>
#include <IP_job.h>

void IPjob() {
    upload_IP_list();
    filter_IPaddress();
    sort_IPaddress();
    print_IPaddress();
    print_IPaddress(1);
    print_IPaddress(46, 70);
    print_IPaddress(46,46,46,46,any);
}