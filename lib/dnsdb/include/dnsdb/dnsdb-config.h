/* include/dnsdb/dnsdb-config.h.  Generated from dnsdb-config.h.in by configure.  */
/* include/dnsdb/dnsdb-config.h.in.  Generated from configure.ac by autoheader.  */

/* Define if building universal (internal helper macro) */
/* #undef AC_APPLE_UNIVERSAL_BUILD */

/* number of hardware core if the auto-detect fails */
#define DEFAULT_ASSUMED_CPU_COUNT 2

/* always on */
#define HAS_ACL_SUPPORT 1

/* bfd debug support disabled. */
#define HAS_BFD_DEBUG_SUPPORT 0

/* Disable timestamps in the build disabled. */
#define HAS_BUILD_TIMESTAMP 1

/* i386, Athlon, Opteron, Core2, i3, i5, i7, ... */
#define HAS_CPU_AMDINTEL 1

/* T1000 has a Niagara cpu */
/* #undef HAS_CPU_NIAGARA */

/* remote control disabled. */
#define HAS_CTRL 0

/* always on */
#define HAS_DNSSEC_SUPPORT 1

/* DROPALL mode will not actually send back the answer (debug/bench) */
#define HAS_DROPALL_SUPPORT 0

/* dynamic update support disabled. */
#define HAS_DYNUPDATE_SUPPORT 1

/* Elliptic Curve (ECDSA) support (ie: the available OpenSSL does not supports
   it) disabled. */
#define HAS_ECDSA_SUPPORT 1

/* acceptance of ASCII7 characters in DNS names (not recommended) disabled. */
#define HAS_FULL_ASCII7 0

/* libc malloc debug support monitors program-wide allocations disabled. */
#define HAS_LIBC_MALLOC_DEBUG_SUPPORT 0

/* where to put the log files */
#define HAS_LOGDIR 0

/* a column with the pid in each line of log disabled. */
#define HAS_LOG_PID_ALWAYS_ON 0

/* a column with an alphanumeric id consistent in the lowest 32 bits of a
   thread id in each log line disabled. */
#define HAS_LOG_THREAD_ID_ALWAYS_ON 0

/* a column with a 8 letters human-readable tag identifying a thread in each
   log line disabled. */
#define HAS_LOG_THREAD_TAG_ALWAYS_ON 0

/* malloc debug support for yadifa objects disabled. */
#define HAS_MALLOC_DEBUG_SUPPORT 0

/* DNS master disabled. */
#define HAS_MASTER_SUPPORT 1

/* Define this to enable slow but safe unaligned memory accesses */
#define HAS_MEMALIGN_ISSUES 0

/* usage of message structure API (not recommended) disabled. */
#define HAS_MESSAGES_SUPPORT 1

/* mutex debug support disabled. */
#define HAS_MUTEX_DEBUG_SUPPORT 0

/* lenient acceptance of AXFR answer from master that do not have AA bit set
   (Microsoft DNS) disabled. */
#define HAS_NON_AA_AXFR_SUPPORT 0

/* always on */
#define HAS_NSEC3_SUPPORT 1

/* always on */
#define HAS_NSEC_SUPPORT 1

/* NSID support disabled. */
#define HAS_NSID_SUPPORT 1

/* The system supports thread affinity */
#define HAS_PTHREAD_SETAFFINITY_NP 1

/* The system supports thread names */
#define HAS_PTHREAD_SETNAME_NP 1

/* The system supports spinlocks */
#define HAS_PTHREAD_SPINLOCK 1

/* always on */
#define HAS_RDTSC_SUPPORT 0

/* always on */
#define HAS_RRCACHE_ENABLED 1

/* DNS Response Rate Limiter disabled. */
#define HAS_RRL_SUPPORT 1

/* RRSIG verification and generation for zones disabled. */
#define HAS_RRSIG_MANAGEMENT_SUPPORT 1

/* The system supports setgroups */
#define HAS_SETGROUPS 1

/* tracking of the instanciated zones for detecting potential leaks.
   Relatively cheap with a small (<100) amount of zones. disabled. */
#define HAS_TRACK_ZONES_DEBUG_SUPPORT 0

/* always on */
#define HAS_TSIG_SUPPORT 1

/* where to put the log files */
/* #undef HAS_WITH_LOGDIR */

/* zalloc debug support for yadifa objects disabled. */
#define HAS_ZALLOC_DEBUG_SUPPORT 0

/* zalloc statistics support disabled. */
#define HAS_ZALLOC_STATISTICS_SUPPORT 0

/* zalloc memory system disabled. */
#define HAS_ZALLOC_SUPPORT 1

/* Define to 1 if you have the <arpa/inet.h> header file. */
#define HAVE_ARPA_INET_H 1

/* Define to 1 if you have the <byteswap.h> header file. */
#define HAVE_BYTESWAP_H 1

/* Define to 1 if you have the `bzero' function. */
/* #undef HAVE_BZERO */

/* Define to 1 if you have the <cpuid.h> header file. */
#define HAVE_CPUID_H 1

/* Define to 1 if you have the <dlfcn.h> header file. */
#define HAVE_DLFCN_H 1

/* Define to 1 if you have the <endian.h> header file. */
#define HAVE_ENDIAN_H 1

/* Define to 1 if you have the <fcntl.h> header file. */
#define HAVE_FCNTL_H 1

/* Define to 1 if you have the `fork' function. */
/* #undef HAVE_FORK */

/* Define to 1 if you have the <grp.h> header file. */
#define HAVE_GRP_H 1

/* Define to 1 if you have the <i386/limits.h> header file. */
/* #undef HAVE_I386_LIMITS_H */

/* Define to 1 if you have the <i386/types.h> header file. */
/* #undef HAVE_I386_TYPES_H */

/* Define to 1 if the system has the type `int64_t'. */
#define HAVE_INT64_T 1

/* Define to 1 if you have the <inttypes.h> header file. */
#define HAVE_INTTYPES_H 1

/* Define to 1 if you have the `c' library (-lc). */
#define HAVE_LIBC 1

/* Define to 1 if you have the `dnscore' library (-ldnscore). */
/* #undef HAVE_LIBDNSCORE */

/* Define to 1 if you have the `dnsdb' library (-ldnsdb). */
/* #undef HAVE_LIBDNSDB */

/* Define to 1 if you have the `dnslg' library (-ldnslg). */
/* #undef HAVE_LIBDNSLG */

/* Define to 1 if you have the `dnszone' library (-ldnszone). */
/* #undef HAVE_LIBDNSZONE */

/* Define to 1 if you have the <linux/limits.h> header file. */
#define HAVE_LINUX_LIMITS_H 1

/* Define to 1 if the system has the type `long long'. */
#define HAVE_LONG_LONG 1

/* Define to 1 if you have the <machine/endian.h> header file. */
/* #undef HAVE_MACHINE_ENDIAN_H */

/* Define to 1 if you have the <memory.h> header file. */
#define HAVE_MEMORY_H 1

/* Define to 1 if you have the `memset' function. */
/* #undef HAVE_MEMSET */

/* Define to 1 if you have the <netinet6/in6.h> header file. */
/* #undef HAVE_NETINET6_IN6_H */

/* Define to 1 if you have the <netinet/in.h> header file. */
#define HAVE_NETINET_IN_H 1

/* Define to 1 if you have the <ppc/limits.h> header file. */
/* #undef HAVE_PPC_LIMITS_H */

/* Define to 1 if you have the <pthread.h> header file. */
#define HAVE_PTHREAD_H 1

/* Define to 1 if you have the `select' function. */
/* #undef HAVE_SELECT */

/* Define to 1 if you have the `socket' function. */
/* #undef HAVE_SOCKET */

/* Define to 1 if `stat' has the bug that it succeeds when given the
   zero-length file name argument. */
#define HAVE_STAT_EMPTY_STRING_BUG 1

/* Define to 1 if you have the <stdint.h> header file. */
#define HAVE_STDINT_H 1

/* Define to 1 if you have the <stdio.h> header file. */
#define HAVE_STDIO_H 1

/* Define to 1 if you have the <stdlib.h> header file. */
#define HAVE_STDLIB_H 1

/* Define to 1 if you have the <strings.h> header file. */
#define HAVE_STRINGS_H 1

/* Define to 1 if you have the <string.h> header file. */
#define HAVE_STRING_H 1

/* Define to 1 if you have the <syslog.h> header file. */
#define HAVE_SYSLOG_H 1

/* Define to 1 if you have the <sys/byteorder.h> header file. */
/* #undef HAVE_SYS_BYTEORDER_H */

/* Define to 1 if you have the <sys/endian.h> header file. */
/* #undef HAVE_SYS_ENDIAN_H */

/* Define to 1 if you have the <sys/select.h> header file. */
#define HAVE_SYS_SELECT_H 1

/* Define to 1 if you have the <sys/socket.h> header file. */
#define HAVE_SYS_SOCKET_H 1

/* Define to 1 if you have the <sys/stat.h> header file. */
#define HAVE_SYS_STAT_H 1

/* Define to 1 if you have the <sys/syslimits.h> header file. */
/* #undef HAVE_SYS_SYSLIMITS_H */

/* Define to 1 if you have the <sys/time.h> header file. */
#define HAVE_SYS_TIME_H 1

/* Define to 1 if you have the <sys/types.h> header file. */
#define HAVE_SYS_TYPES_H 1

/* Define to 1 if the system has the type `uint64_t'. */
#define HAVE_UINT64_T 1

/* Define to 1 if you have the <unistd.h> header file. */
#define HAVE_UNISTD_H 1

/* Define to 1 if the system has the type `u_char'. */
#define HAVE_U_CHAR 1

/* Define to 1 if you have the `vfork' function. */
/* #undef HAVE_VFORK */

/* Define to 1 if you have the <vfork.h> header file. */
/* #undef HAVE_VFORK_H */

/* Define to 1 if `fork' works. */
/* #undef HAVE_WORKING_FORK */

/* Define to 1 if `vfork' works. */
/* #undef HAVE_WORKING_VFORK */

/* BSD */
#define IS_BSD_FAMILY 0

/* OSX */
#define IS_DARWIN_OS 0

/* LINUX */
#define IS_LINUX_FAMILY 1

/* SOLARIS */
#define IS_SOLARIS_FAMILY 0

/* Define to 1 if `lstat' dereferences a symlink specified with a trailing
   slash. */
/* #undef LSTAT_FOLLOWS_SLASHED_SYMLINK */

/* Define to the sub-directory where libtool stores uninstalled libraries. */
#define LT_OBJDIR ".libs/"

/* Name of package */
#define PACKAGE "dnsdb"

/* Define to the address where bug reports for this package should be sent. */
#define PACKAGE_BUGREPORT "bugreport@yadifa.eu"

/* Define to the full name of this package. */
#define PACKAGE_NAME "dnsdb"

/* Define to the full name and version of this package. */
#define PACKAGE_STRING "dnsdb 2.3.8-7713"

/* Define to the one symbol short name of this package. */
#define PACKAGE_TARNAME "dnsdb"

/* Define to the home page for this package. */
#define PACKAGE_URL ""

/* Define to the version of this package. */
#define PACKAGE_VERSION "2.3.8-7713"

/* Define as the return type of signal handlers (`int' or `void'). */
#define RETSIGTYPE void

/* Define to the type of arg 1 for `select'. */
#define SELECT_TYPE_ARG1 int

/* Define to the type of args 2, 3 and 4 for `select'. */
#define SELECT_TYPE_ARG234 (fd_set *)

/* Define to the type of arg 5 for `select'. */
#define SELECT_TYPE_ARG5 (struct timeval *)

/* Define to 1 if you have the ANSI C header files. */
#define STDC_HEADERS 1

/* Define to 1 if your <sys/time.h> declares `struct tm'. */
/* #undef TM_IN_SYS_TIME */

/* Version number of package */
#define VERSION "2.3.8-7713"

/* Define WORDS_BIGENDIAN to 1 if your processor stores words with the most
   significant byte first (like Motorola and SPARC, unlike Intel). */
#if defined AC_APPLE_UNIVERSAL_BUILD
# if defined __BIG_ENDIAN__
#  define WORDS_BIGENDIAN 1
# endif
#else
# ifndef WORDS_BIGENDIAN
/* #  undef WORDS_BIGENDIAN */
# endif
#endif

/* Enable large inode numbers on Mac OS X 10.5.  */
#ifndef _DARWIN_USE_64_BIT_INODE
# define _DARWIN_USE_64_BIT_INODE 1
#endif

/* Number of bits in a file offset, on hosts where this is settable. */
/* #undef _FILE_OFFSET_BITS */

/* Define for large files, on AIX-style hosts. */
/* #undef _LARGE_FILES */

/* Define to empty if `const' does not conform to ANSI C. */
/* #undef const */

/* Define to `int' if <sys/types.h> does not define. */
/* #undef mode_t */

/* Define to `int' if <sys/types.h> does not define. */
/* #undef pid_t */

/* Define to `unsigned int' if <sys/types.h> does not define. */
/* #undef size_t */

/* Define as `fork' if `vfork' does not work. */
#define vfork fork
