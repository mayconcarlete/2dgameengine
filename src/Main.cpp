#include <iostream>
#include "LuaConfig.h"


void lua_example_dofile(void){
  /**
   * @brief call a lua file.
   *
   */
  lua_State* L = luaL_newstate();
  luaL_openlibs(L);
  luaL_dofile(L, "./scripts/myscript.lua");
  lua_close(L);
}

void lua_example_get_var(void){
  lua_State* L = luaL_newstate();
  luaL_dostring(L, "some_var = 486");
  lua_getglobal(L, "some_var");
  lua_Number some_var_in_c = lua_tonumber(L, -1);
  printf("The value of some var in C: %d \n", (int)some_var_in_c);
  lua_close(L);
}


int main() {
    lua_example_get_var();
    return EXIT_SUCCESS;
}