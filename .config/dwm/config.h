/* See LICENSE file for copyright and license details.
 ____  _ _ _ _____
|    \| | | |     |
|  |  | | | | | | |
|____/|_____|_|_|_|
                   
window manager settings */
static const unsigned int borderpx  = 3;    /* border pixel of windows */
static const unsigned int gappx     = 0;    /* gaps between tiled windows */
static const unsigned int snap      = 10;   /* snap pixel */
static const int showbar            = 1;    /* 0 means no bar */
static const int topbar             = 1;    /* 0 means bottom bar */
static const char *fonts[]          = { "Fantasque Sans Mono:size=13:style=normal:antialias=true:autohint=true" };
static const char dmenufont[]       = "CodeNewRoman Nerd Font:size=13:style=normal:antialias=true:autohint=true";
#include "/home/jll/.cache/wal/colors-wal-dwm.h"
/* alpha values and approximate opacity 
100% — 0xFF, 95% — 0xF2, 90% — 0xE6, 85% — 0xD9, 80% — 0xCC, 
75% — 0xBF, 70% — 0xB3, 65% — 0xA6, 60% — 0x99, 55% — 0x8C, 
50% — 0x80, 45% — 0x73, 40% — 0x66, 35% — 0x59, 30% — 0x4D, 
25% — 0x40, 20% — 0x33, 15% — 0x26, 10% — 0x1A, 5% — 0x0D, 0% — 0x00 */
static const unsigned int alpha = 0xCC;
static const unsigned int borderalpha = 0xCC;
static const unsigned int alphas[][5]      = {
	/*                   fg       bg        border     */
	[SchemeNorm]      = { OPAQUE, alpha, borderalpha },
	[SchemeSel]       = { OPAQUE, alpha, borderalpha },
    [SchemeTitle]     = { OPAQUE, alpha, borderalpha },
    [SchemeWarn]      = { OPAQUE, alpha, borderalpha },
    [SchemeUrgent]    = { OPAQUE, alpha, borderalpha },
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class                  instance     title      tags mask      isfloating   monitor */
    { "Sxiv",                   NULL,       NULL,       0,              1,           -1 },
    { "Skype",                  NULL,       NULL,       0,              1,           -1 },
    { "Pavucontrol",            NULL,       NULL,       0,              1,           -1 },
    { "Grsync",                 NULL,       NULL,       0,              1,           -1 },
    { "GParted",                NULL,       NULL,       0,              1,           -1 },
    { "Gnome-disks",            NULL,       NULL,       0,              1,           -1 },
    { "Gsimplecal",             NULL,       NULL,       0,              1,           -1 },
    { "Gnome-calculator",       NULL,       NULL,       0,              1,           -1 },
    { "File-roller",            NULL,       NULL,       0,              1,           -1 },
    { "Deluge-gtk",             NULL,       NULL,       0,              1,           -1 },
    { "Python3",                NULL,       NULL,       0,              1,           -1 },
    { "Gcolor2",                NULL,       NULL,       0,              1,           -1 },
    { "Python3",                NULL,       NULL,       0,              1,           -1 },
    { "Gufw.py",                NULL,       NULL,       0,              1,           -1 },
    { "Chromium",               NULL,       NULL,       0,              1,           -1 },
    { "Asunder",                NULL,       NULL,       0,              1,           -1 },
};

/* layout(s) */
static const float mfact     = 0.539; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */

#include "layouts.c"
#include "fibonacci.c"
static const Layout layouts[] = {
    /* first entry is default */
	/* symbol     arrange function */
    { "[]=",      tile },
    { "><>",      NULL },
    { "|M|",      centeredmaster },
    { "[@]",      spiral },
    { "===",      bstackhoriz },
    { "TTT",      bstack },
    { "HHH",      grid },
    { "[\\]",     dwindle },
    { "[M]",      monocle },
    { NULL,       NULL },
};

/* key definitions */
#define MODKEY    Mod1Mask
#define MOD4      Mod4Mask
#define NOMOD     0
#define LAUNCH    0x1008ff41
#define MUTE      0x1008ff12
#define MICMUTE   0x1008ffb2
#define VOLDEC    0x1008ff11
#define VOLINC    0x1008ff13
#define BLINC     0x1008ff02
#define BLDEC     0x1008ff03
#define PRVTRK    0x1008ff16
#define NXTTRK    0x1008ff17
#define PLYTRK    0x1008ff14
#define STPTRK    0x1008ff15
#define SEEKFWD   0x1008ff27
#define SEEKBK    0x1008ff26
#define FUNCTN    0x1008ff2b
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *termcmd[]     =  { "st", NULL };
static const char *lockcmd[]     =  { "slimlock", NULL };
static const char *webcmd[]      =  { "qutebrowser", NULL };
static const char *walcmd[]      =  { "wallpaper", NULL };
static const char *altwebcmd[]   =  { "chromium", NULL };
static const char *filemancmd[]  =  { "pcmanfm", NULL };
static const char *musiccmd[]    =  { "dwm-music", NULL };
static const char *niccmd[]      =  { "nicotine", NULL };
static const char *textcmd[]     =  { "dwm-text", NULL };
static const char *calccmd[]     =  { "gnome-calculator", NULL };
static const char *calcmd[]      =  { "gsimplecal", NULL };
static const char *dmenucmd[]    =  { "dmenu_run", NULL };
static const char *netmancmd[]   =  { "networkmanager_dmenu", NULL };
static const char *dwebcmd[]     =  { "dmenu_websearch", NULL };
static const char *dpasscmd[]    =  { "dmenu_pass", NULL };
static const char *j4cmd[]       =  { "j4-dmenu-desktop", NULL };
static const char *scrotcmd[]    =  { "dwm-flameshot", NULL };
static const char *volinccmd[]   =  { "volinc", NULL };
static const char *voldeccmd[]   =  { "voldec", NULL };
static const char *mutecmd[]     =  { "mute", NULL };
static const char *micmutecmd[]  =  { "micmute", NULL };
static const char *d100cmd[]     =  { "vol100d", NULL };
static const char *i100cmd[]     =  { "vol100i", NULL };
static const char *blinccmd[]    =  { "blinc", NULL };
static const char *bldeccmd[]    =  { "bldec", NULL };
static const char *mpdplypzcmd[] =  { "mpd-playpaws", NULL };
static const char *mpdstopcmd[]  =  { "mpd-stop", NULL };
static const char *mpdnxtcmd[]   =  { "mpd-next", NULL };
static const char *mpdprvcmd[]   =  { "mpd-prev", NULL };
static const char *mpdskfwdcmd[] =  { "mpd-seekfwd", NULL };
static const char *mpdskbkcmd[]  =  { "mpd-seekbk", NULL };
static const char *mpdmenucmd[]  =  { "mpdmenu", NULL };
static const char *mpdcnkycmd[]  =  { "mpd-conky-kill", NULL };
static const char *blockscmd[]   =  { "dwmblockskill", NULL };
static const char *settingscmd[] =  { "dmenu_syssettings", NULL };
static const char *xresetcmd[]   =  { "xsettingsd-reset", NULL };
static const char *exitcmd[]     =  { "dwm-logout", NULL };

static Key keys[] = {
	/* modifier             key       function        argument */
     /* PROGRAM LAUNCHERS */
     { NOMOD,               XK_grave,  spawn,    {.v = termcmd }  },
     { NOMOD,               LAUNCH,    spawn,    {.v = lockcmd }  },
     { NOMOD,               XK_Print,  spawn,    {.v = scrotcmd }  },
     { NOMOD,               VOLINC,    spawn,    {.v = volinccmd }  },
     { NOMOD,               VOLDEC,    spawn,    {.v = voldeccmd }  },
     { MODKEY,              VOLINC,    spawn,    {.v = d100cmd }  },
     { MODKEY,              VOLDEC,    spawn,    {.v = i100cmd }  },
     { NOMOD,               MUTE,      spawn,    {.v = mutecmd }  },
     { NOMOD,               MICMUTE,   spawn,    {.v = micmutecmd }  },
     { NOMOD,               PLYTRK,    spawn,    {.v = mpdplypzcmd }  },
     { MOD4,                XK_Return, spawn,    {.v = mpdplypzcmd }  },
     { NOMOD,               STPTRK,    spawn,    {.v = mpdstopcmd }  },
     { NOMOD,               NXTTRK,    spawn,    {.v = mpdnxtcmd }  },
     { NOMOD,               PRVTRK,    spawn,    {.v = mpdprvcmd }  },
     { MODKEY,              SEEKFWD,   spawn,    {.v = mpdskfwdcmd }  },
     { MODKEY,              SEEKBK,    spawn,    {.v = mpdskbkcmd }  },
     { NOMOD,               STPTRK,    spawn,    {.v = mpdcnkycmd }  },
     { MOD4,                XK_m,      spawn,    {.v = mpdmenucmd }  },
     { MODKEY,              XK_w,      spawn,    {.v = webcmd }  },
     { MODKEY,              XK_f,      spawn,    {.v = filemancmd }  },
     { MODKEY,              XK_m,      spawn,    {.v = musiccmd }  },
     { MODKEY|ShiftMask,    XK_w,      spawn,    {.v = walcmd }  },
     { MODKEY,              XK_n,      spawn,    {.v = niccmd }  },
     { MOD4,                XK_n,      spawn,    {.v = netmancmd }  },
     { MODKEY,              XK_p,      spawn,    {.v = textcmd }  },
     { MODKEY,              XK_c,      spawn,    {.v = calccmd }  },
     { MODKEY|ShiftMask,    XK_c,      spawn,    {.v = calcmd }  },
     { MOD4,                XK_w,      spawn,    {.v = altwebcmd }  },
     { MOD4,                XK_d,      spawn,    {.v = dmenucmd }  },
     { MOD4,                XK_space,  spawn,    {.v = j4cmd }  },
     { MOD4,                XK_u,      spawn,    {.v = dwebcmd }  },
     { MOD4,                XK_p,      spawn,    {.v = dpasscmd }  },
     { NOMOD,               BLINC,     spawn,    {.v = blinccmd} },
     { NOMOD,               BLDEC,     spawn,    {.v = bldeccmd} },
     { NOMOD,               BLINC,     spawn,    {.v = blockscmd} },
     { NOMOD,               BLDEC,     spawn,    {.v = blockscmd} },
     { NOMOD,               VOLINC,    spawn,    {.v = blockscmd }  },
     { NOMOD,               VOLDEC,    spawn,    {.v = blockscmd }  },
     { MODKEY,              VOLINC,    spawn,    {.v = blockscmd }  },
     { MODKEY,              VOLDEC,    spawn,    {.v = blockscmd }  },
     { NOMOD,               MUTE,      spawn,    {.v = blockscmd }  },
     { NOMOD,               STPTRK,    spawn,    {.v = blockscmd} },
     { NOMOD,               PLYTRK,    spawn,    {.v = blockscmd} },
     { NOMOD,               NXTTRK,    spawn,    {.v = blockscmd} },
     { NOMOD,               PRVTRK,    spawn,    {.v = blockscmd} },
     /* WINDOW MANAGER CONTROL */
     { MODKEY,              XK_b,      togglebar,      {0} },
     { MODKEY,              XK_Left,   focusstack,     {.i = +1 } },
     { MODKEY,              XK_Right,  focusstack,     {.i = -1 } },
     { MODKEY,              XK_Up,     incnmaster,     {.i = +1 } },
     { MODKEY,              XK_Down,   incnmaster,     {.i = -1 } },
     { MODKEY|ControlMask,  XK_Left,   setmfact,       {.f = -0.05} },
     { MODKEY|ControlMask,  XK_Right,  setmfact,       {.f = +0.05} },
     { MODKEY,              XK_Return, zoom,           {0} },
     { MODKEY,              XK_Tab,    view,           {0} },
     { MODKEY,              XK_q,      killclient,     {0} },
     { MODKEY,              XK_t,      setlayout,      {.v = &layouts[0]} },
     { MODKEY|ShiftMask,    XK_f,      setlayout,      {.v = &layouts[1]} },
     { MODKEY|ControlMask,  XK_c,      setlayout,      {.v = &layouts[2]} },
     { MODKEY|ShiftMask,    XK_s,      setlayout,      {.v = &layouts[3]} },
     { MODKEY,              XK_h,      setlayout,      {.v = &layouts[4]} },
     { MODKEY|ShiftMask,    XK_b,      setlayout,      {.v = &layouts[5]} },
     { MODKEY,              XK_g,      setlayout,      {.v = &layouts[6]} },
     { MODKEY|ShiftMask,    XK_d,      setlayout,      {.v = &layouts[7]} },
     { MODKEY|ShiftMask,    XK_m,      setlayout,      {.v = &layouts[8]} },
     { MODKEY,              XK_l,      cyclelayout,    {.i = -1  } },
     { MODKEY,              XK_comma,  cyclelayout,    {.i = -1  } },
     { MODKEY|ShiftMask,    XK_space,  setlayout,      {0} },
     { MODKEY,              XK_space,  togglefloating, {0} },
     { MODKEY,              XK_s,      togglesticky,   {0} },
     { MODKEY,              XK_0,      view,           {.ui = ~0 } },
     { MODKEY|ShiftMask,    XK_0,      tag,            {.ui = ~0 } },
     { MODKEY|ControlMask,  XK_comma,  focusmon,       {.i = -1 } },
     { MODKEY|ControlMask,  XK_period, focusmon,       {.i = +1 } },
     { MODKEY|ShiftMask,    XK_comma,  tagmon,         {.i = -1 } },
     { MODKEY|ShiftMask,    XK_period, tagmon,         {.i = +1 } },
     { MODKEY,              XK_minus,  setgaps,        {.i = -5 } },
     { MODKEY,              XK_equal,  setgaps,        {.i = +5 } },
     { MODKEY|ShiftMask,    XK_equal,  setgaps,        {.i =  0 } },
     TAGKEYS(               XK_1,                      0)
     TAGKEYS(               XK_2,                      1)
     TAGKEYS(               XK_3,                      2)
     TAGKEYS(               XK_4,                      3)
     TAGKEYS(               XK_5,                      4)
     TAGKEYS(               XK_6,                      5)
     TAGKEYS(               XK_7,                      6)
     TAGKEYS(               XK_8,                      7)
     TAGKEYS(               XK_9,                      8)
     { MODKEY|ShiftMask,    XK_q,      quit,           {0} },
     { MODKEY|ShiftMask,    XK_r,      quit,           {1} },
     { MOD4,                XK_s,      spawn,          {.v = settingscmd }  },
     { MODKEY|ShiftMask,    XK_r,      spawn,          {.v = xresetcmd }  },
     { MODKEY|ShiftMask,    XK_e,      spawn,          {.v = exitcmd }  },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};
