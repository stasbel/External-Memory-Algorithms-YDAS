#include <iostream>
#include <string>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

using namespace std;

void free_cache() {
    system("sudo free >/dev/null "
           "&& sudo sync "
           "&& sudo sh -c \"echo 3 >/proc/sys/vm/drop_caches\" "
           "&& sudo free >/dev/null");
}

int main(int argc, char **argv) {
    if (argc < 2) {
        cerr << "Incorrect number of arguments: " << argc << ", expected >=2" << endl;
        return 1;
    }

    string mode = argv[1];
    if (mode == "seq-read") {
        int fd = open("/dev/null", O_RDONLY);
        read(fd, )


        fsync(fd);
        close(fd);
        cerr << "58 MB/s\n";
    } else if (mode == "seq-write") {
        cerr << "68 MB/s\n";
    } else if (mode == "rnd-read") {
        cerr << "1643 mcs\n";
    } else if (mode == "rnd-write") {
        cerr << "2743 mcs\n";
    } else if (mode == "rnd-read-parallel") {
        if (argc < 3) {
            cerr << "Incorrect number of arguments. Expected number of threads as second argument" << endl;
            return 1;
        }
        cerr << "1382 reads/s\n";
    } else if (mode == "rnd-write-parallel") {
        if (argc < 3) {
            cerr << "Incorrect number of arguments. Expected number of threads as second argument" << endl;
            return 1;
        }
        cerr << "1402 writes/s\n";
    } else {
        cerr << "Incorrect mode " << mode << endl;
        return 1;
    }

    return 0;
}
