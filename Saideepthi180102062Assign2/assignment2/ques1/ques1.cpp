# include "global.h"
# include "complex.h"

lli recpower(lli x, lli n, lli mod)
{
    if (n == 0)
        return 1;
    else if (n % 2 == 0) //n is even
        return recpower((x * x) % mod, n / 2, mod);
    else //n is odd
        return (x * recpower((x * x) % mod, (n - 1) / 2, mod)) % mod;
}








