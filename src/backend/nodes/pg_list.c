#include "postgres.h"
#include "nodes/pg_list.h"
#include "nodes/primnodes.h"
#include "utils/elog.h"

void pglist_print(const char * name, List *l) {
 ListCell *lc = list_head(l);
 elog(WARNING, "%s list:",name);
 for(;;){
  elog(WARNING,"\t int %d ",lfirst_int(lc));
  lc=lnext(lc);
  if (lc == NULL) break;
 }

}

void pglist_print2(const char * name,List *l) {
        ListCell *lt;
	elog(WARNING, "%s list:",name);
        if(list_length(l) == 0) 	elog(WARNING, "null");
        else
	foreach(lt, l)	{
		TargetEntry *tle = (TargetEntry *) lfirst(lt);
		elog(WARNING,"\t %s  %d %d", tle->resname,tle->resorigtbl,tle->resorigcol);
	}

}

