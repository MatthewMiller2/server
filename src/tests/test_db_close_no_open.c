/* Can I close a db without opening it? */
#include <assert.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <db.h>

#define DIR "dir.test_db_close_no_open"

DB_ENV *env;
DB *db;

int main (int argc, char *argv[]) {
    int r;
    system("rm -rf " DIR);
    r=mkdir(DIR, 0777);       assert(r==0);
    r=db_env_create(&env, 0); assert(r==0);
    r=env->open(env, DIR, DB_PRIVATE|DB_CREATE, 0777); assert(r==0);
    r=db_create(&db, env, 0); assert(r==0);
    r=db->close(db, 0);       assert(r==0);
    r=env->close(env, 0);     assert(r==0);
    return 0;
}
