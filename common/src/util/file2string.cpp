#include "file2string.h"

#include <fstream>

#include "muduo/base/Logging.h"

namespace common
{
//http://www.cplusplus.com/reference/istream/istream/read/
std::string File2String(const std::string& filename)
{
    std::ifstream is(filename, std::ifstream::binary);
    std::string jssbuffer;
    if (is) {
        // get length of file:
        is.seekg(0, is.end);
        int length = (int)is.tellg();
        length = length + 1;
        is.seekg(0, is.beg);
        char* buffer = new char[length];
        memset(buffer, 0, length);
        // read data as a block:
        is.read(buffer, length);
        is.close();
        // ...buffer contains the entire file...
        jssbuffer = buffer;
        //jssbuffer.erase(remove_if(jssbuffer.begin(), jssbuffer.end(), iscntrl), jssbuffer.end());
        //jssbuffer.erase(remove_if(jssbuffer.begin(), jssbuffer.end(), isspace), jssbuffer.end());
        delete[] buffer;
    }
    else
    {
        LOG_FATAL << " No such file or directory " << filename;
    }
    return jssbuffer;
}

}//namespace common
