#ifndef EFFECTS_H
#define EFFECTS_H

#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "merc.h"
#include "handler.h"
#include "recycle.h"
#include "comm.h"
#include "update.h"
#include "db.h"
#include "magic.h"
#include "utility.h"

//
// LOCAL FUNCTIONS
//

void acid_effect (void *vo, int level, int dam, int target);
void cold_effect (void *vo, int level, int dam, int target);
void fire_effect (void *vo, int level, int dam, int target);
void poison_effect (void *vo,int level, int dam, int target);
void shock_effect (void *vo,int level, int dam, int target);

#endif /* EFFECTS_H */
