#include <SDL.h>
#include <SDL_opengles2.h> // استخدام OpenGL ES 2.0
#include <iostream>

int main(int argc, char* argv[]) {
    // 1. تهيئة مكتبة SDL2 للفيديو
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        return -1;
    }

    // تحديد استخدام OpenGL ES 2.0
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_ES);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);

    // 2. إنشاء النافذة لتناسب أبعاد شاشة الهاتف تلقائياً
    SDL_Window* window = SDL_CreateWindow(
        "SDL2 GLES App",
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
        0, 0, // أندرويد سيتكفل بالأبعاد تلقائياً
        SDL_WINDOW_OPENGL | SDL_WINDOW_FULLSCREEN
    );

    if (!window) return -1;

    // 3. إنشاء سياق OpenGL
    SDL_GLContext glContext = SDL_GL_CreateContext(window);
    if (!glContext) return -1;

    bool running = true;
    SDL_Event event;

    // 4. حلقة التطبيق الأساسية (Main Loop)
    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
        }

        // الرسم باستخدام OpenGL ES: جعل الشاشة باللون الأزرق
        glClearColor(0.0f, 0.5f, 1.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // تحديث النافذة لعرض ما تم رسمه
        SDL_GL_SwapWindow(window);
    }

    // تنظيف الذاكرة قبل الخروج
    SDL_GL_DeleteContext(glContext);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}

