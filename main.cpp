#include <cstdint>
#include <fstream>
#include <iostream>
#include <limits>

int main() {
  std::cout << "Maximum of std::streamsize: "
            << std::numeric_limits<std::streamsize>::max() << "\n";
  std::cout << "INT32_MAX: " << std::numeric_limits<int32_t>::max() << "\n";

  auto const filename = R"(test.dat)";  // a large file > INT32_MAX

  auto dataStream = std::ifstream();
  dataStream.open(filename, std::ios_base::binary);
  if (!dataStream.is_open()) {
    std::cerr << "Failed to open file, does it exist?\n";
    return 1;
  }
  dataStream.seekg(0, dataStream.end);
  size_t filesize = dataStream.tellg();
  std::cout << "Size of file: " << filesize << "\n";

  // buffer for the whole file
  auto buffer = new uint8_t[filesize];

  dataStream.seekg(0, dataStream.beg);
  std::cout << "Reading INT32_MAX bytes...\n";
  dataStream.read(reinterpret_cast<char *>(buffer),
                  std::numeric_limits<int32_t>::max());
  std::cout << "Read failed: " << dataStream.fail() << "\n";

  dataStream.seekg(0, dataStream.beg);
  std::cout << "Reading INT32_MAX + 1 bytes...\n";
  dataStream.read(
      reinterpret_cast<char *>(buffer),
      static_cast<int64_t>(std::numeric_limits<int32_t>::max()) + 1);
  std::cout << "Read failed: " << dataStream.fail() << "\n";

  delete[] buffer;
  return 0;
}
