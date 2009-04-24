#ifndef _CTYPE_H_
#define _CTYPE_H_

#include "_ansi.h"

_BEGIN_STD_C

int _EXFUN(isalnum, (int __c));
int _EXFUN(isalpha, (int __c));
int _EXFUN(iscntrl, (int __c));
int _EXFUN(isdigit, (int __c));
int _EXFUN(isgraph, (int __c));
int _EXFUN(islower, (int __c));
int _EXFUN(isprint, (int __c));
int _EXFUN(ispunct, (int __c));
int _EXFUN(isspace, (int __c));
int _EXFUN(isupper, (int __c));
int _EXFUN(isxdigit,(int __c));
int _EXFUN(tolower, (int __c));
int _EXFUN(toupper, (int __c));

#if !defined(__STRICT_ANSI__) || defined(__cplusplus) || __STDC_VERSION__ >= 199901L
int _EXFUN(isblank, (int __c));
#endif

#ifndef __STRICT_ANSI__
int _EXFUN(isascii, (int __c));
int _EXFUN(toascii, (int __c));
#define _tolower(c) ((unsigned char)(c) - 'A' + 'a')
#define _toupper(c) ((unsigned char)(c) - 'a' + 'A')
#endif

#define	_U	01
#define	_L	02
#define	_N	04
#define	_S	010
#define _P	020
#define _C	040
#define _X	0100
#define	_B	0200

#ifndef _MB_CAPABLE
_CONST
#endif
extern	__IMPORT char	*__ctype_ptr__;

#ifndef __cplusplus
/* These macros are intentionally written in a manner that will trigger
   a gcc -Wall warning if the user mistakenly passes a 'char' instead
   of an int containing an 'unsigned char'.  */
#define	isalpha(c)	((__ctype_ptr__+1)[c]&(_U|_L))
#define	isupper(c)	(((__ctype_ptr__+1)[c]&(_U|_L))==_U)
#define	islower(c)	(((__ctype_ptr__+1)[c]&(_U|_L))==_L)
#define	isdigit(c)	((__ctype_ptr__+1)[c]&_N)
#define	isxdigit(c)	((__ctype_ptr__+1)[c]&(_X|_N))
#define	isspace(c)	((__ctype_ptr__+1)[c]&_S)
#define ispunct(c)	((__ctype_ptr__+1)[c]&_P)
#define isalnum(c)	((__ctype_ptr__+1)[c]&(_U|_L|_N))
#define isprint(c)	((__ctype_ptr__+1)[c]&(_P|_U|_L|_N|_B))
#define	isgraph(c)	((__ctype_ptr__+1)[c]&(_P|_U|_L|_N))
#define iscntrl(c)	((__ctype_ptr__+1)[c]&_C)

#if defined(__GNUC__) && \
    (!defined(__STRICT_ANSI__) || __STDC_VERSION__ >= 199901L)
#define isblank(c) \
  __extension__ ({ __typeof__ (c) __c = (c);		\
      ((__ctype_ptr__+1)[__c]&_B) || (__c) == '\t';})
#endif


/* Non-gcc versions will get the library versions, and will be
   slightly slower.  These macros are not NLS-aware so they are
   disabled if the system supports the extended character sets. */
# if defined(__GNUC__) && !defined (_MB_EXTENDED_CHARSETS_ISO) && !defined (_MB_EXTENDED_CHARSETS_WINDOWS)
# define toupper(c) \
  __extension__ ({ __typeof__ (c) __x = (c);	\
      islower(__x) ? (__x - 'a' + 'A') : __x;})
# define tolower(c) \
  __extension__ ({ __typeof__ (c) __x = (c);	\
      isupper(__x) ? (__x - 'A' + 'a') : __x;})
#endif
#endif /* !__cplusplus */

#ifndef __STRICT_ANSI__
#define isascii(c)	((unsigned)(c)<=0177)
#define toascii(c)	((c)&0177)
#endif

/* For C++ backward-compatibility only.  */
extern	__IMPORT _CONST char	_ctype_[];

_END_STD_C

#endif /* _CTYPE_H_ */
