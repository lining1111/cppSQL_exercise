message(STATUS "Conan: Using CMakeDeps conandeps_legacy.cmake aggregator via include()")
message(STATUS "Conan: It is recommended to use explicit find_package() per dependency instead")

find_package(glog)
find_package(gflags)
find_package(fmt)
find_package(Poco)
find_package(xpack)
find_package(indicators)
find_package(CURL)
find_package(OpenSSL)

set(CONANDEPS_LEGACY  glog::glog  gflags::gflags  fmt::fmt  Poco::Poco  xpack::xpack  indicators::indicators  CURL::libcurl  openssl::openssl )