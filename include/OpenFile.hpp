#ifndef OPENFILE_HPP
#define OPENFILE_HPP

#include <iostream>
#include <fstream>
#include <sys/stat.h>
#include <sys/types.h>

class OpenFile {
public:
    OpenFile(std::string file) {
        config();
        name = cgroupFolder + file;
        os.open(name, std::ofstream::out | std::ofstream::app);
    }

    ~OpenFile() {
        std::cout << "Closing... " << name << " stream now." << std::endl;
        os.close();
        chmod(name.c_str(), permissionFlags);
    }

    template <typename T>
        void write(T content) {
            std::cout << "Adding " << content << " to " << name << "." << std::endl;
            os << content;
        }

private:
    void config() {
        mkdir(cgroupFolder.c_str(), permissionFlags);
    }

private:
    std::ofstream os;
    std::string name;

    std::string cgroupFolder = "/sys/fs/cgroup/pids/cg";
    int permissionFlags = S_IRUSR | S_IWUSR;
};

#endif

