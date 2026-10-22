#include <stdio.h>

#include <X11/xshmfence.h>

int main(void)
{
    /* Windows has no shared memory for a fence: allocation fails and nothing maps. */
    if (xshmfence_alloc_shm() != -1)
        return 1;
    if (xshmfence_map_shm(-1) != NULL)
        return 1;
    xshmfence_unmap_shm(NULL);

    puts("libxshmfence stub API test passed.");
    return 0;
}
