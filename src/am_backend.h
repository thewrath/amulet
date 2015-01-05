typedef void* am_native_window;

enum am_window_mode {
    AM_WINDOW_MODE_WINDOWED,
    AM_WINDOW_MODE_FULLSCREEN,
    AM_WINDOW_MODE_FULLSCREEN_DESKTOP,
};

am_native_window *am_create_native_window(
    am_window_mode mode,
    int top, int left,
    int width, int height,
    const char *title,
    bool resizable,
    bool borderless,
    bool depth_buffer,
    bool stencil_buffer,
    int msaa_samples,
    int *drawable_width, int *drawable_height);

void am_destroy_native_window(am_native_window* window);

void am_native_window_pre_render(am_native_window* window);
void am_native_window_post_render(am_native_window* window);

double am_get_current_time();
double am_get_frame_time();
double am_get_delta_time();
double am_get_average_fps();

bool am_set_relative_mouse_mode(bool enabled);
