struct window
  {
    Window  window;
    Drawable drawable;
    Pixmap  buffer;
    int     isbuffered;
    Pixmap  background;
    int     type;
    char   *data;
    int     mapped;
    int     width, height;
    char   *name;
    W_Callback handle_keydown;
    W_Callback handle_keyup;
    W_Callback handle_button;
    W_Callback handle_expose;

#ifdef SHORT_PACKETS
    int     insensitive;
#endif
    Cursor  cursor;
  };

struct scrollingWindow
  {
    int     lines;
    int     updated;
    int     topline;
    struct stringList *head;
    struct stringList *tail;
    struct stringList *index;
  };

/* x11window.c */
int _myerror(Display *d, XErrorEvent *e);
void pastebuffer(void);
void checkFont(XFontStruct *fontinfo, char *fontname);
void GetFonts(void);
XFontStruct *find_font(char *oldf, char **fonts);
void GetColors(void);
void W_RenameWindow(W_Window window, char *str);
W_Window W_MakeWindow(char *name, int x, int y, int width, int height, W_Window parent, int border, W_Color color);
void W_ChangeBorder(W_Window window, int color);
void W_MapWindow(W_Window window);
void W_UnmapWindow(W_Window window);
int W_IsMapped(W_Window window);
void W_FillArea(W_Window window, int x, int y, int width, int height, W_Color color);
void W_CacheClearArea(W_Window window, int x, int y, int width, int height);
void W_FlushClearAreaCache(W_Window window);
void W_ClearArea(W_Window window, int x, int y, int width, int height);
void W_ClearWindow(W_Window window);
int W_EventsPending(void);
void W_NextEvent(W_Event *wevent);
int W_SpNextEvent(W_Event *wevent);
void W_MakeLine(W_Window window, int x0, int y0, int x1, int y1, W_Color color);
void W_CacheLine(W_Window window, int x0, int y0, int x1, int y1, int color);
void W_FlushLineCaches(W_Window window);
void W_MakeTractLine(W_Window window, int x0, int y0, int x1, int y1, W_Color color);
void W_MakePhaserLine(W_Window window, int x0, int y0, int x1, int y1, W_Color color);
void W_WriteTriangle(W_Window window, int x, int y, int s, int t, W_Color color);
void W_WriteText(W_Window window, int x, int y, W_Color color, char *str, int len, W_Font font);
void W_MaskText(W_Window window, int x, int y, W_Color color, char *str, int len, W_Font font);
W_Icon W_StoreBitmap(int width, int height, char *data, W_Window window);
void W_WriteBitmap(int x, int y, W_Icon bit, W_Color color);
void W_TileWindow(W_Window window, W_Icon bit);
void W_UnTileWindow(W_Window window);
W_Window W_MakeTextWindow(char *name, int x, int y, int width, int height, W_Window parent, int border);
struct window *newWindow(Window window, int type);
struct window *findWindow(Window window);
void addToHash(struct window *win);
W_Window W_MakeScrollingWindow(char *name, int x, int y, int width, int height, W_Window parent, int border);
void W_FlushScrollingWindow(W_Window window);
void W_SetSensitive(W_Window w, int v);
W_Window W_MakeMenu(char *name, int x, int y, int width, int height, W_Window parent, int border);
void redrawMenu(struct window *win);
void redrawMenuItem(struct window *win, int n);
void W_DefineMapcursor(W_Window window);
void W_DefineLocalcursor(W_Window window);
void W_DefineFedCursor(W_Window window);
void W_DefineRomCursor(W_Window window);
void W_DefineKliCursor(W_Window window);
void W_DefineOriCursor(W_Window window);
void W_DefineTrekCursor(W_Window window);
void W_DefineWarningCursor(W_Window window);
void W_DefineArrowCursor(W_Window window);
void W_DefineTextCursor(W_Window window);
void W_DefineCursor(W_Window window, int width, int height, char *bits, char *mask, int xhot, int yhot);
int W_LoadBitmap(W_Window window, char *path, Pixmap *pixmap, int *width, int *height, int *x_hot, int *y_hot);
void W_Beep(void);
int W_WindowWidth(W_Window window);
int W_WindowHeight(W_Window window);
int W_Socket(void);
void W_DestroyWindow(W_Window window);
void deleteWindow(struct window *window);
void W_SetIconWindow(W_Window main, W_Window icon);
void checkParent(char *name, W_Window *parent);
int checkMapped(char *name);
int checkMappedPref(char *name, int preferred);
void W_WarpPointer(W_Window window, int x, int y);
void findMouse(int *x, int *y);
int findMouseInWin(int *x, int *y, W_Window w);
void W_Flush(void);
W_Callback W_GetWindowKeyDownHandler(W_Window w);
void W_SetWindowKeyDownHandler(W_Window w, W_Callback c);
W_Callback W_GetWindowKeyUpHandler(W_Window w);
void W_SetWindowKeyUpHandler(W_Window w, W_Callback c);
W_Callback W_GetWindowButtonHandler(W_Window w);
void W_SetWindowButtonHandler(W_Window w, W_Callback c);
W_Callback W_GetWindowExposeHandler(W_Window w);
void W_SetWindowExposeHandler(W_Window w, W_Callback c);
void W_ResizeWindow(W_Window window, int neww, int newh);
void W_ResizeTextWindow(W_Window window, int neww, int newh);
int W_Mono(void);
int W_EventsQueued(void);
int W_EventsQueuedCk(void);
int W_ReadEvents(void);
void W_OverlayBitmap(int x, int y, W_Icon bit, W_Color color);
void W_SetWindowName(W_Window w, char *name);
int W_TTSTextHeight(void);
int W_TTSTextWidth(char *s, int l);
void init_tts(void);
void W_EraseTTSText(W_Window window, int max_width, int y, int width);
void W_WriteTTSText(W_Window window, int max_width, int y, int width, char *str, int len);
void W_Halo(int x, int y, W_Color color);
void W_CameraSnap(W_Window window);
