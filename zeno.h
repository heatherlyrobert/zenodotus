/*===============================[[ beg code ]]===============================*/

/*===[[ ONE_LINERS ]]=========================================================*/
/*                      ´·········1·········2·········3·········4·········5·········6·········7*/
/*--------- 12345678901 ´123456789-123456789-123456789-123456789-123456789-123456789-123456789-*/
/*········· ··········· ´·····························´········································*/
#define     P_FOCUS     "PS (programming support)"
#define     P_NICHE     "in (installation)"
#define     P_SUBJECT   "compilation and installation tailoring"
#define     P_PURPOSE   "group of programs, headers, and files to tailor make/install"
/*········· ··········· ´·····························´········································*/
#define     P_NAMESAKE  "zenodotus-bibliothikarios (librarian)"
#define     P_PRONOUNCE ""
#define     P_TRANSLATE ""
#define     P_HERITAGE  "first librarian of alexandria (345-270bc) appointed in 284bc"
#define     P_BRIEFLY   "first librarian of alexandria"
#define     P_IMAGERY   ""
#define     P_REASON    ""
/*········· ··········· ´·····························´········································*/
#define     P_ONELINE   P_NAMESAKE " " P_SUBJECT
/*········· ··········· ´·····························´········································*/
#define     P_HOMEDIR   "/home/system/zenodotus.tailored_makefile_system"
#define     P_BASENAME  "zeno_lib"
#define     P_FULLPATH  "/usr/local/bin/zeno_lib"
#define     P_SUFFIX    "···"
#define     P_CONTENT   "···"
/*········· ··········· ´·····························´········································*/
#define     P_SYSTEM    "gnu/linux   (powerful, ubiquitous, technical, and hackable)"
#define     P_LANGUAGE  "ansi-c      (wicked, limitless, universal, and everlasting)"
#define     P_COMPILER  "gcc 5.3.0"
#define     P_CODESIZE  "small       (appoximately 1,000 slocl)"
/*········· ··········· ´·····························´········································*/
#define     P_AUTHOR    "heatherlyrobert"
#define     P_CREATED   "2008-07"
/*········· ··········· ´·····························´········································*/
#define     P_VERMAJOR  "3.-- merging tools into new zenodotus"
#define     P_VERMINOR  "3.2- unit testing Makefile"
#define     P_VERNUM    "3.2f"
#define     P_VERTXT    "painful updates to handle utility unit testing ;)"
/*········· ··········· ´·····························´········································*/
#define     P_PRIORITY  "direct, simple, brief, vigorous, and lucid (h.w. fowler)"
#define     P_PRINCIPAL "[grow a set] and build your wings on the way down (r. bradbury)"
#define     P_REMINDER  "there are many better options, but i *own* every byte of this one"
/*········· ··········· ´·····························´········································*/
#define     P_HEADERS   P_FOCUS, P_NICHE, P_SUBJECT, P_PURPOSE, P_NAMESAKE, P_PRONOUNCE, P_HERITAGE, P_BRIEFLY, P_IMAGERY, P_REASON, P_ONELINE, P_HOMEDIR, P_BASENAME, P_FULLPATH, P_SUFFIX, P_CONTENT, P_SYSTEM, P_LANGUAGE, P_COMPILER, P_CODESIZE, NULL, NULL, NULL, NULL, NULL, NULL, NULL, P_AUTHOR, P_CREATED, P_VERMAJOR, P_VERMINOR, P_VERNUM, P_VERTXT
/*········· ··········· ´·····························´········································*/
/*--------- 12345678901 ´123456789-123456789-123456789-123456789-123456789-123456789-123456789-*/

/*===[[ PURPOSE ]]=============================================================*

 *   _lib is a quick set of capabilities to move custom developed shared (.so)
 *   and static (.a) libraries into the right places for use by other programs
 *   as well as their associated header files.  it is intended as a very small
 *   helper application only.
 *
 *   _lib focuses only on providing the ability to...
 *      - install libraries into system folders
 *      - listing the installed libraries
 *      - deleting specific installed libraries
 *      - installing custom shared libraries and their headers
 *      - installing custom static libraries and their headers
 *
 *   many existing libraries and utilities have been built by better programmers
 *   which are likely superior in speed, size, capability, and reliability; BUT,
 *   i would not have learned nearly as much using them, so i follow the adage...
 *
 *   TO TRULY LEARN> do not seek to follow in the footsteps of the men of old;
 *   seek what they sought ~ Matsuo Basho
 *
 */
/*===[[ END HDOC ]]===========================================================*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define  HEADERS      "/usr/local/include"
#define  LIBRARIES    "/usr/local/lib64"

typedef struct stat      tSTAT;
#define   LEN_FULL       200
#define   LEN_TERSE       10
typedef   const char   cchar;

