#include <iostream>
#include <unistd.h>

#ifndef PASSWORD
#error "Undefined PASSWORD"
#include <stophere>
#endif

/*
 *  https://github.com/adamyaxley/Obfuscate
 */
#ifndef AY_OBFUSCATE_DEFAULT_KEY
#define AY_OBFUSCATE_DEFAULT_KEY ay::generate_key(65534)
#endif

#include "obfuscate.h"
/***/

#define USAGE std::cout << "Usage: " << argv0 << " [-h, --help] [-d, --delete]" << std::endl

int main(int argc, const char **argv)
{
    if (argc > 1) {
        const std::string argv0(argv[0]);
        const std::string argv1(argv[1]);

        if (argv1 == "--help" || argv1 == "-h") {
            USAGE;
            return 0;
        } else if (argv1 == "--delete" || argv1 == "-d") {
            unlink(argv0.c_str());
        } else {
            USAGE;
            return 1;
        }
    }

    std::cout << AY_OBFUSCATE(PASSWORD) << std::endl;
    return 0;
}
