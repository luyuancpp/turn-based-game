#pragma once
#include "src/thread_local/thread_local_storage.h"

class EventHandler
{
public:
static void Register();
static void UnRegister();
};
