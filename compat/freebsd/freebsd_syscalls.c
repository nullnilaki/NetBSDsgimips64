/* $NetBSD: freebsd_syscalls.c,v 1.90 2018/08/10 21:47:14 pgoyette Exp $ */

/*
 * System call names.
 *
 * DO NOT EDIT-- this file is automatically generated.
 * created from	NetBSD: syscalls.master,v 1.72 2018/01/06 16:41:23 kamil Exp
 */

#include <sys/cdefs.h>
__KERNEL_RCSID(0, "$NetBSD: freebsd_syscalls.c,v 1.90 2018/08/10 21:47:14 pgoyette Exp $");

#if defined(_KERNEL_OPT)
#if defined(_KERNEL_OPT)
#include "opt_ktrace.h"
#include "opt_ntp.h"
#include "opt_sysv.h"
#include "opt_compat_43.h"
#endif
#include <sys/param.h>
#include <sys/systm.h>
#include <sys/signal.h>
#include <sys/mount.h>
#include <sys/syscallargs.h>
#include <compat/sys/signal.h>
#include <compat/sys/time.h>
#include <compat/freebsd/freebsd_syscallargs.h>
#include <compat/freebsd/freebsd_machdep.h>
#else /* _KERNEL_OPT */
#include <sys/null.h>
#endif /* _KERNEL_OPT */

const char *const freebsd_syscallnames[] = {
	/*   0 */	"syscall",
	/*   1 */	"exit",
	/*   2 */	"fork",
	/*   3 */	"read",
	/*   4 */	"write",
	/*   5 */	"open",
	/*   6 */	"close",
	/*   7 */	"wait4",
	/*   8 */	"ocreat",
	/*   9 */	"link",
	/*  10 */	"unlink",
	/*  11 */	"#11 (obsolete execv)",
	/*  12 */	"chdir",
	/*  13 */	"fchdir",
	/*  14 */	"mknod",
	/*  15 */	"chmod",
	/*  16 */	"chown",
	/*  17 */	"break",
	/*  18 */	"getfsstat",
	/*  19 */	"olseek",
	/*  20 */	"getpid_with_ppid",
	/*  21 */	"mount",
	/*  22 */	"unmount",
	/*  23 */	"setuid",
	/*  24 */	"getuid_with_euid",
	/*  25 */	"geteuid",
	/*  26 */	"ptrace",
	/*  27 */	"recvmsg",
	/*  28 */	"sendmsg",
	/*  29 */	"recvfrom",
	/*  30 */	"accept",
	/*  31 */	"getpeername",
	/*  32 */	"getsockname",
	/*  33 */	"access",
	/*  34 */	"chflags",
	/*  35 */	"fchflags",
	/*  36 */	"sync",
	/*  37 */	"kill",
	/*  38 */	"stat43",
	/*  39 */	"getppid",
	/*  40 */	"lstat43",
	/*  41 */	"dup",
	/*  42 */	"pipe",
	/*  43 */	"getegid",
	/*  44 */	"profil",
#ifdef KTRACE
	/*  45 */	"ktrace",
#else
	/*  45 */	"#45 (excluded ktrace)",
#endif
	/*  46 */	"sigaction",
	/*  47 */	"getgid_with_egid",
	/*  48 */	"sigprocmask",
	/*  49 */	"__getlogin",
	/*  50 */	"__setlogin",
	/*  51 */	"acct",
	/*  52 */	"sigpending",
	/*  53 */	"sigaltstack",
	/*  54 */	"ioctl",
	/*  55 */	"oreboot",
	/*  56 */	"revoke",
	/*  57 */	"symlink",
	/*  58 */	"readlink",
	/*  59 */	"execve",
	/*  60 */	"umask",
	/*  61 */	"chroot",
	/*  62 */	"fstat43",
	/*  63 */	"ogetkerninfo",
	/*  64 */	"ogetpagesize",
	/*  65 */	"msync",
	/*  66 */	"vfork",
	/*  67 */	"#67 (obsolete vread)",
	/*  68 */	"#68 (obsolete vwrite)",
	/*  69 */	"#69 (obsolete sbrk)",
	/*  70 */	"#70 (obsolete sstk)",
	/*  71 */	"ommap",
	/*  72 */	"vadvise",
	/*  73 */	"munmap",
	/*  74 */	"mprotect",
	/*  75 */	"madvise",
	/*  76 */	"#76 (obsolete vhangup)",
	/*  77 */	"#77 (obsolete vlimit)",
	/*  78 */	"mincore",
	/*  79 */	"getgroups",
	/*  80 */	"setgroups",
	/*  81 */	"getpgrp",
	/*  82 */	"setpgid",
	/*  83 */	"setitimer",
	/*  84 */	"owait",
	/*  85 */	"swapon",
	/*  86 */	"getitimer",
	/*  87 */	"ogethostname",
	/*  88 */	"osethostname",
	/*  89 */	"ogetdtablesize",
	/*  90 */	"dup2",
	/*  91 */	"#91 (unimplemented getdopt)",
	/*  92 */	"fcntl",
	/*  93 */	"select",
	/*  94 */	"#94 (unimplemented setdopt)",
	/*  95 */	"fsync",
	/*  96 */	"setpriority",
	/*  97 */	"socket",
	/*  98 */	"connect",
	/*  99 */	"oaccept",
	/* 100 */	"getpriority",
	/* 101 */	"osend",
	/* 102 */	"orecv",
	/* 103 */	"sigreturn",
	/* 104 */	"bind",
	/* 105 */	"setsockopt",
	/* 106 */	"listen",
	/* 107 */	"#107 (obsolete vtimes)",
	/* 108 */	"osigvec",
	/* 109 */	"osigblock",
	/* 110 */	"osigsetmask",
	/* 111 */	"sigsuspend",
	/* 112 */	"osigstack",
	/* 113 */	"orecvmsg",
	/* 114 */	"osendmsg",
#ifdef TRACE
	/* 115 */	"vtrace",
#else
	/* 115 */	"#115 (obsolete vtrace)",
#endif
	/* 116 */	"gettimeofday",
	/* 117 */	"getrusage",
	/* 118 */	"getsockopt",
	/* 119 */	"#119 (obsolete resuba)",
	/* 120 */	"readv",
	/* 121 */	"writev",
	/* 122 */	"settimeofday",
	/* 123 */	"fchown",
	/* 124 */	"fchmod",
	/* 125 */	"orecvfrom",
	/* 126 */	"setreuid",
	/* 127 */	"setregid",
	/* 128 */	"rename",
	/* 129 */	"otruncate",
	/* 130 */	"oftruncate",
	/* 131 */	"flock",
	/* 132 */	"mkfifo",
	/* 133 */	"sendto",
	/* 134 */	"shutdown",
	/* 135 */	"socketpair",
	/* 136 */	"mkdir",
	/* 137 */	"rmdir",
	/* 138 */	"utimes",
	/* 139 */	"#139 (obsolete 4.2 sigreturn)",
	/* 140 */	"adjtime",
	/* 141 */	"ogetpeername",
	/* 142 */	"ogethostid",
	/* 143 */	"osethostid",
	/* 144 */	"ogetrlimit",
	/* 145 */	"osetrlimit",
	/* 146 */	"okillpg",
	/* 147 */	"setsid",
	/* 148 */	"quotactl",
	/* 149 */	"oquota",
	/* 150 */	"ogetsockname",
	/* 151 */	"#151 (unimplemented sem_lock)",
	/* 152 */	"#152 (unimplemented sem_wakeup)",
	/* 153 */	"#153 (unimplemented asyncdaemon)",
	/* 154 */	"#154 (unimplemented)",
	/* 155 */	"#155 (unimplemented nfssvc)",
	/* 156 */	"ogetdirentries",
	/* 157 */	"statfs",
	/* 158 */	"fstatfs",
	/* 159 */	"#159 (unimplemented)",
	/* 160 */	"#160 (unimplemented)",
	/* 161 */	"getfh",
	/* 162 */	"getdomainname",
	/* 163 */	"setdomainname",
	/* 164 */	"uname",
	/* 165 */	"sysarch",
	/* 166 */	"rtprio",
	/* 167 */	"#167 (unimplemented)",
	/* 168 */	"#168 (unimplemented)",
#if defined(SYSVSEM) && !defined(_LP64)
	/* 169 */	"semsys",
#else
	/* 169 */	"#169 (unimplemented 1.0 semsys)",
#endif
#if defined(SYSVMSG) && !defined(_LP64)
	/* 170 */	"msgsys",
#else
	/* 170 */	"#170 (unimplemented 1.0 msgsys)",
#endif
#if defined(SYSVSHM) && !defined(_LP64)
	/* 171 */	"shmsys",
#else
	/* 171 */	"#171 (unimplemented 1.0 shmsys)",
#endif
	/* 172 */	"#172 (unimplemented)",
	/* 173 */	"pread",
	/* 174 */	"pwrite",
	/* 175 */	"#175 (unimplemented)",
#ifdef NTP
	/* 176 */	"freebsd_ntp_adjtime",
#else
	/* 176 */	"#176 (excluded ntp_adjtime)",
#endif
	/* 177 */	"#177 (unimplemented sfork)",
	/* 178 */	"#178 (unimplemented getdescriptor)",
	/* 179 */	"#179 (unimplemented setdescriptor)",
	/* 180 */	"#180 (unimplemented)",
	/* 181 */	"setgid",
	/* 182 */	"setegid",
	/* 183 */	"seteuid",
	/* 184 */	"#184 (unimplemented)",
	/* 185 */	"#185 (unimplemented)",
	/* 186 */	"#186 (unimplemented)",
	/* 187 */	"#187 (unimplemented)",
	/* 188 */	"stat",
	/* 189 */	"fstat",
	/* 190 */	"lstat",
	/* 191 */	"pathconf",
	/* 192 */	"fpathconf",
	/* 193 */	"#193 (unimplemented)",
	/* 194 */	"getrlimit",
	/* 195 */	"setrlimit",
	/* 196 */	"getdirentries",
	/* 197 */	"mmap",
	/* 198 */	"__syscall",
	/* 199 */	"lseek",
	/* 200 */	"truncate",
	/* 201 */	"ftruncate",
	/* 202 */	"sysctl",
	/* 203 */	"mlock",
	/* 204 */	"munlock",
#ifdef FREEBSD_BASED_ON_44LITE_R2
	/* 205 */	"undelete",
#else
	/* 205 */	"#205 (unimplemented undelete)",
#endif
	/* 206 */	"futimes",
	/* 207 */	"getpgid",
#if 0
	/* 208 */	"reboot",
#else
	/* 208 */	"#208 (unimplemented newreboot)",
#endif
	/* 209 */	"poll",
	/* 210 */	"#210 (unimplemented)",
	/* 211 */	"#211 (unimplemented)",
	/* 212 */	"#212 (unimplemented)",
	/* 213 */	"#213 (unimplemented)",
	/* 214 */	"#214 (unimplemented)",
	/* 215 */	"#215 (unimplemented)",
	/* 216 */	"#216 (unimplemented)",
	/* 217 */	"#217 (unimplemented)",
	/* 218 */	"#218 (unimplemented)",
	/* 219 */	"#219 (unimplemented)",
#ifdef SYSVSEM
	/* 220 */	"__semctl",
	/* 221 */	"semget",
	/* 222 */	"semop",
	/* 223 */	"semconfig",
#else
	/* 220 */	"#220 (unimplemented semctl)",
	/* 221 */	"#221 (unimplemented semget)",
	/* 222 */	"#222 (unimplemented semop)",
	/* 223 */	"#223 (unimplemented semconfig)",
#endif
#ifdef SYSVMSG
	/* 224 */	"msgctl",
	/* 225 */	"msgget",
	/* 226 */	"msgsnd",
	/* 227 */	"msgrcv",
#else
	/* 224 */	"#224 (unimplemented msgctl)",
	/* 225 */	"#225 (unimplemented msgget)",
	/* 226 */	"#226 (unimplemented msgsnd)",
	/* 227 */	"#227 (unimplemented msgrcv)",
#endif
#ifdef SYSVSHM
	/* 228 */	"shmat",
	/* 229 */	"shmctl",
	/* 230 */	"shmdt",
	/* 231 */	"shmget",
#else
	/* 228 */	"#228 (unimplemented shmat)",
	/* 229 */	"#229 (unimplemented shmctl)",
	/* 230 */	"#230 (unimplemented shmdt)",
	/* 231 */	"#231 (unimplemented shmget)",
#endif
	/* 232 */	"clock_gettime",
	/* 233 */	"clock_settime",
	/* 234 */	"clock_getres",
	/* 235 */	"#235 (unimplemented timer_create)",
	/* 236 */	"#236 (unimplemented timer_delete)",
	/* 237 */	"#237 (unimplemented timer_settime)",
	/* 238 */	"#238 (unimplemented timer_gettime)",
	/* 239 */	"#239 (unimplemented timer_getoverrun)",
	/* 240 */	"nanosleep",
	/* 241 */	"#241 (unimplemented)",
	/* 242 */	"#242 (unimplemented)",
	/* 243 */	"#243 (unimplemented)",
	/* 244 */	"#244 (unimplemented)",
	/* 245 */	"#245 (unimplemented)",
	/* 246 */	"#246 (unimplemented)",
	/* 247 */	"#247 (unimplemented)",
	/* 248 */	"#248 (unimplemented)",
	/* 249 */	"#249 (unimplemented)",
	/* 250 */	"minherit",
	/* 251 */	"rfork",
	/* 252 */	"#252 (unimplemented openbsd_poll)",
	/* 253 */	"issetugid",
	/* 254 */	"lchown",
	/* 255 */	"#255 (unimplemented)",
	/* 256 */	"#256 (unimplemented)",
	/* 257 */	"#257 (unimplemented)",
	/* 258 */	"#258 (unimplemented)",
	/* 259 */	"#259 (unimplemented)",
	/* 260 */	"#260 (unimplemented)",
	/* 261 */	"#261 (unimplemented)",
	/* 262 */	"#262 (unimplemented)",
	/* 263 */	"#263 (unimplemented)",
	/* 264 */	"#264 (unimplemented)",
	/* 265 */	"#265 (unimplemented)",
	/* 266 */	"#266 (unimplemented)",
	/* 267 */	"#267 (unimplemented)",
	/* 268 */	"#268 (unimplemented)",
	/* 269 */	"#269 (unimplemented)",
	/* 270 */	"#270 (unimplemented)",
	/* 271 */	"#271 (unimplemented)",
	/* 272 */	"getdents",
	/* 273 */	"#273 (unimplemented)",
	/* 274 */	"lchmod",
	/* 275 */	"netbsd_lchown",
	/* 276 */	"lutimes",
	/* 277 */	"__msync13",
	/* 278 */	"__stat13",
	/* 279 */	"__fstat13",
	/* 280 */	"__lstat13",
	/* 281 */	"#281 (unimplemented)",
	/* 282 */	"#282 (unimplemented)",
	/* 283 */	"#283 (unimplemented)",
	/* 284 */	"#284 (unimplemented)",
	/* 285 */	"#285 (unimplemented)",
	/* 286 */	"#286 (unimplemented)",
	/* 287 */	"#287 (unimplemented)",
	/* 288 */	"#288 (unimplemented)",
	/* 289 */	"#289 (unimplemented)",
	/* 290 */	"#290 (unimplemented)",
	/* 291 */	"#291 (unimplemented)",
	/* 292 */	"#292 (unimplemented)",
	/* 293 */	"#293 (unimplemented)",
	/* 294 */	"#294 (unimplemented)",
	/* 295 */	"#295 (unimplemented)",
	/* 296 */	"#296 (unimplemented)",
	/* 297 */	"fhstatfs",
	/* 298 */	"fhopen",
	/* 299 */	"fhstat",
	/* 300 */	"#300 (unimplemented modnext)",
	/* 301 */	"#301 (unimplemented modstat)",
	/* 302 */	"#302 (unimplemented modfnext)",
	/* 303 */	"#303 (unimplemented modfind)",
	/* 304 */	"#304 (unimplemented kldload)",
	/* 305 */	"#305 (unimplemented kldunload)",
	/* 306 */	"#306 (unimplemented kldfind)",
	/* 307 */	"#307 (unimplemented kldnext)",
	/* 308 */	"#308 (unimplemented kldstat)",
	/* 309 */	"#309 (unimplemented kldfirstmod)",
	/* 310 */	"getsid",
	/* 311 */	"#311 (unimplemented setresuid)",
	/* 312 */	"#312 (unimplemented setresgid)",
	/* 313 */	"#313 (unimplemented signanosleep)",
	/* 314 */	"#314 (unimplemented aio_return)",
	/* 315 */	"#315 (unimplemented aio_suspend)",
	/* 316 */	"#316 (unimplemented aio_cancel)",
	/* 317 */	"#317 (unimplemented aio_error)",
	/* 318 */	"#318 (unimplemented aio_read)",
	/* 319 */	"#319 (unimplemented aio_write)",
	/* 320 */	"#320 (unimplemented lio_listio)",
	/* 321 */	"yield",
	/* 322 */	"#322 (unimplemented thr_sleep)",
	/* 323 */	"#323 (unimplemented thr_wakeup)",
	/* 324 */	"mlockall",
	/* 325 */	"munlockall",
	/* 326 */	"__getcwd",
	/* 327 */	"sched_setparam",
	/* 328 */	"sched_getparam",
	/* 329 */	"sched_setscheduler",
	/* 330 */	"sched_getscheduler",
	/* 331 */	"sched_yield",
	/* 332 */	"sched_get_priority_max",
	/* 333 */	"sched_get_priority_min",
	/* 334 */	"#334 (unimplemented sched_rr_get_interval)",
	/* 335 */	"utrace",
	/* 336 */	"#336 (unimplemented sendfile)",
	/* 337 */	"#337 (unimplemented kldsym)",
	/* 338 */	"#338 (unimplemented jail)",
	/* 339 */	"#339 (unimplemented pioctl)",
	/* 340 */	"__sigprocmask14",
	/* 341 */	"__sigsuspend14",
	/* 342 */	"sigaction4",
	/* 343 */	"__sigpending14",
	/* 344 */	"#344 (unimplemented 4.0 sigreturn)",
	/* 345 */	"#345 (unimplemented sigtimedwait)",
	/* 346 */	"#346 (unimplemented sigwaitinfo)",
	/* 347 */	"#347 (unimplemented __acl_get_file)",
	/* 348 */	"#348 (unimplemented __acl_set_file)",
	/* 349 */	"#349 (unimplemented __acl_get_fd)",
	/* 350 */	"#350 (unimplemented __acl_set_fd)",
	/* 351 */	"#351 (unimplemented __acl_delete_file)",
	/* 352 */	"#352 (unimplemented __acl_delete_fd)",
	/* 353 */	"#353 (unimplemented __acl_aclcheck_file)",
	/* 354 */	"#354 (unimplemented __acl_aclcheck_fd)",
	/* 355 */	"#355 (unimplemented extattrctl)",
	/* 356 */	"#356 (unimplemented extattr_set_file)",
	/* 357 */	"#357 (unimplemented extattr_get_file)",
	/* 358 */	"#358 (unimplemented extattr_delete_file)",
	/* 359 */	"#359 (unimplemented aio_waitcomplete)",
	/* 360 */	"#360 (unimplemented getresuid)",
	/* 361 */	"#361 (unimplemented getresgid)",
	/* 362 */	"#362 (unimplemented kqueue)",
	/* 363 */	"#363 (unimplemented kevent)",
	/* 364 */	"#364 (unimplemented __cap_get_proc)",
	/* 365 */	"#365 (unimplemented __cap_set_proc)",
	/* 366 */	"#366 (unimplemented __cap_get_fd)",
	/* 367 */	"#367 (unimplemented __cap_get_file)",
	/* 368 */	"#368 (unimplemented __cap_set_fd)",
	/* 369 */	"#369 (unimplemented __cap_set_file)",
	/* 370 */	"#370 (unimplemented lkmressym)",
	/* 371 */	"#371 (unimplemented extattr_set_fd)",
	/* 372 */	"#372 (unimplemented extattr_get_fd)",
	/* 373 */	"#373 (unimplemented extattr_delete_fd)",
	/* 374 */	"#374 (unimplemented __setugid)",
	/* 375 */	"#375 (unimplemented nfsclnt)",
	/* 376 */	"#376 (unimplemented eaccess)",
	/* 377 */	"#377 (unimplemented afs_syscall)",
	/* 378 */	"#378 (unimplemented nmount)",
	/* 379 */	"#379 (unimplemented kse_exit)",
	/* 380 */	"#380 (unimplemented kse_wakeup)",
	/* 381 */	"#381 (unimplemented kse_create)",
	/* 382 */	"#382 (unimplemented kse_thr_interrupt)",
	/* 383 */	"#383 (unimplemented kse_release)",
	/* 384 */	"#384 (unimplemented __mac_get_proc)",
	/* 385 */	"#385 (unimplemented __mac_set_proc)",
	/* 386 */	"#386 (unimplemented __mac_get_fd)",
	/* 387 */	"#387 (unimplemented __mac_get_file)",
	/* 388 */	"#388 (unimplemented __mac_set_fd)",
	/* 389 */	"#389 (unimplemented __mac_set_file)",
	/* 390 */	"#390 (unimplemented kenv)",
	/* 391 */	"lchflags",
	/* 392 */	"uuidgen",
	/* 393 */	"#393 (unimplemented sendfile)",
	/* 394 */	"#394 (unimplemented mac_syscall)",
	/* 395 */	"#395 (unimplemented getfsstat)",
	/* 396 */	"#396 (unimplemented statfs)",
	/* 397 */	"#397 (unimplemented fsstatfs)",
	/* 398 */	"#398 (unimplemented fhstatfs)",
	/* 399 */	"#399 (unimplemented nosys)",
	/* 400 */	"_ksem_close",
	/* 401 */	"_ksem_post",
	/* 402 */	"_ksem_wait",
	/* 403 */	"_ksem_trywait",
	/* 404 */	"#404 (unimplemented ksem_init)",
	/* 405 */	"#405 (unimplemented ksem_open)",
	/* 406 */	"_ksem_unlink",
	/* 407 */	"_ksem_getvalue",
	/* 408 */	"_ksem_destroy",
	/* 409 */	"#409 (unimplemented __mac_get_pid)",
	/* 410 */	"#410 (unimplemented __mac_get_link)",
	/* 411 */	"#411 (unimplemented __mac_set_link)",
	/* 412 */	"#412 (unimplemented extattr_set_link)",
	/* 413 */	"#413 (unimplemented extattr_get_link)",
	/* 414 */	"#414 (unimplemented extattr_delete_link)",
	/* 415 */	"#415 (unimplemented __mac_execve)",
	/* 416 */	"#416 (unimplemented sigaction)",
	/* 417 */	"#417 (unimplemented sigreturn)",
	/* 418 */	"#418 (unimplemented __xstat)",
	/* 419 */	"#419 (unimplemented __xfstat)",
	/* 420 */	"#420 (unimplemented __xlstat)",
	/* 421 */	"#421 (unimplemented getcontext)",
	/* 422 */	"#422 (unimplemented setcontext)",
	/* 423 */	"#423 (unimplemented swapcontext)",
	/* 424 */	"#424 (unimplemented swapoff)",
	/* 425 */	"#425 (unimplemented __acl_get_link)",
	/* 426 */	"#426 (unimplemented __acl_set_link)",
	/* 427 */	"#427 (unimplemented __acl_delete_link)",
	/* 428 */	"#428 (unimplemented __acl_aclcheck_link)",
	/* 429 */	"#429 (unimplemented sigwait)",
	/* 430 */	"#430 (unimplemented thr_create)",
	/* 431 */	"#431 (unimplemented thr_exit)",
	/* 432 */	"#432 (unimplemented thr_self)",
	/* 433 */	"#433 (unimplemented thr_kill)",
	/* 434 */	"#434 (unimplemented _umtx_lock)",
	/* 435 */	"#435 (unimplemented _umtx_unlock)",
	/* 436 */	"#436 (unimplemented jail_attach)",
	/* 437 */	"#437 (unimplemented extattr_list_fd)",
	/* 438 */	"#438 (unimplemented extattr_list_file)",
	/* 439 */	"#439 (unimplemented extattr_list_link)",
	/* 440 */	"# filler",
	/* 441 */	"# filler",
	/* 442 */	"# filler",
	/* 443 */	"# filler",
	/* 444 */	"# filler",
	/* 445 */	"# filler",
	/* 446 */	"# filler",
	/* 447 */	"# filler",
	/* 448 */	"# filler",
	/* 449 */	"# filler",
	/* 450 */	"# filler",
	/* 451 */	"# filler",
	/* 452 */	"# filler",
	/* 453 */	"# filler",
	/* 454 */	"# filler",
	/* 455 */	"# filler",
	/* 456 */	"# filler",
	/* 457 */	"# filler",
	/* 458 */	"# filler",
	/* 459 */	"# filler",
	/* 460 */	"# filler",
	/* 461 */	"# filler",
	/* 462 */	"# filler",
	/* 463 */	"# filler",
	/* 464 */	"# filler",
	/* 465 */	"# filler",
	/* 466 */	"# filler",
	/* 467 */	"# filler",
	/* 468 */	"# filler",
	/* 469 */	"# filler",
	/* 470 */	"# filler",
	/* 471 */	"# filler",
	/* 472 */	"# filler",
	/* 473 */	"# filler",
	/* 474 */	"# filler",
	/* 475 */	"# filler",
	/* 476 */	"# filler",
	/* 477 */	"# filler",
	/* 478 */	"# filler",
	/* 479 */	"# filler",
	/* 480 */	"# filler",
	/* 481 */	"# filler",
	/* 482 */	"# filler",
	/* 483 */	"# filler",
	/* 484 */	"# filler",
	/* 485 */	"# filler",
	/* 486 */	"# filler",
	/* 487 */	"# filler",
	/* 488 */	"# filler",
	/* 489 */	"# filler",
	/* 490 */	"# filler",
	/* 491 */	"# filler",
	/* 492 */	"# filler",
	/* 493 */	"# filler",
	/* 494 */	"# filler",
	/* 495 */	"# filler",
	/* 496 */	"# filler",
	/* 497 */	"# filler",
	/* 498 */	"# filler",
	/* 499 */	"# filler",
	/* 500 */	"# filler",
	/* 501 */	"# filler",
	/* 502 */	"# filler",
	/* 503 */	"# filler",
	/* 504 */	"# filler",
	/* 505 */	"# filler",
	/* 506 */	"# filler",
	/* 507 */	"# filler",
	/* 508 */	"# filler",
	/* 509 */	"# filler",
	/* 510 */	"# filler",
	/* 511 */	"# filler",
};


/* libc style syscall names */
const char *const altfreebsd_syscallnames[] = {
	/*   0 */	"nosys",
	/*   1 */	NULL, /* exit */
	/*   2 */	NULL, /* fork */
	/*   3 */	NULL, /* read */
	/*   4 */	NULL, /* write */
	/*   5 */	NULL, /* open */
	/*   6 */	NULL, /* close */
	/*   7 */	NULL, /* wait4 */
	/*   8 */	"creat",
	/*   9 */	NULL, /* link */
	/*  10 */	NULL, /* unlink */
	/*  11 */	NULL, /* obsolete execv */
	/*  12 */	NULL, /* chdir */
	/*  13 */	NULL, /* fchdir */
	/*  14 */	NULL, /* mknod */
	/*  15 */	NULL, /* chmod */
	/*  16 */	NULL, /* chown */
	/*  17 */	"obreak",
	/*  18 */	NULL, /* getfsstat */
	/*  19 */	"lseek",
	/*  20 */	NULL, /* getpid_with_ppid */
	/*  21 */	NULL, /* mount */
	/*  22 */	NULL, /* unmount */
	/*  23 */	NULL, /* setuid */
	/*  24 */	NULL, /* getuid_with_euid */
	/*  25 */	NULL, /* geteuid */
	/*  26 */	NULL, /* ptrace */
	/*  27 */	NULL, /* recvmsg */
	/*  28 */	NULL, /* sendmsg */
	/*  29 */	NULL, /* recvfrom */
	/*  30 */	NULL, /* accept */
	/*  31 */	NULL, /* getpeername */
	/*  32 */	NULL, /* getsockname */
	/*  33 */	NULL, /* access */
	/*  34 */	NULL, /* chflags */
	/*  35 */	NULL, /* fchflags */
	/*  36 */	NULL, /* sync */
	/*  37 */	NULL, /* kill */
	/*  38 */	"stat",
	/*  39 */	NULL, /* getppid */
	/*  40 */	"lstat",
	/*  41 */	NULL, /* dup */
	/*  42 */	NULL, /* pipe */
	/*  43 */	NULL, /* getegid */
	/*  44 */	NULL, /* profil */
#ifdef KTRACE
	/*  45 */	NULL, /* ktrace */
#else
	/*  45 */	NULL, /* excluded ktrace */
#endif
	/*  46 */	NULL, /* sigaction */
	/*  47 */	NULL, /* getgid_with_egid */
	/*  48 */	NULL, /* sigprocmask */
	/*  49 */	NULL, /* __getlogin */
	/*  50 */	NULL, /* __setlogin */
	/*  51 */	NULL, /* acct */
	/*  52 */	NULL, /* sigpending */
	/*  53 */	NULL, /* sigaltstack */
	/*  54 */	NULL, /* ioctl */
	/*  55 */	"reboot",
	/*  56 */	NULL, /* revoke */
	/*  57 */	NULL, /* symlink */
	/*  58 */	NULL, /* readlink */
	/*  59 */	NULL, /* execve */
	/*  60 */	NULL, /* umask */
	/*  61 */	NULL, /* chroot */
	/*  62 */	"fstat",
	/*  63 */	"getkerninfo",
	/*  64 */	"getpagesize",
	/*  65 */	NULL, /* msync */
	/*  66 */	NULL, /* vfork */
	/*  67 */	NULL, /* obsolete vread */
	/*  68 */	NULL, /* obsolete vwrite */
	/*  69 */	NULL, /* obsolete sbrk */
	/*  70 */	NULL, /* obsolete sstk */
	/*  71 */	"mmap",
	/*  72 */	"ovadvise",
	/*  73 */	NULL, /* munmap */
	/*  74 */	NULL, /* mprotect */
	/*  75 */	NULL, /* madvise */
	/*  76 */	NULL, /* obsolete vhangup */
	/*  77 */	NULL, /* obsolete vlimit */
	/*  78 */	NULL, /* mincore */
	/*  79 */	NULL, /* getgroups */
	/*  80 */	NULL, /* setgroups */
	/*  81 */	NULL, /* getpgrp */
	/*  82 */	NULL, /* setpgid */
	/*  83 */	NULL, /* setitimer */
	/*  84 */	"wait",
	/*  85 */	NULL, /* swapon */
	/*  86 */	NULL, /* getitimer */
	/*  87 */	"gethostname",
	/*  88 */	"sethostname",
	/*  89 */	"getdtablesize",
	/*  90 */	NULL, /* dup2 */
	/*  91 */	NULL, /* unimplemented getdopt */
	/*  92 */	NULL, /* fcntl */
	/*  93 */	NULL, /* select */
	/*  94 */	NULL, /* unimplemented setdopt */
	/*  95 */	NULL, /* fsync */
	/*  96 */	NULL, /* setpriority */
	/*  97 */	NULL, /* socket */
	/*  98 */	NULL, /* connect */
	/*  99 */	"accept",
	/* 100 */	NULL, /* getpriority */
	/* 101 */	"send",
	/* 102 */	"recv",
	/* 103 */	NULL, /* sigreturn */
	/* 104 */	NULL, /* bind */
	/* 105 */	NULL, /* setsockopt */
	/* 106 */	NULL, /* listen */
	/* 107 */	NULL, /* obsolete vtimes */
	/* 108 */	"sigvec",
	/* 109 */	"sigblock",
	/* 110 */	"sigsetmask",
	/* 111 */	NULL, /* sigsuspend */
	/* 112 */	"sigstack",
	/* 113 */	"recvmsg",
	/* 114 */	"sendmsg",
#ifdef TRACE
	/* 115 */	NULL, /* vtrace */
#else
	/* 115 */	NULL, /* obsolete vtrace */
#endif
	/* 116 */	NULL, /* gettimeofday */
	/* 117 */	NULL, /* getrusage */
	/* 118 */	NULL, /* getsockopt */
	/* 119 */	NULL, /* obsolete resuba */
	/* 120 */	NULL, /* readv */
	/* 121 */	NULL, /* writev */
	/* 122 */	NULL, /* settimeofday */
	/* 123 */	NULL, /* fchown */
	/* 124 */	NULL, /* fchmod */
	/* 125 */	"recvfrom",
	/* 126 */	NULL, /* setreuid */
	/* 127 */	NULL, /* setregid */
	/* 128 */	NULL, /* rename */
	/* 129 */	"truncate",
	/* 130 */	"ftruncate",
	/* 131 */	NULL, /* flock */
	/* 132 */	NULL, /* mkfifo */
	/* 133 */	NULL, /* sendto */
	/* 134 */	NULL, /* shutdown */
	/* 135 */	NULL, /* socketpair */
	/* 136 */	NULL, /* mkdir */
	/* 137 */	NULL, /* rmdir */
	/* 138 */	NULL, /* utimes */
	/* 139 */	NULL, /* obsolete 4.2 sigreturn */
	/* 140 */	NULL, /* adjtime */
	/* 141 */	"getpeername",
	/* 142 */	"gethostid",
	/* 143 */	"sethostid",
	/* 144 */	"getrlimit",
	/* 145 */	"setrlimit",
	/* 146 */	"killpg",
	/* 147 */	NULL, /* setsid */
	/* 148 */	NULL, /* quotactl */
	/* 149 */	"quota",
	/* 150 */	"getsockname",
	/* 151 */	NULL, /* unimplemented sem_lock */
	/* 152 */	NULL, /* unimplemented sem_wakeup */
	/* 153 */	NULL, /* unimplemented asyncdaemon */
	/* 154 */	NULL, /* unimplemented */
	/* 155 */	NULL, /* unimplemented nfssvc */
	/* 156 */	"getdirentries",
	/* 157 */	NULL, /* statfs */
	/* 158 */	NULL, /* fstatfs */
	/* 159 */	NULL, /* unimplemented */
	/* 160 */	NULL, /* unimplemented */
	/* 161 */	NULL, /* getfh */
	/* 162 */	NULL, /* getdomainname */
	/* 163 */	NULL, /* setdomainname */
	/* 164 */	NULL, /* uname */
	/* 165 */	NULL, /* sysarch */
	/* 166 */	NULL, /* rtprio */
	/* 167 */	NULL, /* unimplemented */
	/* 168 */	NULL, /* unimplemented */
#if defined(SYSVSEM) && !defined(_LP64)
	/* 169 */	NULL, /* semsys */
#else
	/* 169 */	NULL, /* unimplemented 1.0 semsys */
#endif
#if defined(SYSVMSG) && !defined(_LP64)
	/* 170 */	NULL, /* msgsys */
#else
	/* 170 */	NULL, /* unimplemented 1.0 msgsys */
#endif
#if defined(SYSVSHM) && !defined(_LP64)
	/* 171 */	NULL, /* shmsys */
#else
	/* 171 */	NULL, /* unimplemented 1.0 shmsys */
#endif
	/* 172 */	NULL, /* unimplemented */
	/* 173 */	NULL, /* pread */
	/* 174 */	NULL, /* pwrite */
	/* 175 */	NULL, /* unimplemented */
#ifdef NTP
	/* 176 */	"ntp_adjtime",
#else
	/* 176 */	NULL, /* excluded ntp_adjtime */
#endif
	/* 177 */	NULL, /* unimplemented sfork */
	/* 178 */	NULL, /* unimplemented getdescriptor */
	/* 179 */	NULL, /* unimplemented setdescriptor */
	/* 180 */	NULL, /* unimplemented */
	/* 181 */	NULL, /* setgid */
	/* 182 */	NULL, /* setegid */
	/* 183 */	NULL, /* seteuid */
	/* 184 */	NULL, /* unimplemented */
	/* 185 */	NULL, /* unimplemented */
	/* 186 */	NULL, /* unimplemented */
	/* 187 */	NULL, /* unimplemented */
	/* 188 */	NULL, /* stat */
	/* 189 */	NULL, /* fstat */
	/* 190 */	NULL, /* lstat */
	/* 191 */	NULL, /* pathconf */
	/* 192 */	NULL, /* fpathconf */
	/* 193 */	NULL, /* unimplemented */
	/* 194 */	NULL, /* getrlimit */
	/* 195 */	NULL, /* setrlimit */
	/* 196 */	NULL, /* getdirentries */
	/* 197 */	NULL, /* mmap */
	/* 198 */	"nosys",
	/* 199 */	NULL, /* lseek */
	/* 200 */	NULL, /* truncate */
	/* 201 */	NULL, /* ftruncate */
	/* 202 */	NULL, /* sysctl */
	/* 203 */	NULL, /* mlock */
	/* 204 */	NULL, /* munlock */
#ifdef FREEBSD_BASED_ON_44LITE_R2
	/* 205 */	NULL, /* undelete */
#else
	/* 205 */	NULL, /* unimplemented undelete */
#endif
	/* 206 */	NULL, /* futimes */
	/* 207 */	NULL, /* getpgid */
#if 0
	/* 208 */	NULL, /* reboot */
#else
	/* 208 */	NULL, /* unimplemented newreboot */
#endif
	/* 209 */	NULL, /* poll */
	/* 210 */	NULL, /* unimplemented */
	/* 211 */	NULL, /* unimplemented */
	/* 212 */	NULL, /* unimplemented */
	/* 213 */	NULL, /* unimplemented */
	/* 214 */	NULL, /* unimplemented */
	/* 215 */	NULL, /* unimplemented */
	/* 216 */	NULL, /* unimplemented */
	/* 217 */	NULL, /* unimplemented */
	/* 218 */	NULL, /* unimplemented */
	/* 219 */	NULL, /* unimplemented */
#ifdef SYSVSEM
	/* 220 */	NULL, /* __semctl */
	/* 221 */	NULL, /* semget */
	/* 222 */	NULL, /* semop */
	/* 223 */	NULL, /* semconfig */
#else
	/* 220 */	NULL, /* unimplemented semctl */
	/* 221 */	NULL, /* unimplemented semget */
	/* 222 */	NULL, /* unimplemented semop */
	/* 223 */	NULL, /* unimplemented semconfig */
#endif
#ifdef SYSVMSG
	/* 224 */	NULL, /* msgctl */
	/* 225 */	NULL, /* msgget */
	/* 226 */	NULL, /* msgsnd */
	/* 227 */	NULL, /* msgrcv */
#else
	/* 224 */	NULL, /* unimplemented msgctl */
	/* 225 */	NULL, /* unimplemented msgget */
	/* 226 */	NULL, /* unimplemented msgsnd */
	/* 227 */	NULL, /* unimplemented msgrcv */
#endif
#ifdef SYSVSHM
	/* 228 */	NULL, /* shmat */
	/* 229 */	NULL, /* shmctl */
	/* 230 */	NULL, /* shmdt */
	/* 231 */	NULL, /* shmget */
#else
	/* 228 */	NULL, /* unimplemented shmat */
	/* 229 */	NULL, /* unimplemented shmctl */
	/* 230 */	NULL, /* unimplemented shmdt */
	/* 231 */	NULL, /* unimplemented shmget */
#endif
	/* 232 */	NULL, /* clock_gettime */
	/* 233 */	NULL, /* clock_settime */
	/* 234 */	NULL, /* clock_getres */
	/* 235 */	NULL, /* unimplemented timer_create */
	/* 236 */	NULL, /* unimplemented timer_delete */
	/* 237 */	NULL, /* unimplemented timer_settime */
	/* 238 */	NULL, /* unimplemented timer_gettime */
	/* 239 */	NULL, /* unimplemented timer_getoverrun */
	/* 240 */	NULL, /* nanosleep */
	/* 241 */	NULL, /* unimplemented */
	/* 242 */	NULL, /* unimplemented */
	/* 243 */	NULL, /* unimplemented */
	/* 244 */	NULL, /* unimplemented */
	/* 245 */	NULL, /* unimplemented */
	/* 246 */	NULL, /* unimplemented */
	/* 247 */	NULL, /* unimplemented */
	/* 248 */	NULL, /* unimplemented */
	/* 249 */	NULL, /* unimplemented */
	/* 250 */	NULL, /* minherit */
	/* 251 */	NULL, /* rfork */
	/* 252 */	NULL, /* unimplemented openbsd_poll */
	/* 253 */	NULL, /* issetugid */
	/* 254 */	NULL, /* lchown */
	/* 255 */	NULL, /* unimplemented */
	/* 256 */	NULL, /* unimplemented */
	/* 257 */	NULL, /* unimplemented */
	/* 258 */	NULL, /* unimplemented */
	/* 259 */	NULL, /* unimplemented */
	/* 260 */	NULL, /* unimplemented */
	/* 261 */	NULL, /* unimplemented */
	/* 262 */	NULL, /* unimplemented */
	/* 263 */	NULL, /* unimplemented */
	/* 264 */	NULL, /* unimplemented */
	/* 265 */	NULL, /* unimplemented */
	/* 266 */	NULL, /* unimplemented */
	/* 267 */	NULL, /* unimplemented */
	/* 268 */	NULL, /* unimplemented */
	/* 269 */	NULL, /* unimplemented */
	/* 270 */	NULL, /* unimplemented */
	/* 271 */	NULL, /* unimplemented */
	/* 272 */	NULL, /* getdents */
	/* 273 */	NULL, /* unimplemented */
	/* 274 */	NULL, /* lchmod */
	/* 275 */	"lchown",
	/* 276 */	NULL, /* lutimes */
	/* 277 */	"msync",
	/* 278 */	"stat",
	/* 279 */	"fstat",
	/* 280 */	"lstat",
	/* 281 */	NULL, /* unimplemented */
	/* 282 */	NULL, /* unimplemented */
	/* 283 */	NULL, /* unimplemented */
	/* 284 */	NULL, /* unimplemented */
	/* 285 */	NULL, /* unimplemented */
	/* 286 */	NULL, /* unimplemented */
	/* 287 */	NULL, /* unimplemented */
	/* 288 */	NULL, /* unimplemented */
	/* 289 */	NULL, /* unimplemented */
	/* 290 */	NULL, /* unimplemented */
	/* 291 */	NULL, /* unimplemented */
	/* 292 */	NULL, /* unimplemented */
	/* 293 */	NULL, /* unimplemented */
	/* 294 */	NULL, /* unimplemented */
	/* 295 */	NULL, /* unimplemented */
	/* 296 */	NULL, /* unimplemented */
	/* 297 */	NULL, /* fhstatfs */
	/* 298 */	NULL, /* fhopen */
	/* 299 */	NULL, /* fhstat */
	/* 300 */	NULL, /* unimplemented modnext */
	/* 301 */	NULL, /* unimplemented modstat */
	/* 302 */	NULL, /* unimplemented modfnext */
	/* 303 */	NULL, /* unimplemented modfind */
	/* 304 */	NULL, /* unimplemented kldload */
	/* 305 */	NULL, /* unimplemented kldunload */
	/* 306 */	NULL, /* unimplemented kldfind */
	/* 307 */	NULL, /* unimplemented kldnext */
	/* 308 */	NULL, /* unimplemented kldstat */
	/* 309 */	NULL, /* unimplemented kldfirstmod */
	/* 310 */	NULL, /* getsid */
	/* 311 */	NULL, /* unimplemented setresuid */
	/* 312 */	NULL, /* unimplemented setresgid */
	/* 313 */	NULL, /* unimplemented signanosleep */
	/* 314 */	NULL, /* unimplemented aio_return */
	/* 315 */	NULL, /* unimplemented aio_suspend */
	/* 316 */	NULL, /* unimplemented aio_cancel */
	/* 317 */	NULL, /* unimplemented aio_error */
	/* 318 */	NULL, /* unimplemented aio_read */
	/* 319 */	NULL, /* unimplemented aio_write */
	/* 320 */	NULL, /* unimplemented lio_listio */
	/* 321 */	NULL, /* yield */
	/* 322 */	NULL, /* unimplemented thr_sleep */
	/* 323 */	NULL, /* unimplemented thr_wakeup */
	/* 324 */	NULL, /* mlockall */
	/* 325 */	NULL, /* munlockall */
	/* 326 */	NULL, /* __getcwd */
	/* 327 */	NULL, /* sched_setparam */
	/* 328 */	NULL, /* sched_getparam */
	/* 329 */	NULL, /* sched_setscheduler */
	/* 330 */	NULL, /* sched_getscheduler */
	/* 331 */	NULL, /* sched_yield */
	/* 332 */	NULL, /* sched_get_priority_max */
	/* 333 */	NULL, /* sched_get_priority_min */
	/* 334 */	NULL, /* unimplemented sched_rr_get_interval */
	/* 335 */	NULL, /* utrace */
	/* 336 */	NULL, /* unimplemented sendfile */
	/* 337 */	NULL, /* unimplemented kldsym */
	/* 338 */	NULL, /* unimplemented jail */
	/* 339 */	NULL, /* unimplemented pioctl */
	/* 340 */	"sigprocmask",
	/* 341 */	"sigsuspend",
	/* 342 */	NULL, /* sigaction4 */
	/* 343 */	"sigpending",
	/* 344 */	NULL, /* unimplemented 4.0 sigreturn */
	/* 345 */	NULL, /* unimplemented sigtimedwait */
	/* 346 */	NULL, /* unimplemented sigwaitinfo */
	/* 347 */	NULL, /* unimplemented __acl_get_file */
	/* 348 */	NULL, /* unimplemented __acl_set_file */
	/* 349 */	NULL, /* unimplemented __acl_get_fd */
	/* 350 */	NULL, /* unimplemented __acl_set_fd */
	/* 351 */	NULL, /* unimplemented __acl_delete_file */
	/* 352 */	NULL, /* unimplemented __acl_delete_fd */
	/* 353 */	NULL, /* unimplemented __acl_aclcheck_file */
	/* 354 */	NULL, /* unimplemented __acl_aclcheck_fd */
	/* 355 */	NULL, /* unimplemented extattrctl */
	/* 356 */	NULL, /* unimplemented extattr_set_file */
	/* 357 */	NULL, /* unimplemented extattr_get_file */
	/* 358 */	NULL, /* unimplemented extattr_delete_file */
	/* 359 */	NULL, /* unimplemented aio_waitcomplete */
	/* 360 */	NULL, /* unimplemented getresuid */
	/* 361 */	NULL, /* unimplemented getresgid */
	/* 362 */	NULL, /* unimplemented kqueue */
	/* 363 */	NULL, /* unimplemented kevent */
	/* 364 */	NULL, /* unimplemented __cap_get_proc */
	/* 365 */	NULL, /* unimplemented __cap_set_proc */
	/* 366 */	NULL, /* unimplemented __cap_get_fd */
	/* 367 */	NULL, /* unimplemented __cap_get_file */
	/* 368 */	NULL, /* unimplemented __cap_set_fd */
	/* 369 */	NULL, /* unimplemented __cap_set_file */
	/* 370 */	NULL, /* unimplemented lkmressym */
	/* 371 */	NULL, /* unimplemented extattr_set_fd */
	/* 372 */	NULL, /* unimplemented extattr_get_fd */
	/* 373 */	NULL, /* unimplemented extattr_delete_fd */
	/* 374 */	NULL, /* unimplemented __setugid */
	/* 375 */	NULL, /* unimplemented nfsclnt */
	/* 376 */	NULL, /* unimplemented eaccess */
	/* 377 */	NULL, /* unimplemented afs_syscall */
	/* 378 */	NULL, /* unimplemented nmount */
	/* 379 */	NULL, /* unimplemented kse_exit */
	/* 380 */	NULL, /* unimplemented kse_wakeup */
	/* 381 */	NULL, /* unimplemented kse_create */
	/* 382 */	NULL, /* unimplemented kse_thr_interrupt */
	/* 383 */	NULL, /* unimplemented kse_release */
	/* 384 */	NULL, /* unimplemented __mac_get_proc */
	/* 385 */	NULL, /* unimplemented __mac_set_proc */
	/* 386 */	NULL, /* unimplemented __mac_get_fd */
	/* 387 */	NULL, /* unimplemented __mac_get_file */
	/* 388 */	NULL, /* unimplemented __mac_set_fd */
	/* 389 */	NULL, /* unimplemented __mac_set_file */
	/* 390 */	NULL, /* unimplemented kenv */
	/* 391 */	NULL, /* lchflags */
	/* 392 */	NULL, /* uuidgen */
	/* 393 */	NULL, /* unimplemented sendfile */
	/* 394 */	NULL, /* unimplemented mac_syscall */
	/* 395 */	NULL, /* unimplemented getfsstat */
	/* 396 */	NULL, /* unimplemented statfs */
	/* 397 */	NULL, /* unimplemented fsstatfs */
	/* 398 */	NULL, /* unimplemented fhstatfs */
	/* 399 */	NULL, /* unimplemented nosys */
	/* 400 */	NULL, /* _ksem_close */
	/* 401 */	NULL, /* _ksem_post */
	/* 402 */	NULL, /* _ksem_wait */
	/* 403 */	NULL, /* _ksem_trywait */
	/* 404 */	NULL, /* unimplemented ksem_init */
	/* 405 */	NULL, /* unimplemented ksem_open */
	/* 406 */	NULL, /* _ksem_unlink */
	/* 407 */	NULL, /* _ksem_getvalue */
	/* 408 */	NULL, /* _ksem_destroy */
	/* 409 */	NULL, /* unimplemented __mac_get_pid */
	/* 410 */	NULL, /* unimplemented __mac_get_link */
	/* 411 */	NULL, /* unimplemented __mac_set_link */
	/* 412 */	NULL, /* unimplemented extattr_set_link */
	/* 413 */	NULL, /* unimplemented extattr_get_link */
	/* 414 */	NULL, /* unimplemented extattr_delete_link */
	/* 415 */	NULL, /* unimplemented __mac_execve */
	/* 416 */	NULL, /* unimplemented sigaction */
	/* 417 */	NULL, /* unimplemented sigreturn */
	/* 418 */	NULL, /* unimplemented __xstat */
	/* 419 */	NULL, /* unimplemented __xfstat */
	/* 420 */	NULL, /* unimplemented __xlstat */
	/* 421 */	NULL, /* unimplemented getcontext */
	/* 422 */	NULL, /* unimplemented setcontext */
	/* 423 */	NULL, /* unimplemented swapcontext */
	/* 424 */	NULL, /* unimplemented swapoff */
	/* 425 */	NULL, /* unimplemented __acl_get_link */
	/* 426 */	NULL, /* unimplemented __acl_set_link */
	/* 427 */	NULL, /* unimplemented __acl_delete_link */
	/* 428 */	NULL, /* unimplemented __acl_aclcheck_link */
	/* 429 */	NULL, /* unimplemented sigwait */
	/* 430 */	NULL, /* unimplemented thr_create */
	/* 431 */	NULL, /* unimplemented thr_exit */
	/* 432 */	NULL, /* unimplemented thr_self */
	/* 433 */	NULL, /* unimplemented thr_kill */
	/* 434 */	NULL, /* unimplemented _umtx_lock */
	/* 435 */	NULL, /* unimplemented _umtx_unlock */
	/* 436 */	NULL, /* unimplemented jail_attach */
	/* 437 */	NULL, /* unimplemented extattr_list_fd */
	/* 438 */	NULL, /* unimplemented extattr_list_file */
	/* 439 */	NULL, /* unimplemented extattr_list_link */
	/* 440 */	NULL, /* filler */
	/* 441 */	NULL, /* filler */
	/* 442 */	NULL, /* filler */
	/* 443 */	NULL, /* filler */
	/* 444 */	NULL, /* filler */
	/* 445 */	NULL, /* filler */
	/* 446 */	NULL, /* filler */
	/* 447 */	NULL, /* filler */
	/* 448 */	NULL, /* filler */
	/* 449 */	NULL, /* filler */
	/* 450 */	NULL, /* filler */
	/* 451 */	NULL, /* filler */
	/* 452 */	NULL, /* filler */
	/* 453 */	NULL, /* filler */
	/* 454 */	NULL, /* filler */
	/* 455 */	NULL, /* filler */
	/* 456 */	NULL, /* filler */
	/* 457 */	NULL, /* filler */
	/* 458 */	NULL, /* filler */
	/* 459 */	NULL, /* filler */
	/* 460 */	NULL, /* filler */
	/* 461 */	NULL, /* filler */
	/* 462 */	NULL, /* filler */
	/* 463 */	NULL, /* filler */
	/* 464 */	NULL, /* filler */
	/* 465 */	NULL, /* filler */
	/* 466 */	NULL, /* filler */
	/* 467 */	NULL, /* filler */
	/* 468 */	NULL, /* filler */
	/* 469 */	NULL, /* filler */
	/* 470 */	NULL, /* filler */
	/* 471 */	NULL, /* filler */
	/* 472 */	NULL, /* filler */
	/* 473 */	NULL, /* filler */
	/* 474 */	NULL, /* filler */
	/* 475 */	NULL, /* filler */
	/* 476 */	NULL, /* filler */
	/* 477 */	NULL, /* filler */
	/* 478 */	NULL, /* filler */
	/* 479 */	NULL, /* filler */
	/* 480 */	NULL, /* filler */
	/* 481 */	NULL, /* filler */
	/* 482 */	NULL, /* filler */
	/* 483 */	NULL, /* filler */
	/* 484 */	NULL, /* filler */
	/* 485 */	NULL, /* filler */
	/* 486 */	NULL, /* filler */
	/* 487 */	NULL, /* filler */
	/* 488 */	NULL, /* filler */
	/* 489 */	NULL, /* filler */
	/* 490 */	NULL, /* filler */
	/* 491 */	NULL, /* filler */
	/* 492 */	NULL, /* filler */
	/* 493 */	NULL, /* filler */
	/* 494 */	NULL, /* filler */
	/* 495 */	NULL, /* filler */
	/* 496 */	NULL, /* filler */
	/* 497 */	NULL, /* filler */
	/* 498 */	NULL, /* filler */
	/* 499 */	NULL, /* filler */
	/* 500 */	NULL, /* filler */
	/* 501 */	NULL, /* filler */
	/* 502 */	NULL, /* filler */
	/* 503 */	NULL, /* filler */
	/* 504 */	NULL, /* filler */
	/* 505 */	NULL, /* filler */
	/* 506 */	NULL, /* filler */
	/* 507 */	NULL, /* filler */
	/* 508 */	NULL, /* filler */
	/* 509 */	NULL, /* filler */
	/* 510 */	NULL, /* filler */
	/* 511 */	NULL, /* filler */
};
