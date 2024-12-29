# SPDX-License-Identifier: MIT

cmake_minimum_required(VERSION 3.20)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(HevSocks5Tunnel LANGUAGES C CXX ASM)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS ON)

add_library(lwip OBJECT
    ${CMAKE_CURRENT_LIST_DIR}/third-part/lwip/src/api/api_lib.c
    ${CMAKE_CURRENT_LIST_DIR}/third-part/lwip/src/api/api_msg.c
    ${CMAKE_CURRENT_LIST_DIR}/third-part/lwip/src/api/err.c
    ${CMAKE_CURRENT_LIST_DIR}/third-part/lwip/src/api/if_api.c
    ${CMAKE_CURRENT_LIST_DIR}/third-part/lwip/src/api/netbuf.c
    ${CMAKE_CURRENT_LIST_DIR}/third-part/lwip/src/api/netdb.c
    ${CMAKE_CURRENT_LIST_DIR}/third-part/lwip/src/api/netifapi.c
    ${CMAKE_CURRENT_LIST_DIR}/third-part/lwip/src/api/sockets.c
    ${CMAKE_CURRENT_LIST_DIR}/third-part/lwip/src/api/tcpip.c
    ${CMAKE_CURRENT_LIST_DIR}/third-part/lwip/src/core/altcp.c
    ${CMAKE_CURRENT_LIST_DIR}/third-part/lwip/src/core/altcp_alloc.c
    ${CMAKE_CURRENT_LIST_DIR}/third-part/lwip/src/core/altcp_tcp.c
    ${CMAKE_CURRENT_LIST_DIR}/third-part/lwip/src/core/def.c
    ${CMAKE_CURRENT_LIST_DIR}/third-part/lwip/src/core/dns.c
    ${CMAKE_CURRENT_LIST_DIR}/third-part/lwip/src/core/inet_chksum.c
    ${CMAKE_CURRENT_LIST_DIR}/third-part/lwip/src/core/init.c
    ${CMAKE_CURRENT_LIST_DIR}/third-part/lwip/src/core/ip.c
    ${CMAKE_CURRENT_LIST_DIR}/third-part/lwip/src/core/ipv4/acd.c
    ${CMAKE_CURRENT_LIST_DIR}/third-part/lwip/src/core/ipv4/autoip.c
    ${CMAKE_CURRENT_LIST_DIR}/third-part/lwip/src/core/ipv4/dhcp.c
    ${CMAKE_CURRENT_LIST_DIR}/third-part/lwip/src/core/ipv4/etharp.c
    ${CMAKE_CURRENT_LIST_DIR}/third-part/lwip/src/core/ipv4/icmp.c
    ${CMAKE_CURRENT_LIST_DIR}/third-part/lwip/src/core/ipv4/igmp.c
    ${CMAKE_CURRENT_LIST_DIR}/third-part/lwip/src/core/ipv4/ip4.c
    ${CMAKE_CURRENT_LIST_DIR}/third-part/lwip/src/core/ipv4/ip4_addr.c
    ${CMAKE_CURRENT_LIST_DIR}/third-part/lwip/src/core/ipv4/ip4_frag.c
    ${CMAKE_CURRENT_LIST_DIR}/third-part/lwip/src/core/ipv6/dhcp6.c
    ${CMAKE_CURRENT_LIST_DIR}/third-part/lwip/src/core/ipv6/ethip6.c
    ${CMAKE_CURRENT_LIST_DIR}/third-part/lwip/src/core/ipv6/icmp6.c
    ${CMAKE_CURRENT_LIST_DIR}/third-part/lwip/src/core/ipv6/inet6.c
    ${CMAKE_CURRENT_LIST_DIR}/third-part/lwip/src/core/ipv6/ip6.c
    ${CMAKE_CURRENT_LIST_DIR}/third-part/lwip/src/core/ipv6/ip6_addr.c
    ${CMAKE_CURRENT_LIST_DIR}/third-part/lwip/src/core/ipv6/ip6_frag.c
    ${CMAKE_CURRENT_LIST_DIR}/third-part/lwip/src/core/ipv6/mld6.c
    ${CMAKE_CURRENT_LIST_DIR}/third-part/lwip/src/core/ipv6/nd6.c
    ${CMAKE_CURRENT_LIST_DIR}/third-part/lwip/src/core/mem.c
    ${CMAKE_CURRENT_LIST_DIR}/third-part/lwip/src/core/memp.c
    ${CMAKE_CURRENT_LIST_DIR}/third-part/lwip/src/core/netif.c
    ${CMAKE_CURRENT_LIST_DIR}/third-part/lwip/src/core/pbuf.c
    ${CMAKE_CURRENT_LIST_DIR}/third-part/lwip/src/core/raw.c
    ${CMAKE_CURRENT_LIST_DIR}/third-part/lwip/src/core/stats.c
    ${CMAKE_CURRENT_LIST_DIR}/third-part/lwip/src/core/sys.c
    ${CMAKE_CURRENT_LIST_DIR}/third-part/lwip/src/core/tcp.c
    ${CMAKE_CURRENT_LIST_DIR}/third-part/lwip/src/core/tcp_in.c
    ${CMAKE_CURRENT_LIST_DIR}/third-part/lwip/src/core/tcp_out.c
    ${CMAKE_CURRENT_LIST_DIR}/third-part/lwip/src/core/timeouts.c
    ${CMAKE_CURRENT_LIST_DIR}/third-part/lwip/src/core/udp.c
    ${CMAKE_CURRENT_LIST_DIR}/third-part/lwip/src/netif/bridgeif.c
    ${CMAKE_CURRENT_LIST_DIR}/third-part/lwip/src/netif/bridgeif_fdb.c
    ${CMAKE_CURRENT_LIST_DIR}/third-part/lwip/src/netif/ethernet.c
    ${CMAKE_CURRENT_LIST_DIR}/third-part/lwip/src/netif/lowpan6.c
    ${CMAKE_CURRENT_LIST_DIR}/third-part/lwip/src/netif/lowpan6_ble.c
    ${CMAKE_CURRENT_LIST_DIR}/third-part/lwip/src/netif/lowpan6_common.c
    ${CMAKE_CURRENT_LIST_DIR}/third-part/lwip/src/netif/ppp/auth.c
    ${CMAKE_CURRENT_LIST_DIR}/third-part/lwip/src/netif/ppp/ccp.c
    ${CMAKE_CURRENT_LIST_DIR}/third-part/lwip/src/netif/ppp/chap-md5.c
    ${CMAKE_CURRENT_LIST_DIR}/third-part/lwip/src/netif/ppp/chap-new.c
    ${CMAKE_CURRENT_LIST_DIR}/third-part/lwip/src/netif/ppp/chap_ms.c
    ${CMAKE_CURRENT_LIST_DIR}/third-part/lwip/src/netif/ppp/demand.c
    ${CMAKE_CURRENT_LIST_DIR}/third-part/lwip/src/netif/ppp/eap.c
    ${CMAKE_CURRENT_LIST_DIR}/third-part/lwip/src/netif/ppp/ecp.c
    ${CMAKE_CURRENT_LIST_DIR}/third-part/lwip/src/netif/ppp/eui64.c
    ${CMAKE_CURRENT_LIST_DIR}/third-part/lwip/src/netif/ppp/fsm.c
    ${CMAKE_CURRENT_LIST_DIR}/third-part/lwip/src/netif/ppp/ipcp.c
    ${CMAKE_CURRENT_LIST_DIR}/third-part/lwip/src/netif/ppp/ipv6cp.c
    ${CMAKE_CURRENT_LIST_DIR}/third-part/lwip/src/netif/ppp/lcp.c
    ${CMAKE_CURRENT_LIST_DIR}/third-part/lwip/src/netif/ppp/magic.c
    ${CMAKE_CURRENT_LIST_DIR}/third-part/lwip/src/netif/ppp/mppe.c
    ${CMAKE_CURRENT_LIST_DIR}/third-part/lwip/src/netif/ppp/multilink.c
    ${CMAKE_CURRENT_LIST_DIR}/third-part/lwip/src/netif/ppp/polarssl/arc4.c
    ${CMAKE_CURRENT_LIST_DIR}/third-part/lwip/src/netif/ppp/polarssl/des.c
    ${CMAKE_CURRENT_LIST_DIR}/third-part/lwip/src/netif/ppp/polarssl/md4.c
    ${CMAKE_CURRENT_LIST_DIR}/third-part/lwip/src/netif/ppp/polarssl/md5.c
    ${CMAKE_CURRENT_LIST_DIR}/third-part/lwip/src/netif/ppp/polarssl/sha1.c
    ${CMAKE_CURRENT_LIST_DIR}/third-part/lwip/src/netif/ppp/ppp.c
    ${CMAKE_CURRENT_LIST_DIR}/third-part/lwip/src/netif/ppp/pppapi.c
    ${CMAKE_CURRENT_LIST_DIR}/third-part/lwip/src/netif/ppp/pppcrypt.c
    ${CMAKE_CURRENT_LIST_DIR}/third-part/lwip/src/netif/ppp/pppoe.c
    ${CMAKE_CURRENT_LIST_DIR}/third-part/lwip/src/netif/ppp/pppol2tp.c
    ${CMAKE_CURRENT_LIST_DIR}/third-part/lwip/src/netif/ppp/pppos.c
    ${CMAKE_CURRENT_LIST_DIR}/third-part/lwip/src/netif/ppp/upap.c
    ${CMAKE_CURRENT_LIST_DIR}/third-part/lwip/src/netif/ppp/utils.c
    ${CMAKE_CURRENT_LIST_DIR}/third-part/lwip/src/netif/ppp/vj.c
    ${CMAKE_CURRENT_LIST_DIR}/third-part/lwip/src/netif/slipif.c
    ${CMAKE_CURRENT_LIST_DIR}/third-part/lwip/src/netif/zepif.c
    ${CMAKE_CURRENT_LIST_DIR}/third-part/lwip/src/ports/lib/mem.c
    ${CMAKE_CURRENT_LIST_DIR}/third-part/lwip/src/ports/unix/lib/perf.c
    ${CMAKE_CURRENT_LIST_DIR}/third-part/lwip/src/ports/unix/lib/sys_arch.c
    ${CMAKE_CURRENT_LIST_DIR}/third-part/lwip/src/ports/unix/netif/fifo.c
    ${CMAKE_CURRENT_LIST_DIR}/third-part/lwip/src/ports/unix/netif/list.c
    ${CMAKE_CURRENT_LIST_DIR}/third-part/lwip/src/ports/unix/netif/pcapif.c
    ${CMAKE_CURRENT_LIST_DIR}/third-part/lwip/src/ports/unix/netif/sio.c
    ${CMAKE_CURRENT_LIST_DIR}/third-part/lwip/src/ports/unix/netif/tapif.c
)

target_include_directories(lwip
    PUBLIC ${CMAKE_CURRENT_LIST_DIR}/third-part/lwip/src/include
    PUBLIC ${CMAKE_CURRENT_LIST_DIR}/third-part/lwip/src/ports/include
)

add_library(HevTaskSystem OBJECT
    ${CMAKE_CURRENT_LIST_DIR}/third-part/hev-task-system/src/kern/aide/hev-task-aide.c
    ${CMAKE_CURRENT_LIST_DIR}/third-part/hev-task-system/src/kern/core/hev-task-system-schedule.c
    ${CMAKE_CURRENT_LIST_DIR}/third-part/hev-task-system/src/kern/core/hev-task-system.c
    ${CMAKE_CURRENT_LIST_DIR}/third-part/hev-task-system/src/kern/io/hev-task-io-reactor-epoll.c
    ${CMAKE_CURRENT_LIST_DIR}/third-part/hev-task-system/src/kern/io/hev-task-io-reactor-kqueue.c
    ${CMAKE_CURRENT_LIST_DIR}/third-part/hev-task-system/src/kern/io/hev-task-io-reactor.c
    ${CMAKE_CURRENT_LIST_DIR}/third-part/hev-task-system/src/kern/itc/hev-task-channel-select.c
    ${CMAKE_CURRENT_LIST_DIR}/third-part/hev-task-system/src/kern/itc/hev-task-channel.c
    ${CMAKE_CURRENT_LIST_DIR}/third-part/hev-task-system/src/kern/sync/hev-task-cond.c
    ${CMAKE_CURRENT_LIST_DIR}/third-part/hev-task-system/src/kern/sync/hev-task-mutex.c
    ${CMAKE_CURRENT_LIST_DIR}/third-part/hev-task-system/src/kern/task/hev-task-call.c
    ${CMAKE_CURRENT_LIST_DIR}/third-part/hev-task-system/src/kern/task/hev-task-executer.c
    ${CMAKE_CURRENT_LIST_DIR}/third-part/hev-task-system/src/kern/task/hev-task-stack-heap.c
    ${CMAKE_CURRENT_LIST_DIR}/third-part/hev-task-system/src/kern/task/hev-task-stack-mmap.c
    ${CMAKE_CURRENT_LIST_DIR}/third-part/hev-task-system/src/kern/task/hev-task.c
    ${CMAKE_CURRENT_LIST_DIR}/third-part/hev-task-system/src/kern/time/hev-task-timer-kevent.c
    ${CMAKE_CURRENT_LIST_DIR}/third-part/hev-task-system/src/kern/time/hev-task-timer-timerfd.c
    ${CMAKE_CURRENT_LIST_DIR}/third-part/hev-task-system/src/kern/time/hev-task-timer.c
    ${CMAKE_CURRENT_LIST_DIR}/third-part/hev-task-system/src/lib/cio/base/hev-task-cio.c
    ${CMAKE_CURRENT_LIST_DIR}/third-part/hev-task-system/src/lib/cio/buffer/hev-task-cio-buffer.c
    ${CMAKE_CURRENT_LIST_DIR}/third-part/hev-task-system/src/lib/cio/fd/hev-task-cio-fd.c
    ${CMAKE_CURRENT_LIST_DIR}/third-part/hev-task-system/src/lib/cio/null/hev-task-cio-null.c
    ${CMAKE_CURRENT_LIST_DIR}/third-part/hev-task-system/src/lib/cio/socket/hev-task-cio-socket.c
    ${CMAKE_CURRENT_LIST_DIR}/third-part/hev-task-system/src/lib/dns/hev-task-dns-proxy.c
    ${CMAKE_CURRENT_LIST_DIR}/third-part/hev-task-system/src/lib/dns/hev-task-dns.c
    ${CMAKE_CURRENT_LIST_DIR}/third-part/hev-task-system/src/lib/io/basic/hev-task-io.c
    ${CMAKE_CURRENT_LIST_DIR}/third-part/hev-task-system/src/lib/io/buffer/hev-circular-buffer.c
    ${CMAKE_CURRENT_LIST_DIR}/third-part/hev-task-system/src/lib/io/pipe/hev-task-io-pipe.c
    ${CMAKE_CURRENT_LIST_DIR}/third-part/hev-task-system/src/lib/io/poll/hev-task-io-poll.c
    ${CMAKE_CURRENT_LIST_DIR}/third-part/hev-task-system/src/lib/io/socket/hev-task-io-socket.c
    ${CMAKE_CURRENT_LIST_DIR}/third-part/hev-task-system/src/lib/list/hev-list.c
    ${CMAKE_CURRENT_LIST_DIR}/third-part/hev-task-system/src/lib/misc/hev-debugger.c
    ${CMAKE_CURRENT_LIST_DIR}/third-part/hev-task-system/src/lib/misc/hev-task-stack-detector.c
    ${CMAKE_CURRENT_LIST_DIR}/third-part/hev-task-system/src/lib/object/hev-object-atomic.c
    ${CMAKE_CURRENT_LIST_DIR}/third-part/hev-task-system/src/lib/object/hev-object.c
    ${CMAKE_CURRENT_LIST_DIR}/third-part/hev-task-system/src/lib/rbtree/hev-rbtree-cached.c
    ${CMAKE_CURRENT_LIST_DIR}/third-part/hev-task-system/src/lib/rbtree/hev-rbtree.c
    ${CMAKE_CURRENT_LIST_DIR}/third-part/hev-task-system/src/mem/api/hev-memory-allocator-api.c
    ${CMAKE_CURRENT_LIST_DIR}/third-part/hev-task-system/src/mem/base/hev-memory-allocator.c
    ${CMAKE_CURRENT_LIST_DIR}/third-part/hev-task-system/src/mem/simple/hev-memory-allocator-simple.c
    ${CMAKE_CURRENT_LIST_DIR}/third-part/hev-task-system/src/mem/slice/hev-memory-allocator-slice.c
    ${CMAKE_CURRENT_LIST_DIR}/third-part/hev-task-system/src/kern/task/hev-task-execute.S
)

target_include_directories(HevTaskSystem
    PUBLIC      ${CMAKE_CURRENT_LIST_DIR}/third-part/hev-task-system/include
    INTERFACE   ${CMAKE_CURRENT_LIST_DIR}/third-part/hev-task-system/src/lib/
    PRIVATE     ${CMAKE_CURRENT_LIST_DIR}/third-part/hev-task-system/src/
)

target_compile_definitions(HevTaskSystem
    PRIVATE
    CONFIG_STACK_BACKEND=STACK_MMAP
    CONFIG_STACK_OVERFLOW_DETECTION=1
    CONFIG_MEMALLOC_SLICE_ALIGN=64
    CONFIG_MEMALLOC_SLICE_MAX_SIZE=4096
    CONFIG_MEMALLOC_SLICE_MAX_COUNT=1000
    CONFIG_SCHED_CLOCK=CLOCK_NONE
)

add_library(HevSocks5Tunnel STATIC
# add_executable(HevSocks5Tunnel
    ${CMAKE_CURRENT_LIST_DIR}/src/hev-main.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/hev-socks5-tunnel.c
    ${CMAKE_CURRENT_LIST_DIR}/src/hev-socks5-session.c
    ${CMAKE_CURRENT_LIST_DIR}/src/hev-socks5-session-udp.c
    ${CMAKE_CURRENT_LIST_DIR}/src/hev-socks5-session-tcp.c

    ${CMAKE_CURRENT_LIST_DIR}/src/misc/hev-ring-buffer.c
    ${CMAKE_CURRENT_LIST_DIR}/src/misc/hev-utils.c

    ${CMAKE_CURRENT_LIST_DIR}/src/socks5/hev-socks5-authenticator.c
    ${CMAKE_CURRENT_LIST_DIR}/src/socks5/hev-socks5-client-tcp.c
    ${CMAKE_CURRENT_LIST_DIR}/src/socks5/hev-socks5-client-udp.c
    ${CMAKE_CURRENT_LIST_DIR}/src/socks5/hev-socks5-client.c
    ${CMAKE_CURRENT_LIST_DIR}/src/socks5/hev-socks5-misc.c
    ${CMAKE_CURRENT_LIST_DIR}/src/socks5/hev-socks5-server.c
    ${CMAKE_CURRENT_LIST_DIR}/src/socks5/hev-socks5-tcp.c
    ${CMAKE_CURRENT_LIST_DIR}/src/socks5/hev-socks5-udp.c
    ${CMAKE_CURRENT_LIST_DIR}/src/socks5/hev-socks5-user.c
    ${CMAKE_CURRENT_LIST_DIR}/src/socks5/hev-socks5.c
)

target_include_directories(HevSocks5Tunnel
    PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/src/
    PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/src/misc
    ${CMAKE_CURRENT_LIST_DIR}/src/socks5
)

target_link_libraries(HevSocks5Tunnel
    PRIVATE
    lwip
    HevTaskSystem
)
