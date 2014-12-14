struct am_scene_node;

struct am_node_child {
    int ref;
    am_scene_node *child;
};

struct am_render_state;

struct am_scene_node : am_nonatomic_userdata {
    am_action *action_list;
    am_lua_array<am_scene_node*> live_parents;
    am_lua_array<am_node_child> children;
    int recursion_limit;
    uint32_t flags;
    int root_count;

    am_scene_node();
    virtual void render(am_render_state *rstate);
    virtual int specialized_index(lua_State *L);
    virtual int specialized_newindex(lua_State *L); // return -1 for failure
    void render_children(am_render_state *rstate);
    void activate();
    void deactivate();
    void activate_root(lua_State *L);
    void deactivate_root();
};

void am_set_scene_node_child(lua_State *L, am_scene_node *parent);

int am_scene_node_index(lua_State *L);

void am_open_scene_module(lua_State *L);