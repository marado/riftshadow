#ifndef RIFT_H
#define RIFT_H

#define STATE_INVALID	0
#define STATE_VALID		1

#define MAX_EXITS		6

#include "stdlibs/bitvector.h"
#include "stdlibs/strings.h"
#include "stdlibs/funcptr.h"

#include "classlist.h"

#ifndef __cplusplus
#include <stdbool.h>
#endif

extern CMud RS;
extern RString EmptyString;
void bug(const char *bugstr, ...); //wraps onto RS.Bug

//the following is for typecasting rstrings when the func is weak typing
#define RSTR	const char *

#define RIFT_ROOT_DIR	".."
#define RIFT_ADMIN_DIR	RIFT_ROOT_DIR "/admin"
#define RIFT_AREA_DIR	RIFT_ROOT_DIR "/area"
#define RIFT_CODE_DIR	RIFT_ROOT_DIR "/code"
#define RIFT_PLAYER_DIR	RIFT_ROOT_DIR "/player"
#define RIFT_TEMP_DIR	RIFT_ROOT_DIR "/temp"

#define GREET_FILE	RIFT_AREA_DIR "/login.txt"

#define throwbug(...) throw Exception(__FILE__, __LINE__, __VA_ARGS__);
#define ERROR_TRAP()	try {
#define CATCH_ERRORS(j)	} catch (const char *msg) { bug("%s error: %s",j,msg); } catch (...) { bug("%s exception: unhandled",j); }

#define begin_benchmark 	struct timeval bttime; long bsec, esec; gettimeofday(&bttime, NULL); bsec = bttime.tv_usec;
#define end_benchmark(name)	gettimeofday(&bttime, NULL); esec = bttime.tv_usec; float res = (float)(esec - bsec) / 1000; \
							RS.Log("%s took %f ms.", name, res);
/////// smallmacros ///////
#define LOWCHAR(c) 		((c) >= 'A' && (c) <= 'Z' ? (c) + 'a' - 'A' : (c))
#define UPCHAR(c)		((c) >= 'a' && (c) <= 'z' ? (c) + 'A' - 'a' : (c))

inline long URANGE(long a, long b, long c)
{
	return 	b < a ? a : /* if b is less than a, a*/
			b > c ? c : /* b greater than c, then c */
	   		b;			/* otherwise b */
}
/* NOTE: strprefix returns true if it IS a prefix, opposite of ROM behavior */
inline bool strprefix(const char *astr, const char *bstr)
{
	for(; *astr != '\0'; astr++, bstr++)
		if(LOWCHAR(*astr) != LOWCHAR(*bstr))
		   return false;
	return true;
}
/*inline void capitalize(char *myString)
{
	if(*myString >= 'a' && *myString <= 'z')
		*myString += 'A' - 'a';
    for(int i = 1; *(myString + i) != ' '; i++)
		if(*(myString + i) >= 'A' && *(myString + i) <= 'Z')
			*(myString + i) += 'a' - 'A';
}*/
#define ZERO_TIMEVAL(time)	time.tv_sec = 0; time.tv_usec = 0;

#endif /* RIFT_H */
