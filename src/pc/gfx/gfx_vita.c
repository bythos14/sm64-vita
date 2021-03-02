#ifdef TARGET_VITA

#include <vitaGL.h>
#include <psp2/kernel/processmgr.h>

#include "gfx_window_manager_api.h"

#define DISPLAY_WIDTH 960
#define DISPLAY_HEIGHT 544

#ifdef VERSION_EU
    #define FRAMERATE 50
#else
    #define FRAMERATE 60
#endif

static const uint64_t frametime = 1000000 / FRAMERATE;

void gfx_vita_init(const char *game_name, bool start_in_fullscreen) {
}

void gfx_vita_set_keyboard_callbacks(bool (*on_key_down)(int scancode), bool (*on_key_up)(int scancode),
                                     void (*on_all_keys_up)()) {
}

void gfx_vita_set_fullscreen_changed_callback(void (*on_fullscreen_changed)(bool is_now_fullscreen)) {
}

void gfx_vita_set_fullscreen(bool enable) {
}

void gfx_vita_main_loop(void (*run_one_game_iter)()) {
    uint64_t t = 0;
    t = sceKernelGetProcessTimeWide();
    run_one_game_iter();
    t = sceKernelGetProcessTimeWide() - t;
    if (t < frametime)
        sceKernelDelayThreadCB(frametime - t);
}

void gfx_vita_get_dimensions(uint32_t *width, uint32_t *height) {
    *width = DISPLAY_WIDTH;
    *height = DISPLAY_HEIGHT;
}

void gfx_vita_handle_events() {
}

bool gfx_vita_start_frame() {
    return true;
}

void gfx_vita_swap_buffers_begin() {
    vglStopRenderingInit();
}

void gfx_vita_swap_buffers_end() {
    vglStopRenderingTerm();
}

double gfx_vita_get_time() {
    uint64_t time = sceKernelGetProcessTimeWide();

    return (double) time / (1.0 * 1000.0 * 1000.0);
}

struct GfxWindowManagerAPI gfx_vita = {
    gfx_vita_init,
    gfx_vita_set_keyboard_callbacks,
    gfx_vita_set_fullscreen_changed_callback,
    gfx_vita_set_fullscreen,
    gfx_vita_main_loop,
    gfx_vita_get_dimensions,
    gfx_vita_handle_events,
    gfx_vita_start_frame,
    gfx_vita_swap_buffers_begin,
    gfx_vita_swap_buffers_end,
    gfx_vita_get_time
};

#endif
