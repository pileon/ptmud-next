cmake_minimum_required(VERSION 3.3)
project(ptmud-next
        LANGUAGES C
        VERSION 0.0.1)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99 -Wall -Wextra -pedantic -Wno-unused-parameter -pipe")

if(CMAKE_HOST_UNIX)
    add_definitions(-D_POSIX_C_SOURCE=200809L -D_XOPEN_SOURCE=700)
endif()

include(CheckIncludeFiles)

set(CIRCLE_UNIX True)
set(RETSIGTYPE "void")

check_include_files(string.h HAVE_STRING_H)
check_include_files(stdlib.h HAVE_STDLIB_H)
check_include_files(stdarg.h HAVE_STDARG_H)
check_include_files(float.h HAVE_FLOAT_H)
check_include_files(memory.h HAVE_MEMORY_H)
check_include_files(unistd.h HAVE_UNISTD_H)
check_include_files(sys/types.h HAVE_SYS_TYPES_H)
check_include_files(limits.h HAVE_LIMITS_H)
check_include_files(errno.h HAVE_ERRNO_H)
check_include_files(net/errno.h HAVE_NET_ERRNO_H)
check_include_files(sys/errno.h HAVE_SYS_ERRNO_H)
check_include_files(crypt.h HAVE_CRYPT_H)
check_include_files(sys/time.h HAVE_SYS_TIME_H)
check_include_files(time.h HAVE_TIME_H)
check_include_files(assert.h HAVE_ASSERT_H)
check_include_files(sys/select.h HAVE_SYS_SELECT_H)
check_include_files(fcntl.h HAVE_FCNTL_H)
check_include_files(sys/fcntl.h HAVE_SYS_FCNTL_H)
check_include_files(sys/socket.h HAVE_SYS_SOCKET_H)
check_include_files(sys/resource.h HAVE_SYS_RESOURCE_H)
check_include_files(sys/wait.h HAVE_SYS_WAIT_H)
check_include_files(netinet/in.h HAVE_NETINET_IN_H)
check_include_files(arpa/inet.h HAVE_ARPA_INET_H)
check_include_files(arpa/telnet.h HAVE_ARPA_TELNET_H)
check_include_files(netdb.h HAVE_NETDB_H)
check_include_files(signal.h HAVE_SIGNAL_H)
check_include_files(sys/uio.h HAVE_SYS_UIO_H)
check_include_files(sys/stat.h HAVE_SYS_STAT_H)

configure_file(src/conf.h.in ${CMAKE_CURRENT_SOURCE_DIR}/src/conf.h)

add_subdirectory(src)
