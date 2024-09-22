/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const unsigned int systraypinning = 0;   /* 0: sloppy systray follows selected monitor, >0: pin systray to monitor X */
static const unsigned int systrayonleft  = 0;   /* 0: systray in the right corner, >0: systray on left of status text */
static const unsigned int systrayspacing = 2;   /* systray spacing */
static const int systraypinningfailfirst = 1;   /* 1: if pinning fails, display systray on the first monitor, False: display systray on the last monitor*/
static const int showsystray        = 1;        /* 0 means no systray */

static const int swallowfloating    = 0;        /* 1 means swallow floating windows by default */
static const unsigned int gappih    = 20;       /* horiz inner gap between windows */
static const unsigned int gappiv    = 10;       /* vert inner gap between windows */
static const unsigned int gappoh    = 10;       /* horiz outer gap between windows and screen edge */
static const unsigned int gappov    = 10;       /* vert outer gap between windows and screen edge */
static       int smartgaps          = 0;        /* 1 means no outer gap when there is only one window */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const int vertpad            = 10;       /* vertical padding of bar */
static const int sidepad            = 10;       /* horizontal padding of bar */
static const char *fonts[]          = { "monospace:size=10" };
static const char dmenufont[]       = "monospace:size=10";

#include "catppuccin.c"
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
	[SchemeSel]  = { col_gray4, col_cyan,  col_cyan  },
};
/* tagging */
static const char *tags[] = { "一", "二", "三", "四", "五", "六", "七", "八", "九", "十" };

static const unsigned int ulinepad	= 5;	/* horizontal padding between the underline and tag */
static const unsigned int ulinestroke	= 2;	/* thickness / height of the underline */
static const unsigned int ulinevoffset	= 0;	/* how far above the bottom of the bar the line should appear */
static const int ulineall 		= 0;	/* 1 to show underline on all tags, 0 for just the active ones */

static const char *tagsel[][2] = {
	{ "#ff0000", "#000000" },
	{ "#ff7f00", "#000000" },
	{ "#ffff00", "#000000" },
	{ "#00ff00", "#000000" },
	{ "#0000ff", "#000000" },
	{ "#4b0082", "#000000" },
	{ "#9400d3", "#000000" },
	{ "#000000", "#ffffff" },
	{ "#ffffff", "#000000" },
	{ "#ffffff", "#000000" },
};

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class     instance  title           tags mask  isfloating  isterminal  noswallow  monitor  scratch key */
	{ "Gimp",          NULL,     NULL,           0,         1,          0,           0,        -1,       0  },
	{ "thunderbird",   NULL,     NULL,           1 << 4,    0,          0,           0,        -1,       0  },
	{ "firefox",       NULL,     NULL,           1 << 8,    0,          0,          -1,        -1,       0  },
	{ NULL,            NULL,"Picture-in-Picture",0,         1,          0,          -1,        -1,       0  },
	{ "Lollypop",      NULL,     NULL,           1 << 3,    0,          0,          -1,        -1,       0  },
	{ "Mullvad VPN",   NULL,     NULL,           1 << 7,    1,          0,          -1,        -1,       0  },
	{ "qBittorrent",   NULL,     NULL,           1 << 7,    0,          0,          -1,        -1,       0  },
	{ "St",            NULL,     NULL,           0,         0,          1,           0,        -1,       0  },
	{ "kitty",         NULL,     NULL,           0,         0,          1,           0,        -1,       0  },
	{ NULL,            NULL,     "Event Tester", 0,         0,          0,           1,        -1,       0  }, /* xev */
	{ NULL,            NULL,     "scratchpad",   0,         1,          1,           0,        -1,      's' },
	{ "Mullvad Browser",      NULL,     NULL,   0,         1,          1,           0,        -1,      's' },
	{ "vesktop",       NULL,     NULL,           1 << 2,    0,          0,           0,        -1,       0  },
	{ "ArmCord",       NULL,     NULL,           1 << 2,    0,          0,           0,        -1,       0  },
	{ "revolt-desktop",NULL,     NULL,           1 << 2,    0,          0,           0,        -1,       0  },
	{ "warp-share",    NULL,     NULL,           0,         1,          0,           0,        -1,       0  },
};

/* window following */
#define WFACTIVE '>'
#define WFINACTIVE 'v'
#define WFDEFAULT WFINACTIVE

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */
static const int attachbelow = 1;    /* 1 means attach after the currently active window */

#define FORCE_VSPLIT 1  /* nrowgrid layout: force two clients to always split vertically */
#include "vanitygaps.c"

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "[M]",      monocle },
	{ "[@]",      spiral },
	{ "[\\]",     dwindle },
	{ "H[]",      deck },
	{ "TTT",      bstack },
	{ "===",      bstackhoriz },
	{ "HHH",      grid },
	{ "###",      nrowgrid },
	{ "---",      horizgrid },
	{ ":::",      gaplessgrid },
	{ "|M|",      centeredmaster },
	{ ">M>",      centeredfloatingmaster },
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ NULL,       NULL },
};

/* key definitions */
#define MODKEY Mod1Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_cyan, "-sf", col_gray4, NULL };
static const char *termcmd[]  = { "st", NULL };
/*First arg only serves to match against key in rules*/
static const char *scratchpadcmd[] = {"s", "st", "-t", "scratchpad", NULL}; 
static const char *scratchpad2cmd[] = {"s", "kitty", "-T", "scratchpad", NULL}; 
static const char *termcmd2[]  = { "kitty", NULL };
/*Media controlls*/
static const char *playpause[]  = { "playerctl", "play-pause" };
static const char *volupcmd[] = { "pactl", "set-sink-volume", "@DEFAULT_SINK@", "+1000", NULL };
static const char *voldowncmd[] = { "pactl", "set-sink-volume", "@DEFAULT_SINK@", "-1000", NULL };
static const char *mutevolcmd[] = { "pactl", "set-sink-mute", "@DEFAULT_SINK@", "toggle", NULL };
static const char *mutemiccmd[] = { "pactl", "set-source-mute", "@DEFAULT_SOURCE@", "toggle", NULL };
static const char *nextcmd[] = { "playerctl", "next", NULL };
static const char *prevcmd[] = { "playerctl", "previous", NULL };

/*Brighness*/
static const char *brightupcmd[] = { "brightnessctl", "set", "+10", NULL };
static const char *brightdowncmd[] = { "brightnessctl", "set", "10-", NULL };

static const char *lockcmd[] = { "betterlockscreen", "-l", NULL };
static const char *screencmd[] = { "screen", NULL };
static const char *browsercmd[]  = { "mullvad-browser", NULL };
static const char *filemanagercmd2[]  = { "st", "./.config/vifm/scripts/vifmrun", NULL };
static const char *filemanagercmd[]  = { "kitty", "./.config/vifm/scripts/vifmrun", NULL };
static const char *discordcmd[]  = { "vesktop", NULL };
static const char *emailcmd[]  = { "thunderbird", NULL };
static const char *calccmd[]  = { "st", "bc", NULL };
/*Screenshot*/
static const char *selectwindowcmd[] = { "screenshot.sh", "select", NULL };
static const char *selectareacmd[] = { "screenshot.sh", "area", NULL };
static const char *activewindowcmd[] = { "screenshot.sh", "window", NULL };
static const char *fullscreencmd[] = {"screenshot.sh", "full", NULL };



#include "unfloat.c"
#include "movestack.c"
static const Key keys[] = {
	/* modifier                     key        function        argument */

  /*FN keys*/
  { 0,                       0x1008FF14,      spawn,         {.v = playpause } },
  { 0,                       0x1008FF13,      spawn,         {.v = volupcmd } },
  { 0,                       0x1008FF11,      spawn,         {.v = voldowncmd } },
  { 0,                       0x1008FF12,      spawn,         {.v = mutevolcmd } },
  { 0,                       0x1008FFB2,      spawn,         {.v = mutemiccmd } },
  { 0,                       0x1008FF02,      spawn,         {.v = brightupcmd } },
  { 0,                       0x1008FF03,      spawn,         {.v = brightdowncmd } },
  { 0,                       0x1008FF17,      spawn,         {.v = nextcmd } },
  { 0,                       0x1008FF16,      spawn,         {.v = prevcmd } },

  { 0,                       0x1008FF1d,      spawn,         {.v = calccmd } },

  /*Screenshots*/
  { 0,                             XK_Print,  spawn,         {.v = activewindowcmd } },
  { MODKEY,                        XK_Print,  spawn,         {.v = fullscreencmd } },
  { MODKEY|ShiftMask,              XK_Print,  spawn,         {.v = selectareacmd } },
  { MODKEY|ShiftMask,              XK_grave,  spawn,         {.v = selectwindowcmd } },

  /*Launching stuff*/ 
  { Mod4Mask,                     XK_t,      spawn,          {.v = lockcmd } },
  { Mod4Mask,                     XK_q,      spawn,          {.v = screencmd } },
	{ MODKEY,                       XK_n,      spawn,          {.v = browsercmd } },
	{ MODKEY,                       XK_e,      spawn,          {.v = filemanagercmd } },
	{ MODKEY|Mod4Mask,             XK_e,      spawn,          {.v = filemanagercmd2 } },
	{ MODKEY|ShiftMask,             XK_d,      spawn,          {.v = discordcmd } },
	{ MODKEY|ShiftMask,             XK_m,      spawn,          {.v = emailcmd } },
	{ MODKEY,                       XK_p,      spawn,          {.v = dmenucmd } },
	{ MODKEY|ShiftMask,             XK_Return, spawn,          {.v = termcmd2 } },
	{ MODKEY|Mod4Mask,              XK_Return, spawn,          {.v = termcmd } },

 	{ MODKEY,                       XK_grave,          togglescratch,  {.v = scratchpad2cmd } },
 	{ MODKEY|Mod4Mask,              XK_grave,          togglescratch,  {.v = scratchpadcmd } },
	{ MODKEY,                       XK_minus,        scratchpad_show,  {0} },
	{ MODKEY|ShiftMask,             XK_minus,        scratchpad_hide,  {0} },
	{ MODKEY,                       XK_plus,       scratchpad_remove,  {0} },


  /*navigation*/
  { MODKEY|ShiftMask,             XK_space,  unfloatvisible, {0} },
  { MODKEY|ShiftMask,             XK_s,      togglefollow,   {0} },
	{ MODKEY,                       XK_s,      togglesticky,   {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
 	{ MODKEY|ShiftMask,             XK_j,      movestack,      {.i = +1 } },
 	{ MODKEY|ShiftMask,             XK_k,      movestack,      {.i = -1 } },
  { MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
  { MODKEY,                       XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
  { MODKEY|ShiftMask,             XK_f,      togglefullscr,  {0} },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
 	{ MODKEY,                       XK_Right,  viewnext,       {0} },
 	{ MODKEY,                       XK_Left,   viewprev,       {0} },
 	{ MODKEY|ShiftMask,             XK_Right,  tagtonext,      {0} },
 	{ MODKEY|ShiftMask,             XK_Left,   tagtoprev,      {0} },

  /*Layouts*/
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} }, /*tile*/
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[13]} }, /*float*/
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[1]} }, /*monocle*/
	{ MODKEY,                       XK_g,      setlayout,      {.v = &layouts[8]} }, /*nrowgrid*/
  { MODKEY,                       XK_u,      setlayout,      {.v = &layouts[4]} }, /*deck*/
  { MODKEY|ShiftMask,             XK_t,      setlayout,      {.v = &layouts[5]} }, /*bstack*/
  { MODKEY,                       XK_o,      setlayout,      {.v = &layouts[11]} }, /*centeredmaster*/
  { MODKEY|ShiftMask,             XK_v,      setlayout,      {.v = &layouts[12]} }, /*centeredfloatingmaster*/

  /*Visuals*/
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
 	{ MODKEY|ShiftMask,             XK_h,      setcfact,       {.f = +0.25} },
	{ MODKEY|ShiftMask,             XK_l,      setcfact,       {.f = -0.25} },
	{ MODKEY|ShiftMask,             XK_o,      setcfact,       {.f =  0.00} },
 	{ MODKEY,                       XK_r,      resetlayout,    {0} },
	{ MODKEY|Mod4Mask,              XK_u,      incrgaps,       {.i = +1 } },
	{ MODKEY|Mod4Mask|ShiftMask,    XK_u,      incrgaps,       {.i = -1 } },
	{ MODKEY|Mod4Mask,              XK_i,      incrigaps,      {.i = +1 } },
	{ MODKEY|Mod4Mask|ShiftMask,    XK_i,      incrigaps,      {.i = -1 } },
	{ MODKEY|Mod4Mask,              XK_o,      incrogaps,      {.i = +1 } },
	{ MODKEY|Mod4Mask|ShiftMask,    XK_o,      incrogaps,      {.i = -1 } },
	{ MODKEY|Mod4Mask,              XK_6,      incrihgaps,     {.i = +1 } },
	{ MODKEY|Mod4Mask|ShiftMask,    XK_6,      incrihgaps,     {.i = -1 } },
	{ MODKEY|Mod4Mask,              XK_7,      incrivgaps,     {.i = +1 } },
	{ MODKEY|Mod4Mask|ShiftMask,    XK_7,      incrivgaps,     {.i = -1 } },
	{ MODKEY|Mod4Mask,              XK_8,      incrohgaps,     {.i = +1 } },
	{ MODKEY|Mod4Mask|ShiftMask,    XK_8,      incrohgaps,     {.i = -1 } },
	{ MODKEY|Mod4Mask,              XK_9,      incrovgaps,     {.i = +1 } },
	{ MODKEY|Mod4Mask|ShiftMask,    XK_9,      incrovgaps,     {.i = -1 } },
	{ MODKEY|Mod4Mask,              XK_0,      togglegaps,     {0} },
	{ MODKEY|Mod4Mask|ShiftMask,    XK_0,      defaultgaps,    {0} },


	



  { MODKEY|ShiftMask,             XK_c,      killclient,     {0} },
	
//	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	TAGKEYS(                        XK_0,                      9)
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
	{ MODKEY|ControlMask|ShiftMask, XK_q,      quit,           {1} }, 
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[13]} },
	{ ClkFollowSymbol,      0,              Button1,        togglefollow,   {0} },
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
