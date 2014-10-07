
#include <stdio.h>
#include <stdlib.h>
#include <v8.h>
#include <libplatform/libplatform.h>

#include "stordb.h"

int
main (int argc, char **argv, char **env) {
  // v8 initialization
  v8::Platform* platform;

  {
    int i = 0;
    int v8argc = argc;
    char *tmp = NULL;
    char *v8argv[v8argc];
    while ((tmp = argv[i++])) { v8argv[i] = tmp; }
    v8argv[v8argc++] = (char *) "--harmony";
    v8::V8::InitializeICU();
    platform = v8::platform::CreateDefaultPlatform();
    v8::V8::InitializePlatform(platform);
    v8::V8::SetFlagsFromCommandLine(&v8argc, v8argv, true);
  }

  // stordb initialization
  {
    int rc = 0;
    stordb_t *sdb = (stordb_t *) malloc(sizeof(stordb_t));
    if (NULL == sdb) { return 1; }
    rc = stordb_initialize(sdb, argc, argv, env);
    if (1 == rc) { return 1; }
  }

  v8::V8::Dispose();
  v8::V8::ShutdownPlatform();
  delete platform;
  return 0;
}
